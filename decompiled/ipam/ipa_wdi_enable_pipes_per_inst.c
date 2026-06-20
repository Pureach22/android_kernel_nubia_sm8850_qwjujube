__int64 __fastcall ipa_wdi_enable_pipes_per_inst(unsigned int a1)
{
  __int64 v1; // x8
  unsigned int v2; // w3
  __int64 v3; // x22
  unsigned int v4; // w20
  __int64 v5; // x0
  signed int ep_mapping; // w19
  int v7; // w20
  unsigned int v8; // w21
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  _DWORD *v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v19; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 ipc_logbuf; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v38; // [xsp+10h] [xbp-100h]
  __int64 v39; // [xsp+18h] [xbp-F8h]
  __int64 v40; // [xsp+20h] [xbp-F0h]
  __int64 v41; // [xsp+28h] [xbp-E8h]
  __int64 v42; // [xsp+30h] [xbp-E0h]
  __int64 v43; // [xsp+38h] [xbp-D8h]
  __int64 v44; // [xsp+40h] [xbp-D0h]
  __int64 v45; // [xsp+48h] [xbp-C8h]
  __int64 v46; // [xsp+50h] [xbp-C0h]
  __int64 v47; // [xsp+58h] [xbp-B8h]
  __int64 v48; // [xsp+60h] [xbp-B0h]
  __int64 v49; // [xsp+68h] [xbp-A8h]
  __int64 v50; // [xsp+70h] [xbp-A0h]
  __int64 v51; // [xsp+78h] [xbp-98h]
  __int64 v52; // [xsp+80h] [xbp-90h]
  __int64 v53; // [xsp+88h] [xbp-88h]
  __int64 v54; // [xsp+90h] [xbp-80h]
  __int64 v55; // [xsp+98h] [xbp-78h]
  __int64 v56; // [xsp+A0h] [xbp-70h]
  __int64 v57; // [xsp+A8h] [xbp-68h]
  __int64 v58; // [xsp+B0h] [xbp-60h]
  __int64 v59; // [xsp+B8h] [xbp-58h]
  __int64 v60; // [xsp+C0h] [xbp-50h]
  __int64 v61; // [xsp+C8h] [xbp-48h]
  __int64 v62; // [xsp+D0h] [xbp-40h]
  __int64 v63; // [xsp+D8h] [xbp-38h]
  __int64 v64; // [xsp+E0h] [xbp-30h]
  __int64 v65; // [xsp+E8h] [xbp-28h]
  __int64 v66; // [xsp+F0h] [xbp-20h]
  __int64 v67; // [xsp+F8h] [xbp-18h]
  __int64 v68; // [xsp+100h] [xbp-10h]
  __int64 v69; // [xsp+108h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 2 )
  {
    printk(&unk_3B3944, "ipa_wdi_enable_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Invalid handle %d\n", "ipa_wdi_enable_pipes_per_inst", 844, a1);
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_44;
    }
    else if ( !ipa3_get_ipc_logbuf_low() )
    {
LABEL_44:
      __break(0x5512u);
LABEL_45:
      printk(&unk_3F0CD4, "ipa_wdi_enable_pipes_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(v19, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_enable_pipes_per_inst", 848);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_wdi %s:%d wdi ctx is not initialized.\n",
          "ipa_wdi_enable_pipes_per_inst",
          848);
        result = 0xFFFFFFFFLL;
        goto LABEL_54;
      }
