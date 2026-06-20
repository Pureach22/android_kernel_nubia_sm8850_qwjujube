__int64 __fastcall sysfs_show_max_mapped(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  _QWORD *v5; // x20
  __int64 v6; // x19
  __int64 pagetable; // x0
  int v14; // w8
  unsigned int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v3 = *a1, v16 = 0, !(unsigned int)kstrtouint(v3, 0, &v16)) )
  {
    pagetable = kgsl_get_pagetable(v16);
    v5 = (_QWORD *)pagetable;
    if ( pagetable )
    {
      v6 = (int)scnprintf(a3, 4096, "%llu\n", *(_QWORD *)(pagetable + 88));
      goto LABEL_5;
    }
  }
  else
  {
    v5 = nullptr;
  }
  v6 = 0;
LABEL_5:
  _X0 = (unsigned int *)v5 + 1;
  __asm { PRFM            #0x11, [X0] }
  do
    v14 = __ldxr(_X0);
  while ( __stlxr(v14 - 1, _X0) );
  if ( v14 == 1 )
  {
    __dmb(9u);
    kgsl_mmu_detach_pagetable(v5);
    queue_work_on(32, qword_3A900, v5 + 5);
  }
  else if ( v14 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
