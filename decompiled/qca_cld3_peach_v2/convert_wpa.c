__int64 __fastcall convert_wpa(__int64 a1, _BYTE *a2, __int64 a3)
{
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int8 v15; // w8
  __int64 result; // x0
  int v17; // [xsp+0h] [xbp-110h] BYREF
  _BYTE s[257]; // [xsp+7h] [xbp-109h] BYREF
  __int64 v19; // [xsp+108h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v17 = 0;
  v6 = dot11f_pack_ie_wpa(a1, a3, s, 0x101u, &v17);
  if ( (v6 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to re-pack the WPA IE (0x%0x8)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "convert_wpa",
      v6);
    result = 16;
  }
  else
  {
    v15 = v17 - 2;
    *a2 = v17 - 2;
    qdf_mem_copy(a2 + 1, &s[2], v15);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
