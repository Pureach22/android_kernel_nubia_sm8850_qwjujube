__int64 __fastcall send_power_dbg_cmd_tlv(__int64 a1, unsigned int *a2)
{
  int v4; // w22
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
  __int64 v8; // x1
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  unsigned int v10; // w9
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
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
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned int v91; // w20
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7

  v4 = 4 * a2[2];
  v5 = wmi_buf_alloc_fl(a1, v4 + 20, "send_power_dbg_cmd_tlv", 0x30F7u);
  if ( v5 )
  {
    v6 = *(_DWORD **)(v5 + 224);
    v7 = v5;
    *v6 = 34537484;
    v8 = *a2;
    v9 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
    if ( *((_DWORD *)v9 - 1) != -2112860426 )
      __break(0x8228u);
    v6[1] = v9(a1, v8);
    v6[2] = a2[1];
    v10 = a2[2];
    v6[3] = v10;
    v6[4] = (4 * (v10 & 0x3FFF)) | 0x100000;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: %d num of args = ",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "send_power_dbg_cmd_tlv",
      a2[2]);
    if ( a2[2] )
    {
      v6[5] = a2[3];
      qdf_trace_msg(0x31u, 8u, "%s: %d,", v19, v20, v21, v22, v23, v24, v25, v26, "send_power_dbg_cmd_tlv");
      if ( a2[2] >= 2 )
      {
        v6[6] = a2[4];
        qdf_trace_msg(0x31u, 8u, "%s: %d,", v27, v28, v29, v30, v31, v32, v33, v34, "send_power_dbg_cmd_tlv");
        if ( a2[2] >= 3 )
        {
          v6[7] = a2[5];
          qdf_trace_msg(0x31u, 8u, "%s: %d,", v35, v36, v37, v38, v39, v40, v41, v42, "send_power_dbg_cmd_tlv");
          if ( a2[2] >= 4 )
          {
            v6[8] = a2[6];
            qdf_trace_msg(0x31u, 8u, "%s: %d,", v43, v44, v45, v46, v47, v48, v49, v50, "send_power_dbg_cmd_tlv");
            if ( a2[2] >= 5 )
            {
              v6[9] = a2[7];
              qdf_trace_msg(0x31u, 8u, "%s: %d,", v51, v52, v53, v54, v55, v56, v57, v58, "send_power_dbg_cmd_tlv");
              if ( a2[2] >= 6 )
              {
                v6[10] = a2[8];
                qdf_trace_msg(0x31u, 8u, "%s: %d,", v59, v60, v61, v62, v63, v64, v65, v66, "send_power_dbg_cmd_tlv");
                if ( a2[2] >= 7 )
                {
                  v6[11] = a2[9];
                  qdf_trace_msg(0x31u, 8u, "%s: %d,", v67, v68, v69, v70, v71, v72, v73, v74, "send_power_dbg_cmd_tlv");
                  if ( a2[2] >= 8 )
                  {
                    v6[12] = a2[10];
                    qdf_trace_msg(
                      0x31u,
                      8u,
                      "%s: %d,",
                      v75,
                      v76,
                      v77,
                      v78,
                      v79,
                      v80,
                      v81,
                      v82,
                      "send_power_dbg_cmd_tlv");
                  }
                }
              }
            }
          }
        }
      }
    }
    qdf_mtrace(49, 100, 0x222u, 0xFFu, 0);
    v91 = wmi_unified_cmd_send_fl(
            a1,
            v7,
            v4 + 20,
            0x4022u,
            "send_power_dbg_cmd_tlv",
            0x3113u,
            v83,
            v84,
            v85,
            v86,
            v87,
            v88,
            v89,
            v90);
    if ( v91 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_unified_cmd_send WMI_PDEV_WAL_POWER_DEBUG_CMDID returned Error %d",
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        "send_power_dbg_cmd_tlv",
        v91);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v91;
}
