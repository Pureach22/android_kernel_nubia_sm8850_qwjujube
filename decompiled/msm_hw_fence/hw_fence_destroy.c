__int64 __fastcall hw_fence_destroy(__int64 a1, unsigned int *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x22
  unsigned int v7; // w6
  unsigned int v8; // w21
  unsigned __int64 v9; // x8
  __int64 result; // x0
  unsigned __int64 v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v6 = v5;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a1 + 80);
  v8 = *a2;
  v11[0] = 0;
  v9 = hw_fence_lookup_and_process_range(a1, a3, a4, a5, v11, 0, v7, (__int64 (__fastcall *)(_QWORD))unreserve_hw_fence);
  result = 0;
  if ( !v9 )
  {
    printk(&unk_2974F, "hw_fence_destroy", 1732, v6, v8);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
