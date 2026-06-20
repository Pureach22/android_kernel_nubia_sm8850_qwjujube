bool __fastcall _dsc_trans_queued(__int64 a1)
{
  return !qdf_list_empty((_QWORD *)(a1 + 8));
}
