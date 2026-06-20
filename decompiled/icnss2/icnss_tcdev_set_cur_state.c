__int64 __fastcall icnss_tcdev_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x21
  __int64 v6; // x22
  __int64 v7; // x2
  __int64 (__fastcall *v8)(__int64, unsigned __int64, __int64); // x8
  unsigned int v9; // w0
  __int64 v10; // x8
  unsigned int v11; // w19

  v2 = *(_QWORD *)(penv + 16);
  if ( v2 && *(_QWORD *)(v2 + 320) )
  {
    v3 = *(_QWORD *)(a1 + 944);
    if ( *(_QWORD *)(v3 + 32) < a2 )
      return 4294967274LL;
    v6 = *(_QWORD *)(penv + 8);
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2: Cooling device set current state: %ld,for cdev id %d",
      a2,
      *(_DWORD *)(v3 + 16));
    mutex_lock(penv + 5544);
    v7 = *(unsigned int *)(v3 + 16);
    v8 = *(__int64 (__fastcall **)(__int64, unsigned __int64, __int64))(*(_QWORD *)(penv + 16) + 320LL);
    if ( *((_DWORD *)v8 - 1) != 1940371796 )
      __break(0x8228u);
    v9 = v8(v6 + 16, a2, v7);
    if ( v9 )
    {
      v11 = v9;
      mutex_unlock(penv + 5544);
      printk(
        "%sicnss2: Setting Current Thermal State Failed: %d,for cdev id %d",
        byte_130B32,
        v11,
        *(_DWORD *)(v3 + 16));
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Setting Current Thermal State Failed: %d,for cdev id %d",
        (const char *)&unk_12DBF3,
        v11,
        *(_DWORD *)(v3 + 16));
      return v11;
    }
    v10 = penv;
    *(_QWORD *)(v3 + 24) = a2;
    mutex_unlock(v10 + 5544);
  }
  return 0;
}
