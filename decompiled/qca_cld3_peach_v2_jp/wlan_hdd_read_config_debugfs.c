__int64 __fastcall wlan_hdd_read_config_debugfs(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x8
  __int64 v17; // x23
  __int64 result; // x0
  _QWORD *v19; // x3
  __int64 v20; // x0
  __int64 v21; // x5
  __int64 v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // [xsp+0h] [xbp-10h] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 40);
  v31 = 0;
  v17 = *(_QWORD *)(v16 + 696);
  LODWORD(result) = _wlan_hdd_validate_context(
                      v17,
                      (__int64)"wlan_hdd_read_config_debugfs",
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10,
                      a11,
                      a12);
  if ( (_DWORD)result
    || (LODWORD(result) = _osif_psoc_sync_op_start(
                            *(_QWORD *)(*(_QWORD *)(v17 + 24) + 488LL),
                            &v31,
                            (__int64)"wlan_hdd_read_config_debugfs"),
        (_DWORD)result) )
  {
    result = (int)result;
  }
  else
  {
    v19 = *(_QWORD **)(a1 + 32);
    if ( v19 )
    {
      v20 = simple_read_from_buffer(a2, a3, a4, v19 + 1, *v19);
      v21 = *a4;
      v22 = v20;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: ini config read req: count: %zu, pos: %lld",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_hdd_config_update",
        a3,
        v21,
        v31,
        v32);
    }
    else
    {
      v22 = -12;
    }
    _osif_psoc_sync_op_stop(v31, (__int64)"wlan_hdd_read_config_debugfs");
    result = v22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
