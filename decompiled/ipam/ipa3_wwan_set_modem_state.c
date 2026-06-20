__int64 __fastcall ipa3_wwan_set_modem_state(const char *a1)
{
  int v2; // w9
  __int64 v3; // x0
  __int64 result; // x0
  __int64 **v5; // x8
  __int64 *v6; // x8
  __int64 v7; // x8
  unsigned int v8; // w20
  unsigned int v9; // w0
  unsigned int v10; // w19
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w0
  unsigned int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x0
  const char *v17; // x3
  unsigned int v18; // w0
  unsigned int v19; // w19
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 ipc_logbuf; // x0
  long double v23; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v25; // x8
  _QWORD v26[4]; // [xsp+8h] [xbp-E8h] BYREF
  char v27[8]; // [xsp+28h] [xbp-C8h] BYREF
  __int64 v28; // [xsp+30h] [xbp-C0h]
  __int64 v29; // [xsp+38h] [xbp-B8h]
  __int64 v30; // [xsp+40h] [xbp-B0h]
  __int64 v31; // [xsp+48h] [xbp-A8h]
  __int64 v32; // [xsp+50h] [xbp-A0h]
  __int64 v33; // [xsp+58h] [xbp-98h]
  __int64 v34; // [xsp+60h] [xbp-90h]
  char v35[8]; // [xsp+68h] [xbp-88h] BYREF
  __int64 v36; // [xsp+70h] [xbp-80h]
  __int64 v37; // [xsp+78h] [xbp-78h]
  __int64 v38; // [xsp+80h] [xbp-70h]
  __int64 v39; // [xsp+88h] [xbp-68h]
  __int64 v40; // [xsp+90h] [xbp-60h]
  __int64 v41; // [xsp+98h] [xbp-58h]
  __int64 v42; // [xsp+A0h] [xbp-50h]
  char s[8]; // [xsp+A8h] [xbp-48h] BYREF
  __int64 v44; // [xsp+B0h] [xbp-40h]
  __int64 v45; // [xsp+B8h] [xbp-38h]
  __int64 v46; // [xsp+C0h] [xbp-30h]
  __int64 v47; // [xsp+C8h] [xbp-28h]
  __int64 v48; // [xsp+D0h] [xbp-20h]
  __int64 v49; // [xsp+D8h] [xbp-18h]
  __int64 v50; // [xsp+E0h] [xbp-10h]
  __int64 v51; // [xsp+E8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = s;
  v26[1] = v35;
  v26[2] = v27;
  v26[3] = 0;
  if ( !a1 )
  {
    result = 4294967274LL;
    goto LABEL_10;
  }
  v2 = *(unsigned __int8 *)a1;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v3 = *(unsigned int *)(rmnet_ipa3_ctx + 1192);
  v45 = 0;
  v46 = 0;
  *(_QWORD *)s = 0;
  v44 = 0;
  *(_QWORD *)v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  *(_QWORD *)v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  if ( v2 )
  {
    result = ipa_pm_activate_sync(v3);
    v5 = (__int64 **)rmnet_ipa3_ctx;
    if ( !rmnet_ipa3_ctx )
      goto LABEL_10;
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64))ipa_pm_deactivate_sync)(v3);
    v5 = (__int64 **)rmnet_ipa3_ctx;
    if ( !rmnet_ipa3_ctx )
      goto LABEL_10;
  }
  v6 = *v5;
  if ( v6 )
  {
    v7 = *v6;
    if ( v7 )
    {
      if ( (*(_BYTE *)(v7 + 190) & 0x80) != 0 )
      {
        v8 = result;
        v9 = snprintf(s, 0x40u, "ALERT_NAME=%s", "upstreamEvent");
        if ( v9 < 0x40 )
        {
          *((_BYTE *)a1 + 16) = 0;
          v13 = snprintf(v35, 0x40u, "UPSTREAM=%s", a1 + 1);
          if ( v13 < 0x40 )
          {
            if ( *a1 )
              v17 = "UP";
            else
              v17 = "DOWN";
            v18 = snprintf(v27, 0x40u, "STATE=%s", v17);
            if ( v18 < 0x40 )
            {
              printk(&unk_3E76DA, "ipa3_wwan_set_modem_state");
              if ( ipa3_get_ipc_logbuf() )
              {
                ipc_logbuf = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  ipc_logbuf,
                  "ipa-wan %s:%d nlmsg: <%s> <%s> <%s>\n",
                  "ipa3_wwan_set_modem_state",
                  3422,
                  s,
                  v35,
                  v27);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
                v23 = ipc_log_string(
                        ipc_logbuf_low,
                        "ipa-wan %s:%d nlmsg: <%s> <%s> <%s>\n",
                        "ipa3_wwan_set_modem_state",
                        3422,
                        s,
                        v35,
                        v27);
              }
              if ( rmnet_ipa3_ctx )
              {
                result = v8;
                if ( !*(_QWORD *)rmnet_ipa3_ctx )
                  goto LABEL_10;
                v25 = **(_QWORD **)rmnet_ipa3_ctx;
                if ( !v25 )
                  goto LABEL_10;
                kobject_uevent_env(v25 + 1376, 2, v26, v23);
              }
            }
            else
            {
              v19 = v18;
              printk(&unk_3DC683, "ipa3_wwan_set_modem_state");
              if ( ipa3_get_ipc_logbuf() )
              {
                v20 = ipa3_get_ipc_logbuf();
                ipc_log_string(v20, "ipa-wan %s:%d Iface state invalid (%d)", "ipa3_wwan_set_modem_state", 3419, v19);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v21 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v21, "ipa-wan %s:%d Iface state invalid (%d)", "ipa3_wwan_set_modem_state", 3419, v19);
              }
            }
          }
          else
          {
            v14 = v13;
            printk(&unk_3C8102, "ipa3_wwan_set_modem_state");
            if ( ipa3_get_ipc_logbuf() )
            {
              v15 = ipa3_get_ipc_logbuf();
              ipc_log_string(v15, "ipa-wan %s:%d Iface name invalid (%d)", "ipa3_wwan_set_modem_state", 3410, v14);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v16 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v16, "ipa-wan %s:%d Iface name invalid (%d)", "ipa3_wwan_set_modem_state", 3410, v14);
            }
          }
        }
        else
        {
          v10 = v9;
          printk(&unk_3E1E10, "ipa3_wwan_set_modem_state");
          if ( ipa3_get_ipc_logbuf() )
          {
            v11 = ipa3_get_ipc_logbuf();
            ipc_log_string(v11, "ipa-wan %s:%d alert message invalid (%d)", "ipa3_wwan_set_modem_state", 3402, v10);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v12 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v12, "ipa-wan %s:%d alert message invalid (%d)", "ipa3_wwan_set_modem_state", 3402, v10);
          }
        }
        result = v8;
      }
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
