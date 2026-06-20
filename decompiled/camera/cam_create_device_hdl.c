__int64 __fastcall cam_create_device_hdl(__int64 a1)
{
  unsigned int first_zero_bit; // w0
  unsigned int v3; // w20
  __int64 v4; // x23
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x9
  unsigned int v8; // w20
  unsigned __int64 v15; // x10
  int v16; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  if ( cam_req_mgr_is_open() )
  {
    raw_spin_lock_bh(&hdl_tbl_lock);
    if ( hdl_tbl )
    {
      first_zero_bit = find_first_zero_bit(*(_QWORD *)(hdl_tbl + 10240), *(_QWORD *)(hdl_tbl + 10248));
      v3 = first_zero_bit;
      if ( first_zero_bit <= 0xFF )
      {
        _X9 = (unsigned __int64 *)(*(_QWORD *)(hdl_tbl + 10240) + 8LL * ((unsigned __int8)first_zero_bit >> 6));
        __asm { PRFM            #0x11, [X9] }
        do
          v15 = __ldxr(_X9);
        while ( __stxr(v15 | (1LL << first_zero_bit), _X9) );
        get_random_bytes(&v16, 1);
        v7 = hdl_tbl + 40LL * (unsigned __int8)v3;
        v8 = v3 | (v16 << 16) | 0x100;
        *(_DWORD *)v7 = *(_DWORD *)a1;
        *(_DWORD *)(v7 + 4) = v8;
        *(_QWORD *)(v7 + 8) = 0x100000001LL;
        *(_QWORD *)(v7 + 32) = *(_QWORD *)(a1 + 32);
        *(_QWORD *)(v7 + 24) = *(_QWORD *)(a1 + 24);
        *(_QWORD *)(v7 + 16) = *(_QWORD *)(a1 + 16);
        raw_spin_unlock_bh(&hdl_tbl_lock);
        result = v8;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_get_free_handle_index",
          161,
          "No free index found idx: %d",
          first_zero_bit);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_create_device_hdl",
          239,
          "Unable to create device handle(idx= %d)",
          -63);
        v4 = -10240;
        do
        {
          if ( (unsigned int)__ratelimit(&cam_dump_tbl_info__rs, "cam_dump_tbl_info") )
            v5 = 3;
          else
            v5 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v5,
            16,
            3,
            "cam_dump_tbl_info",
            179,
            "session_hdl=%x hdl_value=%x type=%d state=%d dev_id=%lld",
            *(_DWORD *)(hdl_tbl + v4 + 10240),
            *(_DWORD *)(hdl_tbl + v4 + 10244),
            *(_DWORD *)(hdl_tbl + v4 + 10248),
            *(_DWORD *)(hdl_tbl + v4 + 10252),
            *(_QWORD *)(hdl_tbl + v4 + 10256));
          v4 += 40;
        }
        while ( v4 );
        raw_spin_unlock_bh(&hdl_tbl_lock);
        result = 4294967233LL;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        16,
        1,
        "cam_create_device_hdl",
        232,
        "Hdl tbl is NULL");
      raw_spin_unlock_bh(&hdl_tbl_lock);
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_create_device_hdl",
      226,
      "CRM is not ACTIVE");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
