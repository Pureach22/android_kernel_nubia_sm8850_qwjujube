__int64 __fastcall trigger_ipc(unsigned int a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  unsigned int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x8
  int v10; // t1
  unsigned int v11; // w20
  int v12; // w9
  __int64 v13; // x23
  const char *v14; // x21
  __int64 v15; // x8
  __int64 v16; // x22
  __int64 v17; // x8
  __int64 v18; // x23
  unsigned int v19; // w24
  __int64 v20; // x3
  __int64 v21; // x4
  int v22; // w8
  __int64 v24; // x20
  int v25; // w21
  __int64 v26; // x22
  __int64 v27; // x21
  __int64 v28; // x22
  unsigned int v29; // w20
  __int64 v30; // x4

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a2 )
      goto LABEL_3;
LABEL_39:
    printk(&unk_1D5BD, "trigger_ipc", 551, v5, a5);
    return 4294967274LL;
  }
  v24 = a2;
  v25 = a3;
  v26 = v5;
  printk(&unk_1E83A, "trigger_ipc", 548, a4, a5);
  a2 = v24;
  a3 = v25;
  v5 = v26;
  if ( !v24 )
    goto LABEL_39;
LABEL_3:
  if ( a1 >= 4 )
  {
    printk(&unk_1D5EB, "trigger_ipc", 556, v5, a1);
    return 4294967274LL;
  }
  if ( a1 == 3 )
    v7 = 1;
  else
    v7 = a1;
  v8 = a2 + 176LL * v7;
  v10 = *(_DWORD *)(v8 + 56);
  v9 = v8 + 56;
  if ( v10 != 1 )
    return 0;
  if ( a3 == 1 )
  {
    v11 = 2;
    if ( hfi_core_loop_back_mode_enable == 1 )
    {
      if ( a1 == 3 )
        v12 = 3;
      else
        v12 = 2;
      if ( a1 == 1 )
        v11 = 4;
      else
        v11 = v12;
    }
  }
  else
  {
    v11 = 1;
  }
  v13 = *(_QWORD *)(v9 + 8);
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( v13 )
      goto LABEL_19;
LABEL_42:
    v28 = v5;
    printk(&unk_1D5BD, "mbox_trigger_signal", 154, v5, a5);
    v29 = -22;
LABEL_45:
    printk(&unk_1D0E1, "trigger_ipc", 592, v28, a1);
    return v29;
  }
  v27 = v5;
  printk(&unk_1E83A, "mbox_trigger_signal", 151, a4, a5);
  v5 = v27;
  if ( !v13 )
    goto LABEL_42;
LABEL_19:
  if ( v11 == 1 )
  {
    v14 = "POWER";
    v15 = 64;
    goto LABEL_23;
  }
  if ( v11 == 2 )
  {
    v14 = "XFER";
    v15 = 72;
LABEL_23:
    v16 = *(_QWORD *)(v13 + v15);
    goto LABEL_25;
  }
  v16 = 0;
  v14 = "unknmown";
LABEL_25:
  if ( hfi_core_loop_back_mode_enable != 1 )
    goto LABEL_31;
  if ( v11 == 3 )
  {
    v14 = "LOOPBACK_DISP";
    v17 = 152;
  }
  else
  {
    if ( v11 != 4 )
      goto LABEL_31;
    v14 = "LOOPBACK_DCP";
    v17 = 160;
  }
  v16 = *(_QWORD *)(v13 + v17);
LABEL_31:
  if ( !v16 )
  {
    v28 = v5;
    printk(&unk_1C669, "mbox_trigger_signal", 184, v5, v14);
    v29 = -22;
    goto LABEL_45;
  }
  v18 = v5;
  v19 = mbox_send_message(v16, 0);
  mbox_client_txdone(v16, v19);
  if ( (v19 & 0x80000000) != 0 )
  {
    v30 = v11;
    v29 = v19;
    v28 = v18;
    printk(&unk_1EAE9, "mbox_trigger_signal", 192, v18, v30);
    goto LABEL_45;
  }
  v22 = msm_hfi_core_debug_level;
  if ( (~msm_hfi_core_debug_level & 0x10002) != 0 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
      goto LABEL_35;
LABEL_47:
    printk(&unk_1C28B, "mbox_trigger_signal", 197, v20, v21);
    if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
      return 0;
LABEL_48:
    printk(&unk_1C28B, "trigger_ipc", 596, v20, v21);
    return 0;
  }
  printk(&unk_1BB2E, "mbox_trigger_signal", 196, v11, v14);
  v22 = msm_hfi_core_debug_level;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    goto LABEL_47;
LABEL_35:
  if ( (~v22 & 0x10001) == 0 )
    goto LABEL_48;
  return 0;
}
