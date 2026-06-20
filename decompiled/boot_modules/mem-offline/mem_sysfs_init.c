__int64 mem_sysfs_init()
{
  __int64 result; // x0
  __int64 v1; // x0
  unsigned __int64 v2; // x19
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x23
  void *v12; // x0
  __int64 v13; // [xsp+0h] [xbp-70h] BYREF
  __int64 v14; // [xsp+8h] [xbp-68h]
  __int64 v15; // [xsp+10h] [xbp-60h]
  __int64 v16; // [xsp+18h] [xbp-58h]
  __int64 v17; // [xsp+20h] [xbp-50h]
  __int64 v18; // [xsp+28h] [xbp-48h]
  __int64 v19; // [xsp+30h] [xbp-40h]
  __int64 v20; // [xsp+38h] [xbp-38h]
  __int64 v21; // [xsp+40h] [xbp-30h]
  __int64 v22; // [xsp+48h] [xbp-28h]
  __int64 v23; // [xsp+50h] [xbp-20h]
  __int64 v24; // [xsp+58h] [xbp-18h]
  int v25; // [xsp+60h] [xbp-10h]
  __int64 v26; // [xsp+68h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( start_section_nr == end_section_nr )
    goto LABEL_2;
  v1 = kobject_create_and_add("mem-offline", kernel_kobj);
  kobj = v1;
  if ( !v1 )
  {
    result = 4294967284LL;
    goto LABEL_18;
  }
  if ( (unsigned int)sysfs_create_group(v1, &mem_attr_group) )
    kobject_put(kobj);
  v2 = start_section_nr;
  if ( start_section_nr <= (unsigned __int64)end_section_nr )
  {
    v9 = kobj;
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    while ( (int)scnprintf(&v13, 100, "memory%lu", v2) >= 1 )
    {
      v10 = kobject_create_and_add(&v13, v9);
      if ( !v10 )
        break;
      v11 = v10;
      if ( (unsigned int)sysfs_create_group(v10, &mem_block_attr_group) )
        kobject_put(v11);
      v2 += (unsigned int)sections_per_block;
      if ( v2 > end_section_nr )
        goto LABEL_7;
    }
    v12 = &unk_9FB2;
    goto LABEL_28;
  }
LABEL_7:
  if ( differing_segment_sizes != 1 )
    goto LABEL_16;
  v3 = kobj;
  v25 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  if ( (unsigned int)sysfs_create_group(kobj, &differing_segments_attr_group) )
  {
    kobject_put(kobj);
  }
  else
  {
    scnprintf(&v13, 100, "seg_info");
    v4 = kobject_create_and_add(&v13, v3);
    if ( v4 )
    {
      if ( num_segments )
      {
        v5 = v4;
        v6 = 0;
        do
        {
          scnprintf(&v13, 100, "segment%lu", v6);
          v7 = kobject_create_and_add(&v13, v5);
          if ( !v7 )
            goto LABEL_27;
          v8 = v7;
          if ( (unsigned int)sysfs_create_group(v7, &seg_info_attr_group) )
            kobject_put(v8);
        }
        while ( ++v6 < (unsigned __int64)num_segments );
      }
LABEL_16:
      result = 0;
      goto LABEL_18;
    }
  }
LABEL_27:
  v12 = &unk_9E27;
LABEL_28:
  printk(v12);
LABEL_2:
  result = 4294967274LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
