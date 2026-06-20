void *__fastcall hdd_copy_ht_operation(__int64 a1, __int64 a2)
{
  void *result; // x0
  int v5; // w8
  unsigned int v6; // w9
  unsigned int v7; // w8
  __int16 v8; // w8

  result = qdf_mem_set((void *)(a1 + 696), 0x16u, 0);
  *(_BYTE *)(a1 + 696) = *(_BYTE *)(a2 + 1);
  v5 = *(_DWORD *)(a2 + 2) & 3;
  if ( v5 )
    LOBYTE(v5) = *(_BYTE *)(a1 + 697) | v5;
  *(_BYTE *)(a1 + 697) = v5;
  v6 = *(_DWORD *)(a2 + 2);
  if ( (v6 & 4) != 0 )
  {
    LOBYTE(v5) = v5 | 4;
    *(_BYTE *)(a1 + 697) = v5;
    v6 = *(_DWORD *)(a2 + 2);
    if ( (v6 & 8) == 0 )
    {
LABEL_5:
      if ( (v6 & 0x10) == 0 )
        goto LABEL_6;
      goto LABEL_25;
    }
  }
  else if ( (v6 & 8) == 0 )
  {
    goto LABEL_5;
  }
  LOBYTE(v5) = v5 | 8;
  *(_BYTE *)(a1 + 697) = v5;
  v6 = *(_DWORD *)(a2 + 2);
  if ( (v6 & 0x10) == 0 )
  {
LABEL_6:
    if ( (v6 & 0xE0) == 0 )
      goto LABEL_8;
    goto LABEL_7;
  }
LABEL_25:
  LOBYTE(v5) = v5 | 0x10;
  *(_BYTE *)(a1 + 697) = v5;
  v6 = *(_DWORD *)(a2 + 2);
  if ( (v6 & 0xE0) != 0 )
  {
LABEL_7:
    *(_BYTE *)(a1 + 697) = v5 | v6 & 0xE0;
    v6 = *(_DWORD *)(a2 + 2);
  }
LABEL_8:
  if ( ((v6 >> 8) & 3) - 1 <= 2 )
  {
    *(_WORD *)(a1 + 698) |= (v6 >> 8) & 3;
    v7 = *(_DWORD *)(a2 + 2);
    if ( (v7 & 0x400) == 0 )
    {
LABEL_10:
      if ( (v7 & 0x800) == 0 )
        goto LABEL_11;
      goto LABEL_29;
    }
  }
  else
  {
    v7 = *(_DWORD *)(a2 + 2);
    if ( (v7 & 0x400) == 0 )
      goto LABEL_10;
  }
  *(_WORD *)(a1 + 698) |= 4u;
  v7 = *(_DWORD *)(a2 + 2);
  if ( (v7 & 0x800) == 0 )
  {
LABEL_11:
    if ( (v7 & 0x1000) == 0 )
      goto LABEL_12;
    goto LABEL_30;
  }
LABEL_29:
  *(_WORD *)(a1 + 698) |= 8u;
  v7 = *(_DWORD *)(a2 + 2);
  if ( (v7 & 0x1000) == 0 )
  {
LABEL_12:
    if ( (v7 & 0xFF0000) == 0 )
      goto LABEL_14;
    goto LABEL_13;
  }
LABEL_30:
  *(_WORD *)(a1 + 698) |= 0x10u;
  v7 = *(_DWORD *)(a2 + 2);
  if ( (v7 & 0xFF0000) != 0 )
LABEL_13:
    *(_WORD *)(a1 + 698) |= (v7 >> 11) & 0x1FE0;
LABEL_14:
  v8 = *(_WORD *)(a2 + 6);
  if ( (v8 & 0x7F) != 0 )
  {
    *(_WORD *)(a1 + 700) |= *(_WORD *)(a2 + 6) & 0x7F;
    v8 = *(_WORD *)(a2 + 6);
  }
  if ( (v8 & 0x80) != 0 )
  {
    *(_WORD *)(a1 + 700) |= 0x80u;
    v8 = *(_WORD *)(a2 + 6);
    if ( (v8 & 0x100) == 0 )
    {
LABEL_18:
      if ( (v8 & 0x200) == 0 )
        goto LABEL_19;
      goto LABEL_34;
    }
  }
  else if ( (v8 & 0x100) == 0 )
  {
    goto LABEL_18;
  }
  *(_WORD *)(a1 + 700) |= 0x100u;
  v8 = *(_WORD *)(a2 + 6);
  if ( (v8 & 0x200) == 0 )
  {
LABEL_19:
    if ( (v8 & 0x400) == 0 )
      goto LABEL_20;
LABEL_35:
    *(_WORD *)(a1 + 700) |= 0x400u;
    if ( (*(_WORD *)(a2 + 6) & 0x800) == 0 )
      goto LABEL_22;
    goto LABEL_21;
  }
LABEL_34:
  *(_WORD *)(a1 + 700) |= 0x200u;
  v8 = *(_WORD *)(a2 + 6);
  if ( (v8 & 0x400) != 0 )
    goto LABEL_35;
LABEL_20:
  if ( (v8 & 0x800) != 0 )
LABEL_21:
    *(_WORD *)(a1 + 700) |= 0x800u;
LABEL_22:
  *(_BYTE *)(a1 + 702) = *(_BYTE *)(a2 + 8);
  *(_BYTE *)(a1 + 703) = *(_BYTE *)(a2 + 9);
  *(_BYTE *)(a1 + 704) = *(_BYTE *)(a2 + 10);
  *(_BYTE *)(a1 + 705) = *(_BYTE *)(a2 + 11);
  *(_BYTE *)(a1 + 706) = *(_BYTE *)(a2 + 12);
  *(_BYTE *)(a1 + 707) = *(_BYTE *)(a2 + 13);
  *(_BYTE *)(a1 + 708) = *(_BYTE *)(a2 + 14);
  *(_BYTE *)(a1 + 709) = *(_BYTE *)(a2 + 15);
  *(_BYTE *)(a1 + 710) = *(_BYTE *)(a2 + 16);
  *(_BYTE *)(a1 + 711) = *(_BYTE *)(a2 + 17);
  *(_BYTE *)(a1 + 712) = *(_BYTE *)(a2 + 18);
  *(_BYTE *)(a1 + 713) = *(_BYTE *)(a2 + 19);
  *(_BYTE *)(a1 + 714) = *(_BYTE *)(a2 + 20);
  *(_BYTE *)(a1 + 715) = *(_BYTE *)(a2 + 21);
  *(_BYTE *)(a1 + 716) = *(_BYTE *)(a2 + 22);
  *(_BYTE *)(a1 + 717) = *(_BYTE *)(a2 + 23);
  return result;
}
