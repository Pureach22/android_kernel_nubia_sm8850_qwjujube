__int64 __fastcall rmnet_ipa3_set_data_quota(__int64 a1)
{
  int upstream_type; // w0
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  int v6; // w8
  unsigned int v7; // w20
  __int64 v8; // x0
  char *v9; // x0
  __int64 v10; // x0
  __int64 v11; // x9
  unsigned int v12; // w8
  unsigned int v13; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
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
    {
LABEL_3:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v13 = result;
    printk(&unk_3C1F88, "rmnet_ipa3_set_data_quota");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa-wan %s:%d set quota on wifi failed\n", "rmnet_ipa3_set_data_quota", 4602);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d set quota on wifi failed\n", "rmnet_ipa3_set_data_quota", 4602);
    }
LABEL_23:
    result = v13;
    goto LABEL_3;
  }
  if ( upstream_type == 3 )
  {
    printk(&unk_3EA699, "rmnet_ipa3_set_data_quota");
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v4,
        "ipa-wan %s:%d Wrong interface_name name %s\n",
        "rmnet_ipa3_set_data_quota",
        4598,
        (const char *)a1);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v5,
        "ipa-wan %s:%d Wrong interface_name name %s\n",
        "rmnet_ipa3_set_data_quota",
        4598,
        (const char *)a1);
      result = 0;
    }
    goto LABEL_3;
  }
  memset(s, 0, 0x110u);
  v6 = *(unsigned __int8 *)(a1 + 24);
  v20 = 0;
  if ( !v6 )
  {
    LOWORD(v20) = 257;
    ipa3_qmi_stop_data_quota((__int64)&v20);
  }
  *(_BYTE *)(a1 + 15) = 0;
  v7 = ((__int64 (__fastcall *)(__int64))find_vchannel_name_index)(a1);
  printk(&unk_3BF001, "rmnet_ipa3_set_data_quota_modem");
  if ( ipa3_get_ipc_logbuf() )
  {
    v8 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v8,
      "ipa-wan %s:%d iface name %s, quota %lu\n",
      "rmnet_ipa3_set_data_quota_modem",
      4451,
      (const char *)a1,
      *(_QWORD *)(a1 + 16));
  }
  v9 = (char *)ipa3_get_ipc_logbuf_low();
  if ( v9 )
  {
    v10 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v10,
      "ipa-wan %s:%d iface name %s, quota %lu\n",
      "rmnet_ipa3_set_data_quota_modem",
      4451,
      (const char *)a1,
      *(_QWORD *)(a1 + 16));
  }
  if ( v7 == 15 )
  {
    printk(&unk_3F9288, "rmnet_ipa3_set_data_quota_modem");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v16,
        "ipa-wan %s:%d %s is an invalid iface name\n",
        "rmnet_ipa3_set_data_quota_modem",
        4455,
        (const char *)a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v17,
        "ipa-wan %s:%d %s is an invalid iface name\n",
        "rmnet_ipa3_set_data_quota_modem",
        4455,
        (const char *)a1);
    }
    v13 = -19;
LABEL_29:
    printk(&unk_3ADCD2, "rmnet_ipa3_set_data_quota");
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(v18, "ipa-wan %s:%d set quota on modem failed\n", "rmnet_ipa3_set_data_quota", 4608);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v19, "ipa-wan %s:%d set quota on modem failed\n", "rmnet_ipa3_set_data_quota", 4608);
    }
    goto LABEL_23;
  }
  if ( v7 < 0xF )
  {
    dword_201790 = *(_DWORD *)(rmnet_ipa3_ctx + 32LL * v7 + 556);
    memset(s, 0, 0x110u);
    v11 = *(_QWORD *)(a1 + 16);
    LOBYTE(s[0]) = 1;
    HIDWORD(s[0]) = 1;
    LODWORD(s[1]) = dword_201790;
    s[2] = v11;
    v12 = ipa3_qmi_set_data_quota((__int64)s);
    result = 0;
    if ( !v12 )
      goto LABEL_3;
    v13 = v12;
    goto LABEL_29;
  }
  __break(0x5512u);
  return find_upstream_type(v9);
}
