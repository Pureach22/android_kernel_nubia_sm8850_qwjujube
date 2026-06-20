__int64 __fastcall wma_derive_ext_ht_cap(__int64 result, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 v7; // x19
  char v8; // w9
  unsigned int v9; // w12
  int v10; // w8
  unsigned int v11; // w10
  unsigned int v12; // w9
  _BOOL4 v13; // w13
  unsigned int v14; // w23
  bool v15; // w14
  unsigned int v16; // w12
  bool v17; // w11
  unsigned int num_of_setbits_from_bitmask; // w22
  __int64 v19; // x0
  unsigned int v20; // w22
  __int64 v21; // x0
  unsigned int v22; // w22
  _QWORD v23[2]; // [xsp+0h] [xbp-20h] BYREF
  int v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v23[0] = 0;
  v23[1] = 0;
  if ( result )
  {
    v7 = result;
    if ( (unsigned int)qdf_mem_cmp((const void *)result, v23, 0x14u) )
    {
      v8 = *(_BYTE *)(v7 + 4);
      v9 = *(unsigned __int8 *)(v7 + 6);
      v10 = a2 & 8 | *(unsigned __int8 *)(v7 + 5);
      if ( (a2 & 0x30) == 0 )
        v8 = 0;
      v11 = *(_DWORD *)v7;
      *(_BYTE *)(v7 + 4) = v8;
      v12 = *(unsigned __int8 *)(v7 + 8);
      v13 = (a2 & 0x700) != 0;
      *(_BYTE *)(v7 + 5) = v10 != 0;
      v14 = *(_DWORD *)(v7 + 12);
      if ( v11 < v13 )
        v13 = 0;
      v15 = ((a2 >> 12) & 1) - 1 < v9;
      v16 = *(unsigned __int8 *)(v7 + 16);
      v17 = ((a2 >> 1) & 1) - 1 < *(unsigned __int8 *)(v7 + 7);
      *(_DWORD *)v7 = v13;
      *(_BYTE *)(v7 + 6) = v15;
      *(_BYTE *)(v7 + 7) = v17;
      *(_BYTE *)(v7 + 8) = ((a2 >> 11) & 1) - 1 < v12;
      *(_BYTE *)(v7 + 16) = ((a2 >> 2) & 1) - 1 < v16;
      num_of_setbits_from_bitmask = wma_get_num_of_setbits_from_bitmask(a3);
      if ( num_of_setbits_from_bitmask <= (unsigned int)wma_get_num_of_setbits_from_bitmask(a4) )
        v19 = a4;
      else
        v19 = a3;
      if ( v14 > (unsigned int)wma_get_num_of_setbits_from_bitmask(v19) )
      {
        result = *(unsigned int *)(v7 + 12);
LABEL_19:
        *(_DWORD *)(v7 + 12) = result;
        goto LABEL_20;
      }
      v22 = wma_get_num_of_setbits_from_bitmask(a3);
      if ( v22 <= (unsigned int)wma_get_num_of_setbits_from_bitmask(a4) )
        v21 = a4;
      else
        v21 = a3;
    }
    else
    {
      *(_BYTE *)(v7 + 4) = (a2 & 0x30) != 0;
      *(_BYTE *)(v7 + 5) = (a2 & 8) != 0;
      *(_BYTE *)(v7 + 6) = (a2 & 0x1000) != 0;
      *(_DWORD *)v7 = (a2 & 0x700) != 0;
      *(_BYTE *)(v7 + 7) = (a2 & 2) != 0;
      *(_BYTE *)(v7 + 8) = (a2 & 0x800) != 0;
      *(_BYTE *)(v7 + 16) = (a2 & 4) != 0;
      v20 = wma_get_num_of_setbits_from_bitmask(a3);
      if ( v20 <= (unsigned int)wma_get_num_of_setbits_from_bitmask(a4) )
        v21 = a4;
      else
        v21 = a3;
    }
    result = wma_get_num_of_setbits_from_bitmask(v21);
    goto LABEL_19;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
