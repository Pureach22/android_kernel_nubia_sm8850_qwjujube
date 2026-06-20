__int64 __fastcall cam_icp_alloc_secheap_mem(__int64 a1, _QWORD *a2)
{
  int v4; // w0
  unsigned int region_info; // w0
  const char *v6; // x5
  __int64 v7; // x6
  unsigned int v8; // w19
  __int64 v9; // x4
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // [xsp+18h] [xbp-88h] BYREF
  __int64 v15; // [xsp+20h] [xbp-80h]
  __int64 v16; // [xsp+28h] [xbp-78h]
  __int64 v17; // [xsp+30h] [xbp-70h]
  __int64 v18; // [xsp+38h] [xbp-68h]
  __int64 v19; // [xsp+40h] [xbp-60h]
  __int64 v20; // [xsp+48h] [xbp-58h]
  __int64 v21; // [xsp+50h] [xbp-50h]
  __int64 v22; // [xsp+58h] [xbp-48h] BYREF
  __int64 v23; // [xsp+60h] [xbp-40h]
  __int64 v24; // [xsp+68h] [xbp-38h]
  __int64 v25; // [xsp+70h] [xbp-30h]
  __int64 v26; // [xsp+78h] [xbp-28h]
  _QWORD v27[4]; // [xsp+80h] [xbp-20h] BYREF

  v27[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 148);
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  region_info = cam_smmu_get_region_info(v4, 4, &v14);
  if ( region_info )
  {
    v6 = "[%s] Unable to get secheap memory info";
    v7 = a1 + 112;
    v8 = region_info;
    v9 = 3744;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_alloc_secheap_mem",
      v9,
      v6,
      v7);
    result = v8;
    goto LABEL_6;
  }
  v27[0] = v15;
  v27[1] = 0;
  v27[2] = *(unsigned int *)(a1 + 148);
  result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64 *))cam_mem_mgr_reserve_memory_region)(v27, 4, &v22);
  if ( (_DWORD)result )
  {
    v6 = "[%s] Unable to reserve secheap memory";
    v7 = a1 + 112;
    v8 = result;
    v9 = 3756;
    goto LABEL_5;
  }
  v11 = v26;
  v12 = v24;
  a2[3] = v25;
  a2[4] = v11;
  v13 = v22;
  a2[1] = v23;
  a2[2] = v12;
  *a2 = v13;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_alloc_secheap_mem",
      3762,
      "[%s] kva: %llX, iova: %x, hdl: %x, len: %lld",
      (const char *)(a1 + 112),
      v22,
      v23,
      v24,
      v25);
    result = 0;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
