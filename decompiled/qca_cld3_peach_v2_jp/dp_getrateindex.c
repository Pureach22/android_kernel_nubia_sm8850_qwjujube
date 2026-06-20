__int64 __fastcall dp_getrateindex(
        int a1,
        unsigned __int16 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        __int64 a6,
        unsigned int *a7,
        _WORD *a8)
{
  int v8; // w19
  unsigned int v9; // w8
  __int64 v10; // x9
  unsigned int v11; // w8
  unsigned __int8 *v12; // x8
  __int64 result; // x0
  int v14; // w9
  int v15; // w10
  bool v16; // zf
  char *v17; // x11

  v9 = 1;
  *a8 = 0;
  if ( a4 <= 2u )
  {
    if ( a4 == 1 )
    {
      v11 = a2 & 0xFFFB;
      if ( v11 <= 0x323 )
        goto LABEL_27;
      goto LABEL_25;
    }
    if ( a4 == 2 )
    {
      v10 = 3;
      if ( !a5 )
        v10 = 2;
      v11 = 8 * a3 + a2 + rc_idx[v10];
      if ( v11 <= 0x323 )
      {
LABEL_27:
        if ( a1 > 1 )
        {
          if ( a1 == 2 )
          {
            v17 = (char *)&dp_11abgnratetable + 36 * v11 + 16;
          }
          else
          {
            v16 = a1 == 3;
            result = 0;
            if ( !v16 )
              goto LABEL_39;
            v17 = (char *)&dp_11abgnratetable + 36 * v11 + 20;
          }
        }
        else if ( a1 )
        {
          v16 = a1 == 1;
          result = 0;
          if ( !v16 )
            goto LABEL_39;
          v17 = (char *)&dp_11abgnratetable + 36 * v11 + 12;
        }
        else
        {
          v17 = (char *)&dp_11abgnratetable + 36 * v11 + 28;
        }
        result = *(unsigned int *)v17;
LABEL_39:
        *a8 = *((_WORD *)&dp_11abgnratetable + 18 * v11 + 16);
        *a7 = v11;
        return result;
      }
LABEL_25:
      *a7 = v11;
      return 0;
    }
LABEL_18:
    v11 = rc_idx[v9];
    switch ( a4 )
    {
      case 0u:
        v11 += a2;
        if ( v11 <= 0x323 )
          goto LABEL_27;
        goto LABEL_25;
      case 3u:
        v14 = a3;
        v15 = 12;
        break;
      case 4u:
        v14 = a3;
        v15 = 14;
        break;
      default:
        goto LABEL_24;
    }
    v11 += v14 * v15 + a2;
LABEL_24:
    if ( v11 <= 0x323 )
      goto LABEL_27;
    goto LABEL_25;
  }
  if ( a4 == 3 )
  {
    if ( a5 < 4u )
    {
      v12 = (unsigned __int8 *)dp_getmodulation__vht_bw_mod;
LABEL_16:
      v9 = *(_DWORD *)&v12[4 * a5];
      if ( v9 > 0xB )
      {
        *a7 = 255;
        return 0;
      }
      goto LABEL_18;
    }
  }
  else
  {
    if ( a4 != 4 )
      goto LABEL_18;
    if ( a5 <= 3u )
    {
      v12 = dp_getmodulation__he_bw_mod;
      goto LABEL_16;
    }
  }
  __break(0x5512u);
  __break(1u);
  if ( !v8 )
    JUMPOUT(0x569628);
  return dp_rate_idx_to_kbps();
}
