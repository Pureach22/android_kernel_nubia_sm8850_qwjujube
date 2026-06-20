__int64 __fastcall init_memdump_imem_area(__int64 a1)
{
  __int64 compatible_node; // x0
  __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x19
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = a1;
  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-mem_dump_table");
  if ( compatible_node )
  {
    v3 = of_iomap(compatible_node, 0);
    if ( v3 )
    {
      v4 = v3;
      _memcpy_toio(v3, &memdump, 8);
      _memcpy_toio(v4 + 1828, v5, 8);
      __dsb(0xFu);
      printk(&unk_88AA);
      iounmap(v4);
      result = 0;
    }
    else
    {
      printk(&unk_86E2);
      result = 4294967284LL;
    }
  }
  else
  {
    printk(&unk_845E);
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