LABEL_53:
      result = 0xFFFFFFFFLL;
      goto LABEL_54;
    }
    v24 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v24, "ipa_wdi %s:%d Invalid handle %d\n", "ipa_wdi_enable_pipes_per_inst", 844, a1);
    __break(0x5512u);
    goto LABEL_57;
  }
  v1 = ipa_wdi_ctx_list[a1];
  if ( !v1 )
    goto LABEL_45;
  v2 = *(_DWORD *)(v1 + 144);
  v3 = a1;
  if ( a1 == 1 && v2 <= 1 )
  {
    printk(&unk_3E2714, "ipa_wdi_enable_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v21,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_enable_pipes_per_inst",
        856,
        *(_DWORD *)(ipa_wdi_ctx_list[v3] + 144));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v22,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_enable_pipes_per_inst",
        856,
        *(_DWORD *)(ipa_wdi_ctx_list[v3] + 144));
      result = 0xFFFFFFFFLL;
      goto LABEL_54;
    }
    goto LABEL_53;
  }
  if ( v2 < 2 )
  {
    ep_mapping = ipa_get_ep_mapping(10);
    v7 = ipa_get_ep_mapping(11);
LABEL_12:
    v8 = -1;
    goto LABEL_13;
  }
  if ( (unsigned int)(*(_DWORD *)(v1 + 184) + 1) >= 2 )
  {
    v4 = 17;
    v5 = 14;
  }
  else
  {
    v4 = 13;
    v5 = 12;
  }
  ep_mapping = ipa_get_ep_mapping(v5);
  v7 = ipa_get_ep_mapping(v4);
  if ( *(_BYTE *)(ipa_wdi_ctx_list[v3] + 161) != 1 )
    goto LABEL_12;
  v8 = ipa_get_ep_mapping(119);
LABEL_13:
  result = 4294967282LL;
  if ( v7 >= 1 && ep_mapping >= 1 )
  {
    if ( !(unsigned int)ipa_pm_activate_sync(*(_DWORD *)(ipa_wdi_ctx_list[v3] + 176)) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v10 = ipa3_get_ipc_logbuf();
        ipc_log_string(v10, "ipa_wdi %s:%d Enable WDI pipes\n", "ipa_wdi_enable_pipes_per_inst", 883);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v11, "ipa_wdi %s:%d Enable WDI pipes\n", "ipa_wdi_enable_pipes_per_inst", 883);
      }
      v12 = (_DWORD *)ipa_wdi_ctx_list[v3];
      if ( v12[36] < 2u )
      {
        v15 = (unsigned int)v12[38];
        if ( (unsigned int)v15 > 0x1E || v12[39] >= 0x1Fu )
        {
          printk(&unk_3D7436, "ipa_wdi_enable_pipes_per_inst");
          if ( ipa3_get_ipc_logbuf() )
          {
            v27 = ipa3_get_ipc_logbuf();
            ipc_log_string(v27, "ipa_wdi %s:%d pipe handle not valid\n", "ipa_wdi_enable_pipes_per_inst", 896);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v28 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v28, "ipa_wdi %s:%d pipe handle not valid\n", "ipa_wdi_enable_pipes_per_inst", 896);
          }
          goto LABEL_39;
        }
        if ( (unsigned int)ipa_enable_wdi_pipe((_QWORD *)v15) )
        {
          printk(&unk_3AB6C3, "ipa_wdi_enable_pipes_per_inst");
          if ( ipa3_get_ipc_logbuf() )
          {
            v29 = ipa3_get_ipc_logbuf();
            ipc_log_string(v29, "ipa_wdi %s:%d fail to enable wdi tx pipe\n", "ipa_wdi_enable_pipes_per_inst", 900);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v30 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v30, "ipa_wdi %s:%d fail to enable wdi tx pipe\n", "ipa_wdi_enable_pipes_per_inst", 900);
          }
          goto LABEL_39;
        }
        if ( (unsigned int)ipa_resume_wdi_pipe((_QWORD *)*(unsigned int *)(ipa_wdi_ctx_list[v3] + 152)) )
        {
          printk(&unk_3B9CEC, "ipa_wdi_enable_pipes_per_inst");
          if ( ipa3_get_ipc_logbuf() )
          {
            v31 = ipa3_get_ipc_logbuf();
            ipc_log_string(v31, "ipa_wdi %s:%d fail to resume wdi tx pipe\n", "ipa_wdi_enable_pipes_per_inst", 904);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v32 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v32, "ipa_wdi %s:%d fail to resume wdi tx pipe\n", "ipa_wdi_enable_pipes_per_inst", 904);
          }
          goto LABEL_39;
        }
        if ( (unsigned int)ipa_enable_wdi_pipe((_QWORD *)*(unsigned int *)(ipa_wdi_ctx_list[v3] + 156)) )
        {
          printk(&unk_3D1495, "ipa_wdi_enable_pipes_per_inst");
          if ( ipa3_get_ipc_logbuf() )
          {
            v33 = ipa3_get_ipc_logbuf();
            ipc_log_string(v33, "ipa_wdi %s:%d fail to enable wdi rx pipe\n", "ipa_wdi_enable_pipes_per_inst", 908);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v34 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v34, "ipa_wdi %s:%d fail to enable wdi rx pipe\n", "ipa_wdi_enable_pipes_per_inst", 908);
          }
          goto LABEL_39;
        }
        if ( (unsigned int)ipa_resume_wdi_pipe((_QWORD *)*(unsigned int *)(ipa_wdi_ctx_list[v3] + 156)) )
        {
          printk(&unk_3B6B51, "ipa_wdi_enable_pipes_per_inst");
          if ( ipa3_get_ipc_logbuf() )
          {
            v35 = ipa3_get_ipc_logbuf();
            ipc_log_string(v35, "ipa_wdi %s:%d fail to resume wdi rx pipe\n", "ipa_wdi_enable_pipes_per_inst", 912);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v36 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v36, "ipa_wdi %s:%d fail to resume wdi rx pipe\n", "ipa_wdi_enable_pipes_per_inst", 912);
          }
          goto LABEL_39;
        }
      }
      else if ( (unsigned int)ipa3_enable_wdi3_pipes((unsigned int)v7, ep_mapping, v8) )
      {
        printk(&unk_3C28B4, "ipa_wdi_enable_pipes_per_inst");
        if ( ipa3_get_ipc_logbuf() )
        {
          v13 = ipa3_get_ipc_logbuf();
          ipc_log_string(v13, "ipa_wdi %s:%d fail to enable wdi pipes\n", "ipa_wdi_enable_pipes_per_inst", 887);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v14, "ipa_wdi %s:%d fail to enable wdi pipes\n", "ipa_wdi_enable_pipes_per_inst", 887);
        }
        v67 = 0;
        v68 = 0;
        v65 = 0;
        v66 = 0;
        v63 = 0;
        v64 = 0;
        v61 = 0;
        v62 = 0;
        v59 = 0;
        v60 = 0;
        v57 = 0;
        v58 = 0;
        v55 = 0;
        v56 = 0;
        v53 = 0;
        v54 = 0;
        v51 = 0;
        v52 = 0;
        v49 = 0;
        v50 = 0;
        v47 = 0;
        v48 = 0;
        v45 = 0;
        v46 = 0;
        v43 = 0;
        v44 = 0;
        v41 = 0;
        v42 = 0;
        v39 = 0;
        v40 = 0;
        *(_QWORD *)s = 0;
        v38 = 0;
        snprintf(s, 0x100u, "ipa-event-log %s:%d fail to enable wdi pipes\n", "ipa_wdi_enable_pipes_per_inst", 888);
        ipa3_send_opt_log_msg(s);
