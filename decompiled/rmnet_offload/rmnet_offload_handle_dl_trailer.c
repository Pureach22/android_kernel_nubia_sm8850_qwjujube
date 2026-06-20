__int64 __fastcall rmnet_offload_handle_dl_trailer(_DWORD *a1)
{
  __int64 v2; // x19
  __int64 result; // x0
  _QWORD v4[3]; // [xsp+8h] [xbp-18h] BYREF

  v4[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = rmnet_offload_state_get();
  v4[0] = v4;
  v4[1] = v4;
  raw_spin_lock_bh(&rmnet_offload_main_lock);
  if ( *(_DWORD *)(v2 + 48) != *a1 )
    rmnet_offload_stats_update(4);
  if ( (unsigned int)rmnet_offload_engine_flush_all_flows((__int64)v4) )
    rmnet_offload_stats_update(5);
  *(_BYTE *)(v2 + 57) = 0;
  *(_QWORD *)(v2 + 48) = 0;
  raw_spin_unlock_bh(&rmnet_offload_main_lock);
  result = rmnet_offload_deliver_descs(v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
