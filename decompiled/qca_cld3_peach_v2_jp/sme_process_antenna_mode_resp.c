__int64 __fastcall sme_process_antenna_mode_resp(__int64 a1, unsigned int *a2)
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
  void (__fastcall *v14)(__int64, __int64); // x8
  __int64 v15; // x1
  __int64 v16; // x0
  const char *v17; // x2

  active = csr_nonscan_active_ll_peek_head(a1, 1);
  if ( !active )
  {
    v17 = "%s: No cmd found in active list";
LABEL_9:
    qdf_trace_msg(0x34u, 2u, v17, v5, v6, v7, v8, v9, v10, v11, v12, "sme_process_antenna_mode_resp");
    return 16;
  }
  v13 = active;
  if ( *(_DWORD *)(active + 16) != 262150 )
  {
    v17 = "%s: Command mismatch!";
    goto LABEL_9;
  }
  v14 = *(void (__fastcall **)(__int64, __int64))(active + 40);
  if ( v14 )
  {
    v15 = *(_QWORD *)(active + 48);
    v16 = *a2;
    if ( *((_DWORD *)v14 - 1) != 1916394597 )
      __break(0x8228u);
    v14(v16, v15);
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Callback does not exist",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sme_process_antenna_mode_resp");
  }
  if ( (csr_nonscan_active_ll_remove_entry(a1, v13, 1) & 1) != 0 )
    csr_release_command(a1, v13);
  return 0;
}
