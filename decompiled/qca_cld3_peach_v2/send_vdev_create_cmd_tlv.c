__int64 __fastcall send_vdev_create_cmd_tlv(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  int mlo_params_size; // w0
  int v7; // w8
  int v8; // w23
  __int64 v9; // x20
  __int64 result; // x0
  _DWORD *v11; // x24
  int v12; // w8
  int v13; // w9
  int v14; // w8
  __int64 v15; // x1
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x6
  __int64 v27; // x7
  int v28; // w8
  int v29; // w9
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w10
  int v39; // w8
  _DWORD *add_mlo_params; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w4
  int v50; // w8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w19

  mlo_params_size = vdev_create_mlo_params_size(a3);
  if ( (unsigned int)(*((_DWORD *)a3 + 8) - 1) >= 2 )
    v7 = 0;
  else
    v7 = 12;
  v8 = mlo_params_size + v7;
  v9 = wmi_buf_alloc_fl(a1, mlo_params_size + v7 + 84, "send_vdev_create_cmd_tlv", 0x461u);
  result = 2;
  if ( v9 )
  {
    v11 = *(_DWORD **)(v9 + 224);
    *v11 = 5636140;
    v11[1] = *a3;
    v11[2] = *((_DWORD *)a3 + 1);
    v11[3] = *((_DWORD *)a3 + 2);
    v12 = *((_DWORD *)a3 + 5);
    v11[8] = v12;
    if ( a3[25] )
      v13 = 16;
    else
      v13 = 0;
    v11[8] = v13 | v12;
    v14 = a3[24];
    v11[6] = 2;
    v11[9] = v14;
    v15 = *((unsigned int *)a3 + 4);
    v16 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
    if ( *((_DWORD *)v16 - 1) != -2112860426 )
      __break(0x8228u);
    v17 = v16(a1, v15);
    v11[7] = v17;
    v11[4] = *(_DWORD *)a2;
    v11[5] = *((unsigned __int16 *)a2 + 2);
    if ( a2 )
    {
      v26 = *a2;
      v27 = a2[1];
      v28 = a2[2];
      v29 = a2[5];
    }
    else
    {
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v29 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: ID = %d[pdev:%d] VAP Addr = %02x:%02x:%02x:**:**:%02x",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_vdev_create_cmd_tlv",
      *a3,
      v17,
      v26,
      v27,
      v28,
      v29);
    v11[12] = 1179680;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: type %d, subtype %d, nss_2g %d, nss_5g %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "send_vdev_create_cmd_tlv",
      *((unsigned int *)a3 + 1),
      *((unsigned int *)a3 + 2),
      a3[12],
      a3[13]);
    v11[14] = 0;
    v11[15] = a3[12];
    v38 = a3[12];
    v11[13] = 26935308;
    v11[18] = 1;
    v11[16] = v38;
    v11[19] = a3[13];
    v39 = a3[13];
    v11[17] = 26935308;
    v11[20] = v39;
    add_mlo_params = (_DWORD *)vdev_create_add_mlo_params(v11 + 21, a3);
    v49 = *((_DWORD *)a3 + 8);
    if ( v49 == 1 )
    {
      v50 = 0;
    }
    else
    {
      if ( v49 != 2 )
      {
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: TLV not required for P2P mode %d",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "wmi_vdev_add_p2p_mode_tlv");
LABEL_19:
        qdf_mtrace(49, 100, 0x281u, v11[1], 0);
        result = wmi_unified_cmd_send_fl(
                   a1,
                   v9,
                   v8 + 84,
                   0x5001u,
                   "send_vdev_create_cmd_tlv",
                   0x498u,
                   v51,
                   v52,
                   v53,
                   v54,
                   v55,
                   v56,
                   v57,
                   v58);
        if ( (_DWORD)result )
        {
          v67 = result;
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: Failed to send WMI_VDEV_CREATE_CMDID",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "send_vdev_create_cmd_tlv");
          wmi_buf_free();
          return v67;
        }
        return result;
      }
      v50 = 1;
    }
    add_mlo_params[2] = v50;
    *add_mlo_params = 1179656;
    add_mlo_params[1] = 82247684;
    goto LABEL_19;
  }
  return result;
}
