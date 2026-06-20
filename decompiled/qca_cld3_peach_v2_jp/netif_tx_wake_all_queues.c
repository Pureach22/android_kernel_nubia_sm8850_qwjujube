__int64 __fastcall netif_tx_wake_all_queues(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned __int64 v3; // x21

  if ( *(_DWORD *)(result + 1096) )
  {
    v1 = result;
    v2 = 0;
    v3 = 0;
    do
    {
      result = netif_tx_wake_queue(*(_QWORD *)(v1 + 24) + v2);
      ++v3;
      v2 += 384;
    }
    while ( v3 < *(unsigned int *)(v1 + 1096) );
  }
  return result;
}
