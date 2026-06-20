__int64 __fastcall sme_register_mgmt_frame_ind_callback(__int64 a1, __int64 a2)
{
  __int64 v5; // x0
  unsigned int v6; // w20

  if ( (unsigned int)qdf_mutex_acquire(a1 + 12848) )
    return 16;
  v5 = _qdf_mem_malloc(0x10u, "sme_register_mgmt_frame_ind_callback", 5625);
  if ( v5 )
  {
    *(_QWORD *)(v5 + 8) = a2;
    *(_DWORD *)v5 = 1053817;
    v6 = umac_send_mb_message_to_mac();
  }
  else
  {
    v6 = 2;
  }
  qdf_mutex_release(a1 + 12848);
  return v6;
}
