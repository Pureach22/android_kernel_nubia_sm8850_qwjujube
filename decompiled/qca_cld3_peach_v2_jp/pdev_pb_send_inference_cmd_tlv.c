__int64 __fastcall pdev_pb_send_inference_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  unsigned int v9; // w8
  unsigned int v10; // w9
  unsigned int v11; // w10
  unsigned int v12; // w11
  unsigned int v13; // w12
  unsigned int v14; // w13
  unsigned int v15; // w14
  unsigned int v16; // w15
  unsigned int v17; // w16
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w20
  unsigned int v44; // [xsp+0h] [xbp-50h]
  unsigned int v45; // [xsp+8h] [xbp-48h]
  unsigned int v46; // [xsp+10h] [xbp-40h]
  unsigned int v47; // [xsp+18h] [xbp-38h]
  unsigned int v48; // [xsp+20h] [xbp-30h]
  unsigned int v49; // [xsp+28h] [xbp-28h]
  unsigned int v50; // [xsp+30h] [xbp-20h]
  unsigned int v51; // [xsp+38h] [xbp-18h]
  unsigned int v52; // [xsp+40h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x38u, "pdev_pb_send_inference_cmd_tlv", 0x5BCEu);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 82378804;
  v7 = a2[4];
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *((_DWORD *)v8 - 1) != -2112860426 )
    __break(0x8228u);
  v5[1] = v8(a1, v7);
  v5[2] = a2[5];
  v5[3] = a2[6];
  v9 = a2[7];
  v5[4] = v9;
  v10 = a2[8];
  v5[5] = v10;
  v11 = a2[9];
  v5[6] = v11;
  v12 = a2[10];
  v5[7] = v12;
  v13 = a2[11];
  v5[8] = v13;
  v14 = a2[12];
  v5[9] = v14;
  v15 = a2[13];
  v5[10] = v15;
  v16 = a2[16];
  v5[11] = v16;
  v17 = a2[17];
  v5[12] = v17;
  v5[13] = a2[14];
  v52 = v17;
  v51 = v16;
  v50 = v15;
  v49 = v14;
  v48 = v13;
  v47 = v12;
  v46 = v11;
  v45 = v10;
  v44 = v9;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: TPB: WMI CMD Params req_id: %u pdev_id: %d status: %d inference_stage: %d mcs: %d bw: %d temperature_degreeC: %d"
    " primary_chan_mhz: %d center_freq1: %d center_freq2: %d phy_mode: %d tx_evm: %d tx_mask_margin: %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "pdev_pb_send_inference_cmd_tlv",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x38u,
             0x4056u,
             "pdev_pb_send_inference_cmd_tlv",
             0x5BF3u,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33);
  if ( (_DWORD)result )
  {
    v43 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: TPB: Failed to send PB Inference cmd WMI",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "pdev_pb_send_inference_cmd_tlv");
    wmi_buf_free();
    return v43;
  }
  return result;
}
