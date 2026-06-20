__int64 __fastcall init_deinit_scan_radio_cap_free(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 5752));
  *(_QWORD *)(a1 + 5752) = 0;
  return 0;
}
