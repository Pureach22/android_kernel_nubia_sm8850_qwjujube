void sde_dbg_ctrl(
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
  int i; // w27
  __int64 gr_offs; // x8
  const char *v11; // x25
  const char **stack; // x8
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  char v23; // [xsp+0h] [xbp-60h]
  gcc_va_list va; // [xsp+38h] [xbp-28h] BYREF
  __int64 v25; // [xsp+58h] [xbp-8h]

  va_start(va, a9);
  v23 = va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_arg(va, _QWORD);
  va_end(va);
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( dword_2945A4 )
  {
    va_start(va, a9);
    for ( i = 15; ; --i )
    {
      gr_offs = va[0].__gr_offs;
      if ( va[0].__gr_offs < 0 && (va[0].__gr_offs += 8, (unsigned int)gr_offs <= 0xFFFFFFF8) )
      {
        v11 = *(const char **)((char *)va[0].__gr_top + gr_offs);
        if ( !v11 )
          goto LABEL_21;
      }
      else
      {
        stack = (const char **)va[0].__stack;
        va[0].__stack = (char *)va[0].__stack + 8;
        v11 = *stack;
        if ( !*stack )
          goto LABEL_21;
      }
      if ( !i )
        break;
      if ( (unsigned __int64)v11 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_21;
      v13 = strcmp(v11, "stop_ftrace");
      if ( !(_DWORD)v13 && (dword_2945A4 & 1) != 0 )
        tracing_off(v13, v14, v15, v16, v17, v18, v19);
      if ( !strcmp(v11, "panic_underrun") && (dword_2945A4 & 2) != 0 )
      {
        printk(&unk_24D14A, "sde_dbg_ctrl");
        sde_dbg_dump(1, (__int64)"sde_dbg_ctrl", 0xFFFFFF, (__int64)"panic", 0, v20, v21, v22, v23);
      }
      if ( !strcmp(v11, "reset_hw_panic") && (dword_2945A4 & 4) != 0 )
        panic("reset_hw");
    }
    printk(&unk_250823, "sde_dbg_ctrl");
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
}
