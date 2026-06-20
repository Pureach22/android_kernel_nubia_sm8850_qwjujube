__int64 __fastcall ml_activate_pend_disconn_req_cb(
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
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 v11; // x20

  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 )
  {
    v10 = *(_QWORD *)(v9 + 1360);
    v11 = *(_QWORD *)(v10 + 2224);
    if ( v11 )
    {
      v10 = *(_QWORD *)(v11 + 280);
      if ( v10 )
      {
        ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))mlo_disconnect_req)(
          *(_QWORD *)(a1 + 8),
          *(unsigned int *)(v10 + 4),
          *(unsigned int *)(v10 + 8));
        _qdf_mem_free(*(_QWORD *)(v11 + 280));
        *(_QWORD *)(v11 + 280) = 0;
      }
    }
    wlan_objmgr_vdev_release_ref(v9, 0x5Au, (unsigned int *)v10, a2, a3, a4, a5, a6, a7, a8, a9);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Null input vdev", a2, a3, a4, a5, a6, a7, a8, a9, "ml_activate_pend_disconn_req_cb");
    return 4;
  }
}
