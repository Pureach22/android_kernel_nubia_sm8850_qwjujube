__int64 __fastcall hw_fence_utils_fence_error_cb(
        unsigned int *a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  _DWORD *v14; // x5
  __int64 v15; // x8
  unsigned int v16; // w20
  _QWORD v18[4]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v19; // [xsp+28h] [xbp-38h]
  __int64 v20; // [xsp+30h] [xbp-30h]
  __int64 v21; // [xsp+38h] [xbp-28h]
  __int64 v22; // [xsp+40h] [xbp-20h]
  __int64 v23; // [xsp+48h] [xbp-18h] BYREF
  _QWORD *v24; // [xsp+50h] [xbp-10h]
  __int64 v25; // [xsp+58h] [xbp-8h]

  v7 = v6;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = nullptr;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  memset(v18, 0, sizeof(v18));
  if ( a1 && (unsigned __int64)a1 < 0xFFFFFFFFFFFFF001LL )
  {
    raw_spin_lock(a1 + 40);
    v14 = *((_DWORD **)a1 + 18);
    if ( a6 && v14 )
    {
      v15 = *((_QWORD *)a1 + 19);
      v19 = a2;
      v20 = a3;
      v21 = a5;
      HIDWORD(v22) = a6;
      v23 = v15;
      v24 = v18;
      if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      {
        printk(&unk_2AEE9, "hw_fence_utils_fence_error_cb", 327, *a1, a2);
        v14 = *((_DWORD **)a1 + 18);
      }
      if ( *(v14 - 1) != 1343075257 )
        __break(0x8225u);
      ((void (__fastcall *)(_QWORD, _QWORD, __int64 *))v14)(a4, a6, &v23);
      v16 = 0;
    }
    else
    {
      printk(&unk_2A8F1, "hw_fence_utils_fence_error_cb", 312, v7, a6);
      v16 = -22;
    }
    raw_spin_unlock(a1 + 40);
  }
  else
  {
    printk(&unk_26C1C, "hw_fence_utils_fence_error_cb", 305, v6, a1);
    v16 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
