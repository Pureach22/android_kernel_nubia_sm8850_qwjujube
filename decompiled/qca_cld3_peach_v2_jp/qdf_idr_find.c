__int64 __fastcall qdf_idr_find(__int64 a1, int a2, _QWORD *a3)
{
  __int64 result; // x0

  result = 4;
  if ( a2 >= 256 )
  {
    if ( a3 )
    {
      qdf_spinlock_acquire(a1);
      *a3 = idr_find(a1 + 16, (unsigned int)a2);
      qdf_spinlock_release(a1);
      return 4 * (unsigned int)(*a3 == 0);
    }
  }
  return result;
}
