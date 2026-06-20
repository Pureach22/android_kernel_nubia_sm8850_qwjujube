__int64 __fastcall cam_icp_dev_iommu_fault_handler(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 result; // x0
  unsigned int v5; // w9
  int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x8
  const char *v9; // x5
  __int64 v10; // x6
  __int64 v11; // x4
  int v12; // w20
  __int64 v13; // x0
  unsigned int v14; // w9
  __int64 v15[6]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v16; // [xsp+38h] [xbp-18h]
  __int64 v17; // [xsp+40h] [xbp-10h]
  __int64 v18; // [xsp+48h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  memset(&v15[1], 0, 40);
  if ( !a1 || (v1 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_dev_iommu_fault_handler",
               96,
               "invalid token in page handler cb");
    goto LABEL_18;
  }
  v2 = *(_DWORD *)(v1 + 104);
  v15[0] = a1;
  if ( !v2 )
    goto LABEL_16;
  result = (__int64)cam_smmu_is_fault_ids_valid((_DWORD *)a1);
  v5 = *(_DWORD *)(v1 + 104);
  if ( (result & 1) != 0 )
  {
    if ( v5 )
    {
      v6 = 0;
      while ( 1 )
      {
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_dev_iommu_fault_handler",
            107,
            "Node name %s ctx_idx %d",
            (const char *)v1,
            v6);
        v7 = *(_QWORD *)(v1 + 96) + 552LL * v6;
        BYTE1(v17) = 1;
        result = cam_context_dump_pf_info(v7, (__int64)v15);
        if ( HIDWORD(v17) )
          break;
        v5 = *(_DWORD *)(v1 + 104);
        if ( ++v6 >= v5 )
          goto LABEL_15;
      }
      if ( HIDWORD(v17) == 1 )
      {
        v9 = "pid %d was not found for %s";
        v10 = *(unsigned int *)(v15[0] + 48);
        v11 = 114;
        goto LABEL_17;
      }
      v5 = *(_DWORD *)(v1 + 104);
      goto LABEL_15;
    }
LABEL_16:
    v9 = "All contexts are inactive. PID %d was not found for %s";
    v10 = *(unsigned int *)(v15[0] + 48);
    v11 = 123;
LABEL_17:
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
               3,
               256,
               3,
               "cam_icp_dev_iommu_fault_handler",
               v11,
               v9,
               v10,
               v1);
    goto LABEL_18;
  }
  v6 = 0;
LABEL_15:
  v8 = a1;
  if ( v6 == v5 )
    goto LABEL_16;
  if ( !v5 )
    goto LABEL_34;
  v12 = 0;
  while ( 1 )
  {
    v13 = *(_QWORD *)(v1 + 96) + 552LL * v12;
    BYTE1(v17) = 0;
    result = cam_context_dump_pf_info(v13, (__int64)v15);
    if ( (unsigned __int8)v16 == 1 )
      break;
    v14 = *(_DWORD *)(v1 + 104);
    if ( ++v12 >= v14 )
    {
      v8 = a1;
      goto LABEL_27;
    }
  }
  v8 = a1;
  *(_BYTE *)(a1 + 59) = 1;
  v14 = *(_DWORD *)(v1 + 104);
LABEL_27:
  if ( v12 == v14 )
  {
LABEL_34:
    if ( *(_BYTE *)(v8 + 58) == 1 )
    {
      result = cam_context_send_pf_evt(0, v15);
      if ( (_DWORD)result )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   256,
                   1,
                   "cam_icp_dev_iommu_fault_handler",
                   142,
                   "Failed to notify PF event to userspace rc: %d",
                   result);
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
