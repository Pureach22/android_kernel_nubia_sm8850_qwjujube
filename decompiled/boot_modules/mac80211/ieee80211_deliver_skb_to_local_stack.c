__int64 __fastcall ieee80211_deliver_skb_to_local_stack(__int64 result, __int64 *a2)
{
  __int64 v2; // x9
  int v3; // w10
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x11
  __int64 v7; // x8
  int v8; // w10
  __int64 v9; // x2
  __int64 *v10; // x1

  v2 = a2[3];
  v3 = *(unsigned __int16 *)(result + 180);
  if ( (v3 == *(unsigned __int16 *)(v2 + 1940) || v3 == 51080 && (*(_BYTE *)(v2 + 1943) & 1) == 0)
    && *(_BYTE *)(v2 + 1944) == 1 )
  {
    v4 = result;
    cfg80211_rx_control_port(
      *(_QWORD *)(v2 + 1608),
      result,
      (*(_DWORD *)(result + 64) & 2) == 0,
      *((unsigned int *)a2 + 19));
    return consume_skb(v4);
  }
  *(_QWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 48) = 0;
  v5 = *(_QWORD *)(result + 216);
  v6 = *(unsigned __int16 *)(result + 186);
  *(_QWORD *)(result + 56) = 0;
  *(_QWORD *)(result + 64) = 0;
  *(_QWORD *)(result + 72) = 0;
  *(_QWORD *)(result + 80) = 0;
  if ( v3 == *(unsigned __int16 *)(v2 + 1940) )
  {
    v7 = v5 + v6;
    v8 = *(_DWORD *)(v2 + 5842);
    if ( v8 ^ *(_DWORD *)v7 | *(unsigned __int16 *)(v2 + 5846) ^ *(unsigned __int16 *)(v7 + 4) )
    {
      *(_DWORD *)v7 = v8;
      *(_WORD *)(v7 + 4) = *(_WORD *)(v2 + 5846);
      v9 = *a2;
      if ( *a2 )
        goto LABEL_9;
      return netif_receive_skb(result);
    }
  }
  v9 = *a2;
  if ( !*a2 )
    return netif_receive_skb(result);
LABEL_9:
  v10 = *(__int64 **)(v9 + 8);
  if ( v9 == result || v10 == (__int64 *)result || *v10 != v9 )
    return _list_add_valid_or_report(result, v10);
  *(_QWORD *)(v9 + 8) = result;
  *(_QWORD *)result = v9;
  *(_QWORD *)(result + 8) = v10;
  *v10 = result;
  return result;
}
