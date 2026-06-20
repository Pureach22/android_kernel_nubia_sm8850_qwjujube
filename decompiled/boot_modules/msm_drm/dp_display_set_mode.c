__int64 __fastcall dp_display_set_mode(__int64 a1, __int64 a2, int *a3)
{
  int *v4; // x23
  int v7; // w8
  int v8; // w1
  __int64 (*v9)(void); // x8
  void (__fastcall *v10)(__int64, int *); // x8
  int v11; // w7
  __int64 v13; // x0
  void *v14; // x0
  __int64 v15; // x0
  char v16; // [xsp+0h] [xbp-10h]

  if ( !a1 || !a2 )
  {
    if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v13 = 0;
    ipc_log_string(v13, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_275B6D;
    goto LABEL_23;
  }
  if ( !*(_QWORD *)(a2 + 944) )
  {
    if ( !g_dp_display || (v15 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v15 = 0;
    ipc_log_string(v15, "[e][%-4d]invalid connector input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_22D77C;
LABEL_23:
    printk(v14, "dp_display_set_mode");
    return 4294967274LL;
  }
  v4 = (int *)(a1 - 1156);
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_set_mode", 2560, 8, 4369, *(_DWORD *)(a1 - 1156), *a3, a3[1], a3[11]);
  mutex_lock(a1 + 560);
  v7 = *(_DWORD *)(*(_QWORD *)(a2 + 944) + 224LL);
  if ( v7 )
    v8 = 3 * v7;
  else
    v8 = 24;
  a3[13] = v8;
  v9 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 992) + 1040LL);
  if ( *((_DWORD *)v9 - 1) != 66303464 )
    __break(0x8228u);
  a3[13] = v9();
  if ( *(_BYTE *)(a1 + 664) == 1 )
  {
    v10 = *(void (__fastcall **)(__int64, int *))(a1 + 704);
    if ( *((_DWORD *)v10 - 1) != -326764400 )
      __break(0x8228u);
    v10(a1, a3);
  }
  memcpy((void *)(a2 + 104), a3, 0x300u);
  mutex_unlock(a1 + 560);
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_set_mode", 2576, 8, 8738, *v4, -1059143953, v11, v16);
  return 0;
}
