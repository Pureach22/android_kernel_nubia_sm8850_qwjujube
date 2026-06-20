__int64 __fastcall synx_hwfence_create_helper(unsigned int *a1, __int64 a2, _DWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x21
  unsigned int v10; // w0
  __int64 v11; // x0
  __int64 result; // x0
  unsigned int v13; // w19
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  unsigned __int64 v17; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v18[5]; // [xsp+8h] [xbp-28h] BYREF

  v7 = v5;
  v18[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[2] = a2;
  v18[3] = 0;
  v17 = 0;
  v18[0] = 0;
  v18[1] = &v17;
  v10 = msm_hw_fence_create(a1, (__int64)v18, (__int64)a3, a4, a5);
  if ( v10 )
  {
    v13 = v10;
    printk(&unk_2523B, "synx_hwfence_create_helper", 200, v7, a2);
    v11 = v13;
  }
  else
  {
    if ( HIDWORD(v17) )
    {
      printk(&unk_234A9, "synx_hwfence_create_helper", 204, v7, v17);
      hw_fence_destroy_refcount(hw_fence_drv_data, v17, 0x80000000);
      msm_hw_fence_destroy_with_handle(a1, v17, v14, v15, v16);
      result = 4294967274LL;
      goto LABEL_5;
    }
    v11 = 0;
    *a3 = v17 | 0x80000000;
  }
  result = hw_fence_interop_to_synx_status(v11);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
