__int64 __fastcall cam_vfe_camif_lite_err_irq_top_half_0(__int64 a1, __int64 *a2)
{
  __int64 v2; // x23
  _QWORD *v3; // x20
  int *v4; // x8
  int v6; // w9
  int v7; // w8
  int v8; // w22
  __int64 result; // x0
  __int64 v10; // x21
  __int64 timestamp; // x0
  __int64 v12; // x1
  int v13; // w24
  char v14; // w22
  unsigned int v15; // w23
  int v16; // w8
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v3 = *(_QWORD **)(*a2 + 24);
  if ( !*(_QWORD *)(v3[5] + 3296LL) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_err_irq_top_half",
      115,
      "Invalid soc_private");
    result = 4294967277LL;
LABEL_25:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v4 = (int *)a2[2];
  v6 = v4[2];
  v7 = *v4;
  if ( v6 || (*(_DWORD *)(v3[4] + 36LL) & v7) != 0 )
  {
    v8 = 1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_err_irq_top_half",
      130,
      "VFE:%d CAMIF LITE:%d Err IRQ status_1: 0x%X status_2: 0x%X",
      *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL),
      *(_DWORD *)(v2 + 4),
      v7,
      v6);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_err_irq_top_half",
      132,
      "Stopping further IRQ processing from VFE:%d",
      *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL));
    cam_irq_controller_disable_all(v3[16]);
  }
  else
  {
    v8 = 0;
  }
  v17[0] = 0;
  result = cam_vfe_camif_lite_get_evt_payload_0(v3, v17);
  if ( (_DWORD)result )
    goto LABEL_25;
  v10 = v17[0];
  timestamp = cam_isp_hw_get_timestamp((__int64 *)(v17[0] + 40LL));
  if ( v8 )
  {
    v3[2842] = *(__int64 *)((char *)&qword_28 + v10);
    v3[2843] = *(__int64 *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v10);
  }
  if ( *((_DWORD *)a2 + 2) )
  {
    *(_DWORD *)((char *)&qword_10 + v10) = *(_DWORD *)a2[2];
    if ( *((_DWORD *)a2 + 2) <= 1u )
    {
      v14 = 0;
      v13 = 1;
      v15 = 1;
    }
    else
    {
      *(_DWORD *)((char *)&qword_10 + v10 + 4) = *(_DWORD *)(a2[2] + 4);
      if ( *((_DWORD *)a2 + 2) < 3u )
      {
        v14 = 0;
        v15 = 2;
        v13 = 1;
      }
      else
      {
        *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v10) = *(_DWORD *)(a2[2] + 8);
        if ( *((_DWORD *)a2 + 2) < 4u )
        {
          v14 = 0;
          v15 = 3;
          v13 = 1;
        }
        else
        {
          *(_DWORD *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v10 + 4) = *(_DWORD *)(a2[2] + 12);
          if ( *((_DWORD *)a2 + 2) < 5u )
          {
            v15 = 4;
            v13 = 1;
            v14 = 1;
          }
          else
          {
            *(int *)((char *)&dword_20 + v10) = *(_DWORD *)(a2[2] + 16);
            if ( *((_DWORD *)a2 + 2) > 5u )
              goto LABEL_26;
            v13 = 0;
            v14 = 0;
            v15 = 5;
          }
        }
      }
    }
  }
  else
  {
    v14 = 0;
    v15 = 0;
    v13 = 1;
  }
  timestamp = cam_io_r(*v3 + *(unsigned int *)(v3[3] + 68LL));
  if ( v13 )
  {
    *(_DWORD *)(v10 + 16 + 4LL * v15) = timestamp;
    timestamp = cam_io_r(*v3 + *(unsigned int *)(v3[3] + 92LL));
    if ( (v14 & 1) == 0 )
    {
      v16 = timestamp;
      result = 0;
      *(_DWORD *)(v10 + 16 + 4LL * (v15 + 1)) = v16;
      a2[3] = v10;
      goto LABEL_25;
    }
  }
LABEL_26:
  __break(0x5512u);
  return cam_vfe_camif_lite_get_evt_payload_0(timestamp, v12);
}
