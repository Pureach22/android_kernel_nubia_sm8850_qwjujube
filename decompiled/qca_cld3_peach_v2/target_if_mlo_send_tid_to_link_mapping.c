__int64 __fastcall target_if_mlo_send_tid_to_link_mapping(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  __int64 pdev_wmi_handle; // x0
  __int64 v14; // x9
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w8
  _QWORD *v33; // x9
  char v34; // w11
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
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 result; // x0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // w19
  const char *v125; // x2
  __int64 v126; // [xsp+0h] [xbp-70h]
  __int64 v127; // [xsp+10h] [xbp-60h] BYREF
  _QWORD v128[9]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v129; // [xsp+60h] [xbp-10h]
  __int64 v130; // [xsp+68h] [xbp-8h]

  v130 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  v129 = 0;
  memset(v128, 0, sizeof(v128));
  v127 = 0;
  if ( !v10 )
  {
    v125 = "%s: null pdev";
LABEL_23:
    qdf_trace_msg(0x99u, 2u, v125, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_mlo_send_tid_to_link_mapping");
    result = 29;
    goto LABEL_24;
  }
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(v10, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_wmi_handle )
  {
    v125 = "%s: null wmi handle";
    goto LABEL_23;
  }
  v14 = *(_QWORD *)(a1 + 184);
  v15 = pdev_wmi_handle;
  LOBYTE(v127) = *(_BYTE *)(v10 + 40);
  qdf_mem_copy((char *)&v127 + 1, (const void *)(v14 + 48), 6u);
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: Fill T2LM WMI info for peer: %02x:%02x:%02x:**:**:%02x pdev_id:%d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "target_if_mlo_send_tid_to_link_mapping",
    BYTE1(v127),
    BYTE2(v127),
    BYTE3(v127),
    BYTE6(v127),
    (unsigned __int8)v127);
  v32 = HIBYTE(v127);
  if ( HIBYTE(v127) >= 3uLL )
    goto LABEL_25;
  v33 = &v128[3 * HIBYTE(v127)];
  v34 = *(_BYTE *)(a2 + 4);
  *(_DWORD *)v33 = *(_DWORD *)a2;
  *((_BYTE *)v33 + 4) = v34;
  if ( (v34 & 1) == 0 )
    qdf_mem_copy((char *)&v128[3 * v32] + 6, (const void *)(a2 + 16), 0x10u);
  if ( *(_BYTE *)(a2 + 5) == 1 )
    LOWORD(v129) = *(_WORD *)(a2 + 8);
  if ( *(_BYTE *)(a2 + 6) == 1 )
    HIDWORD(v129) = *(_DWORD *)(a2 + 12);
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: mapping_switch_time_present %d MST %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "target_if_mlo_send_tid_to_link_mapping");
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: expected_switch_time_present %d EDT %d",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "target_if_mlo_send_tid_to_link_mapping",
    *(unsigned __int8 *)(a2 + 6),
    HIDWORD(v129));
  if ( HIBYTE(v127) > 2u )
    goto LABEL_25;
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: num_dir:%d direction:%d default_link_mapping:%d",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "target_if_mlo_send_tid_to_link_mapping");
  if ( HIBYTE(v127) > 2uLL
    || (qdf_trace_msg(
          0x99u,
          8u,
          "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "target_if_mlo_send_tid_to_link_mapping",
          0,
          HIWORD(v128[3 * HIBYTE(v127)]),
          *(unsigned __int16 *)(a2 + 16)),
        HIBYTE(v127) > 2uLL)
    || (qdf_trace_msg(
          0x99u,
          8u,
          "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "target_if_mlo_send_tid_to_link_mapping",
          1,
          LOWORD(v128[3 * HIBYTE(v127) + 1]),
          *(unsigned __int16 *)(a2 + 18)),
        HIBYTE(v127) > 2uLL)
    || (qdf_trace_msg(
          0x99u,
          8u,
          "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "target_if_mlo_send_tid_to_link_mapping",
          2,
          WORD1(v128[3 * HIBYTE(v127) + 1]),
          *(unsigned __int16 *)(a2 + 20)),
        HIBYTE(v127) > 2uLL)
    || (qdf_trace_msg(
          0x99u,
          8u,
          "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "target_if_mlo_send_tid_to_link_mapping",
          3,
          WORD2(v128[3 * HIBYTE(v127) + 1]),
          *(unsigned __int16 *)(a2 + 22)),
        HIBYTE(v127) > 2uLL)
    || (qdf_trace_msg(
          0x99u,
          8u,
          "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          "target_if_mlo_send_tid_to_link_mapping",
          4,
          HIWORD(v128[3 * HIBYTE(v127) + 1]),
          *(unsigned __int16 *)(a2 + 24)),
        HIBYTE(v127) > 2uLL)
    || (qdf_trace_msg(
          0x99u,
          8u,
          "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          "target_if_mlo_send_tid_to_link_mapping",
          5,
          LOWORD(v128[3 * HIBYTE(v127) + 2]),
          *(unsigned __int16 *)(a2 + 26)),
        HIBYTE(v127) > 2uLL)
    || (qdf_trace_msg(
          0x99u,
          8u,
          "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          "target_if_mlo_send_tid_to_link_mapping",
          6,
          WORD1(v128[3 * HIBYTE(v127) + 2]),
          *(unsigned __int16 *)(a2 + 28)),
        HIBYTE(v127) > 2uLL) )
  {
LABEL_25:
    __break(0x5512u);
  }
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: tid:%d hw_link_map:%x ieee_link_map:%x",
    v107,
    v108,
    v109,
    v110,
    v111,
    v112,
    v113,
    v114,
    "target_if_mlo_send_tid_to_link_mapping",
    7,
    WORD2(v128[3 * HIBYTE(v127) + 2]),
    *(unsigned __int16 *)(a2 + 30));
  ++HIBYTE(v127);
  result = wmi_send_mlo_peer_tid_to_link_map_cmd(v15, &v127, 1);
  if ( (_DWORD)result )
  {
    v124 = result;
    LODWORD(v126) = BYTE6(v127);
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Failed to send T2LM WMI command for pdev_id:%d peer_mac: %02x:%02x:%02x:**:**:%02x",
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      "target_if_mlo_send_tid_to_link_mapping",
      (unsigned __int8)v127,
      BYTE1(v127),
      BYTE2(v127),
      BYTE3(v127),
      v126);
    result = v124;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
