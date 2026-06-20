__int64 __fastcall flush_status_show(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE *v4; // x21
  unsigned int v5; // w20

  v4 = *(_BYTE **)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v4 + 24);
  if ( (v4[32] & 1) != 0 )
  {
    v5 = readl_relaxed((unsigned int *)(*(_QWORD *)v4 + 8LL));
    raw_spin_unlock(v4 + 24);
    return (int)scnprintf(a3, 4096, "%lx\n", (v5 >> 2) & 1);
  }
  else
  {
    raw_spin_unlock(v4 + 24);
    return -1;
  }
}
