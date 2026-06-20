__int64 __fastcall osif_cm_reset_id_and_src_no_lock(__int64 result)
{
  *(_QWORD *)(result + 24) = -4294967275LL;
  return result;
}
