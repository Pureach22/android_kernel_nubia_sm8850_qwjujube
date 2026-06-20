__int64 __fastcall sde_encoder_phys_cmd_te_deassert_irq(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  int v8; // w4
  char v9; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    _ReadStatusReg(SP_EL0);
    if ( *(_QWORD *)result )
      v8 = *(_DWORD *)(*(_QWORD *)result + 24LL);
    else
      v8 = -1;
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_phys_cmd_te_deassert_irq",
             691,
             2,
             v8,
             -1059143953,
             a7,
             a8,
             v9);
  }
  return result;
}
