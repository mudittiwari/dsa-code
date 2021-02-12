// import 'dart:html';

import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:double_back_to_close_app/double_back_to_close_app.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:whatsapp_clone/booking_done.dart';
import 'package:whatsapp_clone/widgets.dart';
import 'package:whatsapp_clone/wishlist.dart';
import 'cart.dart';
import 'customer.dart';
import 'homepage.dart';
import 'profilescreen.dart';
import 'package:async/async.dart';

class history extends StatefulWidget {
  // final AuthResult result;
  final user;
  const history(this.user);
  @override
  _historyState createState() => _historyState();
}

class _historyState extends State<history> {
  final AsyncMemoizer _memoizer1 = AsyncMemoizer<QuerySnapshot>();
  final AsyncMemoizer _memoizer2 = AsyncMemoizer<QuerySnapshot>();
  Future<QuerySnapshot> getactive() {
    return _memoizer1.runOnce(() async {
      return Firestore.instance
          .collection('active_bookings')
          .where('user_number', isEqualTo: widget.user["number"])
          .getDocuments();
    });
  }

  Future<QuerySnapshot> getlocation(String name) {
    return Firestore.instance
        .collection('sallon_data')
        .where('name', isEqualTo: name)
        .getDocuments();
  }

  Future<QuerySnapshot> getprev() {
    return _memoizer2.runOnce(() async {
      return Firestore.instance
          .collection('previous_bookings')
          .where('user_number', isEqualTo: widget.user["number"])
          .getDocuments();
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      bottomNavigationBar: BottomAppBar(
        child: Container(
          width: MediaQuery.of(context).size.width,
          child: Padding(
            padding: const EdgeInsets.only(top: 8.0, bottom: 8),
            child: Row(
              children: [
                Expanded(
                  child: IconButton(
                      icon: Icon(
                        Icons.home,
                        color: Colors.grey,
                        size: 33.0,
                      ),
                      onPressed: () {
                        Navigator.pushReplacement(
                            context,
                            MaterialPageRoute(
                                builder: (context) => homepage(widget.user)));
                      }),
                ),
                Expanded(
                  child: IconButton(
                      icon: Icon(
                        Icons.favorite,
                        color: Colors.grey,
                        size: 33.0,
                      ),
                      onPressed: () {
                        Navigator.pushReplacement(
                            context,
                            MaterialPageRoute(
                              builder: (context) => wishlist(widget.user),
                            ));
                      }),
                ),
                Expanded(
                  child: IconButton(
                      icon: Icon(
                        Icons.history,
                        color: Colors.grey,
                        size: 33.0,
                      ),
                      onPressed: () {}),
                ),
                Expanded(
                  child: IconButton(
                      icon: Icon(
                        Icons.call,
                        color: Colors.grey,
                        size: 33.0,
                      ),
                      onPressed: () {
                        Navigator.pushReplacement(
                            context,
                            MaterialPageRoute(
                              builder: (context) => customer(widget.user),
                            ));
                      }),
                ),
                Expanded(
                  child: IconButton(
                      icon: Icon(
                        Icons.person,
                        color: Colors.grey,
                        size: 33.0,
                      ),
                      onPressed: () {
                        Navigator.pushReplacement(
                            context,
                            MaterialPageRoute(
                              builder: (context) => profilescreen(widget.user),
                            ));
                      }),
                ),
              ],
            ),
          ),
        ),
      ),
      appBar: AppBar(
        iconTheme: IconThemeData(
          color: Colors.black,
        ),
        elevation: 0,
        backgroundColor: Colors.white,
        title: Text(
          "Bookings & Appointments",
          style: TextStyle(color: Colors.black, fontWeight: FontWeight.bold),
        ),
        centerTitle: true,
      ),
      body: DoubleBackToCloseApp(
        snackBar: SnackBar(content: Text("Press again to quit")),
        child: Container(
          height: MediaQuery.of(context).size.height,
          width: MediaQuery.of(context).size.width,
          child: ListView(
            children: [
              Padding(
                padding: const EdgeInsets.only(top: 18.0),
                child: ListTile(
                  title: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        "Upcoming Bookings:",
                        style: TextStyle(
                            color: Colors.black,
                            fontSize: 18,
                            fontWeight: FontWeight.bold),
                      ),
                      FutureBuilder(
                        future: getactive(),
                        builder: (context, snapshot) {
                          if (snapshot.connectionState ==
                              ConnectionState.waiting)
                            return Center(
                              child: CircularProgressIndicator(),
                            );
                          else if (snapshot.hasError)
                            return Center(
                              child: Icon(Icons.error),
                            );
                          else {
                            // print(snapshot.data.documents.length);
                            return Container(
                              child: ListView.builder(
                                shrinkWrap: true,
                                physics: NeverScrollableScrollPhysics(),
                                itemBuilder: (context, index) {
                                  return Padding(
                                    padding: const EdgeInsets.only(top: 20),
                                    child: Container(
                                      width: MediaQuery.of(context).size.width,
                                      height: 200,
                                      decoration: BoxDecoration(
                                        color: Colors.white,
                                        borderRadius: BorderRadius.circular(12),
                                        boxShadow: [
                                          BoxShadow(
                                              color:
                                                  Colors.grey.withOpacity(0.5),
                                              spreadRadius: 1,
                                              blurRadius: 5,
                                              offset: Offset(0, 2))
                                        ],
                                      ),
                                      child: Row(
                                        children: [
                                          Expanded(
                                              flex: 3,
                                              child: Column(
                                                crossAxisAlignment:
                                                    CrossAxisAlignment.start,
                                                children: [
                                                  Padding(
                                                    padding:
                                                        const EdgeInsets.all(
                                                            8.0),
                                                    child: Text(
                                                      "16 January 2021, Tuesday",
                                                      style: TextStyle(
                                                          fontSize: 15.0),
                                                    ),
                                                  ),
                                                  Padding(
                                                    padding: const EdgeInsets
                                                            .symmetric(
                                                        horizontal: 8.0),
                                                    child: Text(
                                                      "11:30 AM",
                                                      style: TextStyle(
                                                          fontSize: 15.0),
                                                    ),
                                                  ),
                                                  Padding(
                                                    padding:
                                                        const EdgeInsets.all(
                                                            8.0),
                                                    child: Text(
                                                      snapshot.data.documents
                                                              .elementAt(index)[
                                                          "sallon_name"],
                                                      style: TextStyle(
                                                          fontWeight:
                                                              FontWeight.bold,
                                                          fontSize: 20),
                                                    ),
                                                  ),
                                                  Padding(
                                                    padding:
                                                        const EdgeInsets.all(
                                                            8.0),
                                                    child: Row(
                                                      children: [
                                                        Icon(
                                                          Icons.star,
                                                          color: Colors.yellow,
                                                        ),
                                                        Padding(
                                                          padding:
                                                              const EdgeInsets
                                                                      .only(
                                                                  left: 8.0),
                                                          child: Text("4.9"),
                                                        )
                                                      ],
                                                    ),
                                                  ),
                                                  Padding(
                                                    padding:
                                                        const EdgeInsets.all(
                                                            8.0),
                                                    child: Row(
                                                      children: [
                                                        Icon(
                                                          Icons.location_on,
                                                        ),
                                                        Flexible(
                                                            child: Padding(
                                                          padding:
                                                              const EdgeInsets
                                                                      .only(
                                                                  left: 8.0),
                                                          child: Container(
                                                            height: 50,
                                                            child: Align(
                                                              alignment: Alignment
                                                                  .centerLeft,
                                                              child:
                                                                  FutureBuilder(
                                                                future: getlocation(snapshot
                                                                        .data
                                                                        .documents
                                                                        .elementAt(
                                                                            index)[
                                                                    "sallon_name"]),
                                                                builder: (context,
                                                                    snapshot) {
                                                                  if (snapshot
                                                                          .connectionState ==
                                                                      ConnectionState
                                                                          .waiting)
                                                                    return Text(
                                                                        "Loading.....");
                                                                  else if (snapshot
                                                                      .hasError)
                                                                    return Text(
                                                                        "Error");
                                                                  else {
                                                                    return Text(
                                                                      snapshot
                                                                          .data
                                                                          .documents
                                                                          .first["address"],
                                                                      style:
                                                                          TextStyle(),
                                                                      textAlign:
                                                                          TextAlign
                                                                              .center,
                                                                    );
                                                                  }
                                                                },
                                                              ),
                                                            ),
                                                          ),
                                                        ))
                                                      ],
                                                    ),
                                                  )
                                                ],
                                              )),
                                          Expanded(
                                            flex: 2,
                                            child: Container(
                                              height: 200,
                                              child: ClipRRect(
                                                borderRadius: BorderRadius.only(
                                                    topRight:
                                                        Radius.circular(12.0),
                                                    bottomRight:
                                                        Radius.circular(12.0)),
                                                child: Image(
                                                  image: AssetImage(
                                                      "assets/images/profile.jpg"),
                                                  fit: BoxFit.cover,
                                                ),
                                              ),
                                            ),
                                          ),
                                        ],
                                      ),
                                    ),
                                  );
                                },
                                itemCount: snapshot.data.documents.length,
                              ),
                            );
                          }
                        },
                      )
                    ],
                  ),
                ),
              ),
              ListTile(
                title: Text(
                  "Previous Bookings:",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                ),
              ),
              Padding(
                padding: const EdgeInsets.only(top: 8.0, bottom: 10.0),
                child: ListTile(
                  title: Container(
                      width: MediaQuery.of(context).size.width,
                      height: 240,
                      child: FutureBuilder(
                        future: getprev(),
                        builder: (context, snapshot) {
                          if (snapshot.connectionState ==
                              ConnectionState.waiting)
                            return Center(
                              child: CircularProgressIndicator(),
                            );
                          else if (snapshot.hasError)
                            return Center(
                              child: Icon(Icons.error),
                            );
                          else {
                            return ListView.builder(
                              scrollDirection: Axis.horizontal,
                              itemCount: snapshot.data.documents.length,
                              itemBuilder: (context, index) {
                                return saloonthree(
                                    snapshot.data.documents.elementAt(index));
                              },
                            );
                          }
                        },
                      )),
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
