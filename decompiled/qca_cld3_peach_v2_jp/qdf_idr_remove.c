__int64 __fastcall qdf_idr_remove(__int64 a1, int a2)
{
  __int64 result; // x0

  result = 4;
  if ( a1 && a2 >= 256 )
  {
    qdf_spinlock_acquire(a1);
    if ( idr_find(a1 + 16, (unsigned int)a2) )
      idr_remove(a1 + 16, (unsigned int)a2);
    qdf_spinlock_release(a1);
    return 0;
  }
  return result;
}
