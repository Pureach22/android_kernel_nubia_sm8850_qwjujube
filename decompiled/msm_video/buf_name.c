const char *__fastcall buf_name(unsigned int a1)
{
  if ( a1 <= 0xF )
    return buf_type_name_arr[a1];
  else
    return "UNKNOWN BUF";
}
