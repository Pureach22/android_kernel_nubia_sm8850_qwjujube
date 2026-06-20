__int64 __fastcall ieee80211_recalc_radar_chanctx(__int64 result, __int64 a2)
{
  _QWORD *v2; // x9
  __int64 v4; // x1
  __int64 v5; // x12
  __int64 v6; // x14
  int v7; // w9
  void (*v8)(void); // x9
  __int64 v9; // x19

  v2 = *(_QWORD **)(result + 4616);
  v4 = a2 + 152;
  if ( v2 == (_QWORD *)(result + 4616) )
  {
LABEL_11:
    v7 = 0;
  }
  else
  {
    while ( (v2[204] & 1) == 0 )
    {
LABEL_3:
      v2 = (_QWORD *)*v2;
      if ( v2 == (_QWORD *)(result + 4616) )
        goto LABEL_11;
    }
    v5 = 0;
    while ( 1 )
    {
      v6 = v2[v5 + 571];
      if ( v6 )
      {
        if ( *(_QWORD *)(*(_QWORD *)(v6 + 944) + 832LL) == v4 && (*(_BYTE *)(v6 + 456) & 1) != 0 )
          break;
      }
      if ( ++v5 == 15 )
        goto LABEL_3;
    }
    v7 = 1;
  }
  if ( *(unsigned __int8 *)(a2 + 254) != v7 )
  {
    *(_BYTE *)(a2 + 254) = v7;
    v8 = *(void (**)(void))(*(_QWORD *)(result + 464) + 608LL);
    if ( v8 )
    {
      if ( (*(_BYTE *)(a2 + 84) & 1) == 0 )
      {
        __break(0x800u);
        v8 = *(void (**)(void))(*(_QWORD *)(result + 464) + 608LL);
      }
      v9 = result;
      if ( *((_DWORD *)v8 - 1) != 1043050079 )
        __break(0x8229u);
      v8();
      return v9;
    }
  }
  return result;
}
