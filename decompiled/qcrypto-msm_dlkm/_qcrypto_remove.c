__int64 __fastcall qcrypto_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 32);
    mutex_lock(v2 + 136);
    qcrypto_remove_engine(v1);
    mutex_unlock(v2 + 136);
    if ( *(_QWORD *)(v1 + 16) )
      qce_close();
    return kfree_sensitive(v1);
  }
  return result;
}
