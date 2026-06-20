__int64 __fastcall extract_roam_initial_info_tlv(
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
        __int64 a11,
        unsigned __int8 a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x8
  _DWORD *v16; // x8

  if ( a10 && (v14 = *(_QWORD *)(a10 + 144)) != 0 && *(_DWORD *)(a10 + 152) > (unsigned int)a12 )
  {
    v16 = (_DWORD *)(v14 + 20LL * a12);
    *(_BYTE *)a11 = 1;
    *(_DWORD *)(a11 + 4) = v16[1];
    *(_DWORD *)(a11 + 8) = v16[2];
    *(_DWORD *)(a11 + 12) = v16[3];
    *(_DWORD *)(a11 + 16) = v16[4];
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Empty roam_initial_info param buf",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_initial_info_tlv",
      v12,
      v13);
    return 0;
  }
}
