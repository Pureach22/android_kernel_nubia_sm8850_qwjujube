__int64 __fastcall a6xx_fusa_init(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD *resource_byname; // x0
  __int64 v3; // x2
  unsigned int *v4; // x0
  unsigned int v5; // w8
  unsigned int v6; // w8

  if ( **(_DWORD **)(result + 14264) == 663 )
  {
    v1 = (_QWORD *)result;
    resource_byname = (_QWORD *)platform_get_resource_byname(*(_QWORD *)(result + 11168), 512, "fusa");
    if ( resource_byname
      && (!arm64_use_ng_mappings ? (v3 = 0x68000000000713LL) : (v3 = 0x68000000000F13LL),
          (v4 = (unsigned int *)ioremap_prot(*resource_byname, resource_byname[1] - *resource_byname + 1LL, v3)) != nullptr) )
    {
      v5 = *v4;
      __dsb(0xFu);
      *v4 = v5 & 0xFFFFFFF0 | 5;
      v6 = v4[82];
      __dsb(0xFu);
      v4[82] = v6 & 0xFFFFFFF0 | 5;
      return iounmap();
    }
    else
    {
      return dev_err(*v1, "Failed to map fusa\n");
    }
  }
  return result;
}
