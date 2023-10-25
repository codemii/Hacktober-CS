package GUIapps.java;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.BorderFactory;
import javax.swing.border.Border;

public class calculator implements ActionListener {
    JFrame f;
    JLabel title;
    JTextField tf;
    JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, sum, sub, multi, divi, per, clr, equal, deci, del;
    static double a = 0, b = 0, result = 0;
    static int operator = 0;

    calculator() {
        f = new JFrame("Calculator Application");
        title = new JLabel("Calculator By Vikash");
        tf = new JTextField("");
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        b0 = new JButton("0");
        sum = new JButton("+");
        sub = new JButton("-");
        multi = new JButton("*");
        divi = new JButton("/");
        per = new JButton("%");
        clr = new JButton("AC");
        equal = new JButton("=");
        deci = new JButton(".");
        del = new JButton("Del");
        title.setBounds(70, 20, 300, 40);
        title.setFont(new Font("Times New Roman", Font.BOLD, 30));
        title.setForeground(Color.BLUE);
        tf.setBounds(50, 100, 300, 50);
        tf.setFont(new Font("Arial", Font.BOLD, 20));
        tf.setHorizontalAlignment(JTextField.RIGHT);
        Border border = BorderFactory.createLineBorder(Color.RED, 5);
        tf.setBorder(border);
        b7.setBounds(50, 160, 60, 30);
        b8.setBounds(130, 160, 60, 30);
        b9.setBounds(210, 160, 60, 30);
        divi.setBounds(290, 160, 60, 30);
        b4.setBounds(50, 210, 60, 30);
        b5.setBounds(130, 210, 60, 30);
        b6.setBounds(210, 210, 60, 30);
        multi.setBounds(290, 210, 60, 30);
        b1.setBounds(50, 260, 60, 30);
        b2.setBounds(130, 260, 60, 30);
        b3.setBounds(210, 260, 60, 30);
        sub.setBounds(290, 260, 60, 30);
        b0.setBounds(50, 310, 60, 30);
        deci.setBounds(130, 310, 60, 30);
        sum.setBounds(210, 310, 60, 30);
        clr.setBounds(290, 310, 60, 30);
        per.setBounds(50, 360, 60, 30);
        del.setBounds(130, 360, 60, 30);
        equal.setBounds(210, 360, 140, 30);
        f.add(title);
        f.add(tf);
        f.add(b1);
        f.add(b2);
        f.add(b3);
        f.add(b4);
        f.add(b5);
        f.add(b6);
        f.add(b7);
        f.add(b8);
        f.add(b9);
        f.add(b0);
        f.add(sum);
        f.add(sub);
        f.add(multi);
        f.add(divi);
        f.add(per);
        f.add(clr);
        f.add(equal);
        f.add(deci);
        f.add(del);
        f.setSize(430, 450);
        f.setLayout(null);
        f.setVisible(true);
        f.setResizable(false);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        b0.addActionListener(this);
        sum.addActionListener(this);
        sub.addActionListener(this);
        multi.addActionListener(this);
        divi.addActionListener(this);
        per.addActionListener(this);
        clr.addActionListener(this);
        equal.addActionListener(this);
        deci.addActionListener(this);
        del.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b1) {
            tf.setText(tf.getText().concat("1"));
        }
        if (e.getSource() == b2) {
            tf.setText(tf.getText().concat("2"));
        }
        if (e.getSource() == b3) {
            tf.setText(tf.getText().concat("3"));
        }
        if (e.getSource() == b4) {
            tf.setText(tf.getText().concat("4"));
        }
        if (e.getSource() == b5) {
            tf.setText(tf.getText().concat("5"));
        }
        if (e.getSource() == b6) {
            tf.setText(tf.getText().concat("6"));
        }
        if (e.getSource() == b7) {
            tf.setText(tf.getText().concat("7"));
        }
        if (e.getSource() == b8) {
            tf.setText(tf.getText().concat("8"));
        }
        if (e.getSource() == b9) {
            tf.setText(tf.getText().concat("9"));
        }
        if (e.getSource() == b0) {
            tf.setText(tf.getText().concat("0"));
        }
        if (e.getSource() == deci) {
            tf.setText(tf.getText().concat("."));
        }
        if (e.getSource() == sum) {
            a = Double.parseDouble(tf.getText());
            operator = 1;
            tf.setText(null);
        }
        if (e.getSource() == sub) {
            a = Double.parseDouble(tf.getText());
            operator = 2;
            tf.setText(null);
        }
        if (e.getSource() == multi) {
            a = Double.parseDouble(tf.getText());
            operator = 3;
            tf.setText(null);
        }
        if (e.getSource() == divi) {
            a = Double.parseDouble(tf.getText());
            operator = 4;
            tf.setText(null);
        }
        if (e.getSource() == per) {
            b = Double.parseDouble(tf.getText());
            operator = 5;
            switch (operator) {
                case 5:
                    result = a * b / 100;
                    break;
            }

            tf.setText("" + result);
        }
        if (e.getSource() == equal) {
            b = Double.parseDouble(tf.getText());
            switch (operator) {
                case 1:
                    result = a + b;
                    break;
                case 2:
                    result = a - b;
                    break;
                case 3:
                    result = a * b;
                    break;
                case 4:
                    result = a / b;
                    break;
            }

            tf.setText("" + result);
        }
        if (e.getSource() == clr) {
            tf.setText(null);
        }
        if (e.getSource() == del) {
            String s = tf.getText();
            tf.setText("");
            for (int i = 0; i < s.length() - 1; i++)
                tf.setText(tf.getText() + s.charAt(i));
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new calculator();
            }
        });
    }
}