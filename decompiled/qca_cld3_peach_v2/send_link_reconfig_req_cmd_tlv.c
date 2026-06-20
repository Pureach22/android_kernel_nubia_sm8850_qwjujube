__int64 __fastcall send_link_reconfig_req_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v4; // w25
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x22
  __int64 v15; // x19
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  int *v26; // x26
  unsigned int v27; // w22
  __int64 v28; // x27
  __int64 v29; // x6
  __int64 v30; // x7
  unsigned __int8 *v31; // x8
  int v32; // w9
  unsigned __int8 *v33; // x9
  __int64 v34; // x5
  __int64 result; // x0
  __int64 v36; // x22
  _DWORD *v37; // x26
  unsigned __int8 *v38; // x27
  __int64 v39; // x6
  __int64 v40; // x7
  int v41; // w8
  int v42; // w9
  __int64 v43; // x5
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // [xsp+0h] [xbp-10h]
  __int64 v61; // [xsp+8h] [xbp-8h]

  v4 = 20 * *((_DWORD *)a2 + 32) + 16 * *((_DWORD *)a2 + 63) + 24;
  v5 = wmi_buf_alloc_fl(a1, (unsigned __int8)v4 & 0xFC, "send_link_reconfig_req_cmd_tlv", 0x888u);
  if ( !v5 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "send_link_reconfig_req_cmd_tlv");
    return 16;
  }
  v14 = *(_DWORD **)(v5 + 224);
  v15 = v5;
  *v14 = 82968588;
  v14[1] = *a2;
  v14[2] = *(_DWORD *)(a2 + 1);
  v14[3] = *(unsigned __int16 *)(a2 + 5);
  v16 = qdf_trace_msg(
          0x31u,
          8u,
          "%s: mld add %02x:%02x:%02x:**:**:%02x",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "send_link_reconfig_req_cmd_tlv",
          a2[1],
          a2[2],
          a2[3],
          a2[6]);
  v25 = *((_DWORD *)a2 + 32);
  if ( v25 )
  {
    v26 = v14 + 5;
    v14[4] = (4 * ((5 * (_WORD)v25) & 0x3FFF)) | 0x120000;
    if ( *((_DWORD *)a2 + 32) )
    {
      v27 = 0;
      v28 = 0;
      do
      {
        *v26 = 83099664;
        if ( v28 == 120 )
          goto LABEL_24;
        v33 = &a2[v28];
        v34 = a2[v28 + 7];
        v26[1] = v34;
        v26[4] = a2[v28 + 8];
        v31 = &a2[v28 + 9];
        v26[2] = *(_DWORD *)v31;
        v26[3] = *(unsigned __int16 *)&a2[v28 + 13];
        if ( &a2[v28] == (unsigned __int8 *)-9LL )
        {
          v29 = 0;
          v30 = 0;
          v32 = 0;
        }
        else
        {
          v29 = *v31;
          v30 = v33[10];
          LODWORD(v31) = v33[11];
          v32 = v33[14];
        }
        LODWORD(v61) = v32;
        LODWORD(v60) = (_DWORD)v31;
        v16 = qdf_trace_msg(
                0x31u,
                8u,
                "%s: add link[%d] with param link_id: %d %02x:%02x:%02x:**:**:%02x",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "send_link_reconfig_req_cmd_tlv",
                v27++,
                v34,
                v29,
                v30,
                v60,
                v61);
        v26 += 5;
        v28 += 8;
      }
      while ( *((_DWORD *)a2 + 32) > v27 );
    }
  }
  else
  {
    v26 = v14 + 5;
    v14[4] = 1179648;
  }
  if ( *((_DWORD *)a2 + 63) )
  {
    *v26 = (16 * (*((_DWORD *)a2 + 63) & 0xFFF)) | 0x120000;
    if ( *((_DWORD *)a2 + 63) )
    {
      v36 = 0;
      v37 = v26 + 1;
      v38 = a2 + 139;
      while ( 1 )
      {
        *v37 = 83165196;
        if ( v36 == 15 )
          break;
        v43 = *(v38 - 7);
        v37[1] = v43;
        v41 = (_DWORD)v38 - 5;
        v37[2] = *(_DWORD *)(v38 - 5);
        v37[3] = *(unsigned __int16 *)(v38 - 1);
        if ( v38 == (_BYTE *)&off_0 + 5 )
        {
          v39 = 0;
          v40 = 0;
          v42 = 0;
        }
        else
        {
          v39 = *(v38 - 5);
          v40 = *(v38 - 4);
          v41 = *(v38 - 3);
          v42 = *v38;
        }
        LODWORD(v61) = v42;
        LODWORD(v60) = v41;
        v16 = qdf_trace_msg(
                0x31u,
                8u,
                "%s: del link[%d] with param link_id: %d %02x:%02x:%02x:**:**:%02x",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "send_link_reconfig_req_cmd_tlv",
                (unsigned int)v36++,
                v43,
                v39,
                v40,
                v60,
                v61);
        v38 += 8;
        v37 += 4;
        if ( *((_DWORD *)a2 + 63) <= (unsigned int)v36 )
          goto LABEL_21;
      }
LABEL_24:
      __break(0x5512u);
      return send_mlo_ttlm_complete_cmd_tlv(v16);
    }
  }
  else
  {
    *v26 = 1179648;
  }
LABEL_21:
  wmi_mtrace(0x4800Du, 0, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v15,
             (unsigned __int8)v4 & 0xFC,
             0x4800Du,
             "send_link_reconfig_req_cmd_tlv",
             0x8E3u,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50,
             v51);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send link reconfig command ret = %d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "send_link_reconfig_req_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 0;
  }
  return result;
}
