__int64 __fastcall wifi_pos_vdev_delete_all_ranging_peers(__int64 a1)
{
  __int64 vdev_priv_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  const char *v12; // x2
  __int64 v14; // [xsp+0h] [xbp-10h] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0x100000000000LL;
  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(a1);
  if ( !vdev_priv_obj )
  {
    v11 = 16;
    v12 = "%s: Wifi pos vdev priv obj is null";
    goto LABEL_6;
  }
  if ( !*(_BYTE *)(vdev_priv_obj + 12264) )
  {
    v11 = 0;
    goto LABEL_8;
  }
  *(_BYTE *)(vdev_priv_obj + 12265) = 1;
  LOBYTE(v14) = *(_BYTE *)(a1 + 104);
  v11 = tgt_vdev_mgr_peer_delete_all_send(a1, (__int64)&v14, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( v11 )
  {
    v12 = "%s: Send vdev delete all peers failed";
LABEL_6:
    qdf_trace_msg(0x25u, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "wifi_pos_vdev_delete_all_ranging_peers", v14, v15);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v11;
}
