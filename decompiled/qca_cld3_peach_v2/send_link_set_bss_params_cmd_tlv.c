__int64 __fastcall send_link_set_bss_params_cmd_tlv(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  __int64 v22; // x19
  int v23; // w0
  int v24; // w9
  int v25; // w1
  int v26; // w2
  int v27; // w3
  int v28; // w10
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 result; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w20
  int v55; // [xsp+0h] [xbp-70h]
  int v56; // [xsp+8h] [xbp-68h]
  int v57; // [xsp+10h] [xbp-60h]
  int v58; // [xsp+18h] [xbp-58h]
  int v59; // [xsp+20h] [xbp-50h]
  int v60; // [xsp+28h] [xbp-48h]
  int v61; // [xsp+30h] [xbp-40h]
  int v62; // [xsp+38h] [xbp-38h]
  int v63; // [xsp+40h] [xbp-30h]
  int v64; // [xsp+48h] [xbp-28h]
  int v65; // [xsp+50h] [xbp-20h]
  int v66; // [xsp+58h] [xbp-18h]
  int v67; // [xsp+60h] [xbp-10h]
  int v68; // [xsp+68h] [xbp-8h]

  if ( !*((_WORD *)a2 + 12) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid ch_freq 0 for link %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_link_set_bss_params_cmd_tlv",
      *a2);
    return 16;
  }
  v12 = wmi_buf_alloc_fl(a1, 0x4Cu, "send_link_set_bss_params_cmd_tlv", 0x902u);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "send_link_set_bss_params_cmd_tlv");
    return 16;
  }
  v21 = *(_QWORD *)(v12 + 224);
  v22 = v12;
  *(_DWORD *)v21 = 77594636;
  *(_DWORD *)(v21 + 4) = *(_DWORD *)(a2 + 1);
  *(_DWORD *)(v21 + 8) = *(unsigned __int16 *)(a2 + 5);
  *(_QWORD *)(v21 + 16) = 0x49F003400120038LL;
  *(_DWORD *)(v21 + 24) = *a2;
  *(_DWORD *)(v21 + 56) = a2[64];
  *(_DWORD *)(v21 + 32) = *((unsigned __int16 *)a2 + 12);
  *(_DWORD *)(v21 + 36) = *((_DWORD *)a2 + 10);
  *(_DWORD *)(v21 + 40) = *((_DWORD *)a2 + 11);
  v23 = wmi_host_to_fw_phymode(*((_DWORD *)a2 + 13));
  v24 = *(_DWORD *)(v21 + 40);
  v25 = *(_DWORD *)(v21 + 32);
  v26 = *(_DWORD *)(v21 + 36);
  v27 = *(_DWORD *)(v21 + 56);
  v28 = *(_DWORD *)(v21 + 24);
  *(_DWORD *)(v21 + 44) = *(_DWORD *)(v21 + 44) & 0xFFFFFFC0 | v23;
  *(_DWORD *)(v21 + 60) = *(_DWORD *)(a2 + 7);
  *(_DWORD *)(v21 + 64) = *(unsigned __int16 *)(a2 + 11);
  *(_DWORD *)(v21 + 68) = *(_DWORD *)(a2 + 13);
  *(_DWORD *)(v21 + 72) = *(unsigned __int16 *)(a2 + 17);
  v68 = v27;
  v67 = v23;
  v65 = v26;
  v64 = v25;
  v66 = v24;
  v63 = v28;
  v62 = a2[12];
  v61 = a2[9];
  v60 = a2[8];
  v59 = a2[7];
  v58 = a2[18];
  v57 = a2[15];
  v56 = a2[14];
  v55 = a2[13];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: ap mld mac: %02x:%02x:%02x:**:**:%02xself link addr %02x:%02x:%02x:**:**:%02x ap link addr %02x:%02x:%02x:**:**:"
    "%02x link id %d chan freq %d cfreq1 %d cfreq2 %d fw phymode %d op_code %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "send_link_set_bss_params_cmd_tlv",
    a2[1],
    a2[2],
    a2[3],
    a2[6],
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68);
  wmi_mtrace(0x48009u, 0, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v22,
             0x4Cu,
             0x48009u,
             "send_link_set_bss_params_cmd_tlv",
             0x93Au,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             v44);
  if ( (_DWORD)result )
  {
    v54 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send link set bss command ret = %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "send_link_set_bss_params_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return v54;
  }
  return result;
}
