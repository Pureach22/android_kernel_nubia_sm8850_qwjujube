__int64 __fastcall tdls_wma_update_peer_state(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w4
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // [xsp+0h] [xbp-50h]
  int v23; // [xsp+8h] [xbp-48h]
  __int64 v24; // [xsp+18h] [xbp-38h] BYREF
  int *v25; // [xsp+20h] [xbp-30h]
  __int64 v26; // [xsp+28h] [xbp-28h]
  __int64 v27; // [xsp+30h] [xbp-20h]
  __int64 v28; // [xsp+38h] [xbp-18h]
  __int64 v29; // [xsp+40h] [xbp-10h]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 8);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = nullptr;
  if ( v10 > 1 )
  {
    v23 = a2[3];
    v22 = *a2;
    qdf_trace_msg(
      0,
      8u,
      "%s: update TDLS peer %02x:%02x:%02x:**:**:%02x vdev %d, state %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_wma_update_peer_state",
      *((unsigned __int8 *)a2 + 4),
      *((unsigned __int8 *)a2 + 5),
      *((unsigned __int8 *)a2 + 6),
      *((unsigned __int8 *)a2 + 9),
      v22,
      v23);
    LODWORD(v24) = *(unsigned __int16 *)(a1 + 338);
    v25 = a2;
    result = scheduler_post_message_debug(
               0,
               0x36u,
               54,
               (unsigned __int16 *)&v24,
               0x755u,
               (__int64)"tdls_wma_update_peer_state");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: scheduler_post_msg failed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "tdls_wma_update_peer_state");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: TDLS mode disabled OR not enabled, current mode %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_validate_current_mode");
    result = 11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
