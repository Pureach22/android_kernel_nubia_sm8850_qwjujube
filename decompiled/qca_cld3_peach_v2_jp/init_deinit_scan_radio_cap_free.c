__int64 __fastcall init_deinit_scan_radio_cap_free(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 4472));
  *(_QWORD *)(a1 + 4472) = 0;
  return 0;
}
