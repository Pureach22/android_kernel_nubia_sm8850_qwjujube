__int64 __fastcall mon_disable(__int64 result)
{
  int v1; // w9
  int v2; // w20
  __int64 v3; // x20
  unsigned int v4; // w0
  unsigned int *v5; // x1
  __int64 v6; // x8
  int v7; // w0

  if ( (unsigned int)result >= 0x20 )
  {
    __break(0x5512u);
    return mon_clear(result);
  }
  v1 = *(_DWORD *)(llccpmu + 1456);
  if ( v1 > 1 )
  {
    v2 = phys_cpu[(unsigned int)result];
    if ( v1 != 2 )
    {
      if ( v1 != 3 )
        return result;
      v3 = 4 * v2;
      v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(llccpmu + 328) + v3 + 768)) & 0xFFFFFFFE;
      v5 = (unsigned int *)(*(_QWORD *)(llccpmu + 328) + v3 + 768);
      return writel_relaxed(v4, v5);
    }
    v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(llccpmu + 328) + 512LL));
    v6 = *(_QWORD *)(llccpmu + 328);
    v4 = v7 & ~(1 << v2);
LABEL_9:
    v5 = (unsigned int *)(v6 + 512);
    return writel_relaxed(v4, v5);
  }
  if ( v1 == 1 )
  {
    v6 = *(_QWORD *)(llccpmu + 328);
    v4 = 0;
    goto LABEL_9;
  }
  if ( !v1 )
    return printk(&unk_6F54);
  return result;
}
