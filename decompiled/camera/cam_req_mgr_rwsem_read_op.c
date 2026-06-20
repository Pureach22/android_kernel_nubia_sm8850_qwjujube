__int64 __fastcall cam_req_mgr_rwsem_read_op(__int64 result)
{
  if ( (_DWORD)result == 2 )
    return up_read(&rwsem_lock);
  if ( (_DWORD)result == 1 )
    return down_read(&rwsem_lock);
  return result;
}
