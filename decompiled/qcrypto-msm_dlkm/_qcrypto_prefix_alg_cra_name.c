__int64 __fastcall qcrypto_prefix_alg_cra_name(const char *a1, unsigned int a2)
{
  __int64 result; // x0
  size_t v4; // x0
  size_t v5; // x20
  size_t v6; // x0
  __int64 v7; // x9
  bool v8; // cf
  size_t v9; // x2
  char *v10; // x0
  __int64 v11; // x20
  size_t v12; // x0
  __int64 v13; // x2
  __int64 v14; // x0
  char s[7]; // [xsp+8h] [xbp-88h] BYREF
  __int16 v16; // [xsp+Fh] [xbp-81h]
  int v17; // [xsp+11h] [xbp-7Fh]
  __int64 v18; // [xsp+15h] [xbp-7Bh]
  __int64 v19; // [xsp+1Dh] [xbp-73h]
  __int64 v20; // [xsp+25h] [xbp-6Bh]
  __int64 v21; // [xsp+2Dh] [xbp-63h]
  __int64 v22; // [xsp+35h] [xbp-5Bh]
  __int64 v23; // [xsp+3Dh] [xbp-53h]
  __int64 v24; // [xsp+45h] [xbp-4Bh]
  __int64 v25; // [xsp+4Dh] [xbp-43h]
  __int64 v26; // [xsp+55h] [xbp-3Bh]
  __int64 v27; // [xsp+5Dh] [xbp-33h]
  __int64 v28; // [xsp+65h] [xbp-2Bh]
  __int64 v29; // [xsp+6Dh] [xbp-23h]
  __int64 v30; // [xsp+75h] [xbp-1Bh]
  _BYTE v31[11]; // [xsp+7Dh] [xbp-13h] BYREF
  __int64 v32; // [xsp+88h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  strcpy(s, "qcom-");
  memset(v31, 0, sizeof(v31));
  v30 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  v26 = 0;
  v25 = 0;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  s[6] = 0;
  v16 = 0;
  v17 = 0;
  if ( a2 > 0x7A )
  {
    result = 4294967274LL;
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v4 = strlen(s);
  if ( v4 != -1 || (v4 = strnlen(s, 0x80u), v4 < 0x81) )
  {
    if ( v4 <= 0x7F )
    {
      v5 = v4;
      v6 = strlen(a1);
      v7 = v6 + v5;
      v8 = v6 + v5 >= 0x80;
      if ( v6 + v5 >= 0x80 )
        v9 = 127 - v5;
      else
        v9 = v6;
      v10 = &s[v5];
      if ( v8 )
        v11 = 127;
      else
        v11 = v7;
      memcpy(v10, a1, v9);
      s[v11] = 0;
    }
    v12 = strnlen(s, 0x80u);
    if ( v12 < 0x81 )
    {
      if ( v12 == 128 )
        v13 = 128;
      else
        v13 = v12 + 1;
      sized_strscpy(a1, s, v13);
      result = 0;
      goto LABEL_18;
    }
  }
  v14 = _fortify_panic(2);
  return qcrypto_sha_alg_alloc(v14);
}
