__int64 __fastcall qrtr_gunyah_share_mem(
        __int64 a1,
        unsigned __int16 a2,
        unsigned __int16 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v9; // x0
  __int64 v10; // x8
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
  _DWORD v26[4]; // [xsp+10h] [xbp-20h] BYREF
  _DWORD v27[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = a2;
  v27[1] = 7;
  v9 = *(_QWORD *)(a1 + 56);
  v26[0] = a2;
  v26[1] = 6;
  v26[2] = a3;
  v26[3] = 6;
  v10 = *(_QWORD *)(a1 + 64) - v9;
  v24 = (1LL << a3) | (1LL << a2);
  v25 = 1LL << a2;
  v11 = qcom_scm_assign_mem(v9, v10 + 1, &v25, v26, 2, a6);
  if ( v11 )
  {
    v19 = *(_QWORD *)(a1 + 24);
    v20 = *(_QWORD *)(a1 + 56);
    v21 = *(_QWORD *)(a1 + 168);
    v22 = v11;
    dev_err(v19, "qcom_scm_assign_mem failed addr=%llx size=%zu err=%d\n", v20, v21, v11);
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
  v13 = _kmalloc_cache_noprof(MEMORY[0x98C8], 3520, 22);
  if ( !v13 )
  {
    kfree(v12);
    goto LABEL_10;
  }
  v14 = *(unsigned int *)(a1 + 260);
  *(_DWORD *)v12 = 2;
  v15 = *(_QWORD *)(a1 + 56);
  v16 = *(_QWORD *)(a1 + 64);
  *(_BYTE *)(v12 + 6) = 6;
  *(_BYTE *)(v12 + 10) = 6;
  *(_DWORD *)v13 = 1;
  *(_QWORD *)(v13 + 6) = v15;
  *(_WORD *)(v12 + 4) = a2;
  *(_WORD *)(v12 + 8) = a3;
  *(_QWORD *)(v13 + 14) = v16 - v15 + 1;
  v17 = ghd_rm_mem_share(0, 0, v14, v12, v13, 0, a1 + 152);
  if ( v17 )
  {
    dev_err(
      *(_QWORD *)(a1 + 24),
      "gh_rm_mem_share failed addr=%llx size=%lu err=%d\n",
      *(_QWORD *)(a1 + 56),
      *(_QWORD *)(a1 + 168),
      v17);
    if ( (unsigned int)qcom_scm_assign_mem(
                         *(_QWORD *)(a1 + 56),
                         *(_QWORD *)(a1 + 64) - *(_QWORD *)(a1 + 56) + 1LL,
                         &v24,
                         v27,
                         1,
                         v23) )
      dev_err(
        *(_QWORD *)(a1 + 24),
        "qcom_scm_assign_mem failed addr=%llx size=%lu err=%d\n",
        *(_QWORD *)(a1 + 56),
        *(_QWORD *)(a1 + 168),
        v17);
  }
  kfree(v12);
  kfree(v13);
  result = v17;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
