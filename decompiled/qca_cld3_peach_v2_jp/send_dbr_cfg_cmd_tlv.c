__int64 __fastcall send_dbr_cfg_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  __int64 v14; // x19
  __int64 v15; // x1
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  unsigned int v17; // w0
  unsigned int v18; // w8
  unsigned int v19; // w9
  unsigned int v20; // w10
  unsigned int v21; // w11
  unsigned int v22; // w12
  unsigned int v23; // w13
  unsigned int v24; // w14
  unsigned int v25; // w15
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w20
  unsigned int v52; // [xsp+0h] [xbp-40h]
  unsigned int v53; // [xsp+8h] [xbp-38h]
  unsigned int v54; // [xsp+10h] [xbp-30h]
  unsigned int v55; // [xsp+18h] [xbp-28h]
  unsigned int v56; // [xsp+20h] [xbp-20h]
  unsigned int v57; // [xsp+28h] [xbp-18h]
  unsigned int v58; // [xsp+30h] [xbp-10h]
  unsigned int v59; // [xsp+38h] [xbp-8h]

  v4 = wmi_buf_alloc_fl(a1, 0x34u, "send_dbr_cfg_cmd_tlv", 0x29u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 46137392;
    v15 = *a2;
    v16 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3704LL);
    if ( *((_DWORD *)v16 - 1) != -2112860426 )
      __break(0x8228u);
    v17 = v16(a1, v15);
    v13[1] = v17;
    v13[2] = a2[1];
    v13[3] = a2[2];
    v13[4] = a2[3];
    v18 = a2[4];
    v13[5] = v18;
    v19 = a2[5];
    v13[6] = v19;
    v20 = a2[7];
    v13[7] = v20;
    v21 = a2[6];
    v13[8] = v21;
    v22 = a2[9];
    v13[9] = v22;
    v23 = a2[8];
    v13[10] = v23;
    v24 = a2[11];
    v13[11] = v24;
    v25 = a2[10];
    v13[12] = v25;
    v59 = v25;
    v58 = v24;
    v57 = v23;
    v56 = v22;
    v55 = v21;
    v54 = v20;
    v53 = v19;
    v52 = v18;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: wmi_dma_ring_cfg_req_fixed_param pdev id %d mod id %dbase paddr lo %x base paddr hi %x head idx paddr lo %xhea"
      "d idx paddr hi %x tail idx paddr lo %xtail idx addr hi %x num elems %d buf size %d num resp %devent timeout %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_dbr_cfg_cmd_tlv",
      v17,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59);
    wmi_mtrace(0x4034u, 0xFFu, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x34u,
               0x4034u,
               "send_dbr_cfg_cmd_tlv",
               0x50u,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41);
    if ( (_DWORD)result )
    {
      v51 = result;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: :wmi cmd send failed",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "send_dbr_cfg_cmd_tlv");
      wmi_buf_free();
      return v51;
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: wmi_buf_alloc failed", v5, v6, v7, v8, v9, v10, v11, v12, "send_dbr_cfg_cmd_tlv");
    return 16;
  }
  return result;
}
