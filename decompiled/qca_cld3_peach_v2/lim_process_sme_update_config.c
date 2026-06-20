__int64 __fastcall lim_process_sme_update_config(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w8
  __int16 v30; // w8
  __int16 v31; // w9
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  qdf_trace_msg(
    0x35u,
    8u,
    "%s: received eWNI_SME_UPDATE_HT_CONFIG message",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_sme_update_config");
  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Buffer is Pointing to NULL",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "lim_process_sme_update_config");
  result = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
  if ( !result )
    return qdf_trace_msg(
             0x35u,
             3u,
             "%s: Session does not exist for given BSSID",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "lim_process_sme_update_config");
  v29 = *(unsigned __int16 *)(a2 + 6);
  if ( v29 > 5 )
  {
    switch ( v29 )
    {
      case 6u:
        v30 = (*(_WORD *)(a2 + 8) & 1) << 6;
        v31 = *(_WORD *)(result + 7266) & 0xFFBF;
        break;
      case 7u:
        v30 = (*(_WORD *)(a2 + 8) & 1) << 7;
        v31 = *(_WORD *)(result + 7266) & 0xFF7F;
        break;
      case 8u:
        v30 = (*(_WORD *)(a2 + 8) & 3) << 8;
        v31 = *(_WORD *)(result + 7266) & 0xFCFF;
        break;
      default:
        goto LABEL_16;
    }
LABEL_15:
    *(_WORD *)(result + 7266) = v30 | v31;
    goto LABEL_16;
  }
  if ( *(_WORD *)(a2 + 6) )
  {
    if ( v29 != 5 )
      goto LABEL_16;
    v30 = 32 * (*(_WORD *)(a2 + 8) & 1);
    v31 = *(_WORD *)(result + 7266) & 0xFFDF;
    goto LABEL_15;
  }
  *(_WORD *)(result + 7266) = *(_WORD *)(result + 7266) & 0xFFFE | *(_WORD *)(a2 + 8) & 1;
LABEL_16:
  if ( *(_DWORD *)(result + 88) == 1 )
  {
    v32 = result;
    sch_set_fixed_beacon_fields(a1, result);
    return lim_send_beacon_ind(a1, v32, 2u, v33, v34, v35, v36, v37, v38, v39, v40);
  }
  return result;
}
