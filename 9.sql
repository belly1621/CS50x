SELECT DISTINCT name
FROM people JOIN stars on people.id = stars.person_id
JOIN movies on movies.id = stars.movie_id
WHERE year = 2004
ORDER BY birth;