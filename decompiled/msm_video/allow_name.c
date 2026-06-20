const char *__fastcall allow_name(unsigned int a1)
{
  if ( a1 <= 4 )
    return inst_allow_name_arr[a1];
  else
    return "UNKNOWN";
}
