__int64 ipa3_wwan_add_ul_flt_rule_to_ipa()
{
  __int64 v0; // x19
  _DWORD *v1; // x0
  __int64 v2; // x24
  __int64 v3; // x27
  _BYTE *v4; // x8
  int v5; // w23
  int v6; // w26
  char v7; // w25
  int v8; // w21
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x9
  int v12; // w21
  __int64 v13; // x0
  __int64 v14; // x0
  int ep_mapping; // w0
  __int64 v16; // x8
  int v17; // w9
  __int64 v18; // x9
  int *v19; // x11
  int v20; // t1
  __int64 v21; // x20
  unsigned int v22; // w22
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v30; // x21
  __int64 (*v31)(_QWORD, _QWORD, const char *, ...); // x0
  int v33; // [xsp+4h] [xbp-17Ch]
  _DWORD *v34; // [xsp+8h] [xbp-178h]
  _QWORD src[45]; // [xsp+18h] [xbp-168h] BYREF

  src[43] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = _kmalloc_cache_noprof(scnprintf, 3520, 388);
  if ( !v0 )
  {
LABEL_42:
    v22 = -12;
    goto LABEL_45;
  }
  while ( 1 )
  {
    v1 = (_DWORD *)_kmalloc_cache_noprof(__ratelimit, 3520, 1908);
    if ( !v1 )
    {
      v22 = -12;
      v21 = v0;
      goto LABEL_44;
    }
    *(_BYTE *)v0 = 1;
    *(_DWORD *)(v0 + 8) = 34;
    *(_WORD *)(v0 + 12) = 256;
    v34 = v1;
    memset(v1, 0, 0x774u);
    if ( *(int *)(rmnet_ipa3_ctx + 1036) >= 1 )
    {
      v2 = 1890;
      v3 = 212;
      v33 = 0;
      while ( v2 != 1925 )
      {
        memset(src, 0, 80);
        v4 = (_BYTE *)(ipa3_qmi_ctx + v3);
        *(_DWORD *)(v0 + 4) = *(_DWORD *)(ipa3_qmi_ctx + v3 - 212);
        v5 = *((_DWORD *)v4 - 6);
        v6 = *((_DWORD *)v4 - 5);
        v7 = *v4;
        v8 = *((_DWORD *)v4 - 1);
        memset(&src[10], 0, 80);
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipa-wan %s:%d install-IPA index(%d),rt-tbl:(%d)\n",
            "ipa3_wwan_add_ul_flt_rule_to_ipa",
            1049,
            v2 - 1890,
            v6);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d install-IPA index(%d),rt-tbl:(%d)\n",
            "ipa3_wwan_add_ul_flt_rule_to_ipa",
            1049,
            v2 - 1890,
            v6);
        }
        memcpy((char *)&src[19] + 4, (const void *)(ipa3_qmi_ctx + v3 - 208), 0xB8u);
        *(_BYTE *)(v0 + 16) = 1;
        *(_WORD *)(v0 + 17) = 0;
        *(_BYTE *)(v0 + 19) = 0;
        *(_DWORD *)(v0 + 20) = v5;
        memcpy((void *)(v0 + 24), src, 0x154u);
        *(_DWORD *)(v0 + 364) = v6;
        *(_WORD *)(v0 + 368) = 1;
        *(_BYTE *)(v0 + 370) = v7;
        *(_BYTE *)(v0 + 371) = 0;
        *(_WORD *)(v0 + 372) = v8;
        *(_WORD *)(v0 + 374) = 0;
        *(_BYTE *)(v0 + 376) = 1;
        *(_QWORD *)(v0 + 377) = 0;
        *(_DWORD *)(v0 + 384) = 0;
        if ( (unsigned int)ipa3_add_flt_rule(v0) )
        {
          v12 = v2 - 1890;
          printk(&unk_3D3E62, "ipa3_wwan_add_ul_flt_rule_to_ipa");
          if ( ipa3_get_ipc_logbuf() )
          {
            v13 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v13,
              "ipa-wan %s:%d add A7 UL filter rule(%d) failed\n",
              "ipa3_wwan_add_ul_flt_rule_to_ipa",
              1058,
              v12);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v14 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v14,
              "ipa-wan %s:%d add A7 UL filter rule(%d) failed\n",
              "ipa3_wwan_add_ul_flt_rule_to_ipa",
              1058,
              v12);
          }
          v33 = -14;
        }
        else
        {
          *(_DWORD *)(ipa3_qmi_ctx + 4 * v2) = *(_DWORD *)(v0 + 380);
        }
        v11 = v2 - 1889;
        ++v2;
        v3 += 216;
        if ( v11 >= *(int *)(rmnet_ipa3_ctx + 1036) )
          goto LABEL_20;
      }
      goto LABEL_41;
    }
    v33 = 0;
