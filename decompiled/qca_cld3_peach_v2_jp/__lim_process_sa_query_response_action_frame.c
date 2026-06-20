__int64 __fastcall _lim_process_sa_query_response_action_frame(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x21
  __int64 v15; // x25
  unsigned int v16; // w20
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x23
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int8 v43; // w11
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  _WORD v52[2]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v53; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *((_QWORD *)a2 + 2);
  v15 = *((_QWORD *)a2 + 3);
  v16 = a2[10];
  v53 = 0;
  v52[0] = 0;
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: SA Query Response received",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "__lim_process_sa_query_response_action_frame");
  if ( v16 > 3 )
  {
    if ( *(_DWORD *)(a3 + 88) == 2 )
    {
      result = lim_send_sme_mgmt_frame_ind(a1, (unsigned __int8)*(_WORD *)v14 >> 4, v14, v16 + 24, 0, *a2, a2[2], 0);
    }
    else if ( (*(_WORD *)v14 & 0x4000) != 0 )
    {
      result = dph_lookup_hash_entry(
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 a1,
                 (unsigned __int8 *)(v14 + 10),
                 &v53,
                 a3 + 360);
      if ( result )
      {
        v34 = result;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: SA Query Response source addr:  %0x:%0x:%0x:%0x:%0x:%0x",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "__lim_process_sa_query_response_action_frame",
          *(unsigned __int8 *)(v14 + 10),
          *(unsigned __int8 *)(v14 + 11),
          *(unsigned __int8 *)(v14 + 12),
          *(unsigned __int8 *)(v14 + 13),
          *(unsigned __int8 *)(v14 + 14),
          *(unsigned __int8 *)(v14 + 15));
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: SA Query state for station: %d",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "__lim_process_sa_query_response_action_frame",
                   *(unsigned __int8 *)(v34 + 628));
        if ( *(_BYTE *)(v34 + 628) == 2 )
        {
          result = (__int64)qdf_mem_copy(v52, (const void *)(v15 + 2), 2u);
          v43 = 0;
          while ( *(unsigned __int16 *)(v34 + 626) + v43 != v52[0] )
          {
            if ( *(unsigned __int8 *)(v34 + 629) < (unsigned int)++v43 )
              goto LABEL_14;
          }
          result = lim_check_oci_match(a1, a3, v15 + 4, v14 + 10, v16 - 4);
          if ( (result & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Found matching SA Query Request - transaction ID: %d",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "__lim_process_sa_query_response_action_frame",
              v52[0]);
            result = tx_timer_deactivate(v34 + 360);
            *(_BYTE *)(v34 + 628) = 1;
          }
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Invalid frame length %d",
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "__lim_process_sa_query_response_action_frame",
               v16);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
