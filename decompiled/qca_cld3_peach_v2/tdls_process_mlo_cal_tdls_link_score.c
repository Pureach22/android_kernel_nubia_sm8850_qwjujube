__int64 __fastcall tdls_process_mlo_cal_tdls_link_score(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x0
  __int64 comp_private_obj; // x0
  __int64 v4; // x8
  __int64 v5; // x20
  unsigned int v6; // w0
  int v7; // w8
  unsigned int v8; // w19
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x20
  unsigned int v13; // w0
  int v14; // w8

  v1 = *(_QWORD *)(a1 + 1360);
  v2 = *(_QWORD *)(v1 + 24);
  if ( v2
    && (comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v2, 0xAu),
        v4 = *(_QWORD *)(comp_private_obj + 952),
        *(_DWORD *)(comp_private_obj + 960) = 0,
        v4) )
  {
    v5 = comp_private_obj;
    v6 = wlan_reg_freq_to_band(*(_DWORD *)(v4 + 4));
    if ( v6 > 2 )
      v7 = 40;
    else
      v7 = dword_B2DEF8[v6];
    v8 = 0;
    *(_DWORD *)(v5 + 960) = v7;
    v9 = *(_QWORD *)(v1 + 32);
    if ( !v9 )
      return v8;
  }
  else
  {
    v8 = 16;
    v9 = *(_QWORD *)(v1 + 32);
    if ( !v9 )
      return v8;
  }
  v10 = wlan_objmgr_vdev_get_comp_private_obj(v9, 0xAu);
  v11 = *(_QWORD *)(v10 + 952);
  *(_DWORD *)(v10 + 960) = 0;
  if ( v11 )
  {
    v12 = v10;
    v13 = wlan_reg_freq_to_band(*(_DWORD *)(v11 + 4));
    if ( v13 > 2 )
      v14 = 40;
    else
      v14 = dword_B2DEF8[v13];
    v8 = 0;
    *(_DWORD *)(v12 + 960) = v14;
  }
  return v8;
}
