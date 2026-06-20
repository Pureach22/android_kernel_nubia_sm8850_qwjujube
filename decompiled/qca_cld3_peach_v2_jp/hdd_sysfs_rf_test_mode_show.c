__int64 __fastcall hdd_sysfs_rf_test_mode_show(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // x20
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 v32; // x0
  int is_rf_test_mode_enabled; // w0
  int v34; // w0
  __int64 v35; // x19
  __int64 v36; // x21
  __int64 v37; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v38[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+18h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_rf_test_mode_show", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v21 = context;
    LODWORD(result) = _osif_psoc_sync_op_start(
                        *(_QWORD *)(context[3] + 488),
                        &v37,
                        (__int64)"hdd_sysfs_rf_test_mode_show");
    if ( (_DWORD)result )
    {
      result = (int)result;
    }
    else
    {
      v32 = *v21;
      v38[0] = 0;
      if ( v32 )
      {
        is_rf_test_mode_enabled = wlan_mlme_is_rf_test_mode_enabled(v32, v38);
        scnprintf(a11, 4096, "0x%x", is_rf_test_mode_enabled);
        v35 = v34;
      }
      else
      {
        v36 = jiffies;
        if ( _hdd_sysfs_rf_test_mode_show___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "__hdd_sysfs_rf_test_mode_show");
          v35 = 0;
          _hdd_sysfs_rf_test_mode_show___last_ticks = v36;
        }
        else
        {
          v35 = 0;
        }
      }
      _osif_psoc_sync_op_stop(v37, (__int64)"hdd_sysfs_rf_test_mode_show");
      result = v35;
    }
  }
  else
  {
    v31 = jiffies;
    if ( hdd_sysfs_rf_test_mode_show___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: invalid input",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_sysfs_rf_test_mode_show");
      hdd_sysfs_rf_test_mode_show___last_ticks = v31;
    }
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
