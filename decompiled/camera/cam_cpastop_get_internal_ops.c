__int64 __fastcall cam_cpastop_get_internal_ops(_QWORD *a1)
{
  if ( a1 )
  {
    *a1 = &cam_cpastop_get_hw_info;
    a1[1] = cam_cpastop_init_hw_version;
    a1[2] = cam_cpastop_handle_irq;
    a1[3] = cam_cpastop_setup_regbase_indices;
    a1[4] = cam_cpastop_poweron;
    a1[5] = &cam_cpastop_poweroff;
    a1[6] = cam_cpastop_setup_qos_settings;
    a1[7] = cam_cpastop_print_poweron_settings;
    a1[8] = &cam_cpastop_qchannel_handshake;
    a1[9] = cam_cpastop_set_tpg_mux_sel;
    a1[10] = &cam_cpastop_dump_camnoc_buff_fill_info;
    a1[11] = cam_cpastop_save_camnoc_buff_fill_info;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_get_internal_ops",
      1845,
      "invalid NULL param");
    return 4294967274LL;
  }
}
