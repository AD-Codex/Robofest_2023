
// ---> F_X
// <--- B_X
// ^ B_Y
// v F_Y


//int x = 200;
//int y = 200;

// mouse direction
//    8
//  4 5 6
//    2



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
      mouse_move_state_int = 8;
    } 
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X_= X_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
      mouse_move_state_int = 6;
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X_= X_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
      mouse_move_state_int = 4;
    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
      strcpy( state, "B_Y");
      mouse_move_state_int = 2;
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");   
    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101) {
        strcpy( state, "B_Y");
        mouse_move_state_int = 2;
        Path_find_1 = 0;
        Serial.println("F_Y change move fn to move_back fn\n");
    }
    else {
        Serial.println("11111111111111111\n");
        mouse_move_state_int = 0;
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
      mouse_move_state_int = 8;
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X_= X_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
      mouse_move_state_int = 6;
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X_= X_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
      mouse_move_state_int = 4;
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 ) {
      strcpy( state, "F_Y");
      mouse_move_state_int = 2;
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101) {
      strcpy( state, "F_Y");
      mouse_move_state_int = 2;
      Path_find_1 = 0;
      Serial.println("B_Y change move fn to move_back fn\n");
    }
    else {
      Serial.println("2222222222222222222\n"); 
      mouse_move_state_int = 0;     
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
      mouse_move_state_int = 8;
    } 
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y_= Y_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
      mouse_move_state_int = 6;
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y_= Y_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
      mouse_move_state_int = 4;
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
      strcpy( state, "B_X");
      mouse_move_state_int = 2;
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101) {
      strcpy( state, "B_X");
      mouse_move_state_int = 2;
      Path_find_1 = 0;
      Serial.println("F_X change move fn to move_back fn\n");
    }
    else {
      Serial.println("33333333333333333333333\n");
      mouse_move_state_int = 0;   
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
      mouse_move_state_int = 8;
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y_= Y_-1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
      mouse_move_state_int = 6;
    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y_= Y_+1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
      mouse_move_state_int = 4;
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
      strcpy( state, "F_X");
      mouse_move_state_int = 2;
      Path_find_1 = 0;
      Serial.println("change move fn to move_back fn\n");     
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101) {
      strcpy( state, "F_X");
      mouse_move_state_int = 2;
      Path_find_1 = 0;
      Serial.println("B_X change move fn to move_back fn\n");
    }
    else {
      Serial.println("444444444444444444444\n"); 
      mouse_move_state_int = 0;     
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
        mouse_move_state_int = 8;
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
        mouse_move_state_int = 6;
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
        mouse_move_state_int = 4; 
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
        mouse_move_state_int = 8; 
        Y_= Y_+1;
        movement_count = movement_count +1;
        Serial.println("F_Y to F_Y moving back\n");
      }
      else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
        count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
        strcpy( state, "B_X");
        mouse_move_state_int = 6; 
        X_= X_-1;
        movement_count = movement_count +1;
        Serial.println("F_Y to B_X moving back\n");
      }
      else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
        count = terminal_maze[ terminalY_coord][ terminalX_coord +2] ;
        strcpy( state, "F_X");
        mouse_move_state_int = 4; 
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
        mouse_move_state_int = 8;
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
        mouse_move_state_int = 6;
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
        mouse_move_state_int = 4;
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
        mouse_move_state_int = 8;
        Y_= Y_-1;
        movement_count = movement_count +1;
        Serial.println("B_Y to B_Y moving back\n");
      }
      else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
        count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
        strcpy( state, "F_X");
        mouse_move_state_int = 6;
        X_= X_+1;
        movement_count = movement_count +1;
        Serial.println("B_Y to F_X moving back\n");
      }
      else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
        count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
        strcpy( state, "B_X");
        mouse_move_state_int = 4;
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
        mouse_move_state_int = 8;
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
        mouse_move_state_int = 6;
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
        mouse_move_state_int = 4;
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
        mouse_move_state_int = 8;
        X_= X_+1;
        movement_count = movement_count +1;
        Serial.println("F_X to F_X moving back\n");
      } 
      else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
        count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
        strcpy( state, "F_Y");
        mouse_move_state_int = 6;
        Y_= Y_+1;
        movement_count = movement_count +1;
        Serial.println("F_X to F_Y moving back\n");
      }
      else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
        count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
        strcpy( state, "B_Y");
        mouse_move_state_int = 4;
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
        mouse_move_state_int = 8;
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
        mouse_move_state_int = 6;
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
        mouse_move_state_int = 4;
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
        mouse_move_state_int = 8;
        X_= X_-1;
        movement_count = movement_count +1;
        Serial.println("B_X to B_X moving back\n");
      } 
      else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
        count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
        strcpy( state, "B_Y");
        mouse_move_state_int = 6;
        Y_= Y_-1;
        movement_count = movement_count +1;
        Serial.println("B_X to B_Y moving back\n");
      }
      else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
        count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
        strcpy( state, "F_Y");
        mouse_move_state_int = 4;
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
