__int64 __fastcall cam_ife_csid_ver1_disable_csi2(__int64 result)
{
  _BYTE *v1; // x19
  __int64 v2; // x21
  __int64 v3; // x22
  const char *v4; // x5
  __int64 v5; // x1
  __int64 v6; // x6
  __int64 v7; // x4

  v1 = (_BYTE *)result;
  if ( (*(_BYTE *)(result + 28318) & 1) != 0 )
  {
    v2 = *(_QWORD *)(result + 8);
    v3 = **(_QWORD **)(result + 16);
    cam_io_w_mb(0, *(_QWORD *)(v2 + 384) + *(unsigned int *)(*(_QWORD *)v3 + 4LL));
    cam_io_w_mb(0, *(_QWORD *)(v2 + 384) + *(unsigned int *)(*(_QWORD *)v3 + 16LL));
    result = cam_io_w_mb(0, *(_QWORD *)(v2 + 384) + *(unsigned int *)(*(_QWORD *)v3 + 20LL));
    v1[28318] = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v4 = "CSID:%d Disable csi2 rx";
      v5 = debug_mdl & 8;
      v6 = *(unsigned int *)(*(_QWORD *)v1 + 4LL);
      v7 = 2879;
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
               3,
               v5,
               4,
               "cam_ife_csid_ver1_disable_csi2",
               v7,
               v4,
               v6);
    }
  }
  else if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v4 = "CSID:%d Rx already disabled";
    v5 = debug_mdl & 8;
    v6 = *(unsigned int *)(*(_QWORD *)result + 4LL);
    v7 = 2863;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             v5,
             4,
             "cam_ife_csid_ver1_disable_csi2",
             v7,
             v4,
             v6);
  }
  return result;
}
