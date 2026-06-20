void __usercall sub_6764(int a1@<W8>)
{
  __int64 v1; // x22
  __int64 v2; // x23
  int v3; // w24
  __int64 v4; // x27
  __int64 v5; // x9

  v4 = *(_QWORD *)(v1 + 80);
  v5 = *(_QWORD *)(v2 + 3256) + 96LL * v3;
  *(_QWORD *)(v1 + 80) = &wcnss_find_pool_table_slot__alloc_tag;
  krealloc_noprof(*(_QWORD *)(v5 + 80), 8LL * a1, 2080);
  *(_QWORD *)(v1 + 80) = v4;
  JUMPOUT(0x6678);
}
