fun main() {
    val t = readln().toInt()
    buildString {
        for (i in 1..t) {
            appendLine(readln().split(",").map(String::toInt).sum())
        }
    }.also(::print)
}