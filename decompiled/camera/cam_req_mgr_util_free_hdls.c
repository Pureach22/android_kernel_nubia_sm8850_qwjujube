__int64 cam_req_mgr_util_free_hdls()
{
  __int64 v0; // x22
  __int64 i; // x23
  unsigned int v2; // w19
  unsigned __int64 v9; // x10
  __int64 v10; // x8
  _QWORD *v11; // x8

  raw_spin_lock_bh(&hdl_tbl_lock);
  if ( hdl_tbl )
  {
    v0 = 0;
    for ( i = 0; i != 256; ++i )
    {
      if ( *(_DWORD *)(hdl_tbl + v0 + 12) == 1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          2,
          "cam_req_mgr_util_free_hdls",
          143,
          "Dev handle = %x session_handle = %x",
          *(_DWORD *)(hdl_tbl + v0 + 4),
          *(_DWORD *)(hdl_tbl + v0));
        v10 = hdl_tbl;
        *(_DWORD *)(hdl_tbl + v0 + 12) = 0;
        _X9 = (unsigned __int64 *)(*(_QWORD *)(v10 + 10240) + 8LL * ((unsigned int)i >> 6));
        __asm { PRFM            #0x11, [X9] }
        do
          v9 = __ldxr(_X9);
        while ( __stxr(v9 & ~(1LL << i), _X9) );
      }
      v0 += 40;
    }
    v2 = 0;
    v11 = *(_QWORD **)(hdl_tbl + 10240);
    v11[2] = 0;
    v11[3] = 0;
    *v11 = 0;
    v11[1] = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_util_free_hdls",
      134,
      "Hdl tbl is NULL");
    v2 = -22;
  }
  raw_spin_unlock_bh(&hdl_tbl_lock);
  return v2;
}
