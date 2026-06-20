__int64 __fastcall cam_ife_csid_ver2_process_cmd(__int64 a1, int a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x4
  __int64 v9; // x8
  int v10; // w8
  unsigned int v11; // w20

  if ( a1 && a3 )
  {
    v4 = *(_QWORD *)(a1 + 3680);
    result = 0;
    switch ( a2 )
    {
      case 0:
        return ((__int64 (__fastcall *)(__int64, _QWORD))cam_ife_csid_get_base)(a1 + 96, 0);
      case 3:
        return cam_ife_csid_ver2_reg_update(v4, a3, a4);
      case 21:
        return cam_ife_csid_ver2_set_csid_clock(v4, a3);
      case 30:
        result = 0;
        *(_QWORD *)a3 = *(_QWORD *)(v4 + 31128) + 96LL;
        return result;
      case 33:
      case 42:
      case 49:
        return result;
      case 44:
        if ( v4 )
        {
          v9 = *(_QWORD *)(**(_QWORD **)(v4 + 31136) + 120LL);
          if ( *(_DWORD *)(v9 + 552) )
          {
            v10 = *(_DWORD *)(v9 + 592);
            result = 0;
            if ( !v10 )
              v10 = 2;
          }
          else
          {
            result = 0;
            v10 = 1;
          }
        }
        else
        {
          v10 = 0;
          result = 4294967274LL;
        }
        *(_DWORD *)(a3 + 24) = v10;
        *(_DWORD *)(a3 + 12) = *(_DWORD *)(*(_QWORD *)(**(_QWORD **)(v4 + 31136) + 120LL) + 692LL);
        return result;
      case 45:
        result = cam_ife_csid_ver2_get_time_stamp(v4, a3);
        if ( (*(_BYTE *)(v4 + 2168) & 0x80) != 0 )
        {
          v11 = result;
          ((void (__fastcall *)(__int64))cam_ife_csid_ver2_print_hbi_vbi)(v4);
          result = v11;
        }
        *(_DWORD *)(v4 + 2140) = 0;
        return result;
      case 46:
        cam_ife_csid_ver2_set_debug(v4, a3);
        return 0;
      case 47:
        cam_ife_csid_ver2_sof_irq_debug(v4, a3);
        return 0;
      case 48:
        cam_ife_csid_ver2_eof_irq_enable(v4, a3);
        return 0;
      case 50:
        return cam_ife_csid_ver2_top_cfg(v4, a3);
      case 51:
        return cam_ife_csid_ver2_program_offline_go_cmd(v4, a3, a4);
      case 52:
        return cam_ife_csid_ver2_dual_sync_cfg(v4, a3);
      case 53:
        return cam_ife_csid_ver2_reset_out_of_sync_cnt(a3);
      case 54:
        return cam_ife_csid_ver2_set_dynamic_switch_config(v4, a3);
      case 55:
        return cam_ife_csid_ver2_set_discard_frame_cfg(v4, a3);
      case 67:
        return cam_ife_csid_init_config_update(a3, a4);
      case 68:
        cam_ife_csid_ver2_mini_dump(v4, a3);
        return 0;
      case 71:
        return cam_ife_csid_ver2_user_dump(v4, a3);
      case 72:
        return cam_ife_csid_ver2_rdi_lcr_cfg(v4, a3);
      case 73:
        return cam_ife_csid_ver2_drv_config(v4, a3);
      case 74:
        return cam_ife_csid_ver2_dump_crop_reg(a1, a3);
      case 76:
        return cam_ife_csid_ver2_irq_comp_cfg(v4, a3, a4);
      case 77:
        return cam_ife_csid_ver2_irq_inject(v4, a3);
      case 78:
        return cam_ife_csid_ver2_dump_irq_desc(v4, a3);
      case 79:
        if ( (*(_BYTE *)(a3 + 20) & 1) != 0 )
          return cam_ife_csid_ver2_get_primary_sof_timer_reg_addr(v4, a3);
        v7 = "CSID does not support set of primary SOF ts addr";
        v8 = 9254;
        break;
      case 83:
        return ((__int64 (__fastcall *)(__int64, __int64))cam_ife_csid_ver2_path_exp_info_update)(v4, a3);
      default:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_process_cmd",
          9278,
          "CSID:%u unsupported cmd:%d",
          *(unsigned int *)(*(_QWORD *)(v4 + 31120) + 4LL));
        return 4294967274LL;
    }
  }
  else
  {
    v7 = "CSID: Invalid arguments";
    v8 = 9147;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_process_cmd",
    v8,
    v7);
  return 4294967274LL;
}
