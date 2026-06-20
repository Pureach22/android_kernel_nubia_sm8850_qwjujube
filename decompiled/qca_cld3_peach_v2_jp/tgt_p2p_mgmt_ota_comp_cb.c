__int64 __fastcall tgt_p2p_mgmt_ota_comp_cb(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  __int64 v24; // x21
  __int64 result; // x0
  unsigned int v26; // w22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // [xsp+8h] [xbp-38h] BYREF
  __int64 v36; // [xsp+10h] [xbp-30h]
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
  v36 = 0;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: context:%pK, buf:%pK, status:%d, tx complete params:%pK",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "tgt_p2p_mgmt_ota_comp_cb",
    a1,
    a2,
    a3,
    a4);
  if ( a1 )
  {
    v23 = _qdf_mem_malloc(0x18u, "tgt_p2p_mgmt_ota_comp_cb", 295);
    if ( v23 )
    {
      *(_QWORD *)v23 = a1;
      *(_QWORD *)(v23 + 8) = a2;
      v24 = v23;
      LOWORD(v35) = 1;
      *(_DWORD *)(v23 + 16) = a3;
      v36 = v23;
      v37 = p2p_process_evt;
      v38 = p2p_event_flush_callback;
      result = scheduler_post_message_debug(
                 0x4Eu,
                 0x4Eu,
                 73,
                 (unsigned __int16 *)&v35,
                 0x137u,
                 (__int64)"tgt_p2p_mgmt_ota_comp_cb");
      if ( (_DWORD)result )
      {
        v26 = result;
        _qdf_mem_free(v24);
        if ( a2 )
          _qdf_nbuf_free(a2);
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: post msg fail:%d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "tgt_p2p_mgmt_ota_comp_cb",
          a3);
        result = v26;
      }
    }
    else
    {
      if ( a2 )
        _qdf_nbuf_free(a2);
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: invalid context", v15, v16, v17, v18, v19, v20, v21, v22, "tgt_p2p_mgmt_ota_comp_cb");
    if ( a2 )
      _qdf_nbuf_free(a2);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
