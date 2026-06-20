const char *__fastcall hdd_action_type_to_string(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x12 )
    return "Invalid";
  else
    return off_AFB240[a1 - 1];
}
