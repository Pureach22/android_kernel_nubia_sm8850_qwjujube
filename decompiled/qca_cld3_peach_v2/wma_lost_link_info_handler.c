__int64 __fastcall wma_lost_link_info_handler(
        __int64 a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v12; // w8
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int16 *)(a1 + 162);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( v12 <= a2 )
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: received invalid vdev_id %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wma_lost_link_info_handler",
               a2);
  }
  else
  {
    result = (__int64)_cds_get_context(54, (__int64)"wma_is_vdev_up", a4, a5, a6, a7, a8, a9, a10, a11);
    if ( result )
    {
      result = wlan_is_vdev_id_up(*(_QWORD *)(result + 32), a2);
      if ( (result & 1) != 0 )
      {
        v24 = *(_QWORD *)(a1 + 520) + 488LL * a2;
        if ( *(_DWORD *)(v24 + 164) == 2 && !*(_DWORD *)(v24 + 168) )
        {
          lim_update_lost_link_rssi(*(_QWORD *)(a1 + 16), a3, v16, v17, v18, v19, v20, v21, v22, v23);
          result = _qdf_mem_malloc(8u, "wma_lost_link_info_handler", 618);
          if ( result )
          {
            v25 = result;
            *(_DWORD *)result = a2;
            *(_DWORD *)(result + 4) = a3;
            v35 = result;
            LOWORD(v34) = 5254;
            HIDWORD(v34) = 0;
            result = scheduler_post_message_debug(
                       0x36u,
                       0x34u,
                       52,
                       (unsigned __int16 *)&v34,
                       0x276u,
                       (__int64)"wma_lost_link_info_handler");
            if ( (_DWORD)result )
            {
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: fail to post msg to SME",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "wma_lost_link_info_handler");
              result = _qdf_mem_free(v25);
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
