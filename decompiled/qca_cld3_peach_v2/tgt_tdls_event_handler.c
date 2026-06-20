__int64 __fastcall tgt_tdls_event_handler(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  unsigned int v13; // w22
  __int64 *v14; // x21
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // [xsp+0h] [xbp-50h]
  int v44; // [xsp+8h] [xbp-48h]
  int v45; // [xsp+10h] [xbp-40h]
  __int64 v46; // [xsp+18h] [xbp-38h] BYREF
  __int64 *v47; // [xsp+20h] [xbp-30h]
  __int64 (__fastcall *v48)(__int64, double, double, double, double, double, double, double, double); // [xsp+28h] [xbp-28h]
  __int64 (__fastcall *v49)(); // [xsp+30h] [xbp-20h]
  __int64 v50; // [xsp+38h] [xbp-18h]
  __int64 v51; // [xsp+40h] [xbp-10h]
  __int64 v52; // [xsp+48h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v51 = 0;
  v48 = nullptr;
  v49 = nullptr;
  v46 = 0;
  v47 = nullptr;
  if ( a1 && a2 )
  {
    v44 = a2[3];
    v45 = a2[6];
    v43 = a2[2];
    qdf_trace_msg(
      0,
      8u,
      "%s: vdev: %d, type: %d, reason: %d%02x:%02x:%02x:**:**:%02x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_tdls_event_handler",
      *a2,
      *((unsigned __int16 *)a2 + 4),
      *((unsigned int *)a2 + 3),
      a2[1],
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52);
    v12 = _qdf_mem_malloc(0x18u, "tgt_tdls_event_handler", 173);
    if ( v12 )
    {
      v13 = *a2;
      v14 = (__int64 *)v12;
      v15 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 16);
      *v14 = v15;
      if ( v15 )
      {
        qdf_mem_copy(v14 + 1, a2, 0x10u);
        v47 = v14;
        v48 = tdls_process_evt;
        v49 = tgt_tdls_event_flush_cb;
        result = scheduler_post_message_debug(
                   0,
                   0,
                   73,
                   (unsigned __int16 *)&v46,
                   0xC1u,
                   (__int64)"tgt_tdls_event_handler");
        if ( (_DWORD)result )
        {
          v33 = result;
          qdf_trace_msg(
            0,
            2u,
            "%s: can't post msg to handle tdls event",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "tgt_tdls_event_handler");
          wlan_objmgr_vdev_release_ref(*v14, 0x10u, v34, v35, v36, v37, v38, v39, v40, v41, v42);
          _qdf_mem_free((__int64)v14);
          result = v33;
        }
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: null vdev, vdev_id: %d, psoc: 0x%pK",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "tgt_tdls_event_handler",
          v13,
          a1);
        result = 4;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: psoc: 0x%pK, info: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_tdls_event_handler",
      a1,
      a2);
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
