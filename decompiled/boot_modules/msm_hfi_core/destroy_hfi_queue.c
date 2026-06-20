__int64 __fastcall destroy_hfi_queue(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    mutex_lock(result + 1016);
    vring_del_virtqueue(*(_QWORD *)(v1 + 1080));
    return mutex_unlock(v1 + 1016);
  }
  return result;
}
