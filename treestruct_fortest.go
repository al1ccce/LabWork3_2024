package fbt

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type TNode struct {
	Value int
	Left  *TNode
	Right *TNode
}

type FullBinaryTree struct {
	Root  *TNode
	Order string
}

func NewFullBinaryTree() *FullBinaryTree {
	return &FullBinaryTree{Root: nil, Order: ""}
}

func (t *FullBinaryTree) Insert(value int) {
	t.insert(&t.Root, value)
}

func (t *FullBinaryTree) insert(root **TNode, value int) {
	if *root == nil {
		*root = &TNode{Value: value, Left: nil, Right: nil}
		t.Order += strconv.Itoa(value) + " "
		return
	}
	if value <= (*root).Value {
		t.insert(&(*root).Left, value)
	} else {
		t.insert(&(*root).Right, value)
	}
}

func (t *FullBinaryTree) Print(file, namestruct string) error {
	f, err := os.Create(file)
	if err != nil {
		return err
	}
	defer f.Close()

	_, err = f.WriteString(namestruct + "\n")
	if err != nil {
		return err
	}

	_, err = f.WriteString(t.Order)
	if err != nil {
		return err
	}

	return nil
}

func (t *FullBinaryTree) Search(value int) *TNode {
	return t.SearchHelp(t.Root, value)
}

func (t *FullBinaryTree) SearchHelp(node *TNode, value int) *TNode {
	if node == nil || node.Value == value {
		return node
	}

	if value < node.Value {
		return t.SearchHelp(node.Left, value)
	} else {
		return t.SearchHelp(node.Right, value)
	}
}

func (t *FullBinaryTree) IsFull() bool {
	return t.IsFullHelp(t.Root)
}

func (t *FullBinaryTree) IsFullHelp(node *TNode) bool {
	if node == nil {
		return true
	}
	if (node.Left == nil && node.Right != nil) ||
		(node.Left != nil && node.Right == nil) {
		return false
	}
	return t.IsFullHelp(node.Left) && t.IsFullHelp(node.Right)
}

func (t *FullBinaryTree) PrintBash() {
	t.PrintBashHelp(t.Root, 0)
}

func (t *FullBinaryTree) PrintBashHelp(root *TNode, level int) {
	if root != nil {
		t.PrintBashHelp(root.Right, level+1)
		fmt.Printf("%s%d\n", strings.Repeat("   ", level), root.Value)
		t.PrintBashHelp(root.Left, level+1)
	}
}