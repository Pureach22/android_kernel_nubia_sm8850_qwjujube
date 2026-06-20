void *__fastcall clear(__int64 a1)
{
  void *result; // x0

  if ( !a1 )
    return (void *)printk(&unk_61D9B);
  memset(*(void **)(a1 + 8), 0, 88LL * *(int *)(a1 + 24));
  result = memset(*(void **)(a1 + 16), 0, 4LL * *(int *)(a1 + 24));
  *(_QWORD *)(a1 + 28) = 0;
  return result;
}
