__int64 __fastcall cfg80211_connect_result_release_bsses(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  __int64 *v4; // x20
  unsigned int v5; // w21
  _QWORD **v6; // x22
  bool v7; // w9
  __int64 v8; // x9
  __int64 v9; // x8
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v20; // w8
  unsigned int v21; // w8

  v2 = *(unsigned __int16 *)(a2 + 104);
  v4 = (__int64 *)result;
  v5 = 0;
  v6 = (_QWORD **)(a2 + 128);
  v7 = *(_WORD *)(a2 + 104) == 0;
  do
  {
    if ( v7 || (((unsigned __int64)v2 >> v5) & 1) != 0 )
    {
      v8 = (__int64)*v6;
      if ( *v6 )
      {
        _X10 = (unsigned int *)(v8 - 32);
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
          v9 = *(_QWORD *)(v8 + 40);
          if ( !v9 )
            goto LABEL_8;
        }
        else
        {
          v9 = *(_QWORD *)(v8 + 40);
          if ( !v9 )
          {
LABEL_8:
            result = cfg80211_put_bss(*v4, *v6);
            v2 = *(unsigned __int16 *)(a2 + 104);
            goto LABEL_9;
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
        goto LABEL_8;
      }
    }
LABEL_9:
    v7 = v2 == 0;
    if ( !v2 )
      break;
    _CF = v5++ >= 0xE;
    v6 += 4;
  }
  while ( !_CF );
  return result;
}
