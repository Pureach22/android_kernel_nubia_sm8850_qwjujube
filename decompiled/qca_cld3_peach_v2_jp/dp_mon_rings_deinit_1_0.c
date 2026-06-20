__int64 __fastcall dp_mon_rings_deinit_1_0(unsigned __int8 *a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  unsigned int v4; // w21
  __int64 v5; // x4
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x4
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w26
  __int64 v24; // x4
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  unsigned int v34; // w23
  __int64 v35; // x27
  __int64 v36; // x4
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w23

  v1 = *((_QWORD *)a1 + 1);
  result = *(_QWORD *)(v1 + 40);
  if ( !*(_BYTE *)(result + 808) )
    return result;
  v4 = *a1;
  result = wlan_cfg_per_pdev_lmac_ring(result);
  if ( (_DWORD)result )
  {
    if ( v4 )
    {
LABEL_16:
      __break(0x5512u);
      return result;
    }
    v4 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
  }
  if ( v4 > 2 )
    goto LABEL_16;
  dp_srng_deinit(v1, (__int64 *)(v1 + 800 + 80LL * v4), 0x11u, 0, v5, v6, v7, v8, v9, v10, v11, v12, v13);
  dp_srng_deinit(v1, (__int64 *)(v1 + 960 + 80LL * v4), 0x1Bu, 0, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_mon_dest_rings_deinit)(a1, v4);
  result = *(_QWORD *)(v1 + 40);
  if ( *(unsigned __int8 *)(result + 808) >= 2u )
  {
    v23 = 1;
    while ( 1 )
    {
      v45 = *a1;
      result = wlan_cfg_per_pdev_lmac_ring(result);
      if ( (_DWORD)result )
        break;
      if ( !v45 )
      {
        v34 = v23;
        if ( v23 >= 3 )
          goto LABEL_16;
LABEL_14:
        v33 = v34;
        goto LABEL_10;
      }
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Both mac_id and pdev_id cannot be non zero",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_get_lmac_id_for_pdev_id");
      v33 = 0;
      v34 = 0;
LABEL_10:
      v35 = 80 * v33;
      dp_srng_deinit(v1, (__int64 *)(v1 + 800 + 80 * v33), 0x11u, 0, v24, v25, v26, v27, v28, v29, v30, v31, v32);
      dp_srng_deinit(v1, (__int64 *)(v1 + 960 + v35), 0x1Bu, 0, v36, v37, v38, v39, v40, v41, v42, v43, v44);
      ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_mon_dest_rings_deinit)(a1, v34);
      result = *(_QWORD *)(v1 + 40);
      if ( ++v23 >= *(unsigned __int8 *)(result + 808) )
        return result;
    }
    if ( v45 )
      goto LABEL_16;
    v34 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
    if ( v34 >= 3 )
      goto LABEL_16;
    goto LABEL_14;
  }
  return result;
}
