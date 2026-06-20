__int64 __fastcall ucsi_qti_unregister_work(__int64 result)
{
  _QWORD *v1; // x20
  __int64 v2; // x19

  v1 = (_QWORD *)(result - 1408);
  if ( *(_QWORD *)(result - 1408) )
  {
    v2 = result - 1192;
    mutex_lock(result - 1192);
    ucsi_unregister(*v1);
    ucsi_destroy(*v1);
    *v1 = 0;
    return mutex_unlock(v2);
  }
  return result;
}
