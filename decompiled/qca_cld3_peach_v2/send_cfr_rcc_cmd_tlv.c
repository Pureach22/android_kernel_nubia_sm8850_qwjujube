__int64 __fastcall send_cfr_rcc_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x24
  unsigned int v4; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  __int64 v16; // x20
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  __int64 v18; // x1
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w8
  int v29; // w10
  int v30; // w8
  int v31; // w9
  unsigned int v32; // w8
  int v33; // w9
  int v34; // w10
  int v35; // w11
  int v36; // w8
  unsigned int v37; // w9
  int v38; // w10
  int v39; // w9
  unsigned int v40; // w9
  unsigned int v41; // w9
  unsigned int v42; // w8
  unsigned int v43; // w8
  unsigned int v44; // w8
  unsigned int v45; // w8
  unsigned int v46; // w8
  __int64 v47; // x8
  int v48; // w9
  _DWORD *v49; // x10
  int v50; // w14
  unsigned int v51; // w14
  unsigned int v52; // w14
  unsigned int v53; // w14
  unsigned int v54; // w14
  unsigned int v55; // w14
  unsigned int v56; // w14
  unsigned int v57; // w14
  unsigned int v58; // w14
  int v59; // w14
  unsigned int v60; // w14
  unsigned int v61; // w19

  v3 = *(_QWORD *)(a1 + 728);
  v4 = 60 * a2[25] + 44;
  v6 = wmi_buf_alloc_fl(a1, v4, "send_cfr_rcc_cmd_tlv", 0xA2u);
  if ( v6 )
  {
    v15 = *(_QWORD *)(v6 + 224);
    v16 = v6;
    *(_DWORD *)v15 = 54657060;
    v17 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 3720);
    v18 = *a2;
    if ( *((_DWORD *)v17 - 1) != -2112860426 )
      __break(0x8228u);
    v19 = v17(a1, v18);
    v28 = *(unsigned __int8 *)(v15 + 15);
    *(_DWORD *)(v15 + 4) = v19;
    v29 = *(unsigned __int8 *)(v15 + 19);
    v28 <<= 24;
    *(_DWORD *)(v15 + 12) = v28;
    *(_DWORD *)(v15 + 12) = v28 & 0xFF000000 | *((_DWORD *)a2 + 2) & 0xFFFFFF;
    *(_DWORD *)(v15 + 16) = v29 << 24;
    v30 = *(_DWORD *)(v15 + 36);
    v31 = (v29 << 24) | *((_DWORD *)a2 + 1) & 0xFFFFFF;
    *(_DWORD *)(v15 + 36) = v30 & 0xFFFF0000;
    *(_DWORD *)(v15 + 16) = v31;
    v32 = *((unsigned __int16 *)a2 + 300) | v30 & 0xFFFE0000;
    v33 = *(unsigned __int16 *)(v15 + 22);
    *(_DWORD *)(v15 + 36) = v32;
    v34 = *((_DWORD *)a2 + 150) & 0x10000;
    *(_DWORD *)(v15 + 20) = v33 << 16;
    *(_DWORD *)(v15 + 36) = v34 | v32;
    v35 = *(_DWORD *)(v15 + 32);
    v36 = *((unsigned __int16 *)a2 + 11) | ((unsigned __int16)v33 << 16);
    v37 = *(_DWORD *)(v15 + 28) & 0xFFFFFFE0;
    *(_DWORD *)(v15 + 20) = v36;
    *(_DWORD *)(v15 + 28) = v37;
    *(_DWORD *)(v15 + 28) = v37 | *((_DWORD *)a2 + 4) & 0x1F;
    v38 = *(_DWORD *)(v15 + 8);
    v39 = *((_DWORD *)a2 + 3);
    *(_DWORD *)(v15 + 32) = v35 & 0xFFFFFFFE;
    *(_DWORD *)(v15 + 24) = v39;
    v40 = v35 & 0xFFFFFE00 | *((_WORD *)a2 + 10) & 1;
    *(_DWORD *)(v15 + 32) = v40;
    *(_DWORD *)(v15 + 32) = v40 | *((_WORD *)a2 + 10) & 0x1FE;
    *(_DWORD *)(v15 + 8) = v38 & 0xFFFFFFFE;
    v41 = v38 & 0xFFFFFFFC | a2[24] & 1;
    *(_DWORD *)(v15 + 8) = v41;
    v42 = v41 & 0xFFFFFFF9 | a2[24] & 2;
    *(_DWORD *)(v15 + 8) = v42;
    v43 = v42 & 0xFFFFFFF3 | a2[24] & 4;
    *(_DWORD *)(v15 + 8) = v43;
    v44 = v43 & 0xFFFFFFE7 | a2[24] & 8;
    *(_DWORD *)(v15 + 8) = v44;
    v45 = v44 & 0xFFFFFFBF | a2[24] & 0x10;
    *(_DWORD *)(v15 + 8) = v45;
    v46 = v45 & 0xFFFFFF9F | a2[24] & 0x40;
    *(_DWORD *)(v15 + 8) = v46;
    *(_DWORD *)(v15 + 8) = v46 | a2[24] & 0x20;
    *(_DWORD *)(v15 + 40) = (60 * a2[25]) | 0x120000;
    if ( a2[25] )
    {
      v47 = 0;
      v48 = 0;
      v49 = (_DWORD *)(v15 + 44);
      do
      {
        if ( ((*((_QWORD *)a2 + 74) >> v48) & 1) != 0 )
        {
          v50 = v49[2];
          *v49 = 54722616;
          v49[1] = v48;
          v49[2] = v50 & 0xFFFFFFFE;
          v51 = v50 & 0xFFFFFFFC | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 1;
          v49[2] = v51;
          v52 = v51 & 0xFFFFFFF9 | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 2;
          v49[2] = v52;
          v53 = v52 & 0xFFFFFFF3 | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 4;
          v49[2] = v53;
          v54 = v53 & 0xFFFFFFE7 | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 8;
          v49[2] = v54;
          v55 = v54 & 0xFFFFFFCF | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 0x10;
          v49[2] = v55;
          v56 = v55 & 0xFFFFFF9F | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 0x20;
          v49[2] = v56;
          v57 = v56 & 0xFFFFFF3F | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 0x40;
          v49[2] = v57;
          v58 = v57 & 0xFFFFFE7F | HIWORD(*(_DWORD *)&a2[v47 + 27]) & 0x80;
          v49[2] = v58;
          v49[2] = HIWORD(*(_DWORD *)&a2[v47 + 27]) & 0x100 | v58;
          v49[3] = *(_DWORD *)&a2[v47 + 37];
          v49[4] = *(unsigned __int16 *)&a2[v47 + 41];
          v49[5] = *(_DWORD *)&a2[v47 + 49];
          v49[6] = *(unsigned __int16 *)&a2[v47 + 53];
          v49[7] = *(_DWORD *)&a2[v47 + 43];
          v49[8] = *(unsigned __int16 *)&a2[v47 + 47];
          v49[9] = *(_DWORD *)&a2[v47 + 55];
          v59 = v49[11];
          v49[10] = *(unsigned __int16 *)&a2[v47 + 59];
          v49[11] = v59 & 0xFFFFFFC0;
          v60 = v59 & 0xFF00FFC0 | *(_DWORD *)&a2[v47 + 27] & 0x3F;
          v49[11] = v60;
          v49[11] = v60 & 0xFF00FFFF | ((unsigned __int8)(*(_DWORD *)&a2[v47 + 27] >> 6) << 16);
          v49[12] = *(unsigned __int16 *)&a2[v47 + 31];
          v49[13] = *(unsigned __int16 *)&a2[v47 + 33];
          v49[14] = *(unsigned __int16 *)&a2[v47 + 35];
          v49 += 15;
        }
        v47 += 35;
        ++v48;
      }
      while ( v47 != 560 );
    }
    v61 = wmi_unified_cmd_send_fl(
            a1,
            v16,
            v4,
            0x44001u,
            "send_cfr_rcc_cmd_tlv",
            0xE4u,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27);
    if ( v61 )
      wmi_buf_free();
  }
  else
  {
    v61 = 2;
    qdf_trace_msg(0x31u, 2u, "%s: wmi_buf_alloc failed", v7, v8, v9, v10, v11, v12, v13, v14, "send_cfr_rcc_cmd_tlv");
  }
  return v61;
}
