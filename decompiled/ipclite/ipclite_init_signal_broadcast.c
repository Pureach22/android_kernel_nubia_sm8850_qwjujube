__int64 ipclite_init_signal_broadcast()
{
  __int64 v0; // x19
  __int64 result; // x0
  unsigned int v2; // w20

  if ( *(_DWORD *)(ipclite + 704) != 2 )
    return 0;
  v0 = *(_QWORD *)(ipclite + 200);
  result = mbox_send_message(v0, 0);
  if ( (result & 0x80000000) == 0 )
  {
    v2 = result;
    mbox_client_txdone(v0, 0);
    return v2;
  }
  return result;
}
