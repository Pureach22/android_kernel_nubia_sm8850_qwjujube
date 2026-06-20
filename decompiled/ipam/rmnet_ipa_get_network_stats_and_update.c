unsigned __int16 *rmnet_ipa_get_network_stats_and_update()
{
  unsigned __int16 *result; // x0
  unsigned __int16 *v1; // x19
  unsigned int network_stats; // w0
  unsigned int v3; // w20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v10[6]; // [xsp+10h] [xbp-30h] BYREF

  v10[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (unsigned __int16 *)_kmalloc_cache_noprof(scnprintf, 3520, 336);
  v1 = result;
  if ( result )
  {
    memset(&v10[2], 0, 24);
    v10[0] = 0x100000001LL;
    memset(result, 0, 0x150u);
    v10[1] = (unsigned int)dword_201790;
    network_stats = ipa3_qmi_get_network_stats((__int64)v10, v1);
    if ( network_stats )
    {
      v3 = network_stats;
      printk(&unk_3CDB93, "rmnet_ipa_get_network_stats_and_update");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa-wan %s:%d ipa3_qmi_get_network_stats failed: %d\n",
          "rmnet_ipa_get_network_stats_and_update",
          4334,
          v3);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa-wan %s:%d ipa3_qmi_get_network_stats failed: %d\n",
          "rmnet_ipa_get_network_stats_and_update",
          4334,
          v3);
      }
    }
    else
    {
      v9 = 22020118;
      result = (unsigned __int16 *)ipa_send_msg((unsigned __int8 *)&v9, v1, rmnet_ipa_free_msg);
      if ( !(_DWORD)result )
        goto LABEL_4;
      v6 = (unsigned int)result;
      printk(&unk_3EA6F6, "rmnet_ipa_get_network_stats_and_update");
      if ( ipa3_get_ipc_logbuf() )
      {
        v7 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v7,
          "ipa-wan %s:%d ipa_send_msg failed: %d\n",
          "rmnet_ipa_get_network_stats_and_update",
          4344,
          v6);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v8 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v8,
          "ipa-wan %s:%d ipa_send_msg failed: %d\n",
          "rmnet_ipa_get_network_stats_and_update",
          4344,
          v6);
      }
    }
    result = (unsigned __int16 *)kfree(v1);
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
