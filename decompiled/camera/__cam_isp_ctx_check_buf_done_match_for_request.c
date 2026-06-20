bool __fastcall _cam_isp_ctx_check_buf_done_match_for_request(int *a1, _QWORD *a2, __int64 a3, char a4)
{
  int v4; // w8
  int v5; // w11
  __int64 v6; // x19
  __int64 v7; // x11
  _QWORD *v10; // x20
  char is_expanded_memory; // w0
  unsigned __int64 v13; // x8
  char v14; // w20
  const char *v16; // x6
  __int64 v17; // x8
  unsigned int v18; // w9
  unsigned int v19; // w10
  _QWORD *v20; // [xsp+48h] [xbp+18h]

  v4 = *((_DWORD *)a2 + 8);
  if ( !v4 )
    return 0;
  v5 = 0;
  while ( 1 )
  {
    v6 = v5;
    v7 = a2[3] + ((__int64)v5 << 6);
    if ( *(_DWORD *)(a3 + 4) != *(_DWORD *)v7 )
      goto LABEL_3;
    if ( (a4 & 1) == 0 )
      break;
    if ( (*(_BYTE *)(v7 + 24) & 1) != 0 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v14 = debug_mdl;
        v20 = a2;
        v16 = _cam_isp_resource_handle_id_to_type(a1[11395], *(_DWORD *)(a3 + 4));
        v17 = v20[3] + (v6 << 6);
        v18 = *(_DWORD *)(v17 + 4);
        v19 = __clz(__rbit32(v18));
        if ( !v18 )
          v19 = -1;
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, const char *, _QWORD, unsigned int, _DWORD, _QWORD, _DWORD, _DWORD))cam_print_log)(
          3,
          v14 & 8,
          4,
          "__cam_isp_ctx_check_buf_done_match_for_request",
          2527,
          "[FRMHDR] Match buf done with res: %s, frmhdr addr: %pK, hw_ctxt_id: %u, local_id: %u, req_id: %llu, ctx %u, link: 0x%x",
          v16,
          *(_QWORD *)(v17 + 8),
          v19,
          *(_DWORD *)(*(_QWORD *)(v17 + 8) + 12LL),
          *(_QWORD *)(*v20 + 24LL),
          *(_DWORD *)(*(_QWORD *)a1 + 32LL),
          *(_DWORD *)(*(_QWORD *)a1 + 64LL));
        a2 = v20;
      }
      return *(_DWORD *)(*(_QWORD *)(a2[3] + (v6 << 6) + 8) + 12LL) == *(_DWORD *)(*a2 + 24LL);
    }
LABEL_3:
    v5 = v6 + 1;
    if ( v4 == (_DWORD)v6 + 1 )
      return 0;
  }
  v10 = a2;
  is_expanded_memory = cam_smmu_is_expanded_memory();
  v13 = *(_QWORD *)(v10[3] + (v6 << 6) + 32);
  if ( (is_expanded_memory & 1) != 0 )
    LODWORD(v13) = v13 >> 8;
  return *(_DWORD *)(a3 + 12) == (_DWORD)v13;
}
