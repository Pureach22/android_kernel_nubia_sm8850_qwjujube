__int64 __fastcall init_v2(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x21
  unsigned int v5; // w0
  unsigned int v6; // w21
  __int64 v7; // x8
  unsigned int v8; // w2
  int v9; // w4
  __int64 v10; // x8
  unsigned int v11; // w2
  int v12; // w4
  __int64 v13; // x1
  __int64 v14; // x1
  __int64 v15; // x22
  __int64 v16; // x9
  int v17; // w8
  __int64 v18; // x8
  unsigned int v19; // w1
  _DWORD *v21; // x10
  unsigned __int64 StatusReg; // x23
  __int64 v23; // x24
  __int64 (__fastcall *v24)(_QWORD); // x0
  _BYTE v25[24]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ((__int64 (*)(void))init_v12)();
  if ( v5 )
  {
    v6 = v5;
    _drm_err("failed to initialize v12: ret %d\n", v5);
  }
  else
  {
    reg_dma_register_count = 145;
    reg_dma_ctl0_queue1_cmd0_offset = 28;
    reg_dma_error_clear_mask |= 0x80000u;
    qword_299F88 = 0x2C0000001CLL;
    qword_299F90 = 0x4C0000003CLL;
    qword_299F98 = 0x6C0000005CLL;
    v7 = a1[2];
    dword_B688 = 254869263;
    if ( (*(_BYTE *)(v7 + 12) & 1) != 0 )
    {
      v25[19] = 0;
      *(_QWORD *)&v25[11] = 0;
      v8 = *(_DWORD *)(v7 + 16);
      v9 = *(_DWORD *)(v7 + 40);
      strcpy(v25, "REG_DMA_SB");
      sde_dbg_reg_register_dump_range((__int64)"reg_dma", v25, v8, v8 + 1024, v9);
      if ( a2 > 1 )
        goto LABEL_23;
      v10 = reg_dma_0[a2];
      *(_QWORD *)(v10 + 120) = last_cmd_sb_v2;
      *(_QWORD *)(v10 + 128) = hfi_last_cmd_null_impl;
      v7 = a1[2];
    }
    if ( *(_BYTE *)v7 == 1 )
    {
      v25[19] = 0;
      *(_QWORD *)&v25[11] = 0;
      v11 = *(_DWORD *)(v7 + 4);
      v12 = *(_DWORD *)(v7 + 40);
      strcpy(v25, "REG_DMA_DB");
      sde_dbg_reg_register_dump_range((__int64)"reg_dma", v25, v11, v11 + 1024, v12);
      v7 = a1[2];
    }
    if ( *(_DWORD *)(v7 + 36) )
    {
      v13 = *(unsigned int *)(v7 + 52);
      v26 = 0;
      *(_OWORD *)&v25[8] = 0u;
      if ( (_DWORD)v13 != 18 )
      {
        printk(&unk_236097, v13);
        goto LABEL_13;
      }
      v2 = *(_QWORD *)(*(_QWORD *)(*a1 + 56LL) + 8LL);
      v15 = _kmalloc_cache_noprof(wake_up_process, 3520, 32);
      if ( !v15 )
        goto LABEL_24;
LABEL_11:
      v16 = a1[2];
      *(_QWORD *)v15 = a1[20];
      v17 = *(_DWORD *)(v16 + 4);
      *(_QWORD *)v25 = v15;
      *(_DWORD *)(v15 + 8) = v17;
      *(_DWORD *)&v25[8] = *(_DWORD *)(v16 + 52);
      *(_QWORD *)&v25[16] = setup_clk_force_ctrl;
      if ( (unsigned int)sde_vbif_clk_register(v2, (__int64)v25) )
      {
        printk(&unk_274B77, *(unsigned int *)(a1[2] + 52LL));
        kfree(v15);
      }
    }
LABEL_13:
    while ( a2 >= 2 )
    {
LABEL_23:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v23 = *(_QWORD *)(StatusReg + 80);
      v24 = wake_up_process;
      *(_QWORD *)(StatusReg + 80) = &init_reg_dma_vbif__alloc_tag;
      v15 = _kmalloc_cache_noprof(v24, 3520, 32);
      *(_QWORD *)(StatusReg + 80) = v23;
      if ( v15 )
        goto LABEL_11;
LABEL_24:
      printk(&unk_269E54, v14);
    }
    v18 = last_cmd_buf[a2];
    if ( v18 && *(_QWORD *)(v18 + 24) )
    {
      v19 = *(_DWORD *)(v18 + 16);
      *(_DWORD *)(v18 + 20) = 0;
      *(_QWORD *)(v18 + 40) = 1;
      *(_DWORD *)(v18 + 48) = 0;
      if ( v19 > 3 )
      {
        v21 = *(_DWORD **)(v18 + 32);
        v6 = 0;
        *v21 = reg_dma_decode_sel;
        v21[1] = 0;
        *(_DWORD *)(v18 + 20) = 8;
        *(_QWORD *)(v18 + 40) = 0x7F0000007ELL;
        goto LABEL_20;
      }
      _drm_err("buffer is full sz %d needs %d bytes\n", v19, 4);
      _drm_err("validate last_cmd_buf failed\n");
    }
    else
    {
      _drm_err("invalid last cmd buf for dpu idx %d\n", a2);
    }
    dealloc_reg_dma_v1((_QWORD *)last_cmd_buf[a2], a2);
    v6 = -22;
    last_cmd_buf[a2] = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v6;
}
