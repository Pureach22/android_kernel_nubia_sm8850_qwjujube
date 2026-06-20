__int64 __fastcall wlan_hdd_set_vlan_config(__int64 a1, unsigned __int8 *a2)
{
  __int64 sta_info_by_mac; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int16 v13; // w8
  __int64 v14; // x21
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x22
  __int64 v18; // x1
  unsigned __int8 *v19; // x24
  __int64 v20; // x9
  _DWORD *v21; // x9
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  char v26; // w25
  __int64 v27; // x8
  void (__fastcall *v28)(__int64, __int64, unsigned __int8 *, __int64, char *); // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  __int64 v38; // [xsp+0h] [xbp-40h] BYREF
  char v39; // [xsp+8h] [xbp-38h] BYREF
  __int64 v40; // [xsp+9h] [xbp-37h]
  _BYTE v41[15]; // [xsp+11h] [xbp-2Fh]
  __int64 v42; // [xsp+20h] [xbp-20h]
  _QWORD v43[3]; // [xsp+28h] [xbp-18h] BYREF

  v43[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  sta_info_by_mac = hdd_get_sta_info_by_mac(a1 + 38848, a2, 22, 3);
  v38 = sta_info_by_mac;
  if ( !sta_info_by_mac )
  {
    if ( a2 )
    {
      v22 = *a2;
      v23 = a2[1];
      v24 = a2[2];
      v25 = a2[5];
    }
    else
    {
      v24 = 0;
      v22 = 0;
      v23 = 0;
      v25 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to find right station MAC:%02x:%02x:%02x:**:**:%02x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_hdd_set_vlan_config",
      v22,
      v23,
      v24,
      v25,
      v38);
    goto LABEL_31;
  }
  v13 = *(_WORD *)(sta_info_by_mac + 496);
  if ( !v13 )
  {
LABEL_27:
    hdd_put_sta_info_ref(a1 + 38848, &v38, 1, 22);
LABEL_31:
    result = 4;
    goto LABEL_32;
  }
  v14 = *(_QWORD *)(*(_QWORD *)(a1 + 52824) + 32LL);
  v15 = *(_QWORD *)(v14 + 152);
  if ( !v15 || (v16 = *(_QWORD *)(v15 + 80)) == 0 )
  {
    v17 = 0;
    v19 = (unsigned __int8 *)(v14 + 104);
    goto LABEL_16;
  }
  v17 = *(_QWORD *)(v16 + 2808);
  v19 = (unsigned __int8 *)(v14 + 104);
  v18 = *(unsigned __int8 *)(v14 + 104);
  if ( !v17 )
  {
LABEL_16:
    v26 = 1;
    goto LABEL_17;
  }
  if ( *(_QWORD *)v17 )
  {
    v20 = *(_QWORD *)(*(_QWORD *)v17 + 8LL);
    if ( v20 )
    {
      v21 = *(_DWORD **)(v20 + 176);
      if ( v21 )
      {
        if ( *(v21 - 1) != -2105220659 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))v21)(v17, v18, a2, (unsigned __int8)v13);
        v18 = *v19;
      }
    }
    v42 = 0;
    memset(v43, 0, 15);
    goto LABEL_18;
  }
  v26 = 0;
LABEL_17:
  qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_peer_set_vlan_id", v38);
  v18 = *v19;
  v42 = 0;
  memset(v43, 0, 15);
  if ( (v26 & 1) != 0 )
  {
LABEL_24:
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_txrx_set_peer_param", v38);
    goto LABEL_25;
  }
LABEL_18:
  if ( !*(_QWORD *)v17 )
    goto LABEL_24;
  v27 = *(_QWORD *)(*(_QWORD *)v17 + 8LL);
  if ( v27 )
  {
    v28 = *(void (__fastcall **)(__int64, __int64, unsigned __int8 *, __int64, char *))(v27 + 112);
    if ( v28 )
    {
      v39 = 1;
      v40 = v42;
      *(_QWORD *)v41 = v43[0];
      *(_QWORD *)&v41[7] = *(_QWORD *)((char *)v43 + 7);
      if ( *((_DWORD *)v28 - 1) != 201075190 )
        __break(0x8228u);
      v28(v17, v18, a2, 2, &v39);
    }
  }
LABEL_25:
  if ( (unsigned int)wlan_mlme_peer_config_vlan(v14, a2, v5, v6, v7, v8, v9, v10, v11, v12) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to send peer vlan config",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_hdd_set_vlan_config");
    goto LABEL_27;
  }
  hdd_put_sta_info_ref(a1 + 38848, &v38, 1, 22);
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
