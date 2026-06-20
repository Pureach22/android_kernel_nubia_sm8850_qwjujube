__int64 __fastcall osif_psoc_sync_wait_for_ops(__int64 a1)
{
  return dsc_psoc_wait_for_ops(*(_QWORD *)(a1 + 8));
}
