void sub_33508()
{
  __int64 v0; // x27
  __int64 v1; // x28
  __int64 v2; // x19

  v2 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)(v1 + 80) = &cnss_pci_get_mhi_msi__alloc_tag;
  if ( (v0 & 0x80000000) == 0 )
    _kmalloc_noprof(4 * v0, 3520);
  *(_QWORD *)(v1 + 80) = v2;
  JUMPOUT(0x33104);
}
