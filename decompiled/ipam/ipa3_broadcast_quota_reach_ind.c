void __fastcall ipa3_broadcast_quota_reach_ind(unsigned int a1, int a2, char a3)
{
  __int64 v5; // x22
  const char *v6; // x3
  int v7; // w0
  int v8; // w0
  int v9; // w0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0
  long double v13; // q0
  __int64 v14; // x0
  _QWORD *v15; // x8
  unsigned __int8 v16; // w8
  unsigned int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w19
  __int64 v21; // x0
  __int64 v22; // x0
  const char *v23; // x1
  const char *v24; // x2
  __int64 v25; // x3
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  int v32; // [xsp+4h] [xbp-ECh] BYREF
  _QWORD v33[4]; // [xsp+8h] [xbp-E8h] BYREF
  char v34[8]; // [xsp+28h] [xbp-C8h] BYREF
  __int64 v35; // [xsp+30h] [xbp-C0h]
  __int64 v36; // [xsp+38h] [xbp-B8h]
  __int64 v37; // [xsp+40h] [xbp-B0h]
  __int64 v38; // [xsp+48h] [xbp-A8h]
  __int64 v39; // [xsp+50h] [xbp-A0h]
  __int64 v40; // [xsp+58h] [xbp-98h]
  __int64 v41; // [xsp+60h] [xbp-90h]
  char v42[8]; // [xsp+68h] [xbp-88h] BYREF
  __int64 v43; // [xsp+70h] [xbp-80h]
  __int64 v44; // [xsp+78h] [xbp-78h]
  __int64 v45; // [xsp+80h] [xbp-70h]
  __int64 v46; // [xsp+88h] [xbp-68h]
  __int64 v47; // [xsp+90h] [xbp-60h]
  __int64 v48; // [xsp+98h] [xbp-58h]
  __int64 v49; // [xsp+A0h] [xbp-50h]
  _QWORD s[9]; // [xsp+A8h] [xbp-48h] BYREF

  s[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 64);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  *(_QWORD *)v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  *(_QWORD *)v34 = 0;
  v35 = 0;
  v33[0] = s;
  v33[1] = v34;
  v33[2] = v42;
  v33[3] = 0;
  if ( a2 == 2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_broadcast_quota_reach_ind__rs, "ipa3_broadcast_quota_reach_ind") )
    {
      printk(&unk_3D6B7C, "ipa3_broadcast_quota_reach_ind");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_16:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d Quota indication is not supported for WLAN\n",
            "ipa3_broadcast_quota_reach_ind",
            5757);
        }
        goto LABEL_32;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_16;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d Quota indication is not supported for WLAN\n",
      "ipa3_broadcast_quota_reach_ind",
      5757);
    goto LABEL_16;
  }
  if ( a2 == 3 )
  {
    printk(&unk_3B0A17, "ipa3_broadcast_quota_reach_ind");
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(v18, "ipa-wan %s:%d  Wrong upstreamIface type %d\n", "ipa3_broadcast_quota_reach_ind", 5753, 3);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v19, "ipa-wan %s:%d  Wrong upstreamIface type %d\n", "ipa3_broadcast_quota_reach_ind", 5753, 3);
    }
    goto LABEL_32;
  }
  if ( a2 == 1 && *(_DWORD *)(rmnet_ipa3_ctx + 556) != a1 )
  {
    if ( *(_DWORD *)(rmnet_ipa3_ctx + 588) == a1 )
    {
      v5 = 1;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 620) == a1 )
    {
      v5 = 2;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 652) == a1 )
    {
      v5 = 3;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 684) == a1 )
    {
      v5 = 4;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 716) == a1 )
    {
      v5 = 5;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 748) == a1 )
    {
      v5 = 6;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 780) == a1 )
    {
      v5 = 7;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 812) == a1 )
    {
      v5 = 8;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 844) == a1 )
    {
      v5 = 9;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 876) == a1 )
    {
      v5 = 10;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 908) == a1 )
    {
      v5 = 11;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 940) == a1 )
    {
      v5 = 12;
    }
    else if ( *(_DWORD *)(rmnet_ipa3_ctx + 972) == a1 )
    {
      v5 = 13;
    }
    else
    {
      if ( *(_DWORD *)(rmnet_ipa3_ctx + 1004) != a1 )
      {
        printk(&unk_3DC701, "ipa3_broadcast_quota_reach_ind");
        if ( ipa3_get_ipc_logbuf() )
        {
          v29 = ipa3_get_ipc_logbuf();
          ipc_log_string(v29, "ipa-wan %s:%d %u is an mux ID\n", "ipa3_broadcast_quota_reach_ind", 5762, a1);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v30 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v30, "ipa-wan %s:%d %u is an mux ID\n", "ipa3_broadcast_quota_reach_ind", 5762, a1);
        }
        goto LABEL_32;
      }
      v5 = 14;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( (a3 & 1) != 0 )
    v6 = "warningReachedAlert";
  else
    v6 = "quotaReachedAlert";
  v7 = snprintf((char *)s, 0x40u, "ALERT_NAME=%s", v6);
  if ( v7 >= 64 )
  {
    v20 = v7;
    printk(&unk_3F9199, "ipa3_broadcast_quota_reach_ind");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(v21, "ipa-wan %s:%d message too long (%d)", "ipa3_broadcast_quota_reach_ind", 5773, v20);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_32;
    v22 = ipa3_get_ipc_logbuf_low();
    v23 = "ipa-wan %s:%d message too long (%d)";
    v24 = "ipa3_broadcast_quota_reach_ind";
    v25 = 5773;
LABEL_61:
    ipc_log_string(v22, v23, v24, v25, v20);
    goto LABEL_32;
  }
  if ( a2 == 1 )
  {
    v8 = snprintf(v34, 0x40u, "UPSTREAM=%s", (const char *)(rmnet_ipa3_ctx + 32 * v5 + 560));
    if ( v8 <= 63 )
    {
      v9 = snprintf(v42, 0x40u, "INTERFACE=%s", rmnet_ipa3_ctx + 32 * v5 + 560);
      goto LABEL_20;
    }
    goto LABEL_49;
  }
  v8 = snprintf(v34, 0x40u, "UPSTREAM=%s", "wlan0");
  if ( v8 >= 64 )
  {
LABEL_49:
    v20 = v8;
    printk(&unk_3F9199, "ipa3_broadcast_quota_reach_ind");
    if ( ipa3_get_ipc_logbuf() )
    {
      v26 = ipa3_get_ipc_logbuf();
      ipc_log_string(v26, "ipa-wan %s:%d message too long (%d)", "ipa3_broadcast_quota_reach_ind", 5787, v20);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_32;
    v22 = ipa3_get_ipc_logbuf_low();
    v23 = "ipa-wan %s:%d message too long (%d)";
    v24 = "ipa3_broadcast_quota_reach_ind";
    v25 = 5787;
    goto LABEL_61;
  }
  v9 = snprintf(v42, 0x40u, "INTERFACE=%s", "wlan0");
LABEL_20:
  if ( v9 >= 64 )
  {
    v20 = v9;
    printk(&unk_3F9199, "ipa3_broadcast_quota_reach_ind");
    if ( ipa3_get_ipc_logbuf() )
    {
      v27 = ipa3_get_ipc_logbuf();
      ipc_log_string(v27, "ipa-wan %s:%d message too long (%d)", "ipa3_broadcast_quota_reach_ind", 5803, v20);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_32;
    v22 = ipa3_get_ipc_logbuf_low();
    v23 = "ipa-wan %s:%d message too long (%d)";
    v24 = "ipa3_broadcast_quota_reach_ind";
    v25 = 5803;
    goto LABEL_61;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v12 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v12,
      "ipa-wan %s:%d putting nlmsg: <%s> <%s> <%s>\n",
      "ipa3_broadcast_quota_reach_ind",
      5808,
      (const char *)s,
      v34,
      v42);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    v13 = ipc_log_string(
            v14,
            "ipa-wan %s:%d putting nlmsg: <%s> <%s> <%s>\n",
            "ipa3_broadcast_quota_reach_ind",
            5808,
            (const char *)s,
            v34,
            v42);
  }
  v15 = (_QWORD *)rmnet_ipa3_ctx;
  if ( rmnet_ipa3_ctx )
  {
    v15 = *(_QWORD **)rmnet_ipa3_ctx;
    if ( *(_QWORD *)rmnet_ipa3_ctx )
      v15 = (_QWORD *)*v15;
  }
  kobject_uevent_env(v15 + 172, 2, v33, v13);
  if ( (a3 & 1) != 0 )
    v16 = 48;
  else
    v16 = 23;
  v32 = v16;
  v17 = ipa_send_msg((unsigned __int8 *)&v32, nullptr, nullptr);
  if ( v17 )
  {
    v20 = v17;
    printk(&unk_3EA6F6, "rmnet_ipa_send_quota_reach_ind");
    if ( ipa3_get_ipc_logbuf() )
    {
      v28 = ipa3_get_ipc_logbuf();
      ipc_log_string(v28, "ipa-wan %s:%d ipa_send_msg failed: %d\n", "rmnet_ipa_send_quota_reach_ind", 4370, v20);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      v23 = "ipa-wan %s:%d ipa_send_msg failed: %d\n";
      v24 = "rmnet_ipa_send_quota_reach_ind";
      v25 = 4370;
      goto LABEL_61;
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
}
