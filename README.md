#Rate Limiter Project
created by Charity Grey (c) 2023

# Table of Contents
1. [Project Context](#project-context)
2. [Credits](#credits)

## Project context:
[Back to top](#table-of-contents)

Database Server is responding to querying requests from different users + computers, and we must manage different requests and queue them equally without letting one user clog up the server with all their requests

REQUIREMENTS:
- Each “company” may have different users (computers) all requesting queries 
- Queries may finish at different times
- Two CPUs(for now) that can process one query request each at a time
- Manage different requests and queue them equally based on time frame, incoming 
- The database manager is ACID compliant, so we do not have to worry about consistency. In event that the server takes in a query that fails, it will seperately contact the client.

For example:
Here the 3 users are making multiple requests to the server, some more than the other. To prevent overwhelming our server, we must devise a way to fairly distribute and queue the requests. Lets say Users 1 and 2 make requests at reasonable intervals, however out of nowhere, User 3 makes way more requests than the server can handle. We should cut off some of User 3's requests and prevent the server from responding to just user 3's requests so we don't block off service to user 1 and 2.

![Diagram of Server connected to User 1, User 2 and User 3](./ContextDiagrams/diagram1.png)

Advanced version: for future implementation. TODO 22Oct23;


![Diagram of Server connected to User 1, Company 1 and Company 2. Company 1 and 2 branch off into more users.](./ContextDiagrams/diagram2.png)



# Credits
[Back to top](#table-of-contents)

- https://towardsdatascience.com/designing-a-rate-limiter-6351bd8762c6
- https://www.youtube.com/watch?v=FU4WlwfS3G0
- https://github.com/charity-g/CPSC221/blob/main/pa3/qtvar.h
- https://blog.logrocket.com/rate-limiting-node-js/ 