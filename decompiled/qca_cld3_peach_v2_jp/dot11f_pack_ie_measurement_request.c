__int64 __fastcall dot11f_pack_ie_measurement_request(__int64 a1, __int64 a2, char *a3, unsigned int a4, int *a5)
{
  int v10; // w24
  __int64 result; // x0
  unsigned int v12; // w23
  unsigned int v13; // w8
  void *v14; // x5
  unsigned int *v15; // x6
  char *v16; // x2
  int v17; // w8
  unsigned int v18; // [xsp+0h] [xbp-10h] BYREF
  _WORD v19[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a5;
  v18 = 0;
  result = dot11f_get_packed_ie_measurement_request(a1, (_BYTE *)a2, (int *)&v18);
  if ( (_DWORD)result )
    goto LABEL_2;
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_2;
  }
  if ( v18 > a4 )
  {
    result = 268435461;
    goto LABEL_2;
  }
  *a3 = 38;
  *a5 += 2;
  a3[2] = *(_BYTE *)(a2 + 1);
  ++*a5;
  if ( !a4 )
  {
    result = 4;
    goto LABEL_2;
  }
  result = 0;
  v12 = a4 - 1;
  a3[3] = *(_BYTE *)(a2 + 2);
  ++*a5;
  a3[4] = *(_BYTE *)(a2 + 3);
  ++*a5;
  v13 = *(unsigned __int8 *)(a2 + 3);
  if ( v13 > 4 )
  {
    if ( *(unsigned __int8 *)(a2 + 3) > 7u )
    {
      if ( v13 == 8 )
      {
        v14 = &FFS_measurement_requestlci;
        v15 = (unsigned int *)&IES_measurement_requestlci;
        v16 = a3 + 6;
        a3[5] = *(_BYTE *)(a2 + 4);
      }
      else
      {
        if ( v13 != 16 )
          goto LABEL_24;
        v19[0] = *(_WORD *)(a2 + 4);
        qdf_mem_copy(a3 + 5, v19, 2u);
        v14 = &FFS_measurement_requestftmrr;
        v15 = (unsigned int *)&IES_measurement_requestftmrr;
        v16 = a3 + 8;
        *a5 += 2;
        a3[7] = *(_BYTE *)(a2 + 6);
      }
      v17 = *a5 + 1;
    }
    else
    {
      if ( v13 != 5 )
      {
        if ( v13 == 7 )
        {
          qdf_mem_copy(a3 + 5, (const void *)(a2 + 4), 6u);
          *a5 += 6;
          v19[0] = *(_WORD *)(a2 + 10);
          qdf_mem_copy(a3 + 11, v19, 2u);
          *a5 += 2;
          v19[0] = *(_WORD *)(a2 + 12);
          qdf_mem_copy(a3 + 13, v19, 2u);
          result = 0;
          *a5 += 2;
          a3[15] = *(_BYTE *)(a2 + 14);
          ++*a5;
        }
        goto LABEL_24;
      }
      a3[5] = *(_BYTE *)(a2 + 4);
      ++*a5;
      a3[6] = *(_BYTE *)(a2 + 5);
      ++*a5;
      v19[0] = *(_WORD *)(a2 + 6);
      qdf_mem_copy(a3 + 7, v19, 2u);
      *a5 += 2;
      v19[0] = *(_WORD *)(a2 + 8);
      qdf_mem_copy(a3 + 9, v19, 2u);
      *a5 += 2;
      a3[11] = *(_BYTE *)(a2 + 10);
      ++*a5;
      qdf_mem_copy(a3 + 12, (const void *)(a2 + 11), 6u);
      v14 = &FFS_measurement_requestBeacon;
      v15 = (unsigned int *)&IES_measurement_requestBeacon;
      v16 = a3 + 18;
      v17 = *a5 + 6;
    }
    goto LABEL_23;
  }
  if ( *(unsigned __int8 *)(a2 + 3) <= 2u )
  {
    a3[5] = *(_BYTE *)(a2 + 4);
    ++*a5;
    qdf_mem_copy(a3 + 6, (const void *)(a2 + 5), 8u);
    *a5 += 8;
    v19[0] = *(_WORD *)(a2 + 14);
    qdf_mem_copy(a3 + 14, v19, 2u);
    result = 0;
    *a5 += 2;
    goto LABEL_24;
  }
  if ( v13 == 3 )
  {
    a3[5] = *(_BYTE *)(a2 + 4);
    ++*a5;
    a3[6] = *(_BYTE *)(a2 + 5);
    ++*a5;
    v19[0] = *(_WORD *)(a2 + 6);
    qdf_mem_copy(a3 + 7, v19, 2u);
    *a5 += 2;
    v19[0] = *(_WORD *)(a2 + 8);
    qdf_mem_copy(a3 + 9, v19, 2u);
    v14 = &FFS_measurement_requestchannel_load;
    v15 = (unsigned int *)&IES_measurement_requestchannel_load;
    v16 = a3 + 11;
    v17 = *a5 + 2;
LABEL_23:
    *a5 = v17;
    result = pack_core(a1, a2, v16, v12, a5, (__int64)v14, v15);
  }
LABEL_24:
  if ( a3 != (char *)-1LL )
    a3[1] = *(_BYTE *)a5 - v10 - 2;
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
