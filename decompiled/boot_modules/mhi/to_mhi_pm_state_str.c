const char *__fastcall to_mhi_pm_state_str(unsigned int a1)
{
  unsigned int v1; // w8

  if ( a1 && (v1 = __clz(a1) ^ 0x1F, v1 <= 0xC) )
    return mhi_pm_state_str[v1];
  else
    return "Invalid State";
}
