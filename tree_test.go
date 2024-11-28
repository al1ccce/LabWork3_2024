package fbt

import (
	"testing"
	"os"
)

func TestInsertAndSearch(t *testing.T) {
	tree := NewFullBinaryTree()
	tree.Insert(5)
	tree.Insert(3)
	tree.Insert(7)
	tree.Insert(4);

	node := tree.Search(4)
	if node == nil {
		t.Error("Значение = null вместо 4")
	} else if node.Value != 4 {
		t.Errorf("Значение = %d вместо 4", node.Value)
	}
	node2 := tree.Search(999)
	if node2 != nil {
		t.Errorf("Ожидалось, что значение = null, но найдено значение = %d", node.Value)
	}
}

func TestIsFull(t *testing.T) {
	tree := NewFullBinaryTree()
	tree.Insert(5)
	tree.Insert(3)
	tree.Insert(7)
	tree.Insert(2)
	tree.Insert(4)
	tree.Insert(6)
	tree.Insert(8)

	if !tree.IsFull() {
		t.Error("Ожидалось, что дерево является полным, но оно таковым не является.")
	}
	tree.Insert(12);

	if tree.IsFull() {
		t.Error("Ожидалось, что дерево является неполным, но оно полное.")
	}
}

func TestPrint(t *testing.T) {
	tree := NewFullBinaryTree()
	tree.Insert(5)
	tree.Insert(3)
	tree.Insert(7)
	tree.Insert(4)

	// Запись данных в файл
	err := tree.Print("tree.data", "@tree")
	if err != nil {
		t.Errorf("Ошибка при записи в файл: %v", err)
	}

	// Проверка содержимого файла
	text := "@tree\n5 3 7 4 "
	content, err := os.ReadFile("tree.data")
	if err != nil {
		t.Errorf("Ошибка при чтении файла: %v", err)
	}

	if string(content) != text {
		t.Errorf("Ожидаемое содержимое: %s, полученное содержимое: %s", text, string(content))
	}

	// Удаление тестового файла
	err = os.Remove("tree.data")
	if err != nil {
		t.Errorf("Ошибка при удалении тестового файла: %v", err)
	}
	tree.PrintBash();
}