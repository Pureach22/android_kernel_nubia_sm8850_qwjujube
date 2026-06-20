void *__fastcall lim_encrypt_auth_frame(
        __int64 a1,
        char a2,
        const void *a3,
        unsigned __int8 *a4,
        __int64 a5,
        unsigned int a6)
{
  unsigned __int8 *v8; // x21
  __int64 v11; // x24
  unsigned int v12; // w10
  __int16 v13; // w8
  unsigned __int8 *v14; // x9
  int v15; // t1
  unsigned int v16; // w10
  unsigned int v17; // w10
  unsigned int v18; // w10
  unsigned int v19; // w10
  unsigned int v20; // w10
  unsigned int v21; // w10
  unsigned int v22; // w10
  unsigned int v23; // w10
  void *result; // x0
  __int64 i; // x8
  _BYTE *v26; // x9
  char v27; // w10
  unsigned __int16 v28; // w8
  unsigned __int16 v29; // w10
  __int64 j; // x11
  char v31; // w14
  int v32; // w8
  int v33; // w9
  int v34; // w10
  __int64 v35; // x11
  char v36; // w14
  char v37; // t1
  int v38; // w12
  char v39; // w13
  __int16 v40; // w9
  int v41; // [xsp+Ch] [xbp-124h] BYREF
  _QWORD v42[2]; // [xsp+10h] [xbp-120h] BYREF
  _BYTE s[258]; // [xsp+26h] [xbp-10Ah] BYREF
  __int64 v44; // [xsp+128h] [xbp-8h]

  v8 = a4;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = a4[7];
  v42[0] = 0;
  v42[1] = 0;
  do
    get_random_bytes(v42, 4);
  while ( !LODWORD(v42[0]) );
  qdf_mem_copy((char *)v42 + 3, a3, a6);
  v12 = -1;
  v13 = v11 + 8;
  v14 = v8;
  do
  {
    v15 = *v14++;
    --v13;
    v16 = v12 ^ v15;
    if ( (v16 & 1) != 0 )
      v17 = (v16 >> 1) ^ 0xEDB88320;
    else
      v17 = v16 >> 1;
    if ( (v17 & 1) != 0 )
      v18 = (v17 >> 1) ^ 0xEDB88320;
    else
      v18 = v17 >> 1;
    if ( (v18 & 1) != 0 )
      v19 = (v18 >> 1) ^ 0xEDB88320;
    else
      v19 = v18 >> 1;
    if ( (v19 & 1) != 0 )
      v20 = (v19 >> 1) ^ 0xEDB88320;
    else
      v20 = v19 >> 1;
    if ( (v20 & 1) != 0 )
      v21 = (v20 >> 1) ^ 0xEDB88320;
    else
      v21 = v20 >> 1;
    if ( (v21 & 1) != 0 )
      v22 = (v21 >> 1) ^ 0xEDB88320;
    else
      v22 = v21 >> 1;
    if ( (v22 & 1) != 0 )
      v23 = (v22 >> 1) ^ 0xEDB88320;
    else
      v23 = v22 >> 1;
    if ( (v23 & 1) != 0 )
      v12 = (v23 >> 1) ^ 0xEDB88320;
    else
      v12 = v23 >> 1;
  }
  while ( v13 );
  v41 = ~v12;
  qdf_mem_copy(&v8[v11 + 8], &v41, 4u);
  result = memset(s, 0, sizeof(s));
  for ( i = 0; i != 256; i += 2 )
  {
    v26 = &s[i];
    v27 = i | 1;
    v26[2] = i;
    v26[3] = v27;
  }
  v28 = 0;
  v29 = 0;
  for ( j = 2; j != 258; ++j )
  {
    v31 = s[j];
    if ( v28 < 0x10u )
      v29 = (unsigned __int8)(v31 + v29 + *((_BYTE *)v42 + v28));
    s[j] = s[v29 + 2];
    if ( a6 + 3 > (unsigned __int16)(v28 + 1) )
      ++v28;
    else
      v28 = 0;
    s[v29 + 2] = v31;
  }
  v32 = 0;
  v33 = 0;
  v34 = v11 + 12;
  v35 = 4;
  do
  {
    v38 = (unsigned __int8)s[(unsigned __int8)++v33 + 2];
    v32 += v38;
    v39 = s[(unsigned __int8)v32 + 2];
    s[(unsigned __int8)v33 + 2] = v39;
    s[(unsigned __int8)v32 + 2] = v38;
    if ( v8 )
    {
      v37 = *v8++;
      v36 = v37;
    }
    else
    {
      v36 = 0;
    }
    --v34;
    *(_BYTE *)(a5 + v35++) = v36 ^ s[(unsigned __int8)(v39 + v38) + 2];
  }
  while ( (_WORD)v34 );
  v40 = *(_WORD *)((char *)v42 + 1);
  *(_BYTE *)a5 = v42[0];
  *(_WORD *)(a5 + 1) = v40;
  *(_BYTE *)(a5 + 3) = a2 << 6;
  _ReadStatusReg(SP_EL0);
  return result;
}
