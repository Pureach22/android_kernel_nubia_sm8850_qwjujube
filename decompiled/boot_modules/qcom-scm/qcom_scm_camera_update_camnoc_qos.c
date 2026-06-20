__int64 __fastcall qcom_scm_camera_update_camnoc_qos(
        void *a1,
        __int64 a2,
        const void *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  size_t v8; // x19
  void *v9; // x20
  void *v11; // x0
  __int64 v12; // x21
  int convention; // w0
  __int64 v14; // x2
  __int64 result; // x0
  unsigned int v16; // w21
  __int64 v17; // [xsp+8h] [xbp-78h] BYREF
  __int64 v18; // [xsp+10h] [xbp-70h] BYREF
  int v19; // [xsp+18h] [xbp-68h]
  int v20; // [xsp+1Ch] [xbp-64h]
  __int64 v21; // [xsp+20h] [xbp-60h]
  _QWORD v22[11]; // [xsp+28h] [xbp-58h] BYREF

  v22[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v17 = 0;
  v18 = 0xA00000018LL;
  v19 = 131;
  memset(v22, 0, 72);
  v21 = (unsigned int)a1;
  v22[9] = 2;
  if ( (unsigned int)a2 > 0x14 || (_DWORD)a2 && !a3 )
  {
    printk(&unk_11EA2, "qcom_scm_camera_update_camnoc_qos", (unsigned int)a2);
    result = 4294967274LL;
    goto LABEL_17;
  }
  v8 = (unsigned int)(8 * a2);
  v9 = nullptr;
  if ( (_DWORD)a1 && (_DWORD)a2 && a3 )
  {
    v11 = (void *)dma_alloc_attrs(*(_QWORD *)_scm, (unsigned int)(8 * a2), &v17, 3264, 0);
    if ( !v11 )
    {
      result = 4294967284LL;
      goto LABEL_17;
    }
    v9 = v11;
    a1 = memcpy(v11, a3, v8);
    v22[0] = v17;
    v22[1] = v8;
  }
  v12 = *(_QWORD *)_scm;
  convention = _get_convention(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)(convention - 2) < 2 )
  {
    result = _scm_smc_call(v12, &v18, qcom_scm_convention, nullptr, 0);
    if ( !v9 )
      goto LABEL_17;
    goto LABEL_14;
  }
  if ( convention != 1 )
  {
    printk(&unk_124E9, "qcom_scm_call", v14);
    result = 4294967274LL;
    if ( !v9 )
      goto LABEL_17;
    goto LABEL_14;
  }
  result = scm_legacy_call(v12, (__int64)&v18, nullptr);
  if ( v9 )
  {
LABEL_14:
    v16 = result;
    dma_free_attrs(*(_QWORD *)_scm, v8, v9, v17, 0);
    result = v16;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
