__int64 cam_req_mgr_util_init()
{
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  if ( hdl_tbl )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_util_init",
      32,
      "Hdl_tbl is already present");
    return 4294967274LL;
  }
  if ( mem_trace_en == 1 )
    v1 = cam_mem_trace_alloc(10256, 3264, 0, "cam_req_mgr_util_init", 36);
  else
    v1 = _kvmalloc_node_noprof(10256, 0, 3520, 0xFFFFFFFFLL);
  cam_req_mgr_util_init_hdl_tbl_local = v1;
  if ( !v1 )
    return 4294967284LL;
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(32, 3264, 0, "cam_req_mgr_util_init", 42);
  else
    v2 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  v3 = v2;
  v4 = cam_req_mgr_util_init_hdl_tbl_local;
  *(_QWORD *)(cam_req_mgr_util_init_hdl_tbl_local + 10240) = v3;
  if ( !v3 )
  {
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
    raw_spin_lock_bh(&hdl_tbl_lock);
    hdl_tbl = 0;
    raw_spin_unlock_bh(&hdl_tbl_lock);
    return 4294967284LL;
  }
  *(_QWORD *)(v4 + 10248) = 256;
  raw_spin_lock_bh(&hdl_tbl_lock);
  if ( hdl_tbl )
  {
    raw_spin_unlock_bh(&hdl_tbl_lock);
    v5 = *(_QWORD *)(cam_req_mgr_util_init_hdl_tbl_local + 10240);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(cam_req_mgr_util_init_hdl_tbl_local, 0);
    else
      kvfree(cam_req_mgr_util_init_hdl_tbl_local);
    return 4294967279LL;
  }
  else
  {
    hdl_tbl = cam_req_mgr_util_init_hdl_tbl_local;
    raw_spin_unlock_bh(&hdl_tbl_lock);
    return 0;
  }
}
