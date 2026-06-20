__int64 __fastcall init_deinit_msdu_idx_qtype_map_free(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 4480));
  *(_QWORD *)(a1 + 4480) = 0;
  return 0;
}
