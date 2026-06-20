__int64 __fastcall mem_dump_resume(__int64 a1)
{
  __int64 v2; // x23
  _QWORD *v3; // x20
  __int64 compatible_node; // x0
  __int64 v5; // x0
  __int64 v6; // x21
  int inited; // w0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = total_size;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 8, 3520);
  v9[0] = 0;
  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-mem_dump_table");
  if ( !compatible_node
    || (v5 = of_iomap(compatible_node, 0)) == 0
    || (v6 = v5, _memcpy_fromio(v3, v5, 8), _memcpy_fromio(v9, v6 + 1828, 8), *v3 != memdump)
    || v9[0] != v2 )
  {
    if ( (unsigned int)qcom_scm_assign_dump_table_region(1, global_mini_phys_addr, total_size) )
    {
      inited = init_memdump_imem_area(total_size);
      if ( inited )
        dev_err(a1 + 16, "init memdump imem area failed, ret=%d\n", inited);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
