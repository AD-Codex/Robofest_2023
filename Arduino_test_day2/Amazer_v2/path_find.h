


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
