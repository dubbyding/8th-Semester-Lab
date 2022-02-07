var interval,
  time,
  i1 = 100,
  i2 = 80;
// set Initial time
window.onload = () => {
  time = 0;
  interval = setInterval(() => {
    time++;
    document.getElementById("time").innerHTML = time;
  }, 1000);
};

// setting dropdown choose sequence
$(".from-class").click(function () {
  var from_id = this.id;
  document.getElementById("from").value = from_id.split("-")[0];
});
$(".to-class").click(function () {
  var to_id = this.id;
  document.getElementById("destination").value = to_id.split("-")[0];
});

// Random Number Generator
var randomNumGen = () => {
  return new Promise((res) => {
    var i3 = ((i1 + i2) % 99) + 1;
    i1 = i2;
    i2 = i3;
    res(i3);
  });
};
// For stopping clock
var stop_clock = document.getElementById("stop");
stop_clock.onclick = function () {
  clearInterval(interval);
};

// Resuming the clock
var resume_clock = document.getElementById("resume");
resume_clock.onclick = () => {
  interval = setInterval(() => {
    time++;
    document.getElementById("time").innerHTML = time;
  }, 1000);
};
//checking empty places
var empty_places = (given_class) => {
  return new Promise((resolve, reject) => {
    var place_class = document.getElementsByClassName(given_class);
    for (var i = 0; i < place_class.length; i++) {
      var id = place_class[i].id;
      if (document.getElementById(id).innerHTML === "0") {
        resolve(i + 1);
      }
    }
  });
};

// setting the submit sequence
var button = document.getElementById("start");
button.onclick = function () {
  var from = document.getElementById("from").value;
  var to = document.getElementById("destination").value;
  var from_status = document.getElementById(from);
  var to_status = document.getElementById(to);
  // checking if line is busy
  //if non of them are busy go to call
  if (from_status.innerHTML == 0 || to_status.innerHTML == 0) {
    from_status.innerHTML = 1;
    to_status.innerHTML = 1;
    randomNumGen().then((duration) => {
      empty_places("from-going-on").then((empty_status) => {
        var from_id = String(empty_status) + "-from";
        var to_id = String(empty_status) + "-to";
        var duration_id = String(empty_status) + "-time";
        document.getElementById(from_id).innerHTML = from;
        document.getElementById(to_id).innerHTML = to;
        document.getElementById(duration_id).innerHTML = String(
          duration + time
        );
      });
    });
  }
};
