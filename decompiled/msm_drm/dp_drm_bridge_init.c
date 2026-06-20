__int64 __fastcall dp_drm_bridge_init(__int64 *a1, __int64 a2, int a3, int a4)
{
  _QWORD *v8; // x19
  __int64 v9; // x8
  __int64 v10; // x24
  unsigned int v11; // w0
  __int64 (__fastcall *v12)(_QWORD); // x8
  unsigned int v13; // w0
  __int64 v14; // x8
  unsigned int v16; // w20
  __int64 ipc_log_context; // x0
  void *v18; // x0
  __int64 v19; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v21; // x25

  v8 = (_QWORD *)_kmalloc_cache_noprof(kthread_should_park, 3520, 1128);
  if ( !v8 )
    return 4294967284LL;
  while ( 1 )
  {
    v9 = *a1;
    v8[39] = a1;
    v8[21] = &dp_bridge_ops;
    v8[14] = a2;
    v10 = *(_QWORD *)(v9 + 56);
    v11 = drm_bridge_attach(a2, v8, 0, 0);
    if ( v11 )
    {
      v16 = v11;
      ipc_log_context = get_ipc_log_context();
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]failed to attach bridge, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v16);
      v18 = &unk_252DBD;
      goto LABEL_10;
    }
    v12 = (__int64 (__fastcall *)(_QWORD))a1[19];
    if ( *((_DWORD *)v12 - 1) != 1970643636 )
      __break(0x8228u);
    v13 = v12(a1);
    if ( v13 )
      break;
    v14 = *(unsigned int *)(v10 + 3928);
    *(_DWORD *)(v10 + 3928) = v14 + 1;
    if ( (unsigned int)v14 < 0x10 )
    {
      *(_QWORD *)(v10 + 8 * v14 + 3936) = v8;
      a1[1] = (__int64)v8;
      *((_DWORD *)a1 + 12) = a3;
      *((_DWORD *)a1 + 13) = a4;
      return 0;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &dp_drm_bridge_init__alloc_tag;
    v8 = (_QWORD *)_kmalloc_cache_noprof(kthread_should_park, 3520, 1128);
    *(_QWORD *)(StatusReg + 80) = v21;
    if ( !v8 )
      return 4294967284LL;
  }
  v16 = v13;
  v19 = get_ipc_log_context();
  ipc_log_string(v19, "[e][%-4d]request_irq failed, rc=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v16);
  v18 = &unk_245682;
LABEL_10:
  printk(v18, "dp_drm_bridge_init");
  kfree(v8);
  return v16;
}
