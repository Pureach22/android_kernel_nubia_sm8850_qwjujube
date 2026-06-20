__int64 __fastcall ieee80211_txq_init(__int64 result, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x8
  __int64 v5; // x9

  *(_QWORD *)a3 = a3;
  *(_QWORD *)(a3 + 8) = a3;
  *(_QWORD *)(a3 + 16) = a3 + 16;
  *(_QWORD *)(a3 + 24) = a3 + 16;
  *(_QWORD *)(a3 + 32) = a3 + 32;
  *(_QWORD *)(a3 + 40) = a3 + 32;
  *(_QWORD *)(a3 + 56) = a3 + 56;
  *(_QWORD *)(a3 + 64) = a3 + 56;
  *(_QWORD *)(a3 + 72) = a3 + 72;
  *(_QWORD *)(a3 + 80) = a3 + 72;
  *(_QWORD *)(a3 + 200) = a3 + 200;
  *(_QWORD *)(a3 + 208) = a3 + 200;
  *(_DWORD *)(a3 + 88) = 0;
  *(_QWORD *)(a3 + 136) = 0;
  *(_QWORD *)(a3 + 144) = 0;
  *(_QWORD *)(a3 + 152) = 0;
  *(_DWORD *)(a3 + 160) = 0;
  *(_DWORD *)(a3 + 216) = 0;
  *(_QWORD *)(a3 + 184) = a3 + 184;
  *(_QWORD *)(a3 + 192) = a3 + 184;
  *(_QWORD *)(a3 + 232) = result + 4720;
  v4 = a3 + 232;
  if ( !a2 )
  {
    *(_QWORD *)(result + 5856) = v4;
    *(_WORD *)(a3 + 248) = 512;
    return result;
  }
  if ( a4 == 16 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(result + 1616) + 96LL);
    if ( *(_DWORD *)(result + 4720) == 2 )
    {
      if ( (v5 & 0x80000000000LL) == 0 )
        return result;
      goto LABEL_10;
    }
  }
  else
  {
    v5 = ieee802_1d_to_ac[a4 & 7];
    *(_QWORD *)(a3 + 240) = a2 + 2688;
    *(_BYTE *)(a3 + 249) = v5;
    *(_BYTE *)(a3 + 248) = a4;
    if ( a4 < 0x11 )
    {
LABEL_11:
      *(_QWORD *)(a2 + 8LL * a4 + 2736) = v4;
      return result;
    }
    __break(0x5512u);
  }
  if ( (v5 & 0x20000000000LL) != 0 )
  {
LABEL_10:
    *(_QWORD *)(a3 + 240) = a2 + 2688;
    *(_WORD *)(a3 + 248) = 16;
    goto LABEL_11;
  }
  return result;
}
