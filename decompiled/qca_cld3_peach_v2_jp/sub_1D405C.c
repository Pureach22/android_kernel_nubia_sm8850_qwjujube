void __fastcall sub_1D405C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, char a7)
{
  if ( a7 < 0 )
    mlme_vdev_state_start_exit();
  else
    tgt_vdev_mgr_start_response_handler();
}
