totalDegrees = function(data) {

  returnValue = 0;
  _.each(data, function(element, index, list) {

    returnValue = element.AWARDS + returnValue;
  });

  return (returnValue);
}

//console.log(totalDegrees(wsudgrs));

percentagePhD = function(data) {
  listOfDoctorals = _.filter(data, function(object) {
    return object.Level === "Doctoral";
  });

  return ((totalDegrees(listOfDoctorals) / totalDegrees(data)) * 100);
};

totalDegreesByYear = function(data, year) {

  listOfYear = _.filter(data, function(object) {
    return object.FISCAL_YEAR == year;
  });

  return (totalDegrees(listOfYear));
}

listCampuses = function(data) {

  dataGroupedByCampuses = _.groupBy(data, "CAMPUS");
  return (Object.keys(dataGroupedByCampuses));
}

listCampusDegrees = function(data) {

  dataGroupedByCampuses = _.groupBy(data, "CAMPUS");
  _.each(dataGroupedByCampuses, function(element, index, list) {
    list[index] = totalDegrees(element);
  });
  return (dataGroupedByCampuses);
}

maxDegrees = function(data) {

  dataGroupedByYear = _.groupBy(data, "FISCAL_YEAR");
  maxValue = 0
  _.each(dataGroupedByYear, function(element, index, list) {
    list[index] = totalDegrees(element);
  });
  dataGroupedByYearArray = Object.entries(dataGroupedByYear); //convert object containing years as keys and total degrees as variables into array of arrays of years and totals.
  return (_.max(dataGroupedByYearArray, function(year) {
    return year[1]
  })[0]); //return the year in which the total degrees is maximum by accessing the second field of the array and returning
  				//the first field of the returned array.
}
//console.log(totalDegrees(wsudgrs));
//console.log(percentagePhD(wsudgrs));
//console.log(totalDegreesByYear(wsudgrs, 2008));
//console.log(listCampuses(wsudgrs));
//console.log(listCampusDegrees(wsudgrs));
console.log(maxDegrees(wsudgrs));