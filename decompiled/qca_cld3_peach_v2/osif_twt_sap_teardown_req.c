__int64 __fastcall osif_twt_sap_teardown_req(__int64 a1, _WORD *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  int v13; // w9
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x5
  __int64 v24; // x20
  __int64 v26; // x6
  __int64 v27; // x7
  int v28; // w8
  int v29; // w9
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  __int64 v39; // [xsp+0h] [xbp-130h] BYREF
  __int64 v40; // [xsp+8h] [xbp-128h]
  unsigned int v41; // [xsp+10h] [xbp-120h]
  __int64 v42; // [xsp+14h] [xbp-11Ch] BYREF
  unsigned int v43; // [xsp+1Ch] [xbp-114h]
  _QWORD s[34]; // [xsp+20h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x108u);
  v12 = *(_QWORD *)(a1 + 216);
  v43 = 0;
  v42 = 0;
  if ( !v12 || !*(_QWORD *)(v12 + 80) )
  {
    qdf_trace_msg(0x48u, 2u, "%s: NULL psoc", v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_sap_teardown_req");
    goto LABEL_6;
  }
  v13 = (__int16)a2[1];
  v41 = *(unsigned __int8 *)(a1 + 168);
  if ( (v13 & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  result = _nla_parse(s, 32, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_add_dialog_policy, 31, 0);
  if ( (_DWORD)result )
    goto LABEL_7;
  if ( !s[5] )
  {
    if ( !s[15] )
    {
      v23 = 255;
      v43 = 255;
      LODWORD(v42) = -1;
      WORD2(v42) = -1;
      goto LABEL_22;
    }
LABEL_15:
    v24 = jiffies;
    if ( osif_twt_sap_teardown_req___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: get_params dialog_id or mac_addr is missing",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "osif_twt_sap_teardown_req");
      osif_twt_sap_teardown_req___last_ticks = v24;
    }
    goto LABEL_6;
  }
  if ( !s[15] )
    goto LABEL_15;
  v43 = *(unsigned __int8 *)(s[5] + 4LL);
  nla_memcpy(&v42, s[15], 6);
  v23 = v43;
  if ( v43 != 255 )
  {
    if ( v43 )
    {
      if ( (_DWORD)v42 == -1 && SWORD2(v42) == -1 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Bcast MAC valid with dlg_id:%d but here dlg_id is:%d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "osif_twt_sap_teardown_req",
          255);
        goto LABEL_6;
      }
    }
    else
    {
      v23 = 255;
      v43 = 255;
    }
  }
LABEL_22:
  if ( &v39 == (__int64 *)-20LL )
    v26 = 0;
  else
    v26 = (unsigned __int8)v42;
  if ( &v42 )
    v27 = BYTE1(v42);
  else
    v27 = 0;
  if ( &v42 )
    v28 = BYTE2(v42);
  else
    v28 = 0;
  if ( &v42 )
    v29 = BYTE5(v42);
  else
    v29 = 0;
  LODWORD(v40) = v29;
  LODWORD(v39) = v28;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: vdev_id %d dialog_id %d peer mac_addr %02x:%02x:%02x:**:**:%02x",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "osif_twt_sap_teardown_req",
    v41,
    v23,
    v26,
    v27,
    v39,
    v40);
  result = ucfg_twt_teardown_req();
  if ( (_DWORD)result )
  {
    v38 = result;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to send del dialog command",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "osif_twt_sap_teardown_req");
    result = qdf_status_to_os_return(v38);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
