// X,Y,x,y start with 0

//   _ _ _ _ _
//  |0|  _   _|
//  | |_ _|   |
//  |       | |
//  | |_ _|_  |
//  |_|_ _ _ _| 

// ---> F_X
// <--- B_X
// ^ B_Y
// v F_Y


//int x = 200;
//int y = 200;


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
