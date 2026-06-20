const char *__fastcall device_region_name(unsigned int a1)
{
  if ( a1 <= 4 )
    return device_region_name_arr[a1];
  else
    return "UNKNOWN REGION";
}
