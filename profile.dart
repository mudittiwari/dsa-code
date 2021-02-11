// import 'dart:html';

// import 'dart:html';

import 'package:flutter/material.dart';
import 'package:flutter_swiper/flutter_swiper.dart';
import 'cart.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:intl/intl.dart';
import 'dart:async';
import 'package:async/async.dart';
import 'package:fluttertoast/fluttertoast.dart';

class profile extends StatefulWidget {
  final user;
  final name;
  const profile(this.name, this.user);
  @override
  _profileState createState() => _profileState();
}

class _profileState extends State<profile> {
  bool _isChecked = false;
  bool _isChecked2 = false;
  bool _isChecked3 = false;
  // List<MapEntry> cartitems = [MapEntry(1, 2)];
  // Map<String, String> cartitems = new Map();
  final total_items = ValueNotifier<int>(0);
  final AsyncMemoizer _memoizer1 = AsyncMemoizer<QuerySnapshot>();
  final AsyncMemoizer _memoizer2 = AsyncMemoizer<QuerySnapshot>();
  final AsyncMemoizer _memoizer3 = AsyncMemoizer<QuerySnapshot>();
  final _scaffoldKey = GlobalKey<ScaffoldState>();
  Future<QuerySnapshot> getdoc() {
    // var doc;
    return _memoizer1.runOnce(() async {
      print("mudit");
      return await Firestore.instance
          .collection('sallons')
          .where('name', isEqualTo: widget.name.toString())
          .getDocuments();
      // print(doc.documents.length);
    });
    // return doc;
  }

  Future<QuerySnapshot> getdoc2() {
    return _memoizer2.runOnce(() async {
      return await Firestore.instance
          .collection('sallons')
          .where('name', isEqualTo: widget.name.toString())
          .getDocuments();
    });
  }

  Future<QuerySnapshot> getsalon() {
    return _memoizer3.runOnce(() async {
      return await Firestore.instance
          .collection('sallon_data')
          .where('name', isEqualTo: widget.name.toString())
          .getDocuments();
    });
  }

  showLoaderDialog(BuildContext context) {
    AlertDialog alert = AlertDialog(
      content: new Row(
        children: [
          CircularProgressIndicator(),
          Container(
              margin: EdgeInsets.only(left: 7), child: Text("Loading...")),
        ],
      ),
    );
    showDialog(
      barrierDismissible: false,
      context: context,
      builder: (BuildContext context) {
        return alert;
      },
    );
  }

