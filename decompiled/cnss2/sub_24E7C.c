void sub_24E7C()
{
  __int64 v0; // x20
  __int64 v1; // x21
  __int64 v2; // x23

  v2 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)(v1 + 80) = &cnss_pci_dump_sram__alloc_tag;
  vzalloc_noprof(*(unsigned int *)(v0 + 6600));
  *(_QWORD *)(v1 + 80) = v2;
  JUMPOUT(0x24D04);
}
