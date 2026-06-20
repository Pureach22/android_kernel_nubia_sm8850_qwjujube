__int64 __fastcall wma_set_vdev_latency_level_param(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w21
  char wlm_multi_client_ll_caps; // w22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8
  int v24; // w9
  int v25; // w9
  int v26; // w9
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x10
  int v36; // w8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _DWORD v45[10]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v46; // [xsp+30h] [xbp-30h]
  __int64 v47; // [xsp+38h] [xbp-28h]
  __int64 v48; // [xsp+40h] [xbp-20h]
  __int64 v49; // [xsp+48h] [xbp-18h]
  int v50; // [xsp+50h] [xbp-10h]
  int v51; // [xsp+54h] [xbp-Ch]
  __int64 v52; // [xsp+58h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5720LL);
  wlm_multi_client_ll_caps = wlan_mlme_get_wlm_multi_client_ll_caps(*(_QWORD *)(a1 + 21552));
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: INI support: %d, fw capability:%d",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wma_set_vdev_latency_level_param",
             v4,
             wlm_multi_client_ll_caps & 1);
  if ( (wlm_multi_client_ll_caps & 1) != 0 )
  {
    if ( v4 )
    {
      v45[0] = 181;
      v45[1] = v4;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Setting vdev params for latency level flags",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wma_set_vdev_latency_level_param");
      v23 = *(_DWORD **)(a1 + 8);
      v24 = v23[1422];
      v45[2] = 172;
      v45[3] = v24;
      v25 = v23[1423];
      v45[4] = 173;
      v45[5] = v25;
      v26 = v23[1424];
      v45[6] = 174;
      v45[7] = v26;
      LODWORD(v23) = v23[1425];
      v45[8] = 175;
      v45[9] = (_DWORD)v23;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Setting vdev params for Latency level UL/DL flags",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wma_set_vdev_latency_level_param");
      v35 = *(_QWORD *)(a1 + 8);
      v46 = 0x640064000000B0LL;
      v47 = 0x3C003C000000B1LL;
      v48 = 0x280028000000B2LL;
      v49 = 0x140014000000B3LL;
      v36 = *(unsigned __int8 *)(v35 + 5686);
      v50 = 180;
      v51 = v36;
      result = wma_send_multi_pdev_vdev_set_params(1, a2, v45, 10);
      if ( (_DWORD)result )
        result = qdf_trace_msg(
                   0x36u,
                   2u,
                   "%s: Failed to configure vdev latency level params",
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   "wma_set_vdev_latency_level_param");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
