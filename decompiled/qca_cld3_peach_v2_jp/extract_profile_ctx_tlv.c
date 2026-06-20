__int64 __fastcall extract_profile_ctx_tlv(
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
  _DWORD *v13; // x8

  if ( a10 )
  {
    v13 = *(_DWORD **)a10;
    *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
    a11[1] = v13[2];
    a11[2] = v13[3];
    a11[3] = v13[4];
    a11[4] = v13[5];
    a11[5] = v13[6];
    a11[6] = v13[7];
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
      "extract_profile_ctx_tlv",
      v11,
      v12);
    return 4;
  }
}
