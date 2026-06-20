__int64 __fastcall a6xx_gmu_parse_fw(__int64 a1)
{
  unsigned __int64 **v1; // x20
  __int64 v2; // x22
  unsigned __int64 *v4; // x8
  unsigned __int64 v5; // x10
  __int64 v6; // x23
  __int64 v7; // x1
  int v8; // w0
  __int64 v9; // x9
  int v10; // w26
  unsigned int *v11; // x27
  unsigned int v12; // w8
  unsigned int vma_block; // w21
  unsigned __int64 v14; // x0

  v1 = (unsigned __int64 **)(a1 - 1640);
  v2 = *(_QWORD *)(a1 + 1544);
  v4 = *(unsigned __int64 **)(a1 - 1640);
  if ( v4 )
  {
    v5 = *v4;
    if ( !*v4 )
      return 0;
LABEL_7:
    v9 = 0;
    while ( 1 )
    {
      v10 = v9 + 16;
      if ( v9 + 16 > v5 )
      {
        dev_err(v2 + 16, "Invalid FW Block\n");
        return (unsigned int)-22;
      }
      v11 = (unsigned int *)(v4[1] + v9);
      if ( v11[1] )
        return 0;
      v12 = v11[2];
      if ( v12 == 7 || v12 == 1 )
      {
        vma_block = gmu_core_find_vma_block(a1, *v11);
        if ( (vma_block & 0x80000000) != 0 )
        {
          dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Invalid prealloc block addr: 0x%x value:%d\n", *v11, v11[3]);
          return vma_block;
        }
        if ( vma_block != 6 && (vma_block & 0x7FFFFFFD) != 0 && !gmu_core_find_memdesc(a1, *v11, v11[3]) )
        {
          v14 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))gmu_core_reserve_kernel_block)(
                  a1,
                  *v11,
                  v11[3],
                  vma_block,
                  0);
          if ( v14 > 0xFFFFFFFFFFFFF000LL )
            return (unsigned int)v14;
          *(_BYTE *)(a1 - 376) = 1;
        }
      }
      v4 = *v1;
      v9 = v10;
      v5 = **v1;
      if ( v10 >= v5 )
        return 0;
    }
  }
  v6 = *(_QWORD *)(a1 + 14264);
  v7 = *(_QWORD *)(v6 + 112);
  if ( !v7 )
    return (unsigned int)-22;
  v8 = request_firmware(a1 - 1640, v7, v2 + 16);
  if ( v8 )
  {
    vma_block = v8;
    dev_err(v2 + 16, "request_firmware (%s) failed: %d\n", *(const char **)(v6 + 112), v8);
    return vma_block;
  }
  v4 = *v1;
  v5 = **v1;
  if ( v5 )
    goto LABEL_7;
  return 0;
}
