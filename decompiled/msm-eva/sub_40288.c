void __usercall sub_40288(int a1@<W8>)
{
  __int64 v1; // x20
  __int64 v2; // x26

  v2 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)(v1 + 80) = &cvp_alloc_fence_data__alloc_tag_181;
  _kmalloc_noprof(a1, 3520);
  *(_QWORD *)(v1 + 80) = v2;
  JUMPOUT(0x3F5F0);
}
