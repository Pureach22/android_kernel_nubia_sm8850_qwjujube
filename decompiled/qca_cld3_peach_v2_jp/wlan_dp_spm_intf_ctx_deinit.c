__int64 __fastcall wlan_dp_spm_intf_ctx_deinit(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x19
  __int64 v12; // x20
  const char *v13; // x2
  __int64 v14; // [xsp+8h] [xbp-18h]

  if ( !*(_DWORD *)(result + 28) )
  {
    v14 = v10;
    v11 = *(_QWORD *)(result + 3736);
    if ( v11 )
    {
      v12 = result;
      wlan_dp_spm_flow_retire(*(_QWORD *)(result + 3736), 1);
      _qdf_mem_free(v11);
      v13 = "%s: SPM interface deinitialized!";
      *(_QWORD *)(v12 + 3736) = 0;
    }
    else
    {
      v13 = "%s: Module already uninitialized!";
    }
    return qdf_trace_msg(0x45u, 5u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_spm_intf_ctx_deinit", v9, v14);
  }
  return result;
}
