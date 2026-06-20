__int64 __fastcall wlan_vdev_mlme_set_start_aid(
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
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
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
  unsigned int v33; // w4
  __int64 v34; // x9
  unsigned int v35; // w9

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj )
  {
    v21 = *(_QWORD *)(cmpt_obj + 248);
    if ( v21 )
    {
      *(_WORD *)(v21 + 256) = a2;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: VDEV mgr start aid %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_vdev_mlme_set_start_aid",
        a2);
      v30 = *(_QWORD *)(a1 + 1360);
      if ( !v30 )
        return 0;
      v31 = *(_QWORD *)(*(_QWORD *)(v30 + 2232) + 8LL);
      if ( v31 )
      {
        v32 = *(_QWORD *)(v31 + 264);
        if ( v32 )
        {
          v33 = *(unsigned __int16 *)(v32 + 256);
          v34 = *(_QWORD *)(v31 + 272);
          if ( v34 )
            goto LABEL_7;
        }
        else
        {
          v33 = 0;
          v34 = *(_QWORD *)(v31 + 272);
          if ( v34 )
          {
LABEL_7:
            v35 = *(unsigned __int16 *)(v34 + 256);
            if ( v33 <= v35 )
              LOWORD(v33) = v35;
          }
        }
        *(_WORD *)(v31 + 256) = v33;
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: MLO mgr start aid %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wlan_vdev_mlme_set_start_aid");
        return 0;
      }
    }
  }
  return 16;
}
