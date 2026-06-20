__int64 __fastcall dp_wfds_deinit(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD **v10; // x20
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( result )
  {
    v10 = (_QWORD **)result;
    v12 = *(_QWORD *)(result + 24);
    qdf_trace_msg(0x45u, 8u, "%s: WFDS QMI deinit", a3, a4, a5, a6, a7, a8, a9, a10, "dp_wfds_deinit");
    if ( *(_DWORD *)(v12 + 104) )
      wlan_qmi_wfds_send_misc_req_msg(**v10, a2 & 1);
    wlan_qmi_wfds_deinit(**v10);
    flush_work(v12 + 8);
    cancel_work_sync(v12 + 8);
    _flush_workqueue(*(_QWORD *)(v12 + 56));
    destroy_workqueue(*(_QWORD *)(v12 + 56));
    if ( *(_DWORD *)(v12 + 96) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "qdf_list_destroy");
    gp_dl_wfds_ctx = 0;
    return _qdf_mem_free(v12);
  }
  return result;
}
