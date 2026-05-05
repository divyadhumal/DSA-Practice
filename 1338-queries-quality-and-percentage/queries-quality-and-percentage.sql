-- Write your PostgreSQL query statement below
SELECT query_name,
       ROUND(SUM(quality)::numeric / COUNT(*), 2) AS quality,
       ROUND(SUM(is_poor)::numeric * 100 / COUNT(*), 2) AS poor_query_percentage
FROM (
    SELECT query_name,
           rating::numeric / position AS quality,
           CASE WHEN rating < 3 THEN 1 ELSE 0 END AS is_poor
    FROM Queries
) AS new
GROUP BY query_name;