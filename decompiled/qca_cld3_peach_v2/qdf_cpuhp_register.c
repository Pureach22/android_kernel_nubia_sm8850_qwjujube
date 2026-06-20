__int64 __fastcall qdf_cpuhp_register(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v8; // x0
  _QWORD *v9; // x20
  __int64 result; // x0
  unsigned int inserted; // w21
  unsigned int v12; // w19

  *a1 = 0;
  v8 = (_QWORD *)_qdf_mem_malloc(0x28u, "qdf_cpuhp_register", 111);
  if ( !v8 )
    return 2;
  v9 = v8;
  v8[2] = a2;
  v8[3] = a3;
  v8[4] = a4;
  LODWORD(result) = qdf_mutex_acquire((__int64)&qdf_cpuhp_lock);
  if ( (_DWORD)result
    || (inserted = qdf_list_insert_back(&qdf_cpuhp_handlers, v9),
        qdf_mutex_release((__int64)&qdf_cpuhp_lock),
        (result = inserted) != 0) )
  {
    v12 = result;
    _qdf_mem_free((__int64)v9);
    return v12;
  }
  else
  {
    *a1 = v9;
  }
  return result;
}
