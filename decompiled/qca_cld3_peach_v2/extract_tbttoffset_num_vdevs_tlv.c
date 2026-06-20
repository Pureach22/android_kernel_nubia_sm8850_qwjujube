__int64 __fastcall extract_tbttoffset_num_vdevs_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  unsigned int v13; // w9
  int v14; // w8
  bool v15; // cc

  if ( a10 )
  {
    v13 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
    if ( v13 )
    {
      v14 = 0;
      do
      {
        v15 = v13 > 1;
        v14 += v13 & 1;
        v13 >>= 1;
      }
      while ( v15 );
    }
    else
    {
      v14 = 0;
    }
    *a11 = v14;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid tbtt update ext event buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_tbttoffset_num_vdevs_tlv",
      v11,
      v12);
    return 4;
  }
}
