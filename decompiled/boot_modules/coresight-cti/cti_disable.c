__int64 __fastcall cti_disable(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  int v3; // w8
  int v4; // w8
  char v5; // w8
  unsigned int *v6; // x8
  unsigned int v7; // w19

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  v2 = *(_QWORD *)(v1 + 8);
  raw_spin_lock(v1 + 56);
  v3 = *(_DWORD *)(v1 + 72);
  if ( v3 )
  {
    v4 = v3 - 1;
    *(_DWORD *)(v1 + 72) = v4;
    if ( v4 <= 0 && *(_BYTE *)(v1 + 76) == 1 && *(_BYTE *)(v1 + 77) == 1 )
    {
      writel_relaxed(0xC5ACCE55, (unsigned int *)(*(_QWORD *)v1 + 4016LL));
      __dsb(0xFu);
      writel_relaxed(0, *(unsigned int **)v1);
      v5 = *(_BYTE *)(v1 + 1200);
      *(_BYTE *)(v1 + 76) = 0;
      if ( (v5 & 1) == 0 )
        coresight_disclaim_device_unlocked(v2);
      v6 = *(unsigned int **)v1;
      __dsb(0xFu);
      writel_relaxed(0, v6 + 1004);
    }
    v7 = 0;
  }
  else
  {
    v7 = -22;
  }
  raw_spin_unlock(v1 + 56);
  return v7;
}
