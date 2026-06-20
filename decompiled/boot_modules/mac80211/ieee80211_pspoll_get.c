__int64 __fastcall ieee80211_pspoll_get(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x9
  __int64 v8; // x8
  int v9; // w10

  if ( *(_DWORD *)a2 == 2 )
  {
    v3 = *(_QWORD *)(a2 - 3104);
    result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v3 + 104) + 16), 2080);
    if ( result )
    {
      v5 = *(int *)(v3 + 104);
      v6 = result;
      v7 = *(_QWORD *)(result + 224) + v5;
      LODWORD(v5) = *(_DWORD *)(result + 208) + v5;
      *(_QWORD *)(result + 224) = v7;
      *(_DWORD *)(result + 208) = v5;
      v8 = skb_put(result, 16);
      *(_QWORD *)(v8 + 2) = 0;
      result = v6;
      *(_QWORD *)(v8 + 8) = 0;
      *(_WORD *)v8 = 164;
      *(_WORD *)(v8 + 2) = *(_WORD *)(a2 + 12) | 0xC000;
      v9 = *(_DWORD *)(a2 - 568);
      *(_WORD *)(v8 + 8) = *(_WORD *)(a2 - 564);
      *(_DWORD *)(v8 + 4) = v9;
      LOWORD(v9) = *(_WORD *)(a2 + 1126);
      *(_DWORD *)(v8 + 10) = *(_DWORD *)(a2 + 1122);
      *(_WORD *)(v8 + 14) = v9;
    }
  }
  else
  {
    __break(0x800u);
    return 0;
  }
  return result;
}
