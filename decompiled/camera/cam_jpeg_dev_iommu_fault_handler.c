__int64 __fastcall cam_jpeg_dev_iommu_fault_handler(__int64 result)
{
  __int64 v1; // x20
  int v2; // w8
  __int64 v3; // x21
  int v4; // w19
  unsigned int v5; // w8
  __int64 v6[6]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v7; // [xsp+38h] [xbp-18h]
  __int64 v8; // [xsp+40h] [xbp-10h]
  __int64 v9; // [xsp+48h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v8 = 0;
  memset(&v6[1], 0, 40);
  if ( result && (v1 = *(_QWORD *)(result + 32)) != 0 )
  {
    v2 = *(_DWORD *)(v1 + 104);
    v6[0] = result;
    if ( v2 )
    {
      v3 = result;
      v4 = 0;
      while ( 1 )
      {
        cam_context_dump_pf_info(*(_QWORD *)(v1 + 96) + 552LL * v4, (__int64)v6);
        if ( (unsigned __int8)v7 == 1 )
          break;
        v5 = *(_DWORD *)(v1 + 104);
        if ( ++v4 >= v5 )
        {
          result = v3;
          if ( v4 != v5 )
            goto LABEL_10;
          goto LABEL_12;
        }
      }
      *(_BYTE *)(v3 + 59) = v7;
      result = v3;
      if ( v4 != *(_DWORD *)(v1 + 104) )
        goto LABEL_10;
    }
LABEL_12:
    if ( *(_BYTE *)(result + 58) == 1 )
    {
      result = cam_context_send_pf_evt(0, v6);
      if ( (_DWORD)result )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   512,
                   1,
                   "cam_jpeg_dev_iommu_fault_handler",
                   76,
                   "Failed to notify PF event to userspace rc: %d",
                   result);
    }
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               512,
               1,
               "cam_jpeg_dev_iommu_fault_handler",
               54,
               "invalid token in page handler cb");
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
