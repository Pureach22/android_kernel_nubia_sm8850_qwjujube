__int64 __fastcall wlan_dp_stc_inc_traffic_type(__int64 result, unsigned int *a2, int a3)
{
  int v3; // w8
  unsigned int v10; // w9
  unsigned int v11; // w9
  unsigned int v14; // w9
  unsigned int v17; // w9
  unsigned int v20; // w9
  unsigned int v23; // w9
  char v24; // w8
  unsigned int v27; // w9

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
          v11 = v20 + 1;
        }
        while ( __stlxr(v11, _X8) );
LABEL_30:
        __dmb(0xBu);
        v24 = 0;
        goto LABEL_14;
      case 7:
        _X8 = a2 + 18;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v27 = __ldxr(_X8);
          v11 = v27 + 1;
        }
        while ( __stlxr(v11, _X8) );
        break;
      case 8:
        _X8 = a2 + 19;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v14 = __ldxr(_X8);
          v11 = v14 + 1;
        }
        while ( __stlxr(v11, _X8) );
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
          v11 = v23 + 1;
        }
        while ( __stlxr(v11, _X8) );
      }
      else
      {
        if ( a3 != 2 )
          return result;
        _X8 = a2 + 16;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v10 = __ldxr(_X8);
          v11 = v10 + 1;
        }
        while ( __stlxr(v11, _X8) );
      }
      goto LABEL_30;
    }
    _X8 = a2 + 14;
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v17 = __ldxr(_X8);
      v11 = v17 + 1;
    }
    while ( __stlxr(v11, _X8) );
  }
  __dmb(0xBu);
  v24 = 1;
LABEL_14:
  if ( *(_BYTE *)(result + 255) == 1 && v11 == 1 )
    a2[22] = 1;
  if ( (unsigned __int8)(v24 & *(_BYTE *)(result + 254)) == 1 )
  {
    v3 = *(unsigned __int16 *)(result + 252);
    *(_WORD *)(result + 252) = v3 + 1;
    if ( !v3 )
      return hif_rtpm_get(0, 0xAu);
  }
  return result;
}
