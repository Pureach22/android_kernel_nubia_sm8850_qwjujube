__int64 __fastcall hif_runtime_resume(__int64 a1)
{
  unsigned int v2; // w19

  hif_bus_resume_noirq(a1);
  v2 = hif_bus_resume(a1);
  if ( v2 )
    qdf_trace_msg(61, 2, "%s: Failed runtime resume: %d", "hif_runtime_resume", v2);
  return v2;
}
