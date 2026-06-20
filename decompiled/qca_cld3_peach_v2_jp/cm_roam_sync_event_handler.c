__int64 __fastcall cm_roam_sync_event_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        unsigned __int8 *a12)
{
  __int64 v12; // x19
  unsigned __int8 *v13; // x20

  if ( a12 )
  {
    if ( a12[306] == 1 )
    {
      v12 = a1;
      v13 = a12;
      cm_handle_roam_sync_update_hw_mode(a12 + 308, a2, a3, a4, a5, a6, a7, a8, a9);
      a1 = v12;
      a12 = v13;
    }
    return cm_fw_roam_sync_req(a1, a12[13], a12, 8u);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: invalid sync_ind", a2, a3, a4, a5, a6, a7, a8, a9, "cm_roam_sync_event_handler");
    return 29;
  }
}
