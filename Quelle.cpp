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

struct Square3 {
    int id3;
    float x3;
    float y3;
    float size3;
};

struct Square4 {
    int id4;
    float x4;
    float y4;
    float size4;
};

struct Square5 {
    int id5;
    float x5;
    float y5;
    float size5;
};

struct Square6 {
    int id6;
    float x6;
    float y6;
    float size6;
};

// Vektor, um Quadratinformationen zu speichern
std::vector<Square> squares;
std::vector<Square2> squares2;
std::vector<Square3> squares3;
std::vector<Square4> squares4;
std::vector<Square5> squares5;
std::vector<Square6> squares6;


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


Square3* findSquare3(int id3) {
    for (auto& square3 : squares3) {
        if (square3.id3 == id3) {
            return &square3;
        }
    }
    return nullptr;
}

Square4* findSquare4(int id4) {
    for (auto& square4 : squares4) {
        if (square4.id4 == id4) {
            return &square4;
        }
    }
    return nullptr;
}

Square5* findSquare5(int id5) {
    for (auto& square5 : squares5) {
        if (square5.id5 == id5) {
            return &square5;
        }
    }
    return nullptr;
}

Square6* findSquare6(int id6) {
    for (auto& square6 : squares6) {
        if (square6.id6 == id6) {
            return &square6;
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
        float xPos3 = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float yPos3 = (float)y / glutGet(GLUT_WINDOW_HEIGHT) * -2 + 1;
        float xPos4 = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float yPos4 = (float)y / glutGet(GLUT_WINDOW_HEIGHT) * -2 + 1;
        float xPos5 = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float yPos5 = (float)y / glutGet(GLUT_WINDOW_HEIGHT) * -2 + 1;
        float xPos6 = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float yPos6 = (float)y / glutGet(GLUT_WINDOW_HEIGHT) * -2 + 1;
    

        // Quadrat auswählen, das am nächsten zur Mausposition ist
        int closestId = -1;
        float closestDist = 0.2f;
        for (auto& square : squares) {
            float dist = std::sqrt(std::pow(square.x - xPos, 2) + std::pow(square.y - yPos, 2));
            if (dist < closestDist) {
                closestId = square.id;
                closestDist = dist;
            }
        }

        int closestId2 = -1;
        float closestDist2 = 0.5f;
        for (auto& square2 : squares2) {
            float dist2 = std::sqrt(std::pow(square2.x2 - xPos2, 2) + std::pow(square2.y2 - yPos2, 2));
            if (dist2 < closestDist) {
                closestId2 = square2.id2;
                closestDist2 = dist2;
            }
        }

        int closestId3 = -1;
        float closestDist3 = 0.5f;
        for (auto& square3 : squares3) {
            float dist3 = std::sqrt(std::pow(square3.x3 - xPos3, 2) + std::pow(square3.y3 - yPos3, 2));
            if (dist3 < closestDist) {
                closestId3 = square3.id3;
                closestDist3 = dist3;
            }
        }

        int closestId4 = -1;
        float closestDist4 = 0.5f;
        for (auto& square4 : squares4) {
            float dist4 = std::sqrt(std::pow(square4.x4 - xPos4, 2) + std::pow(square4.y4 - yPos4, 2));
            if (dist4 < closestDist) {
                closestId4 = square4.id4;
                closestDist4 = dist4;
            }
        }

        int closestId5 = -1;
        float closestDist5 = 0.5f;
        for (auto& square5 : squares5) {
            float dist5 = std::sqrt(std::pow(square5.x5 - xPos5, 2) + std::pow(square5.y5 - yPos5, 2));
            if (dist5 < closestDist) {
                closestId5 = square5.id5;
                closestDist5 = dist5;
            }
        }

        int closestId6 = -1;
        float closestDist6 = 0.5f;
        for (auto& square6 : squares6) {
            float dist6 = std::sqrt(std::pow(square6.x6 - xPos6, 2) + std::pow(square6.y6 - yPos6, 2));
            if (dist6 < closestDist) {
                closestId6 = square6.id6;
                closestDist6 = dist6;
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

        // Position des ausgewählten Quadrats aktualisieren
        if (closestId3 != -1) {
            Square3* square3 = findSquare3(closestId3);
            if (square3) {
                square3->x3 = xPos3;
                square3->y3 = yPos3;

                // Neuzeichnen des Fensters
                glutPostRedisplay();
            }
        }

        // Position des ausgewählten Quadrats aktualisieren
        if (closestId4 != -1) {
            Square4* square4 = findSquare4(closestId4);
            if (square4) {
                square4->x4 = xPos4;
                square4->y4 = yPos4;

                // Neuzeichnen des Fensters
                glutPostRedisplay();
            }
        }

        // Position des ausgewählten Quadrats aktualisieren
        if (closestId5 != -1) {
            Square5* square5 = findSquare5(closestId5);
            if (square5) {
                square5->x5 = xPos5;
                square5->y5 = yPos5;

                // Neuzeichnen des Fensters
                glutPostRedisplay();
            }
        }

        // Position des ausgewählten Quadrats aktualisieren
        if (closestId6 != -1) {
            Square6* square6 = findSquare6(closestId6);
            if (square6) {
                square6->x6 = xPos6;
                square6->y6 = yPos6;

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
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(square.x - square.size / 3, square.y - square.size);
        glVertex2f(square.x + square.size / 3, square.y - square.size);
        glVertex2f(square.x + square.size / 3, square.y + square.size);
        glVertex2f(square.x - square.size / 3, square.y + square.size);
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

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(square2.x2 - square2.size2 / 150, square2.y2 + square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2, square2.y2 + square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2, square2.y2 - square2.size2 / 3);
        glVertex2f(square2.x2 - square2.size2 / 150, square2.y2 - square2.size2 / 3);
        glEnd();

        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square2.x2 - square2.size2 + square2.size2 + square2.size2 / 3, square2.y2 + square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2, square2.y2 + square2.size2 / 3);
        glVertex2f(square2.x2 - square2.size2 / 3, square2.y2 - square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2, square2.y2 - square2.size2 / 3);
        glEnd();

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(square2.x2 - square2.size2 / 3, square2.y2 - square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2 / 3, square2.y2 - square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2 / 3, square2.y2 + square2.size2);
        glVertex2f(square2.x2 - square2.size2 / 3, square2.y2 + square2.size2);
        glEnd();

        // Zeichne Linien
        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square2.x2 - square2.size2 / 3, square2.y2 - square2.size2 / 3);
        glVertex2f(square2.x2 - square2.size2 / 3, square2.y2 + square2.size2);
        glVertex2f(square2.x2 + square2.size2 / 3, square2.y2 - square2.size2 + square2.size2 + square2.size2 / 3);
        glVertex2f(square2.x2 + square2.size2 / 3, square2.y2 + square2.size2);
        glEnd();
    }

    for (auto& square3 : squares3) {
        // Zeichne Quadrate
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(square3.x3 - square3.size3, square3.y3 + square3.size3);
        glVertex2f(square3.x3 + square3.size3, square3.y3 + square3.size3);
        glVertex2f(square3.x3 + square3.size3, square3.y3 - square3.size3);
        glVertex2f(square3.x3 - square3.size3, square3.y3 - square3.size3);
        glEnd();

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(square3.x3 - square3.size3, square3.y3 + square3.size3 / 3);
        glVertex2f(square3.x3 + square3.size3, square3.y3 + square3.size3 / 3);
        glVertex2f(square3.x3 + square3.size3, square3.y3 - square3.size3 / 3);
        glVertex2f(square3.x3 - square3.size3, square3.y3 - square3.size3 / 3);
        glEnd();

        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square3.x3 - square3.size3, square3.y3 + square3.size3 / 3);
        glVertex2f(square3.x3 + square3.size3, square3.y3 + square3.size3 / 3);
        glVertex2f(square3.x3 - square3.size3, square3.y3 - square3.size3 / 3);
        glVertex2f(square3.x3 + square3.size3, square3.y3 - square3.size3 / 3);
        glEnd();
    }

    for (auto& square4 : squares4) {
        // Zeichne Quadrate
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(square4.x4 - square4.size4, square4.y4 + square4.size4);
        glVertex2f(square4.x4 + square4.size4, square4.y4 + square4.size4);
        glVertex2f(square4.x4 + square4.size4, square4.y4 - square4.size4);
        glVertex2f(square4.x4 - square4.size4, square4.y4 - square4.size4);
        glEnd();

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(square4.x4 - square4.size4, square4.y4 + square4.size4 / 3);
        glVertex2f(square4.x4 + square4.size4 / 150, square4.y4 + square4.size4 / 3);
        glVertex2f(square4.x4 + square4.size4 / 150, square4.y4 - square4.size4 / 3);
        glVertex2f(square4.x4 - square4.size4, square4.y4 - square4.size4 / 3);
        glEnd();

        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square4.x4 - square4.size4, square4.y4 + square4.size4 / 3);
        glVertex2f(square4.x4 + square4.size4 - square4.size4 - square4.size4 / 3, square4.y4 + square4.size4 / 3);
        glVertex2f(square4.x4 - square4.size4, square4.y4 - square4.size4 / 3);
        glVertex2f(square4.x4 + square4.size4 / 3, square4.y4 - square4.size4 / 3);
        glEnd();

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(square4.x4 - square4.size4 / 3, square4.y4 - square4.size4 / 3);
        glVertex2f(square4.x4 + square4.size4 / 3, square4.y4 - square4.size4 / 3);
        glVertex2f(square4.x4 + square4.size4 / 3, square4.y4 + square4.size4);
        glVertex2f(square4.x4 - square4.size4 / 3, square4.y4 + square4.size4);
        glEnd();

        // Zeichne Linien
        glLineWidth(2.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(square4.x4 - square4.size4 / 3, square4.y4 - square4.size4 + square4.size4 + square4.size4 / 3);
        glVertex2f(square4.x4 - square4.size4 / 3, square4.y4 + square4.size4);
        glVertex2f(square4.x4 + square4.size4 / 3, square4.y4 - square4.size4 / 3);
        glVertex2f(square4.x4 + square4.size4 / 3, square4.y4 + square4.size4);
        glEnd();
    }

        for (auto& square5 : squares5) {
            // Zeichne Quadrate
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_QUADS);
            glVertex2f(square5.x5 - square5.size5, square5.y5 + square5.size5);
            glVertex2f(square5.x5 + square5.size5, square5.y5 + square5.size5);
            glVertex2f(square5.x5 + square5.size5, square5.y5 - square5.size5);
            glVertex2f(square5.x5 - square5.size5, square5.y5 - square5.size5);
            glEnd();

            glColor3f(0.5f, 0.5f, 0.5f);
            glBegin(GL_QUADS);
            glVertex2f(square5.x5 - square5.size5, square5.y5 + square5.size5 / 3);
            glVertex2f(square5.x5 + square5.size5 / 150, square5.y5 + square5.size5 / 3);
            glVertex2f(square5.x5 + square5.size5 /150, square5.y5 - square5.size5 / 3);
            glVertex2f(square5.x5 - square5.size5, square5.y5 - square5.size5 / 3);
            glEnd();

            glLineWidth(2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINES);
            glVertex2f(square5.x5 - square5.size5, square5.y5 + square5.size5 / 3);
            glVertex2f(square5.x5 + square5.size5 - square5.size5 + square5.size5 /3 , square5.y5 + square5.size5 / 3);
            glVertex2f(square5.x5 - square5.size5, square5.y5 - square5.size5 / 3);
            glVertex2f(square5.x5 + square5.size5 /3, square5.y5 - square5.size5 / 3);
            glEnd();

            glColor3f(0.5f, 0.5f, 0.5f);
            glBegin(GL_QUADS);
            glVertex2f(square5.x5 - square5.size5  / 3, square5.y5 - square5.size5 );
            glVertex2f(square5.x5 + square5.size5 / 3, square5.y5 - square5.size5 );
            glVertex2f(square5.x5 + square5.size5 / 3, square5.y5 + square5.size5 - square5.size5 + square5.size5 /3);
            glVertex2f(square5.x5 - square5.size5 / 3, square5.y5 + square5.size5 - square5.size5 + square5.size5 /3);
            glEnd();

            // Zeichne Linien
            glLineWidth(2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINES);
            glVertex2f(square5.x5 - square5.size5 / 3, square5.y5 - square5.size5 );
            glVertex2f(square5.x5 - square5.size5 / 3, square5.y5 + square5.size5 - square5.size5 - square5.size5 /3);
            glVertex2f(square5.x5 + square5.size5 / 3, square5.y5 - square5.size5 );
            glVertex2f(square5.x5 + square5.size5 / 3, square5.y5 + square5.size5 /3);
            glEnd();
        }

        for (auto& square6 : squares6) {
            // Zeichne Quadrate
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_QUADS);
            glVertex2f(square6.x6 - square6.size6, square6.y6 + square6.size6);
            glVertex2f(square6.x6 + square6.size6, square6.y6 + square6.size6);
            glVertex2f(square6.x6 + square6.size6, square6.y6 - square6.size6);
            glVertex2f(square6.x6 - square6.size6, square6.y6 - square6.size6);
            glEnd();

            glColor3f(0.5f, 0.5f, 0.5f);
            glBegin(GL_QUADS);
            glVertex2f(square6.x6 - square6.size6 /150, square6.y6 + square6.size6 / 3);
            glVertex2f(square6.x6 + square6.size6 , square6.y6 + square6.size6 / 3);
            glVertex2f(square6.x6 + square6.size6 , square6.y6 - square6.size6 / 3);
            glVertex2f(square6.x6 - square6.size6 /150, square6.y6 - square6.size6 / 3);
            glEnd();

            glLineWidth(2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINES);
            glVertex2f(square6.x6 - square6.size6 /3, square6.y6 + square6.size6 / 3);
            glVertex2f(square6.x6 + square6.size6 , square6.y6 + square6.size6 / 3);
            glVertex2f(square6.x6 - square6.size6 /3, square6.y6 - square6.size6 / 3);
            glVertex2f(square6.x6 + square6.size6 , square6.y6 - square6.size6 / 3);
            glEnd();

            glColor3f(0.5f, 0.5f, 0.5f);
            glBegin(GL_QUADS);
            glVertex2f(square6.x6 - square6.size6 / 3, square6.y6 - square6.size6);
            glVertex2f(square6.x6 + square6.size6 / 3, square6.y6 - square6.size6);
            glVertex2f(square6.x6 + square6.size6 / 3, square6.y6 + square6.size6 - square6.size6 + square6.size6 / 3);
            glVertex2f(square6.x6 - square6.size6 / 3, square6.y6 + square6.size6 - square6.size6 + square6.size6 / 3);
            glEnd();

            // Zeichne Linien
            glLineWidth(2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINES);
            glVertex2f(square6.x6 - square6.size6 / 3, square6.y6 - square6.size6 );
            glVertex2f(square6.x6 - square6.size6 / 3, square6.y6 + square6.size6 / 3);
            glVertex2f(square6.x6 + square6.size6 / 3, square6.y6 - square6.size6 );
            glVertex2f(square6.x6 + square6.size6 / 3, square6.y6 + square6.size6 - square6.size6 - square6.size6 / 3);
            glEnd();
        }


        glutSwapBuffers();
    }

