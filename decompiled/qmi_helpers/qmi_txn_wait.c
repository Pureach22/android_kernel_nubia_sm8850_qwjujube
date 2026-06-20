__int64 __fastcall qmi_txn_wait(__int64 *a1)
{
  __int64 v2; // x21
  int v3; // w0
  int v5; // w20

  v2 = *a1;
  v3 = wait_for_completion_timeout(a1 + 2);
  if ( *((_DWORD *)a1 + 12) == -102 )
    return 4294967194LL;
  v5 = v3;
  mutex_lock(v2 + 248);
  idr_remove(v2 + 224, *((unsigned __int16 *)a1 + 4));
  mutex_unlock(v2 + 248);
  if ( v5 )
    return *((unsigned int *)a1 + 12);
  else
    return 4294967186LL;
}
