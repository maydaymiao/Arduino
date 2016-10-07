var mqtt = require('mqtt'); //includes mqtt server
var mongodb = require('mongodb'); // includes mongoDB
var mongodbClient = mongodb.MongoClient; //initialises the mongoDB client
var mongodbURI = 'mongodb://localhost:27017/test'; //activating the MongoDB port 27017, here TempMontor is the name of the database
var deviceRoot = "dht11"; //deviceroot is topic name given in arduino code
var collection,client; //initialise collection and client

mongodbClient.connect(mongodbURI, setupCollection); //connect the database with collecion

function setupCollection(err, db) {
    if(err) throw err;
    collection=db.collection("newcollection"); //name of the collection in the database
    client=mqtt.connect('mqtt://192.168.2.103'); //connecting the mqtt server with the MongoDB database
    client.subscribe(deviceRoot); //subscribing to the topic name
    client.on('message', insertEvent); //inserting the event
}

//function that displays the data in the MongoDataBase
function insertEvent(topic,message) {
    //var key=topic.replace(deviceRoot,'');

    collection.update(
        { _id:deviceRoot },
        { $push: { events: { event: {  value:message.toString(), when:new Date() } } } },
        { upsert:true },

        function(err,docs) {
            if(err) {
                console.log("Insert fail")// Improve error handling
            }
        }

    );

}
