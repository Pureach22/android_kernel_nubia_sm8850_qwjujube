__int64 allocate_si_object()
{
  __int64 result; // x0

  result = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( result )
  {
    *(_QWORD *)(result + 16) = 0;
    *(_DWORD *)(result + 12) = 16;
    *(_QWORD *)(result + 80) = 0;
  }
  return result;
}
