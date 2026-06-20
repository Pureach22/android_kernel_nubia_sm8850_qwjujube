__int64 __fastcall hdd_update_cds_config_ftm(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  char v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v23[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v22 = 0;
  v2 = _qdf_mem_malloc(0x94u, "hdd_update_cds_config_ftm", 65);
  if ( v2 )
  {
    v3 = v2;
    if ( (unsigned int)wlan_mlme_get_self_recovery(*a1, v23) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get self recovery ini config",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "hdd_update_cds_config_ftm");
      result = 4294967291LL;
    }
    else
    {
      *(_DWORD *)(v3 + 8) = 1;
      hdd_lpass_populate_cds_config(v3, a1);
      v13 = v23[0];
      *(_DWORD *)(v3 + 32) = 0;
      *(_BYTE *)(v3 + 37) = v13;
      *(_DWORD *)(v3 + 124) = *(unsigned __int8 *)(a1[13] + 64);
      wlan_mlme_get_sap_max_peers(*a1, &v22);
      *(_WORD *)v3 = v22;
      cds_init_ini_config(v3, v14, v15, v16, v17, v18, v19, v20, v21);
      result = 0;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
