__int64 __fastcall qdf_default_hmac_sha256_kdf(
        __int64 a1,
        unsigned int a2,
        char *s,
        __int64 a4,
        unsigned int a5,
        int a6,
        unsigned int a7)
{
  int v13; // w0
  __int64 v14; // x25
  __int64 v15; // x26
  unsigned int v16; // w23
  unsigned int v17; // w24
  __int64 result; // x0
  char v19; // [xsp+4h] [xbp-9Ch] BYREF
  _QWORD *v20; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v21[3]; // [xsp+10h] [xbp-90h] BYREF
  _QWORD v22[4]; // [xsp+28h] [xbp-78h] BYREF
  __int64 v23; // [xsp+48h] [xbp-58h] BYREF
  __int64 v24; // [xsp+50h] [xbp-50h]
  __int64 v25; // [xsp+58h] [xbp-48h]
  __int64 v26; // [xsp+60h] [xbp-40h]
  __int64 v27; // [xsp+68h] [xbp-38h]
  __int64 v28; // [xsp+70h] [xbp-30h]
  __int64 v29; // [xsp+78h] [xbp-28h]
  __int64 v30; // [xsp+80h] [xbp-20h]
  __int64 v31; // [xsp+88h] [xbp-18h]
  __int64 v32; // [xsp+90h] [xbp-10h]
  __int64 v33; // [xsp+98h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 1;
  memset(v22, 0, sizeof(v22));
  v20 = v22;
  v21[0] = s;
  v13 = strlen(s);
  v21[1] = a4;
  v21[2] = &v19;
  if ( a7 - 8161 <= 0xFFFFE01F )
  {
    qdf_trace_msg(56, 2, "%s: invalid key length %d", "qdf_default_hmac_sha256_kdf", a7);
LABEL_13:
    result = 16;
    goto LABEL_14;
  }
  v14 = (unsigned int)(v13 + 1);
  v31 = 0;
  v32 = 0;
  v15 = a5;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v23 = v14;
  v24 = a5;
  v25 = 1;
  v26 = 0;
  if ( (qdf_get_keyed_hash("hmac(sha256)", a1, a2, v21, (unsigned int *)&v23, 3, (__int64)v22) & 0x80000000) != 0 )
  {
LABEL_12:
    qdf_trace_msg(56, 2, "%s: failed to get hmac hash", "qdf_default_hmac_sha256_kdf");
    goto LABEL_13;
  }
  qdf_mem_copy(a6, (int)v22, 0x20u);
  v19 = 2;
  if ( a7 >= 0x21 )
  {
    v16 = 32;
    do
    {
      v31 = 0;
      v32 = 0;
      v29 = 0;
      v30 = 0;
      v27 = 0;
      v28 = 0;
      v23 = 32;
      v24 = v14;
      v25 = v15;
      v26 = 1;
      if ( (qdf_get_keyed_hash("hmac(sha256)", a1, a2, &v20, (unsigned int *)&v23, 4, (__int64)v22) & 0x80000000) != 0 )
        goto LABEL_12;
      if ( a7 - v16 >= 0x20 )
        v17 = 32;
      else
        v17 = a7 - v16;
      qdf_mem_copy(a6 + v16, (int)v22, v17);
      v16 += v17;
      ++v19;
    }
    while ( v16 < a7 );
  }
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
