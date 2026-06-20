__int64 __fastcall target_if_spectral_finite_scan_update(
        _QWORD *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 result; // x0
  __int64 v12; // x20
  _QWORD *v13; // x8
  int v14; // w9
  _BYTE *v15; // x19
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  unsigned int v26; // w22

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    v12 = jiffies;
    if ( target_if_spectral_finite_scan_update___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: target if spectral object is null",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_spectral_finite_scan_update");
      target_if_spectral_finite_scan_update___last_ticks = v12;
      result = 4;
      goto LABEL_20;
    }
    goto LABEL_7;
  }
  if ( !*a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: pdev object is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_spectral_finite_scan_update");
    result = 4;
    goto LABEL_20;
  }
  if ( a2 >= 2 )
  {
    v10 = jiffies;
    if ( target_if_spectral_finite_scan_update___last_ticks_57 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Invalid Spectral mode",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_spectral_finite_scan_update");
      target_if_spectral_finite_scan_update___last_ticks_57 = v10;
      result = 4;
      goto LABEL_20;
    }
LABEL_7:
    result = 4;
    goto LABEL_20;
  }
  v13 = &a1[2 * a2];
  v14 = *((_DWORD *)v13 + 368);
  if ( v14 )
  {
    v15 = (char *)v13 + 1468;
    *((_DWORD *)v13 + 368) = v14 - 1;
    if ( v14 == 1 )
    {
      result = target_if_spectral_scan_complete_event();
      if ( (_DWORD)result )
      {
        v25 = jiffies;
        if ( target_if_spectral_finite_scan_update___last_ticks_61 - jiffies + 125 < 0 )
        {
          v26 = result;
          qdf_trace_msg(
            0x56u,
            2u,
            "%s: Failed to notify finite spectral scan completion",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "target_if_spectral_finite_scan_update");
          result = v26;
          target_if_spectral_finite_scan_update___last_ticks_61 = v25;
        }
      }
      *v15 = 0;
      v15[12] = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v16 = jiffies;
    if ( target_if_spectral_finite_scan_update___last_ticks_59 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Error, No reports expected",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_spectral_finite_scan_update");
      target_if_spectral_finite_scan_update___last_ticks_59 = v16;
    }
    result = 16;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
