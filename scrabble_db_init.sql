/* instalujemy bazke widzowie */

CREATE DATABASE scrabble;

USE scrabble;

CREATE TABLE users (
	uid INT(4) PRIMARY KEY auto_increment,
	login VARCHAR(20) NOT NULL,
	password VARCHAR(65) NOT NULL
);

CREATE TABLE matches (
	mid INT(4) primary key auto_increment
);

CREATE TABLE moves (
	mvid INT(4) PRIMARY KEY auto_increment,
	mid INT(4),
	seq INT(4) NOT NULL,
	uid INT(4),
	r0w INT(4) NOT NULL,
	col INT(4) NOT NULL,
	is_vert INT(1) NOT NULL,
	word VARCHAR(10) NOT NULL,
	score INT(4) NOT NULL,
	FOREIGN KEY (mid) REFERENCES matches(mid) ON DELETE SET NULL,
 	FOREIGN KEY (uid) REFERENCES users(uid) ON DELETE SET NULL,
 	CONSTRAINT uq_seq UNIQUE (mid, seq),
 	CONSTRAINT uq_position UNIQUE (mid, r0w, col, is_vert)
);

DELIMITER $$
CREATE TRIGGER move_seq_in_match_increment
BEFORE INSERT
ON moves FOR EACH ROW BEGIN
	DECLARE last_seq INT(4) DEFAULT 0;
	SELECT seq INTO last_seq FROM moves WHERE mid = new.mid ORDER BY seq DESC LIMIT 1;
	SET new.seq = last_seq + 1;
END $$
DELIMITER ;

INSERT INTO users(login, password) VALUES
('easy', '77dc294fdaada5c21f1fca28f686795c94fb2a1a00eac7c6222dea69a0032024'),
('medium', '77dc294fdaada5c21f1fca28f686795c94fb2a1a00eac7c6222dea69a0032024'),
('hard', '77dc294fdaada5c21f1fca28f686795c94fb2a1a00eac7c6222dea69a0032024'),
('mufasa', '8add1abaa6eaadcb8e10b8c3efb91e063db8c3a12060280718661b3ab8bb8839'), /*mufasa1*/
('esteban', '7c73b6f7177e24d79d94430a85ccb2ef2f090bdd54157a12af97aaa3efb73154'), /*esteban37*/
('rokoko', 'A2C988799DCB80C5AAE08C7404FAC588A0AC2AE41979C16678C584F3FE43AF16'); /*rokoko1*/


CREATE VIEW played_matches_count AS SELECT uid, COALESCE(COUNT(DISTINCT(mid)),0) as cnt FROM moves RIGHT JOIN users USING(uid) GROUP BY uid;

CREATE VIEW played_maches_relative AS SELECT DISTINCT m.mid, uid, (SELECT SUM(score) FROM moves WHERE mid=m.mid AND uid=m.uid)-(SELECT MAX(l1.sum) FROM (SELECT m2.mid, (SELECT SUM(score) FROM moves WHERE mid=m2.mid AND uid=m2.uid) AS sum FROM moves m2) AS l1 WHERE l1.mid=m.mid) AS diff FROM moves m ORDER BY m.mid; 

CREATE VIEW won_matches_count AS SELECT u.uid, COALESCE(l1.cnt, 0) AS cnt FROM (SELECT uid, COUNT(*) AS cnt FROM played_maches_relative WHERE diff=0 GROUP BY uid) AS l1 RIGHT JOIN users u USING(uid);

CREATE VIEW won_matches_percentage AS SELECT pmc.uid, COALESCE(wmc.cnt/pmc.cnt, 0) AS prc FROM won_matches_count wmc JOIN played_matches_count pmc USING(uid);

CREATE VIEW lost_matches_count AS SELECT u.uid, COALESCE(l1.cnt, 0) AS cnt FROM (SELECT uid, COUNT(*) AS cnt FROM played_maches_relative WHERE diff<0 GROUP BY uid) AS l1 RIGHT JOIN users u USING(uid);

CREATE VIEW lost_matches_percentage AS SELECT pmc.uid, COALESCE(lmc.cnt/pmc.cnt, 0) as prc FROM lost_matches_count lmc JOIN played_matches_count pmc USING(uid);

CREATE VIEW mean_letter_count AS SELECT u.uid, COALESCE(l2.sum/l3.total, 0) AS mean FROM (SELECT l1.uid, SUM(l1.len) AS sum FROM (SELECT uid, LENGTH(word) AS len FROM moves) AS l1 GROUP BY l1.uid) AS l2 JOIN (SELECT uid, COUNT(*) AS total FROM moves GROUP BY uid) AS l3 USING(uid) RIGHT JOIN users u USING(uid);

CREATE VIEW mean_word_score AS SELECT u.uid, COALESCE(l1.sum/l2.total, 0) AS mean FROM (SELECT uid, SUM(score) AS sum FROM moves GROUP BY uid) AS l1 JOIN (SELECT uid, COUNT(*) AS total FROM moves GROUP BY uid) AS l2 USING(uid) RIGHT JOIN users u USING(uid);

CREATE VIEW played_matches_opponents AS SELECT DISTINCT (SELECT login FROM users WHERE uid=m.uid) AS opp, m.mid, (select login from moves join users using(uid) where mid=m.mid group by uid order by SUM(score) desc limit 1) as winner, u.uid FROM moves m JOIN (SELECT mid, uid FROM moves) AS l1 USING(mid) JOIN users u ON(l1.uid=u.uid AND m.uid<>u.uid) ORDER BY m.mid;

CREATE USER serviceaccount IDENTIFIED BY 'cZtx7b$xwkSL'; 

GRANT ALL PRIVILEGES ON scrabble.* TO serviceaccount; 

/* koniec widzowie */ 
