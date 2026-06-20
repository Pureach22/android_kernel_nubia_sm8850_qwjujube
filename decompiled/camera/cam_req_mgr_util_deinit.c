__int64 cam_req_mgr_util_deinit()
{
  __int64 v0; // x0
  unsigned int v1; // w19
  int v2; // w8
  __int64 v3; // x0

  raw_spin_lock_bh(&hdl_tbl_lock);
  if ( hdl_tbl )
  {
    v0 = *(_QWORD *)(hdl_tbl + 10240);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v0, 0);
    else
      kvfree(v0);
    v2 = (unsigned __int8)mem_trace_en;
    v3 = hdl_tbl;
    *(_QWORD *)(hdl_tbl + 10240) = 0;
    if ( v2 == 1 )
      cam_mem_trace_free(v3, 0);
    else
      kvfree(v3);
    v1 = 0;
    hdl_tbl = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_util_deinit",
      76,
      "Hdl tbl is NULL");
    v1 = -22;
  }
  raw_spin_unlock_bh(&hdl_tbl_lock);
  return v1;
}