LABEL_39:
        result = 4294967282LL;
        goto LABEL_54;
      }
      if ( *(_BYTE *)(ipa3_ctx + 32267) != 1 )
      {
        result = 0;
        goto LABEL_54;
      }
      result = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(ipa_wdi_ctx_list[v3] + 176));
      if ( !(_DWORD)result )
      {
        *((_DWORD *)&opt_dpath_info + 34 * (unsigned int)v3 + 27) = 1;
        goto LABEL_54;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v16 = ipa3_get_ipc_logbuf();
        ipc_log_string(v16, "ipa_wdi %s:%d fail to deactivate ipa pm\n", "ipa_wdi_enable_pipes_per_inst", 920);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v17 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v17, "ipa_wdi %s:%d fail to deactivate ipa pm\n", "ipa_wdi_enable_pipes_per_inst", 920);
      }
      goto LABEL_39;
    }
LABEL_57:
    printk(&unk_3E8256, "ipa_wdi_enable_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v25 = ipa3_get_ipc_logbuf();
      ipc_log_string(v25, "ipa_wdi %s:%d fail to activate ipa pm\n", "ipa_wdi_enable_pipes_per_inst", 880);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa_wdi %s:%d fail to activate ipa pm\n", "ipa_wdi_enable_pipes_per_inst", 880);
    }
    goto LABEL_39;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
