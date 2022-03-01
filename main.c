#include "c_vector_ci/las.h"
#include "c_vector_ci/point.h"
#include "c_vector_ci/vector_point_3d.h"
#include "stl/stl.h"
#include "triangle/triangulation.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    char *nom_du_fichier = argv[1];

    double epsilon = atof(argv[2]);

    char *outputname = argv[3];

    int num_de_points = 0;

    vec_point_2d points_2d;
    vec_point_3d points_3d;
    vec_i_triangle triangles;
    vec_point_2d_init(&points_2d);
    vec_point_3d_init(&points_3d);
    vec_i_triangle_init(&triangles);

    header head = header_from_file(nom_du_fichier);

    point_3d *data = points_from_file(nom_du_fichier, head, &num_de_points);

    for (int i = 0; i < num_de_points; i++)
    {
        double random = (double)((double)rand() / (double)RAND_MAX);
        if (random < epsilon)
        {
            point_2d pt = point_2d_create(data[i].x, data[i].y);

            vec_point_3d_push(&points_3d, data[i]);
            vec_point_2d_push(&points_2d, pt);
        }
    }
    printf("\nRunning with %d points\n", points_2d.length);

    bowyer_watson(&points_2d, &triangles);



    triangle table_triangles[triangles.length];

    for (int i = 0; i < triangles.length; i++)
    {
        point_3d sommets[3];
        i_triangle tmp;
        error_message_displayer(vec_i_triangle_get(&triangles, i, &tmp),
                                "Getting tmp_triangle from triangles in main");
        error_message_displayer(vec_point_3d_get(&points_3d, tmp.p1, &sommets[0]),
                                "Getting sommet[0] from points_3d in main");
        error_message_displayer(vec_point_3d_get(&points_3d, tmp.p2, &sommets[1]),
                                "Getting sommet[1] from points_3d in main");
        error_message_displayer(vec_point_3d_get(&points_3d, tmp.p3, &sommets[2]),
                                "Getting sommet[2] from points_3d in main");

        table_triangles[i] = triangle_create(sommets[0], sommets[1], sommets[2]);
    }


    stl_file_create_and_write(outputname, "triangle", table_triangles, triangles.length);

    //Free
    free(data);
    vec_point_2d_free(&points_2d);
    vec_point_3d_free(&points_3d);
    vec_i_triangle_free(&triangles);
}
