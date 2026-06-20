__int64 __fastcall dp_catalog_get_v420(__int64 a1, _QWORD *a2, __int64 a3)
{
  _QWORD *v6; // x0
  __int64 ipc_log_context; // x0

  if ( a1 && a2 )
  {
    v6 = (_QWORD *)devm_kmalloc(a1, 48, 3520);
    if ( v6 )
    {
      v6[3] = dp_catalog_put_v420;
      *v6 = a1;
      a2[8] = &dp_catalog_aux_setup_v420;
      a2[10] = dp_catalog_aux_clear_hw_int_v420;
      a2[135] = dp_catalog_panel_config_msa_v420;
      v6[4] = a3;
      v6[5] = a2;
      a2[29] = dp_catalog_ctrl_phy_lane_cfg_v420;
      a2[30] = dp_catalog_ctrl_update_vx_px_v420;
      a2[21] = dp_catalog_ctrl_lane_pnswap_v420;
      return (__int64)(v6 + 1);
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
    printk(&unk_275B6D, "dp_catalog_get_v420");
    return -22;
  }
}
