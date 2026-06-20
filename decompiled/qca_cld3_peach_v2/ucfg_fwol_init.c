__int64 __fastcall ucfg_fwol_init(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  unsigned int handler; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w19
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  handler = wlan_objmgr_register_psoc_create_handler(
              0x1Du,
              (__int64)fwol_psoc_object_created_notification,
              0,
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8);
  if ( handler )
  {
    v17 = handler;
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: unable to register psoc create handle",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "ucfg_fwol_init");
  }
  else
  {
    result = wlan_objmgr_register_psoc_destroy_handler(
               0x1Du,
               (__int64)fwol_psoc_object_destroyed_notification,
               0,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16);
    if ( !(_DWORD)result )
      return result;
    v17 = result;
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: unable to register psoc create handle",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ucfg_fwol_init");
    wlan_objmgr_unregister_psoc_create_handler(
      0x1Du,
      (__int64)fwol_psoc_object_created_notification,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34);
  }
  return v17;
}
