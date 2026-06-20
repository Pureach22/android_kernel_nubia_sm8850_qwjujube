__int64 __fastcall qcom_scm_set_cold_boot_addr(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  unsigned __int64 v9; // x24
  __int64 v10; // x9
  __int64 v11; // x19
  int convention; // w0
  __int64 v13; // x2
  unsigned __int64 v14; // x13
  __int64 v15; // x9
  unsigned __int64 v16; // x13
  int v17; // w15
  __int64 v18; // x10
  __int64 v19; // x19
  int v20; // w0
  __int64 v21; // x2
  __int64 v22; // [xsp+0h] [xbp-70h] BYREF
  __int64 v23; // [xsp+8h] [xbp-68h]
  __int64 v24; // [xsp+10h] [xbp-60h]
  __int64 v25; // [xsp+18h] [xbp-58h]
  __int64 v26; // [xsp+20h] [xbp-50h]
  __int64 v27; // [xsp+28h] [xbp-48h]
  __int64 v28; // [xsp+30h] [xbp-40h]
  __int64 v29; // [xsp+38h] [xbp-38h]
  __int64 v30; // [xsp+40h] [xbp-30h]
  __int64 v31; // [xsp+48h] [xbp-28h]
  __int64 v32; // [xsp+50h] [xbp-20h]
  __int64 v33; // [xsp+58h] [xbp-18h]
  __int64 v34; // [xsp+60h] [xbp-10h]
  __int64 v35; // [xsp+68h] [xbp-8h]

  v8 = result << 8 >> 8;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0x1100000001LL;
  v23 = 6;
  v9 = (unsigned __int64)(v8 + 0x8000000000LL) >> 38;
  v10 = memstart_addr + v8 + 0x8000000000LL;
  v26 = -1;
  v27 = -1;
  v28 = -1;
  v29 = 2;
  if ( v9 )
    v10 = v8 - kimage_voffset;
  v30 = 0;
  v31 = 0;
  v24 = v10;
  v25 = -1;
  v33 = 0;
  v34 = 2;
  v32 = 0;
  if ( !_scm )
    goto LABEL_10;
  result = _get_convention(result, a2, a3, a4, a5, a6, a7, a8, v22, v23, v24, v25, v26, v27);
  if ( (_DWORD)result == 1 )
    goto LABEL_10;
  v11 = *(_QWORD *)_scm;
  convention = _get_convention(result, a2, a3, a4, a5, a6, a7, a8, v22, v23, v24, v25, v26, v27);
  if ( (unsigned int)(convention - 2) < 2 )
  {
    result = _scm_smc_call(v11, &v22, qcom_scm_convention, nullptr, 0);
    if ( !(_DWORD)result )
      goto LABEL_25;
LABEL_10:
    v33 = 0;
    v22 = 0x100000001LL;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v24 = 0;
    v23 = 2;
    v34 = 2;
    if ( _scm )
    {
      v14 = _cpu_present_mask;
      if ( _cpu_present_mask )
      {
        LODWORD(v15) = 0;
        while ( 1 )
        {
          v16 = __clz(__rbit64(v14));
          if ( v16 > 3 )
            goto LABEL_24;
          v17 = qcom_scm_cpu_cold_bits[v16];
          v14 = _cpu_present_mask & 0xFFFFFFFE & (unsigned __int64)(-2LL << v16);
          v15 = (unsigned int)v15 | v17;
          if ( !v14 )
            goto LABEL_17;
        }
      }
      v15 = 0;
LABEL_17:
      v18 = memstart_addr + v8 + 0x8000000000LL;
      if ( v9 )
        v18 = v8 - kimage_voffset;
      v24 = v15;
      v25 = v18;
      v19 = *(_QWORD *)_scm;
      v20 = _get_convention(result, a2, a3, a4, a5, a6, a7, a8, v22, v23, v15, v18, v26, v27);
      if ( (unsigned int)(v20 - 2) < 2 )
      {
        result = _scm_smc_call(v19, &v22, qcom_scm_convention, nullptr, 1);
        goto LABEL_25;
      }
      if ( v20 == 1 )
      {
        result = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))scm_legacy_call_atomic)(v19, &v22, 0);
        goto LABEL_25;
      }
      printk(&unk_124E9, "qcom_scm_call_atomic", v21);
    }
LABEL_24:
    result = 4294967274LL;
    goto LABEL_25;
  }
  if ( convention != 1 )
  {
    result = printk(&unk_124E9, "qcom_scm_call", v13);
    goto LABEL_10;
  }
  result = scm_legacy_call(v11, (__int64)&v22, nullptr);
  if ( (_DWORD)result )
    goto LABEL_10;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
