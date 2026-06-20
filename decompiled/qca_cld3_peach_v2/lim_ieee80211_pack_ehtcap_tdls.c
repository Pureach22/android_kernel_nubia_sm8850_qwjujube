_BYTE *__fastcall lim_ieee80211_pack_ehtcap_tdls(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _BYTE *v15; // x20
  bool is_24ghz_ch_freq; // w0
  __int64 v17; // x9
  int v18; // w8
  bool v19; // w22
  __int64 v20; // x9
  __int64 v21; // x10
  int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x10
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _BYTE *result; // x0
  char v40; // w8
  _QWORD v41[7]; // [xsp+8h] [xbp-E8h] BYREF
  int v42; // [xsp+40h] [xbp-B0h]
  _QWORD v43[11]; // [xsp+48h] [xbp-A8h] BYREF
  int v44; // [xsp+A0h] [xbp-50h]
  __int64 v45; // [xsp+A8h] [xbp-48h] BYREF
  __int64 v46; // [xsp+B0h] [xbp-40h]
  __int64 v47; // [xsp+B8h] [xbp-38h]
  __int64 v48; // [xsp+C0h] [xbp-30h]
  __int64 v49; // [xsp+C8h] [xbp-28h]
  __int64 v50; // [xsp+D0h] [xbp-20h]
  __int64 v51; // [xsp+D8h] [xbp-18h]
  int v52; // [xsp+E0h] [xbp-10h]
  __int64 v53; // [xsp+E8h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v52 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v45 = 0;
    v6 = _qdf_mem_malloc(0x101u, "lim_ieee80211_pack_ehtcap_tdls", 1587);
    if ( v6 )
    {
      v15 = (_BYTE *)v6;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284));
      v17 = *(_QWORD *)(a1 + 8);
      v18 = a1;
      v19 = is_24ghz_ch_freq;
      populate_dot11f_set_tdls_he_cap(v18, *(_DWORD *)(v17 + 5964), (int)&v45);
      v20 = *(_QWORD *)(a2 + 10144);
      v21 = *(_QWORD *)(a2 + 10152);
      v43[8] = *(_QWORD *)(a2 + 10136);
      v43[9] = v20;
      v22 = *(_DWORD *)(a2 + 10160);
      v23 = *(_QWORD *)(a2 + 10104);
      v43[10] = v21;
      v24 = *(_QWORD *)(a2 + 10120);
      v44 = v22;
      v25 = *(_QWORD *)(a2 + 10112);
      v43[4] = v23;
      v43[5] = v25;
      v26 = *(_QWORD *)(a2 + 10128);
      v27 = *(_QWORD *)(a2 + 10072);
      v43[6] = v24;
      v43[7] = v26;
      v28 = *(_QWORD *)(a2 + 10080);
      v29 = *(_QWORD *)(a2 + 10088);
      v43[0] = v27;
      v43[1] = v28;
      v30 = *(_QWORD *)(a2 + 10096);
      v43[2] = v29;
      v43[3] = v30;
      v41[4] = v49;
      v41[5] = v50;
      v41[6] = v51;
      v42 = v52;
      v41[0] = v45;
      v41[1] = v46;
      v41[2] = v47;
      v41[3] = v48;
      lim_ieee80211_pack_ehtcap(v15, v43, (__int64)v41, v19, 1, v31, v32, v33, v34, v35, v36, v37, v38);
      result = v15;
      v40 = v15[1] + 2;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: malloc failed for eht_cap_ie",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "lim_ieee80211_pack_ehtcap_tdls");
      v40 = 0;
      result = nullptr;
    }
    *a3 = v40;
  }
  else
  {
    result = nullptr;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
