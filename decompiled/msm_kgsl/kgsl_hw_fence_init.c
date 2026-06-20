__int64 __fastcall kgsl_hw_fence_init(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x2
  _QWORD v5[4]; // [xsp+0h] [xbp-20h] BYREF

  v5[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[2] = 1024;
  v5[0] = 0;
  v5[1] = &qword_17D1F8;
  v2 = synx_initialize(v5);
  kgsl_synx = v2;
  if ( v2 && v2 < 0xFFFFFFFFFFFFF001LL )
  {
    result = 0;
    hw_fence_list = (__int64)&hw_fence_list;
    qword_17D230 = (__int64)&hw_fence_list;
    hw_fence_list_lock = 0;
  }
  else
  {
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
      v4 = 0;
    else
      v4 = (unsigned int)v2;
    dev_err(*a1, "HW fences not supported: %d\n", v4);
    result = 4294967274LL;
    kgsl_synx = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
