__int64 ipa3_setup_dflt_wan_rt_tables()
{
  __int64 v0; // x19
  char v1; // w8
  unsigned __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  unsigned int v18; // w20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v24; // x21
  long double (*v25)(_QWORD, const char *, ...); // x0

  v0 = _kmalloc_cache_noprof(ipc_log_string, 3520, 64);
  if ( !v0 )
    return (unsigned int)-12;
  while ( 1 )
  {
    v1 = *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u ? 1 : 2;
    *(_BYTE *)(v0 + 40) = v1;
    v2 = 192LL * *(unsigned __int8 *)(v0 + 40);
    v3 = _kmalloc_noprof(v2, 3520);
    v4 = v3;
    *(_QWORD *)(v0 + 56) = v3;
    if ( !v3 )
      break;
    *(_DWORD *)(v0 + 44) = 192;
    *(_DWORD *)(v0 + 4) = 0;
    *(_BYTE *)v0 = 1;
    strcpy((char *)(v0 + 8), "ipa_dflt_wan_rt");
    if ( !v2 )
      goto LABEL_59;
    *(_BYTE *)v3 = 1;
    v5 = rmnet_ipa3_ctx;
    *(_DWORD *)(v3 + 16) = 35;
    *(_DWORD *)(v3 + 20) = *(_DWORD *)(v5 + 520);
    if ( v2 < 0xB5 )
      goto LABEL_59;
    v6 = ipa3_ctx;
    *(_BYTE *)(v3 + 181) = 1;
    if ( *(_DWORD *)(v6 + 32240) >= 0x15u )
    {
      if ( v2 < 0xC1 )
        goto LABEL_59;
      *(_BYTE *)(v3 + 192) = 0;
      if ( v2 < 0xD0 )
        goto LABEL_59;
      *(_DWORD *)(v3 + 208) = 35;
      if ( v2 < 0xD4 )
        goto LABEL_59;
      *(_DWORD *)(v3 + 212) = *(_DWORD *)(v5 + 520);
      if ( v2 < 0x17A )
        goto LABEL_59;
      *(_BYTE *)(v3 + 378) = 1;
      *(_DWORD *)(v3 + 220) = 2;
      *(_BYTE *)(v3 + 281) = 1;
    }
    if ( (unsigned int)ipa3_add_rt_rule_ext_v2(v0, 0) )
    {
      printk(&unk_3ADF53, "ipa3_setup_dflt_wan_rt_tables");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa-wan %s:%d fail to add dflt_wan v4 rule\n", "ipa3_setup_dflt_wan_rt_tables", 518);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa-wan %s:%d fail to add dflt_wan v4 rule\n",
          "ipa3_setup_dflt_wan_rt_tables",
          518);
      }
      goto LABEL_57;
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v7,
        "ipa-wan %s:%d dflt v4 rt rule hdl[WAN_RT_COMMON]=%x\n",
        "ipa3_setup_dflt_wan_rt_tables",
        523,
        *(_DWORD *)(v4 + 4));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v8,
        "ipa-wan %s:%d dflt v4 rt rule hdl[WAN_RT_COMMON]=%x\n",
        "ipa3_setup_dflt_wan_rt_tables",
        523,
        *(_DWORD *)(v4 + 4));
    }
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v9 = ipa3_get_ipc_logbuf();
        if ( v2 < 0xC4 )
          goto LABEL_59;
        ipc_log_string(
          v9,
          "ipa-wan %s:%d dflt v4 rt rule hdl[WAN_RT_ICMP]=%x\n",
          "ipa3_setup_dflt_wan_rt_tables",
          526,
          *(_DWORD *)(v4 + 196));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        if ( v2 < 0xC4 )
          goto LABEL_59;
        ipc_log_string(
          v10,
          "ipa-wan %s:%d dflt v4 rt rule hdl[WAN_RT_ICMP]=%x\n",
          "ipa3_setup_dflt_wan_rt_tables",
          526,
          *(_DWORD *)(v4 + 196));
      }
    }
    v11 = rmnet_ipa3_ctx;
    v12 = ipa3_ctx;
    *(_DWORD *)(rmnet_ipa3_ctx + 524) = *(_DWORD *)(v4 + 4);
    if ( *(_DWORD *)(v12 + 32240) >= 0x15u )
    {
      if ( v2 < 0xC4 )
        goto LABEL_59;
      *(_DWORD *)(v11 + 528) = *(_DWORD *)(v4 + 196);
      v12 = ipa3_ctx;
    }
    *(_DWORD *)(v0 + 4) = 1;
    if ( *(_DWORD *)(v12 + 32240) >= 0x15u )
    {
      if ( v2 < 0xDC )
        goto LABEL_59;
      *(_DWORD *)(v4 + 220) = 0x2000;
      if ( v2 < 0x120 )
        goto LABEL_59;
      *(_BYTE *)(v4 + 288) = 58;
    }
    if ( (unsigned int)ipa3_add_rt_rule_ext_v2(v0, 0) )
    {
      printk(&unk_3B0ACA, "ipa3_setup_dflt_wan_rt_tables");
      if ( ipa3_get_ipc_logbuf() )
      {
        v21 = ipa3_get_ipc_logbuf();
        ipc_log_string(v21, "ipa-wan %s:%d fail to add dflt_wan v6 rule\n", "ipa3_setup_dflt_wan_rt_tables", 543);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v22 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v22, "ipa-wan %s:%d fail to add dflt_wan v6 rule\n", "ipa3_setup_dflt_wan_rt_tables", 543);
      }
