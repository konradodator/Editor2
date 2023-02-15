#include <GL/glut.h>
#include <vector>
#include <iostream>

// Struktur zur Speicherung von Quadratinformationen
struct Square {
    int id;
    float x;
    float y;
    float size;
};

// Vektor, um Quadratinformationen zu speichern
std::vector<Square> squares;

// Hilfsfunktion zum Finden eines Quadrats anhand seiner ID
Square* findSquare(int id) {
    for (auto& square : squares) {
        if (square.id == id) {
            return &square;
        }
    }
    return nullptr;
}

// Mausereignis-Callback-Funktion
void mouse(int button, int state, int x, int y) {
    // Wenn die linke Maustaste gedrückt wurde, Quadrat auswählen und Position aktualisieren
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Umrechnung der Fensterkoordinaten in OpenGL-Koordinaten (-1 bis 1)
        float xPos = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float yPos = (float)y / glutGet(GLUT_WINDOW_HEIGHT) * -2 + 1;
    

        // Quadrat auswählen, das am nächsten zur Mausposition ist
        int closestId = -1;
        float closestDist = 99999.0f;
        for (auto& square : squares) {
            float dist = std::sqrt(std::pow(square.x - xPos, 2) + std::pow(square.y - yPos, 2));
            if (dist < closestDist) {
                closestId = square.id;
                closestDist = dist;
            }
        }


        // Position des ausgewählten Quadrats aktualisieren
        if (closestId != -1) {
            Square* square = findSquare(closestId);
            if (square) {
                square->x = xPos;
                square->y = yPos;

                // Neuzeichnen des Fensters
                glutPostRedisplay();
            }
        }
    }
}

// Zeichenfunktion
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Alle Quadrate zeichnen
    for (auto& square : squares) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(square.x - square.size, square.y + square.size);
        glVertex2f(square.x + square.size, square.y + square.size);
        glVertex2f(square.x + square.size, square.y - square.size);
        glVertex2f(square.x - square.size, square.y - square.size);
        glEnd();

       
        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square.x - square.size/3, square.y - square.size);
        glVertex2f(square.x - square.size / 3, square.y + square.size);
        glVertex2f(square.x + square.size / 3, square.y - square.size);
        glVertex2f(square.x + square.size / 3, square.y + square.size);
        glEnd();


    }

    glutSwapBuffers();
}

// Funktion zum Hinzufügen eines neuen Quadrats
void addSquare(float x, float y, float size) {
    int id = squares.empty() ? 1 : squares.back().id + 1;
    squares.push_back({ id, x, y, size });
}

// Funktion zum Entfernen eines Quadrats anhand seiner ID
void removeSquare(int id) {
    squares.erase(std::remove_if(squares.begin(), squares.end(), [&](Square& square) {
        return square.id == id;
        }), squares.end());
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') {
        addSquare(-0.5f, 0.5f, 0.15f);
    }
    else if (key == 'r' && !squares.empty()) {
        removeSquare(squares.back().id);
    }
    glutPostRedisplay();
}

// Hauptfunktion
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Verschieben Sie Quadrate mit der Maus");

    // Mausereignis-Callback registrieren
    glutMouseFunc(mouse);

    // Erzeugen von drei Quadraten mit verschiedenen Positionen
    squares.push_back({ 1, -0.5f, 0.5f, 0.15f });
    squares.push_back({ 2, -0.1f, 0.5f, 0.15f });
    squares.push_back({ 3,  0.3f, 0.5f, 0.15f });

    glutKeyboardFunc([](unsigned char key, int x, int y) {
        if (key == 'a') {
            addSquare(-0.5f, 0.5f, 0.15f);
            glutPostRedisplay();
        }
        else if (key == 'r') {
            removeSquare(squares.back().id);
            glutPostRedisplay();
        }
        });





    // Zeichenfunktion als Callback registrieren
    glutDisplayFunc(draw);

    // OpenGL-Initialisierung
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Haupt-Loop starten
    glutMainLoop();

    return 0;
}
