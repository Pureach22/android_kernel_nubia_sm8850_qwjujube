void sub_38394()
{
  __int64 v0; // x19
  __int64 v1; // x26
  __int64 v2; // x21
  __int64 v3; // x8

  v2 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)(v1 + 80) = &cnss_aop_update_mode__alloc_tag;
  v3 = *(unsigned int *)(v0 + 7720);
  if ( (v3 & 0x80000000) == 0 )
    _kmalloc_noprof(8 * v3, 3520);
  *(_QWORD *)(v1 + 80) = v2;
  JUMPOUT(0x37D94);
}
