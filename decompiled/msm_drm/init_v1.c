__int64 __fastcall init_v1(_QWORD *a1, unsigned int a2)
{
  unsigned int v2; // w8
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x0
  __int64 v6; // x12
  unsigned int v7; // w1

  v2 = -22;
  if ( a1 && a2 <= 1 )
  {
    v4 = last_cmd_buf[a2];
    reg_dma_0[a2] = a1;
    if ( !v4 )
    {
      v5 = alloc_reg_dma_buf_v1(512, a2);
      v4 = v5;
      last_cmd_buf[a2] = v5;
      if ( !v5 || v5 > 0xFFFFFFFFFFFFF000LL )
      {
        printk(&unk_274B25, v5);
        return 0;
      }
      a1 = (_QWORD *)reg_dma_0[a2];
    }
    a1[3] = check_support_v1;
    a1[4] = setup_payload_v1;
    a1[5] = kick_off_v1;
    a1[6] = hfi_kick_off_v1;
    a1[8] = reset_v1;
    a1[9] = alloc_reg_dma_buf_v1;
    a1[10] = dealloc_reg_dma_v1;
    a1[11] = reset_reg_dma_buffer_v1;
    a1[12] = &last_cmd_v1;
    a1[13] = hfi_last_cmd_null_impl;
    a1[18] = dump_regs_v1;
    a1[19] = reg_dma_select_queue_sb_v1_to_3;
    reg_dma_register_count = 60;
    reg_dma_decode_sel = 403357792;
    reg_dma_opmode_offset = 1;
    reg_dma_ctl0_queue0_cmd0_offset = 20;
    reg_dma_intr_4_status_offset = 160;
    reg_dma_ctl_trigger_offset = 212;
    reg_dma_error_clear_mask = 65543;
    reg_dma_intr_4_clear_offset = 192;
    reg_dma_intr_0_status_offset = 0x9000000090LL;
    qword_299EA0 = 0x9000000090LL;
    qword_299EA8 = 0x9000000090LL;
    qword_299EB0 = 0x9000000090LL;
    qword_299EB8 = 0x9000000090LL;
    qword_299EC0 = 0x9000000090LL;
    qword_299EC8 = 0x9000000090LL;
    reg_dma_intr_0_clear_offset = 0xB0000000B0LL;
    qword_299ED8 = 0xB0000000B0LL;
    reg_dma_ctl0_reset_offset = 0xE4000000E4LL;
    qword_299F10 = 0xE8000000E8LL;
    qword_299EE0 = 0xB0000000B0LL;
    qword_299EE8 = 0xB0000000B0LL;
    qword_299EF0 = 0xB0000000B0LL;
    qword_299EF8 = 0xB0000000B0LL;
    qword_299F00 = 0xB0000000B0LL;
    qword_299F38 = 0xFC000000FCLL;
    qword_299F18 = 0xEC000000ECLL;
    qword_299F20 = 0xF0000000F0LL;
    qword_299F44 = 0x2400000014LL;
    qword_299F4C = 0x4400000034LL;
    qword_299F28 = 0xF4000000F4LL;
    qword_299F30 = 0xF8000000F8LL;
    qword_299F54 = 0x6400000054LL;
    validate_queue_func = validate_queue_type_v1_to_3;
    reg_dma_submit_payload = &reg_dma_submit_queue_v1_to_v3;
    v6 = *(_QWORD *)(v4 + 24);
    read_clear_reg_dma_status = reg_dma_read_clear_status_v1_to_v3;
    trigger_reg_dma = &reg_dma_trigger_v1_to_v3;
    if ( v6 )
    {
      v7 = *(_DWORD *)(v4 + 16);
      *(_DWORD *)(v4 + 20) = 0;
      *(_QWORD *)(v4 + 40) = 1;
      *(_DWORD *)(v4 + 48) = 0;
      if ( v7 > 3 )
      {
        v2 = 0;
        **(_QWORD **)(v4 + 32) = 403357792;
        *(_DWORD *)(v4 + 20) = 8;
        *(_QWORD *)(v4 + 40) = 0x7F0000007ELL;
        return v2;
      }
      _drm_err("buffer is full sz %d needs %d bytes\n", v7, 4);
      _drm_err("validate last_cmd_buf failed\n");
    }
    else
    {
      _drm_err("invalid last cmd buf for dpu idx %d\n", a2);
    }
    dealloc_reg_dma_v1(last_cmd_buf[a2], a2);
    last_cmd_buf[a2] = 0;
    return (unsigned int)-22;
  }
  return v2;
}
