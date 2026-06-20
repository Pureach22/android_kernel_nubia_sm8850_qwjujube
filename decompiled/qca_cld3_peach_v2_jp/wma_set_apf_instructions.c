__int64 __fastcall wma_set_apf_instructions(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w23
  int v31; // w8
  unsigned int v32; // w21
  const char *v33; // x2
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _DWORD *v43; // x24
  __int64 v44; // x22
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7

  if ( (unsigned int)_wma_validate_handle(a1, "wma_set_apf_instructions") )
    return 4;
  v12 = *(_QWORD *)a1;
  if ( (unsigned int)_wmi_validate_handle(
                       *(_QWORD *)a1,
                       (__int64)"wma_set_apf_instructions",
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11) )
    return 4;
  if ( (wmi_service_enabled(v12, 0x6Du, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: APF offload feature Disabled",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_set_apf_instructions");
    return 11;
  }
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid APF instruction request",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_set_apf_instructions");
    return 4;
  }
  if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)*a2 )
  {
    v33 = "%s: Invalid vdev_id: %d";
LABEL_15:
    qdf_trace_msg(0x36u, 2u, v33, v22, v23, v24, v25, v26, v27, v28, v29, "wma_set_apf_instructions");
    return 4;
  }
  if ( (wma_is_vdev_up(*a2) & 1) == 0 )
  {
    v33 = "%s: vdev %d is not up skipping APF offload";
    goto LABEL_15;
  }
  v30 = 1114112;
  if ( *((_DWORD *)a2 + 3) )
  {
    v31 = *((_DWORD *)a2 + 5) + 3;
    v32 = (v31 & 0xFFFFFFFC) + 32;
    v30 = v31 & 0xFFFC | 0x110000;
  }
  else
  {
    v32 = 28;
  }
  v34 = wmi_buf_alloc_fl(v12, v32, "wma_set_apf_instructions", 0x139Cu);
  if ( !v34 )
    return 2;
  v43 = *(_DWORD **)(v34 + 224);
  v44 = v34;
  *v43 = 29360152;
  v43[1] = *a2;
  v43[2] = *((_DWORD *)a2 + 2);
  v43[4] = *((_DWORD *)a2 + 3);
  v43[5] = *((_DWORD *)a2 + 4);
  v43[6] = *((_DWORD *)a2 + 5);
  if ( *((_DWORD *)a2 + 3) )
  {
    v43[7] = v30;
    qdf_mem_copy(v43 + 8, *((const void **)a2 + 3), *((unsigned int *)a2 + 5));
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "wma_set_apf_instructions",
      (unsigned int)v43[1]);
    v35 = ((double (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
            54,
            8,
            *((_QWORD *)a2 + 3),
            *((unsigned int *)a2 + 5));
  }
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       v12,
                       v44,
                       v32,
                       0x36003u,
                       "wma_set_apf_instructions",
                       0x13BBu,
                       v35,
                       v36,
                       v37,
                       v38,
                       v39,
                       v40,
                       v41,
                       v42) )
  {
    wmi_buf_free();
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: APF offload enabled in fw",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wma_set_apf_instructions");
    return 0;
  }
}
