__int64 __fastcall lim_process_set_default_scan_ie_request(
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
  __int64 result; // x0
  void *v13; // x19
  __int64 session_by_vdev_id; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x0
  __int64 v24; // x22
  void *v25; // x0
  size_t v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // [xsp+0h] [xbp-40h] BYREF
  __int64 v36; // [xsp+8h] [xbp-38h]
  __int64 v37; // [xsp+10h] [xbp-30h]
  __int64 v38; // [xsp+18h] [xbp-28h]
  __int64 v39; // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h]
  unsigned __int16 v41; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+38h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  if ( a2 )
  {
    v41 = *(_WORD *)(a2 + 6);
    result = _qdf_mem_malloc(0x800u, "lim_process_set_default_scan_ie_request", 457);
    if ( result )
    {
      v13 = (void *)result;
      session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
      if ( (unsigned int)lim_update_ext_cap_ie(a1, (const void *)(a2 + 8), (char *)v13, &v41, session_by_vdev_id) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Update ext cap IEs fails",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "lim_process_set_default_scan_ie_request",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40);
      }
      else
      {
        v23 = (_DWORD *)_qdf_mem_malloc(v41 + 24LL, "lim_process_set_default_scan_ie_request", 470);
        if ( v23 )
        {
          v24 = (__int64)v23;
          *v23 = *(unsigned __int16 *)(a2 + 4);
          v23[1] = 256;
          v25 = v23 + 6;
          v26 = v41;
          *(_QWORD *)(v24 + 16) = v25;
          *(_DWORD *)(v24 + 8) = v26;
          qdf_mem_copy(v25, v13, v26);
          v36 = v24;
          LOWORD(v35) = 4462;
          HIDWORD(v35) = 0;
          if ( (unsigned int)wma_post_ctrl_msg(a1, &v35) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: fail to send WMA_SET_IE_INFO",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "lim_process_set_default_scan_ie_request");
            _qdf_mem_free(v24);
          }
        }
      }
      result = _qdf_mem_free((__int64)v13);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: msg_buf is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_set_default_scan_ie_request",
               v35,
               v36,
               v37,
               v38,
               v39,
               v40);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
