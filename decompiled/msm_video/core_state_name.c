const char *__fastcall core_state_name(unsigned int a1)
{
  if ( a1 <= 3 )
    return core_state_name_arr[a1];
  else
    return "UNKNOWN STATE";
}
