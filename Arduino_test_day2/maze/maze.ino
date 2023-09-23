

///////////////////// example_1 ////////////////////////////////////////////

// X,Y,x,y start with 0

//   _ _ _ _ _
//  | |  _   _|    ------->   13,8 ,10,2 ,12
//  | |_ _|   |    ------->   9 ,5 ,12,1 ,7
//  |       | |    ------->   1 ,2 ,2 ,3 ,9
//  | |_ _|_  |    ------->   9 ,5 ,6 ,5 ,3
//  |_|_ _ _ _|    ------->   11,14,10,10,6

//          _
//  |= - 1,  =  -2, =|-3, _ -4
//                 _      _        
//  |_ - 5, _| -6,  |-7, | -8
//          _               _
//  | | -9, _ -10, |_| -11, _| -12,
//   _        _            _
//  | | -13, |_ -14, -15, |_| -16

//  50x50

//////////////////////////////////////////////////////////////////////////////////////////

// ---> F_X
// <--- B_X
// ^ B_Y
// v F_Y


//int x = 200;
//int y = 200;


///////////////////////////////////////////// maze examples ///////////////////////////////

int maze[14][14] = {
          {14 ,2  ,10 ,10 ,2  ,10 ,2  ,10 ,12 ,14 ,10 ,10 ,10 , 7},
          {14 ,4  ,10 ,7  ,1  ,12 ,1  ,10 ,7  ,14 ,10 ,2  ,7  ,9},
          {14 ,10 ,7  ,9  ,1  ,10 ,6  ,13 ,9  ,14 ,7  ,9  ,11 , 9},
          {14 ,7 ,9  ,9  ,1  ,2  ,10 ,6  ,9  ,13 ,5  ,4  ,2  , 6},
          {13 ,9  ,1  ,15 ,6  ,9  ,14 ,10 ,6  ,5  ,10 ,10 ,4  ,7},
          {9  ,1  ,6  ,9  ,8  ,4  ,10 ,10 ,7  ,14 ,2  ,10 ,2  ,6},
          {11 ,9  ,8  ,6  ,9  ,8  ,2  ,7  ,9  ,14 ,15 ,12 ,1  ,12},
          {8  ,4  ,4  ,2  ,6  ,9  ,5  ,6  ,9  ,8  ,4  ,2  ,15 ,12},
          {5  ,10 ,12 ,9  ,8  ,4  ,10 ,10 ,4  ,3  ,13 ,11 ,9  ,16},
          {8  ,10 ,10 ,6  ,1  ,10 ,2  ,2  ,7  ,1  ,15 ,10 ,4  ,12},
          {1  ,7  ,13 ,14 ,3  ,8  ,6  ,9  ,9  ,11 ,1  ,12 ,8  ,12},
          {9  ,9  ,1  ,10 ,3  ,1  ,10 ,6  ,9  ,8  ,15 ,7  ,9  ,13},
          {9  ,11 ,9  ,8  ,6  ,5  ,10 ,10 ,4  ,3  ,9  ,5  ,6  ,9},
          {11 ,14 ,4  ,4  ,10 ,10 ,10 ,10 ,10 ,6  ,5  ,10 ,10 ,6}
        };

//int maze[10][10] = {
//          {13 ,8  ,10 ,10 ,10 ,10 ,10 ,2  ,2  ,7},
//          {9  ,9  ,13 ,14 ,2  ,10 ,7  ,11 ,11 ,9},
//          {5  ,15 ,15 ,2  ,3  ,14 ,15 ,12 ,13 ,9},
//          {14 ,6  ,9  ,11 ,9  ,13 ,9  ,8  ,6  ,9},
//          {13 ,8  ,6  ,13 ,11 ,5  ,15 ,4  ,7  ,9},
//          {5  ,3  ,13 ,5  ,10 ,2  ,15 ,12 ,9  ,9},
//          {14 ,3  ,1  ,12 ,14 ,3  ,9  ,13 ,11 ,9},
//          {8  ,4  ,3  ,8  ,7  ,9  ,5  ,15 ,12 ,9},
//          {1  ,12 ,5  ,3  ,9  ,9  ,14 ,15 ,12 ,9},
//          {5  ,10 ,12 ,11 ,11 ,11 ,14 ,4  ,10 ,6}
//        };

