__int64 __fastcall osif_twt_sta_teardown_req(__int64 a1, _WORD *a2)
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
  __int64 v13; // x20
  unsigned int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x20
  __int64 result; // x0
  __int64 v41; // x21
  __int64 v42; // [xsp+0h] [xbp-120h] BYREF
  __int64 v43; // [xsp+8h] [xbp-118h]
  _BYTE s[264]; // [xsp+10h] [xbp-110h] BYREF
  __int64 v45; // [xsp+118h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v12 = *(_QWORD *)(a1 + 216);
  v42 = 0;
  v43 = 0;
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    qdf_trace_msg(0x48u, 2u, "%s: NULL psoc", v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_sta_teardown_req", v42, v43);
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v14 = *(unsigned __int8 *)(a1 + 168);
  if ( wlan_cm_is_vdev_connected(a1, v4, v5, v6, v7, v8, v9, v10, v11) )
  {
    if ( (wlan_cm_host_roam_in_progress(v13, v14) & 1) != 0 )
    {
LABEL_7:
      result = 4294967280LL;
      goto LABEL_10;
    }
    if ( (unsigned int)wlan_get_vdev_status(a1, v23, v24, v25, v26, v27, v28, v29, v30) )
    {
      v39 = jiffies;
      if ( osif_twt_sta_teardown_req___last_ticks_23 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Scan in progress",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "osif_twt_sta_teardown_req",
          v42,
          v43);
        osif_twt_sta_teardown_req___last_ticks_23 = v39;
        result = 4294967280LL;
        goto LABEL_10;
      }
      goto LABEL_7;
    }
    if ( ((__int16)a2[1] & 0x80000000) == 0 )
    {
      do_trace_netlink_extack("NLA_F_NESTED is missing");
      goto LABEL_9;
    }
    result = _nla_parse(s, 32, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_add_dialog_policy, 31, 0);
    if ( !(_DWORD)result )
    {
      result = osif_fill_peer_macaddr(a1, (char *)&v42 + 4);
      if ( !(_DWORD)result )
      {
        LODWORD(v42) = v14;
        wlan_get_pdev_id_from_vdev_id(v13, v14, 0x5Eu);
        osif_twt_parse_del_dialog_attrs(s, &v42);
        result = osif_send_sta_twt_teardown_req(v13, (__int64)&v42);
      }
    }
  }
  else
  {
    v41 = jiffies;
    if ( osif_twt_sta_teardown_req___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Not associated!, vdev %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "osif_twt_sta_teardown_req",
        v14,
        v42,
        v43);
      result = 0;
      osif_twt_sta_teardown_req___last_ticks = v41;
    }
    else
    {
      result = 0;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
