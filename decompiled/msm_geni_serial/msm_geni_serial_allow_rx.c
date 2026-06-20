__int64 __fastcall msm_geni_serial_allow_rx(_QWORD *a1)
{
  int v2; // w0

  writel_relaxed(0x80000001, (unsigned int *)(a1[2] + 684LL));
  __dsb(0xFu);
  v2 = readl_relaxed((unsigned int *)(a1[2] + 684LL));
  ipc_log_string(a1[120], "%s(): rfr = 0x%x\n", "msm_geni_serial_allow_rx", v2);
  _ftrace_dbg(a1[43], "%s(): rfr = 0x%x\n");
  return msm_geni_serial_set_manual_flow(1, a1);
}
