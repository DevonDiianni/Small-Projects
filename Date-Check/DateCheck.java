package edu.vtc.cis3720;

import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.regex.Pattern;

public class DateCheck2{
	
	private int year;
	private int month;
	private int day;
	
	/**
	 * Constructor 
	 * @param month the month being passed
	 * @param day the day being passed
	 * @param year the year being passed
	 */
	public DateCheck2(int month, int day, int year)
	{
		this.month = month;
		this.day = day; 
		this.year = year;
		toString();
	}
	
	//toString
	public String toString() {
        return "Your date is valid!:" + this.month + "," + this.day + "," + this.year;
    }
	
	/**
	 * Calls the global globalDateCheck validation method and the dateCheck validation method
	 * @param month the months being validated
	 * @param day the day being validated
	 * @param year the year being validated
	 */
	public static void validate(int month, int day, int year) {
		if (globalDateCheck(month, day, year) == true) {
			if (validDateCheck(month, day, year) == true) {
				DateCheck2 date = new DateCheck2(month, day, year);
				
			}
		}
		else {
			System.out.println("This date is out of the global bounds of being a real month!");
		}
	}
	
	/**
	 * A global check that a date is in the global bounds of being a legitimate date
	 * @param month the month being passed to be checked
	 * @param day the day being passed to be checked
	 * @param year the year being passed to be checked
	 * @return true if a valid date, return false if the day is not valid
	 */
	public static boolean globalDateCheck(int month, int day, int year) 
	{
		
		if (((year >= 1900 && year <= 2099) && 
				(month >= 1 && month <= 12) && 
				(day >= 1 && day <= 31))) 
		{
			return true;	
		}
		
		else {
			return false;
		}
		
	}
	
	/**
	 * Once date has met global bounds, check the date by month and ensure that the day is valid in that month
	 * @param month the month being passed to be checked
	 * @param day the day being passed to be checked
	 * @param year
	 */
	public static boolean validDateCheck(int month, int day, int year) {
		
		switch (month) 
		{
        case 1:
        	System.out.println("This date in January is valid 1!");
        	return true;
        case 2:
        	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))){
        		if(day <= 28) {
        			System.out.println("This is a valid date for a leap year in February!");
        			return true;
        		}
        		else {
        			System.out.println("This is not a valid date for a leap year in February!");
        			return false;
        		}
        	}
        	else {
        		if(day <= 29) {
        			System.out.println("This is a valid date in February!");
        			return true;
        		}
        		else {
        			System.out.println("This is not a valid date in February!");
        		}
        	}
        case 3:
        	System.out.println("This date in March is valid!");
        	return true;
        case 4:
        	if (day > 30) {
    			System.out.println("This date in April is not valid!");
    			return false;
    		}
    		else {
    			System.out.println("This date in April is valid!");
    			return true;
    		}
        case 5:
        	System.out.println("This is a valid date in May!");
        	return true;
        case 6:
        	if (day > 30) {
    			System.out.println("This date in June is not valid!");
    			return false;
    		}
    		else {
    			System.out.println("This date in June is valid!");
    			return true;
    		}
        case 7:
        	System.out.println("This is a valid date in July!");
            return true;
        case 8:
        	System.out.println("This is a valid date in August!");
            return true;
        case 9:
        	if (day > 30) {
    			System.out.println("This date in September is not valid!");
    			return false;
    		}
    		else {
    			System.out.println("This date in September is valid!");
    			return true;
    		}
        case 10:
        	System.out.println("This is a valid date in October!");
            return true;
        case 11:
        	if (day > 30) {
    			System.out.println("This date in November is not valid!");
    			return false;
    		}
    		else {
    			System.out.println("This date in November is valid!");
    			return true;
    		}
        case 12:
        	System.out.println("This is a valid date in December!");
            return true;
		}
		return false;
		
	}
	
	/**
	 * Check that the date being passed is in a valid date format. If the date is valid a line will be output
	 * @param date the date format being passed in from the user
	 * @return the date
	 * @throws ParseException if the format is not in an acceptable format
	 */
	public static boolean validInput(String date)
	{
	    String[] formats = {"\\d{4}-\\d{2}-\\d{2}","\\d{1,2}/\\d{1,2}/\\d{4}", 
	            "\\w{3}\\s\\d{1,2},\\s{1,}\\d{4}"};

		  for (int i = 0; i < formats.length; i++)
		  {
		      String format = formats[i];
		      if(date.matches(format))
		      {
		          return true;
		      }
		  }
		  System.out.println("The date doesn't have a valid format");
		  return false;
	}
	
	/**
	 * Parse the string input, assign the month, day, and year
	 * @param date the date to be parsed
	 * @return an array of integers (3) that correspond to the month, day, and year
	 */
	public static int[] parse(String date) 
	{
	    final String REGEX = "\\s*(\\s|-|,|/)\\s*";
	    Pattern p = Pattern.compile(REGEX);
        String[] items = p.split(date);
        
        String day = "";
        String year = "";
        String month = "";
	    
	    if(!Character.isDigit(items[0].charAt(0)))
	    {
	        switch (items[0]) {
            case "Jan":
            	month = "1";
                break;
            case "Feb":
            	month = "2";
                break;
            case "Mar":
            	month = "3";
                break;
            case "Apr":
            	month = "4";
                break;
            case "May":
            	month = "5";
                break;
            case "Jun":
            	month = "6";
                break;
            case "Jul":
            	month = "7";
                break;
            case "Aug":
            	month = "8";
                break;
            case "Sep":
            	month = "9";
                break;
            case "Oct":
            	month = "10";
                break;
            case "Nov":
            	month = "11";
                break;
            case "Dec":
            	month = "12";
                break;
	        }
	        day = items[1];
	        year = items[2];
	    }
	    else if(items[0].length() == 4) 
	    {
	        year = items[0];
	        month = items[1];
	        day = items[2];
	    }
	    else
	    {
	        year = items[2];
	        month = items[0];
	        day = items[1];
	    }
	    
	    int imonth = Integer.parseInt(month);
        int iday = Integer.parseInt(day);
        int iyear = Integer.parseInt(year);

        int[] myYear = {imonth, iday, iyear};
		return myYear;
	}
	
	
	 	//getter
	    public int getYear() {
	        return this.year;
	    }
	    
	    //getter
	    public int getMonth() {
	        return this.month;
	    }
	    
	    //getter
	    public int getDay() {
	        return this.day;
	    }
	  
	//main
	public static void main(String[] args) throws ParseException
	{
		String date = "Feb 8, 1907";
		String date2 = "Feb 28, 1908";
		String date3 = "Feb 29, 1908";
		
		if (validInput(date))
		{
		    int[] myYear = parse(date);
		    validate(myYear[0],myYear[1],myYear[2]);
		}
		
		if (validInput(date2))
		{
		    int[] myYear = parse(date2);
		    validate(myYear[0],myYear[1],myYear[2]);
		}
		
		if (validInput(date3))
		{
		    int[] myYear = parse(date3);
		    validate(myYear[0],myYear[1],myYear[2]);
		}
		
		
	}
	
}