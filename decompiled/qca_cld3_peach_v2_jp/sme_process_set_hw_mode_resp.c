__int64 __fastcall sme_process_set_hw_mode_resp(__int64 a1, unsigned int *a2)
{
  __int64 active; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned int v14; // w21
  unsigned int v15; // w24
  void (__fastcall *v16)(__int64, __int64, __int64, unsigned int *, __int64, __int64, __int64, __int64, int); // x25
  unsigned int v17; // w23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x2
  __int64 v31; // x7
  __int64 v32; // x4
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  const char *v42; // x2
  int v45; // w3
  int v46; // [xsp+0h] [xbp-10h]

  active = csr_nonscan_active_ll_peek_head(a1, 1);
  if ( !active )
  {
    v42 = "%s: No cmd found in active list";
LABEL_15:
    qdf_trace_msg(0x34u, 2u, v42, v5, v6, v7, v8, v9, v10, v11, v12, "sme_process_set_hw_mode_resp");
    return 16;
  }
  v13 = active;
  if ( *(_DWORD *)(active + 16) != 262147 )
  {
    v42 = "%s: Command mismatch!";
    goto LABEL_15;
  }
  v15 = *(_DWORD *)(active + 48);
  v14 = *(_DWORD *)(active + 52);
  v16 = *(void (__fastcall **)(__int64, __int64, __int64, unsigned int *, __int64, __int64, __int64, __int64, int))(active + 40);
  v17 = *(_DWORD *)(active + 72);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: reason: %d session: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "sme_process_set_hw_mode_resp",
    v15,
    v14);
  if ( v16 )
  {
    v26 = *a2;
    v27 = a2[1];
    v28 = *(unsigned int *)(v13 + 48);
    v29 = *(unsigned int *)(v13 + 52);
    v30 = a2[2];
    v31 = *(_QWORD *)(v13 + 64);
    v32 = *(unsigned __int8 *)(v13 + 56);
    v46 = *(_DWORD *)(v13 + 72);
    if ( *((_DWORD *)v16 - 1) != -845582708 )
      __break(0x8239u);
    v16(v26, v27, v30, a2 + 3, v32, v28, v29, v31, v46);
    if ( a1 && v14 <= 5 && (v41 = *(_QWORD *)(a1 + 17224)) != 0 && (*(_BYTE *)(v41 + 96LL * v14 + 1) & 1) != 0 )
    {
      if ( v15 == 8 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Continue channel switch for SAP on vdev %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "sme_process_set_hw_mode_resp",
          v14);
        csr_csa_restart(a1, v14);
      }
      else if ( v15 == 7 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Continue channel switch for STA on vdev %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "sme_process_set_hw_mode_resp",
          v14);
        csr_sta_continue_csa(a1, v14);
      }
      else if ( v15 - 13 <= 1 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Continue connect/reassoc on vdev %d reason %d status %d cm_id 0x%x",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "sme_process_set_hw_mode_resp",
          v14,
          v15,
          *a2,
          v17);
        if ( *a2 == 7 || *a2 == 0 )
          v45 = 0;
        else
          v45 = 16;
        wlan_cm_handle_hw_mode_change_resp(*(_QWORD *)(a1 + 21560), v14, v17, v45);
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: session %d is invalid",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "sme_process_set_hw_mode_resp",
        v14);
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Callback does not exist",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "sme_process_set_hw_mode_resp");
  }
  if ( (csr_nonscan_active_ll_remove_entry(a1, v13, 1) & 1) != 0 )
    csr_release_command(a1, v13);
  return 0;
}
