__int64 __fastcall cam_vfe_top_ver4_process_cmd(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 result; // x0
  const char *v8; // x3
  const char *v9; // x5
  __int64 v10; // x6
  __int64 v11; // x4
  __int64 v12; // x8
  __int64 v13; // x8
  int v14; // w9
  unsigned int v15; // w10
  __int64 (*v16)(void); // x8
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  unsigned int v18; // w8
  bool v19; // cf
  __int64 v20; // x8
  unsigned __int64 v21; // x9
  _DWORD *v22; // x11
  int v23; // w13

  if ( !a1 || !a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_process_cmd",
      1960,
      "Error, Invalid arguments");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL) )
  {
    v8 = "cam_vfe_top_ver4_process_cmd";
    v9 = "VFE:%u Error soc_private NULL";
    v10 = *(unsigned int *)(*(_QWORD *)a1 + 4LL);
    v11 = 1969;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      v8,
      v11,
      v9,
      v10);
    return 4294967274LL;
  }
  switch ( a2 )
  {
    case 0u:
      return cam_vfe_top_ver4_mux_get_base();
    case 3u:
      v8 = "cam_vfe_top_ver4_mux_get_reg_update";
      v9 = "VFE:%u Invalid request, Add RUP in CSID";
      v10 = *(unsigned int *)(*(_QWORD *)a1 + 4LL);
      v11 = 1187;
      goto LABEL_8;
    case 9u:
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_vfe_top_clock_update)(a1 + 24, a3, a4);
    case 0xAu:
      return ((__int64 (__fastcall *)(_QWORD, __int64))cam_vfe_top_bw_update)(
               *(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL),
               a1 + 24);
    case 0xBu:
      return ((__int64 (__fastcall *)(_QWORD, __int64))cam_vfe_top_bw_update_v2)(
               *(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL),
               a1 + 24);
    case 0xCu:
      return ((__int64 (__fastcall *)(_QWORD, __int64))cam_vfe_top_bw_control)(
               *(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL),
               a1 + 24);
    case 0xDu:
      return cam_vfe_top_fcg_config();
    case 0x12u:
      return cam_vfe_top_ver4_update_sof_debug(a3, a4);
    case 0x14u:
      v17 = *(__int64 (__fastcall **)(__int64, __int64))(a3 + 104);
      if ( !v17 )
        return 4294967274LL;
      if ( *((_DWORD *)v17 - 1) != -1380041226 )
        __break(0x8228u);
      return v17(a3, 20);
    case 0x16u:
      v16 = *(__int64 (**)(void))(*(_QWORD *)a3 + 104LL);
      if ( !v16 )
        return 0;
      if ( *((_DWORD *)v16 - 1) != -1380041226 )
        __break(0x8228u);
      return v16();
    case 0x19u:
      cam_vfe_core_config_control(a3);
      return 0;
    case 0x2Cu:
      *(_DWORD *)(a3 + 4) = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 476LL) + *(_DWORD *)(*(_QWORD *)(a1 + 8) + 248LL);
      v12 = *(_QWORD *)(a1 + 16);
      if ( (*(_BYTE *)(v12 + 296) & 1) == 0 && *(_BYTE *)(v12 + 297) != 1 )
        return 0;
      *(_BYTE *)(a3 + 28) = 1;
      *(_DWORD *)(a3 + 16) = **(_DWORD **)(*(_QWORD *)(a1 + 16) + 216LL);
      *(_DWORD *)(a3 + 20) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 216LL) + 4LL);
      return 0;
    case 0x3Au:
      *(_DWORD *)(a1 + 10512) = 1;
      cam_vfe_top_ver4_print_overflow_debug_info();
      return 0;
    case 0x3Cu:
      cam_vfe_top_ver4_get_path_port_map();
      return 0;
    case 0x3Du:
      v13 = *(_QWORD *)(a1 + 8);
      v14 = *(_DWORD *)(v13 + 248);
      if ( v14 )
      {
        *(_DWORD *)(a1 + 10776) = *(_DWORD *)(a3 + 12);
        if ( v14 == 1 )
        {
          v15 = 1;
        }
        else
        {
          *(_DWORD *)(a1 + 10784) = *(_DWORD *)(a3 + 16);
          if ( v14 == 2 )
          {
            v15 = 2;
          }
          else
          {
            *(_DWORD *)(a1 + 10792) = *(_DWORD *)(a3 + 20);
            if ( v14 == 3 )
            {
              v15 = 3;
            }
            else
            {
              *(_DWORD *)(a1 + 10800) = *(_DWORD *)(a3 + 24);
              if ( v14 == 4 )
              {
                v15 = 4;
              }
              else
              {
                *(_DWORD *)(a1 + 10808) = *(_DWORD *)(a3 + 28);
                if ( v14 == 5 )
                {
                  v15 = 5;
                }
                else
                {
                  *(_DWORD *)(a1 + 10816) = *(_DWORD *)(a3 + 32);
                  if ( v14 == 6 )
                  {
                    v15 = 6;
                  }
                  else
                  {
                    *(_DWORD *)(a1 + 10824) = *(_DWORD *)(a3 + 36);
                    if ( v14 == 7 )
                    {
                      v15 = 7;
                    }
                    else
                    {
                      *(_DWORD *)(a1 + 10832) = *(_DWORD *)(a3 + 40);
                      if ( v14 != 8 )
                        goto LABEL_64;
                      v15 = 8;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v15 = 0;
      }
      v18 = *(_DWORD *)(v13 + 476) + v14;
      v19 = v18 >= v15;
      v20 = v18 - v15;
      if ( (_DWORD)v20 == 0 || !v19 )
      {
LABEL_63:
        *(_BYTE *)(a1 + 10920) = *(_BYTE *)(a3 + 77);
        *(_QWORD *)(a1 + 10928) = *(_QWORD *)a3;
        return 0;
      }
      v21 = 0;
      v22 = (_DWORD *)(a1 + 10840);
      while ( ((v15 + v21) | v21) <= 7 )
      {
        v23 = *(_DWORD *)(a3 + 4LL * v15 + 12 + 4 * v21++);
        *v22 = v23;
        v22 += 2;
        if ( v20 == v21 )
          goto LABEL_63;
      }
LABEL_64:
      __break(0x5512u);
      result = cam_vfe_top_ver4_mux_get_base();
      break;
    case 0x42u:
      return cam_vfe_top_apply_clk_bw_update(a1 + 24, (__int64 *)a3, a4);
    case 0x43u:
      return cam_vfe_init_config_update(a3, a4);
    case 0x48u:
      return cam_vfe_top_ver4_pdaf_lcr_config();
    case 0x4Fu:
      if ( *(_BYTE *)(a3 + 20) == 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_top_ver4_process_cmd",
          2075,
          "VFE does not support get of primary SOF ts addr",
          a7,
          a2);
        return 4294967274LL;
      }
      return cam_vfe_top_ver4_set_primary_sof_timer_reg_addr();
    default:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver4_process_cmd",
        2091,
        "VFE:%u Error, Invalid cmd:%d",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL));
      return 4294967274LL;
  }
  return result;
}
