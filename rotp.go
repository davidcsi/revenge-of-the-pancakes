package main
import (
    "fmt"
	"strconv"
	"bufio"
	"os"
)

func check(e error) {
    if e != nil {
        panic(e)
    }
}

func flipStack(stack string) (int) {
	flips := 0

	// Loop through the stack, if the currect position is different from the last, flip it.
	for pos, char := range stack {
		if pos > 0 {
			if char != int32(stack[pos-1]) {
				flips += 1
			}
		}
	}

	// If the last pancake is not OK, flip it!
	if stack[ len(stack)-1 ] == '+' {
		return flips;
	} else {
		return flips + 1;
	}
}

func main() {
	file, err := os.Open("sample.in") 
    check(err)
	snl := bufio.NewScanner(file)

	// Read first line to get sample count
	snl.Scan()
	lines, err := strconv.Atoi( snl.Text() )
	fmt.Printf("Samples: %v\n", lines)
	check(err)

	// Get the count of samples, on per line and do the flipping
    for i:=1; i<=lines; i++ {
		snl.Scan()
		flips := flipStack( snl.Text() )
		fmt.Printf( "Case [%s] #%v: %v\n", snl.Text(), i, flips )
    }

	err = snl.Err()

}
