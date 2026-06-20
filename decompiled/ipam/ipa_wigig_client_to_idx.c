__int64 __fastcall ipa_wigig_client_to_idx(int a1, _DWORD *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 > 90 )
  {
    if ( a1 == 91 )
    {
      *a2 = 3;
      return 0;
    }
    if ( a1 == 93 )
    {
      *a2 = 4;
      return 0;
    }
  }
  else
  {
    if ( a1 == 87 )
    {
      *a2 = 1;
      return 0;
    }
    if ( a1 == 89 )
    {
      *a2 = 2;
      return 0;
    }
  }
  printk(&unk_3D4646, "ipa_wigig_client_to_idx");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d invalid client %d\n", "ipa_wigig_client_to_idx", 723, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d invalid client %d\n", "ipa_wigig_client_to_idx", 723, a1);
  }
  return 4294967274LL;
}
