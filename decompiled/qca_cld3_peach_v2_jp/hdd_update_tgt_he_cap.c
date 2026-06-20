__int64 __fastcall hdd_update_tgt_he_cap(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x0
  __int64 result; // x0
  _BYTE v15[4]; // [xsp+4h] [xbp-4Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-48h] BYREF
  __int128 v17; // [xsp+10h] [xbp-40h]
  __int64 v18; // [xsp+20h] [xbp-30h]
  __int64 v19; // [xsp+28h] [xbp-28h]
  __int64 v20; // [xsp+30h] [xbp-20h]
  __int64 v21; // [xsp+38h] [xbp-18h]
  int v22; // [xsp+40h] [xbp-10h]
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)a1;
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v17 = 0u;
  v16 = 0;
  v15[0] = 0;
  if ( (unsigned int)wlan_mlme_cfg_get_vht_tx_bfee_ant_supp(v4, v15) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to get tx_bfee_ant_supp",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_update_tgt_he_cap");
  v13 = *(_QWORD **)(a1 + 16);
  *(_QWORD *)((char *)&v17 + 1) = ((unsigned __int64)(v15[0] & 7) << 24) | ((unsigned __int64)(v15[0] & 7) << 19);
  sme_update_tgt_he_cap(v13, a2, (__int64)&v16);
  result = mlme_update_tgt_he_caps_in_cfg(*(_QWORD *)a1, a2, *(_DWORD *)(a1 + 1248));
  _ReadStatusReg(SP_EL0);
  return result;
}
