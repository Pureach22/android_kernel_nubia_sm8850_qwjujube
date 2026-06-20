__int64 __fastcall cam_vfe_rdi_err_irq_top_half(__int64 a1, __int64 *a2)
{
  __int64 v3; // x23
  int v4; // w21
  _QWORD *v5; // x22
  unsigned int evt_payload; // w20
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x23
  __int64 timestamp; // x0
  __int64 v11; // x1
  int v12; // w24
  __int64 v13; // x25
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_rdi_err_irq_top_half",
      102,
      "IRQ status_1 = %x",
      *(_DWORD *)(a2[2] + 4));
  v3 = *a2;
  v4 = *(_DWORD *)(a2[2] + 4);
  v5 = *(_QWORD **)(*a2 + 24);
  if ( v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_rdi_err_irq_top_half",
      114,
      "RDI Error: vfe:%d: STATUS_1=0x%x",
      *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL),
      v4);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_rdi_err_irq_top_half",
      116,
      "Stopping further IRQ processing from vfe=%d",
      *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL));
    cam_irq_controller_disable_all(v5[11]);
  }
  v15[0] = 0;
  evt_payload = cam_vfe_rdi_get_evt_payload(v5, v15);
  if ( evt_payload )
  {
    if ( (unsigned int)__ratelimit(&cam_vfe_rdi_err_irq_top_half__rs, "cam_vfe_rdi_err_irq_top_half") )
      v7 = 3;
    else
      v7 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v7,
      8,
      1,
      "cam_vfe_rdi_err_irq_top_half",
      125,
      "No tasklet_cmd is free in queue");
    if ( (unsigned int)__ratelimit(&cam_vfe_rdi_err_irq_top_half__rs_16, "cam_vfe_rdi_err_irq_top_half") )
      v8 = 3;
    else
      v8 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      v8,
      8,
      1,
      "cam_vfe_rdi_err_irq_top_half",
      127,
      "STATUS_1=0x%x",
      *(unsigned int *)(a2[2] + 4));
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return evt_payload;
  }
  v9 = v15[0];
  timestamp = cam_isp_hw_get_timestamp((__int64 *)(v15[0] + 40LL));
  if ( v4 )
  {
    v5[2833] = *(__int64 *)((char *)&qword_28 + v9);
    v5[2834] = *(__int64 *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v9);
  }
  if ( *((_DWORD *)a2 + 2) )
  {
    *(_DWORD *)((char *)&qword_10 + v9) = *(_DWORD *)a2[2];
    if ( *((_DWORD *)a2 + 2) <= 1u )
    {
      v12 = 1;
      v13 = 1;
    }
    else
    {
      *(_DWORD *)((char *)&qword_10 + v9 + 4) = *(_DWORD *)(a2[2] + 4);
      if ( *((_DWORD *)a2 + 2) < 3u )
      {
        v12 = 1;
        v13 = 2;
      }
      else
      {
        *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v9) = *(_DWORD *)(a2[2] + 8);
        if ( *((_DWORD *)a2 + 2) < 4u )
        {
          v12 = 1;
          v13 = 3;
        }
        else
        {
          *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v9 + 4) = *(_DWORD *)(a2[2] + 12);
          if ( *((_DWORD *)a2 + 2) < 5u )
          {
            v12 = 1;
            v13 = 4;
          }
          else
          {
            *(int *)((char *)&dword_20 + v9) = *(_DWORD *)(a2[2] + 16);
            if ( *((_DWORD *)a2 + 2) > 5u )
              goto LABEL_33;
            v12 = 0;
            v13 = 5;
          }
        }
      }
    }
  }
  else
  {
    v13 = 0;
    v12 = 1;
  }
  timestamp = cam_io_r(*v5 + *(unsigned int *)(v5[2] + 76LL));
  if ( v12 )
  {
    *(_DWORD *)(v9 + 4 * v13 + 16) = timestamp;
    if ( v4 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_rdi_err_irq_top_half",
        147,
        "Violation status = 0x%x",
        timestamp);
    a2[3] = v9;
    goto LABEL_32;
  }
LABEL_33:
  __break(0x5512u);
  return cam_vfe_rdi_get_evt_payload(timestamp, v11);
}
