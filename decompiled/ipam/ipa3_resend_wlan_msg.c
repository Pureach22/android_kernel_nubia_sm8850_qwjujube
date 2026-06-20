__int64 ipa3_resend_wlan_msg()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x8
  _QWORD *v4; // x25
  int v5; // w19
  _QWORD *v6; // x24
  __int64 v7; // x26
  unsigned __int64 v8; // x27
  char *v9; // x22
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  _DWORD *v13; // x0
  _QWORD *v14; // x22
  __int64 v15; // x0
  __int64 v16; // x8
  _QWORD *v17; // x0
  __int64 v18; // x2
  _QWORD *v19; // x1
  unsigned int v20; // w19

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d \n", "ipa3_resend_wlan_msg", 579);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d \n", "ipa3_resend_wlan_msg", 579);
      v0 = ipa3_ctx;
    }
  }
  mutex_lock(v0 + 32168);
  v3 = ipa3_ctx;
  v4 = *(_QWORD **)(ipa3_ctx + 32152);
  if ( v4 == (_QWORD *)(ipa3_ctx + 32152) )
  {
LABEL_28:
    v20 = 0;
  }
  else
  {
    v5 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v7 = *(v4 - 1);
      v6 = (_QWORD *)*v4;
      if ( *(_BYTE *)(v7 + 32) )
      {
        v8 = 0;
        v9 = (char *)(v7 + 41);
        do
        {
          if ( !*(_DWORD *)(v9 - 5) )
          {
            v10 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v11 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v11 )
              {
                ipc_log_string(v11, "ipa %s:%d %d-Mac %pM\n", "ipa3_resend_wlan_msg", 590, v5, v9);
                v10 = ipa3_ctx;
              }
              v12 = *(_QWORD *)(v10 + 34160);
              if ( v12 )
                ipc_log_string(v12, "ipa %s:%d %d-Mac %pM\n", "ipa3_resend_wlan_msg", 590, v5, v9);
            }
          }
          ++v8;
          v9 += 12;
        }
        while ( v8 < *(unsigned __int8 *)(v7 + 32) );
      }
      v13 = (_DWORD *)_kmalloc_cache_noprof(ipc_log_string, 3520, 40);
      v14 = v13;
      if ( !v13 )
        break;
      *v13 = *((_DWORD *)v4 - 6);
      v15 = kmemdup_noprof(*(v4 - 1), *((unsigned __int16 *)v4 - 11), 3264);
      if ( !v15 )
      {
        kfree(v14);
        break;
      }
      v16 = ipa3_ctx;
      v14[1] = ipa_send_msg_free;
      v14[2] = v15;
      mutex_lock(v16 + 32104);
      v17 = v14 + 3;
      v18 = ipa3_ctx + 32072;
      v19 = *(_QWORD **)(ipa3_ctx + 32080);
      if ( v14 + 3 == (_QWORD *)(ipa3_ctx + 32072) || v19 == v17 || *v19 != v18 )
      {
        _list_add_valid_or_report(v17, v19);
      }
      else
      {
        *(_QWORD *)(ipa3_ctx + 32080) = v17;
        v14[3] = v18;
        v14[4] = v19;
        *v19 = v17;
      }
      mutex_unlock(ipa3_ctx + 32104);
      _wake_up(ipa3_ctx + 32216, 3, 1, 0);
      v3 = ipa3_ctx;
      ++v5;
      v4 = v6;
      if ( v6 == (_QWORD *)(ipa3_ctx + 32152) )
        goto LABEL_28;
    }
    v3 = ipa3_ctx;
    v20 = -12;
  }
  mutex_unlock(v3 + 32168);
  return v20;
}
