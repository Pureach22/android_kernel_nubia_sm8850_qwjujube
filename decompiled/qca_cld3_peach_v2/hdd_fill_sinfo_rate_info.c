__int64 __fastcall hdd_fill_sinfo_rate_info(
        _QWORD *a1,
        int a2,
        char a3,
        char a4,
        unsigned __int16 a5,
        char a6,
        int a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v15; // x9
  unsigned __int16 *v18; // x9
  __int64 v19; // x4
  char v20; // w8
  char v22; // w8
  char v23; // w8
  char v24; // w8
  int v25; // w8
  __int64 result; // x0
  __int64 v27; // x9

  v15 = 70;
  if ( (a6 & 1) != 0 )
    v15 = 56;
  v18 = (unsigned __int16 *)((char *)a1 + v15);
  if ( (a2 & 1) != 0 )
  {
    v19 = *v18;
    v18[1] = a5;
    goto LABEL_45;
  }
  v19 = *v18;
  if ( (a2 & 0x3E000) != 0 )
  {
    v19 = (unsigned int)v19 | 0x80;
    *((_BYTE *)v18 + 5) = a4;
    *((_BYTE *)v18 + 4) = a3;
    *v18 = v19;
    if ( (a2 & 0x20000) != 0 )
    {
      v20 = 7;
    }
    else if ( (a2 & 0x10000) != 0 )
    {
      v20 = 5;
    }
    else if ( (a2 & 0x8000) != 0 )
    {
      v20 = 4;
    }
    else if ( (a2 & 0x4000) != 0 )
    {
      v20 = 3;
    }
    else
    {
      if ( (a2 & 0x2000) == 0 )
        goto LABEL_17;
      v20 = 0;
    }
    *((_BYTE *)v18 + 6) = v20;
  }
LABEL_17:
  if ( (a2 & 0xF00) == 0 )
    goto LABEL_30;
  v19 = (unsigned int)v19 | 0x10;
  *((_BYTE *)v18 + 5) = a4;
  *((_BYTE *)v18 + 4) = a3;
  *v18 = v19;
  if ( (a2 & 0x800) != 0 )
  {
    v22 = 5;
    goto LABEL_26;
  }
  if ( (a2 & 0x400) != 0 )
  {
    v22 = 4;
    goto LABEL_26;
  }
  if ( (a2 & 0x200) != 0 )
  {
    v22 = 3;
    goto LABEL_26;
  }
  if ( (a2 & 0x100) != 0 )
  {
    v22 = 0;
LABEL_26:
    *((_BYTE *)v18 + 6) = v22;
  }
  v23 = a7 == 2;
  if ( a7 == 3 )
    v23 = 2;
  *((_BYTE *)v18 + 7) = v23;
LABEL_30:
  if ( (a2 & 0x10E0) == 0 )
    goto LABEL_40;
  v19 = (unsigned int)v19 | 2;
  *((_BYTE *)v18 + 5) = a4;
  *((_BYTE *)v18 + 4) = a3;
  *v18 = v19;
  if ( (a2 & 0x1000) != 0 )
  {
    v24 = 5;
  }
  else if ( (a2 & 0x80) != 0 )
  {
    v24 = 4;
  }
  else if ( (a2 & 0x40) != 0 )
  {
    v24 = 3;
  }
  else
  {
    if ( (a2 & 0x20) == 0 )
      goto LABEL_40;
    v24 = 0;
  }
  *((_BYTE *)v18 + 6) = v24;
LABEL_40:
  if ( (a2 & 6) != 0 )
  {
    v19 = (unsigned int)v19 | 1;
    *v18 = v19;
    *((_BYTE *)v18 + 4) = (8 * a4 - 8) | a3;
    if ( (a2 & 4) != 0 )
      *((_BYTE *)v18 + 6) = 3;
  }
  if ( (a2 & 8) != 0 )
  {
    v25 = v19 | ((v19 & 0x92) == 0);
    v19 = v25 | 4u;
    *v18 = v25 | 4;
  }
LABEL_45:
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: flag %x mcs %d legacy %d nss %d",
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             "hdd_fill_sinfo_rate_info",
             v19,
             *((unsigned __int8 *)v18 + 4),
             v18[1],
             *((unsigned __int8 *)v18 + 5));
  v27 = 0x4000;
  if ( (a6 & 1) != 0 )
    v27 = 256;
  *a1 |= v27;
  return result;
}
