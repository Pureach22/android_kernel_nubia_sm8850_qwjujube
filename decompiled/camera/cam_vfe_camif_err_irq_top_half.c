__int64 __fastcall cam_vfe_camif_err_irq_top_half(__int64 a1, __int64 *a2)
{
  int *v3; // x9
  __int64 v4; // x23
  int v5; // w7
  int v6; // w8
  _QWORD *v7; // x21
  int v8; // w22
  unsigned int evt_payload; // w20
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x23
  __int64 timestamp; // x0
  __int64 v14; // x1
  int v15; // w24
  __int64 v16; // x25
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_err_irq_top_half",
      121,
      "IRQ status_0 = %x, IRQ status_1 = %x",
      *(_DWORD *)a2[2],
      *(_DWORD *)(a2[2] + 4));
  v3 = (int *)a2[2];
  v4 = *a2;
  v5 = *v3;
  v6 = v3[1];
  v7 = *(_QWORD **)(*a2 + 24);
  if ( v6 || (*(_DWORD *)(v7[4] + 96LL) & v5) != 0 )
  {
    v8 = 1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_err_irq_top_half",
      135,
      "Camif Error: vfe:%d: IRQ STATUS_0=0x%x STATUS_1=0x%x",
      *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL),
      v5,
      v6);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_err_irq_top_half",
      137,
      "Stopping further IRQ processing from vfe=%d",
      *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL));
    cam_irq_controller_disable_all(v7[9]);
  }
  else
  {
    v8 = 0;
  }
  v18[0] = 0;
  evt_payload = cam_vfe_camif_get_evt_payload(v7, v18);
  if ( evt_payload )
  {
    if ( (unsigned int)__ratelimit(&cam_vfe_camif_err_irq_top_half__rs, "cam_vfe_camif_err_irq_top_half") )
      v10 = 3;
    else
      v10 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v10,
      8,
      1,
      "cam_vfe_camif_err_irq_top_half",
      146,
      "No tasklet_cmd is free in queue");
    if ( (unsigned int)__ratelimit(&cam_vfe_camif_err_irq_top_half__rs_24, "cam_vfe_camif_err_irq_top_half") )
      v11 = 3;
    else
      v11 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
      v11,
      8,
      1,
      "cam_vfe_camif_err_irq_top_half",
      149,
      "IRQ STATUS_0=0x%x STATUS_1=0x%x",
      *(unsigned int *)a2[2],
      *(unsigned int *)(a2[2] + 4));
LABEL_34:
    _ReadStatusReg(SP_EL0);
    return evt_payload;
  }
  v12 = v18[0];
  timestamp = cam_isp_hw_get_timestamp((__int64 *)(v18[0] + 40LL));
  if ( v8 )
  {
    v7[2842] = *(__int64 *)((char *)&qword_28 + v12);
    v7[2843] = *(__int64 *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v12);
  }
  if ( *((_DWORD *)a2 + 2) )
  {
    *(_DWORD *)((char *)&qword_10 + v12) = *(_DWORD *)a2[2];
    if ( *((_DWORD *)a2 + 2) <= 1u )
    {
      v15 = 1;
      v16 = 1;
    }
    else
    {
      *(_DWORD *)((char *)&qword_10 + v12 + 4) = *(_DWORD *)(a2[2] + 4);
      if ( *((_DWORD *)a2 + 2) < 3u )
      {
        v15 = 1;
        v16 = 2;
      }
      else
      {
        *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v12) = *(_DWORD *)(a2[2] + 8);
        if ( *((_DWORD *)a2 + 2) < 4u )
        {
          v15 = 1;
          v16 = 3;
        }
        else
        {
          *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v12 + 4) = *(_DWORD *)(a2[2] + 12);
          if ( *((_DWORD *)a2 + 2) < 5u )
          {
            v15 = 1;
            v16 = 4;
          }
          else
          {
            *(int *)((char *)&dword_20 + v12) = *(_DWORD *)(a2[2] + 16);
            if ( *((_DWORD *)a2 + 2) > 5u )
              goto LABEL_35;
            v15 = 0;
            v16 = 5;
          }
        }
      }
    }
  }
  else
  {
    v16 = 0;
    v15 = 1;
  }
  timestamp = cam_io_r(*v7 + *(unsigned int *)(v7[3] + 76LL));
  if ( v15 )
  {
    *(_DWORD *)(v12 + 4 * v16 + 16) = timestamp;
    if ( v8 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_err_irq_top_half",
        169,
        "Violation status = 0x%x",
        *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v12));
    a2[3] = v12;
    goto LABEL_34;
  }
LABEL_35:
  __break(0x5512u);
  return cam_vfe_camif_get_evt_payload(timestamp, v14);
}
