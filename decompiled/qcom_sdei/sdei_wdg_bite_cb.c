__int64 __fastcall sdei_wdg_bite_cb(unsigned int a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x1
  __int64 v5; // x2
  char v6; // w10
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x10
  __int64 v9; // x11
  __int64 v15; // x1
  __int64 v16; // x2
  int v17; // w8
  char v18; // w9
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  printk(&unk_65E8, a1);
  v6 = 0;
  do
  {
    v7 = (unsigned int)(-1LL << v6) & _cpu_possible_mask;
    if ( !(_DWORD)v7 )
      break;
    v4 = 0;
    v8 = __clz(__rbit64(v7));
    v9 = _per_cpu_offset[v8];
    v6 = v8 + 1;
    v5 = *(_QWORD *)((char *)&cpu_mpidr + v9);
    __asm { HVC             #0 }
  }
  while ( !_CF );
  show_regs(a2, v4, v5);
  v17 = _cpu_possible_mask;
  v18 = 0;
  do
  {
    v19 = (unsigned int)(-1LL << v18) & v17;
    if ( !(_DWORD)v19 )
      break;
    v20 = __clz(__rbit64(v19));
    if ( *(_DWORD *)(StatusReg + 40) != (_DWORD)v20 )
    {
      show_regs((char *)&regs_before_sdei + _per_cpu_offset[v20], v15, v16);
      v17 = _cpu_possible_mask;
    }
    v18 = v20 + 1;
  }
  while ( v20 < 0x1F );
  return 0;
}
