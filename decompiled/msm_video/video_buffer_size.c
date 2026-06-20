__int64 __fastcall video_buffer_size(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // w12
  unsigned int v4; // w8
  int v5; // w10
  unsigned int v6; // w9
  int v7; // w10
  int v8; // w11
  unsigned int v9; // w11
  unsigned int v10; // w13
  int v11; // w12
  int v12; // w14
  unsigned int v13; // w12
  unsigned int v14; // w9
  unsigned int v15; // w8
  unsigned int v16; // w11
  unsigned int v17; // w10
  unsigned int v18; // w12
  unsigned int v19; // w14
  int v20; // w10
  int v21; // w9
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned int v24; // w10
  unsigned int v25; // w9

  v3 = 0;
  if ( !a2 || !a3 )
    return (v3 + 4095) & 0xFFFFF000;
  v4 = 0;
  if ( a1 > 15 )
  {
    if ( a1 == 16 || a1 == 128 || a1 == 256 )
      v4 = (2 * a2 + 255) & 0xFFFFFF00;
  }
  else if ( (unsigned int)(a1 - 1) < 2 || a1 == 4 )
  {
    v4 = (a2 + 127) & 0xFFFFFF80;
  }
  else if ( a1 == 8 )
  {
    v5 = 16;
    v6 = (768 * ((a2 + 191) / 0xC0) / 3 + 255) & 0x7FFFFF00;
    v4 = v6;
    goto LABEL_29;
  }
  v6 = 0;
  if ( a1 > 15 )
  {
    if ( a1 == 16 || a1 == 128 || a1 == 256 )
      v6 = (2 * a2 + 255) & 0xFFFFFF00;
LABEL_21:
    if ( (unsigned int)a1 > 0x10 )
      goto LABEL_26;
    goto LABEL_24;
  }
  if ( (unsigned int)(a1 - 1) >= 2 && a1 != 4 )
    goto LABEL_21;
  v6 = (a2 + 127) & 0xFFFFFF80;
LABEL_24:
  if ( ((1 << a1) & 0x10016) != 0 )
  {
    v5 = 32;
    goto LABEL_29;
  }
LABEL_26:
  if ( a1 == 256 || a1 == 128 )
  {
    v5 = 16;
LABEL_29:
    v7 = (a3 + v5 - 1) & -v5;
    if ( (unsigned int)a1 > 0x10 )
      goto LABEL_36;
    goto LABEL_30;
  }
  v7 = 0;
  if ( (unsigned int)a1 > 0x10 )
    goto LABEL_36;
LABEL_30:
  if ( ((1 << a1) & 0x10114) != 0 )
  {
    v8 = 16;
LABEL_32:
    v9 = (v8 + ((a3 + 1) >> 1) - 1) & -v8;
    goto LABEL_40;
  }
  if ( a1 == 1 )
  {
    v8 = 32;
    goto LABEL_32;
  }
LABEL_36:
  if ( a1 == 256 || a1 == 128 )
  {
    v9 = (a3 + 15) & 0xFFFFFFF0;
  }
  else
  {
    v9 = 0;
    if ( a1 == 64 )
      goto LABEL_41;
  }
LABEL_40:
  if ( a1 != 32 )
  {
    v10 = 0;
    goto LABEL_42;
  }
LABEL_41:
  v10 = (4 * a2 + 255) & 0xFFFFFF00;
  if ( a1 == 32 )
  {
    v11 = 16;
    goto LABEL_46;
  }
LABEL_42:
  if ( a1 == 64 )
  {
    v11 = 32;
LABEL_46:
    v12 = (a3 + v11 - 1) & -v11;
    goto LABEL_48;
  }
  v12 = 0;
LABEL_48:
  v3 = 0;
  if ( a1 > 15 )
  {
    if ( a1 > 63 )
    {
      if ( a1 == 64 )
      {
        v3 = (v12 * v10 + 4095) & 0xFFFFF000;
        return (v3 + 4095) & 0xFFFFF000;
      }
      if ( a1 != 128 )
      {
        if ( a1 != 256 )
          return (v3 + 4095) & 0xFFFFF000;
        goto LABEL_65;
      }
      goto LABEL_60;
    }
    if ( a1 != 16 )
    {
      if ( a1 == 32 )
      {
        v14 = (v12 * v10 + 4095) & 0xFFFFF000;
        v15 = (((((a3 + 3) >> 2) + 15) & 0x7FFFFFF0) * ((((a2 + 15) >> 4) + 63) & 0x1FFFFFC0) + 4095) & 0xFFFFF000;
LABEL_78:
        v3 = v14 + v15;
        return (v3 + 4095) & 0xFFFFF000;
      }
      return (v3 + 4095) & 0xFFFFF000;
    }
LABEL_65:
    v3 = v7 * v4 + v9 * v6;
    return (v3 + 4095) & 0xFFFFF000;
  }
  if ( a1 <= 3 )
  {
    if ( a1 == 1 )
    {
      v16 = (((a2 + 31) >> 5) + 63) & 0xFFFFFC0;
      v17 = (((((a2 + 1) >> 1) + 15) >> 4) + 63) & 0x1FFFFFC0;
      if ( a2 > 0x780 || a3 > 0x780 || a3 * a2 > 0x1FE0FF )
      {
        v3 = ((((((((a3 + 1) >> 1) + 7) >> 3) + 15) & 0x3FFFFFF0) * v17 + 4095) & 0xFFFFF000)
           + ((((((a3 + 7) >> 3) + 15) & 0x3FFFFFF0) * v16 + 4095) & 0xFFFFF000)
           + ((v6 * ((((a3 + 1) >> 1) + 31) & 0xFFFFFFE0) + 4095) & 0xFFFFF000)
           + ((v4 * ((a3 + 31) & 0xFFFFFFE0) + 4095) & 0xFFFFF000);
      }
      else
      {
        v18 = (a3 + 1) >> 1;
        v3 = 2
           * (((((((((v18 + 1) >> 1) + 7) >> 3) + 15) & 0x3FF0) * v17 + 4095) & 0x7FFFF000)
            + ((((((v18 + 7) >> 3) + 15) & 0x1FFFFFF0) * v16 + 4095) & 0x7FFFF000)
            + ((v6 * ((((v18 + 1) >> 1) + 31) & 0x7FFFFFE0) + 4095) & 0x7FFFF000)
            + ((v4 * (((_WORD)v18 + 31) & 0xFE0) + 4095) & 0x7FFFF000));
      }
      return (v3 + 4095) & 0xFFFFF000;
    }
    if ( a1 != 2 )
      return (v3 + 4095) & 0xFFFFF000;
    goto LABEL_65;
  }
  if ( a1 == 4 )
    goto LABEL_65;
  if ( a1 == 8 )
  {
LABEL_60:
    if ( a1 == 128 )
      v13 = 32;
    else
      v13 = 48;
    v19 = (((a3 + 3) >> 2) + 15) & 0x7FFFFFF0;
    v20 = v7 * v4 + 4095;
    v21 = v9 * v6 + 4095;
    if ( a1 == 128 )
      v22 = 16;
    else
      v22 = 24;
    v23 = ((v22 + ((a2 + 1) >> 1) - 1) / v22 + 63) & 0x1FFFFFC0;
    v24 = v20 & 0xFFFFF000;
    v25 = v21 & 0xFFFFF000;
    if ( a1 != 128 )
      a3 = (a3 + 1) >> 1;
    v14 = v25 + v24;
    v15 = ((v19 * (((a2 + v13 - 1) / v13 + 63) & 0xFFFFFC0) + 4095) & 0xFFFFF000)
        + ((((((a3 + 3) >> 2) + 15) & 0x7FFFFFF0) * v23 + 4095) & 0xFFFFF000);
    goto LABEL_78;
  }
  return (v3 + 4095) & 0xFFFFF000;
}
