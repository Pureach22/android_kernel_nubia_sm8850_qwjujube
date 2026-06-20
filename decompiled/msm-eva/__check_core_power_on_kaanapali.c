__int64 __fastcall _check_core_power_on_kaanapali(__int64 a1)
{
  if ( (_read_register(a1, 0xF8068u) & 0x80000000) != 0 )
    return ((int)_read_register(a1, 0xF807Cu) >> 31) & 0xFFFFFFFE;
  else
    return 0xFFFFFFFFLL;
}
