__int64 __fastcall cnss_va_to_pa(__int64 a1, __int64 a2, __int64 a3, __int64 a4, _QWORD *a5)
{
  char v5; // w19
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  __int64 result; // x0
  __int16 v11; // w9
  const char *v12; // x8
  _QWORD v13[2]; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v14[2]; // [xsp+20h] [xbp-10h] BYREF

  v5 = a2;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = a4;
  v13[0] = 0;
  v13[1] = 0;
  if ( (unsigned int)dma_get_sgtable_attrs(a1, v13, a3, a4, a2) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v12;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_va_to_pa",
      3u,
      3u,
      "Failed to get sgtable for va: 0x%pK, dma: %pa, size: 0x%zx, attrs: 0x%x\n",
      a3,
      (__int64)v14,
      v5);
    result = 4294967274LL;
  }
  else
  {
    *a5 = (((*(_QWORD *)v13[0] & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
    sg_free_table(v13);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
