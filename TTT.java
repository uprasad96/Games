
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class TTT extends JFrame implements ActionListener {

	public static final int BOARD_SIZE = 3;

	private static enum GameStatus {
		Tie, Xwins, Owins, Incomplete
	};

	JButton[][] buttons = new JButton[BOARD_SIZE][BOARD_SIZE];
	boolean crossturn = true;

	public TTT() {

		super.setTitle("TicTacToe");
		super.setSize(800, 800);

		GridLayout grid = new GridLayout(BOARD_SIZE, BOARD_SIZE);

		super.setLayout(grid);

		Font font = new Font("Comic Sans", 1, 150);
		for (int row = 0; row < BOARD_SIZE; row++) {
			for (int col = 0; col < BOARD_SIZE; col++) {
				JButton obj = new JButton("");
				buttons[row][col] = obj;
				obj.setFont(font);
				obj.addActionListener(this);
				super.add(obj);

			}

		}
		super.setResizable(false);
		super.setVisible(true);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		JButton obj = (JButton) e.getSource();
		makeMove(obj);

		GameStatus stat = this.getGameStatus();

		if (stat != GameStatus.Incomplete) {
			declareWinner(stat);
			int choice = JOptionPane.showConfirmDialog(this, "Play again?");

			if (choice == JOptionPane.YES_OPTION) {
				for (int row = 0; row < BOARD_SIZE; row++) {
					for (int col = 0; col < BOARD_SIZE; col++) {
						buttons[row][col].setText("");
					}
				}
				crossturn = true;
			} else
				super.dispose();
		}

	}

	private void makeMove(JButton clickedButton) {
		String text = clickedButton.getText();
		if (text.length() > 0) {
			JOptionPane.showMessageDialog(this, "Invald Move");
			return;
		}
		if (crossturn) {
			clickedButton.setText("X");
			crossturn = !crossturn;
		} else {
			clickedButton.setText("O");
			crossturn = !crossturn;
		}
	}

	private GameStatus getGameStatus() {

		int row;
		int col;
		// test in rows
		String text1 = "";
		String text2 = "";
		row = 0;
		while (row < BOARD_SIZE) {
			col = 0;
			while (col < BOARD_SIZE - 1) {
				text1 = buttons[row][col].getText();
				text2 = buttons[row][col + 1].getText();

				if (!text1.equals(text2) || text1.length() == 0) {
					break;
				}
				col++;
			}
			if (col == BOARD_SIZE - 1) {
				if (text1.equals("X"))
					return GameStatus.Xwins;
				else
					return GameStatus.Owins;
			}
			row++;
		}

		// test in col

		text1 = "";
		text2 = "";
		col = 0;
		while (col < BOARD_SIZE) {
			row = 0;
			while (row < BOARD_SIZE - 1) {
				text1 = buttons[row][col].getText();
				text2 = buttons[row + 1][col].getText();

				if (!text1.equals(text2) || text1.length() == 0) {
					break;
				}
				row++;
			}

			if (row == BOARD_SIZE - 1) {
				if (text1.equals("X"))
					return GameStatus.Xwins;
				else
					return GameStatus.Owins;
			}

			col++;
		}

		// test in diag1

		text1 = "";
		text2 = "";
		row = 0;
		col=0;
		while (row < BOARD_SIZE - 1) {
			
			text1 = buttons[row][col].getText();
			text2 = buttons[row + 1][col + 1].getText();

			if (!text1.equals(text2) || text1.length() == 0) {
				break;
			}
			row++;
			col++;
			if (row == BOARD_SIZE - 1) {
				if (text1.equals("X"))
					return GameStatus.Xwins;
				else
					return GameStatus.Owins;
			}
		}

		// test in diag2
		text1 = "";
		text2 = "";
		row = 0;
		col=BOARD_SIZE - 1;
		while (row < BOARD_SIZE - 1) {
			
			text1 = buttons[row][col].getText();
			text2 = buttons[row + 1][col - 1].getText();

			if (!text1.equals(text2) || text1.length() == 0) {
				break;
			}
			row++;
			col--;
			if (row == BOARD_SIZE - 1) {
				if (text1.equals("X"))
					return GameStatus.Xwins;
				else
					return GameStatus.Owins;
			}
		}
		String text = "";
		for (int r = 0; r < BOARD_SIZE; r++) {
			for (int c = 0; c < BOARD_SIZE; c++) {
				text = buttons[r][c].getText();
				if (text.length() == 0)
					return GameStatus.Incomplete;
			}
		}
		return GameStatus.Tie;
	}

	private void declareWinner(GameStatus gs) {
		if (gs == GameStatus.Xwins)
			JOptionPane.showMessageDialog(this, "X Wins");
		else if (gs == GameStatus.Owins)
			JOptionPane.showMessageDialog(this, "O Wins");
		else if (gs == GameStatus.Tie)
			JOptionPane.showMessageDialog(this, "Tie");
	}
}
