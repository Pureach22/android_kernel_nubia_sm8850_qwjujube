__int64 __fastcall hdd_sysfs_feature_set_show(
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
  int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  unsigned int v32; // w26
  int v33; // w0
  __int64 v34; // x1
  __int64 v35; // [xsp+0h] [xbp-10h] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_feature_set_show", a1, a2, a3, a4, a5, a6, a7, a8);
  v21 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_feature_set_show",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  if ( v21
    || (v21 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v35, (__int64)"hdd_sysfs_feature_set_show")) != 0 )
  {
    v30 = v21;
  }
  else
  {
    if ( *((_BYTE *)context + 8148) )
    {
      v32 = 0;
      v30 = 0;
      do
      {
        v34 = 4096 - v30;
        if ( v32 == 2 )
        {
          scnprintf(a11 + v30, v34, "%s", "QCT");
          v32 = 4;
        }
        else
        {
          scnprintf(a11 + v30, v34, "%.2X", *((unsigned __int8 *)context + v32 + 7124));
        }
        ++v32;
        v30 += v33;
      }
      while ( v32 < *((unsigned __int8 *)context + 8148) );
      *(_BYTE *)(a11 + v30) = 10;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Feature info is not available",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__hdd_sysfs_feature_set_show",
        v35,
        v36);
      v30 = 0;
    }
    _osif_psoc_sync_op_stop(v35, (__int64)"hdd_sysfs_feature_set_show");
  }
  _ReadStatusReg(SP_EL0);
  return v30;
}
