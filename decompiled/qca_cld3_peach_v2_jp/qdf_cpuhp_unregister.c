_QWORD **__fastcall qdf_cpuhp_unregister(_QWORD **result)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x19

  v1 = *result;
  if ( *result )
  {
    v2 = result;
    qdf_mutex_acquire((__int64)&qdf_cpuhp_lock);
    qdf_list_remove_node((__int64)&qdf_cpuhp_handlers, v1);
    qdf_mutex_release((__int64)&qdf_cpuhp_lock);
    result = (_QWORD **)_qdf_mem_free((__int64)v1);
    *v2 = 0;
  }
  return result;
}
