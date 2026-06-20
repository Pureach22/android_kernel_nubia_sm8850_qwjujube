__int64 __fastcall ipa_uc_offload_ntn_register_pm_client(_DWORD *a1)
{
  int v2; // w8
  unsigned int *v3; // x19
  bool v4; // zf
  const char *v5; // x8
  unsigned int v6; // w0
  unsigned int v7; // w1
  __int64 result; // x0
  unsigned int v9; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v12; // w21
  __int64 v13; // x0
  long double v14; // q0
  __int64 v15; // x0
  _QWORD v16[5]; // [xsp+8h] [xbp-28h] BYREF

  v16[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1 + 26;
  v2 = *a1;
  v16[2] = a1;
  v16[3] = 0;
  v4 = v2 == 3;
  v5 = "ETH_v2x";
  if ( !v4 )
    v5 = "ETH";
  v16[0] = v5;
  v16[1] = ipa_uc_offload_ntn_pm_cb;
  v6 = ipa_pm_register((__int64)v16, v3);
  if ( v6 )
  {
    v9 = v6;
    printk(&unk_3DCF37, "ipa_uc_offload_ntn_register_pm_client");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_uc_offload %s:%d fail to register with PM %d\n",
        "ipa_uc_offload_ntn_register_pm_client",
        133,
        v9);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_uc_offload %s:%d fail to register with PM %d\n",
        "ipa_uc_offload_ntn_register_pm_client",
        133,
        v9);
    }
    result = v9;
  }
  else
  {
    if ( *a1 == 3 )
      v7 = 117;
    else
      v7 = 49;
    result = ipa_pm_associate_ipa_cons_to_client(a1[26], v7);
    if ( (_DWORD)result )
    {
      v12 = result;
      printk(&unk_3F9B96, "ipa_uc_offload_ntn_register_pm_client");
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v13,
          "ipa_uc_offload %s:%d fail to associate. PM (%d) Prot: %d\n",
          "ipa_uc_offload_ntn_register_pm_client",
          144,
          v12,
          *a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v15 = ipa3_get_ipc_logbuf_low();
        v14 = ipc_log_string(
                v15,
                "ipa_uc_offload %s:%d fail to associate. PM (%d) Prot: %d\n",
                "ipa_uc_offload_ntn_register_pm_client",
                144,
                v12,
                *a1);
      }
      ((void (__fastcall *)(_QWORD, long double))ipa_pm_deregister)(*v3, v14);
      result = v12;
      *v3 = -1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
