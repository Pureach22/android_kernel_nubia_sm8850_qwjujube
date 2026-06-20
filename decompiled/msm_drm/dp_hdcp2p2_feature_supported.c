__int64 __fastcall dp_hdcp2p2_feature_supported(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 (*v4)(void); // x8
  char v5; // w0
  __int64 ipc_log_context; // x0
  void *v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v7 = &unk_275B6D;
LABEL_11:
    printk(v7, "dp_hdcp2p2_valid_handle");
    goto LABEL_12;
  }
  v2 = *(_QWORD *)(a1 + 344);
  if ( !v2 )
  {
    v8 = get_ipc_log_context(0);
    ipc_log_string(v8, "[e][%-4d]HDCP library needs to be acquired\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v7 = &unk_233A43;
    goto LABEL_11;
  }
  v3 = *(_QWORD *)(a1 + 352);
  if ( !v3 )
  {
    v9 = get_ipc_log_context(v2);
    ipc_log_string(v9, "[e][%-4d]invalid lib ops data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v7 = &unk_260BD9;
    goto LABEL_11;
  }
  v4 = *(__int64 (**)(void))(v3 + 8);
  if ( !v4 )
  {
LABEL_12:
    v5 = 0;
    return v5 & 1;
  }
  if ( *((_DWORD *)v4 - 1) != -2091637267 )
    __break(0x8228u);
  v5 = v4();
  return v5 & 1;
}
