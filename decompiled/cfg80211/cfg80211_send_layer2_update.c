__int64 __fastcall cfg80211_send_layer2_update(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  __int16 v7; // w9

  result = _netdev_alloc_skb(0, 20, 2080);
  if ( result )
  {
    v5 = result;
    v6 = skb_put(result, 20);
    *(_DWORD *)v6 = -1;
    *(_WORD *)(v6 + 4) = -1;
    *(_DWORD *)(v6 + 6) = *(_DWORD *)a2;
    v7 = *(_WORD *)(a2 + 4);
    *(_WORD *)(v6 + 12) = 1536;
    *(_DWORD *)(v6 + 14) = -2119237376;
    *(_WORD *)(v6 + 18) = 1;
    *(_WORD *)(v6 + 10) = v7;
    *(_QWORD *)(v5 + 16) = a1;
    *(_WORD *)(v5 + 180) = eth_type_trans(v5, a1);
    *(_QWORD *)(v5 + 40) = 0;
    *(_QWORD *)(v5 + 48) = 0;
    *(_QWORD *)(v5 + 56) = 0;
    *(_QWORD *)(v5 + 64) = 0;
    *(_QWORD *)(v5 + 72) = 0;
    *(_QWORD *)(v5 + 80) = 0;
    return netif_rx(v5);
  }
  return result;
}