//int maze[10][10] = {
//          {8  ,7  ,14 ,2  ,7  ,14 ,10 ,7  ,8  ,12},
//          {9  ,1  ,7  ,11 ,1  ,10 ,10 ,3  ,5  ,7},
//          {11 ,9  ,11 ,8  ,4  ,10 ,7  ,1  ,12 ,9},
//          {8  ,6  ,13 ,5  ,10 ,7  ,9  ,5  ,2  ,6},
//          {5  ,7  ,5  ,10 ,7  ,1  ,15 ,10 ,3  ,13},
//          {8  ,4  ,7  ,13 ,5  ,6  ,9  ,14 ,4  ,3},
//          {11 ,8  ,6  ,1  ,7  ,14 ,15 ,10 ,2  ,3},
//          {8  ,6  ,8  ,6  ,9  ,8  ,15 ,2  ,3  ,9},
//          {1  ,10 ,6  ,13 ,5  ,6  ,9  ,9  ,11 ,9},
//          {11 ,14 ,10 ,4  ,10 ,10 ,6  ,5  ,10 ,6}
//        };
        

//int maze[8][8] = {
//          {8  ,7  ,8  ,2  ,10 ,7  ,13 ,13},
//          {9  ,5  ,6  ,11 ,13 ,5  ,3  ,9},
//          {9  ,8  ,2  ,10 ,4  ,10 ,4  ,3},
//          {9  ,9  ,9  ,8  ,7  ,13 ,8  ,3},
//          {9  ,9  ,11 ,5  ,3  ,9  ,5  ,3},
//          {9  ,1  ,10 ,2  ,3  ,5  ,10 ,3},
//          {9  ,11 ,13 ,11 ,5  ,10 ,2  ,3},
//          {11 ,14 ,4  ,10 ,10 ,10 ,6  ,11}
//        };
        
//int maze[8][8] = {
//          {13 ,8  ,2  ,10 ,10 ,2  ,10 ,7},
//          {9  ,9  ,5  ,10 ,7  ,9  ,13 ,9},
//          {9  ,5  ,7  ,13 ,1  ,6  ,9  ,9},
//          {9  ,8  ,3  ,9  ,9  ,8  ,4  ,6},
//          {5  ,6  ,9  ,9  ,11 ,1  ,10 ,12},
//          {14 ,10 ,6  ,1  ,10 ,4  ,10 ,7},
//          {8  ,10 ,2  ,6  ,14 ,10 ,2  ,3},
//          {5  ,10 ,4  ,10 ,10 ,10 ,6  ,11}
//        };

//int maze[5][5] =  { 
//          {13,8,10,2,12},
//          {9,5,12,1,7},
//          {1,2,2,3,9},
//          {9,5,6,5,3},
//          {11,14,10,10,6},
//        };
        

int maze_size = 14; // change vaule based on maze_size

int terminal_maze[ 29][ 29]; // change vaule based on maze_size ( value = maze_size*2 +1 ) 
int edit_terminal_maze[ 2][ 29][ 29];  // change vaule based on maze_size ( value = maze_size*2 +1 ) 
//
////int edit_terminal_maze1[ 21][ 21];  // change vaule based on maze_size ( value = maze_size*2 +1 ) 
////int edit_terminal_maze2[ 21][ 21]; 
////int edit_terminal_maze3[ 21][ 21]; 
////int edit_terminal_maze4[ 21][ 21]; 
////int edit_terminal_maze5[ 21][ 21]; 
////int edit_terminal_maze6[ 21][ 21]; 
////int edit_terminal_maze7[ 21][ 21]; 
////int edit_terminal_maze8[ 21][ 21]; 
////int edit_terminal_maze9[ 21][ 21]; 



int maze_lenght = maze_size*2 +1;     
        
int X_coordinate = 225 ;
int Y_coordinate= 225;
int X_ =0;
int Y_ =0;

