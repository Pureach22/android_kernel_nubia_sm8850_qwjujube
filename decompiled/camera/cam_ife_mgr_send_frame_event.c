__int64 __fastcall cam_ife_mgr_send_frame_event(__int64 a1, int a2)
{
  __int64 result; // x0

  result = cam_presil_mode_enabled(a1);
  if ( (result & 1) != 0 )
  {
    if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x8000000,
        4,
        "cam_ife_mgr_send_frame_event",
        7617,
        "PRESIL FRAME req_id=%llu ctx_index %u",
        a1,
        a2);
    result = cam_presil_send_event(291, (unsigned int)a1);
    if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x8000000,
               4,
               "cam_ife_mgr_send_frame_event",
               7620,
               "PRESIL FRAME FINISHED req_id=%llu ctx_index %u",
               a1,
               a2);
  }
  return result;
}
