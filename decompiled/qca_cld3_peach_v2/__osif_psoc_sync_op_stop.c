__int64 __fastcall _osif_psoc_sync_op_stop(__int64 a1, __int64 a2)
{
  return dsc_psoc_op_stop(*(_QWORD *)(a1 + 8), a2);
}
