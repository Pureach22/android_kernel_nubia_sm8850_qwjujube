__int64 __fastcall stm_source_unregister_device(__int64 a1)
{
  _QWORD *v1; // x19
  unsigned int lock; // w0
  __int64 v3; // x22
  unsigned int v4; // w21
  int v5; // w23

  v1 = *(_QWORD **)(a1 + 8);
  while ( 1 )
  {
    lock = _srcu_read_lock(&stm_source_srcu);
    v3 = v1[116];
    v4 = lock;
    if ( !v3 )
      break;
    mutex_lock(v3 + 992);
    v5 = _stm_source_link_drop(v1, v3);
    mutex_unlock(v3 + 992);
    _srcu_read_unlock(&stm_source_srcu, v4);
    if ( v5 != -11 )
      return device_unregister(v1);
  }
  _srcu_read_unlock(&stm_source_srcu, lock);
  return device_unregister(v1);
}
