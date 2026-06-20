__int64 __fastcall send_pdev_utf_cmd_tlv(
        __int64 a1,
        char **a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  char *v12; // x23
  unsigned __int8 v14; // w20
  __int16 v15; // w9
  __int64 v16; // x28
  char v17; // w0
  int v18; // w25
  char v19; // w19
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w25
  unsigned int v30; // w26
  __int64 v31; // x27
  _DWORD *v32; // x22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _DWORD *v41; // x25
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char *v50; // x19
  _DWORD *v51; // x8
  unsigned int v52; // w0
  __int64 v53; // x4
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w0
  __int64 result; // x0
  unsigned int v64; // w19
  int v67; // [xsp+14h] [xbp-1Ch]
  unsigned __int8 v68; // [xsp+18h] [xbp-18h]
  unsigned int v69; // [xsp+1Ch] [xbp-14h]
  int v70; // [xsp+24h] [xbp-Ch]

  v11 = *((_DWORD *)a2 + 2);
  if ( v11 )
  {
    v12 = *a2;
    v14 = 0;
    v69 = (unsigned __int16)*((_DWORD *)a2 + 2);
    v15 = (unsigned __int16)v11 / 0xFCu;
    if ( -252 * (unsigned __int8)((unsigned __int16)v11 / 0xFCu) + v11 )
      LOBYTE(v15) = v15 + 1;
    v68 = v15;
    v67 = 16 * (v15 & 0xF);
    while ( 1 )
    {
      if ( v11 >= 0xFC )
        v16 = 252;
      else
        v16 = v11;
      v17 = is_service_enabled_tlv(a1, 0x18Au, a4, a5, a6, a7, a8, a9, a10, a11);
      if ( (v17 & 1) != 0 )
        v18 = 28;
      else
        v18 = 20;
      v19 = v17;
      v20 = wmi_buf_alloc_fl(a1, v18 + (int)v16, "send_pdev_utf_cmd_tlv", 0xA50u);
      if ( !v20 )
        return 2;
      v70 = v18;
      v29 = (unsigned __int8)send_pdev_utf_cmd_tlv_msgref;
      v30 = v14 & 0xF | v67;
      v31 = v20;
      v32 = *(_DWORD **)(v20 + 224);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: segHdrInfo.len = %u, segHdrInfo.msgref = %u, segHdrInfo.segmentInfo = %u",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "send_pdev_utf_cmd_tlv",
        v69,
        (unsigned __int8)send_pdev_utf_cmd_tlv_msgref,
        v30);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: total_bytes %u segNumber %u totalSegments %u chunk len %u",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "send_pdev_utf_cmd_tlv",
        v69,
        v14,
        v68,
        (unsigned int)v16);
      v32[2] = v29;
      v32[3] = v30;
      v41 = v32 + 5;
      v32[4] = 0;
      *v32 = v16 + 1114128;
      v32[1] = v69;
      qdf_mem_copy(v32 + 5, v12, (unsigned int)v16);
      if ( (v19 & 1) != 0 )
      {
        v50 = (char *)v41 + v16;
        *(_DWORD *)((char *)v41 + v16) = 79560708;
        v51 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3704LL);
        if ( v51 )
        {
          if ( *(v51 - 1) != -2112860426 )
            __break(0x8228u);
          v52 = ((__int64 (__fastcall *)(__int64, _QWORD))v51)(a1, a3);
          v53 = v52;
          *((_DWORD *)v50 + 1) = v52;
        }
        else
        {
          v53 = *((unsigned int *)v50 + 1);
        }
        qdf_trace_msg(0x31u, 8u, "%s: pdev_id %u", v42, v43, v44, v45, v46, v47, v48, v49, "send_pdev_utf_cmd_tlv", v53);
      }
      qdf_mtrace(49, 100, 0xE82u, 0xFFu, 0);
      v62 = wmi_unified_cmd_send_fl(
              a1,
              v31,
              v70 + (int)v16,
              0x1D002u,
              "send_pdev_utf_cmd_tlv",
              0xA7Eu,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61);
      if ( v62 )
        break;
      v12 += v16;
      ++v14;
      v11 = *((_DWORD *)a2 + 2) - v16;
      *((_DWORD *)a2 + 2) = v11;
      if ( !v11 )
      {
        result = 0;
        goto LABEL_25;
      }
    }
    v64 = v62;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_PDEV_UTF_CMDID command",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "send_pdev_utf_cmd_tlv");
    wmi_buf_free();
    result = v64;
  }
  else
  {
    result = 4;
  }
LABEL_25:
  ++send_pdev_utf_cmd_tlv_msgref;
  return result;
}
