__int64 __fastcall csr_roam_update_add_ies(__int64 a1, const void **a2, int a3)
{
  void *v5; // x0
  __int64 v6; // x19
  __int64 v7; // x0
  int v8; // w9
  __int16 v9; // w8
  unsigned int v10; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( *((_WORD *)a2 + 5) )
  {
    v5 = (void *)_qdf_mem_malloc(*((unsigned __int16 *)a2 + 5), "csr_roam_update_add_ies", 7255);
    if ( !v5 )
      return 2;
    v6 = (__int64)v5;
    qdf_mem_copy(v5, a2[2], *((unsigned __int16 *)a2 + 5));
  }
  else
  {
    v6 = 0;
  }
  v7 = _qdf_mem_malloc(0x28u, "csr_roam_update_add_ies", 7263);
  if ( !v7 )
  {
    v10 = 2;
    goto LABEL_9;
  }
  *(_DWORD *)v7 = 2626653;
  v8 = *(_DWORD *)a2;
  *(_WORD *)(v7 + 12) = *((_WORD *)a2 + 2);
  *(_DWORD *)(v7 + 8) = v8;
  *(_WORD *)(v7 + 14) = *((_WORD *)a2 + 3);
  *(_BYTE *)(v7 + 16) = *((_BYTE *)a2 + 8);
  *(_BYTE *)(v7 + 17) = *((_BYTE *)a2 + 9);
  v9 = *((_WORD *)a2 + 5);
  *(_QWORD *)(v7 + 24) = v6;
  *(_DWORD *)(v7 + 32) = a3;
  *(_WORD *)(v7 + 18) = v9;
  v10 = umac_send_mb_message_to_mac(v7);
  if ( v10 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to send eWNI_SME_UPDATE_ADDTIONAL_IES msg status %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "csr_roam_update_add_ies",
      v10);
LABEL_9:
    _qdf_mem_free(v6);
  }
  return v10;
}
