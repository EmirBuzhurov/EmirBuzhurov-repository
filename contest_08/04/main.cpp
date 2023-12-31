int** new_matrix(int rows, int cols, int value){
    int** matrix = new int*[rows]{}; 
    for (int cur_row = 0; cur_row < rows; cur_row++){
        matrix[cur_row] = new int[cols];
    }

    for (int cur_row = 0; cur_row < rows; cur_row++){
        for (int cur_col = 0; cur_col < cols; cur_col++){
            matrix[cur_row][cur_col] = value;
        }
    }
    return matrix;
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols){
    int rows_conv = mrows - crows + 1;
    int cols_conv = mcols - ccols + 1;

    int** conv = new int*[rows_conv];
    for (int i = 0; i < rows_conv; ++i) {
        conv[i] = new int[cols_conv]();
    }

    for (int i = 0; i < rows_conv; ++i) {
        for (int j = 0; j < cols_conv; ++j) {
            for (int k = 0; k < crows; ++k) {
                for (int l = 0; l < ccols; ++l) {
                    conv[i][j] += matrix[i + k][j + l] * core[k][l];
                }
            }
        }
    }

    return std::make_tuple(conv, rows_conv, cols_conv);
}


std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols){
    int** result = new int*[arows];
    for (int cur_row = 0; cur_row < arows; cur_row++) {
        result[cur_row] = new int[bcols];
    }

    for (int i = 0; i < arows; ++i) {
        for (int j = 0; j < bcols; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < acols; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return std::make_tuple(result, arows, bcols);
}

std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value){
    int** new_matrix = new int*[rows+1]{};
    for (int cur_row = 0; cur_row < rows+1; cur_row++){
        new_matrix[cur_row] = new int[cols];
    }

    for (int cur_row = 0; cur_row < rows+1; cur_row++){
        for (int cur_col = 0; cur_col < cols; cur_col++){
           if (cur_row < rows){
                new_matrix[cur_row][cur_col] = (*matrix)[cur_row][cur_col];
            }else{
                new_matrix[cur_row][cur_col] = value;
            }
        }
    }


    for (int cur_row = 0; cur_row < rows; cur_row++) {
        delete[] (*matrix)[cur_row];
    }
    delete[] (*matrix);
    *matrix = new_matrix;

    return std::make_tuple(rows+1, cols);
}

std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value){
    int** new_matrix = new int*[rows];
    for (int cur_row = 0; cur_row < rows; cur_row++) {
        new_matrix[cur_row] = new int[cols + 1];
    }
    
    for (int cur_row = 0; cur_row < rows; cur_row++) {
        for (int cur_col = 0; cur_col < cols + 1; cur_col++) {
            if (cur_col < cols) {
                new_matrix[cur_row][cur_col] = (*matrix)[cur_row][cur_col];
            } else {
                new_matrix[cur_row][cur_col] = value;
            }
        }
    }

    for (int cur_row = 0; cur_row < rows; cur_row++) {
        delete[] (*matrix)[cur_row];
    }
    delete[] (*matrix);

    *matrix = new_matrix;

    return std::make_tuple(rows, cols + 1);
}

void delete_matrix(int*** matrix, int rows){
    if (matrix == nullptr || *matrix == nullptr) {
        return;
    }
    
    for (int i = 0; i < rows; ++i) {
        delete[] (*matrix)[i];
    }
   
    delete[] *matrix;
    
    *matrix = nullptr;
}

void print(int** matrix, int rows, int cols){
    for (int cur_row = 0; cur_row < rows; cur_row++){
        for (int cur_col = 0; cur_col < cols; cur_col++){
            std::cout << matrix[cur_row][cur_col] << " ";
        }
        std::cout << "\n";
    }
}
