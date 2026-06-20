__int64 __fastcall ipa_eth_get_ipa_client_type_from_pipe(__int64 a1)
{
  _DWORD *v1; // x19
  int v2; // w3
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  if ( !a1 )
  {
    printk(&unk_3D9A89, "ipa_eth_get_ipa_client_type_from_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_eth %s:%d invalid pipe\n", "ipa_eth_get_ipa_client_type_from_pipe", 358);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_eth %s:%d invalid pipe\n", "ipa_eth_get_ipa_client_type_from_pipe", 358);
    }
    return 134;
  }
  v1 = *(_DWORD **)(a1 + 160);
  if ( !v1 )
  {
    printk(&unk_3B9679, "ipa_eth_get_ipa_client_type_from_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v6 = ipa3_get_ipc_logbuf();
      ipc_log_string(v6, "ipa_eth %s:%d invalid client\n", "ipa_eth_get_ipa_client_type_from_pipe", 364);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v7 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v7, "ipa_eth %s:%d invalid client\n", "ipa_eth_get_ipa_client_type_from_pipe", 364);
    }
    return 134;
  }
  v2 = *v1;
  if ( *v1 > 5u )
  {
    printk(&unk_3D0FA3, "ipa_eth_get_ipa_client_type_from_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(v8, "ipa_eth %s:%d invalid client type%d\n", "ipa_eth_get_ipa_client_type_from_pipe", 431, *v1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v9, "ipa_eth %s:%d invalid client type%d\n", "ipa_eth_get_ipa_client_type_from_pipe", 431, *v1);
    }
    return 134;
  }
  if ( ((1 << v2) & 3) != 0 )
  {
    if ( v1[2] || *((_BYTE *)v1 + 4) )
      return 134;
    if ( *(_DWORD *)(a1 + 16) )
      return 102;
    else
      return 103;
  }
  else
  {
    if ( ((1 << v2) & 0xC) != 0 )
    {
      if ( !v1[2] && !*((_BYTE *)v1 + 4) )
      {
        if ( *(_DWORD *)(a1 + 16) )
          return 108;
        else
          return 109;
      }
      return 134;
    }
    if ( v1[2] || *((_BYTE *)v1 + 4) )
      return 134;
    if ( *(_DWORD *)(a1 + 16) )
      return 48;
    else
      return 49;
  }
}
