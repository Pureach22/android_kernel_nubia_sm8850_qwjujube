__int64 __fastcall sdhci_msm_gcc_reset(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  unsigned int v4; // w0
  __int64 v5; // x1
  const char *v6; // x2
  unsigned int v7; // w0

  v2 = *(_QWORD *)(a2 + 2016);
  if ( v2 )
  {
    v3 = a1;
    v4 = reset_control_assert(*(_QWORD *)(a2 + 2016));
    if ( v4 )
    {
      v5 = v4;
      v6 = "core_reset assert failed\n";
    }
    else
    {
      usleep_range_state(200, 210, 2);
      v7 = reset_control_deassert(v2);
      if ( !v7 )
        return usleep_range_state(200, 210, 2);
      v5 = v7;
      v6 = "core_reset deassert failed\n";
    }
    a1 = v3;
  }
  else
  {
    v6 = "unable to acquire core_reset\n";
    v5 = 4294967201LL;
  }
  return dev_err_probe(a1, v5, v6);
}
