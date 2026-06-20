unsigned __int64 __fastcall qdf_create_thread(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 result; // x0

  result = kthread_create_on_node(a1, a2, 0xFFFFFFFFLL, a3);
  if ( result > 0xFFFFFFFFFFFFF000LL )
    return 0;
  return result;
}
