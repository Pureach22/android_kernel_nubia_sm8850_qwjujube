__int64 __fastcall cam_ife_csid_ver1_hw_reset(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x21
  __int64 v4; // x23
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x7
  __int64 result; // x0
  const char *v9; // x5
  __int64 v10; // x1
  __int64 v11; // x6
  __int64 v12; // x4
  __int64 v13; // x0

  v1 = *(_QWORD *)(a1 + 8);
  v3 = a1 + 24576;
  v4 = **(_QWORD **)(a1 + 16);
  *(_DWORD *)(a1 + 26504) = 0;
  v5 = raw_spin_lock_irqsave(v1 + 48);
  *(_BYTE *)(v3 + 3740) = 1;
  cam_io_w_mb(1, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 32LL));
  cam_io_w_mb(1, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 40LL));
  cam_io_w_mb(1, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 28LL));
  cam_io_w_mb(1, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 40LL));
  cam_io_w_mb(
    *(unsigned int *)(*(_QWORD *)(v4 + 96) + 168LL),
    *(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 16LL));
  raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 8) + 48LL, v5);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_hw_reset",
      445,
      "CSID reset start");
  v6 = cam_common_wait_for_completion_timeout(v3 + 1928);
  if ( v6 )
  {
    v7 = v6;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v9 = "CSID:%d hw reset completed %d";
      v10 = debug_mdl & 8;
      v11 = *(unsigned int *)(*(_QWORD *)a1 + 4LL);
      v12 = 471;
LABEL_14:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        v10,
        4,
        "cam_ife_csid_ver1_hw_reset",
        v12,
        v9,
        v11,
        v7);
      result = 0;
    }
  }
  else
  {
    v13 = cam_io_r_mb(*(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 24LL));
    if ( (v13 & 1) != 0 )
    {
      cam_io_w_mb(v13, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 32LL));
      cam_io_w_mb(1, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 96) + 40LL));
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v9 = "CSID:%d HW reset completed %d";
        v10 = debug_mdl & 8;
        v11 = *(unsigned int *)(*(_QWORD *)a1 + 4LL);
        v12 = 462;
        v7 = 0;
        goto LABEL_14;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_hw_reset",
        466,
        "CSID:%d hw csid_reset fail rc = %d",
        0);
      result = 4294967186LL;
    }
  }
  *(_BYTE *)(v3 + 3740) = 0;
  return result;
}
