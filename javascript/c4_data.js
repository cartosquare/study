DATA = require('./jacques_journal.js')

var journal = [];

function addEntry(events, didITurnIntoASquirrel) {
    journal.push({
        events: events,
    });
}

addEntry(["work", "touched tree", "pizza", "running", "television"], false);
addEntry(["work", "ice cream", "cauliflower", "lasagna", "touched tree", "brushed teeth"], false);
addEntry(["weekend", "cycling", "break", "peanuts", "beer"], true);

function phi(table) {
    return (table[3] * table[0] - table[2] * table[1]) /
        Math.sqrt((table[2] + table[3]) * (table[0] + table[1]) * (table[1] + table[3]) * (table[0] + table[2]));
}

function hasEvent(event, entry) {
     return entry.events.indexOf(event) != -1;
 }

function tableFor(event, journal) {
    console.log("table for event: " + event);

    var table = [0, 0, 0, 0];
    for (var i = 0; i < journal.length; ++i) {
        var entry = journal[i];
        var index = 0;
        if (hasEvent(event, entry))
            index += 1;
        if (entry.squirrel)
            index += 2;
        table[index] += 1;
    }
    console.log("table for this event: " + table);
    return table;
}

var map = {};
function storePhi(event, phi) {
    map[event] = phi;
}

function gatherCorrelations(journal) {
    var phis = {};
    console.log("Journal length: " + journal.length);
    for (var entry = 0; entry < journal.length; ++entry) {
        var events= journal[entry].events;
        console.log("Events for this journal: " + events);
        console.log("Events length: " + events.length);

        for (var i = 0; i < events.length; ++i) {
            var event = events[i];
            console.log("event--" + event);

            if (!(event in phis)) {
                console.log("Precessing event: " + event);

                phis[event] = phi(tableFor(event, journal));

                console.log("PHI: " + phis[event]);
            }
        }
    }
    return phis;
}

var correlations = gatherCorrelations(DATA);
console.log("##################################");
for (var event in correlations) {
    var correlation = correlations[event];
    if (correlation > 0.1 || correlation < -0.1)
        console.log(event + ": " + correlations[event]);
}
