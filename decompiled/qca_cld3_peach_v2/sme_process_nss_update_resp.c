__int64 __fastcall sme_process_nss_update_resp(
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
  __int64 active; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  void (__fastcall *v22)(__int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x6
  __int64 v28; // x3
  __int64 v29; // x2
  const char *v31; // x2

  if ( *((_DWORD *)a2 + 1) != 1 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: reason not NSS update",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_process_nss_update_resp");
    return 4;
  }
  active = csr_nonscan_active_ll_peek_head(a1, 1);
  if ( !active )
  {
    v31 = "%s: No cmd found in active list";
LABEL_11:
    qdf_trace_msg(0x34u, 2u, v31, v13, v14, v15, v16, v17, v18, v19, v20, "sme_process_nss_update_resp");
    return 16;
  }
  v21 = active;
  if ( *(_DWORD *)(active + 16) != 262148 )
  {
    v31 = "%s: Command mismatch!";
    goto LABEL_11;
  }
  v22 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64))(active + 48);
  if ( v22 )
  {
    v23 = *(unsigned int *)(active + 68);
    v24 = *(unsigned int *)(active + 72);
    v25 = *(_QWORD *)(active + 56);
    v26 = *((unsigned int *)a2 + 2);
    v27 = *(unsigned int *)(v21 + 76);
    v28 = *(unsigned __int8 *)(v21 + 64);
    v29 = *a2;
    if ( *((_DWORD *)v22 - 1) != 1154897714 )
      __break(0x8228u);
    v22(v25, v26, v29, v28, v23, v24, v27);
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Callback does not exist",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sme_process_nss_update_resp");
  }
  if ( (csr_nonscan_active_ll_remove_entry(a1, v21, 1) & 1) != 0 )
    csr_release_command(a1, v21);
  return 0;
}
