__int64 __fastcall cnss_pci_collect_host_dump_info(unsigned __int64 a1)
{
  unsigned __int64 v1; // x21
  const char *v2; // x23
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v5; // x19
  __int64 v6; // x8
  _DWORD *v7; // x8
  __int64 v8; // x0
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  __int64 result; // x0
  unsigned __int64 v14; // x24
  __int64 v15; // x8
  const char *v16; // x1
  __int64 v17; // x8
  __int64 v18; // x2
  unsigned __int64 v19; // x20
  __int64 v20; // x22
  unsigned __int64 v21; // x8
  const char *v22; // x1
  __int16 v23; // w9
  const char *v24; // x8
  char v25; // [xsp+0h] [xbp-30h]
  const char *v26; // [xsp+10h] [xbp-20h]
  _QWORD v27[2]; // [xsp+20h] [xbp-10h] BYREF

  v1 = a1;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(const char **)(a1 + 8);
  v27[0] = 0;
  v5 = _kmalloc_cache_noprof(put_device, 3264, 5472);
  if ( v5 )
  {
    while ( 1 )
    {
      v6 = *(_QWORD *)(v1 + 40);
      if ( !v6 )
        goto LABEL_7;
      v7 = *(_DWORD **)(v6 + 152);
      if ( !v7 )
        goto LABEL_7;
      v8 = *(_QWORD *)v1;
      if ( *(v7 - 1) != 332576058 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *))v7)(v8, v5, v27) )
      {
LABEL_7:
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v10 = "irq";
        }
        else
        {
          v11 = *(_DWORD *)(StatusReg + 16);
          v12 = (const char *)(StatusReg + 2320);
          if ( (v11 & 0xFF00) != 0 )
            v10 = "soft_irq";
          else
            v10 = v12;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v10,
          "cnss_pci_collect_host_dump_info",
          6u,
          6u,
          "Host SSR elf dump collection feature disabled\n",
          v3,
          v4,
          v25);
        goto LABEL_13;
      }
      if ( !v27[0] )
        break;
      v14 = _ReadStatusReg(SP_EL0);
      v15 = 0;
      v1 = 0;
      v26 = v2;
      v2 = "Idx:%d, ptr: %p, name: %s, size: %d\n";
      while ( 1 )
      {
        v16 = "irq";
        if ( (*(_DWORD *)(v14 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
            v16 = "soft_irq";
          else
            v16 = (const char *)(v14 + 2320);
        }
        v17 = 48 * v15;
        if ( (unsigned __int64)(v17 - 5441) < 0xFFFFFFFFFFFFEA9FLL
          || (unsigned __int64)(v17 - 5433) < 0xFFFFFFFFFFFFEA9FLL )
        {
          break;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v16,
          "cnss_pci_collect_host_dump_info",
          6u,
          6u,
          "Idx:%d, ptr: %p, name: %s, size: %d\n",
          (unsigned int)v1,
          *(_QWORD *)(v5 + v17 + 32),
          v5 + v17);
        v1 = (unsigned int)(v1 + 1);
        v18 = v27[0];
        v15 = (int)v1;
        if ( v27[0] <= (unsigned __int64)(int)v1 )
        {
          v2 = v26;
          goto LABEL_25;
        }
      }
      __break(1u);
      v19 = _ReadStatusReg(SP_EL0);
      v20 = *(_QWORD *)(v19 + 80);
      *(_QWORD *)(v19 + 80) = &cnss_pci_collect_host_dump_info__alloc_tag;
      v5 = _kmalloc_cache_noprof(put_device, 3264, 5472);
      *(_QWORD *)(v19 + 80) = v20;
      if ( !v5 )
        goto LABEL_27;
    }
    v18 = 0;
LABEL_25:
    cnss_do_host_ramdump((__int64)v2, v5, v18);
LABEL_13:
    result = kfree(v5);
  }
  else
  {
LABEL_27:
    v21 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
    {
      v22 = "irq";
    }
    else
    {
      v23 = *(_DWORD *)(v21 + 16);
      v24 = (const char *)(v21 + 2320);
      if ( (v23 & 0xFF00) != 0 )
        v22 = "soft_irq";
      else
        v22 = v24;
    }
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v22,
               "cnss_pci_collect_host_dump_info",
               3u,
               3u,
               "ssr_entry malloc failed",
               v3,
               v4,
               v25);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
