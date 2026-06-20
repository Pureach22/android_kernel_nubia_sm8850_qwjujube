__int64 __fastcall hdd_get_nss(__int64 a1, char *a2)
{
  __int64 v3; // x20
  __int64 v4; // x0
  char v5; // w8
  __int64 result; // x0
  unsigned int vht_mimo_cap; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19
  char v17; // w8
  char v18[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v19[4]; // [xsp+10h] [xbp-10h] BYREF
  char v20[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  v20[0] = 0;
  if ( *(_BYTE *)(v3 + 3752) == 1 )
  {
    v4 = *(unsigned int *)(a1 + 40);
    v19[0] = 0;
    v18[0] = 0;
    sme_get_vdev_type_nss(v4, v19, v18);
    v5 = v19[0];
    result = 0;
  }
  else
  {
    vht_mimo_cap = wlan_mlme_get_vht_mimo_cap(*(_QWORD *)v3, v20);
    if ( vht_mimo_cap )
    {
      v16 = vht_mimo_cap;
      qdf_trace_msg(0x33u, 2u, "%s: unable to get vht_enable2x2", v8, v9, v10, v11, v12, v13, v14, v15, "hdd_get_nss");
      result = v16;
      goto LABEL_13;
    }
    if ( v20[0] )
      v17 = 2;
    else
      v17 = 1;
    *a2 = v17;
    if ( policy_mgr_is_hw_dbs_2x2_capable(*(_QWORD *)v3) || (policy_mgr_is_current_hwmode_dbs(*(_QWORD *)v3) & 1) == 0 )
    {
      result = 0;
      goto LABEL_13;
    }
    result = 0;
    v5 = *a2 - 1;
  }
  *a2 = v5;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
