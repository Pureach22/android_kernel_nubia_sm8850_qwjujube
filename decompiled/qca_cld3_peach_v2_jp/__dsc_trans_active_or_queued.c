bool __fastcall _dsc_trans_active_or_queued(_QWORD *a1)
{
  return *a1 || !qdf_list_empty(a1 + 1);
}
