__int64 __fastcall qcom_ice_program_key(
        __int64 *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int64 *a4,
        unsigned __int8 a5,
        unsigned int a6)
{
  int v6; // w20
  int v7; // w19
  __int64 v8; // x21
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x10
  __int64 result; // x0
  unsigned __int64 v14; // [xsp+8h] [xbp-48h] BYREF
  unsigned __int64 v15; // [xsp+10h] [xbp-40h]
  unsigned __int64 v16; // [xsp+18h] [xbp-38h]
  unsigned __int64 v17; // [xsp+20h] [xbp-30h]
  unsigned __int64 v18; // [xsp+28h] [xbp-28h]
  unsigned __int64 v19; // [xsp+30h] [xbp-20h]
  unsigned __int64 v20; // [xsp+38h] [xbp-18h]
  unsigned __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v6 = a3;
  v7 = a2;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a1;
  if ( a2 || a3 != 3 )
  {
    if ( (unsigned int)__ratelimit(&qcom_ice_program_key__rs, "qcom_ice_program_key") )
      dev_err(v8, "Unhandled crypto capability; algorithm_id=%d, key_size=%d\n", v7, v6);
    result = 4294967274LL;
  }
  else
  {
    v9 = a4[5];
    v18 = a4[4];
    v19 = v9;
    v10 = a4[7];
    v20 = a4[6];
    v21 = v10;
    v11 = a4[1];
    v14 = *a4;
    v15 = v11;
    v12 = a4[2];
    v17 = a4[3];
    v14 = _byteswap_uint64(__PAIR64__(v14, HIDWORD(v14)));
    v15 = _byteswap_uint64(__PAIR64__(v11, HIDWORD(v11)));
    v16 = _byteswap_uint64(__PAIR64__(v12, HIDWORD(v12)));
    v17 = _byteswap_uint64(__PAIR64__(v17, HIDWORD(v17)));
    v18 = _byteswap_uint64(__PAIR64__(v18, HIDWORD(v18)));
    v19 = _byteswap_uint64(__PAIR64__(v9, HIDWORD(v9)));
    v20 = _byteswap_uint64(__PAIR64__(v20, HIDWORD(v20)));
    v21 = _byteswap_uint64(__PAIR64__(v21, HIDWORD(v21)));
    result = qcom_scm_ice_set_key(a6, &v14, 64, 3, a5);
    v14 = 0;
    v15 = 0;
    v16 = 0;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v21 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
