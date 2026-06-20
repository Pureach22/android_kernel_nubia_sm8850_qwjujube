__int64 __fastcall rmnet_ctl_send_client(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  unsigned int v4; // w8
  __int64 v5; // x4
  __int64 (*v6)(void); // x8
  __int64 v7; // x0

  if ( qword_6B08 == a1 )
  {
    _rcu_read_lock();
    if ( (unsigned __int8)ipc_log_lvl >= 2u && qword_6B20 )
    {
      if ( *(_QWORD *)(a2 + 224) && (v4 = *(_DWORD *)(a2 + 112)) != 0 )
      {
        if ( v4 >= 0x20 )
          v5 = 32;
        else
          v5 = v4;
        ipc_log_string(qword_6B20, "%3s(%d): %*ph\n", "TX", 0, v5);
      }
      else
      {
        ipc_log_string(qword_6B20, "%3s(%d): (null)\n", "TX", 0);
      }
    }
    if ( ctl_ep && (v6 = *(__int64 (**)(void))ctl_ep) != nullptr )
    {
      if ( *((_DWORD *)v6 - 1) != 1576281851 )
        __break(0x8228u);
      v7 = v6();
      v2 = v7;
      if ( !(_DWORD)v7 || !ipc_log_lvl )
        goto LABEL_22;
    }
    else
    {
      v7 = sk_skb_reason_drop(0, a2, 2);
      v2 = -22;
      if ( !ipc_log_lvl )
      {
LABEL_22:
        _rcu_read_unlock(v7);
        return v2;
      }
    }
    v7 = qword_6B20;
    if ( qword_6B20 )
      v7 = ipc_log_string(qword_6B20, "%3s(%d): (null)\n", "TXE", v2);
    goto LABEL_22;
  }
  sk_skb_reason_drop(0, a2, 2);
  return (unsigned int)-22;
}
