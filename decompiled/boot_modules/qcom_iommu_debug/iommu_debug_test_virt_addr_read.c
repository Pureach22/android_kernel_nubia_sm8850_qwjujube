__int64 __fastcall iommu_debug_test_virt_addr_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  const void *v8; // x3
  __int64 v9; // x22
  _QWORD v10[12]; // [xsp+0h] [xbp-70h] BYREF
  int v11; // [xsp+60h] [xbp-10h]
  __int64 v12; // [xsp+68h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a4 )
  {
    result = 0;
  }
  else
  {
    v11 = 0;
    memset(v10, 0, sizeof(v10));
    mutex_lock(&test_virt_addr_lock);
    v8 = (const void *)test_virt_addr;
    if ( test_virt_addr && (unsigned __int64)test_virt_addr < 0xFFFFFFFFFFFFF001LL
      || (v8 = (const void *)_kmalloc_large_noprof(0x100000, 3520), (test_virt_addr = (__int64)v8) != 0) )
    {
      v9 = (int)scnprintf(v10, 100, "0x%p\n", v8);
    }
    else
    {
      test_virt_addr = -12;
      strcpy((char *)v10, "FAIL\n");
      v9 = 5;
    }
    mutex_unlock(&test_virt_addr_lock);
    result = simple_read_from_buffer(a2, a3, a4, v10, v9);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
