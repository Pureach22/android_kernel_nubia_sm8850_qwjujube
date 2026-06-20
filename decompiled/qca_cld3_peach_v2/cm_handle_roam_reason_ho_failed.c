_QWORD *__fastcall cm_handle_roam_reason_ho_failed(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  result = _cds_get_context(54, (__int64)"wma_handle_roam_reason_ho_failed", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( result )
  {
    v23 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: LFR3:Hand-Off Failed for vdevid %x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_handle_roam_reason_ho_failed",
      (unsigned __int8)a1);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: mac addr to avoid %02x:%02x:%02x:**:**:%02x",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wma_handle_roam_reason_ho_failed",
      (unsigned __int8)a2,
      BYTE1(a2),
      BYTE2(a2),
      BYTE5(a2));
    ((void (__fastcall *)(_QWORD *, __int64))wma_handle_hw_mode_trans_ind)(v23, a3);
    cm_fw_ho_fail_req(v23[3], a1, a2 & 0xFFFFFFFFFFFFLL);
    return (_QWORD *)lim_sae_auth_cleanup_retry(v23[2], a1);
  }
  return result;
}
