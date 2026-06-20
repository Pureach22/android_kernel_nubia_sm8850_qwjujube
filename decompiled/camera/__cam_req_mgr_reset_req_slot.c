__int64 __fastcall _cam_req_mgr_reset_req_slot(__int64 result, __int64 a2, __int64 a3)
{
  unsigned int v3; // w19
  __int64 v4; // x21
  __int64 v5; // x24
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v8; // x26

  v3 = a2;
  if ( (a2 & 0x80000000) != 0 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             16,
             1,
             "__cam_req_mgr_reset_req_slot",
             969,
             "Wrong array idx is sent, idx: %d",
             a2);
  if ( (unsigned int)a2 >= 0x31 )
  {
LABEL_21:
    __break(0x5512u);
    return _cam_req_mgr_check_sync_for_mslave(result, a2, a3);
  }
  else
  {
    v4 = *(_QWORD *)(result + 48);
    v5 = *(_QWORD *)(result + 56);
    v6 = v4 + 72LL * (unsigned int)a2;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      v8 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_reset_req_slot",
        974,
        "RESET: idx: %d: slot->status %d",
        a2,
        *(_DWORD *)(v6 + 16));
      result = v8;
    }
    if ( *(_DWORD *)(v6 + 16) != 1 && *(_DWORD *)(v4 + 3472) != v3 )
    {
      if ( *(__int64 *)(v6 + 24) >= 1 && *(_DWORD *)(v6 + 44) )
        result = _cam_req_mgr_disconnect_req_on_sync_link(result, v6 + 8);
      *(_WORD *)(v6 + 76) = 0;
      *(_QWORD *)(v6 + 12) = 0;
      *(_DWORD *)(v6 + 20) = 0;
      *(_QWORD *)(v6 + 24) = -1;
      *(_QWORD *)(v6 + 32) = 0;
      *(_QWORD *)(v6 + 40) = 0;
      *(_QWORD *)(v6 + 48) = 0;
      *(_QWORD *)(v6 + 56) = 0;
      for ( *(_QWORD *)(v6 + 64) = 0; v5; *(_QWORD *)(v7 + 76) = -1 )
      {
        if ( (debug_mdl & 0x10) != 0 && !debug_priority )
        {
          if ( v3 == 48 )
            goto LABEL_21;
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     debug_mdl & 0x10,
                     4,
                     "__cam_req_mgr_reset_req_slot",
                     1003,
                     "pd: %d: idx %d state %d",
                     *(_DWORD *)(v5 + 4),
                     v3,
                     *(_DWORD *)(v5 + 48LL * v3 + 52));
        }
        else if ( v3 == 48 )
        {
          goto LABEL_21;
        }
        v7 = v5 + 48LL * v3;
        v5 = *(_QWORD *)(v5 + 24);
        *(_BYTE *)(v7 + 84) = 0;
        *(_QWORD *)(v7 + 44) = 0;
        *(_QWORD *)(v7 + 52) = 0;
        *(_QWORD *)(v7 + 60) = 0;
        *(_QWORD *)(v7 + 68) = -1;
      }
    }
  }
  return result;
}
