void sub_30D40()
{
  __int64 v0; // x26
  __int64 v1; // x20

  v1 = *(_QWORD *)(v0 + 80);
  *(_QWORD *)(v0 + 80) = &_init_resources__alloc_tag;
  _kmalloc_large_noprof(23424, 3520);
  *(_QWORD *)(v0 + 80) = v1;
  JUMPOUT(0x2F8F0);
}
