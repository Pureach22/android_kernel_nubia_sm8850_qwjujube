__int64 __fastcall dp_pll_get(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 device_by_node; // x0
  __int64 v4; // x19
  __int64 v5; // x21
  __int64 (__fastcall *v6)(__int64, const char *); // x8
  __int64 v7; // x0
  __int64 (__fastcall *v8)(__int64, const char *); // x8
  __int64 v9; // x0
  __int64 (__fastcall *v10)(__int64, const char *); // x8
  __int64 v11; // x0
  __int64 (__fastcall *v12)(__int64, const char *); // x8
  __int64 v13; // x0
  __int64 (__fastcall *v14)(__int64, const char *); // x8
  __int64 v15; // x0
  __int64 v16; // x0
  void *v17; // x0
  __int64 ipc_log_context; // x0
  void *v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  void *v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  _QWORD v28[11]; // [xsp+8h] [xbp-58h] BYREF

  v28[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*a1 || (v2 = *(_QWORD *)(*a1 + 760LL)) == 0 || !a1[2] )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid resource pointers\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v19 = &unk_226A5F;
LABEL_26:
    printk(v19, "dp_pll_get");
    v4 = -22;
    goto LABEL_35;
  }
  memset(v28, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "qcom,dp-pll", 0, 0, 0, v28) || !v28[0] )
  {
    v20 = get_ipc_log_context();
    ipc_log_string(v20, "[e][%-4d]couldn't find dp-pll node\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v19 = &unk_26F8F6;
    goto LABEL_26;
  }
  device_by_node = of_find_device_by_node();
  if ( !device_by_node )
  {
    v21 = get_ipc_log_context();
    ipc_log_string(v21, "[e][%-4d]couldn't find dp-pll device\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v22 = &unk_218F6B;
LABEL_30:
    printk(v22, "dp_pll_get");
    v4 = -19;
    goto LABEL_35;
  }
  v4 = *(_QWORD *)(device_by_node + 168);
  if ( !v4 )
  {
    v23 = get_ipc_log_context();
    ipc_log_string(v23, "[e][%-4d]couldn't find pll\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v22 = &unk_21CA5E;
    goto LABEL_30;
  }
  v5 = a1[2];
  *(_QWORD *)(v4 + 320) = v5;
  *(_QWORD *)(v4 + 336) = a1[1];
  v6 = *(__int64 (__fastcall **)(__int64, const char *))(v5 + 848);
  if ( *((_DWORD *)v6 - 1) != -816176389 )
    __break(0x8228u);
  v7 = v6(v5, "dp_phy");
  *(_QWORD *)(v4 + 344) = v7;
  if ( !v7 )
  {
    v24 = get_ipc_log_context();
    ipc_log_string(v24, "[e][%-4d]Invalid dp_phy resource\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_22002C;
    goto LABEL_34;
  }
  v8 = *(__int64 (__fastcall **)(__int64, const char *))(v5 + 848);
  if ( *((_DWORD *)v8 - 1) != -816176389 )
    __break(0x8228u);
  v9 = v8(v5, "dp_pll");
  *(_QWORD *)(v4 + 352) = v9;
  if ( !v9 )
  {
    v25 = get_ipc_log_context();
    ipc_log_string(v25, "[e][%-4d]Invalid dp_pll resource\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_276516;
    goto LABEL_34;
  }
  v10 = *(__int64 (__fastcall **)(__int64, const char *))(v5 + 848);
  if ( *((_DWORD *)v10 - 1) != -816176389 )
    __break(0x8228u);
  v11 = v10(v5, "dp_ln_tx0");
  *(_QWORD *)(v4 + 360) = v11;
  if ( !v11 )
    goto LABEL_33;
  v12 = *(__int64 (__fastcall **)(__int64, const char *))(v5 + 848);
  if ( *((_DWORD *)v12 - 1) != -816176389 )
    __break(0x8228u);
  v13 = v12(v5, "dp_ln_tx1");
  *(_QWORD *)(v4 + 368) = v13;
  if ( !v13 )
  {
LABEL_33:
    v26 = get_ipc_log_context();
    ipc_log_string(v26, "[e][%-4d]Invalid dp_ln_tx1 resource\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_22D93A;
    goto LABEL_34;
  }
  v14 = *(__int64 (__fastcall **)(__int64, const char *))(v5 + 848);
  if ( *((_DWORD *)v14 - 1) != -816176389 )
    __break(0x8228u);
  v15 = v14(v5, "gdsc");
  *(_QWORD *)(v4 + 376) = v15;
  if ( !v15 )
  {
    v16 = get_ipc_log_context();
    ipc_log_string(v16, "[e][%-4d]Invalid gdsc resource\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_23B0F0;
LABEL_34:
    printk(v17, "dp_pll_fill_io");
    v4 = -12;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return v4;
}