// Funktion zum Hinzufügen eines neuen Quadrats
void addSquare(float x, float y, float size) {
    int id = squares.empty() ? 1 : squares.back().id + 1;
    squares.push_back({ id, x, y, size });
}

void addSquare2(float x2, float y2, float size2) {
    int id2 = squares2.empty() ? 1 : squares2.back().id2 + 1;
    squares2.push_back({ id2, x2, y2, size2 });
}

void addSquare3(float x3, float y3, float size3) {
    int id3 = squares3.empty() ? 1 : squares3.back().id3 + 1;
    squares3.push_back({ id3, x3, y3, size3 });
}

void addSquare4(float x4, float y4, float size4) {
    int id4 = squares4.empty() ? 1 : squares4.back().id4 + 1;
    squares4.push_back({ id4, x4, y4, size4 });
}

void addSquare5(float x5, float y5, float size5) {
    int id5 = squares5.empty() ? 1 : squares5.back().id5 + 1;
    squares5.push_back({ id5, x5, y5, size5 });
}

void addSquare6(float x6, float y6, float size6) {
    int id6 = squares6.empty() ? 1 : squares6.back().id6 + 1;
    squares6.push_back({ id6, x6, y6, size6 });
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

void removeSquare3(int id3) {
    squares3.erase(std::remove_if(squares3.begin(), squares3.end(), [&](Square3& square3) {
        return square3.id3 == id3;
        }), squares3.end());
}

void removeSquare4(int id4) {
    squares4.erase(std::remove_if(squares4.begin(), squares4.end(), [&](Square4& square4) {
        return square4.id4 == id4;
        }), squares4.end());
}

void removeSquare5(int id5) {
    squares5.erase(std::remove_if(squares5.begin(), squares5.end(), [&](Square5& square5) {
        return square5.id5 == id5;
        }), squares5.end());
}

void removeSquare6(int id6) {
    squares6.erase(std::remove_if(squares6.begin(), squares6.end(), [&](Square6& square6) {
        return square6.id6 == id6;
        }), squares6.end());
}



// Hauptfunktion
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Verschieben Sie Quadrate mit der Maus");

    // Mausereignis-Callback registrieren
    glutMouseFunc(mouse);

    // Erzeugen von Quadraten mit verschiedenen Positionen
    squares.push_back({  1, -0.8f, 0.5f, 0.15f });
    squares2.push_back({  2, -0.5f, 0.5f, 0.15f });
    squares3.push_back({  3, -0.2f, 0.5f, 0.15f });
    squares4.push_back({ 4,  0.2f, 0.5f, 0.15f });
    squares5.push_back({ 5,  0.5f, 0.5f, 0.15f });
    squares6.push_back({ 6,  0.8f, 0.5f, 0.15f });

    //Tastenzuweisung 
    glutKeyboardFunc([](unsigned char key, int x, int y) {
        if (key == '1') {
            addSquare(-0.8f, 0.5f, 0.15f);
            glutPostRedisplay();
        }
        else if (key == 'q') {
            removeSquare(squares.back().id);
            glutPostRedisplay();
        }

    if (key == '2') {
        addSquare2(-0.5f, 0.5f, 0.15f);
        glutPostRedisplay();
    }

        else if (key == 'w') {
        removeSquare2(squares2.back().id2);
        glutPostRedisplay();
    }

    if (key == '3') {
        addSquare3(-0.2f, 0.5f, 0.15f);
        glutPostRedisplay();
    }

    else if (key == 'e') {
        removeSquare3(squares3.back().id3);
        glutPostRedisplay();
    }

    if (key == '4') {
        addSquare4(0.2f, 0.5f, 0.15f);
        glutPostRedisplay();
    }

    else if (key == 'r') {
        removeSquare4(squares4.back().id4);
        glutPostRedisplay();
    }

    if (key == '5') {
        addSquare5(0.5f, 0.5f, 0.15f);
        glutPostRedisplay();
    }

    else if (key == 't') {
        removeSquare5(squares5.back().id5);
        glutPostRedisplay();
    }

    if (key == '6') {
        addSquare6(0.8f, 0.5f, 0.15f);
        glutPostRedisplay();
    }

    else if (key == 'z') {
        removeSquare6(squares6.back().id6);
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
