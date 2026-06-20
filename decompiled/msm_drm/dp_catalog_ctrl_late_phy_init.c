__int64 __fastcall dp_catalog_ctrl_late_phy_init(__int64 a1, char a2, char a3)
{
  int v4; // w11
  int v5; // w12
  int v6; // w17
  int v7; // w0
  int v8; // w14
  int v9; // w10
  __int64 v10; // x22
  unsigned int v11; // w15
  int v12; // w9
  bool v13; // zf
  void (__fastcall *v14)(__int64, __int64, __int64, __int64); // x8
  __int64 v15; // x3
  __int64 v16; // x1
  unsigned int v17; // w21
  unsigned int v18; // w23
  unsigned int v19; // w24
  _DWORD *v20; // x8
  __int64 v21; // x22
  _DWORD *v22; // x8
  _DWORD *v23; // x8
  __int64 v24; // x21
  void (__fastcall *v25)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v26)(__int64, __int64, __int64, __int64); // x8
  __int64 v27; // x21
  __int64 v28; // x22
  __int64 v29; // x0
  __int64 v30; // x23
  __int64 v31; // x1
  void (__fastcall *v32)(__int64, __int64, __int64, __int64); // x8
  __int64 v33; // x1
  void (__fastcall *v34)(__int64, __int64, __int64, __int64); // x8
  __int64 v35; // x1
  void (__fastcall *v36)(__int64, __int64, __int64, __int64); // x8
  __int64 v37; // x1
  void (__fastcall *v38)(__int64, __int64, __int64, __int64); // x8
  __int64 v39; // x1
  void (__fastcall *v40)(__int64, __int64, __int64, __int64); // x8
  __int64 v41; // x1
  void (__fastcall *v42)(__int64, __int64, __int64, __int64); // x8
  int v44; // w19
  __int64 ipc_log_context; // x0
  __int64 v46; // x0

  if ( a1 )
  {
    if ( (a3 & 1) != 0 )
      v4 = 63;
    else
      v4 = 21;
    if ( (a3 & 1) != 0 )
      v5 = 21;
    else
      v5 = 63;
    if ( (a3 & 1) != 0 )
      v6 = 19;
    else
      v6 = 16;
    if ( (a3 & 1) != 0 )
      v7 = 62;
    else
      v7 = 21;
    if ( (a3 & 1) != 0 )
      v8 = 16;
    else
      v8 = 19;
    if ( (a3 & 1) != 0 )
      v9 = 21;
    else
      v9 = 62;
    v10 = *(_QWORD *)(a1 - 184);
    if ( a2 == 1 )
    {
      v11 = v6;
    }
    else
    {
      v8 = 16;
      v9 = 63;
      v11 = 16;
    }
    if ( a2 == 1 )
      v12 = v7;
    else
      v12 = 63;
    v13 = a2 == 2;
    v14 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( a2 == 2 )
      v15 = 16;
    else
      v15 = v11;
    v16 = *(_QWORD *)(a1 - 184);
    if ( v13 )
      v17 = 16;
    else
      v17 = v8;
    if ( v13 )
      v18 = v5;
    else
      v18 = v9;
    if ( v13 )
      v19 = v4;
    else
      v19 = v12;
    if ( *((_DWORD *)v14 - 1) != -626862723 )
      __break(0x8228u);
    v14(a1 - 232, v16, 88, v15);
    v20 = *(_DWORD **)(a1 - 104);
    if ( *(v20 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v20)(a1 - 232, v10, 84, v19);
    v21 = *(_QWORD *)(a1 - 176);
    v22 = *(_DWORD **)(a1 - 104);
    if ( *(v22 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v22)(a1 - 232, v21, 88, v17);
    v23 = *(_DWORD **)(a1 - 104);
    if ( *(v23 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v23)(a1 - 232, v21, 84, v18);
    v24 = *(_QWORD *)(a1 - 192);
    v25 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v25 - 1) != -626862723 )
      __break(0x8228u);
    v25(a1 - 232, v24, 16, 24);
    _const_udelay(8590000);
    v26 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v26 - 1) != -626862723 )
      __break(0x8228u);
    v26(a1 - 232, v24, 16, 25);
    __dsb(0xEu);
    v27 = *(_QWORD *)(*(_QWORD *)(a1 - 192) + 24LL);
    if ( (unsigned int)dp_catalog_get_dp_phy_version(a1 - 88) >> 29 <= 2 )
      v28 = 220;
    else
      v28 = 228;
    v29 = readl_0(v27 + v28);
    if ( (v29 & 2) != 0 )
    {
LABEL_57:
      if ( (v29 & 2) == 0 )
      {
LABEL_72:
        v44 = v29;
        ipc_log_context = get_ipc_log_context(v29);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]PHY status failed, status=%x\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          v44);
        printk(&unk_23093B, "dp_catalog_ctrl_wait_for_phy_ready");
        return 4294967274LL;
      }
    }
    else
    {
      v30 = 10500001;
      while ( 1 )
      {
        v30 -= 500001;
        if ( v30 < 0 )
          break;
        _const_udelay(2147500);
        __yield();
        v29 = readl_0(v27 + v28);
        if ( (v29 & 2) != 0 )
          goto LABEL_57;
      }
      v29 = readl_0(v27 + v28);
      if ( (v29 & 2) == 0 )
        goto LABEL_72;
    }
    v31 = *(_QWORD *)(a1 - 184);
    v32 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v32 - 1) != -626862723 )
      __break(0x8228u);
    v32(a1 - 232, v31, 92, 10);
    v33 = *(_QWORD *)(a1 - 176);
    v34 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v34 - 1) != -626862723 )
      __break(0x8228u);
    v34(a1 - 232, v33, 92, 10);
    v35 = *(_QWORD *)(a1 - 184);
    v36 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v36 - 1) != -626862723 )
      __break(0x8228u);
    v36(a1 - 232, v35, 20, 39);
    v37 = *(_QWORD *)(a1 - 176);
    v38 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v38 - 1) != -626862723 )
      __break(0x8228u);
    v38(a1 - 232, v37, 20, 39);
    v39 = *(_QWORD *)(a1 - 184);
    v40 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v40 - 1) != -626862723 )
      __break(0x8228u);
    v40(a1 - 232, v39, 12, 32);
    v41 = *(_QWORD *)(a1 - 176);
    v42 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v42 - 1) != -626862723 )
      __break(0x8228u);
    v42(a1 - 232, v41, 12, 32);
    __dsb(0xEu);
    return 0;
  }
  else
  {
    v46 = get_ipc_log_context(0);
    ipc_log_string(v46, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_ctrl_late_phy_init");
    return 4294967274LL;
  }
}
