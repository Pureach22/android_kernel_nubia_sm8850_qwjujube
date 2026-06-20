__int64 __fastcall lim_reconfig_obss_scan_param(
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
  __int64 session_by_vdev_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x22
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _DWORD *v34; // x20
  int v35; // w8
  __int64 v36; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v37; // [xsp+10h] [xbp-30h]
  __int64 v38; // [xsp+18h] [xbp-28h]
  __int64 v39; // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h]
  __int64 v41; // [xsp+30h] [xbp-10h]
  __int64 v42; // [xsp+38h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = nullptr;
  if ( a2 )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
    if ( session_by_vdev_id )
    {
      v21 = session_by_vdev_id + 0x2000;
      v22 = *(unsigned __int8 *)(session_by_vdev_id + 8676);
      v23 = *(unsigned __int8 *)(session_by_vdev_id + 10020);
      if ( (_DWORD)v22 == 1 && (v23 & 1) != 0 && *(_DWORD *)(session_by_vdev_id + 10016) )
      {
        v24 = session_by_vdev_id;
        result = _qdf_mem_malloc(0x1Cu, "lim_reconfig_obss_scan_param", 11909);
        if ( result )
        {
          v34 = (_DWORD *)result;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev_id %d: sending event:%d scan_reconfig:%d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "lim_reconfig_obss_scan_param",
            *(unsigned __int8 *)(v24 + 10),
            *(unsigned int *)(v24 + 10016),
            *(unsigned __int8 *)(a2 + 5));
          *v34 = *(unsigned __int8 *)(v24 + 10);
          v34[2] = *(_DWORD *)(v24 + 10016);
          v34[3] = *(_BYTE *)(v21 + 553) & 0x3F;
          if ( *(_BYTE *)(a2 + 5) )
            v35 = 1200000;
          else
            v35 = 120000;
          v34[4] = v35;
          v34[5] = 200;
          if ( *(_DWORD *)(v24 + 10016) == 2 )
            v34[6] = 50000;
          LODWORD(v36) = 4524;
          v37 = v34;
          result = scheduler_post_message_debug(
                     0x35u,
                     0x36u,
                     54,
                     (unsigned __int16 *)&v36,
                     0x2EA4u,
                     (__int64)"lim_reconfig_obss_scan_param");
          if ( (_DWORD)result )
            result = _qdf_mem_free((__int64)v34);
        }
      }
      else
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: %d: obss color det not enabled, he_cap:%d, sup:%d:%d event_type:%d",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "lim_reconfig_obss_scan_param",
                   *(unsigned __int8 *)(session_by_vdev_id + 10),
                   v22,
                   v23,
                   *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2810LL),
                   *(_DWORD *)(session_by_vdev_id + 10016),
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42);
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Session not found for given vdev_id %d",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "lim_reconfig_obss_scan_param",
                 *(unsigned __int8 *)(a2 + 4));
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Buffer is Pointing to NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_reconfig_obss_scan_param");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
