__int64 __fastcall cnss_vreg_off_type(
        _QWORD *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x6
  const char *v10; // x1
  __int64 v11; // x20
  _QWORD *v12; // x24
  __int64 v14; // x21
  unsigned __int64 v15; // x8
  __int64 v16; // x26
  __int16 v17; // w9
  const char *v18; // x8
  __int64 result; // x0
  __int64 property; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = a2;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v18;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_vreg_off_type",
      3u,
      3u,
      "Unsupported vreg type 0x%x\n",
      v9,
      a8,
      vars0);
    return 4294967274LL;
  }
  v11 = a1[4];
  v12 = a1 + 3;
  if ( (_QWORD *)v11 == a1 + 3 )
  {
    if ( a1[66] == 4369 )
      return 0;
    v14 = 0;
LABEL_24:
    property = of_find_property(*(_QWORD *)(*a1 + 760LL), "fig-direct-cx", 0);
    result = 0;
    if ( property && v14 )
      goto LABEL_26;
    return result;
  }
  v14 = 0;
  do
  {
    v15 = *(_QWORD *)(v11 + 16);
    v16 = v14;
    if ( !v15 || v15 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_8;
    if ( a1[66] != 4369 && !of_find_property(*(_QWORD *)(*a1 + 760LL), "fig-direct-cx", 0)
      || (v14 = v11, strcmp(*(const char **)(v11 + 24), "vdd-wlan-cx")) )
    {
      cnss_vreg_off_single(v11);
LABEL_8:
      v14 = v16;
    }
    v11 = *(_QWORD *)(v11 + 8);
  }
  while ( (_QWORD *)v11 != v12 );
  if ( a1[66] != 4369 )
    goto LABEL_24;
  if ( !v14 )
    return 0;
LABEL_26:
  if ( (a1[69] & 0x200) != 0 )
    return 0;
  cnss_vreg_off_single(v14);
  return 0;
}
