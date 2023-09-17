fun get() = readln().toInt()

fun MergeSort(arr: IntArray, l: Int, r: Int) {
    val m = (l + r) / 2
    if (l < r) {
        MergeSort(arr, l, m)
        MergeSort(arr, m+1, r)
        Merge(arr, l, m, r)
    }
}

fun Merge(arr: IntArray, l: Int, m: Int, r: Int) {
    val size = r - l + 1
    var a = l
    var b = m+1
    var i = 0
    val tmp = IntArray(size)
    while (a <= m && b <= r) {
        if (arr[a] <= arr[b]) tmp[i] = arr[a++]
        else tmp[i] = arr[b++]
        i++
    }
    while (a <= m) {
        tmp[i] = arr[a++]
        i++
    }
    while (b <= r) {
        tmp[i] = arr[b++]
        i++
    }
    (l..r).forEach { idx ->
        arr[idx] = tmp[idx - l]
    }
}

fun main() {
    val n = get()
    val arr = IntArray(n) { get() }
    MergeSort(arr, 0, n-1)
    arr.joinToString("\n").also(::print)
}