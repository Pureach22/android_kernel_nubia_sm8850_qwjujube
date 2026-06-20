__int64 __fastcall extract_ext_tbttoffset_num_vdevs_tlv(
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

  if ( a10 )
  {
    *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
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
      "extract_ext_tbttoffset_num_vdevs_tlv",
      v11,
      v12);
    return 4;
  }
}
