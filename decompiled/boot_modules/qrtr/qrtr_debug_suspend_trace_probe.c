void __fastcall qrtr_debug_suspend_trace_probe(__int64 a1, const char *a2, int a3, char a4)
{
  const char *v6; // x21
  int v7; // w0

  if ( a3 >= 1 && (a4 & 1) != 0 )
  {
    v6 = a2;
    v7 = strcmp("machine_suspend", a2);
    a2 = v6;
    if ( !v7 )
      qrtr_count = 3;
  }
  if ( a3 >= 1 && (a4 & 1) == 0 && !strcmp("dpm_resume", a2) )
    qrtr_count = 0;
}