char state[4] = "F_Y";
int count =1;


int F_sensor = 0;
int R_sensor = 0;
int L_sensor = 0;

int Path_find_1 = 0;
int maze_path = 0;
int maze_solved = 0;

int movement_count =0;

int turn_points[100][2];
int t_point = 0;
int points[100][2];
int ij =1;
int operation = 1;
int count_operation;
int y_coord;
int x_coord;

int loop_condition = 1;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  for ( int i=0; i<maze_lenght; i=i+1) {
    for ( int j=0; j<maze_lenght; j=j+1) {
      if ( i==0 || i == maze_lenght -1 || j==0 || j==maze_lenght -1 ) {
            terminal_maze[i][j] = 101;
        }
        else{
          terminal_maze[i][j] = -1;
        }
    }
  }
  terminal_maze[ 0][ 1] = 101;
  terminal_maze[ 1][ 1] = 1;

  
  Path_find_1 = 1; 

  Serial.println("strat ................");

}

void loop() {
  // put your main code here, to run repeatedly:

  if (loop_condition ==  1 ) {

  int x = 200;
  int y = 200;  
    
  Sensor_check();
  
  Fill_box();

  Serial.println("------------------------------------------------------------------------------------");
  Serial.println("");
  for ( int i=0; i<maze_lenght; i=i+1) {
    for ( int j=0; j<maze_lenght; j=j+1) {
      char value_[20];
      sprintf( value_, "%d\t",terminal_maze[i][j]);
      Serial.print(value_);
    }
    Serial.println("");
  }
  Serial.println("-------------------------------------------------------------------------------------");
  Serial.println("");
  Serial.println("");

  delay(10);

  if ( maze_solved == 0){
    if ( Path_find_1 == 1) {
      move_mouse();
    }
    else {
      move_back();
    }
  }
  else {
      Serial.println("maze solved----------------------\n");

      char value_[20];
      sprintf(value_, "\nmovement_count = %d\n", movement_count);
      Serial.print(value_);
      
      
      for ( int i=0; i<=t_point; i=i+1) {
        for ( int j=0; j<maze_lenght; j=j+1) {
          for ( int k=0; k<maze_lenght; k=k+1) {
            edit_terminal_maze[i][j][k] = terminal_maze[j][k];
          }
        }
        
      }
      
      
      Serial.println("--------------------------------0 maze -----------------------------------------------\n");
        
      for ( int j=0; j<maze_lenght; j=j+1) {
        for ( int k=0; k<maze_lenght; k=k+1) {
          char value_[20];
          sprintf(value_,  "%d\t",terminal_maze[j][k]);
          Serial.print(value_);
        }
        Serial.println("");
      }
      Serial.println("-------------------------------------------------------------------------------------");
      Serial.println("");
      Serial.println("");
        
      
      
      for ( int i=0; i<=t_point; i=i+1) {
        char value_[50];
        sprintf(value_, "----------------- %d maze breaked by [ %d, %d] -------------\n", i+1, turn_points[ i][0], turn_points[ i][1]);
        Serial.print(value_);
        Path_manage( i, turn_points[ i][0], turn_points[ i][1]);
        
        for ( int j=0; j<maze_lenght; j=j+1) {
          for ( int k=0; k<maze_lenght; k=k+1) {
            char value_[20];
            sprintf( value_, "%d\t",edit_terminal_maze[ i][j][k]);
            Serial.print(value_);
          }
          Serial.println("");
        }
        Serial.println("-------------------------------------------------------------------------------------");
        Serial.println("");
        Serial.println("");
      }
      
      Short_path_find(6,6);
      
      loop_condition = 0;
      
    }

    if ( Y_ == (maze_size/2)-1 && X_ == (maze_size/2)-1) {
      maze_path = maze_path + 1;
    }
    
    if ( X_==0 && Y_==0 && maze_path > 0 ) {
      maze_solved = 1;
    }

    char value_[20];
    sprintf(value_, "count number = %d \n", count);
    Serial.print(value_);

    
  }
  

}

