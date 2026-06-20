__int64 __fastcall valid_regdb(_DWORD *a1, unsigned int a2)
{
  int v4; // w21
  __int64 result; // x0
  unsigned __int64 v6; // x21
  _DWORD *v7; // x9
  _DWORD *v8; // x8
  _DWORD *v9; // x22
  unsigned int v10; // w10
  unsigned __int8 *v11; // x9
  unsigned int v12; // w10
  __int64 v13; // x23
  unsigned __int8 *v14; // x24
  unsigned int v16; // t1
  unsigned __int8 *v17; // x9
  unsigned int v18; // w10
  __int64 v19; // x8
  char valid; // w0
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 8
    && *a1 == 1111770962
    && a1[1] == 335544320
    && (v21[0] = 0, !(unsigned int)request_firmware(v21, "regulatory.db.p7s", reg_pdev + 16))
    && (v4 = verify_pkcs7_signature(a1, a2, *(_QWORD *)(v21[0] + 8LL), *(_QWORD *)v21[0], builtin_regdb_keys, 5, 0, 0),
        release_firmware(v21[0]),
        !v4) )
  {
    v6 = (unsigned __int64)a1 + a2;
    v7 = a1 + 3;
    if ( (unsigned __int64)(a1 + 3) <= v6 )
    {
      v8 = a1;
      v9 = a1 + 2;
      while ( 1 )
      {
        v10 = *((unsigned __int16 *)v9 + 1);
        if ( !*((_WORD *)v9 + 1) )
          break;
        v9 = v7;
        v11 = (unsigned __int8 *)&v8[__rev16(v10)];
        if ( (unsigned __int64)(v11 + 2) > v6 )
          goto LABEL_6;
        v12 = *v11;
        v13 = v11[1];
        v14 = &v11[((_WORD)v12 + 1) & 0x1FE];
        if ( v12 < 3 || (unsigned __int64)&v14[2 * v13] > v6 )
          goto LABEL_6;
        if ( v11[1] )
        {
          do
          {
            v16 = *(unsigned __int16 *)v14;
            v14 += 2;
            v17 = (unsigned __int8 *)&v8[bswap32(v16) >> 16];
            if ( (unsigned __int64)(v17 + 1) > v6 )
              goto LABEL_6;
            v18 = *v17;
            if ( v18 < 0x10 )
              goto LABEL_6;
            if ( v18 >= 0x14 )
            {
              v19 = bswap32(*((unsigned __int16 *)v17 + 9)) >> 16;
              if ( v19 * 4 + 32 > (unsigned __int64)a2 )
                goto LABEL_6;
              valid = valid_wmm(&a1[v19]);
              v8 = a1;
              if ( (valid & 1) == 0 )
                goto LABEL_6;
            }
          }
          while ( --v13 );
        }
        v7 = v9 + 1;
        result = 1;
        if ( (unsigned __int64)(v9 + 1) > v6 )
          goto LABEL_7;
      }
    }
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
