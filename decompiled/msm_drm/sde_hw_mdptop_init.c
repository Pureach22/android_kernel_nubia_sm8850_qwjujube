__int64 __fastcall sde_hw_mdptop_init(int a1, __int64 a2, int *a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  int v8; // w8
  unsigned __int64 v9; // x21
  int v10; // w8
  int v11; // w9
  int v12; // w10
  __int64 v13; // x8
  int v14; // w9
  __int64 (__fastcall *v15)(); // x10
  __int64 (__fastcall *v16)(); // x9
  _DWORD *v17; // x20
  unsigned int v18; // w2
  int v19; // w4
  const char *v20; // x1
  unsigned int v21; // w3
  __int64 v22; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v24; // x23
  __int64 (__fastcall *v25)(_QWORD); // x0
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  result = -22;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || !a3 )
    goto LABEL_69;
  v7 = _kmalloc_cache_noprof(msleep, 3520, 512);
  if ( !v7 )
  {
LABEL_68:
    result = -12;
    goto LABEL_69;
  }
  while ( 1 )
  {
    v8 = a3[161];
    if ( !v8 )
      goto LABEL_13;
    if ( a3[166] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 162);
      goto LABEL_7;
    }
    if ( v8 == 1 )
      goto LABEL_13;
    if ( a3[266] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 262);
      goto LABEL_7;
    }
    if ( v8 == 2 )
      goto LABEL_13;
    if ( a3[366] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 362);
      goto LABEL_7;
    }
    if ( v8 == 3 )
      goto LABEL_13;
    if ( a3[466] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 462);
      goto LABEL_7;
    }
    if ( v8 == 4 )
      goto LABEL_13;
    if ( a3[566] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 562);
      goto LABEL_7;
    }
    if ( v8 == 5 )
      goto LABEL_13;
    if ( a3[666] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 662);
      goto LABEL_7;
    }
    if ( v8 == 6 )
      goto LABEL_13;
    if ( a3[766] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 762);
      goto LABEL_7;
    }
    if ( v8 == 7 )
      goto LABEL_13;
    if ( a3[866] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 862);
      goto LABEL_7;
    }
    if ( v8 == 8 )
      goto LABEL_13;
    if ( a3[966] == a1 )
    {
      v9 = (unsigned __int64)(a3 + 962);
      goto LABEL_7;
    }
    if ( v8 == 9 )
      goto LABEL_13;
    if ( a3[1066] == a1 )
    {
      v22 = 1062;
      goto LABEL_59;
    }
    if ( v8 == 10 )
      goto LABEL_13;
    if ( a3[1166] == a1 )
    {
      v22 = 1162;
      goto LABEL_59;
    }
    if ( v8 == 11 )
      goto LABEL_13;
    if ( a3[1266] == a1 )
      break;
    if ( v8 == 12 )
      goto LABEL_13;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v24 = *(_QWORD *)(StatusReg + 80);
    v25 = msleep;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_mdptop_init__alloc_tag;
    v7 = _kmalloc_cache_noprof(v25, 3520, 512);
    *(_QWORD *)(StatusReg + 80) = v24;
    if ( !v7 )
      goto LABEL_68;
  }
  v22 = 1262;
LABEL_59:
  v9 = (unsigned __int64)&a3[v22];
