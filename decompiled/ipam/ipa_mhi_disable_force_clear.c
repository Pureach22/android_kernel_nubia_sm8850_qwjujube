__int64 __fastcall ipa_mhi_disable_force_clear(int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_disable_force_clear", 1057);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_disable_force_clear", 1057);
  }
  v12 = a1;
  if ( ipa3_get_ipc_logbuf() )
  {
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa_mhi_client %s:%d req_id=0x%x\n", "ipa_mhi_disable_force_clear", 1060, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v5, "ipa_mhi_client %s:%d req_id=0x%x\n", "ipa_mhi_disable_force_clear", 1060, a1);
  }
  v6 = ipa3_qmi_disable_force_clear_datapath_send((__int64)&v12);
  if ( v6 )
  {
    printk(&unk_3E7EE3, "ipa_mhi_disable_force_clear");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v10,
        "ipa_mhi_client %s:%d ipa3_qmi_disable_force_clear_datapath_send failed %d\n",
        "ipa_mhi_disable_force_clear",
        1065,
        v6);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v11,
        "ipa_mhi_client %s:%d ipa3_qmi_disable_force_clear_datapath_send failed %d\n",
        "ipa_mhi_disable_force_clear",
        1065,
        v6);
    }
  }
  else
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(v7, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_disable_force_clear", 1069);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v8, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_disable_force_clear", 1069);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
