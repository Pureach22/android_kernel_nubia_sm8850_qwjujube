__int64 __fastcall lim_process_nss_update_request(
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
  unsigned int v10; // w20
  __int64 session_by_vdev_id; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 v23; // x4
  int v24; // w10
  unsigned int v25; // w11
  unsigned int v26; // w9
  __int64 v27; // x4
  unsigned int v28; // w11
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w22
  const char *v39; // x2
  __int64 result; // x0
  const char *v41; // x2

  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Buffer is Pointing to NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_process_nss_update_request");
  v10 = *(_DWORD *)(a2 + 8);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, v10);
  if ( !session_by_vdev_id )
  {
    v23 = *(unsigned int *)(a2 + 8);
    v41 = "%s: Session not found for given session_id %d";
LABEL_16:
    qdf_trace_msg(0x35u, 2u, v41, v14, v15, v16, v17, v18, v19, v20, v21, "lim_process_nss_update_request", v23);
    v38 = 16;
    return lim_nss_or_ch_width_update_rsp(a1, v10, v38, 1);
  }
  v22 = session_by_vdev_id;
  if ( *(_BYTE *)(session_by_vdev_id + 70) )
  {
    v23 = *(unsigned int *)(session_by_vdev_id + 88);
    if ( (_DWORD)v23 != 1 )
    {
      v41 = "%s: Invalid SystemRole %d";
      goto LABEL_16;
    }
  }
  *(_BYTE *)(session_by_vdev_id + 7171) = 1;
  v24 = *(_BYTE *)(session_by_vdev_id + 7172) & 0x80 | (16 * (*(_BYTE *)(a2 + 4) & 7));
  v25 = *(_DWORD *)(session_by_vdev_id + 7176);
  v26 = v24 | v25 & 0xF;
  *(_BYTE *)(session_by_vdev_id + 7172) = *(_BYTE *)(session_by_vdev_id + 7172) & 0x80
                                        | (16 * (*(_BYTE *)(a2 + 4) & 7))
                                        | v25 & 0xF;
  if ( *(_BYTE *)(a2 + 4) == 1 && v25 >= 3 )
  {
    v26 = v24 | 2;
    *(_BYTE *)(session_by_vdev_id + 7172) = v24 | 2;
  }
  v27 = v26 & 0xF;
  if ( (unsigned int)v27 <= 3 )
  {
    v28 = *(unsigned __int8 *)(a2 + 5);
    if ( v28 < (unsigned int)v27 )
    {
      v26 = v28 | v24;
      v27 = *(unsigned __int8 *)(a2 + 5);
      *(_BYTE *)(session_by_vdev_id + 7172) = v28 | v24;
    }
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: ch width %d Rx NSS %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "lim_process_nss_update_request",
    v27,
    (v26 >> 4) & 7);
  v29 = ((__int64 (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(a1, v22);
  if ( v29 )
  {
    v38 = v29;
    v39 = "%s: Unable to set op mode IE in beacon";
  }
  else
  {
    result = lim_send_beacon_ind(a1, v22, 1u, v30, v31, v32, v33, v34, v35, v36, v37);
    if ( !(_DWORD)result )
      return result;
    v38 = result;
    v39 = "%s: Unable to send beacon";
  }
  qdf_trace_msg(0x35u, 2u, v39, v30, v31, v32, v33, v34, v35, v36, v37, "lim_process_nss_update_request");
  return lim_nss_or_ch_width_update_rsp(a1, v10, v38, 1);
}