LABEL_7:
  v10 = *(_DWORD *)(v9 + 20);
  v11 = *(_DWORD *)(v9 + 24);
  v12 = *a3;
  *(_QWORD *)v7 = a2;
  *(_DWORD *)(v7 + 8) = v10;
  *(_DWORD *)(v7 + 12) = v11;
  *(_DWORD *)(v7 + 20) = v12;
  *(_DWORD *)(v7 + 24) = 512;
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_13:
    kfree(v7);
    result = -22;
    goto LABEL_69;
  }
  v13 = *(_QWORD *)(v9 + 32);
  *(_QWORD *)(v7 + 56) = sde_hw_setup_split_pipe;
  *(_QWORD *)(v7 + 80) = sde_hw_setup_pp_split;
  *(_QWORD *)(v7 + 104) = sde_hw_setup_cdm_output;
  *(_QWORD *)(v7 + 152) = sde_hw_setup_clk_force_ctrl;
  *(_QWORD *)(v7 + 176) = sde_hw_get_clk_ctrl_status;
  *(_QWORD *)(v7 + 296) = sde_hw_program_cwb_ppb_ctrl;
  v14 = a3[13];
  *(_QWORD *)(v7 + 224) = sde_hw_reset_ubwc;
  *(_DWORD *)(v7 + 48) = 0;
  *(_QWORD *)(v7 + 248) = sde_hw_intf_audio_select;
  *(_DWORD *)(v7 + 32) = a1;
  *(_QWORD *)(v7 + 40) = v9;
  *(_QWORD *)(v7 + 272) = sde_hw_mdp_events;
  if ( (v13 & 0x40) != 0 )
  {
    v15 = (__int64 (__fastcall *)())&sde_hw_setup_vsync_source;
  }
  else
  {
    if ( (v13 & 0x80) == 0 )
      goto LABEL_18;
    v15 = sde_hw_setup_vsync_source_v1;
  }
  *(_QWORD *)(v7 + 200) = v15;
LABEL_18:
  if ( (v13 & 0x700) != 0 )
    *(_QWORD *)(v7 + 320) = sde_hw_set_hdr_plus_metadata;
  *(_QWORD *)(v7 + 344) = sde_hw_get_autorefresh_status;
  if ( v14 )
  {
    v16 = sde_hw_setup_hw_fences_config_with_dir_write;
    if ( (v13 & 0x2000) == 0 )
      v16 = sde_hw_setup_hw_fences_config;
    *(_QWORD *)(v7 + 368) = v16;
    *(_QWORD *)(v7 + 416) = sde_hw_hw_fence_timestamp_ctrl;
    *(_QWORD *)(v7 + 392) = sde_hw_input_hw_fence_status;
  }
  if ( (v13 & 0x1000) == 0 )
  {
    if ( (v13 & 0x4000) == 0 )
      goto LABEL_26;
LABEL_31:
    *(_QWORD *)(v7 + 464) = sde_hw_setup_dpu_sync_intf_mux;
    if ( (v13 & 0x8000) == 0 )
      goto LABEL_28;
    goto LABEL_27;
  }
  *(_QWORD *)(v7 + 440) = &sde_hw_top_set_ppb_fifo_size;
  if ( (v13 & 0x4000) != 0 )
    goto LABEL_31;
LABEL_26:
  if ( (v13 & 0x8000) != 0 )
LABEL_27:
    *(_QWORD *)(v7 + 488) = sde_hw_setup_flush_sync_intf_mux;
LABEL_28:
  v17 = (_DWORD *)v7;
  sde_dbg_reg_register_dump_range((__int64)"sde", "mdss_hw", 0, a3[160], 0);
  if ( (*((_QWORD *)a3 + 85) & 0x800) != 0 )
  {
    *(_QWORD *)s = 0;
    v27 = 0;
    snprintf(s, 0x10u, "%s_1", (const char *)v9);
    sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v9, v17[2], v17[2] + 896, v17[4]);
    sde_dbg_reg_register_dump_range((__int64)"sde", s, v17[2] + 936, v17[3] + v17[2], v17[4]);
    v18 = *(_DWORD *)(v9 + 68);
    v19 = v17[4];
    v20 = "hw_fence";
    v21 = v18 + 196;
  }
  else
  {
    v18 = v17[2];
    v19 = v17[4];
    v20 = (const char *)v9;
    v21 = v17[3] + v18;
  }
  sde_dbg_reg_register_dump_range((__int64)"sde", v20, v18, v21, v19);
  sde_dbg_set_sde_top_offset((unsigned int)v17[2]);
  result = (__int64)v17;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
