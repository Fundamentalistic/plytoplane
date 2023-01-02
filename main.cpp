#include <iostream>
#include <set>
#include <map>
#include "PLY.h"

int main(int argc, char * argv[])
{
    const char * ply_file_path = "1cd0.ply";
    printf("PLY READING RESULTS: \n");
    PLY * content = read_ply_file(ply_file_path);
    printf("content_length: %i\n", content->content_length);
    printf("faces_length: %i\n", content->faces_length);

    std::set<int> * nbrs = new std::set<int>[content->content_length];

    printf("nbrs cycle start\n");

    for( int i = 0; i < content->faces_length; i++ ){
        if(content->faces[i]->point_ids.size() < 3){
            continue;
        }

        int p1id = content->faces[i]->point_ids[0];
        int p2id = content->faces[i]->point_ids[1];
        int p3id = content->faces[i]->point_ids[2];

        nbrs[p1id].insert(p2id);
        nbrs[p1id].insert(p3id);

        nbrs[p2id].insert(p1id);
        nbrs[p2id].insert(p3id);

        nbrs[p3id].insert(p2id);
        nbrs[p3id].insert(p1id);
    }

    printf("content->content_length\n");

    std::map<int, int> stat;

    for( int i = 0; i < content->content_length; i++ ){
        if ( nbrs[i].size() > 6 ) {
            printf("TestFailed: neighbours size more than 6 for id %i\n", i);
            printf("Size value: %u\n", nbrs[i].size());
            // exit(1);
            if(stat.find(nbrs[i].size()) == stat.end()){
                stat[nbrs[i].size()] = 1;
            }else{
                stat[nbrs[i].size()]++;
            }
        }
    }

    for( auto &el : stat ){
        std::cout << "size: " << el.first << " count: " << el.second << std::endl;
    }



    return 0;
}