__int64 __fastcall qcom_scm_assign_mem_regions(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x13
  __int64 v11; // x14
  unsigned __int64 v12; // x15
  __int64 v13; // x12
  __int64 v14; // x8
  bool v15; // zf
  unsigned __int64 v16; // x15
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x12
  unsigned __int64 v19; // x15
  __int64 v20; // x13
  unsigned __int64 v21; // x12
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x8
  int convention; // w0
  __int64 v26; // x2
  __int64 result; // x0
  _QWORD v28[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v29[14]; // [xsp+20h] [xbp-70h] BYREF

  v29[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( _scm )
    v8 = *(_QWORD *)_scm;
  else
    v8 = 0;
  v9 = a1 << 8 >> 8;
  v10 = a3 << 8 >> 8;
  v11 = a5 << 8 >> 8;
  v12 = (unsigned __int64)(v9 + 0x8000000000LL) >> 38;
  v13 = memstart_addr + v9 + 0x8000000000LL;
  v14 = v9 - kimage_voffset;
  v15 = v12 == 0;
  v16 = v10 + 0x8000000000LL;
  v17 = v11 + 0x8000000000LL;
  if ( v15 )
    v14 = v13;
  v18 = v16 >> 38;
  v19 = memstart_addr + v16;
  v20 = v10 - kimage_voffset;
  v29[2] = v14;
  v29[3] = a2;
  v15 = v18 == 0;
  v21 = v17 >> 38;
  v22 = memstart_addr + v17;
  if ( v15 )
    v23 = v19;
  else
    v23 = v20;
  v29[0] = 0x160000000CLL;
  v29[1] = 4375;
  v29[4] = v23;
  v29[5] = a4;
  if ( v21 )
    v24 = v11 - kimage_voffset;
  else
    v24 = v22;
  memset(&v29[8], 0, 32);
  v29[6] = v24;
  v29[7] = a6;
  v29[12] = 2;
  memset(v28, 0, sizeof(v28));
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) >= 2 )
  {
    if ( convention != 1 )
    {
      printk(&unk_124E9, "qcom_scm_call", v26);
      result = 4294967274LL;
      goto LABEL_19;
    }
    LODWORD(result) = scm_legacy_call(v8, (__int64)v29, v28);
  }
  else
  {
    LODWORD(result) = _scm_smc_call(v8, v29, qcom_scm_convention, v28, 0);
  }
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = LODWORD(v28[0]);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
