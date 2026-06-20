__int64 __fastcall cnss_pci_add_dump_seg(
        __int64 *a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x22
  __int64 v13; // x24
  __int64 v14; // x0
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  __int64 result; // x0
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // [xsp+18h] [xbp-18h] BYREF
  __int64 v22[2]; // [xsp+20h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v22[0] = a6;
  v13 = *a1;
  v12 = a1[1];
  *(_QWORD *)a2 = a6;
  *(_QWORD *)(a2 + 8) = a5;
  *(_QWORD *)(a2 + 16) = a7;
  v14 = cnss_ipc_log_context;
  *(_DWORD *)(a2 + 24) = a3;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v15 = "irq";
  }
  else
  {
    v16 = *(_DWORD *)(StatusReg + 16);
    v17 = (const char *)(StatusReg + 2320);
    if ( (v16 & 0xFF00) != 0 )
      v15 = "soft_irq";
    else
      v15 = v17;
  }
  v21 = 0;
  result = cnss_debug_ipc_log_print(
             v14,
             v15,
             "cnss_pci_add_dump_seg",
             7u,
             7u,
             "Seg: %x, va: %pK, dma: %pa, size: 0x%zx\n",
             a4,
             a5,
             (char)v22);
  if ( a3 != 3 )
  {
    result = cnss_va_to_pa(v13 + 200, a7, a5, v22[0], &v21);
    if ( !(_DWORD)result )
      result = cnss_minidump_add_region(v12, a3, a4, a5, v21, a7, v19, v20);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
