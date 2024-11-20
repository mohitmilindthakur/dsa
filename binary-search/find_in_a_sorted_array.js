function search(A, B) {
    let low = 0;
    let high = A.length - 1;

    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (A[mid] === B) {
            return mid;
        }

        // if the right array is sorted
        if (A[low] < A[mid]) {
            if (B < A[mid] && B >= A[low]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // left array is sorted
        else {
            if (B <= A[high] && B > A[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        console.log(mid, A[mid], high, low);
    }
    return -1;
}

const ar = [ 101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100 ]
const num = 202

console.log(search(ar, num));