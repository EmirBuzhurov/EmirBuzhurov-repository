int* new_array(int len, int value){
    int* array = new int[len];
    for (int i = 0; i < len; i++){
        array[i] = value;
    }
    return array;
}

int set_new_length(int** array, int old_len, int new_len){
    int* new_arr = new int[new_len];
    if (new_len > old_len){
        for (int i = 0; i < new_len; i++){
            if (i < old_len){
                new_arr[i] = (*array)[i];
            }else{
                new_arr[i] = 0;
            }
        }
    }else{
        for (int i = 0; i < new_len; i++){
            new_arr[i] = (*array)[i];
        }
    }
    
    delete [] *array;
    *array = new_arr;
    
    return new_len;
}

int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array){
    int* new_arr = new int[len_dest_array + len_src_array];
    for (int i = 0; i < len_dest_array; i++){
            new_arr[i] = (*dest_array)[i];
        }
    for (int i = 0; i < len_src_array; i++){
            new_arr[len_dest_array+i] = src_array[i];
        }
    delete [] *dest_array;
    *dest_array = new_arr;

    return len_dest_array + len_src_array;
}

int dot(const int* a, const int* b, int len){
    int result = 0;
    if (len != 0){
        for (int i = 0; i < len; i++){
        result += (a[i] * b[i]);
        }
    }
    
    return result;
}

int* find(int* array, int len, int value){
    int index = -1;
    for (int i = 0; i < len; i++){
        if (array[i] == value){
            index = i;
            break;
        }
    }
    if (index == -1){
        return nullptr;
    }else{
        return &array[index];
    }
}

void delete_array(int** array){
    if (*array != nullptr){
        delete [] *array;
    	*array = nullptr;
    }
}
