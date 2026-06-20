__int64 __fastcall tgt_scan_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w21
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int *v31; // x8
  unsigned int v32; // w19
  __int64 v33; // [xsp+8h] [xbp-38h] BYREF
  __int64 v34; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v35)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v36)(__int64, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v37; // [xsp+28h] [xbp-18h]
  __int64 v38; // [xsp+30h] [xbp-10h]
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = 0;
  v35 = nullptr;
  v36 = nullptr;
  v33 = 0;
  v34 = 0;
  if ( a1 && a2 )
  {
    v12 = *(unsigned __int8 *)(a2 + 8);
    v13 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            *(unsigned __int8 *)(a2 + 8),
            12);
    *(_QWORD *)a2 = v13;
    if ( v13 )
    {
      v34 = a2;
      v35 = scm_scan_event_handler;
      v36 = scm_scan_event_flush_callback;
      result = scheduler_post_message_debug(
                 0x15u,
                 0x15u,
                 21,
                 (unsigned __int16 *)&v33,
                 0x135u,
                 (__int64)"tgt_scan_event_handler");
      if ( (_DWORD)result )
      {
        v31 = *(unsigned int **)a2;
        v32 = result;
        wlan_objmgr_vdev_release_ref((__int64)v31, 0xCu, v31, v23, v24, v25, v26, v27, v28, v29, v30);
        result = v32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: null vdev, vdev_id: %d, psoc: 0x%pK",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "tgt_scan_event_handler",
        v12,
        a1);
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: psoc: 0x%pK, event_info: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_scan_event_handler",
      a1,
      a2);
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
