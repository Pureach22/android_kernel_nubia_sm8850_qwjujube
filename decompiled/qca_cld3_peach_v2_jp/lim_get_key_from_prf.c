__int64 __fastcall lim_get_key_from_prf(
        const char *a1,
        __int64 a2,
        unsigned int a3,
        const char *a4,
        __int64 a5,
        unsigned int a6,
        __int64 a7,
        unsigned int a8)
{
  unsigned int v9; // w24
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  unsigned int v25; // w27
  unsigned __int64 v26; // x25
  unsigned __int64 v27; // x28
  size_t v28; // x2
  __int64 result; // x0
  __int16 v30[2]; // [xsp+8h] [xbp-78h] BYREF
  __int16 v31; // [xsp+Ch] [xbp-74h] BYREF
  _WORD v32[2]; // [xsp+10h] [xbp-70h] BYREF
  _WORD v33[2]; // [xsp+14h] [xbp-6Ch] BYREF
  _QWORD v34[6]; // [xsp+18h] [xbp-68h] BYREF
  unsigned int v35[4]; // [xsp+48h] [xbp-38h] BYREF
  _QWORD v36[5]; // [xsp+58h] [xbp-28h] BYREF

  v9 = a8;
  v36[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v31 = 8 * a8;
  v32[0] = 0;
  if ( !strcmp(a1, "hmac(sha384)") )
  {
    v25 = 48;
  }
  else
  {
    if ( strcmp(a1, "hmac(sha256)") )
    {
      v24 = "%s: Incorrect crypto length";
LABEL_15:
      qdf_trace_msg(0x35u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "lim_get_key_from_prf");
      result = 16;
      goto LABEL_16;
    }
    v25 = 32;
  }
  memset(v34, 0, sizeof(v34));
  v35[0] = 2;
  v36[0] = v33;
  v36[1] = a4;
  v35[1] = strlen(a4);
  v35[2] = a6;
  v36[2] = a5;
  qdf_mem_copy(v32, &v31, 2u);
  v36[3] = v32;
  v35[3] = 2;
  v30[0] = 1;
  if ( v9 )
  {
    v26 = 0;
    v27 = v9;
    while ( 1 )
    {
      qdf_mem_copy(v33, v30, 2u);
      if ( (qdf_get_hmac_hash((__int64)a1, a2, a3, 4u, (__int64)v36, v35) & 0x80000000) != 0 )
        break;
      if ( v9 >= v25 )
        v28 = v25;
      else
        v28 = v9;
      qdf_mem_copy((void *)(a7 + v26), v34, v28);
      v26 += v25;
      v9 -= v25;
      ++v30[0];
      if ( v26 >= v27 )
        goto LABEL_13;
    }
    v24 = "%s: qdf_get_hmac_hash failed";
    goto LABEL_15;
  }
LABEL_13:
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
