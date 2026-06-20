__int64 __fastcall gen7_cx_timer_init(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 StatusReg; // x25
  __int64 v8; // x24
  int v9; // w27
  __int64 (*v10)(void); // x8
  __int64 v11; // x0
  __int64 (*v12)(void); // x8
  __int64 v13; // x20
  unsigned __int64 v14; // x21
  __int64 v15; // x0
  __int64 (__fastcall *v16)(__int64); // x8
  unsigned __int64 v17; // x21
  __int64 (*v19)(void); // x8
  unsigned __int64 v20; // x20
  unsigned __int64 v23; // x9

  if ( **(_DWORD **)(result + 14264) >> 1 == 230528 )
  {
    v1 = result;
    if ( (*(_QWORD *)(result + 14240) & 0x20000) == 0 )
    {
      StatusReg = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v8 = 0;
      v9 = 16;
      do
      {
        v10 = (__int64 (*)(void))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        v11 = v10();
        v12 = (__int64 (*)(void))arch_timer_read_counter;
        v13 = v11;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        v14 = v12();
        kgsl_regmap_write(v1 + 13200, (unsigned int)v14);
        v15 = kgsl_regmap_write(v1 + 13200, HIDWORD(v14));
        __dsb(0xFu);
        v16 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        --v9;
        v8 = v13 + v8 - 2 * v14 + v16(v15);
      }
      while ( v9 );
      _WriteStatusReg(DAIF, StatusReg);
      v17 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v19 = (__int64 (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v20 = v19() + ((unsigned __int64)(v8 + 8) >> 4);
      kgsl_regmap_write(v1 + 13200, (unsigned int)v20);
      result = kgsl_regmap_write(v1 + 13200, HIDWORD(v20));
      _WriteStatusReg(DAIF, v17);
      _X8 = (unsigned __int64 *)(v1 + 14240);
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stxr(v23 | 0x20000, _X8) );
    }
  }
  return result;
}
