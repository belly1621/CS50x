-- Keep a log of any SQL queries you execute as you solve the mystery.

-- get a baseline of what happened the day of the incident
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = "Humphrey Street";
-- result: theft at 10:15am at the Humphrey St Bakery, 3 witnesses all mention bakery, littering at 4:36pm

-- view witness statements from bakery
SELECT transcript
FROM interviews
WHERE month = 7 AND day = 28;
-- result: within 10 minutes of 10:15am thief enters vehicle and leaves from parking lot
-- result: thief seen withdrawing from ATM on Leggett Street (early morning)
-- result: thief made a phone call and requested earliest flight out of fiftyville (7/29), accomplice most likely purchased ticket

-- check security for footage from 10:15am to 10:25am getting activity and license plate within time frame
SELECT activity, license_plate
FROM bakery_security_logs
WHERE month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25;
-- Results:
-- Exit - 5P2BI95
-- Exit - 94KL13X
-- Exit - 6P58WS2
-- Exit - 4328GD8
-- Exit - G412CB7
-- Exit - L93JTIZ
-- Exit - 322W7JE
-- Exit - 0NTHK55

-- check ATM logs for withdrawal from Leggett Street (Early Morning to before time of robbery)
SELECT account_number, transaction_type
FROM atm_transactions
WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28
AND transaction_type = "withdraw";
-- Results:
-- withdraw - 28500762
-- withdraw - 28296815
-- withdraw - 76054385
-- withdraw - 49610011
-- withdraw - 16153065
-- withdraw - 25506511
-- withdraw - 81061156
-- withdraw - 26013199

-- check for phone calls less than a minute around time of robbery - 10:15am
SELECT caller, receiver,
FROM phone_calls
WHERE month = 7 AND day = 28
AND duration <= 60;
-- Results:
-- caller: (130) 555-0289 // receiver: (996) 555-8899
-- caller: (499) 555-9472 // receiver: (892) 555-8872
-- caller: (367) 555-5533 // receiver: (375) 555-8161
-- caller: (609) 555-5876 // receiver: (389) 555-5198
-- caller: (499) 555-9472 // receiver: (717) 555-1342
-- caller: (286) 555-6063 // receiver: (676) 555-6554
-- caller: (770) 555-1861 // receiver: (725) 555-3243
-- caller: (031) 555-6622 // receiver: (910) 555-3251
-- caller: (826) 555-1652 // receiver: (066) 555-9701
-- caller: (338) 555-6650 // receiver: (704) 555-2131

-- check for earliest flight at each airport
SELECT origin_airport_id, destination_airport_id, hour, minute
FROM airports JOIN flights ON flights.origin_airport_id = airports.id
WHERE month = 7 AND day = 29
ORDER BY hour ASC;
-- Results:
-- origin airport: 8 // destination airport: 4 // time: 08:20 (8:20am)

-- find destination airport name / city using destination airport id = 4
SELECT full_name, city
FROM airports
WHERE id = 4;
-- Result: LaGuardia Airport - New York City

-- get flight ID from flight
SELECT id
FROM flights
WHERE origin_airport_id = 8 AND destination_airport_id = 4
AND hour = 8;
-- Result: flight ID = 36

-- get name from license plates leaving bakery
SELECT name
FROM people
WHERE license_plate = "94KL13X";
--Results:
-- 5P2BI95 = Vanessa
-- 94KL13X = Bruce
-- 6P58WS2 = Barry
-- 4328GD8 = Luca
-- G412CB7 = Sofia
-- L93JTIZ = Iman
-- 322W7JE = Diana
-- 0NTHK55 = Kelsey

--Try to find who missing plate belongs to using passport numbers
SELECT phone_number
FROM people
WHERE license_plate = "94KL73X";

-- pull names from flight 36 that match license plates from bakery security
SELECT name
FROM people JOIN passengers ON passengers.flight_id
WHERE flight_id = 36 AND license_plate =

-- get person_id from ATM transactions, had to do this one at a time
SELECT person_id, name, account_number
FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 26013199;
--Results:
--person id = 467400 / name = Luca / account = 28500762
--person id = 395717 / name = Kenny / account = 28296815
--person id = 449774 / name = Taylor / account = 76054385
--person id = 686048 / name = Bruce / account = 49610011
--person id = 458378 / name = Brooke / account = 16153065
--person id = 396669 / name = Iman / account = 25506511
--person id = 438727 / name = Benista / account = 81061156
--person id = 514354 / name = Diana / account = 26013199

-- match names with phone numbers from the call log of less than a minute, had to do this one at a time again
SELECT name, phone_number
FROM people
WHERE name = 'Diana';
--Results:
--Luca = (389) 555-5198
--Kenny = (826) 555-1652
--Taylor = (286) 555-6063
--Bruce = (367) 555-5533
--Brooke = (122) 555-4581
--Iman = (829) 555-5269
--Benista = (338) 555-6650
--Diana = (770) 555-1861

            -- caller: Bruce (367) 555-5533 // receiver: Robin (375) 555-8161

            -- caller: Taylor (286) 555-6063 // receiver: James (676) 555-6554

            -- caller: Diana (770) 555-1861 // receiver: Philip (725) 555-3243

            -- caller: Kenny (826) 555-1652 // receiver: Doris (066) 555-9701

            -- caller: Benista (338) 555-6650 // receiver: Anna (704) 555-2131

--Results = one of the following is the thief
--Bruce, Diana,- made calls less than a minute, and withdrew from Leggett ATM and left the bakery lot

--Check for names of receivers of calls to determine possible accomplice list.
SELECT name
FROM people
WHERE phone_number = '(704) 555-2131';
--Results:
--Possible criminal pairs:
--Bruce/Robin
--Taylor/James
--Diana/Philip
--Kenny/Doris
--Benista/Anna

--Get passport numbers for everyone
SELECT passport_number
FROM people
WHERE name = 'Anna';
--Results:
--Bruce (5773159633) / Robin (BLANK)
--Taylor (1988161715) / James (2438825627)
--Diana (3592750733) / Philip (3391710505)
--Kenny (9878712108) / Doris (7214083635)
--Benista (9586786673) / Anna (BLANK)

--pair passport numbers with seats on flight 36
SELECT seat
FROM passengers
WHERE flight_id = 36 AND passport_number = 9586786673;
--Results:
--Bruce - 4A / Robin not on plane
--Taylor - 6D / james not on plane
--Diana - not on plane / philip not on plane
--Kenny - 7A / Doris - 2A
--Benista not on plane / Anna not on plane

-- FINAL RESULT:
-- Must be Bruce and Robin because Bruce is the only one who left the parking lot, made a call less than 60 seconds, withdrew from Leggett ATM, and is on flight 36
