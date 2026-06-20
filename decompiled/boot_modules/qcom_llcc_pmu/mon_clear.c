__int64 __fastcall mon_clear(__int64 result)
{
  unsigned int *v1; // x19
  int v2; // w9
  int v3; // w10
  __int64 v4; // x21
  int v5; // w19
  int v6; // w0
  unsigned int *v7; // x1
  __int64 v8; // x8
  int v9; // w21
  int v10; // w19

  if ( (unsigned int)result >= 0x20 )
  {
    __break(0x5512u);
    atomic_load(v1);
    JUMPOUT(0x6B68);
  }
  v2 = *(_DWORD *)(llccpmu + 1456);
  if ( v2 > 1 )
  {
    v3 = phys_cpu[(unsigned int)result];
    if ( v2 != 2 )
    {
      if ( v2 != 3 )
        return result;
      v4 = 4 * v3;
      v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(llccpmu + 328) + v4 + 768));
      writel_relaxed(v5 | 0x10, (unsigned int *)(*(_QWORD *)(llccpmu + 328) + v4 + 768));
      v6 = v5 & 0xFFFFFFEF;
      v7 = (unsigned int *)(*(_QWORD *)(llccpmu + 328) + v4 + 768);
      return writel_relaxed(v6, v7);
    }
    v9 = 1 << (v3 + 16);
    v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(llccpmu + 328) + 512LL));
    writel_relaxed(v10 | v9, (unsigned int *)(*(_QWORD *)(llccpmu + 328) + 512LL));
    v6 = v10 & ~v9;
    v8 = *(_QWORD *)(llccpmu + 328);
LABEL_9:
    v7 = (unsigned int *)(v8 + 512);
    return writel_relaxed(v6, v7);
  }
  if ( v2 == 1 )
  {
    v8 = *(_QWORD *)(llccpmu + 328);
    v6 = 16;
    goto LABEL_9;
  }
  if ( !v2 )
    return printk(&unk_6F54);
  return result;
}