int move_mouse() {
  int terminalX_coord = X_*2 +1;
  int terminalY_coord = Y_*2 +1;
  
  if ( strcmp( state, "F_Y") == 0) {
    // turning point search
    if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1) {
      Serial.println("terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1\n");
      turn_points[ t_point][0] = terminalY_coord +2;
      turn_points[ t_point][1] = terminalX_coord;
      t_point = t_point +1;
      } 
    } 
    if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord;
        turn_points[ t_point][1] = terminalX_coord +2;
        t_point = t_point +1;
      }
    } 
    if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0) {
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord;
        turn_points[ t_point][1] = terminalX_coord -2;
        t_point = t_point +1;
      }
    }
  
    if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y_= Y_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
    } 
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X_= X_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X_= X_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
      strcpy( state, "B_Y");
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");   
    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101) {
        strcpy( state, "B_Y");
        Path_find_1 = 0;
        Serial.println("F_Y change move fn to move_back fn\n");
    }
    else {
        Serial.println("11111111111111111\n");
    }
    
  }
  else if ( strcmp( state, "B_Y") == 0) { 
    // turning point search 
    if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord -2;
        turn_points[ t_point][1] = terminalX_coord;
        t_point = t_point +1;
      }
    } 
    if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord;
        turn_points[ t_point][1] = terminalX_coord +2;
        t_point = t_point +1;
      }
    } 
    if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0) {
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord;
        turn_points[ t_point][1] = terminalX_coord -2;
        t_point = t_point +1;
      }
    }
    
    if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y_= Y_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X_= X_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X_= X_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 ) {
      strcpy( state, "F_Y");
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101) {
      strcpy( state, "F_Y");
      Path_find_1 = 0;
      Serial.println("B_Y change move fn to move_back fn\n");
    }
    else {
      Serial.println("2222222222222222222\n");      
    }
        
  }
  else if ( strcmp( state, "F_X") == 0) {
    // turning point search
    if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] < count+1) {
        Serial.println("terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord +2;
        turn_points[ t_point][1] = terminalX_coord;
        t_point = t_point +1;
      } 
    } 
    if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] < count+1) {
        Serial.println("terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord -2;
        turn_points[ t_point][1] = terminalX_coord;
        t_point = t_point +1;
      }
    } 
    if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] < count+1) {
        Serial.println("terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord;
        turn_points[ t_point][1] = terminalX_coord +2;
        t_point = t_point +1;
      }
    }
    
    if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X_= X_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
    } 
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y_= Y_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y_= Y_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
      strcpy( state, "B_X");
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101) {
      strcpy( state, "B_X");
      Path_find_1 = 0;
      Serial.println("F_X change move fn to move_back fn\n");
    }
    else {
      Serial.println("33333333333333333333333\n");      
    }
    
  }
  else if ( strcmp( state, "B_X") == 0) {
    // turning point search
    if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord +2;
        turn_points[ t_point][1] = terminalX_coord;
        t_point = t_point +1;
      } 
    } 
    if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord -2;
        turn_points[ t_point][1] = terminalX_coord;
        t_point = t_point +1;
      }
    } 
    if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0) {
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1) {
        Serial.println("terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1\n");
        turn_points[ t_point][0] = terminalY_coord;
        turn_points[ t_point][1] = terminalX_coord -2;
        t_point = t_point +1;
      }
    }
    
    if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X_= X_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
    } 
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y_= Y_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y_= Y_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
      strcpy( state, "F_X");
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");     
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101) {
      strcpy( state, "F_X");
      Path_find_1 = 0;
      Serial.println("B_X change move fn to move_back fn\n");
    }
    else {
      Serial.println("444444444444444444444\n");      
    }
    
  }
      
}


