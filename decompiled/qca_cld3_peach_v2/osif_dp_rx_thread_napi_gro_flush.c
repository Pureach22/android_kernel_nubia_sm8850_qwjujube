__int64 __fastcall osif_dp_rx_thread_napi_gro_flush(__int64 result, int a2)
{
  __int64 v2; // x19

  if ( *(_QWORD *)(result + 40) )
  {
    v2 = result;
    if ( a2 != 2 )
      result = napi_gro_flush(result, 0);
    if ( *(_DWORD *)(v2 + 280) )
    {
      result = netif_receive_skb_list(v2 + 264);
      *(_QWORD *)(v2 + 264) = v2 + 264;
      *(_QWORD *)(v2 + 272) = v2 + 264;
      *(_DWORD *)(v2 + 280) = 0;
    }
  }
  return result;
}
