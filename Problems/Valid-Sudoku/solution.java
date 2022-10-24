class Solution {
    public boolean isValidSudoku(char[][] board) {
        byte[] arr = new byte[10];
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char c = board[row][col];
                if (c == '.') continue;
                if (arr[c - '0'] > 0) {
                    return false;
                } else {
                    arr[c - '0']++;
                }
            }
            clearArray(arr);
        }
        for (int col = 0; col < 9; col++) {
            for (int row = 0; row < 9; row++) {
                char c = board[row][col];
                if (c == '.') continue;
                if (arr[c - '0'] > 0) {
                    return false;
                } else {
                    arr[c - '0']++;
                }
            }
            clearArray(arr);
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        char ch = board[row + r][col + c];
                        if (ch == '.') continue;
                        if (arr[ch - '0'] > 0) {
                            return false;
                        } else {
                            arr[ch - '0']++;
                        }
                    }
                }
                clearArray(arr);
            }
        }
        return true;
    }

    private void clearArray(byte[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = 0;
        }
    }
}
