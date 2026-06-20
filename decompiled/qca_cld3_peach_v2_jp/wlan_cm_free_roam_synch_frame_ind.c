__int64 __fastcall wlan_cm_free_roam_synch_frame_ind(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0

  if ( !a1 )
    return 16;
  v2 = *(_QWORD *)(a1 + 880);
  if ( v2 )
  {
    _qdf_mem_free(v2);
    *(_DWORD *)(a1 + 872) = 0;
    *(_QWORD *)(a1 + 880) = 0;
  }
  v3 = *(_QWORD *)(a1 + 896);
  if ( v3 )
  {
    _qdf_mem_free(v3);
    *(_DWORD *)(a1 + 892) = 0;
    *(_QWORD *)(a1 + 896) = 0;
  }
  v4 = *(_QWORD *)(a1 + 912);
  if ( v4 )
  {
    _qdf_mem_free(v4);
    *(_DWORD *)(a1 + 908) = 0;
    *(_QWORD *)(a1 + 912) = 0;
  }
  result = *(_QWORD *)(a1 + 928);
  if ( result )
  {
    _qdf_mem_free(result);
    result = 0;
    *(_DWORD *)(a1 + 920) = 0;
    *(_QWORD *)(a1 + 928) = 0;
  }
  return result;
}
