__int64 __fastcall sde_connector_late_register(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  _DWORD *v4; // x8
  __int64 v5; // x2
  int v6; // w8
  __int64 result; // x0
  void *v8; // x0
  void *v9; // x0
  void *v10; // x0
  _QWORD v11[21]; // [xsp+8h] [xbp-A8h] BYREF

  v11[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 160);
  if ( !a1 || !*(_QWORD *)(a1 + 2504) )
  {
    v8 = &unk_242658;
LABEL_29:
    printk(v8, "sde_connector_init_debugfs");
    result = 4294967274LL;
    goto LABEL_30;
  }
  if ( !*(_QWORD *)a1 || (v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v9 = &unk_242658;
LABEL_28:
    printk(v9, "sde_connector_get_kms");
    v8 = &unk_234896;
    goto LABEL_29;
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    v9 = &unk_234896;
    goto LABEL_28;
  }
  if ( !*(_QWORD *)(a1 + 2760) || (v4 = *(_DWORD **)(a1 + 2944)) == nullptr )
  {
    printk(&unk_27DE90, "sde_connector_get_info");
    if ( !*(_QWORD *)(a1 + 3064) )
      goto LABEL_13;
    goto LABEL_11;
  }
  v5 = *(_QWORD *)(a1 + 2760);
  if ( *(v4 - 1) != 81886827 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD *, __int64))v4)(a1, v11, v5);
  if ( *(_QWORD *)(a1 + 3064) )
  {
LABEL_11:
    if ( (v11[0] & 0x1000000000LL) != 0 )
      debugfs_create_u32("esd_status_interval", 384, *(_QWORD *)(a1 + 2504), a1 + 4512);
  }
LABEL_13:
  if ( *(_QWORD *)(a1 + 3072) && !debugfs_create_file("tx_cmd", 384, *(_QWORD *)(a1 + 2504), a1, &conn_cmd_tx_fops) )
  {
    v10 = &unk_24D019;
LABEL_33:
    printk(v10, "sde_connector_init_debugfs");
    result = 4294967284LL;
    goto LABEL_30;
  }
  if ( *(_QWORD *)(a1 + 3080) && !debugfs_create_file("rx_cmd", 384, *(_QWORD *)(a1 + 2504), a1, &conn_cmd_rx_fops) )
  {
    v10 = &unk_23C3B5;
    goto LABEL_33;
  }
  v6 = *(_DWORD *)(a1 + 2736);
  if ( v6 != 15 )
    goto LABEL_20;
  if ( *(_DWORD *)(*(_QWORD *)(v3 + 152) + 52LL) )
  {
    debugfs_create_bool("wb_hw_fence_enable", 384, *(_QWORD *)(a1 + 2504), a1 + 5120);
    v6 = *(_DWORD *)(a1 + 2736);
LABEL_20:
    if ( v6 == 16 )
    {
      debugfs_create_u32("num_bl_frames", 384, *(_QWORD *)(a1 + 2504), a1 + 4724);
      debugfs_create_bool("disable_cont_dimming", 384, *(_QWORD *)(a1 + 2504), a1 + 4728);
    }
  }
  result = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
