void *__fastcall hdd_copy_ht_caps(_WORD *a1, __int64 a2)
{
  void *result; // x0
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w9
  unsigned int v8; // w8
  int v9; // w8
  unsigned int v10; // w8
  int v11; // w9
  int v12; // w9
  int v13; // w9
  int v14; // w9
  unsigned int v15; // w8
  __int16 v16; // w8
  char v17; // w8

  result = qdf_mem_set(a1, 0x1Au, 0);
  v5 = *(unsigned __int16 *)(a2 + 1);
  if ( (v5 & 1) != 0 )
  {
    *a1 |= 1u;
    v5 = *(unsigned __int16 *)(a2 + 1);
    if ( (v5 & 2) == 0 )
    {
LABEL_3:
      v6 = (v5 >> 2) & 3;
      if ( !v6 )
        goto LABEL_5;
      goto LABEL_4;
    }
  }
  else if ( (v5 & 2) == 0 )
  {
    goto LABEL_3;
  }
  *a1 |= 2u;
  v5 = *(unsigned __int16 *)(a2 + 1);
  v6 = (v5 >> 2) & 3;
  if ( v6 )
  {
LABEL_4:
    *a1 |= 4 * (_WORD)v6;
    v5 = *(unsigned __int16 *)(a2 + 1);
  }
LABEL_5:
  if ( (v5 & 0x10) != 0 )
  {
    *a1 |= 0x10u;
    v5 = *(unsigned __int16 *)(a2 + 1);
    if ( (v5 & 0x20) == 0 )
    {
LABEL_7:
      if ( (v5 & 0x40) == 0 )
        goto LABEL_8;
      goto LABEL_60;
    }
  }
  else if ( (v5 & 0x20) == 0 )
  {
    goto LABEL_7;
  }
  *a1 |= 0x20u;
  v5 = *(unsigned __int16 *)(a2 + 1);
  if ( (v5 & 0x40) == 0 )
  {
LABEL_8:
    if ( (v5 & 0x80) == 0 )
      goto LABEL_9;
    goto LABEL_61;
  }
LABEL_60:
  *a1 |= 0x40u;
  v5 = *(unsigned __int16 *)(a2 + 1);
  if ( (v5 & 0x80) == 0 )
  {
LABEL_9:
    v7 = (v5 >> 8) & 3;
    if ( !v7 )
      goto LABEL_11;
    goto LABEL_10;
  }
LABEL_61:
  *a1 |= 0x80u;
  v5 = *(unsigned __int16 *)(a2 + 1);
  v7 = (v5 >> 8) & 3;
  if ( v7 )
  {
LABEL_10:
    *a1 |= (_WORD)v7 << 8;
    LOWORD(v5) = *(_WORD *)(a2 + 1);
  }
LABEL_11:
  if ( (v5 & 0x400) != 0 )
  {
    *a1 |= 0x400u;
    LOWORD(v5) = *(_WORD *)(a2 + 1);
    if ( (v5 & 0x800) == 0 )
    {
LABEL_13:
      if ( (v5 & 0x1000) == 0 )
        goto LABEL_14;
      goto LABEL_65;
    }
  }
  else if ( (v5 & 0x800) == 0 )
  {
    goto LABEL_13;
  }
  *a1 |= 0x800u;
  LOWORD(v5) = *(_WORD *)(a2 + 1);
  if ( (v5 & 0x1000) == 0 )
  {
LABEL_14:
    if ( (v5 & 0x2000) == 0 )
      goto LABEL_15;
    goto LABEL_66;
  }
LABEL_65:
  *a1 |= 0x1000u;
  LOWORD(v5) = *(_WORD *)(a2 + 1);
  if ( (v5 & 0x2000) == 0 )
  {
LABEL_15:
    if ( (v5 & 0x4000) == 0 )
      goto LABEL_16;
LABEL_67:
    *a1 |= 0x4000u;
    if ( (*(_WORD *)(a2 + 1) & 0x8000) == 0 )
      goto LABEL_17;
    goto LABEL_68;
  }
LABEL_66:
  *a1 |= 0x2000u;
  LOWORD(v5) = *(_WORD *)(a2 + 1);
  if ( (v5 & 0x4000) != 0 )
    goto LABEL_67;
LABEL_16:
  if ( (v5 & 0x8000) == 0 )
    goto LABEL_17;
LABEL_68:
  *a1 |= 0x8000u;
LABEL_17:
  v8 = *(unsigned __int8 *)(a2 + 3);
  if ( (v8 & 3) != 0 )
  {
    *((_BYTE *)a1 + 2) |= 3u;
    v8 = *(unsigned __int8 *)(a2 + 3);
  }
  v9 = (v8 >> 2) & 7;
  if ( v9 )
    *((_BYTE *)a1 + 2) |= 4 * (_BYTE)v9;
  v10 = *(_DWORD *)(a2 + 20);
  if ( (v10 & 1) != 0 )
  {
    *(_WORD *)((char *)a1 + 19) |= 1u;
    v10 = *(_DWORD *)(a2 + 20);
  }
  v11 = (v10 >> 1) & 3;
  if ( v11 )
  {
    *(_WORD *)((char *)a1 + 19) |= 2 * (_WORD)v11;
    v10 = *(_DWORD *)(a2 + 20);
  }
  v12 = (v10 >> 8) & 3;
  if ( v12 )
  {
    *(_WORD *)((char *)a1 + 19) |= (_WORD)v12 << 8;
    v10 = *(_DWORD *)(a2 + 20);
  }
  if ( (v10 & 0x10000) != 0 )
  {
    *(_DWORD *)((char *)a1 + 21) |= 1u;
    v10 = *(_DWORD *)(a2 + 20);
    if ( (v10 & 0x20000) == 0 )
    {
LABEL_29:
      if ( (v10 & 0x40000) == 0 )
        goto LABEL_30;
      goto LABEL_71;
    }
  }
  else if ( (v10 & 0x20000) == 0 )
  {
    goto LABEL_29;
  }
  *(_DWORD *)((char *)a1 + 21) |= 2u;
  v10 = *(_DWORD *)(a2 + 20);
  if ( (v10 & 0x40000) == 0 )
  {
LABEL_30:
    if ( (v10 & 0x80000) == 0 )
      goto LABEL_31;
    goto LABEL_72;
  }
LABEL_71:
  *(_DWORD *)((char *)a1 + 21) |= 4u;
  v10 = *(_DWORD *)(a2 + 20);
  if ( (v10 & 0x80000) == 0 )
  {
LABEL_31:
    if ( (v10 & 0x100000) == 0 )
      goto LABEL_32;
    goto LABEL_73;
  }
LABEL_72:
  *(_DWORD *)((char *)a1 + 21) |= 8u;
  v10 = *(_DWORD *)(a2 + 20);
  if ( (v10 & 0x100000) == 0 )
  {
LABEL_32:
    if ( (v10 & 0x200000) == 0 )
      goto LABEL_33;
    goto LABEL_74;
  }
LABEL_73:
  *(_DWORD *)((char *)a1 + 21) |= 0x10u;
  v10 = *(_DWORD *)(a2 + 20);
  if ( (v10 & 0x200000) == 0 )
  {
LABEL_33:
    v13 = (v10 >> 22) & 3;
    if ( !v13 )
      goto LABEL_35;
    goto LABEL_34;
  }
LABEL_74:
  *(_DWORD *)((char *)a1 + 21) |= 0x20u;
  v10 = *(_DWORD *)(a2 + 20);
  v13 = (v10 >> 22) & 3;
  if ( v13 )
  {
LABEL_34:
    *(_DWORD *)((char *)a1 + 21) |= v13 << 6;
    v10 = *(_DWORD *)(a2 + 20);
  }
LABEL_35:
  if ( (v10 & 0x1000000) != 0 )
  {
    *(_DWORD *)((char *)a1 + 21) |= 0x100u;
    v10 = *(_DWORD *)(a2 + 20);
    if ( (v10 & 0x2000000) == 0 )
    {
LABEL_37:
      v14 = (v10 >> 26) & 7;
      if ( !v14 )
        goto LABEL_39;
      goto LABEL_38;
    }
  }
  else if ( (v10 & 0x2000000) == 0 )
  {
    goto LABEL_37;
  }
  *(_DWORD *)((char *)a1 + 21) |= 0x200u;
  v10 = *(_DWORD *)(a2 + 20);
  v14 = (v10 >> 26) & 7;
  if ( v14 )
  {
LABEL_38:
    *(_DWORD *)((char *)a1 + 21) |= v14 << 10;
    v10 = *(_DWORD *)(a2 + 20);
  }
LABEL_39:
  v15 = v10 >> 29;
  if ( v15 )
    *(_DWORD *)((char *)a1 + 21) |= v15 << 13;
  v16 = *(_WORD *)(a2 + 24);
  if ( (v16 & 7) != 0 )
  {
    *(_DWORD *)((char *)a1 + 21) |= (v16 & 7) << 16;
    v16 = *(_WORD *)(a2 + 24);
  }
  if ( (v16 & 0x10) != 0 )
  {
    *(_DWORD *)((char *)a1 + 21) |= 0x80000u;
    v16 = *(_WORD *)(a2 + 24);
    if ( (v16 & 0x40) == 0 )
    {
LABEL_45:
      if ( (v16 & 0x100) == 0 )
        goto LABEL_46;
      goto LABEL_81;
    }
  }
  else if ( (v16 & 0x40) == 0 )
  {
    goto LABEL_45;
  }
  *(_DWORD *)((char *)a1 + 21) |= 0x200000u;
  if ( (*(_WORD *)(a2 + 24) & 0x100) == 0 )
  {
LABEL_46:
    v17 = *(_BYTE *)(a2 + 26);
    if ( (v17 & 1) == 0 )
      goto LABEL_47;
    goto LABEL_82;
  }
LABEL_81:
  *(_DWORD *)((char *)a1 + 21) |= 0x800000u;
  v17 = *(_BYTE *)(a2 + 26);
  if ( (v17 & 1) == 0 )
  {
LABEL_47:
    if ( (v17 & 2) == 0 )
      goto LABEL_48;
    goto LABEL_83;
  }
LABEL_82:
  *((_BYTE *)a1 + 25) |= 1u;
  v17 = *(_BYTE *)(a2 + 26);
  if ( (v17 & 2) == 0 )
  {
LABEL_48:
    if ( (v17 & 4) == 0 )
      goto LABEL_49;
    goto LABEL_84;
  }
LABEL_83:
  *((_BYTE *)a1 + 25) |= 2u;
  v17 = *(_BYTE *)(a2 + 26);
  if ( (v17 & 4) == 0 )
  {
LABEL_49:
    if ( (v17 & 8) == 0 )
      goto LABEL_50;
    goto LABEL_85;
  }
LABEL_84:
  *((_BYTE *)a1 + 25) |= 4u;
  v17 = *(_BYTE *)(a2 + 26);
  if ( (v17 & 8) == 0 )
  {
LABEL_50:
    if ( (v17 & 0x10) == 0 )
      goto LABEL_51;
    goto LABEL_86;
  }
LABEL_85:
  *((_BYTE *)a1 + 25) |= 8u;
  v17 = *(_BYTE *)(a2 + 26);
  if ( (v17 & 0x10) == 0 )
  {
LABEL_51:
    if ( (v17 & 0x20) == 0 )
      goto LABEL_52;
LABEL_87:
    *((_BYTE *)a1 + 25) |= 0x20u;
    if ( (*(_BYTE *)(a2 + 26) & 0x40) == 0 )
      goto LABEL_54;
    goto LABEL_53;
  }
LABEL_86:
  *((_BYTE *)a1 + 25) |= 0x10u;
  v17 = *(_BYTE *)(a2 + 26);
  if ( (v17 & 0x20) != 0 )
    goto LABEL_87;
LABEL_52:
  if ( (v17 & 0x40) != 0 )
LABEL_53:
    *((_BYTE *)a1 + 25) |= 0x40u;
LABEL_54:
  *((_BYTE *)a1 + 3) = *(_BYTE *)(a2 + 4);
  *((_BYTE *)a1 + 4) = *(_BYTE *)(a2 + 5);
  *((_BYTE *)a1 + 5) = *(_BYTE *)(a2 + 6);
  *((_BYTE *)a1 + 6) = *(_BYTE *)(a2 + 7);
  *((_BYTE *)a1 + 7) = *(_BYTE *)(a2 + 8);
  *((_BYTE *)a1 + 8) = *(_BYTE *)(a2 + 9);
  *((_BYTE *)a1 + 9) = *(_BYTE *)(a2 + 10);
  *((_BYTE *)a1 + 10) = *(_BYTE *)(a2 + 11);
  *((_BYTE *)a1 + 11) = *(_BYTE *)(a2 + 12);
  *((_BYTE *)a1 + 12) = *(_BYTE *)(a2 + 13);
  *(_WORD *)((char *)a1 + 13) = *(_WORD *)(a2 + 14);
  *((_BYTE *)a1 + 15) = *(_BYTE *)(a2 + 16);
  return result;
}
