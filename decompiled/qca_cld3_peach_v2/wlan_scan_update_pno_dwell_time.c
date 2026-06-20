__int64 __fastcall wlan_scan_update_pno_dwell_time(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x21

  v3 = *(_QWORD *)(result + 216);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 80);
    if ( v4 )
    {
      result = policy_mgr_get_beaconing_mode_count(*(_QWORD *)(v3 + 80), 0);
      if ( (_DWORD)result || (result = policy_mgr_mode_specific_connection_count(v4, 2, 0), (_DWORD)result) )
      {
        *(_DWORD *)(a2 + 40) = *(_DWORD *)(a3 + 52);
        *(_DWORD *)(a2 + 44) = *(_DWORD *)(a3 + 56);
      }
    }
  }
  return result;
}
