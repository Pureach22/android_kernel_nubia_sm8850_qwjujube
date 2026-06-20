__int64 __fastcall wlan_reg_get_freq_range(__int64 a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _DWORD *v18; // x8
  __int64 result; // x0

  comp_private_obj = (_DWORD *)wlan_objmgr_pdev_get_comp_private_obj(a1, 0xDu);
  if ( comp_private_obj )
  {
    v18 = comp_private_obj + 13312;
    if ( a2 )
      *a2 = comp_private_obj[14184];
    if ( a3 )
      *a3 = comp_private_obj[14185];
    if ( a4 )
      *a4 = comp_private_obj[14186];
    result = 0;
    if ( a5 )
      *a5 = v18[875];
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_reg_get_freq_range");
    return 5;
  }
  return result;
}
