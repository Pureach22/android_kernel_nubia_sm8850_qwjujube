const char *__fastcall policy_mgr_hw_mode_to_str(unsigned int a1)
{
  if ( a1 <= 7 )
    return off_9E7380[a1];
  else
    return "Unknown";
}
