// positive sp value has been detected, the output may be wrong!
__int64 sub_1526FC()
{
  __int64 v0; // x19
  __int64 v1; // x20
  unsigned int v2; // w23
  __int64 v3; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x9
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v13; // x0
  int v14; // w9
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  long double v23; // q0
  __int64 v24; // x0
  __int64 v26; // [xsp-78h] [xbp-78h]

  v3 = _arch_copy_to_user(v0 & 0xFF7FFFFFFFFFFFFFLL, &ingress_param, v1);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v10 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v10 - 4096);
  _WriteStatusReg(TTBR1_EL1, v10);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( v3 )
  {
    if ( (unsigned int)__ratelimit(&ipa_setup_cons_pipes__rs_385, "ipa_setup_cons_pipes") )
    {
      printk(&unk_3B92C0, "ipa_setup_cons_pipes");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_5;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_5:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d Ingress copy to user failed\n", "ipa_setup_cons_pipes", 2055);
      }
      mutex_unlock(rmnet_ipa3_ctx + 1088);
      v2 = -14;
      goto LABEL_45;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d Ingress copy to user failed\n", "ipa_setup_cons_pipes", 2055);
    goto LABEL_5;
  }
  cons_pipes_setup_complete = 1;
  v13 = mutex_unlock(rmnet_ipa3_ctx + 1088);
  v14 = *(_DWORD *)(rmnet_ipa3_ctx + 2056);
  if ( (*(_BYTE *)(v26 + 190) & 0x80) != 0 )
  {
    if ( (v14 & 3) == 0 )
      goto LABEL_45;
  }
  else if ( (v14 & 1) == 0 )
  {
    goto LABEL_45;
  }
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 2060) == 1 )
  {
    if ( (unsigned int)__ratelimit(&ipa_setup_cons_pipes__rs_388, "ipa_setup_cons_pipes") )
    {
      printk(&unk_3B92ED, "ipa_setup_cons_pipes");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_16;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_16:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v16 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v16, "ipa-wan %s:%d WAN rt table already exists\n", "ipa_setup_cons_pipes", 2068);
      }
      v2 = -1;
      goto LABEL_45;
    }
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(v15, "ipa-wan %s:%d WAN rt table already exists\n", "ipa_setup_cons_pipes", 2068);
    goto LABEL_16;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64))ipa3_setup_a7_qmap_hdr)(v13) )
  {
    if ( (unsigned int)__ratelimit(&ipa_setup_cons_pipes__rs_391, "ipa_setup_cons_pipes") )
    {
      printk(&unk_3EA83A, "ipa_setup_cons_pipes");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_23;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_23:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v18 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v18, "ipa-wan %s:%d A7 QMAP header setup failed\n", "ipa_setup_cons_pipes", 2074);
      }
      v2 = -14;
      goto LABEL_45;
    }
    v17 = ipa3_get_ipc_logbuf();
    ipc_log_string(v17, "ipa-wan %s:%d A7 QMAP header setup failed\n", "ipa_setup_cons_pipes", 2074);
    goto LABEL_23;
  }
  v19 = ipa3_setup_dflt_wan_rt_tables();
  if ( (_DWORD)v19 )
  {
    v2 = v19;
    ipa3_del_a7_qmap_hdr(v19);
    goto LABEL_45;
  }
  if ( *(_BYTE *)(ipa3_ctx + 48859) == 1 )
  {
    v2 = ipa3_setup_low_lat_rt_rules();
    if ( v2 )
    {
      if ( (unsigned int)__ratelimit(&ipa_setup_cons_pipes__rs_394, "ipa_setup_cons_pipes") )
      {
        printk(&unk_3F947A, "ipa_setup_cons_pipes");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_35:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v21 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v21, "ipa-wan %s:%d low lat rt rule add failed = %d\n", "ipa_setup_cons_pipes", 2087, v2);
          }
          goto LABEL_40;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_35;
      }
      v20 = ipa3_get_ipc_logbuf();
      ipc_log_string(v20, "ipa-wan %s:%d low lat rt rule add failed = %d\n", "ipa_setup_cons_pipes", 2087, v2);
      goto LABEL_35;
    }
  }
  else
  {
    v2 = 0;
  }
LABEL_40:
  if ( ipa3_get_ipc_logbuf() )
  {
    v22 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v22,
      "ipa-wan %s:%d ingress_ep_mask = %d\n",
      "ipa_setup_cons_pipes",
      2090,
      *(_DWORD *)(rmnet_ipa3_ctx + 2056));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v24 = ipa3_get_ipc_logbuf_low();
    v23 = ipc_log_string(
            v24,
            "ipa-wan %s:%d ingress_ep_mask = %d\n",
            "ipa_setup_cons_pipes",
            2090,
            *(_DWORD *)(rmnet_ipa3_ctx + 2056));
  }
  ((void (__fastcall *)(_QWORD, long double))ipa_send_wan_pipe_ind_to_modem)(
    *(unsigned int *)(rmnet_ipa3_ctx + 2056),
    v23);
  *(_BYTE *)(rmnet_ipa3_ctx + 2060) = 1;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return v2;
}
