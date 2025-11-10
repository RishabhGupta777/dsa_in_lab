//Post tab like instragram

                //    controller.isLoading.value ? Center(child: CircularProgressIndicator()) :
                //   GridView.builder(
                //     padding: EdgeInsets.only(top:60),
                //   gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                //     crossAxisCount: 3,
                //     crossAxisSpacing: 4,
                //     mainAxisSpacing: 4,
                //   ),
                //   itemCount: controller.posts.length,
                //   itemBuilder: (context, index) {
                //     final data = controller.posts[index];
                //     final mediaList = data['mediaUrl'] as List<dynamic>?;
                //
                //     if (mediaList == null || mediaList.isEmpty) {
                //       return const Center(child: Icon(Icons.image_not_supported));
                //     }
                //
                //     final firstMedia = mediaList[0];
                //     final type = firstMedia['type'];
                //     final url = firstMedia['url'];
                //
                //     if (type == 'image') {
                //       return GestureDetector(
                //         onTap: () {
                //           // TODO: open post detail
                //         },
                //         child: Image.network(url, fit: BoxFit.cover),
                //       );
                //     }
                //     // else if (type == 'video') {
                //     //   return _VideoThumbnail(videoUrl: url);
                //     // }
                //
                //     return const SizedBox.shrink();
                //   },
                // ),


                   //var posts = <Map<String, dynamic>>[].obs; // ✅ class-level observable
                   /// ✅ Listen for posts in real-time
                   //   FirebaseFirestore.instance
                   //       .collection('posts')
                   //       .where("uid", isEqualTo: _uid.value)
                   //       .snapshots()
                   //       .listen((snapshot) {
                   //     posts.value = snapshot.docs.map((doc) {
                   //       final data = doc.data();
                   //       return {
                   //         'id': doc.id,
                   //         ...data,
                   //       };
                   //     }).toList();
                   //   });



    //total likes of the id
                      /*SizedBox(width: 25,),
                                                Column(
                      crossAxisAlignment: CrossAxisAlignment.center,
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Text(controller.user['likes'] , style: TextStyle(fontSize: 20 , fontWeight: FontWeight.w700),),
                        SizedBox(height:2,),
                        Text("Likes" , style: TextStyle(fontSize: 14 , fontWeight: FontWeight.w400))
                      ],
                                                ),
                                                 */