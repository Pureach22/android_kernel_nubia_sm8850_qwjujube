__int64 __fastcall wlan_vdev_mlme_aid_mgr_max_aid_set(
        __int64 a1,
        unsigned __int16 a2,
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10
  unsigned __int16 v34; // w10
  unsigned __int16 v35; // w11
  unsigned __int16 v36; // w9

  result = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    if ( a2 )
    {
      v21 = *(_QWORD *)(result + 248);
      if ( v21 )
      {
        result = qdf_trace_msg(
                   0x8Fu,
                   8u,
                   "%s: VDEV mgr max aid %d",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "wlan_vdev_mlme_aid_mgr_max_aid_set",
                   a2);
        *(_WORD *)(v21 + 258) = a2;
        v30 = *(_QWORD *)(a1 + 1360);
        if ( v30 )
        {
          v31 = *(_QWORD *)(*(_QWORD *)(v30 + 2232) + 8LL);
          if ( v31 )
          {
            v32 = *(_QWORD *)(v31 + 264);
            if ( v32 )
              LOWORD(v32) = *(_WORD *)(v32 + 258) - *(_WORD *)(v32 + 256);
            v33 = *(_QWORD *)(v31 + 272);
            if ( v33 )
            {
              v34 = *(_WORD *)(v33 + 258) - *(_WORD *)(v33 + 256);
              v35 = v34;
              if ( (unsigned __int16)v32 < (unsigned int)v34 )
                v35 = v32;
              if ( (_WORD)v32 )
                LOWORD(v32) = v35;
              else
                LOWORD(v32) = v34;
            }
            v36 = *(_WORD *)(v31 + 256) + v32;
            *(_WORD *)(v31 + 258) = v36;
            return qdf_trace_msg(
                     0x8Fu,
                     8u,
                     "%s: MLO mgr max aid %d",
                     v22,
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     "wlan_vdev_mlme_aid_mgr_max_aid_set",
                     v36);
          }
        }
      }
    }
  }
  return result;
}
