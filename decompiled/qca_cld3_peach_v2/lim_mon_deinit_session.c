__int64 __fastcall lim_mon_deinit_session(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
  if ( result )
  {
    if ( *(_DWORD *)(result + 92) == 3 )
    {
      wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(result + 16), 0xCu, 0, 0, v4, v5, v6, v7, v8, v9, v10, v11);
      return pe_delete_session(a1);
    }
  }
  return result;
}
