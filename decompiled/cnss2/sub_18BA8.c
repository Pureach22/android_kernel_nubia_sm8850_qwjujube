void __usercall sub_18BA8(__int64 a1@<X1>, __int64 a2@<X8>)
{
  __int64 v2; // x21
  __int64 (__fastcall *v3)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v5; // x0

  v2 = *(_QWORD *)(a2 + 80);
  v3 = of_find_compatible_node;
  *(_QWORD *)(a2 + 80) = &cnss_schedule_recovery__alloc_tag;
  v5 = _kmalloc_cache_noprof(v3, a1, 4);
  *(_QWORD *)(a2 + 80) = v2;
  if ( !v5 )
    JUMPOUT(0x18B5C);
  JUMPOUT(0x18B90);
}
