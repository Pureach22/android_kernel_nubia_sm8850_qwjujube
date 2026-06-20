__int64 __fastcall mlme_vdev_self_peer_delete_resp(__int64 a1)
{
  __int64 result; // x0
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[1] = a1;
  v12[0] = 5277;
  v12[4] = 0;
  v12[5] = 0;
  v12[2] = 0;
  v12[3] = mlme_vdev_self_peer_delete_resp_flush_cb;
  result = scheduler_post_message_debug(
             0x1Fu,
             0x34u,
             52,
             (unsigned __int16 *)v12,
             0x90Cu,
             (__int64)"mlme_vdev_self_peer_delete_resp");
  if ( (_DWORD)result )
  {
    wlan_objmgr_vdev_release_ref(*(_QWORD *)(a1 + 16), 0xBu, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    result = _qdf_mem_free(a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
