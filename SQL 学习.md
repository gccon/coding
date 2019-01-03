SQL 学习

```sql
select 列名字
from 表名字;

SELECT prod_name    --//返回这一列所有值，但顺序不定
FROM Products;     --// select from 不区分大小写，而且可以写在一行

SELECT a,b,c    --//检索多个列，没个列逗号隔开，最后不要有逗号
FROM T;

SELECT *    --// *表示通配符，检索所有列
FROM T;

SELECT DISTINCT a,b,c  --// 显示的a,b,c列的每一行是唯一的，也就是去重复的作用
FROM T;

SELECT TOP 5 a --/检索a列中前5行
FROM T;

SELECT a   --// 效果同上 用于mysql
FROM T
LIMIT 5;

SELECT a   --# 效果同上 用于Oracle ROWNUM是行计数器
FROM T
WHERE ROWNUM <=5 ;

SELECT a
FROM T
LIMIT 5 OFFSET 5;  --// offset偏移多少， limit限制返回的行数，除非不够

--# // 第一个行是第0行

```



order排序

```sql
SELECT a
FROM T
ORDER BY a; --order by语句按照a名字排序，字母序，order by需要放在select语句的最后

SELECT a,b,c
FROM T
ORDER BY a,b;  -- 选出的3列按照a列从小到大排，如果a列一样则按照b列的从小到大排


SELECT a,b,c
FROM T
ORDER BY a DESC， b; -- DESC表示a按照降序来排， b还是默认的升序
--descending 降序 ascending 升序
```

过滤数据 WHERE 子句

```sql
SELECT a, b
FROM T
WHERE a = 1.00; --检索出a=1.00的那一行（可能几行） where放在order by之前

SELECT name,price
FROM T
WHERE price >= 10; --检索所有price大于10的行 

SELECT name, price
FROM T
WHERE name <> 'guoylong'; -- 检索所有用户名不为guoylong的， 注意单引号引起来

SELECT name, price
FROM T
WHERE price BETWEEN 5 AND 10

SELECT name
FROM T
WHERE phonenum is NULL; -- 选择phoneNUM这一列为空的name, NULL表示为空
```

<> 不等于  < <= > >= BETWEEN 

高级数据过滤

```sql
-- OR AND  IN IN操作符表示在什么之中选择，类似OR 
-- NOT 用来否定
SELECT a,b,c
FROM T
WHERE name IN ('gyl','ylg')
ORDER BY name;

SELECT a,b,c
FROM T
WHERE name = 'gyl' or name = 'ylg'  -- 与上面等价
ORDER BY name;

SELECT a,b,c
FROM T
WHERE NOT name = 'gyl'; -- name 不为gyl的 类似 <>
```



通配符 LIKE

