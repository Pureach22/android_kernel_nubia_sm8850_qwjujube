__int64 __fastcall dp_catalog_get_v500(__int64 a1, _QWORD *a2, __int64 a3)
{
  _QWORD *v6; // x0
  _QWORD *v7; // x20
  __int64 v8; // x9
  __int64 v10; // x10
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 ipc_log_context; // x0

  if ( a1 && a2 )
  {
    v6 = (_QWORD *)devm_kmalloc(a1, 392, 3520);
    if ( v6 )
    {
      *v6 = a1;
      v6[4] = a3;
      v6[5] = a2;
      v7 = v6;
      memcpy(v6 + 6, a2 + 11, 0x118u);
      v8 = a2[51];
      v7[45] = a2[50];
      v7[46] = v8;
      v10 = a2[53];
      v7[47] = a2[52];
      v7[48] = v10;
      v11 = a2[47];
      v7[41] = a2[46];
      v7[42] = v11;
      v13 = a2[48];
      v12 = a2[49];
      v7[3] = dp_catalog_put_v500;
      v7[43] = v13;
      v7[44] = v12;
      a2[8] = &dp_catalog_aux_setup_v500;
      a2[10] = dp_catalog_aux_clear_hw_interrupts_v500;
      a2[135] = dp_catalog_panel_config_msa_v500;
      a2[29] = dp_catalog_ctrl_phy_lane_cfg_v500;
      a2[30] = dp_catalog_ctrl_update_vx_px_v500;
      a2[21] = dp_catalog_ctrl_lane_pnswap_v500;
      a2[25] = dp_catalog_ctrl_usb_reset_v500;
      a2[43] = dp_catalog_ctrl_late_phy_init_v500;
      return (__int64)(v7 + 1);
    }
    else
    {
      return -12;
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_279170, "dp_catalog_get_v500");
    return -22;
  }
}
