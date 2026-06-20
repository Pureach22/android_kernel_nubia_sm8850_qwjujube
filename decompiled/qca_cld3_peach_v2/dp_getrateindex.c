__int64 __fastcall dp_getrateindex(
        int a1,
        unsigned __int16 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned int *a7,
        _WORD *a8)
{
  int v8; // w24
  unsigned int v14; // w0
  __int64 result; // x0
  unsigned int v16; // w8
  int v17; // w9
  int v18; // w9
  int v19; // w9
  int v20; // w10

  v8 = a4;
  *a8 = 0;
  v14 = dp_getmodulation(a4, a5, a6);
  if ( v14 > 0x16 )
  {
    result = 0;
    v16 = 255;
    goto LABEL_31;
  }
  v16 = rc_idx[v14];
  if ( v8 > 2 )
  {
    switch ( v8 )
    {
      case 3:
        v19 = a3;
        v20 = 12;
        break;
      case 4:
        v19 = a3;
        v20 = 14;
        break;
      case 5:
        v18 = ((_BYTE)a2 + 2) & 0xF | (16 * a3);
        goto LABEL_20;
      default:
        goto LABEL_15;
    }
    v17 = v19 * v20;
    goto LABEL_19;
  }
  if ( !v8 )
  {
    v16 += a2;
    if ( v16 <= 0x5E3 )
      goto LABEL_21;
    goto LABEL_16;
  }
  if ( v8 != 1 )
  {
    v17 = 8 * a3;
LABEL_19:
    v18 = v17 + a2;
LABEL_20:
    v16 += v18;
    if ( v16 <= 0x5E3 )
      goto LABEL_21;
LABEL_16:
    result = 0;
    goto LABEL_31;
  }
  v16 += a2 & 0xFFFB;
LABEL_15:
  if ( v16 > 0x5E3 )
    goto LABEL_16;
LABEL_21:
  result = 0;
  if ( a1 > 1 )
  {
    if ( a1 == 2 )
    {
      result = *((unsigned int *)&dp_11abgnratetable + 10 * v16 + 5);
    }
    else if ( a1 == 3 )
    {
      result = *((unsigned int *)&dp_11abgnratetable + 10 * v16 + 6);
    }
  }
  else if ( a1 )
  {
    if ( a1 == 1 )
      result = *((unsigned int *)&dp_11abgnratetable + 10 * v16 + 4);
  }
  else
  {
    result = *((unsigned int *)&dp_11abgnratetable + 10 * v16 + 8);
  }
  *a8 = *((_WORD *)&dp_11abgnratetable + 20 * v16 + 18);
LABEL_31:
  *a7 = v16;
  return result;
}
