__int64 __fastcall zte_get_xbl_log_memory_region(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  _QWORD v9[11]; // [xsp+8h] [xbp-58h] BYREF

  v9[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(*a1 + 744LL);
  memset(v9, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "memory-region", 0, 0, 0, v9) || !v9[0] )
  {
    dev_err(*a1, "ztedbg no xbl log memory-region specified\n");
LABEL_9:
    result = 4294967274LL;
    goto LABEL_6;
  }
  v3 = of_reserved_mem_lookup();
  if ( !v3 )
  {
    dev_err(*a1, "ztedbg unable to resolve xbl log memory-region\n");
    goto LABEL_9;
  }
  v4 = v3;
  a1[14] = *(_QWORD *)(v3 + 24);
  v5 = *(_QWORD *)(v3 + 32);
  v6 = *a1;
  a1[15] = v5;
  v7 = devm_ioremap_wc(v6);
  a1[16] = v7;
  if ( v7 )
  {
    result = 0;
  }
  else
  {
    dev_err(*a1, "ztedbg unable to map xbl log memory region: %pa+%zx\n", (const void *)(v4 + 24), a1[15]);
    result = 4294967280LL;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
