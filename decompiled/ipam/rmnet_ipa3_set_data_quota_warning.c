__int64 __fastcall rmnet_ipa3_set_data_quota_warning(__int64 a1)
{
  int upstream_type; // w0
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w8
  unsigned int v10; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v13; // w8
  int v14; // w20
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  int v20; // [xsp+4h] [xbp-11Ch] BYREF
  _QWORD s[35]; // [xsp+8h] [xbp-118h] BYREF

  s[34] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 15) = 0;
  upstream_type = find_upstream_type((char *)a1);
  if ( upstream_type == 2 )
  {
    result = rmnet_ipa3_set_data_quota_wifi(a1);
    if ( !(_DWORD)result )
      goto LABEL_3;
    v10 = result;
    printk(&unk_3B6108, "rmnet_ipa3_set_data_quota_warning");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa-wan %s:%d set quota and warning on wifi failed\n",
        "rmnet_ipa3_set_data_quota_warning",
        4653);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d set quota and warning on wifi failed\n",
        "rmnet_ipa3_set_data_quota_warning",
        4653);
    }
LABEL_21:
    result = v10;
    goto LABEL_3;
  }
  if ( upstream_type == 3 )
  {
    printk(&unk_3EA699, "rmnet_ipa3_set_data_quota_warning");
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v4,
        "ipa-wan %s:%d Wrong interface_name name %s\n",
        "rmnet_ipa3_set_data_quota_warning",
        4645,
        (const char *)a1);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v5,
        "ipa-wan %s:%d Wrong interface_name name %s\n",
        "rmnet_ipa3_set_data_quota_warning",
        4645,
        (const char *)a1);
      result = 0;
    }
    goto LABEL_3;
  }
  memset(s, 0, 0x110u);
  *(_BYTE *)(a1 + 15) = 0;
  v6 = ((__int64 (__fastcall *)(__int64))find_vchannel_name_index)(a1);
  printk(&unk_3BF02B, "rmnet_ipa3_set_data_quota_warning_modem");
  if ( ipa3_get_ipc_logbuf() )
  {
    v7 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v7,
      "ipa-wan %s:%d iface name %s, quota %lu, warning %lu\n",
      "rmnet_ipa3_set_data_quota_warning_modem",
      4502,
      (const char *)a1,
      *(_QWORD *)(a1 + 16),
      *(_QWORD *)(a1 + 32));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v8,
      "ipa-wan %s:%d iface name %s, quota %lu, warning %lu\n",
      "rmnet_ipa3_set_data_quota_warning_modem",
      4502,
      (const char *)a1,
      *(_QWORD *)(a1 + 16),
      *(_QWORD *)(a1 + 32));
  }
  if ( v6 == 15 )
  {
    printk(&unk_3F9288, "rmnet_ipa3_set_data_quota_warning_modem");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v16,
        "ipa-wan %s:%d %s is an invalid iface name\n",
        "rmnet_ipa3_set_data_quota_warning_modem",
        4506,
        (const char *)a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v17,
        "ipa-wan %s:%d %s is an invalid iface name\n",
        "rmnet_ipa3_set_data_quota_warning_modem",
        4506,
        (const char *)a1);
    }
    v10 = -19;
    goto LABEL_39;
  }
  v9 = *(unsigned __int8 *)(a1 + 24);
  v20 = 0;
  if ( v9 )
  {
    if ( *(_BYTE *)(a1 + 25) )
      goto LABEL_25;
    goto LABEL_23;
  }
  v13 = *(unsigned __int8 *)(a1 + 25);
  LOWORD(v20) = 257;
  if ( !v13 )
LABEL_23:
    HIWORD(v20) = 257;
  ipa3_qmi_stop_data_quota((__int64)&v20);
LABEL_25:
  if ( v6 > 0xE )
  {
    __break(0x5512u);
    JUMPOUT(0x1449BC);
  }
  v14 = *(_DWORD *)(rmnet_ipa3_ctx + 32LL * v6 + 556);
  dword_201790 = v14;
  memset(s, 0, 0x110u);
  if ( *(_BYTE *)(a1 + 24) && *(_QWORD *)(a1 + 16) )
  {
    s[2] = *(_QWORD *)(a1 + 16);
    LOBYTE(s[0]) = 1;
    HIDWORD(s[0]) = 1;
    LODWORD(s[1]) = v14;
  }
  if ( *(_BYTE *)(a1 + 25) )
  {
    v15 = *(_QWORD *)(a1 + 32);
    if ( v15 )
    {
      LOBYTE(s[17]) = 1;
      HIDWORD(s[17]) = 1;
      LODWORD(s[18]) = v14;
      s[19] = v15;
    }
  }
  result = ipa3_qmi_set_data_quota((__int64)s);
  if ( (_DWORD)result )
  {
    v10 = result;
LABEL_39:
    printk(&unk_3C1FB2, "rmnet_ipa3_set_data_quota_warning");
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v18,
        "ipa-wan %s:%d set quota and warning on modem failed\n",
        "rmnet_ipa3_set_data_quota_warning",
        4659);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v19,
        "ipa-wan %s:%d set quota and warning on modem failed\n",
        "rmnet_ipa3_set_data_quota_warning",
        4659);
    }
    goto LABEL_21;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
