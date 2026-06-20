__int64 __fastcall process_mem_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20

  if ( *(_QWORD *)(*(_QWORD *)(a2 + 32) + 128LL) )
  {
    v2 = a1;
    v3 = a2;
    kgsl_process_private_put(*(unsigned int **)(*(_QWORD *)(a2 + 32) + 128LL));
    a1 = v2;
    a2 = v3;
  }
  return seq_release(a1, a2);
}
