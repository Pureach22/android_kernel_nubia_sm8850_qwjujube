__int64 __fastcall gh_panic_notifier_share_mem(_QWORD *a1, unsigned __int16 a2, unsigned __int16 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  int v8; // w0
  __int64 v9; // x20
  __int64 v10; // x23
  __int64 v11; // x2
  __int64 v12; // x8
  __int64 v13; // x10
  unsigned int v14; // w21
  __int64 result; // x0
  __int64 v16; // x2
  __int64 v17; // x8
  __int64 v18; // x3
  unsigned int v19; // w19
  __int64 v20; // [xsp+0h] [xbp-30h] BYREF
  __int64 v21; // [xsp+8h] [xbp-28h] BYREF
  _DWORD v22[2]; // [xsp+10h] [xbp-20h] BYREF
  _DWORD v23[4]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = a2;
  v23[1] = 6;
  v6 = a1[1];
  v7 = a1[14];
  v23[2] = a3;
  v23[3] = 6;
  v22[0] = v23[0];
  v22[1] = 7;
  v20 = 1LL << a2;
  v21 = (1LL << a3) | (1LL << a2);
  v8 = qcom_scm_assign_mem(v6, v7, &v20, v23, 2);
  if ( v8 )
  {
    v17 = *a1;
    v16 = a1[1];
    v18 = a1[14];
    v19 = v8;
    dev_err(v17, "qcom_scm_assign_mem addr=%llx size=%llu failed: %d\n", v16, v18, v8);
    result = v19;
    goto LABEL_11;
  }
  v9 = _kmalloc_cache_noprof(gh_rm_register_notifier, 3520, 12);
  if ( !v9 )
  {
LABEL_10:
    result = 4294967284LL;
    goto LABEL_11;
  }
  v10 = _kmalloc_cache_noprof(gh_dbl_tx_unregister, 3520, 22);
  if ( !v10 )
  {
    kfree(v9);
    goto LABEL_10;
  }
  v11 = *((unsigned int *)a1 + 30);
  *(_DWORD *)v9 = 2;
  v12 = a1[1];
  v13 = a1[2];
  *(_BYTE *)(v9 + 6) = 6;
  *(_BYTE *)(v9 + 10) = 6;
  *(_DWORD *)v10 = 1;
  *(_QWORD *)(v10 + 6) = v12;
  *(_WORD *)(v9 + 4) = a2;
  *(_WORD *)(v9 + 8) = a3;
  *(_QWORD *)(v10 + 14) = v13 - v12 + 1;
  v14 = ghd_rm_mem_share(0, 0, v11, v9, v10, 0, a1 + 16);
  if ( v14 )
  {
    dev_err(*a1, "Gunyah mem share addr=%llx size=%llu failed: %d\n", a1[1], a1[14], v14);
    if ( (unsigned int)qcom_scm_assign_mem(a1[1], a1[14], &v21, v22, 1) )
      dev_err(*a1, "qcom_scm_assign_mem addr=%llx size=%llu failed: %d\n", a1[1], a1[14], v14);
  }
  kfree(v9);
  kfree(v10);
  result = v14;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