LABEL_57:
      v18 = -1;
      goto LABEL_58;
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v13,
        "ipa-wan %s:%d dflt v6 rt rule hdl[WAN_RT_COMMON]=%x\n",
        "ipa3_setup_dflt_wan_rt_tables",
        548,
        *(_DWORD *)(v4 + 4));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v14,
        "ipa-wan %s:%d dflt v6 rt rule hdl[WAN_RT_COMMON]=%x\n",
        "ipa3_setup_dflt_wan_rt_tables",
        548,
        *(_DWORD *)(v4 + 4));
    }
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v15 = ipa3_get_ipc_logbuf();
        if ( v2 < 0xC4 )
          goto LABEL_59;
        ipc_log_string(
          v15,
          "ipa-wan %s:%d dflt v6 rt rule hdl[WAN_RT_ICMP]=%x\n",
          "ipa3_setup_dflt_wan_rt_tables",
          551,
          *(_DWORD *)(v4 + 196));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v16 = ipa3_get_ipc_logbuf_low();
        if ( v2 < 0xC4 )
          goto LABEL_59;
        ipc_log_string(
          v16,
          "ipa-wan %s:%d dflt v6 rt rule hdl[WAN_RT_ICMP]=%x\n",
          "ipa3_setup_dflt_wan_rt_tables",
          551,
          *(_DWORD *)(v4 + 196));
      }
    }
    v17 = rmnet_ipa3_ctx;
    *(_DWORD *)(rmnet_ipa3_ctx + 532) = *(_DWORD *)(v4 + 4);
    if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
    {
      v18 = 0;
      goto LABEL_58;
    }
    if ( v2 >= 0xC4 )
    {
      v18 = 0;
      *(_DWORD *)(v17 + 536) = *(_DWORD *)(v4 + 196);
LABEL_58:
      kfree(*(_QWORD *)(v0 + 56));
      goto LABEL_62;
    }
LABEL_59:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v24 = *(_QWORD *)(StatusReg + 80);
    v25 = ipc_log_string;
    *(_QWORD *)(StatusReg + 80) = &ipa3_setup_dflt_wan_rt_tables__alloc_tag;
    v0 = _kmalloc_cache_noprof(v25, 3520, 64);
    *(_QWORD *)(StatusReg + 80) = v24;
    if ( !v0 )
      return (unsigned int)-12;
  }
  v18 = -12;
LABEL_62:
  kfree(v0);
  return v18;
}
