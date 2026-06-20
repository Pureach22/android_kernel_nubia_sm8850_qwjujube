const char *__fastcall state_name(unsigned int a1)
{
  if ( a1 <= 5 )
    return state_name_arr[a1];
  else
    return "UNKNOWN STATE";
}
