__int64 __fastcall hif_log_pcie_info(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x8
  int v15; // w9
  __int64 result; // x0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  if ( a1 )
  {
    pld_pci_read_config_word(*(_QWORD *)(a1 + 30768), 2u, (__int64)&v17 + 2);
    v14 = (unsigned int)*a3;
    LOWORD(v17) = 2306;
    if ( (unsigned int)v14 > 0xBF
      || (qdf_mem_copy((void *)(a2 + v14), &v17, 4u),
          v15 = HIWORD(v17),
          *a3 += 4,
          v15 == *(unsigned __int16 *)(a1 + 30908)) )
    {
      result = 0;
    }
    else
    {
      qdf_recovery_reason_update();
      qdf_get_bus_reg_dump();
      result = 1;
    }
  }
  else
  {
    qdf_trace_msg(0x3Du, 2u, "%s: HIF Bus Context is Invalid", a4, a5, a6, a7, a8, a9, a10, a11, "hif_log_pcie_info");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
