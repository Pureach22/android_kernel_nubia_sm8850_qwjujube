__int64 __fastcall hdd_sysfs_max_chipset_log_size_show(
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
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x20
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
  __int64 v32; // x22
  int v33; // w0
  __int64 v34; // x19
  __int64 v35; // [xsp+0h] [xbp-10h] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_max_chipset_log_size_show", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v21 = context;
    LODWORD(result) = _wlan_hdd_validate_context(
                        (__int64)context,
                        (__int64)"hdd_sysfs_max_chipset_log_size_show",
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20);
    if ( (_DWORD)result
      || (LODWORD(result) = _osif_psoc_sync_op_start(
                              *(_QWORD *)(v21[3] + 488LL),
                              &v35,
                              (__int64)"hdd_sysfs_max_chipset_log_size_show"),
          (_DWORD)result) )
    {
      result = (int)result;
    }
    else
    {
      v32 = jiffies;
      if ( _hdd_sysfs_max_chipset_log_size_show___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: max_chipset_log_size %d",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "__hdd_sysfs_max_chipset_log_size_show",
          *((unsigned __int16 *)v21 + 3558),
          v35,
          v36);
        _hdd_sysfs_max_chipset_log_size_show___last_ticks = v32;
      }
      scnprintf(a11, 4096, "%d\n", *((unsigned __int16 *)v21 + 3558));
      v34 = v33;
      _osif_psoc_sync_op_stop(v35, (__int64)"hdd_sysfs_max_chipset_log_size_show");
      result = v34;
    }
  }
  else
  {
    v31 = jiffies;
    if ( hdd_sysfs_max_chipset_log_size_show___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_ctx is NULL",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_sysfs_max_chipset_log_size_show",
        v35,
        v36);
      hdd_sysfs_max_chipset_log_size_show___last_ticks = v31;
    }
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
