__int64 __fastcall dp_reo_shared_qaddr_detach(__int64 a1)
{
  _qdf_mem_free_consistent(*(_QWORD *)(a1 + 24), *(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), 139400);
  return _qdf_mem_free_consistent(*(_QWORD *)(a1 + 24), *(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), 278528);
}
