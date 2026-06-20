__int64 __fastcall cnss_pm_relax(__int64 result)
{
  unsigned __int64 StatusReg; // x9
  const char *v2; // x1
  __int16 v3; // w10
  const char *v4; // x9
  _QWORD *v5; // x19
  unsigned int v12; // w8
  unsigned int v13; // w8
  char v14; // [xsp+0h] [xbp+0h]

  _X9 = (unsigned int *)(result + 6264);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v12 = __ldxr(_X9);
    v13 = v12 - 1;
  }
  while ( __stlxr(v13, _X9) );
  __dmb(0xBu);
  if ( (v13 & 0x80000000) != 0 )
  {
    __break(0x800u);
  }
  else if ( !v13 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v2 = "irq";
    }
    else
    {
      v3 = *(_DWORD *)(StatusReg + 16);
      v4 = (const char *)(StatusReg + 2320);
      if ( (v3 & 0xFF00) != 0 )
        v2 = "soft_irq";
      else
        v2 = v4;
    }
    v5 = (_QWORD *)result;
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v2,
      "cnss_pm_relax",
      7u,
      7u,
      "PM relax, state: 0x%lx, count: %d\n",
      *(_QWORD *)(result + 552),
      *(unsigned int *)(result + 6264),
      v14);
    return pm_relax(*v5 + 16LL);
  }
  return result;
}
