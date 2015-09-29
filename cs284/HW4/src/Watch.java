
public interface Watch 
{ 
   int  getHour     ();	
   void setHour     (int hour  );
   int  getMinute     ();	
   void setMinute     (int minutes  );
   int  getSecond     ();	
   void setSecond     (int seconds  );
   
   
   
   // TODO Declare functions that get/set minutes and seconds

   int  getUtcHour  ();
   void setUtcHour  (int hour  );
   int  getUtcMinute  ();
   void setUtcMinute  (int minutes  );
   int  getUtcSecond  ();
   void setUtcSecond  (int seconds  );
   // TODO Declare functions that get/set UTC minutes and seconds
   
   String toString();
}
