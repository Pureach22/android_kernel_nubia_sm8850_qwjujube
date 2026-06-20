__int64 __fastcall dp_catalog_get(__int64 a1, __int64 a2)
{
  char *v4; // x0
  __int64 (__fastcall *v5)(__int64, const char *); // x8
  char *v6; // x19
  __int64 v7; // x0
  __int64 (__fastcall *v8)(__int64, const char *); // x8
  __int64 v9; // x0
  __int64 (__fastcall *v10)(__int64, const char *); // x8
  __int64 v11; // x0
  __int64 (__fastcall *v12)(__int64, const char *); // x8
  __int64 v13; // x0
  __int64 (__fastcall *v14)(__int64, const char *); // x8
  __int64 v15; // x0
  __int64 (__fastcall *v16)(__int64, const char *); // x8
  __int64 v17; // x0
  __int64 (__fastcall *v18)(__int64, const char *); // x8
  __int64 v19; // x0
  __int64 (__fastcall *v20)(__int64, const char *); // x8
  __int64 v21; // x0
  __int64 (__fastcall *v22)(__int64, const char *); // x8
  __int64 v23; // x0
  __int64 (__fastcall *v24)(__int64, const char *); // x8
  __int64 v25; // x0
  __int64 (__fastcall *v26)(__int64, const char *); // x8
  __int64 v27; // x0
  __int64 (__fastcall *v28)(__int64, const char *); // x8
  __int64 v29; // x0
  __int64 (__fastcall *v30)(__int64, const char *); // x8
  __int64 v31; // x0
  int v32; // w8
  __int64 v33; // x12
  __int64 v34; // x11
  __int64 v35; // x10
  __int64 v36; // x9
  _QWORD *v37; // x23
  int v38; // w8
  _QWORD *v39; // x0
  int v40; // w20
  void (__fastcall *v41)(_QWORD); // x9
  __int64 v42; // x0
  __int64 ipc_log_context; // x0

  if ( !a1 || !a2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_get");
    return -22;
  }
  v4 = (char *)devm_kmalloc(a1, 1384, 3520);
  if ( !v4 )
    return -12;
  *((_QWORD *)v4 + 14) = a2;
  *((_QWORD *)v4 + 15) = dp_read_hw;
  v5 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  v6 = v4;
  *(_QWORD *)v4 = a1;
  *((_QWORD *)v4 + 16) = dp_write_hw;
  if ( *((_DWORD *)v5 - 1) != -816176389 )
    __break(0x8228u);
  v7 = v5(a2, "dp_ahb");
  v8 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 1) = v7;
  if ( *((_DWORD *)v8 - 1) != -816176389 )
    __break(0x8228u);
  v9 = v8(a2, "dp_aux");
  v10 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 2) = v9;
  if ( *((_DWORD *)v10 - 1) != -816176389 )
    __break(0x8228u);
  v11 = v10(a2, "dp_link");
  v12 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 3) = v11;
  if ( *((_DWORD *)v12 - 1) != -816176389 )
    __break(0x8228u);
  v13 = v12(a2, "dp_p0");
  v14 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 4) = v13;
  if ( *((_DWORD *)v14 - 1) != -816176389 )
    __break(0x8228u);
  v15 = v14(a2, "dp_phy");
  v16 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 5) = v15;
  if ( *((_DWORD *)v16 - 1) != -816176389 )
    __break(0x8228u);
  v17 = v16(a2, "dp_ln_tx0");
  v18 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 6) = v17;
  if ( *((_DWORD *)v18 - 1) != -816176389 )
    __break(0x8228u);
  v19 = v18(a2, "dp_ln_tx1");
  v20 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 7) = v19;
  if ( *((_DWORD *)v20 - 1) != -816176389 )
    __break(0x8228u);
  v21 = v20(a2, "dp_pll");
  v22 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 9) = v21;
  if ( *((_DWORD *)v22 - 1) != -816176389 )
    __break(0x8228u);
  v23 = v22(a2, "usb3_dp_com");
  v24 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 10) = v23;
  if ( *((_DWORD *)v24 - 1) != -816176389 )
    __break(0x8228u);
  v25 = v24(a2, "dp_mmss_cc");
  v26 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 8) = v25;
  if ( *((_DWORD *)v26 - 1) != -816176389 )
    __break(0x8228u);
  v27 = v26(a2, "hdcp_physical");
  v28 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 11) = v27;
  if ( *((_DWORD *)v28 - 1) != -816176389 )
    __break(0x8228u);
  v29 = v28(a2, "dp_p1");
  v30 = *(__int64 (__fastcall **)(__int64, const char *))(a2 + 848);
  *((_QWORD *)v6 + 12) = v29;
  if ( *((_DWORD *)v30 - 1) != -816176389 )
    __break(0x8228u);
  v31 = v30(a2, "dp_tcsr");
  v32 = *(unsigned __int8 *)(a2 + 832);
  *((_QWORD *)v6 + 13) = v31;
  strcpy(v6 + 1368, "hw");
  if ( v32 == 1 )
  {
    v33 = *(_QWORD *)(a2 + 800);
    v34 = *(_QWORD *)(a2 + 808);
    v35 = *(_QWORD *)(a2 + 816);
    v36 = *(_QWORD *)(a2 + 824);
  }
  else
  {
    LOBYTE(v32) = 0;
    v36 = 0;
    v35 = 0;
    v34 = 0;
    v33 = 0;
  }
  *((_QWORD *)v6 + 18) = 0;
  v37 = v6 + 144;
  *((_QWORD *)v6 + 168) = a2;
  *((_QWORD *)v6 + 31) = v33;
  *((_QWORD *)v6 + 32) = v34;
  *((_QWORD *)v6 + 33) = v35;
  *((_QWORD *)v6 + 34) = v36;
  *((_QWORD *)v6 + 25) = &dp_catalog_aux_update_cfg;
  *((_QWORD *)v6 + 26) = &dp_catalog_aux_setup;
  v6[280] = v32;
  *((_QWORD *)v6 + 27) = dp_catalog_aux_get_irq;
  *((_QWORD *)v6 + 28) = dp_catalog_aux_clear_hw_interrupts;
  *((_QWORD *)v6 + 21) = dp_catalog_aux_write_trans;
  *((_QWORD *)v6 + 22) = dp_catalog_aux_clear_trans;
  *((_QWORD *)v6 + 19) = dp_catalog_aux_read_data;
  *((_QWORD *)v6 + 20) = dp_catalog_aux_write_data;
  *((_QWORD *)v6 + 23) = dp_catalog_aux_reset;
  *((_QWORD *)v6 + 24) = dp_catalog_aux_enable;
  *((_QWORD *)v6 + 29) = 0;
  *((_QWORD *)v6 + 30) = 0;
  memcpy(v6 + 281, &unk_2807B9, 0xE7u);
  *((_QWORD *)v6 + 163) = dp_catalog_hpd_config_hpd;
  *((_QWORD *)v6 + 164) = dp_catalog_hpd_get_interrupt;
  *((_QWORD *)v6 + 162) = 0;
  *((_QWORD *)v6 + 165) = dp_catalog_hpd_wait_for_edp_panel_ready;
  *((_QWORD *)v6 + 166) = dp_catalog_hpd_set_edp_mode;
  *((_QWORD *)v6 + 68) = dp_catalog_audio_config_acr;
  *((_QWORD *)v6 + 69) = dp_catalog_audio_config_sdp;
  *((_QWORD *)v6 + 70) = &dp_catalog_audio_set_header;
  *((_QWORD *)v6 + 71) = &dp_catalog_audio_get_header;
  *((_QWORD *)v6 + 64) = 0;
  *((_QWORD *)v6 + 65) = 0;
  *((_QWORD *)v6 + 66) = dp_catalog_audio_init;
  *((_QWORD *)v6 + 67) = dp_catalog_audio_enable;
  memcpy(v6 + 576, &unk_280908, 0x2D0u);
  v38 = *(_DWORD *)(a2 + 712);
  if ( v38 <= 1279 )
  {
    if ( v38 != 512 )
    {
      if ( v38 != 1056 )
      {
LABEL_49:
        *((_QWORD *)v6 + 169) = dp_catalog_set_exe_mode;
        *((_QWORD *)v6 + 170) = dp_catalog_reg_dump;
        return (__int64)v37;
      }
      goto LABEL_41;
    }
    v39 = (_QWORD *)dp_catalog_get_v200(a1, v6 + 144, v6 + 8);
  }
  else
  {
    if ( v38 != 1280 )
    {
      if ( v38 != 2048 && v38 != 1536 )
        goto LABEL_49;
LABEL_41:
      v39 = (_QWORD *)dp_catalog_get_v420(a1, v6 + 144, v6 + 8);
      goto LABEL_44;
    }
    v39 = (_QWORD *)dp_catalog_get_v500(a1, v6 + 144, v6 + 8);
  }
LABEL_44:
  *((_QWORD *)v6 + 167) = v39;
  if ( (unsigned __int64)v39 <= 0xFFFFFFFFFFFFF000LL )
  {
    *v39 = dp_read_sub_hw;
    *(_QWORD *)(*((_QWORD *)v6 + 167) + 8LL) = dp_write_sub_hw;
    goto LABEL_49;
  }
  *((_QWORD *)v6 + 167) = 0;
  v40 = (int)v39;
  v41 = *(void (__fastcall **)(_QWORD))(*((_QWORD *)v6 + 14) + 864LL);
  v42 = *((_QWORD *)v6 + 14);
  if ( *((_DWORD *)v41 - 1) != 680055959 )
    __break(0x8229u);
  v41(v42);
  devm_kfree(*(_QWORD *)v6);
  return v40;
}
