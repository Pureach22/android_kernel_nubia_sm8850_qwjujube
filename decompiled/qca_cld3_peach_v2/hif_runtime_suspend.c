__int64 __fastcall hif_runtime_suspend(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w19

  v2 = hif_bus_suspend(a1);
  if ( v2 )
  {
    v3 = v2;
    qdf_trace_msg(61, 2, "%s: Failed bus suspend: %d", "hif_runtime_suspend", v2);
  }
  else
  {
    *(_DWORD *)(gp_hif_rtpm_ctx + 200) = 1;
    v3 = hif_bus_suspend_noirq(a1);
    if ( v3 )
    {
      qdf_trace_msg(61, 2, "%s: Failed bus suspend noirq: %d", "hif_runtime_suspend", v3);
      *(_DWORD *)(gp_hif_rtpm_ctx + 200) = 0;
      hif_bus_resume(a1);
    }
  }
  return v3;
}
