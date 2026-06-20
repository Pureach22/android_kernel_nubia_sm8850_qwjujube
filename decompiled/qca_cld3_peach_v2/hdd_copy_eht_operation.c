void *__fastcall hdd_copy_eht_operation(__int64 a1, _BYTE *a2)
{
  void *result; // x0
  char v5; // w10
  char v6; // w8
  int v7; // w9
  int v8; // w8

  result = qdf_mem_set((void *)(a1 + 906), 5u, 0);
  if ( (a2[1] & 1) == 0 )
    return result;
  v5 = *(_BYTE *)(a1 + 906);
  v6 = v5 | 1;
  *(_BYTE *)(a1 + 906) = v5 | 1;
  v7 = *(_DWORD *)(a2 + 1);
  if ( (v7 & 4) == 0 )
  {
    if ( (v7 & 8) == 0 )
      goto LABEL_4;
LABEL_9:
    v6 |= 8u;
    *(_BYTE *)(a1 + 906) = v6;
    v7 = *(_DWORD *)(a2 + 1);
    if ( (v7 & 0x30) == 0 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v6 = v5 | 5;
  *(_BYTE *)(a1 + 906) = v5 | 5;
  v7 = *(_DWORD *)(a2 + 1);
  if ( (v7 & 8) != 0 )
    goto LABEL_9;
LABEL_4:
  if ( (v7 & 0x30) != 0 )
  {
LABEL_5:
    v6 |= 0x30u;
    *(_BYTE *)(a1 + 906) = v6;
    v7 = *(_DWORD *)(a2 + 1);
  }
LABEL_6:
  *(_WORD *)(a1 + 908) = 0;
  *(_BYTE *)(a1 + 910) = 0;
  *(_BYTE *)(a1 + 907) = BYTE1(v7);
  *(_BYTE *)(a1 + 911) = a2[6] & 7;
  *(_BYTE *)(a1 + 912) = a2[7];
  *(_BYTE *)(a1 + 913) = a2[8];
  if ( (a2[1] & 2) != 0 )
  {
    *(_BYTE *)(a1 + 906) = v6 | 2;
    v8 = 10;
  }
  else
  {
    v8 = 8;
  }
  *(_DWORD *)(a1 + 912) = v8;
  return result;
}
