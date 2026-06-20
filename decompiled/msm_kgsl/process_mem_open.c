__int64 __fastcall process_mem_open(__int64 a1, __int64 a2)
{
  __int64 *v3; // x0
  unsigned int *v4; // x20
  __int64 result; // x0
  unsigned int v6; // w19

  v3 = kgsl_process_private_find(*(_DWORD *)(a1 + 696));
  if ( !v3 )
    return 4294967277LL;
  v4 = (unsigned int *)v3;
  result = seq_open(a2, process_mem_seq_fops);
  if ( (_DWORD)result )
  {
    v6 = result;
    kgsl_process_private_put(v4);
    return v6;
  }
  else
  {
    *(_QWORD *)(*(_QWORD *)(a2 + 32) + 128LL) = v4;
  }
  return result;
}
