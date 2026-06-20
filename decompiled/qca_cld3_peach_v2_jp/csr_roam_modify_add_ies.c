__int64 __fastcall csr_roam_modify_add_ies(__int64 a1, const void **a2, int a3)
{
  __int64 v5; // x0
  void *v6; // x19
  __int64 v7; // x0
  _DWORD *v8; // x22
  int v9; // w9
  char v10; // w8
  int v11; // w8
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v5 = _qdf_mem_malloc(*((unsigned __int16 *)a2 + 6), "csr_roam_modify_add_ies", 7191);
  if ( v5 )
  {
    v6 = (void *)v5;
    v7 = _qdf_mem_malloc(0x30u, "csr_roam_modify_add_ies", 7195);
    if ( !v7 )
    {
      v12 = 2;
      goto LABEL_7;
    }
    v8 = (_DWORD *)v7;
    qdf_mem_copy(v6, a2[2], *((unsigned __int16 *)a2 + 6));
    qdf_mem_set(v8, 0x30u, 0);
    *v8 = 3150942;
    v9 = *(_DWORD *)a2;
    *((_WORD *)v8 + 6) = *((_WORD *)a2 + 2);
    v8[2] = v9;
    *((_WORD *)v8 + 7) = *((_WORD *)a2 + 3);
    *((_BYTE *)v8 + 16) = *((_BYTE *)a2 + 8);
    *((_BYTE *)v8 + 17) = *((_BYTE *)a2 + 9);
    v10 = *((_BYTE *)a2 + 10);
    *((_QWORD *)v8 + 3) = v6;
    *((_BYTE *)v8 + 18) = v10;
    *((_WORD *)v8 + 10) = *((_WORD *)a2 + 6);
    v11 = *((_DWORD *)a2 + 6);
    v8[10] = a3;
    v8[8] = v11;
    v12 = umac_send_mb_message_to_mac(v8);
    if ( v12 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to send eWNI_SME_UPDATE_ADDTIONAL_IES msg status %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "csr_roam_modify_add_ies",
        v12);
LABEL_7:
      _qdf_mem_free((__int64)v6);
    }
  }
  else
  {
    return 2;
  }
  return v12;
}
