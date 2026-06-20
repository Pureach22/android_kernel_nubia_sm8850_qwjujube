__int64 __fastcall qmi_txn_cancel(__int64 *a1)
{
  __int64 v1; // x20

  v1 = *a1;
  mutex_lock(*a1 + 248);
  idr_remove(v1 + 224, *((unsigned __int16 *)a1 + 4));
  return mutex_unlock(v1 + 248);
}
