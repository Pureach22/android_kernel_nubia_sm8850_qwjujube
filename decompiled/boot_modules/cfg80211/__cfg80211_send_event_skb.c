__int64 __fastcall _cfg80211_send_event_skb(__int64 result, unsigned int a2)
{
  __int16 v2; // w12
  __int16 v3; // w13
  __int64 v4; // x8
  _WORD *v5; // x10
  __int64 v6; // x9
  __int64 v7; // x11
  __int16 v8; // w12
  __int64 v9; // x13
  __int64 v10; // x2
  unsigned int v11; // w10
  __int64 v12; // x4
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // x3

  v2 = *(_DWORD *)(result + 216);
  v3 = *(_DWORD *)(result + 208);
  v4 = result;
  v5 = *(_WORD **)(result + 56);
  *(_QWORD *)(result + 72) = 0;
  *(_QWORD *)(result + 80) = 0;
  v6 = *(_QWORD *)(result + 40);
  v7 = *(_QWORD *)(result + 48);
  v8 = v2 + v3 - (_WORD)v5;
  *(_QWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 48) = 0;
  v9 = *(_QWORD *)(result + 224);
  *(_QWORD *)(result + 56) = 0;
  *(_QWORD *)(result + 64) = 0;
  *v5 = v8;
  *(_DWORD *)(v7 - 20) = *(_DWORD *)(result + 216) + *(_DWORD *)(result + 208) - (v7 - 20);
  v10 = *(unsigned int *)(v9 + 12);
  if ( (_DWORD)v10 )
    return netlink_unicast(*(_QWORD *)(*(_QWORD *)(v6 + 2344) + 288LL), result, v10, 64);
  if ( v5[1] == 197 )
    v11 = 4;
  else
    v11 = 6;
  if ( v11 >= (unsigned __int8)byte_BF570 )
  {
    __break(0x800u);
  }
  else
  {
    v12 = a2;
    v13 = result;
    v14 = *(_QWORD *)(*(_QWORD *)(v6 + 2344) + 288LL);
    v15 = dword_BF5E4 + v11;
    *(_DWORD *)(v4 + 56) = v15;
    return netlink_broadcast_filtered(v14, v13, 0, v15, v12, 0, 0);
  }
  return result;
}
