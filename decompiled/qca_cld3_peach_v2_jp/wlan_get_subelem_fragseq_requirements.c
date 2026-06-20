__int64 __fastcall wlan_get_subelem_fragseq_requirements(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int64 a10,
        _BYTE *a11,
        _QWORD *a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 result; // x0
  unsigned __int64 v15; // x8

  if ( a11 )
  {
    if ( a10 <= 0xFF )
    {
      *a11 = 0;
      return 0;
    }
    else
    {
      result = 0;
      *a11 = 1;
      if ( a12 )
      {
        v15 = ((2 * (a10 / 0xFF) + 0x1FFFFFFFELL) & 0x1FFFFFFFELL) + 2;
        if ( !(a10 % 0xFF) )
          v15 = (2 * (a10 / 0xFF) + 0x1FFFFFFFELL) & 0x1FFFFFFFELL;
        *a12 = a10 + v15 + 2;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "Pointer to indication of whether fragmentation is required or not is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      v12,
      v13);
    return 29;
  }
  return result;
}
