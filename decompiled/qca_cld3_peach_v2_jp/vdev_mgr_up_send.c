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
  _QWORD v30[7]; // [xsp+38h] [xbp-78h] BYREF
  __int64 v31; // [xsp+70h] [xbp-40h] BYREF
  int v32; // [xsp+78h] [xbp-38h]
  __int64 v33; // [xsp+80h] [xbp-30h] BYREF
  __int64 v34; // [xsp+88h] [xbp-28h] BYREF
  int v35; // [xsp+90h] [xbp-20h]
  int v36; // [xsp+98h] [xbp-18h] BYREF
  __int16 v37; // [xsp+9Ch] [xbp-14h]
  int v38; // [xsp+A0h] [xbp-10h] BYREF
  __int16 v39; // [xsp+A4h] [xbp-Ch]
  __int64 v40; // [xsp+A8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v33 = 0;
  v34 = 0;
  v32 = 0;
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  if ( !a1 )
  {
    v25 = "%s: VDEV_MLME is NULL";
LABEL_13:
    qdf_trace_msg(0x68u, 2u, v25, a2, a3, a4, a5, a6, a7, a8, a9, "vdev_mgr_up_send");
    result = 4;
    goto LABEL_14;
  }
  v9 = *(_QWORD *)(a1 + 504);
  if ( !v9 )
  {
    v25 = "%s: VDEV is NULL";
    goto LABEL_13;
  }
  v11 = *(_BYTE *)(v9 + 104);
  v37 = -1;
  v36 = -1;
  v12 = *(_WORD *)(a1 + 42);
  v39 = 0;
  v38 = 0;
  LOBYTE(v33) = v11;
  WORD1(v33) = v12;
  wlan_vdev_mgr_get_param_bssid(v9, &v38);
  if ( *(_DWORD *)(v9 + 16) )
    goto LABEL_4;
  if ( !*(_DWORD *)(a1 + 444) )
  {
    entry_by_bssid = wlan_scan_get_entry_by_bssid(*(_QWORD *)(v9 + 152), &v38);
    if ( entry_by_bssid )
    {
      v27 = entry_by_bssid;
      mlme_set_mbssid_info(v9, entry_by_bssid + 112, **(unsigned __int16 **)(v9 + 32));
      if ( (*(_BYTE *)(v27 + 50) & 1) != 0 )
        qdf_mem_copy((void *)(a1 + 465), &v36, 6u);
      v28 = *(_QWORD *)(v27 + 1192);
      if ( v28 )
        _qdf_mem_free(v28);
      v29 = *(_QWORD *)(v27 + 1712);
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
    *(unsigned __int8 *)(a1 + 465),
    *(unsigned __int8 *)(a1 + 466),
    *(unsigned __int8 *)(a1 + 467),
    *(unsigned __int8 *)(a1 + 470),
    *(unsigned __int8 *)(a1 + 471),
    *(unsigned __int8 *)(a1 + 472),
    *(unsigned __int8 *)(a1 + 473),
    *(unsigned __int8 *)(a1 + 476),
    *(_DWORD *)(a1 + 440),
    *(_DWORD *)(a1 + 444));
  if ( !(unsigned int)qdf_mem_cmp(&v36, (const void *)(a1 + 465), 6u)
    || !(unsigned int)qdf_mem_cmp(&v38, (const void *)(a1 + 465), 6u)
    || !(unsigned int)qdf_mem_cmp(&v38, (const void *)(a1 + 471), 6u) )
  {
LABEL_4:
    v21 = *(_DWORD *)(a1 + 444);
    HIDWORD(v33) = *(_DWORD *)(a1 + 440);
    LODWORD(v34) = v21;
    qdf_mem_copy((char *)&v34 + 4, (const void *)(a1 + 465), 6u);
  }
  v22 = *(_DWORD *)(v9 + 16);
  if ( !v22 )
  {
    v23 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL);
    v32 = *(unsigned __int16 *)(a1 + 44);
    v31 = v23 | 0xC00000000LL;
    tgt_vdev_mgr_sta_ps_param_send(a1, &v31);
  }
  result = tgt_vdev_mgr_beacon_tmpl_send(a1, v30);
  if ( !(_DWORD)result )
  {
    result = tgt_vdev_mgr_up_send(a1, &v33);
    if ( !(_DWORD)result )
    {
      *(_DWORD *)(a1 + 240) = 0;
      *(_QWORD *)(a1 + 248) = 0;
      if ( v22 == 1 )
        result = vdev_mgr_configure_fd_for_sap(a1);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
