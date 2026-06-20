__int64 __fastcall cam_vfe_top_ver3_process_cmd(__int64 a1, int a2, __int64 *a3, unsigned int a4)
{
  __int64 result; // x0
  const char *v5; // x5
  __int64 v6; // x4
  __int64 (*v7)(void); // x8
  __int64 (__fastcall *v8)(__int64 *, __int64); // x8

  if ( !a1 || !a3 )
  {
    v5 = "Error, Invalid arguments";
    v6 = 650;
    goto LABEL_8;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL) )
  {
    v5 = "Error soc_private NULL";
    v6 = 658;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_process_cmd",
      v6,
      v5);
    return 4294967274LL;
  }
  switch ( a2 )
  {
    case 0:
      return cam_vfe_top_ver3_mux_get_base();
    case 3:
      v7 = *(__int64 (**)(void))(*a3 + 104);
      if ( !v7 )
        return 4294967274LL;
      if ( *((_DWORD *)v7 - 1) != -1380041226 )
        __break(0x8228u);
      goto LABEL_37;
    case 9:
      return ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))cam_vfe_top_clock_update)(a1 + 24, a3, a4);
    case 10:
      return ((__int64 (__fastcall *)(_QWORD, __int64))cam_vfe_top_bw_update)(
               *(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL),
               a1 + 24);
    case 11:
      return ((__int64 (__fastcall *)(_QWORD, __int64))cam_vfe_top_bw_update_v2)(
               *(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL),
               a1 + 24);
    case 12:
      return ((__int64 (__fastcall *)(_QWORD, __int64))cam_vfe_top_bw_control)(
               *(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL),
               a1 + 24);
    case 20:
      v8 = (__int64 (__fastcall *)(__int64 *, __int64))a3[13];
      if ( !v8 )
        return 4294967274LL;
      if ( *((_DWORD *)v8 - 1) != -1380041226 )
        __break(0x8228u);
      return v8(a3, 20);
    case 22:
      v7 = *(__int64 (**)(void))(*a3 + 104);
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != -1380041226 )
          __break(0x8228u);
LABEL_37:
        result = v7();
      }
      else
      {
        result = 0;
      }
      break;
    case 25:
      v7 = *(__int64 (**)(void))(*a3 + 104);
      if ( !v7 )
        return 4294967274LL;
      if ( *((_DWORD *)v7 - 1) != -1380041226 )
        __break(0x8228u);
      goto LABEL_37;
    case 28:
      return cam_vfe_top_wait_comp_event();
    case 29:
      return cam_vfe_top_add_wait_trigger();
    case 39:
      return cam_vfe_top_ver3_blanking_update(a3, a4);
    case 58:
      return cam_vfe_top_ver3_dump_info();
    case 60:
      ((void (*)(void))cam_vfe_top_ver3_get_path_port_map)();
      return 0;
    case 66:
      return cam_vfe_top_apply_clk_bw_update(a1 + 24, a3, a4);
    default:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver3_process_cmd",
        720,
        "Error, Invalid cmd:%d",
        a2);
      return 4294967274LL;
  }
  return result;
}
