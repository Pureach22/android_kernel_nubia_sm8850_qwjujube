__int64 __fastcall cfg80211_wdev_release_link_bsses(__int64 result, unsigned __int16 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x19
  unsigned int v4; // w20
  unsigned __int64 v5; // x21
  __int64 v6; // x22
  bool v7; // w9
  __int64 v8; // x9
  __int64 v9; // x8
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v20; // w8
  unsigned int v21; // w8

  v2 = *(unsigned __int16 *)(result + 1472);
  v3 = result;
  v4 = 0;
  v5 = a2;
  v6 = 400;
  v7 = *(_WORD *)(result + 1472) == 0;
  do
  {
    if ( v7 || (((unsigned __int64)v2 >> v4) & 1) != 0 )
    {
      v8 = *(_QWORD *)(v3 + v6);
      if ( v8 )
      {
        if ( ((v5 >> v4) & 1) != 0 )
        {
          _X10 = (unsigned int *)(v8 + 80);
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v16 = __ldxr(_X10);
            v17 = v16 - 1;
          }
          while ( __stlxr(v17, _X10) );
          __dmb(0xBu);
          if ( (v17 & 0x80000000) != 0 )
          {
            __break(0x800u);
            v9 = *(_QWORD *)(v8 + 152);
            if ( !v9 )
              goto LABEL_9;
          }
          else
          {
            v9 = *(_QWORD *)(v8 + 152);
            if ( !v9 )
            {
LABEL_9:
              result = cfg80211_put_bss(*(_QWORD *)v3, (_QWORD *)(*(_QWORD *)(v3 + v6) + 112LL));
              *(_QWORD *)(v3 + v6) = 0;
              v2 = *(unsigned __int16 *)(v3 + 1472);
              goto LABEL_10;
            }
          }
          _X9 = (unsigned int *)(v9 - 32);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v20 = __ldxr(_X9);
            v21 = v20 - 1;
          }
          while ( __stlxr(v21, _X9) );
          __dmb(0xBu);
          if ( (v21 & 0x80000000) != 0 )
            __break(0x800u);
          goto LABEL_9;
        }
      }
    }
LABEL_10:
    v7 = v2 == 0;
    if ( !v2 )
      break;
    _CF = v4++ >= 0xE;
    v6 += 72;
  }
  while ( !_CF );
  return result;
}
