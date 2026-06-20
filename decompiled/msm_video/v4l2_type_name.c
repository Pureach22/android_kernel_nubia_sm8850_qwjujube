const char *__fastcall v4l2_type_name(int a1)
{
  if ( (unsigned int)(a1 - 9) > 5 )
    return "UNKNOWN";
  else
    return off_9C140[a1 - 9];
}
