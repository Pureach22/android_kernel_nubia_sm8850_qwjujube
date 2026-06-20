__int64 __fastcall spss_start(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x21
  __int64 result; // x0
  unsigned int v5; // w22
  __int64 v6; // x0
  int v7; // w0
  int v8; // w21
  int v9; // w2
  __int64 v10; // x0
  int state; // w0

  v1 = *(_QWORD **)(a1 + 40);
  v3 = v1[2];
  result = clk_prepare(v3);
  if ( !(_DWORD)result )
  {
    v5 = clk_enable(v3);
    if ( v5 )
    {
LABEL_7:
      clk_unprepare(v3);
      return v5;
    }
    v5 = spss_enable_regulator(v1, v1 + 3);
    if ( v5 )
    {
LABEL_6:
      v3 = v1[2];
      clk_disable(v3);
      goto LABEL_7;
    }
    v5 = spss_enable_regulator(v1, v1 + 5);
    if ( v5 )
    {
LABEL_5:
      spss_disable_regulator(v1, v1 + 3);
      goto LABEL_6;
    }
    v6 = v1[18];
    if ( v6 && (v7 = qcom_rproc_toggle_load_state(v6, v1[17], 1)) != 0 )
    {
      v9 = v7;
      v5 = 0;
    }
    else
    {
      if ( (unsigned int)qcom_scm_pas_auth_and_reset(*((unsigned int *)v1 + 14)) )
        panic("Panicking, auth and reset failed for remoteproc %s\n", *(const char **)(a1 + 24));
      *(_DWORD *)v1[49] = ~((1LL << *((_DWORD *)v1 + 107)) | (1LL << *((_DWORD *)v1 + 106)));
      dev_err(*v1, "trying to read spss registers\n");
      v8 = wait_for_completion_timeout(v1 + 8, 1250);
      read_sp2cl_debug_registers(v1);
      if ( *(_BYTE *)(a1 + 1204) == 1 && !v8 )
        panic("Panicking, %s start timed out\n", *(const char **)(a1 + 24));
      if ( v8 )
      {
        v5 = 0;
        goto LABEL_18;
      }
      dev_err(*v1, "start timed out\n");
      v10 = v1[18];
      if ( !v10 )
      {
        v5 = -110;
        goto LABEL_18;
      }
      state = qcom_rproc_toggle_load_state(v10, v1[17], 0);
      v5 = -110;
      if ( !state )
      {
LABEL_18:
        spss_disable_regulator(v1, v1 + 5);
        goto LABEL_5;
      }
      v9 = state;
    }
    dev_err(*v1, "Failed to signal AOP about spss status [%d]\n", v9);
    goto LABEL_18;
  }
  return result;
}
