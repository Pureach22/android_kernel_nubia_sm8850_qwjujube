__int64 __fastcall ucfg_mlme_init(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const char *v16; // x2

  if ( (unsigned int)wlan_objmgr_register_peer_create_handler(
                       0,
                       (__int64)mlme_peer_object_created_notification,
                       0,
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8) )
  {
    v16 = "%s: peer create register notification failed";
  }
  else
  {
    if ( !(unsigned int)wlan_objmgr_register_peer_destroy_handler(
                          0,
                          (__int64)mlme_peer_object_destroyed_notification,
                          0,
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15) )
    {
      mlme_register_mlo_ext_ops();
      return 0;
    }
    v16 = "%s: peer destroy register notification failed";
  }
  qdf_trace_msg(0x1Fu, 2u, v16, v8, v9, v10, v11, v12, v13, v14, v15, "ucfg_mlme_init");
  return 16;
}
