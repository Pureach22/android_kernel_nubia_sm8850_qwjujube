__int64 __fastcall send_fw_profiling_cmd_tlv(
        __int64 a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x0
  _DWORD *v16; // x8
  __int64 v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  __int64 v36; // x0
  _DWORD *v37; // x8
  __int64 v38; // x22
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0
  _DWORD *v48; // x8
  __int64 v49; // x20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w21
  __int64 v67; // x0
  __int64 v68; // x22
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7

  if ( a2 <= 65538 )
  {
    if ( a2 == 65537 )
    {
      v47 = wmi_buf_alloc_fl(a1, 8u, "send_fw_profiling_cmd_tlv", 0x140u);
      if ( v47 )
      {
        v48 = *(_DWORD **)(v47 + 224);
        v49 = v47;
        *v48 = 8650756;
        v48[1] = a3;
        wmi_mtrace(0x10001u, 0xFFu, 0);
        result = wmi_unified_cmd_send_fl(
                   a1,
                   v49,
                   8u,
                   0x10001u,
                   "send_fw_profiling_cmd_tlv",
                   0x14Eu,
                   v50,
                   v51,
                   v52,
                   v53,
                   v54,
                   v55,
                   v56,
                   v57);
        if ( !(_DWORD)result )
          return result;
        v66 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: PROFILE_TRIGGER cmd Failed with value %d",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "send_fw_profiling_cmd_tlv",
          a3);
        goto LABEL_20;
      }
      return 2;
    }
    if ( a2 == 65538 )
    {
      v15 = wmi_buf_alloc_fl(a1, 0xCu, "send_fw_profiling_cmd_tlv", 0x172u);
      if ( v15 )
      {
        v16 = *(_DWORD **)(v15 + 224);
        v17 = v15;
        *v16 = 8716296;
        v16[1] = a3;
        v16[2] = a4;
        wmi_mtrace(0x10002u, 0xFFu, 0);
        result = wmi_unified_cmd_send_fl(
                   a1,
                   v17,
                   0xCu,
                   0x10002u,
                   "send_fw_profiling_cmd_tlv",
                   0x182u,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25);
        if ( !(_DWORD)result )
          return result;
        v35 = "%s: HIST_INTVL cmd Failed for id %d value %d";
LABEL_19:
        v66 = result;
        qdf_trace_msg(0x31u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "send_fw_profiling_cmd_tlv", a3, a4);
LABEL_20:
        wmi_buf_free();
        return v66;
      }
      return 2;
    }
LABEL_12:
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Invalid profiling command: %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "send_fw_profiling_cmd_tlv");
    return 0;
  }
  if ( a2 == 65539 )
  {
    v67 = wmi_buf_alloc_fl(a1, 8u, "send_fw_profiling_cmd_tlv", 0x159u);
    if ( v67 )
    {
      v68 = v67;
      **(_DWORD **)(v67 + 224) = 8781828;
      wmi_mtrace(0x10003u, 0xFFu, 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v68,
                 8u,
                 0x10003u,
                 "send_fw_profiling_cmd_tlv",
                 0x167u,
                 v69,
                 v70,
                 v71,
                 v72,
                 v73,
                 v74,
                 v75,
                 v76);
      if ( !(_DWORD)result )
        return result;
      v35 = "%s: PROFILE_DATA cmd Failed for id %d value %d";
      goto LABEL_19;
    }
    return 2;
  }
  if ( a2 != 65540 )
    goto LABEL_12;
  v36 = wmi_buf_alloc_fl(a1, 0xCu, "send_fw_profiling_cmd_tlv", 0x18Eu);
  if ( v36 )
  {
    v37 = *(_DWORD **)(v36 + 224);
    v38 = v36;
    *v37 = 8847368;
    v37[1] = a3;
    v37[2] = a4;
    wmi_mtrace(0x10004u, 0xFFu, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v38,
               0xCu,
               0x10004u,
               "send_fw_profiling_cmd_tlv",
               0x19Eu,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46);
    if ( !(_DWORD)result )
      return result;
    v35 = "%s: enable cmd Failed for id %d value %d";
    goto LABEL_19;
  }
  return 2;
}
