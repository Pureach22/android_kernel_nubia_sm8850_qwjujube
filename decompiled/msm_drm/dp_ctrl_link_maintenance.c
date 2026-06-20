__int64 __fastcall dp_ctrl_link_maintenance(__int64 a1)
{
  __int64 result; // x0
  int *v3; // x8
  int v4; // w9
  __int64 v5; // x0
  void (*v6)(void); // x8
  __int64 ipc_log_context; // x0
  void *v8; // x0
  __int64 v9; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid input data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_23AC6D;
LABEL_13:
    printk(v8, "dp_ctrl_link_maintenance");
    return 4294967274LL;
  }
  **(_DWORD **)(a1 + 136) &= ~0x400u;
  **(_DWORD **)(a1 + 136) &= ~0x800u;
  if ( (*(_BYTE *)(a1 + 257) & 1) == 0 )
  {
    v9 = get_ipc_log_context(a1);
    ipc_log_string(v9, "[e][%-4d]ctrl off\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_234092;
    goto LABEL_13;
  }
  if ( *(_DWORD *)(a1 + 264) )
    return 0;
  **(_DWORD **)(a1 + 136) |= 0x200u;
  result = dp_ctrl_setup_main_link(a1);
  **(_DWORD **)(a1 + 136) &= ~0x200u;
  v3 = *(int **)(a1 + 136);
  v4 = *v3;
  if ( !(_DWORD)result )
  {
    *v3 = v4 | 0x400;
    if ( *(_DWORD *)(a1 + 276) )
    {
      v5 = *(_QWORD *)(a1 + 176);
      *(_DWORD *)(a1 + 224) = 0;
      v6 = *(void (**)(void))(v5 + 56);
      if ( *((_DWORD *)v6 - 1) != -1041116529 )
        __break(0x8228u);
      v6();
      dp_ctrl_mst_send_act(a1);
      dp_ctrl_wait4video_ready(a1);
      dp_ctrl_fec_setup(a1);
    }
    return 0;
  }
  *v3 = v4 | 0x800;
  return result;
}
