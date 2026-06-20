void *__fastcall hdd_copy_vht_caps(_WORD *a1, __int64 a2)
{
  void *result; // x0
  int v5; // w8
  unsigned int v6; // w9
  int v7; // w10
  int v8; // w10
  char v9; // w9
  unsigned int v10; // w9
  int v11; // w10

  result = qdf_mem_set(a1, 0xCu, 0);
  v5 = *(_DWORD *)a1 | *(_WORD *)(a2 + 1) & 3;
  *(_DWORD *)a1 = v5;
  v6 = *(unsigned __int16 *)(a2 + 1);
  v7 = (v6 >> 2) & 3;
  if ( v7 )
  {
    if ( ((v6 >> 2) & 1) != 0 )
    {
      v5 |= 16 * v7;
      *(_DWORD *)a1 = v5;
      v6 = *(unsigned __int16 *)(a2 + 1);
    }
    if ( (v6 & 8) != 0 )
    {
      v5 |= v7 << 8;
      *(_DWORD *)a1 = v5;
      v6 = *(unsigned __int16 *)(a2 + 1);
    }
  }
  if ( (v6 & 0x10) != 0 )
  {
    v5 |= 0x10u;
    *(_DWORD *)a1 = v5;
    v6 = *(unsigned __int16 *)(a2 + 1);
    if ( (v6 & 0x20) == 0 )
    {
LABEL_8:
      if ( (v6 & 0x40) == 0 )
        goto LABEL_9;
      goto LABEL_34;
    }
  }
  else if ( (v6 & 0x20) == 0 )
  {
    goto LABEL_8;
  }
  v5 |= 0x20u;
  *(_DWORD *)a1 = v5;
  v6 = *(unsigned __int16 *)(a2 + 1);
  if ( (v6 & 0x40) == 0 )
  {
LABEL_9:
    if ( (v6 & 0x80) == 0 )
      goto LABEL_10;
    goto LABEL_35;
  }
LABEL_34:
  v5 |= 0x40u;
  *(_DWORD *)a1 = v5;
  v6 = *(unsigned __int16 *)(a2 + 1);
  if ( (v6 & 0x80) == 0 )
  {
LABEL_10:
    v8 = (v6 >> 8) & 7;
    if ( !v8 )
      goto LABEL_12;
    goto LABEL_11;
  }
LABEL_35:
  v5 |= 0x80u;
  *(_DWORD *)a1 = v5;
  v6 = *(unsigned __int16 *)(a2 + 1);
  v8 = (v6 >> 8) & 7;
  if ( v8 )
  {
LABEL_11:
    v5 |= v8 << 8;
    *(_DWORD *)a1 = v5;
    v6 = *(unsigned __int16 *)(a2 + 1);
  }
LABEL_12:
  if ( (v6 & 0x800) != 0 )
  {
    v5 |= 0x800u;
    *(_DWORD *)a1 = v5;
    v6 = *(unsigned __int16 *)(a2 + 1);
    if ( (v6 & 0x1000) == 0 )
    {
LABEL_14:
      if ( v6 < 0x2000 )
        goto LABEL_16;
      goto LABEL_15;
    }
  }
  else if ( (v6 & 0x1000) == 0 )
  {
    goto LABEL_14;
  }
  v5 |= 0x1000u;
  *(_DWORD *)a1 = v5;
  v6 = *(unsigned __int16 *)(a2 + 1);
  if ( v6 >= 0x2000 )
  {
LABEL_15:
    v5 |= v6 & 0xE000;
    *(_DWORD *)a1 = v5;
  }
LABEL_16:
  v9 = *(_BYTE *)(a2 + 3);
  if ( (v9 & 7) != 0 )
  {
    v5 |= (v9 & 7) << 16;
    *(_DWORD *)a1 = v5;
    v9 = *(_BYTE *)(a2 + 3);
  }
  if ( (v9 & 8) != 0 )
  {
    v5 |= 0x80000u;
    *(_DWORD *)a1 = v5;
    v9 = *(_BYTE *)(a2 + 3);
    if ( (v9 & 0x10) == 0 )
    {
LABEL_20:
      if ( (v9 & 0x20) == 0 )
        goto LABEL_21;
      goto LABEL_42;
    }
  }
  else if ( (v9 & 0x10) == 0 )
  {
    goto LABEL_20;
  }
  v5 |= 0x100000u;
  *(_DWORD *)a1 = v5;
  v9 = *(_BYTE *)(a2 + 3);
  if ( (v9 & 0x20) == 0 )
  {
LABEL_21:
    if ( (v9 & 0x40) == 0 )
      goto LABEL_23;
    goto LABEL_22;
  }
LABEL_42:
  v5 |= 0x200000u;
  *(_DWORD *)a1 = v5;
  if ( (*(_BYTE *)(a2 + 3) & 0x40) != 0 )
  {
LABEL_22:
    v5 |= 0x400000u;
    *(_DWORD *)a1 = v5;
  }
LABEL_23:
  v10 = *(unsigned __int16 *)(a2 + 4);
  if ( (v10 & 7) != 0 )
  {
    v5 |= (v10 & 7) << 23;
    *(_DWORD *)a1 = v5;
    v10 = *(unsigned __int16 *)(a2 + 4);
  }
  v11 = (v10 >> 3) & 3;
  if ( v11 )
  {
    v5 |= v11 << 26;
    *(_DWORD *)a1 = v5;
    LOWORD(v10) = *(_WORD *)(a2 + 4);
  }
  if ( (v10 & 0x20) != 0 )
  {
    v5 |= 0x10000000u;
    *(_DWORD *)a1 = v5;
    LOWORD(v10) = *(_WORD *)(a2 + 4);
  }
  if ( (v10 & 0x40) != 0 )
    *(_DWORD *)a1 = v5 | 0x20000000;
  a1[2] = *(_WORD *)(a2 + 6);
  a1[3] = *(_WORD *)(a2 + 8) & 0x1FFF;
  a1[4] = *(_WORD *)(a2 + 10);
  a1[5] = *(_WORD *)(a2 + 12) & 0x1FFF;
  return result;
}
