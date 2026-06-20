__int64 __fastcall lim_process_sta_mlm_del_bss_rsp(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 hash_entry; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  const char *v16; // x2
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  hash_entry = dph_get_hash_entry(a1, 1u, a3 + 360);
  v15 = hash_entry;
  if ( !a2 )
  {
    v16 = "%s: Invalid body pointer in message";
LABEL_5:
    result = qdf_trace_msg(0x35u, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "lim_process_sta_mlm_del_bss_rsp");
    if ( !v15 )
      return result;
    goto LABEL_6;
  }
  if ( *a2 )
  {
    LODWORD(a2) = 533;
    v16 = "%s: DEL BSS failed!";
    goto LABEL_5;
  }
  if ( !hash_entry )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: DPH Entry for STA 1 missing",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "lim_process_sta_mlm_del_bss_rsp");
  if ( *(_DWORD *)(hash_entry + 8) == 17 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: STA AssocID %d MAC %02x:%02x:%02x:**:**:%02x",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "lim_process_sta_mlm_del_bss_rsp",
               *(unsigned __int16 *)(hash_entry + 336),
               *(unsigned __int8 *)(hash_entry + 338),
               *(unsigned __int8 *)(hash_entry + 339),
               *(unsigned __int8 *)(hash_entry + 340),
               *(unsigned __int8 *)(hash_entry + 343));
    LODWORD(a2) = 0;
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Received unexpected WMA_DEL_BSS_RSP in state %X",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "lim_process_sta_mlm_del_bss_rsp");
    LODWORD(a2) = 506;
  }
LABEL_6:
  if ( *(_DWORD *)(a3 + 88) != 2 || (*(_DWORD *)(a3 + 80) & 0xFFFFFFFE) == 0xC || *(_WORD *)(v15 + 34) == 7 )
    return lim_prepare_and_send_del_sta_cnf(a1, v15, (unsigned int)a2, a3, v18, v19, v20, v21, v22, v23, v24, v25);
  return result;
}
