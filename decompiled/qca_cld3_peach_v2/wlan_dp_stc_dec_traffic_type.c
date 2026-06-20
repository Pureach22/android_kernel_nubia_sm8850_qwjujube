__int64 __fastcall wlan_dp_stc_dec_traffic_type(__int64 result, unsigned int *a2, int a3)
{
  unsigned int v9; // w9
  unsigned int v10; // w9
  char v12; // w8
  unsigned int v14; // w9
  unsigned int v17; // w9
  unsigned int v20; // w9
  unsigned int v23; // w9
  unsigned int v26; // w9

  if ( a3 > 2 )
  {
    switch ( a3 )
    {
      case 3:
        _X8 = a2 + 17;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v20 = __ldxr(_X8);
          v10 = v20 - 1;
        }
        while ( __stlxr(v10, _X8) );
LABEL_31:
        __dmb(0xBu);
        v12 = 0;
        goto LABEL_14;
      case 7:
        _X10 = a2 + 18;
        v12 = 1;
        __asm { PRFM            #0x11, [X10] }
        do
        {
          v26 = __ldxr(_X10);
          v10 = v26 - 1;
        }
        while ( __stlxr(v10, _X10) );
        break;
      case 8:
        _X10 = a2 + 19;
        v12 = 1;
        __asm { PRFM            #0x11, [X10] }
        do
        {
          v14 = __ldxr(_X10);
          v10 = v14 - 1;
        }
        while ( __stlxr(v10, _X10) );
        break;
      default:
        return result;
    }
  }
  else
  {
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        _X8 = a2 + 15;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v23 = __ldxr(_X8);
          v10 = v23 - 1;
        }
        while ( __stlxr(v10, _X8) );
      }
      else
      {
        if ( a3 != 2 )
          return result;
        _X8 = a2 + 16;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v9 = __ldxr(_X8);
          v10 = v9 - 1;
        }
        while ( __stlxr(v10, _X8) );
      }
      goto LABEL_31;
    }
    _X10 = a2 + 14;
    v12 = 1;
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v17 = __ldxr(_X10);
      v10 = v17 - 1;
    }
    while ( __stlxr(v10, _X10) );
  }
  __dmb(0xBu);
LABEL_14:
  if ( *(_BYTE *)(result + 255) == 1 && !v10 )
    a2[22] = 1;
  if ( (unsigned __int8)(v12 & *(_BYTE *)(result + 254)) == 1 && --*(_WORD *)(result + 252) == 0 )
    return hif_rtpm_put(4, 0xAu);
  return result;
}
