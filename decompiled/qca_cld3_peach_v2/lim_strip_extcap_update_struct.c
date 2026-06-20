__int64 __fastcall lim_strip_extcap_update_struct(__int64 a1, unsigned __int8 *a2, unsigned __int16 *a3, __int64 a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD v26[2]; // [xsp+0h] [xbp-20h] BYREF
  char v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v26[0] = 0;
  v26[1] = 0;
  qdf_mem_set(v26, 0x11u, 0);
  v16 = wlan_strip_ie(a2, a3, 0x7Fu, 1, nullptr, 0, (char *)v26, 15, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( v16 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Failed to strip extcap IE status: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_strip_extcap_update_struct",
      v16);
  else
    lim_update_extcap_struct(a1, v26, a4, v17, v18, v19, v20, v21, v22, v23, v24);
  _ReadStatusReg(SP_EL0);
  return v16;
}
