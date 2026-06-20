__int64 __fastcall send_vdev_create_cmd_tlv(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  unsigned int v6; // w21
  __int64 v7; // x19
  __int64 result; // x0
  _DWORD *v9; // x24
  int v10; // w8
  int v11; // w9
  int v12; // w8
  __int64 v13; // x1
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x6
  __int64 v25; // x7
  int v26; // w8
  int v27; // w9
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  int v45; // w8
  int v46; // w4
  int v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w20

  if ( (unsigned int)(*((_DWORD *)a3 + 7) - 1) >= 2 )
    v6 = 88;
  else
    v6 = 100;
  v7 = wmi_buf_alloc_fl(a1, v6, "send_vdev_create_cmd_tlv", 0x461u);
  result = 2;
  if ( v7 )
  {
    v9 = *(_DWORD **)(v7 + 224);
    *v9 = 5636140;
    v9[1] = *a3;
    v9[2] = *((_DWORD *)a3 + 1);
    v9[3] = *((_DWORD *)a3 + 2);
    v10 = *((_DWORD *)a3 + 5);
    v9[8] = v10;
    if ( a3[25] )
      v11 = 16;
    else
      v11 = 0;
    v9[8] = v11 | v10;
    v12 = a3[24];
    v9[6] = 2;
    v9[9] = v12;
    v13 = *((unsigned int *)a3 + 4);
    v14 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
    if ( *((_DWORD *)v14 - 1) != -2112860426 )
      __break(0x8228u);
    v15 = v14(a1, v13);
    v9[7] = v15;
    v9[4] = *(_DWORD *)a2;
    v9[5] = *((unsigned __int16 *)a2 + 2);
    if ( a2 )
    {
      v24 = *a2;
      v25 = a2[1];
      v26 = a2[2];
      v27 = a2[5];
    }
    else
    {
      v26 = 0;
      v24 = 0;
      v25 = 0;
      v27 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: ID = %d[pdev:%d] VAP Addr = %02x:%02x:%02x:**:**:%02x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "send_vdev_create_cmd_tlv",
      *a3,
      v15,
      v24,
      v25,
      v26,
      v27);
    v9[12] = 1179680;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: type %d, subtype %d, nss_2g %d, nss_5g %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_vdev_create_cmd_tlv",
      *((unsigned int *)a3 + 1),
      *((unsigned int *)a3 + 2),
      a3[12],
      a3[13]);
    v9[14] = 0;
    v9[15] = a3[12];
    v44 = a3[12];
    v9[18] = 1;
    v9[13] = 26935308;
    v9[16] = v44;
    v9[19] = a3[13];
    v45 = a3[13];
    v9[17] = 26935308;
    v9[20] = v45;
    v9[21] = 1179648;
    v46 = *((_DWORD *)a3 + 7);
    if ( v46 == 1 )
    {
      v47 = 0;
    }
    else
    {
      if ( v46 != 2 )
      {
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: TLV not required for P2P mode %d",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "wmi_vdev_add_p2p_mode_tlv");
LABEL_19:
        qdf_mtrace(49, 100, 0x281u, v9[1], 0);
        result = wmi_unified_cmd_send_fl(
                   a1,
                   v7,
                   v6,
                   0x5001u,
                   "send_vdev_create_cmd_tlv",
                   0x498u,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   v53,
                   v54,
                   v55);
        if ( (_DWORD)result )
        {
          v64 = result;
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: Failed to send WMI_VDEV_CREATE_CMDID",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "send_vdev_create_cmd_tlv");
          wmi_buf_free();
          return v64;
        }
        return result;
      }
      v47 = 1;
    }
    v9[24] = v47;
    v9[22] = 1179656;
    v9[23] = 82247684;
    goto LABEL_19;
  }
  return result;
}
