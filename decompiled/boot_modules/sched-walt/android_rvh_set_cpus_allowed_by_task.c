void __fastcall android_rvh_set_cpus_allowed_by_task(__int64 a1, _DWORD *a2, _QWORD *a3, __int64 a4, _DWORD *a5)
{
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (walt_disabled & 1) == 0
    && (*(_BYTE *)(a4 + 70) & 0x20) == 0
    && ((*(unsigned __int64 *)((char *)&_cpu_halt_mask + (((unsigned __int64)(unsigned int)*a5 >> 3) & 0x1FFFFFF8)) >> *a5)
      & 1) != 0
    && !*(_WORD *)(a4 + 1408)
    && ((*(_QWORD *)a4 & 0x400000) == 0 || (*(_WORD *)(a4 + 1728) & 4) == 0) )
  {
    v5[0] = *a3 & *a2 & (unsigned int)~(_DWORD)_cpu_halt_mask;
    if ( v5[0] )
      *a5 = cpumask_any_and_distribute(v5, a3);
  }
  _ReadStatusReg(SP_EL0);
}
