__int64 __fastcall cm_roam_candidate_event_handler(__int64 a1, unsigned __int8 *a2)
{
  return wlan_cm_add_frame_to_scan_db(a1, a2);
}