  Map<String, int> item_count_map = new Map();
  // Map ls = new Map();
  @override
  Widget build(BuildContext context) {
    total_items.value = 0;
    return Scaffold(
      backgroundColor: Colors.white,
      body: CustomScrollView(
        slivers: [
          SliverAppBar(
            backgroundColor: Colors.white,
            expandedHeight: 250,
            centerTitle: true,
            // floating: false,
            // pinned: false,
            flexibleSpace: FlexibleSpaceBar(
              background: Swiper(
                itemCount: 5,
                itemBuilder: (context, index) => Image.asset(
                  "assets/images/profile.jpg",
                  fit: BoxFit.cover,
                ),
                autoplay: true,
              ),
            ),
          ),
          SliverList(
              delegate: SliverChildListDelegate([
            Padding(
              padding: const EdgeInsets.only(top: 8.0),
              child: ListTile(
                title: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    FutureBuilder(
                      future: getsalon(),
                      builder: (context, snapshot) {
                        if (snapshot.connectionState == ConnectionState.waiting)
                          return Center(
                            child: CircularProgressIndicator(),
                          );
                        else if (snapshot.hasError)
                          return Icon(Icons.error);
                        else {
                          return Container(
                            child: Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                Text(
                                  widget.name.toString(),
                                  style: TextStyle(
                                      fontWeight: FontWeight.bold,
                                      fontSize: 20),
                                ),
                                Padding(
                                  padding: const EdgeInsets.only(top: 4.0),
                                  child: Text(
                                    snapshot.data.documents.first["address"]
                                        .toString(),
                                    style: TextStyle(fontSize: 15),
                                  ),
                                ),
                                Padding(
                                  padding: const EdgeInsets.only(top: 8.0),
                                  child: Text(
                                    "irimudittiwa irimuditti wairimudi ttiwairim udittiwairim uditt iwai rimudittiwair imud ittiwai r imuditt iwairim udittiwa irimuditti wairi mud ittiwairi",
                                    style: TextStyle(fontSize: 17.0),
                                  ),
                                ),
                              ],
                            ),
                          );
                        }
                      },
                    ),
                    Padding(
                      padding: const EdgeInsets.only(top: 8.0),
                      child: Text(
                        "Ammenities:",
                        style: TextStyle(
                            fontSize: 20.0, fontWeight: FontWeight.bold),
                      ),
                    ),
                    FutureBuilder(
                      future: getdoc2(),
                      builder: (context, snapshot) {
                        if (snapshot.connectionState == ConnectionState.waiting)
                          return Center(
                            child: CircularProgressIndicator(),
                          );
                        else if (snapshot.hasError)
                          return Icon(Icons.error);
                        else {
                          Map ls = snapshot.data.documents
                              .elementAt(0)
                              .data
                              .map((key, value) {
                            return MapEntry(key, value);
                          });
                          ls.remove("name");
                          ls.remove("photo_url");
                          // print("muidt");
                          // print(ls);
                          List keys = ls.keys.toList();
                          return Container(
                            child: ListView.builder(
                              padding: EdgeInsets.symmetric(vertical: 6),
                              shrinkWrap: true,
                              physics: NeverScrollableScrollPhysics(),
                              itemCount: ls.length,
                              itemBuilder: (context, index) {
                                return Padding(
                                  padding: const EdgeInsets.only(top: 0.0),
                                  child: Text(
                                    keys[index],
                                    style: TextStyle(
                                        fontSize: 20.0,
                                        fontWeight: FontWeight.w400),
                                  ),
                                );
                              },
                            ),
                          );
                        }
                      },
                    ),
                    Padding(
                      padding: const EdgeInsets.only(top: 8.0),
                      child: Container(
                        padding: EdgeInsets.all(15.0),
                        decoration: BoxDecoration(
                            color: Colors.grey[300],
                            borderRadius: BorderRadius.circular(10.0)),
                        child: Row(
                          children: [
                            Expanded(
                              flex: 1,
                              child: Center(
                                child: Text(
                                  "31 DEC",
                                  style: TextStyle(fontWeight: FontWeight.bold),
                                ),
                              ),
                            ),
                            Expanded(
                              flex: 2,
                              child: Container(
                                decoration: BoxDecoration(
                                    border: Border.symmetric(
                                        vertical: BorderSide(width: 1.0))),
                                child: Center(
                                  child: Text(
                                    "08:30 AM",
                                    style:
                                        TextStyle(fontWeight: FontWeight.bold),
                                  ),
                                ),
                              ),
                            ),
                            Expanded(
                              flex: 1,
                              child: Container(
                                child: Center(
                                  child: Text(
                                    "Male",
                                    style:
                                        TextStyle(fontWeight: FontWeight.bold),
                                  ),
                                ),
                              ),
                            ),
                          ],
                        ),
                      ),
                    )
                  ],
                ),
              ),
            ),
            FutureBuilder<QuerySnapshot>(
              future: getdoc(),
              builder: (context, snapshot) {
                if (snapshot.connectionState == ConnectionState.waiting)
                  return Center(
                    child: CircularProgressIndicator(),
                  );
                else if (snapshot.hasError)
                  return Icon(Icons.error);
                else {
                  Map ls = snapshot.data.documents
                      .elementAt(0)
                      .data
                      .map((key, value) {
                    return MapEntry(key, value);
                  });
                  // print(ls);
                  ls.remove("name");
                  ls.remove("photo_url");
                  List keys = ls.keys.toList();
                  for (var item in keys) {
                    item_count_map[item.toString()] = 0;
                  }
                  print(item_count_map);
                  return Container(
                    // height: 400,
                    child: ListView.builder(
                      shrinkWrap: true,
                      physics: NeverScrollableScrollPhysics(),
                      itemBuilder: (context, index) {
                        final item_count = ValueNotifier<int>(0);
                        return Padding(
                          padding: const EdgeInsets.symmetric(
                              vertical: 8.0, horizontal: 12),
                          child: Container(
                            decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(12),
                              boxShadow: [
                                BoxShadow(
                                    color: Colors.grey.withOpacity(0.5),
                                    spreadRadius: 1,
                                    blurRadius: 5,
                                    offset: Offset(0, 2))
                              ],
                            ),
                            child: ListTile(
                              title: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text(
                                    keys[index].toString()[0].toUpperCase() +
                                        keys[index].toString().substring(1),
                                    style: TextStyle(
                                        color: Colors.blue[700],
                                        fontWeight: FontWeight.w500),
                                  ),
                                  Padding(
                                    padding: const EdgeInsets.only(top: 5.0),
                                    child: Text("(25-30 min app)",
                                        style: TextStyle(
                                            // color: Colors.blue[700],
                                            // fontWeight: FontWeight.w500),
                                            fontSize: 13.0)),
                                  ),
                                  Padding(
                                    padding: const EdgeInsets.only(top: 5.0),
                                    child: Text(
                                      '${ls[keys[index]]}',
                                      style: TextStyle(
                                          color: Colors.blue[700],
                                          fontWeight: FontWeight.w500,
                                          fontSize: 15.0),
                                    ),
                                  ),
                                ],
                              ),
                              leading: Image(
                                  image:
                                      AssetImage("assets/images/profile.jpg")),
                              trailing: Container(
                                  decoration: BoxDecoration(
                                      color: Colors.grey,
                                      borderRadius: BorderRadius.circular(8)),
                                  width: 70,
                                  padding: EdgeInsets.symmetric(
                                      horizontal: 8, vertical: 6),
                                  // width: 20,
                                  // color: Colors.blue,
                                  child: Row(
                                    mainAxisAlignment:
                                        MainAxisAlignment.spaceBetween,
                                    children: [
                                      InkWell(
                                        onTap: () {
                                          if (item_count_map[keys[index]] ==
                                              0) {
                                            total_items.value = 0;
                                            final snack = SnackBar(
                                                content:
                                                    Text("item not in cart"));
                                            Scaffold.of(context)
                                                .showSnackBar(snack);
                                          } else {
                                            total_items.value--;
                                            item_count_map[keys[index]]--;
                                          }
                                          item_count.value =
                                              item_count_map[keys[index]];
                                          print(item_count_map);
                                        },
                                        child: Icon(
                                          Icons.remove,
                                          color: Colors.white,
                                          size: 15,
                                        ),
                                      ),
                                      ValueListenableBuilder(
                                        valueListenable: item_count,
                                        builder: (context, value, child) {
                                          return Text(
                                            value == 0 ? "0" : value.toString(),
                                            style:
                                                TextStyle(color: Colors.white),
                                          );
                                        },
                                      ),
                                      InkWell(
                                        onTap: () {
                                          item_count_map[keys[index]]++;
                                          item_count.value =
                                              item_count_map[keys[index]];
                                          total_items.value++;
                                        },
                                        child: Icon(
                                          Icons.add,
                                          color: Colors.white,
                                          size: 15,
                                        ),
                                      ),
                                    ],
                                  )),
                            ),
                          ),
                        );
                      },
                      itemCount: ls.length,
                    ),
                  );
                }
              },
            ),
            ListTile(
              title: Text(
                "Please select more options if necessary:",
                style: TextStyle(fontWeight: FontWeight.bold, fontSize: 17),
              ),
            ),
            Padding(
              padding: const EdgeInsets.only(bottom: 100.0),
              child: ListTile(
                  title: Scrollbar(
                child: Column(
                  children: [
                    Padding(
                      padding: const EdgeInsets.symmetric(vertical: 8.0),
                      child: Container(
                        decoration: BoxDecoration(
                          color: Colors.white,
                          borderRadius: BorderRadius.circular(12),
                          boxShadow: [
                            BoxShadow(
                                color: Colors.grey.withOpacity(0.5),
                                spreadRadius: 1,
                                blurRadius: 5,
                                offset: Offset(0, 2))
                          ],
                        ),
                        child: CheckboxListTile(
                          title: Text(
                            'Senitized Cloth',
                            style: TextStyle(
                                color: Colors.blue[700],
                                fontWeight: FontWeight.w500),
                          ),
                          subtitle: const Text('160 Rs'),
                          value: _isChecked,
                          checkColor: Colors.blue,
                          activeColor: Colors.white,
                          onChanged: (bool value) {
                            setState(() {
                              _isChecked = value;
                            });
                          },
                        ),
                      ),
                    ),
                    Padding(
                      padding: const EdgeInsets.symmetric(vertical: 8.0),
                      child: Container(
                        decoration: BoxDecoration(
                          color: Colors.white,
                          borderRadius: BorderRadius.circular(12),
                          boxShadow: [
                            BoxShadow(
                                color: Colors.grey.withOpacity(0.5),
                                spreadRadius: 1,
                                blurRadius: 5,
                                offset: Offset(0, 2))
                          ],
                        ),
                        child: CheckboxListTile(
                          title: Text(
                            'Senitized wrapper',
                            style: TextStyle(
                                color: Colors.blue[700],
                                fontWeight: FontWeight.w500),
                          ),
                          subtitle: const Text('160 Rs'),
                          value: _isChecked2,
                          checkColor: Colors.blue,
                          activeColor: Colors.white,
                          onChanged: (bool value) {
                            setState(() {
                              _isChecked2 = value;
                            });
                          },
                        ),
                      ),
                    ),
                    Padding(
                      padding: const EdgeInsets.symmetric(vertical: 8.0),
                      child: Container(
                        decoration: BoxDecoration(
                          color: Colors.white,
                          borderRadius: BorderRadius.circular(12),
                          boxShadow: [
                            BoxShadow(
                                color: Colors.grey.withOpacity(0.5),
                                spreadRadius: 1,
                                blurRadius: 5,
                                offset: Offset(0, 2))
                          ],
                        ),
                        child: CheckboxListTile(
                          title: Text(
                            'Senitized mask',
                            style: TextStyle(
                                color: Colors.blue[700],
                                fontWeight: FontWeight.w500),
                          ),
                          subtitle: const Text('160 Rs'),
                          value: _isChecked3,
                          checkColor: Colors.blue,
                          activeColor: Colors.white,
                          onChanged: (bool value) {
                            setState(() {
                              _isChecked3 = value;
                            });
                          },
                        ),
                      ),
                    ),
                  ],
                ),
              )),
            ),
          ])),
        ],
      ),
      floatingActionButton: new Builder(
        builder: (context) {
          return Padding(
            padding: const EdgeInsets.only(bottom: 18.0, left: 4, right: 4),
            // child: Row(
            //   children: [
            //     // RaisedButton(
            //     //   elevation: 8.0,
            //     //   shape: RoundedRectangleBorder(
            //     //       borderRadius: BorderRadius.circular(25)),
            //     //   color: Colors.green,
            //     //   padding: EdgeInsets.symmetric(
            //     //       horizontal: MediaQuery.of(context).size.width * (.4),
            //     //       vertical: 15),
            //     //   onPressed: () {
            //     //     if (cartitems.length == 0) {
            //     //       Scaffold.of(context).showSnackBar(
            //     //           SnackBar(content: Text("Cart is empty")));
            //     //     } else {
            //     //       if (_isChecked == true)
            //     //         cartitems["cloth"] = "160";
            //     //       else {
            //     //         if (cartitems.containsKey("cloth") == true)
            //     //           cartitems.remove("cloth");
            //     //       }
            //     //       if (_isChecked2 == true)
            //     //         cartitems["wrapper"] = "160";
            //     //       else {
            //     //         if (cartitems.containsKey("wrapper") == true)
            //     //           cartitems.remove(("wrapper"));
            //     //       }
            //     //       if (_isChecked3 == true)
            //     //         cartitems["mask"] = "160";
            //     //       else {
            //     //         if (cartitems.containsKey("mask") == true)
            //     //           cartitems.remove("mask");
            //     //       }
            //     //       List<MapEntry<dynamic, dynamic>> finallist = cartitems
            //     //           .entries
            //     //           .map((e) => MapEntry(e.key, e.value))
            //     //           .toList();
            //     //       // print(finallist[0].key);
            //     //       Navigator.push(
            //     //           context,
            //     //           MaterialPageRoute(
            //     //             builder: (context) => cart(
            //     //                 finallist, widget.name, widget.user, cartitems),
            //     //           ));
            //     //     }
            //     //     // print(cartitems);
            //     //     // List finallist = cartitems.entries.map((entry) {});
            //     //   },
            //     //   child: Text(
            //     //     "BOOK",
            //     //     style: TextStyle(
            //     //         color: Colors.white,
            //     //         fontSize: 20,
            //     //         fontWeight: FontWeight.bold),
            //     //   ),
            //     // ),

            //   ],
            // ),
            child: InkWell(
              onTap: () {
                showLoaderDialog(context);
                item_count_map.removeWhere((key, value) => value == 0);
                if (item_count_map.length == 0) {
                  Scaffold.of(context)
                      .showSnackBar(SnackBar(content: Text("Cart is empty")));
                } else {
                  if (_isChecked) item_count_map["cloth"] = 1;
                  if (_isChecked2) item_count_map["wrapper"] = 1;
                  if (_isChecked3) item_count_map["mask"] = 1;
                  Map ls = new Map();
                  Firestore.instance
                      .collection('sallons')
                      .where('name', isEqualTo: widget.name)
                      .getDocuments()
                      .then((value) {
                    ls = value.documents.elementAt(0).data.map((key, value) {
                      return MapEntry(key, value);
                    });
                  });
                  // print(ls);
                  ls.remove("name");
                  ls.remove("photo_url");
                  List keys = ls.keys.toList();
                  print(item_count_map);
                }
              },
              child: Container(
                height: 55,
                width: MediaQuery.of(context).size.width,
                decoration: BoxDecoration(
                    color: Colors.green,
                    borderRadius: BorderRadius.circular(25)),
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 18.0),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text(
                        "BOOK",
                        style: TextStyle(
                            color: Colors.white,
                            fontSize: 20,
                            fontWeight: FontWeight.bold),
                      ),
                      ValueListenableBuilder(
                        valueListenable: total_items,
                        builder: (context, value, child) {
                          return Text(
                            value == 0
                                ? "0 items"
                                : value.toString() + " items",
                            style: TextStyle(
                                color: Colors.white,
                                fontSize: 20,
                                fontWeight: FontWeight.bold),
                          );
                        },
                      ),
                    ],
                  ),
                ),
              ),
            ),
          );
        },
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
    );
  }
}
