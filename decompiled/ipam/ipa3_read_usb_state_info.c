__int64 __fastcall ipa3_read_usb_state_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x0
  __int64 v9; // x10
  const char *v10; // x23
  __int64 v11; // x10
  const char *v12; // x24
  _DWORD *v13; // x9
  int v14; // w25
  const char **v15; // x8
  int v16; // w12
  const char **v17; // x12
  int v18; // w12
  const char **v19; // x12
  int v20; // w12
  const char **v21; // x12
  int v22; // w12
  const char **v23; // x12
  int v24; // w12
  const char **v25; // x11
  int v26; // w9
  __int64 v27; // x0
  unsigned int v28; // w23
  char *v29; // x0
  __int64 v30; // x1
  int v31; // w0
  unsigned int v32; // w27
  int v33; // w0
  unsigned __int64 v34; // x23
  unsigned int v35; // w27
  unsigned __int64 v36; // x24
  char *v37; // x0
  __int64 v38; // x1
  int v39; // w0
  int v40; // w0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  long double v43; // q0
  __int64 v44; // x0
  const char *v45; // [xsp+18h] [xbp-48h] BYREF
  const char *v46; // [xsp+20h] [xbp-40h]
  const char *v47; // [xsp+28h] [xbp-38h]
  const char *v48; // [xsp+30h] [xbp-30h]
  const char *v49; // [xsp+38h] [xbp-28h]
  const char *v50; // [xsp+40h] [xbp-20h]
  const char *v51; // [xsp+48h] [xbp-18h] BYREF
  const char *v52[2]; // [xsp+50h] [xbp-10h] BYREF

  v52[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa3_usb_get_status_dbg_info", 1755);
  }
  if ( ipa3_usb_ctx )
  {
    mutex_lock(ipa3_usb_ctx + 544);
    v51 = nullptr;
    v52[0] = nullptr;
    v49 = nullptr;
    v50 = nullptr;
    v47 = nullptr;
    v48 = nullptr;
    v45 = nullptr;
    v46 = nullptr;
    v8 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
    v9 = *(unsigned int *)(ipa3_usb_ctx + 656);
    if ( (unsigned int)v9 > 7 )
      v10 = "UNSUPPORTED";
    else
      v10 = off_1E52B8[v9];
    v11 = *(unsigned int *)(ipa3_usb_ctx + 912);
    if ( (unsigned int)v11 > 7 )
      v12 = "UNSUPPORTED";
    else
      v12 = off_1E52B8[v11];
    raw_spin_unlock_irqrestore(ipa3_usb_ctx + 524, v8);
    v13 = (_DWORD *)ipa3_usb_ctx;
    v14 = 0;
    v15 = &v51;
    v16 = *(_DWORD *)(ipa3_usb_ctx + 56);
    if ( v16 == 1 )
    {
      v17 = &v51;
    }
    else
    {
      if ( v16 )
        goto LABEL_15;
      v14 = 1;
      v17 = &v45;
    }
    *v17 = "rndis_ipa";
LABEL_15:
    v18 = v13[32];
    if ( v18 == 1 )
    {
      v19 = &v51;
    }
    else
    {
      if ( v18 )
        goto LABEL_20;
      v19 = &(&v45)[v14++];
    }
    *v19 = "ecm_ipa";
LABEL_20:
    v20 = v13[50];
    if ( v20 == 1 )
    {
      v21 = &v51;
    }
    else
    {
      if ( v20 )
        goto LABEL_25;
      v21 = &(&v45)[v14++];
    }
    *v21 = "rmnet";
LABEL_25:
    v22 = v13[68];
    if ( v22 == 1 )
    {
      v23 = &v51;
    }
    else
    {
      if ( v22 )
        goto LABEL_30;
      v23 = &(&v45)[v14++];
    }
    *v23 = "mbim";
LABEL_30:
    v24 = v13[86];
    if ( v24 == 1 )
    {
      v25 = v52;
    }
    else
    {
      if ( v24 )
        goto LABEL_35;
      v25 = &(&v45)[v14++];
    }
    *v25 = "dpl";
LABEL_35:
    v26 = v13[104];
    if ( v26 != 1 )
    {
      if ( v26 )
      {
LABEL_39:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v27 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v27, "ipa_usb %s:%d exit\n", "ipa3_usb_get_status_dbg_info", 1811);
        }
        mutex_unlock(ipa3_usb_ctx + 544);
        v28 = scnprintf(
                &dbg_buff_6,
                4096,
                "Tethering Data State: %s\nDPL State: %s\nProtocols in Initialized State: ",
                v10,
                v12);
        if ( v14 )
        {
          if ( v28 > 0x1000 )
            goto LABEL_76;
          v28 += scnprintf((char *)&dbg_buff_6 + v28, 4096 - v28, "%s ", v45);
          if ( v14 != 1 )
          {
            if ( v28 > 0x1000 )
              goto LABEL_76;
            v28 += scnprintf((char *)&dbg_buff_6 + v28, 4096 - v28, "%s ", v46);
            if ( v14 != 2 )
            {
              if ( v28 > 0x1000 )
                goto LABEL_76;
              v28 += scnprintf((char *)&dbg_buff_6 + v28, 4096 - v28, "%s ", v47);
              if ( v14 != 3 )
              {
                if ( v28 > 0x1000 )
                  goto LABEL_76;
                v28 += scnprintf((char *)&dbg_buff_6 + v28, 4096 - v28, "%s ", v48);
                if ( v14 != 4 )
                {
                  if ( v28 > 0x1000 )
                    goto LABEL_76;
                  v28 += scnprintf((char *)&dbg_buff_6 + v28, 4096 - v28, "%s ", v49);
                  if ( v14 != 5 )
                  {
                    if ( v28 > 0x1000 )
                      goto LABEL_76;
                    v28 += scnprintf((char *)&dbg_buff_6 + v28, 4096 - v28, "%s ", v50);
                  }
                }
              }
            }
          }
        }
        if ( v28 <= 0x1000 )
        {
          v29 = (char *)&dbg_buff_6 + v28;
          v30 = 4096 - v28;
          v31 = v14 ? scnprintf(v29, v30, "\n") : scnprintf(v29, v30, "None\n");
          v32 = v31 + v28;
          if ( v31 + v28 <= 0x1000 )
          {
            v33 = scnprintf((char *)&dbg_buff_6 + v32, 4096 - v32, "Protocols in Connected State: ");
            v34 = (unsigned __int64)v51;
            v35 = v33 + v32;
            if ( v51 )
            {
              if ( v35 > 0x1000 )
                goto LABEL_76;
              v35 += scnprintf((char *)&dbg_buff_6 + v35, 4096 - v35, "%s ", v51);
            }
            v36 = (unsigned __int64)v52[0];
            if ( v52[0] )
            {
              if ( v35 > 0x1000 )
                goto LABEL_76;
              v35 += scnprintf((char *)&dbg_buff_6 + v35, 4096 - v35, "%s ", v52[0]);
            }
            if ( v35 <= 0x1000 )
            {
              v37 = (char *)&dbg_buff_6 + v35;
              v38 = 4096 - v35;
              if ( v34 | v36 )
                v39 = scnprintf(v37, v38, "\n");
              else
                v39 = scnprintf(v37, v38, "None\n");
              v40 = v39 + v35;
              goto LABEL_70;
            }
          }
        }
LABEL_76:
        __break(0x5512u);
      }
      v15 = &(&v45)[v14++];
    }
    *v15 = "rmnet_cv2x";
    goto LABEL_39;
  }
  printk(&unk_3B6ACA, "ipa3_usb_get_status_dbg_info");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_usb %s:%d IPA USB was not inited yet\n", "ipa3_usb_get_status_dbg_info", 1758);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v44 = ipa3_get_ipc_logbuf_low();
    v43 = ipc_log_string(v44, "ipa_usb %s:%d IPA USB was not inited yet\n", "ipa3_usb_get_status_dbg_info", 1758);
  }
  v40 = scnprintf(&dbg_buff_6, 4096, "Fail to read IPA USB status\n", *(double *)&v43);
LABEL_70:
  result = simple_read_from_buffer(a2, a3, a4, &dbg_buff_6, v40);
  _ReadStatusReg(SP_EL0);
  return result;
}
