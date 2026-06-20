__int64 __fastcall osif_connect_handler(__int64 a1, unsigned __int8 *a2)
{
  const char *v4; // x24
  int v5; // w8
  _QWORD **v6; // x21
  const char *v7; // x5
  const char *v8; // x9
  unsigned int v9; // w8
  int v10; // w6
  int v11; // w7
  int v12; // w4
  int v13; // w8
  unsigned int v14; // w21
  __int64 v15; // x2
  __int64 v16; // x0
  __int64 v17; // x21
  unsigned int v18; // w0
  __int64 bss; // x1
  __int64 channel_khz; // x24
  _QWORD v22[6]; // [xsp+60h] [xbp-40h] BYREF
  __int16 v23; // [xsp+90h] [xbp-10h]
  __int64 v24; // [xsp+98h] [xbp-8h]

  v4 = "SUCCESS";
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_DWORD *)a2 + 13);
  v6 = *(_QWORD ***)(a1 + 680);
  v23 = 0;
  memset(v22, 0, sizeof(v22));
  if ( v5 )
  {
    v7 = (a2[1] & 0x20) != 0 ? ", Send disconnect" : (const char *)&unk_98C763;
    scnprintf(v22, 50, "reason %d status %d %s", *((_DWORD *)a2 + 14), *((_DWORD *)a2 + 15), v7);
    if ( *((_DWORD *)a2 + 13) )
      v4 = "FAILURE";
  }
  v8 = "Roam";
  if ( (a2[1] & 4) == 0 )
    v8 = "Connect";
  qdf_trace_msg(
    72,
    4,
    "%s(vdevid-%d): %02x:%02x:%02x:**:**:%02x %s with %02x:%02x:%02x:**:**:%02x \"%.*s\" is %s, freq %d cmid 0x%x %s",
    (const char *)((*v6)[4] + 296LL),
    *a2,
    *(unsigned __int8 *)(a1 + 74),
    *(unsigned __int8 *)(a1 + 75),
    *(unsigned __int8 *)(a1 + 76),
    *(unsigned __int8 *)(a1 + 79),
    v8,
    a2[8],
    a2[9],
    a2[10],
    a2[13],
    a2[14],
    (const char *)a2 + 15,
    v4,
    *((_DWORD *)a2 + 12),
    *((_DWORD *)a2 + 1),
    (const char *)v22);
  if ( *((_DWORD *)a2 + 13) )
  {
    if ( (ucfg_cm_is_link_switch_connect_resp(a2) & 1) == 0 )
    {
      v9 = *((_DWORD *)a2 + 14);
      if ( v9 <= 0xA && ((1 << v9) & 0x542) != 0 )
        osif_cm_unlink_bss(a1, a2 + 8);
    }
  }
  qdf_spinlock_acquire(v6 + 4);
  v11 = *((_DWORD *)v6 + 6);
  v10 = *((_DWORD *)v6 + 7);
  v12 = *((_DWORD *)a2 + 1);
  if ( v12 != v10 )
  {
    v13 = *((_DWORD *)a2 + 13);
LABEL_23:
    qdf_trace_msg(
      72,
      8,
      "%s: Ignore as cm_id(0x%x)/src(%d) != cm_id(0x%x)/src(%d) OR source is CFG connect with status %d",
      "osif_validate_connect_and_reset_src_id",
      v12,
      0,
      v10,
      v11,
      v13);
    qdf_spinlock_release(v6 + 4);
    v14 = 4;
    v15 = 2;
    goto LABEL_37;
  }
  if ( v11 == 11 )
  {
    v13 = *((_DWORD *)a2 + 13);
    if ( !v13 )
      goto LABEL_23;
  }
  osif_cm_reset_id_and_src_no_lock(v6);
  qdf_spinlock_release(v6 + 4);
  if ( (ucfg_cm_is_link_switch_connect_resp(a2) & 1) != 0 && (mlo_mgr_is_link_add_link_switch(a1) & 1) != 0 )
    ((void (__fastcall *)(__int64, unsigned __int8 *))osif_update_link_add_partner_links)(a1, a2);
  if ( (ucfg_cm_is_link_switch_connect_resp(a2) & 1) != 0 )
  {
    v14 = 0;
    v15 = 2;
  }
  else
  {
    v16 = osif_cm_connect_comp_ind(a1, a2, 1);
    if ( (a2[1] & 4) != 0 )
    {
      osif_indicate_reassoc_results(a1, v6, a2);
    }
    else if ( (a2[1] & 0x20) != 0 && *((_DWORD *)a2 + 13) )
    {
      v17 = (*v6)[4];
      v18 = qdf_mem_malloc_flags(v16);
      osif_cm_indicate_disconnect(a1, v17, 1, 0, 0, 0, 0xFFFFFFFFLL, v18);
    }
    else if ( (wlan_vdev_mlme_is_mlo_vdev(a1) & 1) != 0
           && (wlan_crypto_get_param(a1, 7), (*(_BYTE *)(a1 + 60) & 2) != 0) )
    {
      if ( (wlan_cm_is_link_add_connect_resp(a2) & 1) != 0 || (mlo_mgr_is_link_add_link_switch(a1) & 1) != 0 )
      {
        ((void (__fastcall *)(__int64, unsigned __int8 *))osif_update_link_add_partner_links)(a1, a2);
      }
      else if ( !*((_DWORD *)a2 + 13) && (wlan_cm_check_mlo_roam_auth_status(a1) & 1) != 0 )
      {
        mlo_mgr_osif_update_connect_info(a1, *(unsigned __int8 *)(a1 + 93));
      }
    }
    else
    {
      if ( *((_DWORD *)a2 + 13) )
      {
        bss = 0;
      }
      else
      {
        channel_khz = ieee80211_get_channel_khz(**v6, (unsigned int)(1000 * *((_DWORD *)a2 + 12)));
        bss = wlan_cfg80211_get_bss(**v6, channel_khz, a2 + 8, a2 + 15, a2[14]);
        if ( !bss )
          bss = wlan_cfg80211_get_bss(**v6, channel_khz, a2 + 8, 0, 0);
      }
      osif_update_connect_results((*v6)[4], bss, a2, a1);
    }
    v15 = 0;
    v14 = 0;
  }
LABEL_37:
  osif_cm_connect_comp_ind(a1, a2, v15);
  _ReadStatusReg(SP_EL0);
  return v14;
}
