void __fastcall msm_geni_serial_break_ctl(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v4; // x8
  int v5; // w0
  unsigned int v6; // w0

  v2 = *(_QWORD *)(a1 + 264);
  if ( v2 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v2 + 74)
    || (v4 = *(_QWORD *)(a1 + 344), !*(_DWORD *)(v4 + 500))
    || (*(_WORD *)(v4 + 488) & 7) != 0 )
  {
    if ( a2 )
    {
      v5 = wait_for_transfers_inflight(a1);
      if ( v5 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 960),
          "%s.wait_for_transfer_inflight return ret: %d\n",
          "msm_geni_serial_break_ctl",
          v5);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.wait_for_transfer_inflight return ret: %d\n");
      }
      v6 = 0x20000000;
    }
    else
    {
      v6 = 671088640;
    }
    writel(v6, (unsigned int *)(*(_QWORD *)(a1 + 712) + 1536LL));
    __dsb(0xFu);
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 960),
      "%s.Device is not in active state, %s\n",
      "msm_geni_serial_break_ctl",
      (const char *)(_ReadStatusReg(SP_EL0) + 2320));
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.Device is not in active state, %s\n");
  }
}
