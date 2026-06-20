__int64 __fastcall send_pno_start_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v2; // x25
  unsigned int v5; // w8
  int v6; // w20
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _DWORD *v16; // x26
  __int64 v17; // x27
  int v18; // w9
  int v19; // w9
  int v20; // w8
  unsigned int v21; // w8
  unsigned int v22; // w28
  unsigned int v23; // w19
  __int64 v24; // x20
  _DWORD *v25; // x22
  __int64 v26; // x24
  size_t v27; // x2
  int v28; // w8
  int v29; // w8
  int *v30; // x24
  _DWORD *v31; // x24
  __int64 v32; // x19
  _DWORD *v33; // x20
  int v34; // w9
  unsigned int v35; // w8
  __int64 v36; // x4
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int64 v45; // x20
  unsigned int v46; // w27
  _DWORD *v47; // x19
  int v48; // w0
  __int64 v49; // x23
  _DWORD *v50; // x19
  __int64 v51; // x9
  int v52; // w8
  __int64 result; // x0
  int v54; // w10
  _DWORD *v55; // x8
  __int64 v56; // x19
  int *v57; // x10
  _DWORD *v58; // x11
  int v59; // t1
  int v60; // w9
  _DWORD *v61; // x8
  int v62; // w12
  _DWORD *v63; // x12
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // [xsp+8h] [xbp-E8h]
  int v81; // [xsp+14h] [xbp-DCh]
  __int64 v82; // [xsp+18h] [xbp-D8h]
  _QWORD v83[26]; // [xsp+20h] [xbp-D0h] BYREF

  v2 = a2 + 20480;
  v83[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a2 + 8);
  if ( v5 >= 0x10 )
    v5 = 16;
  v6 = 76 * v5 + 4 * *(unsigned __int8 *)(a2 + 116) + 8 * *(_DWORD *)(a2 + 20600);
  v7 = wmi_buf_alloc_fl(a1, v6 + 224, "send_pno_start_cmd_tlv", 0x1C24u);
  if ( v7 )
  {
    v16 = *(_DWORD **)(v7 + 224);
    v17 = v7;
    *v16 = 9437308;
    v18 = *(_DWORD *)(a2 + 16);
    v16[1] = 66;
    v16[2] = v18;
    v19 = *(_DWORD *)(a2 + 60);
    v20 = ((v19 & 7) << 21) | 0x42;
    v16[1] = v20;
    v16[4] = *(_DWORD *)(a2 + 40);
    v16[5] = *(_DWORD *)(a2 + 44);
    if ( *(_BYTE *)(a2 + 12) == 1 )
    {
      v20 = ((v19 & 7) << 21) | 0x142;
      v16[1] = v20;
    }
    v16[10] = *(_DWORD *)(a2 + 20);
    v16[11] = *(_DWORD *)(a2 + 24);
    v16[14] = 1000 * *(_DWORD *)(a2 + 28);
    v16[3] = *(_DWORD *)(a2 + 32);
    v16[9] = *(unsigned __int8 *)(a2 + 36);
    if ( *(_BYTE *)(v2 + 68) == 1 )
    {
      v16[1] = v20 | 0xC00;
      v16[15] = *(_DWORD *)(v2 + 69);
      v16[16] = *(unsigned __int16 *)(v2 + 73);
      v16[17] = *(_DWORD *)(v2 + 75);
      v16[18] = *(unsigned __int16 *)(v2 + 79);
    }
    v21 = *(_DWORD *)(a2 + 8);
    v81 = v6;
    v82 = a1;
    if ( v21 >= 0x10 )
      v22 = 16;
    else
      v22 = *(_DWORD *)(a2 + 8);
    v16[12] = v22;
    v16[32] = (76 * v22) | 0x120000;
    if ( v21 )
    {
      v23 = 0;
      v24 = 0;
      v25 = v16 + 51;
      while ( 1 )
      {
        *(v25 - 18) = 1114184;
        *(v25 - 17) = 1;
        if ( v24 == 20480 )
          break;
        v26 = a2 + v24;
        v27 = *(unsigned __int8 *)(a2 + v24 + 68);
        *(v25 - 16) = v27;
        qdf_mem_copy(v25 - 15, (const void *)(a2 + v24 + 69), v27);
        v28 = *(_DWORD *)(a2 + v24 + 1344);
        if ( v28 && v28 >= -299 )
        {
          *(v25 - 3) = 1;
          *(v25 - 2) = *(_DWORD *)(v26 + 1344);
        }
        *(v25 - 1) = 1;
        ++v23;
        v24 += 1280;
        *v25 = *(_DWORD *)(v26 + 112);
        v25 += 19;
        v22 = v16[12];
        if ( v22 <= v23 )
          goto LABEL_18;
      }
LABEL_50:
      __break(0x5512u);
    }
LABEL_18:
    v29 = *(unsigned __int8 *)(a2 + 116);
    v30 = &v16[19 * v22 + 33];
    v16[13] = v29;
    *v30 = (4 * v29) | 0x100000;
    v31 = v30 + 1;
    if ( v29 )
    {
      v32 = 0;
      v33 = (_DWORD *)(a2 + 120);
      while ( v32 != 102 )
      {
        v35 = v31[v32] | *v33 & 0xFFFFF;
        v31[v32] = v35;
        if ( v35 <= 0x3E7 )
        {
          v35 = v31[v32] | wlan_chan_to_freq(*v33) & 0xFFFFF;
          v31[v32] = v35;
        }
        v34 = v33[2];
        v33 += 3;
        v31[v32++] = v35 | (v34 << 20);
        if ( v16[13] <= (unsigned int)v32 )
          goto LABEL_24;
      }
      goto LABEL_50;
    }
LABEL_24:
    v36 = *(unsigned __int8 *)(a2 + 116);
    v80 = v17;
    memset(v83, 0, 192);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: [PNO_SCAN] Total freq %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wmi_dump_pno_scan_freq_list",
      v36);
    if ( *(_BYTE *)(a2 + 116) )
    {
      v45 = 0;
      v46 = 0;
      v47 = (_DWORD *)(a2 + 128);
      do
      {
        if ( v45 == 103 )
          goto LABEL_50;
        v37 = scnprintf((char *)v83 + v46, 192LL - v46, " %d[%d]", *(v47 - 2), *v47);
        if ( v48 < 1 )
          break;
        v46 += v48;
        if ( v46 >= 0xAC )
        {
          qdf_trace_msg(0x31u, 8u, "Freq[flag]:%s", v37, v38, v39, v40, v41, v42, v43, v44, v83);
          v46 = 0;
        }
        ++v45;
        v47 += 3;
      }
      while ( v45 < *(unsigned __int8 *)(a2 + 116) );
      if ( v46 )
        qdf_trace_msg(0x31u, 8u, "Freq[flag]:%s", v37, v38, v39, v40, v41, v42, v43, v44, v83);
    }
    v49 = (unsigned int)v16[13];
    v50 = &v31[v49];
    *v50 = 1179668;
    v50[1] = 1114128;
    v50[2] = *(_DWORD *)(a2 + 48);
    v50[3] = *(_DWORD *)(a2 + 52);
    v50[4] = *(_DWORD *)(a2 + 56);
    v50[5] = *(_DWORD *)(a2 + 64);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: enable: %d, top_k_num: %d, stat_thresh: %d, full_scan: %d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wmi_set_pno_channel_prediction");
    v50[6] = 29687836;
    if ( (*(_BYTE *)(v2 + 84) & 1) != 0 )
    {
      v16[1] |= 0x1000u;
      v16[19] = *(_DWORD *)(v2 + 88);
      v16[20] = *(_DWORD *)(v2 + 92);
      v16[21] = *(_DWORD *)(v2 + 96);
      v16[22] = *(_DWORD *)(v2 + 100);
      v16[23] = *(_DWORD *)(v2 + 104);
      v16[24] = *(_DWORD *)(v2 + 108);
      v16[25] = *(_DWORD *)(v2 + 112);
      v16[26] = *(_DWORD *)(v2 + 116);
      LODWORD(v51) = *(_DWORD *)(v2 + 120);
      LOWORD(v52) = v51;
      v16[27] = v51;
    }
    else
    {
      v52 = *(_DWORD *)(v2 + 120);
      LODWORD(v51) = v16[27];
    }
    v54 = (8 * (v52 & 0x1FFF)) | 0x120000;
    v55 = v50 + 15;
    v50[14] = v54;
    if ( (_DWORD)v51 )
    {
      v56 = v82;
      v51 = (unsigned int)v51;
      v57 = (int *)(v2 + 124);
      v58 = &v16[19 * v22 + 50 + v49];
      do
      {
        *(v58 - 1) = 39256068;
        --v51;
        v59 = *v57++;
        *v58 = v59;
        v58 += 2;
      }
      while ( v51 );
      v55 += 2 * (unsigned int)v16[27];
    }
    else
    {
      v56 = v82;
    }
    if ( *(_BYTE *)(v2 + 188) == 1 )
      v16[1] |= 0x2000u;
    *v55 = 39714824;
    v55[1] = *(char *)(v2 + 189);
    v16[28] = 1;
    v55[3] = 1179660;
    if ( v16[28] )
    {
      v60 = 0;
      v61 = v55 + 4;
      do
      {
        v62 = (unsigned __int8)v60++;
        v63 = &v61[3 * v62];
        *v63 = 40697864;
        v63[1] = *(char *)(v2 + 190);
        v63[2] = *(char *)(v2 + 191);
      }
      while ( v16[28] > (unsigned int)(unsigned __int8)v60 );
    }
    qdf_mtrace(49, 100, 0xC01u, v16[2], 0);
    result = wmi_unified_cmd_send_fl(
               v56,
               v80,
               v81 + 224,
               0x18001u,
               "send_pno_start_cmd_tlv",
               0x1CCEu,
               v64,
               v65,
               v66,
               v67,
               v68,
               v69,
               v70,
               v71);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send nlo wmi cmd",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "send_pno_start_cmd_tlv");
      wmi_buf_free();
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
