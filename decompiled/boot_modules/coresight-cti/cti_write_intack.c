__int64 __fastcall cti_write_intack(__int64 a1, unsigned int a2)
{
  _BYTE *v3; // x20
  __int64 v4; // x8

  v3 = *(_BYTE **)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v3 + 56);
  if ( v3[77] == 1 && v3[76] == 1 )
  {
    writel_relaxed(0xC5ACCE55, (unsigned int *)(*(_QWORD *)v3 + 4016LL));
    __dsb(0xFu);
    writel_relaxed(a2, (unsigned int *)(*(_QWORD *)v3 + 16LL));
    v4 = *(_QWORD *)v3;
    __dsb(0xFu);
    writel_relaxed(0, (unsigned int *)(v4 + 4016));
  }
  return raw_spin_unlock(v3 + 56);
}
