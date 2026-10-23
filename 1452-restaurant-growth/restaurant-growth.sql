WITH daily AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
)
SELECT
    d1.visited_on,
    SUM(d2.amount) AS amount,
    ROUND(AVG(d2.amount), 2) AS average_amount
FROM daily d1
JOIN daily d2
    ON d1.visited_on - d2.visited_on BETWEEN 0 AND 6
GROUP BY d1.visited_on
HAVING COUNT(*) = 7
ORDER BY d1.visited_on;
