_DWORD *__fastcall hif_log_ce_info(_DWORD *result, int a2, int *a3)
{
  unsigned int v5; // w8
  _DWORD *v6; // x21
  unsigned __int8 v7; // w9
  unsigned __int8 v8; // w22
  _DWORD *v9; // x23
  __int64 (__fastcall *v10)(_QWORD); // x8
  unsigned __int8 v11; // w27
  int v12; // w8
  int v13; // w21
  _QWORD v14[14]; // [xsp+0h] [xbp-80h] BYREF
  char v15; // [xsp+70h] [xbp-10h]
  __int64 v16; // [xsp+78h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  BYTE2(v14[0]) = result[168];
  v5 = result[164];
  BYTE3(v14[0]) = result[169];
  if ( !v5 )
    goto LABEL_13;
  v6 = result;
  v7 = 0;
  v8 = 0;
  v9 = result + 120;
  while ( 1 )
  {
    v11 = v7;
    if ( ((1LL << v7) & 0x61E) != 0 )
    {
      if ( v7 >= 0xCu )
        goto LABEL_12;
      if ( *(_QWORD *)&v9[2 * v7] )
        break;
    }
LABEL_7:
    v7 = v11 + 1;
    if ( v5 <= (unsigned __int8)(v11 + 1) )
      goto LABEL_14;
  }
  if ( v8 <= 0xCu )
  {
    v10 = *(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)v6 + 3837) + 120LL);
    if ( *((_DWORD *)v10 - 1) != 1176737163 )
      __break(0x8228u);
    result = (_DWORD *)v10(v6);
    v5 = v6[164];
    if ( !(_DWORD)result )
      ++v8;
    goto LABEL_7;
  }
LABEL_12:
  __break(0x5512u);
LABEL_13:
  v8 = 0;
LABEL_14:
  BYTE4(v14[0]) = v8;
  v12 = *a3;
  v13 = (unsigned __int16)(113 - 9 * (12 - v8));
  if ( (unsigned int)(*a3 + v13) <= 0xC3 )
  {
    LOWORD(v14[0]) = (unsigned __int8)(111 - 9 * (12 - v8)) | 0x800;
    result = (_DWORD *)qdf_mem_copy(a2 + v12, (int)v14, (unsigned __int16)(113 - 9 * (12 - v8)));
    *a3 += v13;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
