void ipa3_wake_tx_queue()
{
  __int64 v0; // x8
  __int64 v1; // x20
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x8
  __int64 v7; // x8

  if ( rmnet_ipa3_ctx )
  {
    if ( *(_QWORD *)rmnet_ipa3_ctx )
    {
      v0 = **(_QWORD **)rmnet_ipa3_ctx;
      if ( v0 )
      {
        v1 = *(_QWORD *)(v0 + 24);
        raw_spin_lock_bh(v1 + 320);
        *(_DWORD *)(v1 + 324) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(ipc_logbuf, "ipa-wan %s:%d Waking up the workqueue.\n", "ipa3_wake_tx_queue", 3493);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          v3 = ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d Waking up the workqueue.\n", "ipa3_wake_tx_queue", 3493);
        }
        v5 = (_QWORD *)rmnet_ipa3_ctx;
        if ( rmnet_ipa3_ctx )
        {
          v5 = *(_QWORD **)rmnet_ipa3_ctx;
          if ( *(_QWORD *)rmnet_ipa3_ctx )
            v5 = (_QWORD *)*v5;
        }
        netif_tx_wake_queue(v5[3], v3);
        v6 = (_QWORD *)rmnet_ipa3_ctx;
        if ( rmnet_ipa3_ctx )
        {
          v6 = *(_QWORD **)rmnet_ipa3_ctx;
          if ( *(_QWORD *)rmnet_ipa3_ctx )
            v6 = (_QWORD *)*v6;
        }
        v7 = v6[3];
        *(_DWORD *)(v7 + 324) = -1;
        raw_spin_unlock_bh(v7 + 320);
      }
    }
  }
}
