__int64 __fastcall msm_dss_ioremap_byname(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x20
  __int64 *resource_byname; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // x0

  v4 = v3;
  if ( a1 && a2 )
  {
    resource_byname = (__int64 *)platform_get_resource_byname(a1, 512, a3);
    if ( resource_byname )
    {
      v7 = resource_byname[1] - *resource_byname + 1;
      *(_DWORD *)a2 = v7;
      v8 = *resource_byname;
      if ( arm64_use_ng_mappings )
        v9 = 0x68000000000F13LL;
      else
        v9 = 0x68000000000713LL;
      v10 = ioremap_prot(v8, (unsigned int)v7, v9);
      *(_QWORD *)(a2 + 8) = v10;
      if ( v10 )
      {
        return 0;
      }
      else
      {
        printk(&unk_227DB9, v4);
        return 4294967291LL;
      }
    }
    else
    {
      printk(&unk_269721, "msm_dss_get_res_byname");
      printk(&unk_21A15A, v4);
      return 4294967277LL;
    }
  }
  else
  {
    printk(&unk_22ECB8, v3);
    return 4294967274LL;
  }
}
