__int64 __fastcall _check_ctl_power_on_pakala(__int64 a1)
{
  if ( (_read_register(a1, 0xF8034u) & 0x80000000) != 0 )
    return ((int)_read_register(a1, 0xF804Cu) >> 31) & 0xFFFFFFFE;
  else
    return 0xFFFFFFFFLL;
}
