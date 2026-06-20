__int64 __fastcall vdevmgr_mlme_ext_hdl_destroy(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  _DWORD v37[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v38; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v39)(); // [xsp+18h] [xbp-28h]
  __int64 v40; // [xsp+20h] [xbp-20h]
  __int64 v41; // [xsp+28h] [xbp-18h]
  __int64 v42; // [xsp+30h] [xbp-10h]
  __int64 v43; // [xsp+38h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 504);
  v11 = *(unsigned __int8 *)(v10 + 104);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: Sending vdev delete to firmware for vdev id = %d ",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "vdevmgr_mlme_ext_hdl_destroy",
    *(unsigned __int8 *)(v10 + 104));
  if ( *(_QWORD *)(a1 + 520) )
  {
    if ( (unsigned int)vdev_mgr_delete_send(a1, v12, v13, v14, v15, v16, v17, v18, v19) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed to send vdev delete to firmware",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "vdevmgr_mlme_ext_hdl_destroy");
      v41 = 0;
      v42 = 0;
      v37[0] = 0;
      v38 = 0;
      v37[1] = v11;
      v39 = mlme_wma_vdev_detach_post_cb;
      v40 = 0;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x1Fu,
                           0x49u,
                           73,
                           (unsigned __int16 *)v37,
                           0x67Du,
                           (__int64)"mlme_wma_vdev_detach_handler") )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Failed to post wma vdev detach",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "mlme_wma_vdev_detach_handler");
    }
    mlme_ext_handler_destroy(a1);
    result = 0;
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
