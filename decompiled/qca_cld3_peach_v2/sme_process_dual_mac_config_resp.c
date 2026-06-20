__int64 __fastcall sme_process_dual_mac_config_resp(__int64 a1, unsigned int *a2)
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
  void (__fastcall *v14)(__int64, __int64, __int64); // x22
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x0
  const char *v18; // x2

  active = csr_nonscan_active_ll_peek_head(a1, 1);
  if ( !active )
  {
    v18 = "%s: No cmd found in active list";
LABEL_9:
    qdf_trace_msg(0x34u, 2u, v18, v5, v6, v7, v8, v9, v10, v11, v12, "sme_process_dual_mac_config_resp");
    return 16;
  }
  v13 = active;
  if ( *(_DWORD *)(active + 16) != 262149 )
  {
    v18 = "%s: Command mismatch!";
    goto LABEL_9;
  }
  v14 = *(void (__fastcall **)(__int64, __int64, __int64))(active + 40);
  if ( v14 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Calling HDD callback for Dual mac config",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sme_process_dual_mac_config_resp");
    v15 = *(unsigned int *)(v13 + 32);
    v16 = *(unsigned int *)(v13 + 36);
    v17 = *a2;
    if ( *((_DWORD *)v14 - 1) != 48842031 )
      __break(0x8236u);
    v14(v17, v15, v16);
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
      "sme_process_dual_mac_config_resp");
  }
  if ( (csr_nonscan_active_ll_remove_entry(a1, v13, 1) & 1) != 0 )
    csr_release_command(a1, v13);
  return 0;
}
