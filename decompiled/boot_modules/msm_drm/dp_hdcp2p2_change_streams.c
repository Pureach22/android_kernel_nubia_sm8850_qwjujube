__int64 __fastcall dp_hdcp2p2_change_streams(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 ipc_log_context; // x0
  void *v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  if ( !a1 || !*(_BYTE *)(a2 + 40) || !*(_QWORD *)(a2 + 32) )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v6 = &unk_275B6D;
LABEL_12:
    printk(v6, "dp_hdcp2p2_change_streams");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(a1 + 344);
  if ( !v2 )
  {
    v7 = get_ipc_log_context(a1);
    ipc_log_string(v7, "[e][%-4d]HDCP library needs to be acquired\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v6 = &unk_233A43;
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(a1 + 352) )
  {
    v8 = get_ipc_log_context(a1);
    ipc_log_string(v8, "[e][%-4d]invalid lib ops data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v6 = &unk_260BD9;
    goto LABEL_12;
  }
  *(_QWORD *)(a2 + 8) = v2;
  v3 = **(__int64 (__fastcall ***)(_QWORD))(a1 + 352);
  if ( *((_DWORD *)v3 - 1) != -417196079 )
    __break(0x8228u);
  return v3(a2);
}
