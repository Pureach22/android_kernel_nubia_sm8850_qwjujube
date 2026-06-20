__int64 *__fastcall ieee80211_link_copy_chanctx_to_vlans(__int64 *result, char a2)
{
  __int64 v2; // x10
  unsigned __int64 v3; // x11
  __int64 v4; // x8
  _QWORD *v5; // x9
  _QWORD *v6; // x10
  __int64 v7; // x12

  v2 = *result;
  if ( *(_DWORD *)(*result + 4720) == 3 )
  {
    v3 = *(_QWORD *)(result[118] + 832);
    v4 = *((unsigned int *)result + 2);
    if ( !v3 )
      __break(0x800u);
    v5 = *(_QWORD **)(v2 + 2264);
    v6 = (_QWORD *)(v2 + 2264);
    if ( v5 != v6 )
    {
      if ( (a2 & 1) != 0 )
        v3 = 0;
      if ( (unsigned int)v4 <= 0xE )
        goto LABEL_10;
      __break(0x5512u);
LABEL_9:
      __break(0x800u);
      while ( 1 )
      {
        v5 = (_QWORD *)*v5;
        if ( v5 == v6 )
          break;
LABEL_10:
        v7 = v5[v4 + 427];
        if ( !v7 )
          goto LABEL_9;
        atomic_store(v3, (unsigned __int64 *)(v7 + 832));
      }
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
