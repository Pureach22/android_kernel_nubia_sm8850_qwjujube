__int64 __fastcall hdd_sysfs_dump_in_progress_show(
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
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x22
  int v31; // w0
  __int64 v33; // [xsp+0h] [xbp-10h] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dump_in_progress_show", a1, a2, a3, a4, a5, a6, a7, a8);
  v21 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_dump_in_progress_show",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  if ( !v21 )
  {
    v21 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v33, (__int64)"hdd_sysfs_dump_in_progress_show");
    if ( !v21 )
    {
      v30 = jiffies;
      if ( _hdd_sysfs_dump_in_progress_show___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: dump in progress %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "__hdd_sysfs_dump_in_progress_show",
          *((unsigned __int8 *)context + 7113),
          v33,
          v34);
        _hdd_sysfs_dump_in_progress_show___last_ticks = v30;
      }
      scnprintf(a11, 4096, "%d\n", *((unsigned __int8 *)context + 7113));
      v21 = v31;
      _osif_psoc_sync_op_stop(v33, (__int64)"hdd_sysfs_dump_in_progress_show");
    }
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