int move_back() {
	int terminalX_coord = X_*2 +1;
	int terminalY_coord = Y_*2 +1;	
	
	
	if ( strcmp( state, "F_Y") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1 ) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord] ;
				strcpy( state, "F_Y");
				Y_= Y_+1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("1. F_Y change move_back fn to move fn\n");
			}			
		} 
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1 ) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X_= X_-1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("2. F_Y change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X_= X_+1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("3. F_Y change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 ) {
			if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y_= Y_+1;
				movement_count = movement_count +1;
				Serial.println("F_Y to F_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X_= X_-1;
				movement_count = movement_count +1;
				Serial.println("F_Y to B_X moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2] ;
				strcpy( state, "F_X");
				X_= X_+1;
				movement_count = movement_count +1;
				Serial.println("F_Y to F_X moving back\n");
			}
			else {
				Serial.println("------F_Y--------\n");
			}
			
		}
		
	}
	else if ( strcmp( state, "B_Y") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord] ;
				strcpy( state, "B_Y");
				Y_= Y_-1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("1. B_Y change move_back fn to move fn\n");
			}
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X_= X_+1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("2. B_Y change move_back fn to move fn\n");
			}
		}
		
		if (  Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];				
				strcpy( state, "B_X");
				X_= X_-1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("3. B_Y change move_back fn to move fn\n");
			}
		}
		
		if ( Path_find_1 == 0) {
			if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y_= Y_-1;
				movement_count = movement_count +1;
				Serial.println("B_Y to B_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X_= X_+1;
				movement_count = movement_count +1;
				Serial.println("B_Y to F_X moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X_= X_-1;
				movement_count = movement_count +1;
				Serial.println("B_Y to B_X moving back\n");
			}
			else {
				Serial.println("------B_Y--------\n");
			}
			
		}
								
	}
	else if ( strcmp( state, "F_X") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X_= X_+1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("1. F_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord] ;
				strcpy( state, "F_Y");
				Y_= Y_+1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("2. F_X change move_back fn to move fn\n");
			}
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y_= Y_-1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("3. F_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X_= X_+1;
				movement_count = movement_count +1;
				Serial.println("F_X to F_X moving back\n");
			} 
			else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y_= Y_+1;
				movement_count = movement_count +1;
				Serial.println("F_X to F_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y_= Y_-1;
				movement_count = movement_count +1;
				Serial.println("F_X to B_Y moving back\n");
			}
			else {
				Serial.println("------F_X--------\n");
			}
			
		}
		
	}
	else if ( strcmp( state, "B_X") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X_= X_-1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("1. B_X change move_back fn to move fn\n");
			}			
		} 
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y_= Y_-1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("2. B_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y_= Y_+1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				Serial.println("3. B_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X_= X_-1;
				movement_count = movement_count +1;
				Serial.println("B_X to B_X moving back\n");
			} 
			else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y_= Y_-1;
				movement_count = movement_count +1;
				Serial.println("B_X to B_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y_= Y_+1;
				movement_count = movement_count +1;
				Serial.println("B_X to F_Y moving back\n");
			}
			else {
				Serial.println("------B_X--------\n");
			}
			
		}
				
	}
	
	
}



int Sensor_check() {
  int Y_coord = Y_;
  int X_coord = X_;
  
  if ( strcmp( state, "F_Y") == 0) {
    if ( maze[ Y_coord][ X_coord] == 1) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 2) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 3) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 4) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 5) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 6) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 7) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 8) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 9) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 10) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 11) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 12) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 13) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 14) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 15) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 16) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    
  }
  else if ( strcmp( state, "B_Y") == 0) {
    if ( maze[ Y_coord][ X_coord] == 1) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 2) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 3) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 4) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 5) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 6) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 7) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 8) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 9) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 10) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 11) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 12) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 13) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 14) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 15) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 16) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    
  }
  else if ( strcmp( state, "F_X") == 0) {
    if ( maze[ Y_coord][ X_coord] == 1) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 2) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 3) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 4) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 5) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 6) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 7) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 8) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 9) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 10) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 11) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 12) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 13) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 14) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 15) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 16) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    
  }
  else if ( strcmp( state, "B_X") == 0) {
    if ( maze[ Y_coord][ X_coord] == 1) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 2) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 3) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 4) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 5) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 6) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 7) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 8) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 9) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 10) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 11) {
      F_sensor = 1;
      R_sensor = 0;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 12) {
      F_sensor = 0;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 13) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 14) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    else if ( maze[ Y_coord][ X_coord] == 15) {
      F_sensor = 0;
      R_sensor = 0;
      L_sensor = 0;
    }
    else if ( maze[ Y_coord][ X_coord] == 16) {
      F_sensor = 1;
      R_sensor = 1;
      L_sensor = 1;
    }
    
  }
  
}


