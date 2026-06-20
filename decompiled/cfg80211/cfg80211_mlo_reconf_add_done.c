__int64 __fastcall cfg80211_mlo_reconf_add_done(__int64 result, __int64 *a2)
{
  __int64 *v2; // x22
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x2
  __int64 v7; // x20
  __int64 v8; // x21
  int v9; // w8
  __int16 v10; // w8
  __int64 v11; // x23
  _QWORD *v12; // x24
  int **i; // x25
  int v14; // w8
  __int64 v15; // x1
  __int64 v16; // x8
  unsigned int v23; // w8
  unsigned int v24; // w8
  unsigned int v27; // w8
  unsigned int v28; // w8

  v2 = *(__int64 **)(result + 992);
  v3 = *a2;
  v4 = a2[1];
  v5 = *((unsigned __int16 *)a2 + 8);
  v7 = result;
  v8 = *v2;
  if ( *((_WORD *)v2 + 736) )
  {
    v9 = *((_DWORD *)v2 + 2);
    if ( v9 == 8 || v9 == 2 )
    {
      v10 = *((_WORD *)a2 + 8);
      if ( ((v10 & 1) == 0 || a2[3])
        && ((v10 & 2) == 0 || a2[5])
        && ((v10 & 4) == 0 || a2[7])
        && ((v10 & 8) == 0 || a2[9])
        && ((v10 & 0x10) == 0 || a2[11])
        && ((v10 & 0x20) == 0 || a2[13])
        && ((v10 & 0x40) == 0 || a2[15])
        && ((v10 & 0x80) == 0 || a2[17])
        && ((a2[2] & 0x100) == 0 || a2[19])
        && ((a2[2] & 0x200) == 0 || a2[21])
        && ((a2[2] & 0x400) == 0 || a2[23])
        && ((a2[2] & 0x800) == 0 || a2[25])
        && ((a2[2] & 0x1000) == 0 || a2[27])
        && ((a2[2] & 0x2000) == 0 || a2[29])
        && ((a2[2] & 0x4000) == 0 || a2[31]) )
      {
        v11 = 0;
        v12 = v2 + 50;
        for ( i = (int **)(a2 + 4); ; i += 2 )
        {
          v15 = (__int64)*(i - 1);
          if ( v15 )
          {
            if ( (((unsigned __int64)*((unsigned __int16 *)a2 + 8) >> v11) & 1) == 0 )
            {
              _X9 = (unsigned int *)(v15 - 32);
              __asm { PRFM            #0x11, [X9] }
              do
              {
                v23 = __ldxr(_X9);
                v24 = v23 - 1;
              }
              while ( __stlxr(v24, _X9) );
              __dmb(0xBu);
              if ( (v24 & 0x80000000) != 0 )
              {
                __break(0x800u);
                v16 = *(_QWORD *)(v15 + 40);
                if ( !v16 )
                  goto LABEL_42;
              }
              else
              {
                v16 = *(_QWORD *)(v15 + 40);
                if ( !v16 )
                {
LABEL_42:
                  cfg80211_put_bss(v8, v15);
                  goto LABEL_36;
                }
              }
              _X9 = (unsigned int *)(v16 - 32);
              __asm { PRFM            #0x11, [X9] }
              do
              {
                v27 = __ldxr(_X9);
                v28 = v27 - 1;
              }
              while ( __stlxr(v28, _X9) );
              __dmb(0xBu);
              if ( (v28 & 0x80000000) != 0 )
                __break(0x800u);
              goto LABEL_42;
            }
            *v12 = v15 - 112;
            v14 = **i;
            *((_WORD *)v12 - 2) = *((_WORD *)*i + 2);
            *((_DWORD *)v12 - 2) = v14;
          }
LABEL_36:
          ++v11;
          v12 += 9;
          if ( v11 == 15 )
          {
            *((_WORD *)v2 + 736) |= *((_WORD *)a2 + 8);
            return ((__int64 (__fastcall *)(__int64, __int64 *, __int64, __int64, __int64))nl80211_mlo_reconf_add_done)(
                     v7,
                     a2,
                     v5,
                     v3,
                     v4);
          }
        }
      }
    }
  }
  __break(0x800u);
  return result;
}
