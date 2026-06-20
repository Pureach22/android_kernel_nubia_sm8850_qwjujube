__int64 __fastcall vdev_mgr_up_send(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  char v11; // w9
  __int16 v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w9
  int v22; // w20
  unsigned int v23; // w8
  __int64 result; // x0
  const char *v25; // x2
  __int64 entry_by_bssid; // x0
  __int64 v27; // x21
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // [xsp+30h] [xbp-D0h] BYREF
  __int64 v31; // [xsp+38h] [xbp-C8h]
  __int64 v32; // [xsp+40h] [xbp-C0h] BYREF
  __int64 v33; // [xsp+48h] [xbp-B8h] BYREF
  int v34; // [xsp+50h] [xbp-B0h]
  int v35; // [xsp+58h] [xbp-A8h] BYREF
  __int16 v36; // [xsp+5Ch] [xbp-A4h]
  int v37; // [xsp+60h] [xbp-A0h] BYREF
  __int16 v38; // [xsp+64h] [xbp-9Ch]
  _QWORD v39[19]; // [xsp+68h] [xbp-98h] BYREF

  v39[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v32 = 0;
  v33 = 0;
  LODWORD(v31) = 0;
  v30 = 0;
  memset(v39, 0, 144);
  if ( !a1 )
  {
    v25 = "%s: VDEV_MLME is NULL";
LABEL_13:
    qdf_trace_msg(0x68u, 2u, v25, a2, a3, a4, a5, a6, a7, a8, a9, "vdev_mgr_up_send");
    result = 4;
    goto LABEL_14;
  }
  v9 = *(_QWORD *)(a1 + 520);
  if ( !v9 )
  {
    v25 = "%s: VDEV is NULL";
    goto LABEL_13;
  }
  v11 = *(_BYTE *)(v9 + 168);
  v36 = -1;
  v35 = -1;
  v12 = *(_WORD *)(a1 + 42);
  v38 = 0;
  v37 = 0;
  LOBYTE(v32) = v11;
  WORD1(v32) = v12;
  wlan_vdev_mgr_get_param_bssid(v9, &v37);
  if ( *(_DWORD *)(v9 + 16) )
    goto LABEL_4;
  if ( !*(_DWORD *)(a1 + 460) )
  {
    entry_by_bssid = wlan_scan_get_entry_by_bssid(*(_QWORD *)(v9 + 216), &v37);
    if ( entry_by_bssid )
    {
      v27 = entry_by_bssid;
      mlme_set_mbssid_info(v9, entry_by_bssid + 112, **(unsigned __int16 **)(v9 + 32));
      if ( (*(_BYTE *)(v27 + 50) & 1) != 0 )
        qdf_mem_copy((void *)(a1 + 481), &v35, 6u);
      v28 = *(_QWORD *)(v27 + 1320);
      if ( v28 )
        _qdf_mem_free(v28);
      v29 = *(_QWORD *)(v27 + 1896);
      if ( v29 )
        _qdf_mem_free(v29);
      _qdf_mem_free(v27);
    }
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: trans BSSID %02x:%02x:%02x:**:**:%02x non-trans BSSID %02x:%02x:%02x:**:**:%02x profile_idx %d, profile_num %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "vdev_mgr_up_param_update",
    *(unsigned __int8 *)(a1 + 481),
    *(unsigned __int8 *)(a1 + 482),
    *(unsigned __int8 *)(a1 + 483),
    *(unsigned __int8 *)(a1 + 486),
    *(unsigned __int8 *)(a1 + 487),
    *(unsigned __int8 *)(a1 + 488),
    *(unsigned __int8 *)(a1 + 489),
    *(unsigned __int8 *)(a1 + 492),
    *(_DWORD *)(a1 + 456),
    *(_DWORD *)(a1 + 460),
    v30,
    v31);
  if ( !(unsigned int)qdf_mem_cmp(&v35, (const void *)(a1 + 481), 6u)
    || !(unsigned int)qdf_mem_cmp(&v37, (const void *)(a1 + 481), 6u)
    || !(unsigned int)qdf_mem_cmp(&v37, (const void *)(a1 + 487), 6u) )
  {
LABEL_4:
    v21 = *(_DWORD *)(a1 + 460);
    HIDWORD(v32) = *(_DWORD *)(a1 + 456);
    LODWORD(v33) = v21;
    qdf_mem_copy((char *)&v33 + 4, (const void *)(a1 + 481), 6u);
  }
  v22 = *(_DWORD *)(v9 + 16);
  if ( !v22 )
  {
    v23 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 520) + 168LL);
    LODWORD(v31) = *(unsigned __int16 *)(a1 + 44);
    v30 = v23 | 0xC00000000LL;
    tgt_vdev_mgr_sta_ps_param_send(a1, &v30);
  }
  result = tgt_vdev_mgr_beacon_tmpl_send(a1, v39);
  if ( !(_DWORD)result )
  {
    result = tgt_vdev_mgr_up_send(a1, &v32);
    if ( !(_DWORD)result )
    {
      *(_DWORD *)(a1 + 256) = 0;
      *(_QWORD *)(a1 + 264) = 0;
      if ( v22 == 1 )
        result = vdev_mgr_configure_fd_for_sap(a1);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
