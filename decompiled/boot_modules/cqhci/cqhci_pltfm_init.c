__int64 __fastcall cqhci_pltfm_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 result; // x0

  if ( !platform_get_resource_byname(a1, 512, "cqhci") )
    return -22;
  v2 = devm_kmalloc(a1 + 16, 224, 3520);
  if ( !v2 )
    return -12;
  v3 = v2;
  v4 = devm_ioremap(a1 + 16);
  result = v3;
  *(_QWORD *)(v3 + 8) = v4;
  if ( !v4 )
  {
    dev_err(a1 + 16, "failed to remap cqhci regs\n");
    return -16;
  }
  return result;
}
