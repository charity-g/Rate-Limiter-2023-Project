#Rate Limiter Project
created by Charity Grey (c) 2023
## Project context:

Server is responding to requests from different users, and we must manage different requests and queue them equally without letting one user clog up the server with all their requests


For example:
Here the 3 users are making multiple requests to the server, some more than the other. To prevent overwhelming our server, we must devise a way to fairly distribute and queue the requests. Lets say Users 1 and 2 make requests at reasonable intervals, however out of nowhere, User 3 makes way more requests than the server can handle. We should cut off User 3's requests and prevent the server from responding to just user 3's requests so we don't block off service to user 1 and 2.


## Project Solution - variation 1
### Demo method: Using the terminal

There are 2 servers that can handle 1 request each at the same time.
The server finishes after a random period of time from 0.5 seconds to 2 seconds, and after this period it can handle new requests 

Instead of just queuing the requests in order of recieving it, we need to manage them.

How will we set this environment up?
Requirements: 
- Users must be identified
   - Must be created and instantiated?
- Servers must operate on their own (do I need threading??)
   - Require two concurrent servers
   - Require event-driven programming
- Design of rate limiter
   - one single rate limiter that receives requests, queues organizes requests, and also sends requests to server to be processed
