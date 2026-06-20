__int64 __fastcall cam_isp_blob_csid_irq_comp_cfg(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  __int64 i; // x8
  __int64 result; // x0
  int v8; // w6
  unsigned int v9; // w19

  if ( *a4 > 7u || a4[1] >= 8u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_csid_irq_comp_cfg",
      13895,
      "Invalid hw ctx masks Ctx:%d IPP SRC mask 0x%x IPP DST mask 0x%x",
      *(unsigned int *)(a1 + 56));
    return 4294967274LL;
  }
  for ( i = *(_QWORD *)(a1 + 208); i != a1 + 208 && (!*(_DWORD *)(i + 16) || !*(_QWORD *)(i + 32)); i = *(_QWORD *)i )
    ;
  if ( !i )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_csid_irq_comp_cfg",
      13909,
      "Ctx:%d invalid res",
      *(_DWORD *)(a1 + 56));
    return 4294967274LL;
  }
  result = cam_isp_hw_mgr_add_cmd_buf_util(i, a2, a3, (__int64)a4, 0x4Cu, 0x1Fu);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v8 = *(_DWORD *)(a1 + 56);
    v9 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_csid_irq_comp_cfg",
      13918,
      "Ctx:%d IPP SRC mask 0x%x IPP DST mask 0x%x",
      v8,
      *a4,
      a4[1]);
    return v9;
  }
  return result;
}
