
$(document).ready(function() {
    //console.log("document ready");
    //var offset = 0;
    plot();

    function plot() {
        var sin = [],
            cos = [],
            visitor,
            dataList = [],
            timestamp;
      var dataRef = new Firebase('https://epicsuprc.firebaseio.com');
    	dataRef.on('value', function(snapshot) {
    		var t = snapshot.val();
    		for (var key in t) {
    		  if (t.hasOwnProperty(key)) {
    		    var dt = [];
    		    visitor=t[key].data;
    		    timestamp=t[key].time*1000; //from unix to javascript
            dataList.push([timestamp,visitor]);
    		  }
    		};


        var options = {
          xaxis:
          {
             mode: "time",
             timezone: "browser",
             timeformat: "%m/%d/%y %H:%M"
           },

            series: {
                lines: {
                    show: false
                },
                points: {
                    show: true
                }
            },

            grid: {
				          hoverable: true,
				            clickable: true
			     },
           tooltip: true,
           tooltipOpts: {
               content: "At %x, No. %y visited this place",
           }
        };

        console.log(dataList);
        $.plot($("#flot-line-chart"), [
            {
                data: dataList,
            }
          ],
            options);


      });
    }
});
