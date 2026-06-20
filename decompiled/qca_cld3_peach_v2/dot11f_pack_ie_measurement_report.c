__int64 __fastcall dot11f_pack_ie_measurement_report(__int64 a1, __int64 a2, char *a3, unsigned int a4, int *a5)
{
  int v10; // w25
  __int64 result; // x0
  unsigned int v12; // w8
  unsigned int v13; // w23
  char *v14; // x2
  unsigned int v15; // w8
  int v16; // w24
  __int64 v17; // x8
  void *v18; // x5
  unsigned int *v19; // x6
  unsigned int v20; // [xsp+0h] [xbp-10h] BYREF
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a5;
  v20 = 0;
  result = dot11f_get_packed_ie_measurement_report(a1, (_BYTE *)a2, (int *)&v20);
  if ( (_DWORD)result )
    goto LABEL_2;
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_2;
  }
  if ( v20 > a4 )
  {
    result = 268435461;
    goto LABEL_2;
  }
  *a3 = 39;
  *a5 += 2;
  a3[2] = *(_BYTE *)(a2 + 1);
  ++*a5;
  if ( !a4 )
    goto LABEL_34;
  result = 0;
  a3[3] = *(_BYTE *)(a2 + 2);
  ++*a5;
  a3[4] = *(_BYTE *)(a2 + 3);
  ++*a5;
  v12 = *(unsigned __int8 *)(a2 + 3);
  if ( v12 > 2 )
  {
    v13 = a4 - 1;
    if ( v12 == 3 )
    {
      a3[5] = *(_BYTE *)(a2 + 4);
      ++*a5;
      a3[6] = *(_BYTE *)(a2 + 5);
      ++*a5;
      frameshtonq((__int64)(a3 + 7), (int *)(a2 + 8));
      *a5 += 8;
      LOWORD(v21) = *(_WORD *)(a2 + 16);
      qdf_mem_copy(a3 + 15, &v21, 2u);
      v18 = &FFS_reportchannel_load_report;
      v19 = (unsigned int *)&IES_reportchannel_load_report;
      v14 = a3 + 18;
      *a5 += 2;
      a3[17] = *(_BYTE *)(a2 + 18);
      ++*a5;
LABEL_31:
      result = pack_core(a1, a2, v14, v13, a5, (__int64)v18, v19);
      goto LABEL_32;
    }
    if ( v12 != 5 )
    {
      if ( v12 != 7 )
        goto LABEL_32;
      LOWORD(v21) = *(_WORD *)(a2 + 4);
      qdf_mem_copy(a3 + 5, &v21, 2u);
      v14 = a3 + 8;
      *a5 += 2;
      a3[7] = *(_BYTE *)(a2 + 6);
      ++*a5;
      v15 = *(unsigned __int8 *)(a2 + 6);
      if ( v15 > 1 )
      {
        if ( v15 == 2 )
        {
          v16 = 4;
          v21 = *(_DWORD *)(a2 + 8);
          qdf_mem_copy(a3 + 8, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 12);
          qdf_mem_copy(a3 + 12, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 16);
          qdf_mem_copy(a3 + 16, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 20);
          qdf_mem_copy(a3 + 20, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 24);
          qdf_mem_copy(a3 + 24, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 28);
          qdf_mem_copy(a3 + 28, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 32);
          qdf_mem_copy(a3 + 32, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 36);
          qdf_mem_copy(a3 + 36, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 40);
          qdf_mem_copy(a3 + 40, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 44);
          qdf_mem_copy(a3 + 44, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 48);
          qdf_mem_copy(a3 + 48, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 52);
          qdf_mem_copy(a3 + 52, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 56);
          qdf_mem_copy(a3 + 56, &v21, 4u);
          v17 = 60;
          goto LABEL_29;
        }
        if ( v15 == 10 )
        {
          a3[8] = *(_BYTE *)(a2 + 8);
          ++*a5;
          a3[9] = *(_BYTE *)(a2 + 9);
          ++*a5;
          a3[10] = *(_BYTE *)(a2 + 10);
          ++*a5;
          a3[11] = *(_BYTE *)(a2 + 11);
          ++*a5;
          a3[12] = *(_BYTE *)(a2 + 12);
          ++*a5;
          LOWORD(v21) = *(_WORD *)(a2 + 14);
          qdf_mem_copy(a3 + 13, &v21, 2u);
          v16 = 1;
          *a5 += 2;
          a3[15] = *(_BYTE *)(a2 + 16);
          v17 = 16;
          goto LABEL_29;
        }
      }
      else
      {
        if ( !*(_BYTE *)(a2 + 6) )
        {
          v16 = 4;
          v21 = *(_DWORD *)(a2 + 8);
          qdf_mem_copy(a3 + 8, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 12);
          qdf_mem_copy(a3 + 12, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 16);
          qdf_mem_copy(a3 + 16, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 20);
          qdf_mem_copy(a3 + 20, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 24);
          qdf_mem_copy(a3 + 24, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 28);
          qdf_mem_copy(a3 + 28, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 32);
          qdf_mem_copy(a3 + 32, &v21, 4u);
          v17 = 36;
          goto LABEL_29;
        }
        if ( v15 == 1 )
        {
          v16 = 4;
          v21 = *(_DWORD *)(a2 + 8);
          qdf_mem_copy(a3 + 8, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 12);
          qdf_mem_copy(a3 + 12, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 16);
          qdf_mem_copy(a3 + 16, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 20);
          qdf_mem_copy(a3 + 20, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 24);
          qdf_mem_copy(a3 + 24, &v21, 4u);
          *a5 += 4;
          v21 = *(_DWORD *)(a2 + 28);
          qdf_mem_copy(a3 + 28, &v21, 4u);
          v17 = 32;
LABEL_29:
          v14 = &a3[v17];
          *a5 += v16;
        }
      }
      v18 = &FFS_reportsta_stats;
      v19 = (unsigned int *)&IES_reportsta_stats;
      goto LABEL_31;
    }
    a3[5] = *(_BYTE *)(a2 + 4);
    ++*a5;
    a3[6] = *(_BYTE *)(a2 + 5);
    ++*a5;
    frameshtonq((__int64)(a3 + 7), (int *)(a2 + 8));
    *a5 += 8;
    LOWORD(v21) = *(_WORD *)(a2 + 16);
    qdf_mem_copy(a3 + 15, &v21, 2u);
    *a5 += 2;
    if ( a4 != 1 )
    {
      v13 = a4 - 2;
      a3[17] = *(_BYTE *)(a2 + 18);
      ++*a5;
      a3[18] = *(_BYTE *)(a2 + 19);
      ++*a5;
      a3[19] = *(_BYTE *)(a2 + 20);
      ++*a5;
      qdf_mem_copy(a3 + 20, (const void *)(a2 + 21), 6u);
      *a5 += 6;
      a3[26] = *(_BYTE *)(a2 + 27);
      ++*a5;
      v21 = *(_DWORD *)(a2 + 28);
      qdf_mem_copy(a3 + 27, &v21, 4u);
      v18 = &FFS_reportBeacon;
      v19 = (unsigned int *)&IES_reportBeacon;
      v14 = a3 + 31;
      *a5 += 4;
      goto LABEL_31;
    }
LABEL_34:
    result = 4;
    goto LABEL_2;
  }
  if ( v12 == 1 )
  {
    a3[5] = *(_BYTE *)(a2 + 4);
    ++*a5;
    frameshtonq((__int64)(a3 + 6), (int *)(a2 + 8));
    *a5 += 8;
    LOWORD(v21) = *(_WORD *)(a2 + 16);
    qdf_mem_copy(a3 + 14, &v21, 2u);
    result = 0;
    *a5 += 2;
    a3[16] = *(_BYTE *)(a2 + 18);
  }
  else
  {
    if ( v12 != 2 )
      goto LABEL_32;
    a3[5] = *(_BYTE *)(a2 + 4);
    ++*a5;
    frameshtonq((__int64)(a3 + 6), (int *)(a2 + 8));
    *a5 += 8;
    LOWORD(v21) = *(_WORD *)(a2 + 16);
    qdf_mem_copy(a3 + 14, &v21, 2u);
    result = 0;
    *a5 += 2;
    a3[16] = *(_BYTE *)(a2 + 18);
    ++*a5;
    a3[17] = *(_BYTE *)(a2 + 19);
    ++*a5;
    a3[18] = *(_BYTE *)(a2 + 20);
    ++*a5;
    a3[19] = *(_BYTE *)(a2 + 21);
    ++*a5;
    a3[20] = *(_BYTE *)(a2 + 22);
    ++*a5;
    a3[21] = *(_BYTE *)(a2 + 23);
    ++*a5;
    a3[22] = *(_BYTE *)(a2 + 24);
    ++*a5;
    a3[23] = *(_BYTE *)(a2 + 25);
  }
  ++*a5;
LABEL_32:
  if ( a3 != (char *)-1LL )
    a3[1] = *(_BYTE *)a5 - v10 - 2;
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
