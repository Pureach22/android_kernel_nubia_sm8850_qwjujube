__int64 __fastcall cam_vfe_camif_ver3_err_irq_top_half(__int64 a1, __int64 *a2)
{
  int *v3; // x9
  __int64 v4; // x22
  int v5; // w8
  _QWORD *v6; // x20
  int v7; // w7
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x22
  __int64 timestamp; // x0
  __int64 v12; // x1
  int v13; // w25
  char v14; // w23
  unsigned int v15; // w24
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (int *)a2[2];
  v4 = *a2;
  v5 = v3[2];
  v6 = *(_QWORD **)(*a2 + 24);
  v7 = *v3;
  if ( v5 || (*(_DWORD *)(v6[4] + 76LL) & v7) != 0 )
  {
    v8 = 1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_err_irq_top_half",
      139,
      "VFE:%d CAMIF Err IRQ status_0: 0x%X status_2: 0x%X",
      *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL),
      v7,
      v5);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_err_irq_top_half",
      141,
      "Stopping further IRQ processing from VFE:%d",
      *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL));
    cam_irq_controller_disable_all(v6[16]);
  }
  else
  {
    v8 = 0;
  }
  v16[0] = 0;
  result = cam_vfe_camif_ver3_get_evt_payload(v6, v16);
  if ( (_DWORD)result )
    goto LABEL_23;
  v10 = v16[0];
  timestamp = cam_isp_hw_get_timestamp((__int64 *)(v16[0] + 40LL));
  if ( v8 )
  {
    v6[2850] = *(__int64 *)((char *)&qword_28 + v10);
    v6[2851] = *(__int64 *)((char *)&_ksymtab_cam_cdm_get_iommu_handle + v10);
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
              goto LABEL_24;
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
  timestamp = cam_io_r(*v6 + *(unsigned int *)(v6[3] + 68LL));
  if ( v13 )
  {
    *(_DWORD *)(v10 + 16 + 4LL * v15) = timestamp;
    timestamp = cam_io_r(*v6 + *(unsigned int *)(v6[3] + 92LL));
    if ( (v14 & 1) == 0 )
    {
      *(_DWORD *)(v10 + 16 + 4LL * (v15 + 1)) = timestamp;
      result = 0;
      a2[3] = v10;
LABEL_23:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
LABEL_24:
  __break(0x5512u);
  return cam_vfe_camif_ver3_get_evt_payload(timestamp, v12);
}
