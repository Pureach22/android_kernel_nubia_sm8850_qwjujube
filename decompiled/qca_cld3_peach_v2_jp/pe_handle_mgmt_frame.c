__int64 __fastcall pe_handle_mgmt_frame(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  _QWORD *v24; // x20
  void *v25; // x0
  __int64 v26; // x19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  unsigned __int16 *v36; // x21
  unsigned __int16 v37; // w22
  int v38; // w8
  unsigned int v39; // w20
  __int64 v40; // [xsp+0h] [xbp-40h] BYREF
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  __int64 v42; // [xsp+10h] [xbp-30h]
  __int64 v43; // [xsp+18h] [xbp-28h]
  __int64 v44; // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v40 = 0;
  context = _cds_get_context(53, (__int64)"pe_handle_mgmt_frame", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    if ( a11 )
      _qdf_nbuf_free(a11);
    goto LABEL_8;
  }
  if ( *((_BYTE *)context + 21710) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Drop Rx pkt with user config",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "pe_handle_mgmt_frame");
    if ( a11 )
      _qdf_nbuf_free(a11);
    result = 0;
    goto LABEL_9;
  }
  v24 = context;
  v25 = qdf_mem_malloc_atomic_fl(0x48u, (__int64)"pe_handle_mgmt_frame", 0x5BAu);
  if ( v25 )
  {
    v26 = (__int64)v25;
    if ( (unsigned int)wma_form_rx_packet(a11, a12, v25) )
    {
      v35 = jiffies;
      if ( pe_handle_mgmt_frame___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Failed to fill cds packet from event buffer",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "pe_handle_mgmt_frame");
        pe_handle_mgmt_frame___last_ticks = v35;
      }
      goto LABEL_8;
    }
    if ( (unsigned int)wma_ds_peek_rx_packet_info(v26, &v40) )
    {
      cds_pkt_return_packet(v26);
LABEL_8:
      result = 16;
      goto LABEL_9;
    }
    v36 = *(unsigned __int16 **)(v40 + 16);
    v37 = *v36;
    v38 = (unsigned __int8)*v36 >> 4;
    if ( (v38 == 8 || v38 == 5) && (pe_filter_bcn_probe_frame(v24, *(_QWORD *)(v40 + 16)) & 1) == 0 )
    {
      cds_pkt_return_packet(v26);
      result = 0;
      goto LABEL_9;
    }
    if ( (v37 & 0xF0) != 0x40 )
    {
      if ( !(unsigned int)pe_drop_pending_rx_mgmt_frames(v24, v36, v26) )
      {
        v42 = v26;
        LOWORD(v41) = 5044;
        HIDWORD(v41) = 0;
        result = ((__int64 (__fastcall *)(_QWORD *, __int64 *, _QWORD, _QWORD))sys_bbt_process_message_core)(
                   v24,
                   &v41,
                   (*v36 >> 2) & 3,
                   (unsigned __int8)*v36 >> 4);
        if ( !(_DWORD)result )
          goto LABEL_9;
        cds_pkt_return_packet(v26);
        lim_decrement_pending_mgmt_count(v24);
      }
      goto LABEL_8;
    }
    result = pe_handle_probe_req_frames(v26);
    if ( (_DWORD)result )
    {
      v39 = result;
      cds_pkt_return_packet(v26);
      result = v39;
    }
  }
  else
  {
    if ( a11 )
      _qdf_nbuf_free(a11);
    result = 2;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
