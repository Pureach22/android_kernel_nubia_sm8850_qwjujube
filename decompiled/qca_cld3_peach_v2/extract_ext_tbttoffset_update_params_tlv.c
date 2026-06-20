__int64 __fastcall extract_ext_tbttoffset_update_params_tlv(
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
  __int64 v12; // x29
  __int64 v13; // x30
  _DWORD *v14; // x8

  if ( a10 )
  {
    v14 = (_DWORD *)(*(_QWORD *)(a10 + 16) + 20LL * a11);
    *a12 = v14[1];
    a12[1] = v14[2];
    a12[2] = v14[3];
    a12[3] = v14[4];
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid tbtt update event buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_ext_tbttoffset_update_params_tlv",
      v12,
      v13);
    return 4;
  }
}
