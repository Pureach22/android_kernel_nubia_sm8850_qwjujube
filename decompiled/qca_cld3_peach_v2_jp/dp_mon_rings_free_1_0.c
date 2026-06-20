__int64 __fastcall dp_mon_rings_free_1_0(unsigned __int8 *a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  unsigned int v4; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w26
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  unsigned int v31; // w23
  __int64 v32; // x27
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w23

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
  dp_srng_free(v1, v1 + 800 + 80LL * v4, v5, v6, v7, v8, v9, v10, v11, v12);
  dp_srng_free(v1, v1 + 960 + 80LL * v4, v13, v14, v15, v16, v17, v18, v19, v20);
  ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_mon_dest_rings_free)(a1, v4);
  result = *(_QWORD *)(v1 + 40);
  if ( *(unsigned __int8 *)(result + 808) >= 2u )
  {
    v21 = 1;
    while ( 1 )
    {
      v41 = *a1;
      result = wlan_cfg_per_pdev_lmac_ring(result);
      if ( (_DWORD)result )
        break;
      if ( !v41 )
      {
        v31 = v21;
        if ( v21 >= 3 )
          goto LABEL_16;
LABEL_14:
        v30 = v31;
        goto LABEL_10;
      }
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Both mac_id and pdev_id cannot be non zero",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dp_get_lmac_id_for_pdev_id");
      v30 = 0;
      v31 = 0;
LABEL_10:
      v32 = 80 * v30;
      dp_srng_free(v1, v1 + 800 + 80 * v30, v22, v23, v24, v25, v26, v27, v28, v29);
      dp_srng_free(v1, v1 + 960 + v32, v33, v34, v35, v36, v37, v38, v39, v40);
      ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_mon_dest_rings_free)(a1, v31);
      result = *(_QWORD *)(v1 + 40);
      if ( ++v21 >= *(unsigned __int8 *)(result + 808) )
        return result;
    }
    if ( v41 )
      goto LABEL_16;
    v31 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
    if ( v31 >= 3 )
      goto LABEL_16;
    goto LABEL_14;
  }
  return result;
}
