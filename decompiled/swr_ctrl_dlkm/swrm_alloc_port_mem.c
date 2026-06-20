__int64 __fastcall swrm_alloc_port_mem(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x8
  __int64 v8; // x22

  v4 = *(_QWORD *)(a2 + 15840);
  if ( v4 || (v8 = a1, v4 = devm_kmalloc(a1, 32, 3520), a1 = v8, (*(_QWORD *)(a2 + 15840) = v4) != 0) )
  {
    if ( *(_QWORD *)(v4 + 8LL * a3) )
    {
      if ( (unsigned int)__ratelimit(&swrm_alloc_port_mem__rs, "swrm_alloc_port_mem") )
        dev_err(*(_QWORD *)(a2 + 8512), "%s: called more than once\n", "swrm_alloc_port_mem");
      return 0;
    }
    *(_QWORD *)(*(_QWORD *)(a2 + 15840) + 8LL * a3) = devm_kmalloc(a1, 12LL * a4, 3520);
    if ( *(_QWORD *)(*(_QWORD *)(a2 + 15840) + 8LL * a3) )
      return 0;
  }
  return 4294967284LL;
}
