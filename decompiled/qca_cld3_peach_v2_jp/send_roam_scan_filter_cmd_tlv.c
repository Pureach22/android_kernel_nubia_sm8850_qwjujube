__int64 __fastcall send_roam_scan_filter_cmd_tlv(__int64 a1, __int64 a2)
{
  int v4; // w9
  int v5; // w22
  int v6; // w23
  __int64 v7; // x0
  _DWORD *v8; // x24
  __int64 v9; // x21
  _DWORD *v10; // x8
  unsigned int v11; // w10
  _DWORD *v12; // x11
  __int64 v13; // x12
  int v14; // w13
  unsigned int v15; // w13
  unsigned int v16; // w19
  __int64 v17; // x25
  _DWORD *v18; // x26
  unsigned int v19; // w8
  __int64 v20; // x10
  __int64 v21; // x8
  unsigned int v22; // w9
  _DWORD *v23; // x11
  __int64 v24; // x10
  _DWORD *v25; // x11
  int v26; // w12
  unsigned int v27; // w12
  __int64 v28; // x8
  _DWORD *v29; // x8
  unsigned int v30; // w9
  __int64 v31; // x9
  _DWORD *v32; // x9
  int *v33; // x10
  unsigned __int64 v34; // x9
  _DWORD *v35; // x10
  int *v36; // x11
  int v37; // t1
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  if ( *(_BYTE *)(a2 + 492) )
    v4 = 24;
  else
    v4 = 4;
  v5 = 36 * *(_DWORD *)(a2 + 12) + 8 * *(_DWORD *)(a2 + 8) + 12 * *(_DWORD *)(a2 + 16) + v4 + 20 * *(_DWORD *)(a2 + 508);
  if ( *(_BYTE *)(a2 + 492) )
    v6 = 1179668;
  else
    v6 = 1179648;
  v7 = wmi_buf_alloc_fl(a1, v5 + 56, "send_roam_scan_filter_cmd_tlv", 0x207u);
  if ( !v7 )
    return 2;
  v8 = *(_DWORD **)(v7 + 224);
  v9 = v7;
  *v8 = 25493536;
  v8[1] = *(unsigned __int8 *)(a2 + 4);
  v8[2] = 0;
  v8[3] = *(_DWORD *)a2;
  v8[4] = *(_DWORD *)(a2 + 8);
  v8[5] = *(_DWORD *)(a2 + 12);
  v8[6] = *(_DWORD *)(a2 + 16);
  v8[7] = *(_DWORD *)(a2 + 508);
  v8[8] = *(_DWORD *)(a2 + 992);
  v8[9] = (8 * (*(_DWORD *)(a2 + 8) & 0x1FFF)) | 0x130000;
  v10 = v8 + 9;
  if ( *(_DWORD *)(a2 + 8) )
  {
    v11 = 0;
    v12 = v8 + 10;
    v13 = a2 + 20;
    do
    {
      ++v11;
      *v12 = *(_DWORD *)v13;
      v14 = *(unsigned __int16 *)(v13 + 4);
      v13 += 6;
      v12[1] = v14;
      v12 += 2;
      v15 = *(_DWORD *)(a2 + 8);
    }
    while ( v11 < v15 );
  }
  else
  {
    v15 = 0;
  }
  v17 = 2LL * v15;
  v10[v17 + 1] = (4 * ((9 * *(_DWORD *)(a2 + 12)) & 0x3FFF)) | 0x130000;
  v18 = &v10[v17 + 1];
  v19 = *(_DWORD *)(a2 + 12);
  if ( !v19 )
    goto LABEL_23;
  v7 = (__int64)qdf_mem_copy(v18 + 2, (const void *)(a2 + 117), *(unsigned __int8 *)(a2 + 116));
  v18[1] = *(unsigned __int8 *)(a2 + 116);
  v19 = *(_DWORD *)(a2 + 12);
  if ( v19 <= 1 )
    goto LABEL_23;
  v7 = (__int64)qdf_mem_copy(v18 + 11, (const void *)(a2 + 150), *(unsigned __int8 *)(a2 + 149));
  v18[10] = *(unsigned __int8 *)(a2 + 149);
  v19 = *(_DWORD *)(a2 + 12);
  if ( v19 < 3 )
    goto LABEL_23;
  v7 = (__int64)qdf_mem_copy(v18 + 20, (const void *)(a2 + 183), *(unsigned __int8 *)(a2 + 182));
  v18[19] = *(unsigned __int8 *)(a2 + 182);
  v19 = *(_DWORD *)(a2 + 12);
  if ( v19 < 4 )
    goto LABEL_23;
  v7 = (__int64)qdf_mem_copy(v18 + 29, (const void *)(a2 + 216), *(unsigned __int8 *)(a2 + 215));
  v18[28] = *(unsigned __int8 *)(a2 + 215);
  v19 = *(_DWORD *)(a2 + 12);
  if ( v19 < 5 )
    goto LABEL_23;
  v7 = (__int64)qdf_mem_copy(v18 + 38, (const void *)(a2 + 249), *(unsigned __int8 *)(a2 + 248));
  v18[37] = *(unsigned __int8 *)(a2 + 248);
  v19 = *(_DWORD *)(a2 + 12);
  if ( v19 < 6 )
    goto LABEL_23;
  v7 = (__int64)qdf_mem_copy(v18 + 47, (const void *)(a2 + 282), *(unsigned __int8 *)(a2 + 281));
  v18[46] = *(unsigned __int8 *)(a2 + 281);
  v19 = *(_DWORD *)(a2 + 12);
  if ( v19 < 7
    || (v7 = (__int64)qdf_mem_copy(v18 + 56, (const void *)(a2 + 315), *(unsigned __int8 *)(a2 + 314)),
        v18[55] = *(unsigned __int8 *)(a2 + 314),
        v19 = *(_DWORD *)(a2 + 12),
        v19 < 8)
    || (v7 = (__int64)qdf_mem_copy(v18 + 65, (const void *)(a2 + 348), *(unsigned __int8 *)(a2 + 347)),
        v18[64] = *(unsigned __int8 *)(a2 + 347),
        v19 = *(_DWORD *)(a2 + 12),
        v19 <= 8) )
  {
LABEL_23:
    v20 = 9 * v19;
    v18[v20 + 1] = (8 * (*(_DWORD *)(a2 + 16) & 0x1FFF)) | 0x130000;
    v21 = (__int64)&v18[v20 + 1];
    if ( *(_DWORD *)(a2 + 16) )
    {
      v22 = 0;
      v23 = &v8[v20 + v17];
      v24 = a2 + 380;
      v25 = v23 + 13;
      do
      {
        ++v22;
        *(v25 - 1) = *(_DWORD *)v24;
        v26 = *(unsigned __int16 *)(v24 + 4);
        v24 += 6;
        *v25 = v26;
        v25 += 2;
        v27 = *(_DWORD *)(a2 + 16);
      }
      while ( v22 < v27 );
    }
    else
    {
      v27 = 0;
    }
    v28 = v21 + 8LL * v27;
    *(_DWORD *)(v28 + 4) = (4 * (v27 & 0x3FFF)) | 0x100000;
    v29 = (_DWORD *)(v28 + 4);
    if ( !*(_DWORD *)(a2 + 16) )
    {
      v31 = 0;
      goto LABEL_47;
    }
    v29[1] = *(unsigned __int8 *)(a2 + 476);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 2 )
      goto LABEL_45;
    v29[2] = *(unsigned __int8 *)(a2 + 477);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 3 )
      goto LABEL_45;
    v29[3] = *(unsigned __int8 *)(a2 + 478);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 4 )
      goto LABEL_45;
    v29[4] = *(unsigned __int8 *)(a2 + 479);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 5 )
      goto LABEL_45;
    v29[5] = *(unsigned __int8 *)(a2 + 480);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 6 )
      goto LABEL_45;
    v29[6] = *(unsigned __int8 *)(a2 + 481);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 7 )
      goto LABEL_45;
    v29[7] = *(unsigned __int8 *)(a2 + 482);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 8 )
      goto LABEL_45;
    v29[8] = *(unsigned __int8 *)(a2 + 483);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 9 )
      goto LABEL_45;
    v29[9] = *(unsigned __int8 *)(a2 + 484);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 0xA )
      goto LABEL_45;
    v29[10] = *(unsigned __int8 *)(a2 + 485);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 0xB )
      goto LABEL_45;
    v29[11] = *(unsigned __int8 *)(a2 + 486);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 0xC )
      goto LABEL_45;
    v29[12] = *(unsigned __int8 *)(a2 + 487);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 0xD )
      goto LABEL_45;
    v29[13] = *(unsigned __int8 *)(a2 + 488);
    v30 = *(_DWORD *)(a2 + 16);
    if ( v30 < 0xE
      || (v29[14] = *(unsigned __int8 *)(a2 + 489), v30 = *(_DWORD *)(a2 + 16), v30 < 0xF)
      || (v29[15] = *(unsigned __int8 *)(a2 + 490), v30 = *(_DWORD *)(a2 + 16), v30 < 0x10)
      || (v29[16] = *(unsigned __int8 *)(a2 + 491), v30 = *(_DWORD *)(a2 + 16), v30 <= 0x10) )
    {
LABEL_45:
      v31 = v30;
LABEL_47:
      v32 = &v29[v31];
      v32[1] = v6;
      if ( *(_BYTE *)(a2 + 492) )
      {
        v32[2] = 43515920;
        v32[3] = *(_DWORD *)(a2 + 496);
        v32[4] = *(_DWORD *)(a2 + 500);
        v32[5] = *(_DWORD *)(a2 + 504);
        v32[6] = 129;
        v33 = v32 + 7;
      }
      else
      {
        v33 = v32 + 2;
      }
      *v33 = (4 * ((5 * (unsigned __int16)*(_DWORD *)(a2 + 508)) & 0x3FFF)) | 0x120000;
      if ( *(_DWORD *)(a2 + 508) )
      {
        v34 = 0;
        v35 = v33 + 1;
        v36 = (int *)(a2 + 528);
        do
        {
          *v35 = 43646992;
          if ( v34 == 10 )
            goto LABEL_57;
          ++v34;
          v35[1] = *(v36 - 4);
          v35[2] = *((unsigned __int16 *)v36 - 6);
          v35[3] = *(v36 - 1);
          v37 = *v36;
          v36 += 12;
          v35[4] = v37;
          v35 += 5;
        }
        while ( v34 < *(unsigned int *)(a2 + 508) );
      }
      wmi_mtrace(0xB00Bu, 0xFFu, 0);
      v16 = wmi_unified_cmd_send_fl(
              a1,
              v9,
              v5 + 56,
              0xB00Bu,
              "send_roam_scan_filter_cmd_tlv",
              0x27Cu,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45);
      if ( v16 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: cmd WMI_ROAM_FILTER_CMDID returned Error %d",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "send_roam_scan_filter_cmd_tlv",
          v16);
        wmi_buf_free();
      }
      return v16;
    }
  }
LABEL_57:
  __break(0x5512u);
  return send_roam_scan_offload_mode_cmd_tlv(v7);
}
