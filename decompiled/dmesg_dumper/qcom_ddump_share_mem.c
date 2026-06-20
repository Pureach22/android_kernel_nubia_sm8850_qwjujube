__int64 __fastcall qcom_ddump_share_mem(
        _QWORD *a1,
        unsigned __int16 a2,
        unsigned __int16 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v9; // x0
  __int64 v10; // x9
  int v11; // w0
  __int64 v12; // x20
  __int64 v13; // x23
  __int64 v14; // x2
  __int64 v15; // x8
  __int64 v16; // x10
  unsigned int v17; // w21
  __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x2
  __int64 v21; // x3
  unsigned int v22; // w19
  __int64 v23; // x5
  __int64 v24; // [xsp+0h] [xbp-30h] BYREF
  __int64 v25; // [xsp+8h] [xbp-28h] BYREF
  _DWORD v26[2]; // [xsp+10h] [xbp-20h] BYREF
  _DWORD v27[4]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[2] = a3;
  v27[3] = 6;
  v9 = a1[7];
  v27[0] = a2;
  v27[1] = 6;
  v26[0] = a2;
  v26[1] = 7;
  v10 = a1[8];
  v24 = 1LL << a2;
  v25 = (1LL << a3) | (1LL << a2);
  v11 = qcom_scm_assign_mem(v9, v10 - v9 + 1, &v24, v27, 2, a6);
  if ( v11 )
  {
    v19 = *a1;
    v20 = a1[7];
    v21 = a1[20];
    v22 = v11;
    dev_err(v19, "qcom_scm_assign_mem addr=%llx size=%llu failed: %d\n", v20, v21, v11);
    result = v22;
    goto LABEL_11;
  }
  v12 = _kmalloc_cache_noprof(ghd_rm_mem_reclaim, 3520, 12);
  if ( !v12 )
  {
LABEL_10:
    result = 4294967284LL;
    goto LABEL_11;
  }
  v13 = _kmalloc_cache_noprof(gh_dbl_read_and_clean, 3520, 22);
  if ( !v13 )
  {
    kfree(v12);
    goto LABEL_10;
  }
  v14 = *((unsigned int *)a1 + 42);
  *(_DWORD *)v12 = 2;
  v15 = a1[7];
  v16 = a1[8];
  *(_BYTE *)(v12 + 6) = 6;
  *(_BYTE *)(v12 + 10) = 6;
  *(_DWORD *)v13 = 1;
  *(_QWORD *)(v13 + 6) = v15;
  *(_WORD *)(v12 + 4) = a2;
  *(_WORD *)(v12 + 8) = a3;
  *(_QWORD *)(v13 + 14) = v16 - v15 + 1;
  v17 = ghd_rm_mem_share(0, 0, v14, v12, v13, 0, a1 + 22);
  if ( v17 )
  {
    dev_err(*a1, "Gunyah mem share addr=%llx size=%llu failed: %d\n", a1[7], a1[20], v17);
    if ( (unsigned int)qcom_scm_assign_mem(a1[7], a1[8] - a1[7] + 1LL, &v25, v26, 1, v23) )
      dev_err(*a1, "qcom_scm_assign_mem addr=%llx size=%llu failed: %d\n", a1[7], a1[20], v17);
  }
  kfree(v12);
  kfree(v13);
  result = v17;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
