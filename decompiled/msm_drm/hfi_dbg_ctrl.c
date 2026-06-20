void hfi_dbg_ctrl(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        ...)
{
  int v9; // w26
  __int64 gr_offs; // x8
  const char *v11; // x24
  const char **stack; // x8
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  gcc_va_list va; // [xsp+38h] [xbp-28h] BYREF
  __int64 v21; // [xsp+58h] [xbp-8h]

  va_start(va, a9);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_end(va);
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(hfi_dbg + 328) )
  {
    v9 = 15;
    va_start(va, a9);
    while ( 1 )
    {
      gr_offs = va[0].__gr_offs;
      if ( va[0].__gr_offs < 0 && (va[0].__gr_offs += 8, (unsigned int)gr_offs <= 0xFFFFFFF8) )
      {
        v11 = *(const char **)((char *)va[0].__gr_top + gr_offs);
        if ( !v11 )
          goto LABEL_18;
      }
      else
      {
        stack = (const char **)va[0].__stack;
        va[0].__stack = (char *)va[0].__stack + 8;
        v11 = *stack;
        if ( !*stack )
          goto LABEL_18;
      }
      if ( !v9 )
        break;
      if ( (unsigned __int64)v11 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_18;
      v13 = strcmp(v11, "stop_ftrace");
      if ( !(_DWORD)v13 && (*(_BYTE *)(hfi_dbg + 328) & 1) != 0 )
        tracing_off(v13, v14, v15, v16, v17, v18, v19);
      if ( !strcmp(v11, "panic_underrun") && (*(_BYTE *)(hfi_dbg + 328) & 2) != 0 )
      {
        printk(&unk_23EF01, "hfi_dbg_ctrl");
        hfi_dbg_dump(1);
      }
      --v9;
    }
    printk(&unk_26FD67, "hfi_dbg_ctrl");
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
}
