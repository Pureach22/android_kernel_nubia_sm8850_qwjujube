__int64 __fastcall gsi_read_gsi_hw_profiling_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v7; // x2
  void (*v8)(void); // x8
  int hw_profiling_stats; // w22
  void (*v10)(void); // x8
  int v11; // w0
  __int64 result; // x0
  __int64 v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v13, 0, 32);
  if ( *(_DWORD *)(gsi_ctx + 16) > 7u )
  {
    v8 = *(void (**)(void))(gsi_ctx + 152);
    if ( *((_DWORD *)v8 - 1) != -440107680 )
      __break(0x8228u);
    v8();
    hw_profiling_stats = gsi_get_hw_profiling_stats(v13);
    v10 = *(void (**)(void))(gsi_ctx + 160);
    if ( *((_DWORD *)v10 - 1) != -440107680 )
      __break(0x8228u);
    v10();
    if ( !hw_profiling_stats )
    {
      v11 = scnprintf(
              dbg_buff,
              4096,
              "bp_count=0x%llx\n"
              "bp_and_pending_count=0x%llx\n"
              "mcs_busy=0x%llx\n"
              "mcs_idle=0x%llx\n"
              "total_cycle_count=0x%llx\n"
              "utilization_percentage=%llu%%\n",
              v13[0]);
      goto LABEL_10;
    }
    v7 = "Fail to read GSI HW Profiling stats\n";
  }
  else
  {
    v7 = "This feature only support on GSI2.9+\n";
  }
  v11 = scnprintf(dbg_buff, 4096, v7, a4);
LABEL_10:
  result = simple_read_from_buffer(a2, a3, a4, dbg_buff, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
