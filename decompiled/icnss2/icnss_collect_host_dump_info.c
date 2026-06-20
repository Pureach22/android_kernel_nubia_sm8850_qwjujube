__int64 __fastcall icnss_collect_host_dump_info(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v4; // x8
  _DWORD *v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x2
  __int64 result; // x0
  const char *v10; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v12; // x23
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v13[0] = 0;
  v3 = _kmalloc_cache_noprof(icc_set_bw, 3264, 5472);
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = *(_QWORD *)(a1 + 16);
      if ( !v4 )
        goto LABEL_16;
      v5 = *(_DWORD **)(v4 + 312);
      if ( !v5 )
        goto LABEL_16;
      if ( *(v5 - 1) != -912711288 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *))v5)(v2 + 16, v3, v13) )
      {
        kfree(v3);
LABEL_16:
        v10 = "%sicnss2: Host SSR elf dump collection feature disabled\n";
        printk("%sicnss2: Host SSR elf dump collection feature disabled\n", byte_13289B);
        goto LABEL_19;
      }
      if ( !v13[0] )
        break;
      v6 = 0;
      v2 = 0;
      while ( 1 )
      {
        v7 = 48 * v6;
        if ( (unsigned __int64)(v7 - 5441) < 0xFFFFFFFFFFFFEA9FLL
          || (unsigned __int64)(v7 - 5433) < 0xFFFFFFFFFFFFEA9FLL )
        {
          break;
        }
        ipc_log_string(
          icnss_ipc_log_long_context,
          "icnss2: Idx:%d, ptr: %p, name: %s, size: %zu\n",
          v2,
          *(const void **)(v3 + v7 + 32),
          (const char *)(v3 + v7),
          *(_QWORD *)(v3 + v7 + 40));
        v2 = (unsigned int)(v2 + 1);
        v8 = v13[0];
        v6 = (int)v2;
        if ( v13[0] <= (unsigned __int64)(int)v2 )
          goto LABEL_14;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v12 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &icnss_collect_host_dump_info__alloc_tag;
      v3 = _kmalloc_cache_noprof(icc_set_bw, 3264, 5472);
      *(_QWORD *)(StatusReg + 80) = v12;
      if ( !v3 )
        goto LABEL_18;
    }
    v8 = 0;
LABEL_14:
    icnss_do_host_ramdump(a1, v3, v8);
    result = kfree(v3);
  }
  else
  {
LABEL_18:
    v10 = "%sicnss2: ssr_entry malloc failed";
    printk("%sicnss2: ssr_entry malloc failed", byte_130B32);
LABEL_19:
    result = ipc_log_string(icnss_ipc_log_context, v10, &unk_12DBF3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
