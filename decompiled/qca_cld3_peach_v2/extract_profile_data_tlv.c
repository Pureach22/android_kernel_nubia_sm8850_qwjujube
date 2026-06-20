__int64 __fastcall extract_profile_data_tlv(
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
        unsigned __int8 a11,
        _DWORD *a12)
{
  _DWORD *v12; // x8

  if ( a10 )
  {
    v12 = (_DWORD *)(*(_QWORD *)(a10 + 16) + 40LL * a11);
    *a12 = v12[1];
    a12[1] = v12[2];
    a12[2] = v12[3];
    a12[3] = v12[4];
    a12[4] = v12[5];
    a12[5] = v12[6];
    qdf_mem_copy(a12 + 6, v12 + 7, 0xCu);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid profile data event buf",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_profile_data_tlv");
    return 4;
  }
}
