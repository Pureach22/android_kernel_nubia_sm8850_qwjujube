__int64 __fastcall _hdd_op_unprotect_cb(__int64 a1, __int64 a2)
{
  return _osif_psoc_sync_op_stop(a1, a2);
}
