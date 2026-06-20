__int64 __fastcall hdd_restore_sme_config_flush_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x19
  const char *v10; // x2

  if ( !a1 )
  {
    v10 = "%s: msg is null";
LABEL_7:
    qdf_trace_msg(0x33u, 8u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_restore_sme_config_flush_cb");
    return 4;
  }
  v9 = *(_QWORD **)(a1 + 8);
  if ( !v9 )
  {
    v10 = "%s: bodyptr is null";
    goto LABEL_7;
  }
  if ( *v9 )
    _hdd_objmgr_put_vdev_by_user(*v9, 5, "hdd_restore_sme_config_flush_cb");
  else
    qdf_trace_msg(0x33u, 8u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_restore_sme_config_flush_cb");
  _qdf_mem_free((__int64)v9);
  return 0;
}
