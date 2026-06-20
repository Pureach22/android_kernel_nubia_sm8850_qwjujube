__int64 __fastcall hfi_dbg_dump(int a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x9
  _QWORD *v6; // x0
  __int64 v7; // x19
  void *v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x19
  void *v12; // x0
  __int64 v13; // x0
  _QWORD v14[6]; // [xsp+28h] [xbp-58h] BYREF
  _QWORD v15[5]; // [xsp+58h] [xbp-28h] BYREF

  v15[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = *(_QWORD *)(hfi_dbg + 24);
  v15[1] = 0;
  v15[2] = 2883584;
  v15[3] = 0;
  v14[0] = &_drm_printfn_coredump;
  v14[1] = &_drm_puts_coredump;
  v14[2] = v15;
  memset(&v14[3], 0, 24);
  drm_printf(v14, "---\n");
  drm_printf(v14, "module: msm_drm\n");
  result = drm_printf(v14, "HFI dump\n");
  v3 = hfi_dbg;
  v4 = *(_QWORD *)(hfi_dbg + 16);
  *(_QWORD *)(hfi_dbg + 32) = v14;
  v5 = v4 + 786432;
  if ( *(_DWORD *)(v5 + 20) )
  {
    *(_DWORD *)(v5 + 24) = a1;
    v6 = *(_QWORD **)(v3 + 16);
    *(_DWORD *)(v3 + 324) = a1;
    if ( *((_DWORD *)v6 + 196613) )
      v6 = hfi_evtlog_dump_all(v6);
    v7 = ktime_get(v6);
    v8 = hfi_dump_reg_all();
    v9 = ktime_get(v8);
    v10 = dev_info(
            *(_QWORD *)hfi_dbg,
            "reg-dump logging time start_us:%llu, end_us:%llu , duration_us:%llu\n",
            v7 / 1000,
            v9 / 1000,
            (v9 - v7) / 1000);
    v11 = ktime_get(v10);
    v12 = hfi_dump_dbg_bus();
    v13 = ktime_get(v12);
    result = dev_info(
               *(_QWORD *)hfi_dbg,
               "debug-bus logging time start_us:%llu, end_us:%llu , duration_us:%llu\n",
               v11 / 1000,
               v13 / 1000,
               (v13 - v11) / 1000);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