int Fill_box() {
  int terminalX_coord = X_*2 +1;
  int terminalY_coord = Y_*2 +1;
  
  if ( strcmp( state, "F_Y") == 0) {  
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    
  }
  else if ( strcmp( state, "B_Y") == 0) {
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    
  }
  else if ( strcmp( state, "F_X") == 0) {
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    
  }
  else if ( strcmp( state, "B_X") == 0) {
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  
}

int Path_manage( int T_poinit, int int_y_coord, int int_x_coord) {
    
  points[0][0] = int_y_coord;
  points[0][1] = int_x_coord;

  count_operation =0;

  while (1) {
    
    if ( count_operation >= ij) {
//      Serial.println("break\n");
      break;
    }
    
    y_coord = points[count_operation][0];
    x_coord = points[count_operation][1];
    
//    Serial.println("%d,%d\n", y_coord, x_coord );
  
    operation = 1;
  
    while ( operation == 1) {
      operation =0;
      Path_cal( T_poinit, y_coord, x_coord);
//      Serial.println("\n");
    }
    
    count_operation = count_operation +1;
    
  }
  
  Serial.println("path break points, ");
  for ( int i=0; i<=ij; i=i+1) { 
    char value_[20];   
    sprintf(value_ ,"%d-[%d , %d] ", i, points[i][0], points[i][1]);
    Serial.println(value_);
  }
  Serial.println("\n");
  
}


int Path_cal( int T_point, int y, int x) {
  int count_points =0;

  int count_number = edit_terminal_maze[T_point][y][x];

  if ( edit_terminal_maze[T_point][y +1][x] == 0 && edit_terminal_maze[T_point][y +2][x] > count_number +1) {
//    Serial.println( "maze[y +1][x] == 0 and maze[y +2][x] > count_number\n" );
    if ( count_points ==0) {
//      Serial.println( "%d , %d \n", y_coord, x_coord);
      edit_terminal_maze[T_point][y +2][x] = count_number +1;
      y_coord = y +2;
      operation = 1;
      count_points = 1;
    }
    else {
      points[ij][0] = y;
      points[ij][1] = x;
      ij = ij +1;
    }
  }

  if ( edit_terminal_maze[T_point][y -1][x] == 0 && edit_terminal_maze[T_point][y -2][x] > count_number +1) {
//    Serial.println( "maze[y -1][x] == 0 and maze[y -2][x] > count_number\n" );
    if ( count_points ==0) {
//      Serial.println( "%d , %d \n", y_coord, x_coord);
      edit_terminal_maze[T_point][y -2][x] = count_number +1;
      y_coord = y -2;
      operation = 1;
      count_points = 1;
    }
    else {
      points[ij][0] = y;
      points[ij][1] = x;
      ij = ij +1;
    }
  }

  if ( edit_terminal_maze[T_point][y][x +1] == 0 && edit_terminal_maze[T_point][y][x +2] > count_number +1) {
//    Serial.println( "maze[y][x -1] == 0 and maze[y][x -2] > count_number\n" );
    if ( count_points ==0) {
//      Serial.println( "%d , %d \n", y_coord, x_coord);
      edit_terminal_maze[T_point][y][x +2] = count_number +1;
      x_coord = x +2;
      operation = 1;
      count_points = 1;
    }
    else {
      points[ij][0] = y;
      points[ij][1] = x;
      ij = ij +1;
    }
  }

  if ( edit_terminal_maze[T_point][y][x -1] == 0 && edit_terminal_maze[T_point][y][x -2] > count_number +1) {
//    Serial.println( "maze[y][x -1] == 0 and maze[y][x -2] > count_number\n" );
    if ( count_points ==0) {
//      Serial.println( "%d , %d \n", y_coord, x_coord);
      edit_terminal_maze[T_point][y][x -2] = count_number +1;
      x_coord = x -2;
      operation = 1;
      count_points = 1;
    }
    else {
      points[ij][0] = y;
      points[ij][1] = x;
      ij = ij +1;
    }
  }
}


int Short_path_find( int y, int x) {
  int given_Xpoint = x;
  int given_Ypoint = y;
  int Mnum = 2000;
  int Mint =0;
  
  int given_T_Xpoint = given_Xpoint *2 +1;
  int given_T_Ypoint = given_Ypoint *2 +1;
  
  int Short_path_points[40][2];
  
  for ( int i=0; i<=t_point; i=i+1) {
    if ( edit_terminal_maze[ i][ given_T_Ypoint][ given_T_Xpoint] < Mnum) {
      Mnum = edit_terminal_maze[ i][ given_T_Ypoint][ given_T_Xpoint];
      Mint = i;
    }
  }
  
  Short_path_points[0][0] = given_T_Ypoint;
  Short_path_points[0][1] = given_T_Xpoint;
  
  int current_Xpoint = given_T_Xpoint;
  int current_Ypoint = given_T_Ypoint;
  int current_count = Mnum;
  int current_i = 0;
  
  while ( current_count > 1) {
//    Serial.println("%d\n", current_count);
    current_i = current_i +1;
    
    if ( edit_terminal_maze[ Mint][ current_Ypoint -1][ current_Xpoint] ==0 && edit_terminal_maze[ Mint][ current_Ypoint -2][ current_Xpoint] == current_count-1) {
      Short_path_points[current_i][0] = current_Ypoint; 
      Short_path_points[current_i][1] = current_Xpoint;   
      current_Ypoint = current_Ypoint -2;
      current_count = current_count -1;     
    }
    else if ( edit_terminal_maze[ Mint][ current_Ypoint +1][ current_Xpoint] ==0 && edit_terminal_maze[ Mint][ current_Ypoint +2][ current_Xpoint] == current_count-1) {
      Short_path_points[current_i][0] = current_Ypoint; 
      Short_path_points[current_i][1] = current_Xpoint;
      current_Ypoint = current_Ypoint +2;
      current_count = current_count -1;
    }
    else if ( edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint -1] ==0 && edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint -2] == current_count-1) {
      Short_path_points[current_i][0] = current_Ypoint; 
      Short_path_points[current_i][1] = current_Xpoint;
      current_Xpoint = current_Xpoint -2;
      current_count = current_count -1;
    }
    else if ( edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint +1] ==0 && edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint +2] == current_count-1) {
      Short_path_points[current_i][0] = current_Ypoint; 
      Short_path_points[current_i][1] = current_Xpoint;
      current_Xpoint = current_Xpoint +2;
      current_count = current_count -1;
    }
        
  }

  char value_[20];
  sprintf(value_, "Short path to run - [ %d, %d] \n", y, x);
  Serial.println(value_);
  for ( int i=1; i<Mnum; i=i+1) {
    char value_[20];
    sprintf(value_, "%d-[ %d, %d], ", i, (Short_path_points[i][0] -1)/2, (Short_path_points[i][1] -1)/2);
    Serial.println(value_);
  }
    
  

}

int sensor_check( int X_coord, int Y_coord) {
  int terminalX_coord = X_coord *2 +1;
  int terminalY_coord = Y_coord *2 +1;
  
  if ( maze[ Y_coord][ X_coord] == 1) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
  }
  else if ( maze[ Y_coord][ X_coord] == 2) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 3) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 4) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 5) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 6) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 7) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 8) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
    
  } 
  else if ( maze[ Y_coord][ X_coord] == 9) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 10) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 11) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 12) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 13) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 14) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 15) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
    
  }
  else if ( maze[ Y_coord][ X_coord] == 16) {
    terminal_maze[ terminalY_coord][ terminalX_coord] = count;
    terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
  
}