LABEL_20:
    ep_mapping = ipa_get_ep_mapping(34);
    *v34 = ep_mapping;
    if ( ep_mapping == -1 )
    {
      printk(&unk_3FC6D4, "ipa3_wwan_add_ul_flt_rule_to_ipa");
      if ( ipa3_get_ipc_logbuf() )
      {
        v27 = ipa3_get_ipc_logbuf();
        ipc_log_string(v27, "ipa-wan %s:%d ep mapping failed\n", "ipa3_wwan_add_ul_flt_rule_to_ipa", 1070);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v28 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v28, "ipa-wan %s:%d ep mapping failed\n", "ipa3_wwan_add_ul_flt_rule_to_ipa", 1070);
      }
      v33 = -14;
    }
    v16 = rmnet_ipa3_ctx;
    v34[1] = 0;
    *((_BYTE *)v34 + 572) = 1;
    v17 = *(_DWORD *)(v16 + 1036);
    v34[144] = v17;
    if ( v17 < 1 )
      break;
    v18 = 0;
    v19 = (int *)(ipa3_qmi_ctx + 208);
    while ( v18 != 35 )
    {
      v20 = *v19;
      v19 += 54;
      v34[v18++ + 145] = v20;
      if ( v18 >= *(int *)(v16 + 1036) )
        goto LABEL_25;
    }
LABEL_41:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v30 = *(_QWORD *)(StatusReg + 80);
    v31 = scnprintf;
    *(_QWORD *)(StatusReg + 80) = &ipa3_wwan_add_ul_flt_rule_to_ipa__alloc_tag;
    v0 = _kmalloc_cache_noprof(v31, 3520, 388);
    *(_QWORD *)(StatusReg + 80) = v30;
    if ( !v0 )
      goto LABEL_42;
  }
LABEL_25:
  v21 = (__int64)v34;
  v22 = v33;
  if ( (unsigned int)((__int64 (__fastcall *)(_DWORD *))ipa3_qmi_filter_notify_send)(v34) )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v23,
        "ipa-wan %s:%d add filter rule index on A7-RX failed\n",
        "ipa3_wwan_add_ul_flt_rule_to_ipa",
        1082);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v24,
        "ipa-wan %s:%d add filter rule index on A7-RX failed\n",
        "ipa3_wwan_add_ul_flt_rule_to_ipa",
        1082);
    }
    v22 = -14;
  }
  *(_DWORD *)(rmnet_ipa3_ctx + 1040) = *(_DWORD *)(rmnet_ipa3_ctx + 1036);
  if ( ipa3_get_ipc_logbuf() )
  {
    v25 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v25,
      "ipa-wan %s:%d add (%d) filter rule index on A7-RX\n",
      "ipa3_wwan_add_ul_flt_rule_to_ipa",
      1087,
      *(_DWORD *)(rmnet_ipa3_ctx + 1040));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v26 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v26,
      "ipa-wan %s:%d add (%d) filter rule index on A7-RX\n",
      "ipa3_wwan_add_ul_flt_rule_to_ipa",
      1087,
      *(_DWORD *)(rmnet_ipa3_ctx + 1040));
  }
  kfree(v0);
LABEL_44:
  kfree(v21);
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return v22;
}
