__int64 __fastcall cam_irq_controller_dep_reg_read(__int64 result, __int64 a2)
{
  char v3; // w8
  __int64 v4; // x25
  __int64 v5; // x21
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x27
  __int64 v8; // x28
  unsigned int v9; // w9
  unsigned int v10; // w8
  int v11; // w9
  __int64 v12; // x24
  int v13; // w23
  const char *v14; // [xsp+20h] [xbp-20h]
  _QWORD v15[3]; // [xsp+28h] [xbp-18h] BYREF

  v3 = 0;
  v4 = result + 216;
  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = (const char *)result;
  v5 = *(_DWORD *)(result + 64) & 0x1FFFLL;
  memset(v15, 0, 13);
  do
  {
    v6 = (-1LL << v3) & v5;
    if ( !v6 )
      break;
    v7 = __clz(__rbit64(v6));
    v8 = *(_QWORD *)(v4 + 8 * v7);
    if ( v8 )
    {
      v9 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 23);
      if ( *(_BYTE *)(a2 + v7) == 1 )
      {
        if ( v9 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000,
            4,
            "cam_irq_controller_dep_reg_read",
            1062,
            "Reading dependent registers for %s",
            *(const char **)(v4 + 8 * v7));
        result = _cam_irq_controller_read_registers(v8);
        goto LABEL_20;
      }
      if ( v9 )
      {
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   debug_mdl & 0x800000,
                   4,
                   "cam_irq_controller_dep_reg_read",
                   1066,
                   "Sanitize registers for %s",
                   *(const char **)(v4 + 8 * v7));
        v10 = *(_DWORD *)(v8 + 24);
        if ( v10 )
        {
LABEL_12:
          v11 = 0;
          do
          {
            v12 = *(_QWORD *)(v8 + 32) + 112LL * v11;
            v13 = v11;
            if ( *(_BYTE *)(v12 + 108) == 1 )
            {
              *(_BYTE *)(v12 + 108) = 0;
              if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x800000,
                  4,
                  "__cam_irq_controller_sanitize_clear_registers",
                  1015,
                  "(%s) Write irq clear%d (0x%x) = 0x%x (dirty=%s)",
                  (const char *)v8,
                  v11,
                  *(_DWORD *)(*(_QWORD *)(v8 + 32) + 112LL * v11 + 8),
                  0,
                  "N");
              result = cam_io_w(0, *(_QWORD *)(v8 + 16) + *(unsigned int *)(v12 + 8));
              v10 = *(_DWORD *)(v8 + 24);
            }
            v11 = v13 + 1;
          }
          while ( v13 + 1 < v10 );
        }
      }
      else
      {
        v10 = *(_DWORD *)(v8 + 24);
        if ( v10 )
          goto LABEL_12;
      }
LABEL_20:
      if ( *(_DWORD *)(v8 + 64) )
      {
        raw_spin_lock(v8 + 320);
        cam_irq_controller_get_need_reg_read(v8, (__int64)v15);
        cam_irq_controller_dep_reg_read(v8, v15);
        result = raw_spin_unlock(v8 + 320);
      }
      goto LABEL_3;
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x800000,
               1,
               "cam_irq_controller_dep_reg_read",
               1056,
               "%s[%d] is undefined",
               v14,
               v7);
LABEL_3:
    v3 = v7 + 1;
  }
  while ( v7 < 0xC );
  _ReadStatusReg(SP_EL0);
  return result;
}
