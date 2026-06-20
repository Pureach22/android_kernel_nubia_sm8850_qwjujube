__int64 __fastcall dot11f_pack_ie_he_op(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w9
  unsigned int v8; // w8
  __int64 result; // x0
  int v10; // w20
  int v14; // w12
  int v15; // w13
  _BYTE *v16; // x10
  _BYTE *v17; // x11
  __int16 v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_19;
  }
  v5 = *(_DWORD *)(a2 + 1);
  if ( (v5 & 0x40000) != 0 )
    v6 = 9;
  else
    v6 = 6;
  v7 = v6 + ((v5 >> 19) & 1);
  if ( (v5 & 0x200000) != 0 )
    v8 = v7 + 5;
  else
    v8 = v7;
  if ( v8 <= a4 )
  {
    v10 = *a5;
    *a3 = -1;
    *a5 += 2;
    a3[2] = 36;
    ++*a5;
    v18 = (*(_DWORD *)(a2 + 1) >> 4) & 0xFFF0 | *(_DWORD *)(a2 + 1) & 0xF;
    qdf_mem_copy(a3 + 3, &v18, 2u);
    *a5 += 2;
    a3[5] = (*(_DWORD *)(a2 + 1) >> 22) & 0xFC | (*(_DWORD *)(a2 + 1) >> 20) & 3;
    ++*a5;
    a3[6] = *(_BYTE *)(a2 + 5);
    ++*a5;
    qdf_mem_copy(a3 + 7, (const void *)(a2 + 6), 2u);
    v14 = *a5 + 2;
    *a5 = v14;
    v15 = *(_DWORD *)(a2 + 1);
    if ( (v15 & 0x40000) != 0 )
    {
      a3[9] = *(_BYTE *)(a2 + 8);
      ++*a5;
      a3[10] = *(_BYTE *)(a2 + 9);
      ++*a5;
      a3[11] = *(_BYTE *)(a2 + 10);
      v14 = *a5 + 1;
      v16 = a3 + 12;
      *a5 = v14;
      v15 = *(_DWORD *)(a2 + 1);
      v17 = a3 + 1;
      if ( (v15 & 0x80000) == 0 )
        goto LABEL_16;
    }
    else
    {
      v16 = a3 + 9;
      v17 = a3 + 1;
      if ( (v15 & 0x80000) == 0 )
      {
LABEL_16:
        if ( (v15 & 0x200000) != 0 )
        {
          *v16 = *(_BYTE *)(a2 + 12);
          ++*a5;
          v16[1] = *(_BYTE *)(a2 + 13);
          ++*a5;
          v16[2] = *(_BYTE *)(a2 + 14);
          ++*a5;
          v16[3] = *(_BYTE *)(a2 + 15);
          ++*a5;
          v16[4] = *(_BYTE *)(a2 + 16);
          v14 = *a5 + 1;
          *a5 = v14;
          result = 0;
          if ( !v17 )
            goto LABEL_19;
        }
        else
        {
          result = 0;
          if ( !v17 )
            goto LABEL_19;
        }
        *v17 = v14 - v10 - 2;
        goto LABEL_19;
      }
    }
    *v16++ = *(_BYTE *)(a2 + 11);
    v14 = *a5 + 1;
    *a5 = v14;
    v15 = *(_DWORD *)(a2 + 1);
    goto LABEL_16;
  }
  result = 268435461;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
