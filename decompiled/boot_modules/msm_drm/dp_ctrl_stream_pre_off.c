__int64 __fastcall dp_ctrl_stream_pre_off(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w20
  void (*v4)(void); // x8
  __int64 v5; // x20
  __int64 v6; // x0
  unsigned __int64 StatusReg; // x21
  int v8; // w2
  void (*v9)(void); // x8
  void (*v10)(void); // x8
  void (*v11)(void); // x8
  __int64 (*v12)(void); // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 ipc_log_context; // x0
  void *v16; // x0
  const char *v17; // x1
  __int64 v18; // x0

  _ReadStatusReg(SP_EL0);
  if ( !result || !a2 )
  {
    ipc_log_context = get_ipc_log_context(result);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_275B6D;
    v17 = "dp_ctrl_stream_pre_off";
LABEL_22:
    result = printk(v16, v17);
    goto LABEL_23;
  }
  v2 = result;
  if ( *(_BYTE *)(result + 257) == 1 )
  {
    if ( *(_BYTE *)(result + 258) == 1 && (v3 = *(_DWORD *)(a2 + 912), v3 >= 2) )
    {
      v18 = get_ipc_log_context(result);
      ipc_log_string(v18, "[e][%-4d]mst push idle, invalid stream:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v3);
      result = printk(&unk_229D34, "dp_ctrl_push_idle");
    }
    else
    {
      *(_DWORD *)(result + 192) = 0;
      v4 = *(void (**)(void))(*(_QWORD *)(result + 176) + 56LL);
      if ( *((_DWORD *)v4 - 1) != -1041116529 )
        __break(0x8228u);
      v4();
      v5 = wait_for_completion_timeout(v2 + 192, 25);
      v6 = get_ipc_log_context(v5);
      StatusReg = _ReadStatusReg(SP_EL0);
      v8 = *(_DWORD *)(StatusReg + 1800);
      if ( v5 )
      {
        result = ipc_log_string(v6, "[d][%-4d]mainlink off done\n", v8);
        if ( (_drm_debug & 4) != 0 )
          result = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mainlink off done\n", *(_DWORD *)(StatusReg + 1800));
      }
      else
      {
        ipc_log_string(v6, "[w][%-4d]time out\n", v8);
        result = printk(&unk_2562A7, "dp_ctrl_push_idle");
      }
    }
  }
  if ( *(_BYTE *)(v2 + 258) == 1 )
  {
    v9 = *(void (**)(void))(*(_QWORD *)(v2 + 176) + 216LL);
    if ( *((_DWORD *)v9 - 1) != -739885351 )
      __break(0x8228u);
    v9();
    v10 = *(void (**)(void))(*(_QWORD *)(v2 + 176) + 216LL);
    if ( *((_DWORD *)v10 - 1) != -739885351 )
      __break(0x8228u);
    v10();
    v11 = *(void (**)(void))(*(_QWORD *)(v2 + 176) + 200LL);
    if ( *((_DWORD *)v11 - 1) != -91942776 )
      __break(0x8228u);
    v11();
    msleep(20);
    v12 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 176) + 208LL);
    if ( *((_DWORD *)v12 - 1) != 1395674136 )
      __break(0x8228u);
    v13 = v12();
    v14 = get_ipc_log_context(v13);
    ipc_log_string(
      v14,
      "[e][%-4d]mst stream_off act trigger complete failed\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_2728AA;
    v17 = "dp_ctrl_mst_stream_pre_off";
    goto LABEL_22;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
