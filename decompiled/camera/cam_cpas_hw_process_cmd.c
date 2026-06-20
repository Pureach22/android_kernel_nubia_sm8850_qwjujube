__int64 __fastcall cam_cpas_hw_process_cmd(_QWORD *a1, int a2, char *string, int a4)
{
  int v4; // w9
  void (*v6)(void); // x8
  __int64 v7; // x4
  __int64 v8; // x6

  v4 = a2;
  if ( a1 && string )
  {
    switch ( a2 )
    {
      case 0:
        if ( a4 == 168 )
          return cam_cpas_hw_register_client((int)a1, string);
        v7 = 4713;
        v8 = 0;
        goto LABEL_74;
      case 1:
        if ( a4 == 4 )
          return cam_cpas_hw_unregister_client((__int64)a1, *(_DWORD *)string);
        v7 = 4726;
        v8 = 1;
        goto LABEL_74;
      case 2:
        if ( a4 == 16 )
          return cam_cpas_hw_set_addr_trans(a1, string);
        v7 = 4739;
        v8 = 2;
        goto LABEL_74;
      case 3:
        if ( a4 == 20 )
          return cam_cpas_hw_reg_write(
                   a1,
                   *(unsigned int *)string,
                   *((unsigned int *)string + 1),
                   *((unsigned int *)string + 2),
                   (unsigned __int8)string[16],
                   *((unsigned int *)string + 3));
        v7 = 4753;
        v8 = 3;
        goto LABEL_74;
      case 4:
        if ( a4 == 20 )
          return cam_cpas_hw_reg_read(
                   a1,
                   *(unsigned int *)string,
                   *((unsigned int *)string + 1),
                   *((unsigned int *)string + 2),
                   (unsigned __int8)string[16],
                   string + 12);
        v7 = 4770;
        v8 = 4;
        goto LABEL_74;
      case 5:
        if ( a4 == 16 )
          return cam_cpas_hw_update_ahb_vote(a1, *(unsigned int *)string, *((_QWORD *)string + 1));
        v7 = 4787;
        v8 = 5;
        goto LABEL_74;
      case 6:
        if ( a4 == 16 )
          return cam_cpas_hw_update_axi_vote(a1, *(unsigned int *)string, *((_QWORD *)string + 1));
        v7 = 4801;
        v8 = 6;
        goto LABEL_74;
      case 7:
        if ( a4 == 8 )
          return cam_cpas_hw_update_axi_floor_lvl(a1, *(unsigned int *)string, *((unsigned int *)string + 1), 0);
        v7 = 4815;
        v8 = 7;
        goto LABEL_74;
      case 8:
        if ( a4 == 1 )
        {
          cam_cpas_log_vote(a1, (unsigned __int8)*string);
          return 0;
        }
        v7 = 4830;
        v8 = 8;
        goto LABEL_74;
      case 9:
        if ( a4 == 4 )
          return cam_cpas_select_qos(a1, *(unsigned int *)string);
        v7 = 4860;
        v8 = 9;
        goto LABEL_74;
      case 10:
        if ( a4 == 16 )
        {
          cam_cpas_update_monitor_array(a1, *(_QWORD *)string, *((unsigned int *)string + 2));
          return 0;
        }
        v7 = 4844;
        v8 = 10;
        goto LABEL_74;
      case 11:
        if ( a4 == 4 )
          return cam_cpas_get_slice_id(a1, *(unsigned int *)string);
        v7 = 4873;
        v8 = 11;
        goto LABEL_74;
      case 12:
        if ( a4 == 4 )
          return cam_cpas_activate_cache_slice(a1, *(unsigned int *)string);
        v7 = 4885;
        v8 = 12;
        goto LABEL_74;
      case 13:
        if ( a4 == 4 )
          return cam_cpas_deactivate_cache_slice(a1, *(unsigned int *)string);
        v7 = 4897;
        v8 = 13;
        goto LABEL_74;
      case 14:
        if ( a4 == 16 )
          return cam_cpas_configure_staling_cache_slice(a1, *(_QWORD *)string, *((_QWORD *)string + 1));
        v7 = 4909;
        v8 = 14;
        goto LABEL_74;
      case 15:
        if ( a4 == 4 )
          return cam_cpas_notif_stalling_inc_cache_slice(a1, *(unsigned int *)string);
        v7 = 4922;
        v8 = 15;
        goto LABEL_74;
      case 16:
        if ( a4 != 4 )
        {
          v7 = 4932;
          v8 = 16;
          goto LABEL_74;
        }
        v6 = *(void (**)(void))(a1[460] + 8080LL);
        if ( !v6 )
          return 0;
        if ( *((_DWORD *)v6 - 1) != 1063422862 )
          __break(0x8228u);
        v6();
        return 0;
      case 17:
        if ( a4 == 12 )
          return cam_cpas_hw_csid_input_core_info_update(
                   a1,
                   *(unsigned int *)string,
                   *((unsigned int *)string + 1),
                   (unsigned __int8)string[8]);
        v7 = 4943;
        v8 = 17;
        goto LABEL_74;
      case 18:
        if ( a4 == 4 )
          return cam_cpas_hw_csid_process_resume(a1, *(unsigned int *)string);
        v7 = 4957;
        v8 = 18;
        goto LABEL_74;
      case 19:
        if ( a4 == 1 )
          return cam_cpas_hw_enable_domain_id_clks(a1, (unsigned __int8)*string);
        v7 = 4984;
        v8 = 19;
        goto LABEL_74;
      case 20:
        if ( a4 == 4 )
          return cam_cpas_hw_enable_tpg_mux_sel(a1, *(unsigned int *)string);
        v7 = 4970;
        v8 = 20;
        goto LABEL_74;
      case 21:
        if ( a4 == 32 )
          return cam_cpas_dump_state_monitor_array_info(a1, string);
        v7 = 4997;
        v8 = 21;
LABEL_74:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_hw_process_cmd",
          v7,
          "cmd_type %d, size mismatch %d",
          v8);
        break;
      default:
        v4 = a2;
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_process_cmd",
      4703,
      "Invalid arguments %pK %pK %d",
      a1,
      string,
      v4);
  }
  return 4294967274LL;
}
