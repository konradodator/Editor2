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

struct Square2 {
    int id2;
    float x2;
    float y2;
    float size2;
};

// Vektor, um Quadratinformationen zu speichern
std::vector<Square> squares;
std::vector<Square2> squares2;


// Hilfsfunktion zum Finden eines Quadrats anhand seiner ID
Square* findSquare(int id) {
    for (auto& square : squares) {
        if (square.id == id) {
            return &square;
        }
    }
    return nullptr;
}

Square2* findSquare2(int id2) {
    for (auto& square2 : squares2) {
        if (square2.id2 == id2) {
            return &square2;
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
        float xPos2 = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float yPos2 = (float)y / glutGet(GLUT_WINDOW_HEIGHT) * -2 + 1;
    

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

        int closestId2 = -1;
        float closestDist2 = 99999.0f;
        for (auto& square2 : squares2) {
            float dist2 = std::sqrt(std::pow(square2.x2 - xPos2, 2) + std::pow(square2.y2 - yPos2, 2));
            if (dist2 < closestDist) {
                closestId2 = square2.id2;
                closestDist2 = dist2;
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
        // Position des ausgewählten Quadrats aktualisieren
        if (closestId2 != -1) {
            Square2* square2 = findSquare2(closestId2);
            if (square2) {
                square2->x2 = xPos2;
                square2->y2 = yPos2;

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
        // Zeichne Quadrate
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(square.x - square.size, square.y + square.size);
        glVertex2f(square.x + square.size, square.y + square.size);
        glVertex2f(square.x + square.size, square.y - square.size);
        glVertex2f(square.x - square.size, square.y - square.size);
        glEnd();


        // Zeichne Linien
        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square.x - square.size / 3, square.y - square.size);
        glVertex2f(square.x - square.size / 3, square.y + square.size);
        glVertex2f(square.x + square.size / 3, square.y - square.size);
        glVertex2f(square.x + square.size / 3, square.y + square.size);
        glEnd();
    }

    for (auto& square2 : squares2) {
        // Zeichne Quadrate
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(square2.x2 - square2.size2, square2.y2 + square2.size2);
        glVertex2f(square2.x2 + square2.size2, square2.y2 + square2.size2);
        glVertex2f(square2.x2 + square2.size2, square2.y2 - square2.size2);
        glVertex2f(square2.x2 - square2.size2, square2.y2 - square2.size2);
        glEnd();

        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square2.x2 - square2.size2, square2.y2 + square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2, square2.y2 + square2.size2 / 3);
        glVertex2f(square2.x2 - square2.size2, square2.y2 - square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2, square2.y2 - square2.size2 / 3);
        glEnd();
    }

    glutSwapBuffers();
}

// Funktion zum Hinzufügen eines neuen Quadrats
void addSquare(float x, float y, float size) {
    int id = squares.empty() ? 1 : squares.back().id + 1;
    squares.push_back({ id, x, y, size });
}

void addSquare2(float x, float y, float size) {
    int id2 = squares2.empty() ? 1 : squares2.back().id2 + 1;
    squares2.push_back({ id2, x, y, size });
}

// Funktion zum Entfernen eines Quadrats anhand seiner ID
void removeSquare(int id) {
    squares.erase(std::remove_if(squares.begin(), squares.end(), [&](Square& square) {
        return square.id == id;
        }), squares.end());
}

void removeSquare2(int id2) {
    squares2.erase(std::remove_if(squares2.begin(), squares2.end(), [&](Square2& square2) {
        return square2.id2 == id2;
        }), squares2.end());
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
    squares2.push_back({ 4,  0.5f, 0.5f, 0.15f });

    glutKeyboardFunc([](unsigned char key, int x, int y) {
        if (key == 'a') {
            addSquare(-0.5f, 0.5f, 0.15f);
            glutPostRedisplay();
        }
    if (key == 'd') {
        addSquare2(-0.5f, 0.5f, 0.15f);
        glutPostRedisplay();
    }
        else if (key == 'r') {
            removeSquare(squares2.back().id2);
            glutPostRedisplay();
        }
        else if (key == 'd') {
        removeSquare2(squares2.back().id2);
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
