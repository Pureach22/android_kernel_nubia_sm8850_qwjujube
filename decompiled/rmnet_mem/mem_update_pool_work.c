__int64 mem_update_pool_work()
{
  unsigned __int64 StatusReg; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  if ( pb_ind_pending && rmnet_mem_pb_ind_max )
  {
    if ( rmnet_mem_pb_ind_max <= (unsigned __int64)(int)target_pool_size )
      v1 = (int)target_pool_size;
    else
      v1 = rmnet_mem_pb_ind_max;
  }
  else
  {
    v1 = (unsigned int)target_pool_size;
  }
  ((void (__fastcall *)(__int64, _QWORD))rmnet_mem_adjust)(v1, 0);
  if ( pb_ind_pending && qword_8F58 )
  {
    if ( qword_8F58 <= (unsigned __int64)SHIDWORD(target_pool_size) )
      v2 = SHIDWORD(target_pool_size);
    else
      v2 = qword_8F58;
  }
  else
  {
    v2 = HIDWORD(target_pool_size);
  }
  ((void (__fastcall *)(__int64, __int64))rmnet_mem_adjust)(v2, 1);
  if ( pb_ind_pending && qword_8F60 )
  {
    if ( qword_8F60 <= (unsigned __int64)(int)qword_1C0 )
      v3 = (int)qword_1C0;
    else
      v3 = qword_8F60;
  }
  else
  {
    v3 = (unsigned int)qword_1C0;
  }
  ((void (__fastcall *)(__int64, __int64))rmnet_mem_adjust)(v3, 2);
  if ( pb_ind_pending && qword_8F68 )
  {
    if ( qword_8F68 <= (unsigned __int64)SHIDWORD(qword_1C0) )
      v4 = SHIDWORD(qword_1C0);
    else
      v4 = qword_8F68;
  }
  else
  {
    v4 = HIDWORD(qword_1C0);
  }
  v5 = ((__int64 (__fastcall *)(__int64, __int64))rmnet_mem_adjust)(v4, 3);
  return local_bh_enable(v5);
}
