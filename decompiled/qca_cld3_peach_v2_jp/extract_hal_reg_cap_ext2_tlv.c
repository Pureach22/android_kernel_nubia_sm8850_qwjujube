__int64 __fastcall extract_hal_reg_cap_ext2_tlv(
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
        __int64 a12)
{
  unsigned int v12; // w8
  _DWORD *v13; // x20
  unsigned int v15; // w19

  if ( !a10 )
  {
    qdf_trace_msg(0x31u, 2u, "%s: null evt_buf", a1, a2, a3, a4, a5, a6, a7, a8, "extract_hal_reg_cap_ext2_tlv");
    return 4;
  }
  v12 = *(_DWORD *)(a10 + 72);
  if ( v12 )
  {
    if ( v12 > a11 )
    {
      v13 = (_DWORD *)(*(_QWORD *)(a10 + 64) + 28LL * a11);
      *(_DWORD *)a12 = v13[1];
      v15 = v13[2];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Target wireless mode: 0x%x",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "convert_wireless_modes_ext_tlv",
        v15);
      *(_QWORD *)(a12 + 8) = v15 << 23;
      *(_DWORD *)(a12 + 16) = v13[3];
      *(_DWORD *)(a12 + 20) = v13[4];
      *(_DWORD *)(a12 + 24) = v13[5];
      *(_DWORD *)(a12 + 28) = v13[6];
      return 0;
    }
    return 4;
  }
  return 0;
}
