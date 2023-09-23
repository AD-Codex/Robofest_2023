
///////////////////////////////////////////// maze examples ///////////////////////////////

//int maze[14][14] = {
//          {14 ,2  ,10 ,10 ,2  ,10 ,2  ,10 ,12 ,14 ,10 ,10 ,10 , 7},
//          {14 ,4  ,10 ,7  ,1  ,12 ,1  ,10 ,7  ,14 ,10 ,2  ,7  ,9},
//          {14 ,10 ,7  ,9  ,1  ,10 ,6  ,13 ,9  ,14 ,7  ,9  ,11 , 9},
//          {14 ,10 ,9  ,9  ,1  ,2  ,10 ,6  ,9  ,13 ,5  ,4  ,2  , 6},
//          {13 ,9  ,1  ,15 ,6  ,9  ,14 ,10 ,6  ,5  ,10 ,10 ,4  ,7},
//          {9  ,1  ,6  ,9  ,8  ,4  ,10 ,10 ,7  ,14 ,2  ,10 ,2  ,6},
//          {11 ,9  ,8  ,6  ,9  ,8  ,2  ,7  ,9  ,14 ,15 ,12 ,1  ,12},
//          {8  ,4  ,4  ,2  ,6  ,9  ,5  ,6  ,9  ,8  ,4  ,2  ,15 ,12},
//          {5  ,10 ,12 ,9  ,8  ,4  ,10 ,10 ,4  ,3  ,13 ,11 ,9  ,10},
//          {8  ,10 ,10 ,6  ,1  ,10 ,2  ,2  ,7  ,1  ,15 ,10 ,4  ,12},
//          {1  ,7  ,13 ,14 ,3  ,8  ,6  ,9  ,9  ,11 ,1  ,12 ,8  ,12},
//          {9  ,9  ,1  ,10 ,3  ,1  ,10 ,6  ,9  ,8  ,15 ,7  ,9  ,13},
//          {9  ,11 ,9  ,8  ,6  ,5  ,10 ,10 ,4  ,3  ,9  ,5  ,6  ,9},
//          {11 ,14 ,4  ,4  ,10 ,10 ,10 ,10 ,10 ,6  ,5  ,10 ,10 ,6}
//        };

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

int maze[5][5] =  { 
          {13,8,10,2,12},
          {9,5,12,1,7},
          {1,2,2,3,9},
          {9,5,6,5,3},
          {11,14,10,10,6},
        };

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
