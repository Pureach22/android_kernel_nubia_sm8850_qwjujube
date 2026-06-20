__int64 __fastcall wlan_dcs_init(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19

  result = wlan_objmgr_register_psoc_create_handler(
             0x24u,
             (__int64)wlan_dcs_psoc_obj_create_notification,
             0,
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8);
  if ( !(_DWORD)result )
  {
    result = wlan_objmgr_register_psoc_destroy_handler(
               0x24u,
               (__int64)wlan_dcs_psoc_obj_destroy_notification,
               0,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16);
    if ( (_DWORD)result )
    {
      v25 = result;
      wlan_objmgr_unregister_psoc_create_handler(
        0x24u,
        (__int64)wlan_dcs_psoc_obj_create_notification,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24);
      return v25;
    }
  }
  return result;
}
