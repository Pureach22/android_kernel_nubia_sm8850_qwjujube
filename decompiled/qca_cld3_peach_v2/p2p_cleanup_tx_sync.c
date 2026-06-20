__int64 __fastcall p2p_cleanup_tx_sync(
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
  __int64 v12; // x0
  __int64 v13; // x20
  int v14; // w8
  __int64 result; // x0
  unsigned int v16; // w0
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  __int64 v27; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v28)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  v28 = nullptr;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  if ( a1 )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: p2p_soc_obj:%pK, vdev:%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "p2p_cleanup_tx_sync",
      a1,
      a2);
    v12 = _qdf_mem_malloc(0x10u, "p2p_cleanup_tx_sync", 2088);
    if ( v12 )
    {
      v13 = v12;
      *(_QWORD *)v12 = a1;
      if ( a2 )
        v14 = *(unsigned __int8 *)(a2 + 168);
      else
        v14 = -1;
      *(_DWORD *)(v12 + 8) = v14;
      qdf_event_reset(a1 + 136);
      LOWORD(v26) = 5;
      v27 = v13;
      v28 = p2p_process_cmd;
      v16 = scheduler_post_message_debug(
              0x4Eu,
              0x4Eu,
              72,
              (unsigned __int16 *)&v26,
              0x838u,
              (__int64)"p2p_cleanup_tx_sync");
      if ( v16 )
      {
        v17 = v16;
        _qdf_mem_free(v13);
LABEL_12:
        result = v17;
        goto LABEL_13;
      }
      result = qdf_wait_single_event(a1 + 136, 0x7D0u);
      if ( (_DWORD)result )
      {
        v17 = result;
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: wait for cleanup tx timeout, %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "p2p_cleanup_tx_sync",
          (unsigned int)result);
        goto LABEL_12;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: p2p soc context is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "p2p_cleanup_tx_sync");
    result = 16;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
