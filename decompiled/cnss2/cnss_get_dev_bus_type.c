__int64 __fastcall cnss_get_dev_bus_type(__int64 a1)
{
  unsigned __int16 **v1; // x8

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v1 = *(unsigned __int16 ***)(a1 + 128);
  if ( !v1 )
    return 0xFFFFFFFFLL;
  if ( **v1 ^ 0x6370 | *((unsigned __int8 *)*v1 + 2) ^ 0x69 )
    return 0xFFFFFFFFLL;
  return 0;
}
