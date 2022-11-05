Git Workflow
------------

     ------------------------------------ clone -----------
     |                                                    |
     v                                                    |
-----------------------------------------          ----------------
|            |            |             |          |              |
| Working    |  Staging   |  Local      |          |  Remote	  |
| Directory  |  Area      |  Repository |-- push ->|  Repository  |
|            |            |             |          |              |
-----------------------------------------          ----------------
  |   |          ^    |            ^  ^
  |   |          |    |            |  | 
  |   --- add ---     --- commit ---  |                               
  |                                   |
  -------------- commit -a ------------
  
  
Some basic git Commands
-----------------------

git status                                  //show if something changed
git add -A                                  //adds all items to stagin area
git add <filename>                          //adds file to staging area
git config -global user.name "Harry Ringer" 
git congig -global user.email hr@emailaddress.com
git commit                                  //adds everything from staging area to local repository
git push                                    //move from local repository to remote repository
git clone <repository>                      //clone from a repository (use git or https)

