__int64 __fastcall send_update_edca_pifs_param_cmd_tlv(
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
  int v12; // w9
  unsigned int v13; // w20
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  __int64 v24; // x19
  int v25; // w8
  _DWORD *v26; // x8
  const char *v27; // x2
  unsigned int v28; // w1
  __int64 result; // x0
  int v30; // w8
  int v31; // w9
  unsigned int v32; // w10
  int v33; // w9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // [xsp+0h] [xbp-20h]
  int v43; // [xsp+0h] [xbp-20h]
  int v44; // [xsp+8h] [xbp-18h]
  unsigned int v45; // [xsp+10h] [xbp-10h]
  int v46; // [xsp+18h] [xbp-8h]

  if ( !a2 )
  {
    v27 = "%s: edca_pifs is NULL";
    v28 = 8;
    goto LABEL_19;
  }
  if ( a2[1] )
    v12 = 20;
  else
    v12 = 48;
  if ( a2[1] == 1 )
    v13 = 36;
  else
    v13 = v12;
  v14 = wmi_buf_alloc_fl(a1, v13, "send_update_edca_pifs_param_cmd_tlv", 0x17FEu);
  if ( !v14 )
    return 2;
  v23 = *(_QWORD *)(v14 + 224);
  v24 = v14;
  *(_DWORD *)v23 = 74776584;
  *(_DWORD *)(v23 + 4) = *a2;
  v25 = a2[1];
  *(_DWORD *)(v23 + 8) = v25 == 1;
  if ( v25 == 1 )
  {
    v26 = (_DWORD *)(v23 + 16);
    *(_DWORD *)(v23 + 12) = 1179648;
LABEL_16:
    *v26 = 1179664;
    v26[1] = 74842124;
    v26[2] = a2[2];
    v26[3] = a2[3];
    v33 = a2[4];
    v26[4] = v33;
    LODWORD(v42) = v33;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id %d type %d sap_offset %d leb_offset %d reb_offset %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "send_update_edca_pifs_param_cmd_tlv",
      *(unsigned int *)(v23 + 4),
      *(unsigned int *)(v23 + 8),
      v42);
    goto LABEL_17;
  }
  *(_DWORD *)(v23 + 12) = 1179676;
  *(_DWORD *)(v23 + 16) = 5505048;
  *(_DWORD *)(v23 + 20) = ~(-1 << (a2[3] & 0xF));
  *(_DWORD *)(v23 + 24) = ~(-1 << (*((unsigned __int16 *)a2 + 1) >> 12));
  v30 = (*((_WORD *)a2 + 1) & 0xF) - 1;
  *(_DWORD *)(v23 + 28) = v30;
  v31 = *((unsigned __int16 *)a2 + 2);
  *(_DWORD *)(v23 + 32) = v31;
  v32 = (*((unsigned __int16 *)a2 + 1) >> 4) & 1;
  *(_QWORD *)(v23 + 36) = v32;
  v46 = 0;
  v45 = v32;
  v44 = v31;
  v43 = v30;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id %d type %d cwmin %d cwmax %d aifsn %d txoplimit %d acm %d no_ack %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "send_update_edca_pifs_param_cmd_tlv",
    v43,
    v44,
    v45,
    v46);
  v26 = (_DWORD *)(v23 + 44);
  if ( *(_DWORD *)(v23 + 8) == 1 )
    goto LABEL_16;
  *v26 = 1179648;
LABEL_17:
  qdf_mtrace(49, 100, 0x1F0Au, *(_DWORD *)(v23 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v24,
             v13,
             0x3E00Au,
             "send_update_edca_pifs_param_cmd_tlv",
             0x184Cu,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41);
  if ( !(_DWORD)result )
    return result;
  wmi_buf_free();
  v27 = "%s: Failed to set EDCA/PIFS Parameters";
  v28 = 2;
LABEL_19:
  qdf_trace_msg(0x31u, v28, v27, a3, a4, a5, a6, a7, a8, a9, a10, "send_update_edca_pifs_param_cmd_tlv");
  return 16;
}
