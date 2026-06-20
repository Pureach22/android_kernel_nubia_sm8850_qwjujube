const char *__fastcall synx_debugfs_util_get_state_name(unsigned int a1)
{
  if ( a1 < 7 )
    return (&off_24EC0)[a1];
  if ( a1 <= 0x40 )
    return "???";
  return "CUS";
}
