__int64 __fastcall dp_rx_mon_populate_cfr_ppdu_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned int v4; // w25
  int v5; // w9
  int v8; // w8
  int v9; // w8
  unsigned int v10; // w8
  unsigned int v11; // w8
  __int64 v12; // x9
  unsigned int v13; // w9
  int v14; // w8
  unsigned int v15; // w9
  int v16; // w10
  unsigned int v17; // w8
  unsigned int v18; // w8
  int v19; // w8
  unsigned int v20; // w8
  __int64 v21; // x22
  __int64 v22; // x27
  char *v23; // x23
  __int64 v24; // x26
  __int64 v25; // x24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 ref_by_id_4; // x0
  __int64 v35; // x22
  __int64 v36; // x0
  unsigned __int16 v37; // w1
  __int64 result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  v3 = *(_QWORD *)(a1 + 8);
  v4 = *(unsigned __int8 *)(a2 + 19);
  v5 = *(_DWORD *)(a3 + 36);
  *(_DWORD *)a3 = *(_DWORD *)a2;
  *(_QWORD *)(a3 + 56) = *(_QWORD *)(a2 + 72);
  v8 = (*(_QWORD *)(a2 + 92) >> 21) & 0x3C000000 | v5 & 0x83FFFFFF;
  *(_DWORD *)(a3 + 36) = v8;
  *(_BYTE *)(a3 + 304) = *(_BYTE *)(a2 + 145);
  *(_BYTE *)(a3 + 305) = *(_BYTE *)(a2 + 146);
  *(_BYTE *)(a3 + 306) = *(_BYTE *)(a2 + 147);
  *(_BYTE *)(a3 + 307) = *(_BYTE *)(a2 + 148);
  *(_BYTE *)(a3 + 308) = *(_BYTE *)(a2 + 149);
  *(_BYTE *)(a3 + 309) = *(_BYTE *)(a2 + 150);
  *(_BYTE *)(a3 + 310) = *(_BYTE *)(a2 + 151);
  *(_BYTE *)(a3 + 311) = *(_BYTE *)(a2 + 152);
  v9 = (*(_QWORD *)(a2 + 92) >> 51) & 3 | v8 & 0xFFFFFFFC;
  *(_DWORD *)(a3 + 36) = v9;
  *(_BYTE *)(a3 + 69) = (*(_DWORD *)(a2 + 92) & 0x2000000) != 0;
  v10 = (2 * *(_DWORD *)(a2 + 92)) & 0x2000000 | v9 & 0xFDFFFFFF;
  *(_DWORD *)(a3 + 36) = v10;
  v11 = v10 & 0xFF0FFFFF;
  v12 = *(_QWORD *)(a2 + 92);
  if ( (v12 & 0x78600000) == 0x18600000 )
    v13 = 0x100000;
  else
    v13 = ((unsigned int)v12 >> 1) & 0x300000;
  v14 = v11 | v13;
  *(_DWORD *)(a3 + 36) = v14;
  v15 = *(_DWORD *)(a2 + 92);
  v16 = (v15 >> 27) & 0xF;
  if ( v16 == 3 )
  {
    v18 = (v15 >> 18) & 4 | v14 & 0xBF3FFFFB;
  }
  else
  {
    if ( v16 != 4 )
      goto LABEL_9;
    v17 = v14 & 0xBF3FFFFB | (*(unsigned __int16 *)(a2 + 184) >> 13) & 4;
    *(_DWORD *)(a3 + 36) = v17;
    v18 = v17 & 0xFEFFFFFF | (((*(unsigned __int16 *)(a2 + 184) >> 12) & 1) << 24);
  }
  *(_DWORD *)(a3 + 36) = v18;
LABEL_9:
  if ( v4 >= 0x26 )
  {
    v35 = a1;
    v36 = printk(
            &unk_9BB309,
            "num_users <= 37",
            "dp_rx_mon_populate_cfr_ppdu_info",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_rx_mon.c");
    dump_stack(v36);
    a1 = v35;
    v19 = *(unsigned __int8 *)(a2 + 19);
    if ( !*(_BYTE *)(a2 + 19) )
      goto LABEL_19;
  }
  else
  {
    v19 = *(unsigned __int8 *)(a2 + 19);
    if ( !*(_BYTE *)(a2 + 19) )
      goto LABEL_19;
  }
  v20 = v19 - 1;
  v21 = *(_QWORD *)(a1 + 8);
  v22 = a2 + 416;
  v23 = (char *)(a3 + 422);
  if ( v20 >= 0x24 )
    v20 = 36;
  v24 = v20 + 1;
  do
  {
    ref_by_id_4 = dp_peer_get_ref_by_id_4(v21, *(_WORD *)(v22 + 2));
    if ( ref_by_id_4 )
    {
      v25 = ref_by_id_4;
      qdf_mem_copy(v23, (const void *)(ref_by_id_4 + 44), 6u);
      dp_peer_unref_delete(v25, 6u, v26, v27, v28, v29, v30, v31, v32, v33);
    }
    else
    {
      *((_WORD *)v23 - 27) = -1;
    }
    --v24;
    v22 += 344;
    v23 += 128;
  }
  while ( v24 );
LABEL_19:
  if ( v4 - 1 > 0x25 )
  {
    __break(0x5512u);
    JUMPOUT(0xE1827C);
  }
  v37 = *(_WORD *)(a2 + 344LL * (v4 - 1) + 418);
  *(_BYTE *)(a3 + 296) = v4;
  result = dp_peer_get_ref_by_id_4(v3, v37);
  if ( result )
  {
    *(_WORD *)(a3 + 25) = *(_WORD *)(result + 16);
    *(_BYTE *)(a3 + 27) = *(_BYTE *)(*(_QWORD *)(result + 24) + 59LL);
    return dp_peer_unref_delete(result, 6u, v39, v40, v41, v42, v43, v44, v45, v46);
  }
  else
  {
    *(_WORD *)(a3 + 25) = -1;
  }
  return result;
}
