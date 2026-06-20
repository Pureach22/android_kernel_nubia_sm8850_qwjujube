__int64 __fastcall tgt_p2p_lo_event_cb(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  __int64 v21; // x21
  _QWORD *v22; // x0
  __int64 v23; // x20
  __int64 result; // x0
  unsigned int v25; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  __int64 v35; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v36; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v37)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v38)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  v37 = nullptr;
  v38 = nullptr;
  v35 = 0;
  v36 = nullptr;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, event_info:%pK",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "tgt_p2p_lo_event_cb",
    a1,
    a2);
  if ( !a1 )
  {
    v34 = "%s: psoc context passed is NULL";
    goto LABEL_9;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
  {
    v34 = "%s: p2p soc object is NULL";
LABEL_9:
    qdf_trace_msg(0x4Eu, 2u, v34, v12, v13, v14, v15, v16, v17, v18, v19, "tgt_p2p_lo_event_cb");
    if ( a2 )
      _qdf_mem_free(a2);
    goto LABEL_12;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: invalid lo stop event information",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "tgt_p2p_lo_event_cb");
LABEL_12:
    result = 4;
    goto LABEL_13;
  }
  v21 = comp_private_obj;
  v22 = (_QWORD *)_qdf_mem_malloc(0x10u, "tgt_p2p_lo_event_cb", 146);
  if ( v22 )
  {
    *v22 = v21;
    v22[1] = a2;
    v23 = (__int64)v22;
    LOWORD(v35) = 3;
    v36 = v22;
    v37 = p2p_process_evt;
    v38 = p2p_event_flush_callback;
    result = scheduler_post_message_debug(
               0x4Eu,
               0x4Eu,
               73,
               (unsigned __int16 *)&v35,
               0xA1u,
               (__int64)"tgt_p2p_lo_event_cb");
    if ( (_DWORD)result )
    {
      v25 = result;
      _qdf_mem_free(*(_QWORD *)(v23 + 8));
      _qdf_mem_free(v23);
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: post msg fail:%d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "tgt_p2p_lo_event_cb",
        v25);
      result = v25;
    }
  }
  else
  {
    _qdf_mem_free(a2);
    result = 2;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
