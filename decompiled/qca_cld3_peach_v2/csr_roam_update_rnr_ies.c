__int64 __fastcall csr_roam_update_rnr_ies(__int64 a1, __int64 a2)
{
  void *v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int16 v6; // w8
  unsigned int v7; // w20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  if ( *(_WORD *)(a2 + 2) )
  {
    v3 = (void *)_qdf_mem_malloc(*(unsigned __int16 *)(a2 + 2), "csr_roam_update_rnr_ies", 7301);
    if ( !v3 )
      return 2;
    v4 = (__int64)v3;
    qdf_mem_copy(v3, *(const void **)(a2 + 8), *(unsigned __int16 *)(a2 + 2));
  }
  else
  {
    v4 = 0;
  }
  v5 = _qdf_mem_malloc(0x18u, "csr_roam_update_rnr_ies", 7309);
  if ( !v5 )
  {
    v7 = 2;
    goto LABEL_9;
  }
  *(_DWORD *)v5 = 1578165;
  *(_WORD *)(v5 + 8) = *(_WORD *)a2;
  v6 = *(_WORD *)(a2 + 2);
  *(_QWORD *)(v5 + 16) = v4;
  *(_WORD *)(v5 + 10) = v6;
  v7 = umac_send_mb_message_to_mac(v5);
  if ( v7 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to send eWNI_SME_UPDATE_ADDTIONAL_IES msg status %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "csr_roam_update_rnr_ies",
      v7);
LABEL_9:
    _qdf_mem_free(v4);
  }
  return v7;
}
