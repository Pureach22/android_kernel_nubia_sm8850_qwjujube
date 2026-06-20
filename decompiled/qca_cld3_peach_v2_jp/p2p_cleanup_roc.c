__int64 __fastcall p2p_cleanup_roc(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  __int64 v15; // x21
  int v16; // w8
  __int64 result; // x0
  unsigned int v18; // w0
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+8h] [xbp-38h] BYREF
  __int64 v29; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v30)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  v30 = nullptr;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  if ( a1 )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: p2p_soc_obj:%pK, vdev:%pK, sync:%d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "p2p_cleanup_roc",
      a1,
      a2,
      a3 & 1);
    v14 = _qdf_mem_malloc(0x10u, "p2p_cleanup_roc", 804);
    if ( v14 )
    {
      v15 = v14;
      *(_QWORD *)v14 = a1;
      if ( a2 )
        v16 = *(unsigned __int8 *)(a2 + 104);
      else
        v16 = -1;
      *(_DWORD *)(v14 + 8) = v16;
      qdf_event_reset(a1 + 96);
      LOWORD(v28) = 4;
      v29 = v15;
      v30 = p2p_process_cmd;
      v18 = scheduler_post_message_debug(0x4Eu, 0x4Eu, 72, (unsigned __int16 *)&v28, 0x334u, (__int64)"p2p_cleanup_roc");
      if ( v18 )
      {
        v19 = v18;
        _qdf_mem_free(v15);
LABEL_10:
        result = v19;
        goto LABEL_15;
      }
      if ( (a3 & 1) == 0 )
      {
        result = 0;
        goto LABEL_15;
      }
      result = qdf_wait_single_event(a1 + 96, 0x7D0u);
      if ( (_DWORD)result )
      {
        v19 = result;
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: wait for cleanup roc timeout, %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "p2p_cleanup_roc",
          (unsigned int)result);
        goto LABEL_10;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: p2p soc context is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "p2p_cleanup_roc");
    result = 16;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
