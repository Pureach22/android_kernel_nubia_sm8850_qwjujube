__int64 __fastcall hdd_twt_update_work_handler(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[3];
  v4[0] = 0;
  result = _osif_psoc_sync_op_start(*(_QWORD *)(v2 + 488), v4, (__int64)"hdd_twt_update_work_handler");
  if ( !(_DWORD)result )
  {
    osif_twt_concurrency_update_handler(*a1, a1[1]);
    result = _osif_psoc_sync_op_stop(v4[0], (__int64)"hdd_twt_update_work_handler");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
