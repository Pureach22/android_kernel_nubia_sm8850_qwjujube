__int64 __fastcall cam_vfe_ver4_err_irq_top_half(__int64 a1, __int64 *a2)
{
  __int64 v3; // x23
  _QWORD *v4; // x20
  int v5; // w22
  __int64 result; // x0
  __int64 v7; // x23
  __int64 timestamp; // x0
  __int64 v9; // x1
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = *(_QWORD **)(*a2 + 24);
  v5 = *(_DWORD *)(v4[8] + 20LL) & *(_DWORD *)a2[2];
  if ( v5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_ver4_err_irq_top_half",
      2575,
      "VFE:%u Err IRQ status_0: 0x%X",
      *(unsigned int *)(*(_QWORD *)(v3 + 16) + 4LL));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_ver4_err_irq_top_half",
      2577,
      "Stopping further IRQ processing from VFE:%u",
      *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL));
    cam_irq_controller_disable_all(v4[14]);
  }
  v10[0] = 0;
  result = cam_vfe_get_evt_payload(v4, v10);
  if ( (_DWORD)result )
    goto LABEL_13;
  v7 = v10[0];
  timestamp = cam_isp_hw_get_timestamp((__int64 *)(v10[0] + 40LL));
  if ( v5 )
  {
    v4[2848] = *(__int64 *)((char *)&qword_28 + v7);
    v4[2849] = *(__int64 *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v7);
  }
  if ( !*((_DWORD *)a2 + 2)
    || (*(_DWORD *)((char *)&qword_10 + v7) = *(_DWORD *)a2[2], *((_DWORD *)a2 + 2) <= 1u)
    || (*(_DWORD *)((char *)&qword_10 + v7 + 4) = *(_DWORD *)(a2[2] + 4), *((_DWORD *)a2 + 2) < 3u)
    || (*(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v7) = *(_DWORD *)(a2[2] + 8), *((_DWORD *)a2 + 2) < 4u)
    || (*(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v7 + 4) = *(_DWORD *)(a2[2] + 12),
        *((_DWORD *)a2 + 2) < 5u)
    || (*(int *)((char *)&dword_20 + v7) = *(_DWORD *)(a2[2] + 16), *((_DWORD *)a2 + 2) <= 5u) )
  {
    result = 0;
    a2[3] = v7;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return cam_vfe_get_evt_payload(timestamp, v9);
}
