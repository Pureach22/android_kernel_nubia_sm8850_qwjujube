__int64 __fastcall kgsl_regmap_poll_read(__int64 a1, int a2, _DWORD *a3)
{
  __int64 result; // x0

  if ( a1 )
  {
    *a3 = readl_relaxed_0((unsigned int *)(*(_QWORD *)a1 + (unsigned int)(4 * (a2 - *(_DWORD *)(a1 + 8)))));
    result = 0;
    __dsb(0xDu);
  }
  else
  {
    _warn_printk("Out of bounds poll read: 0x%x\n", a2);
    __break(0x800u);
    return 4294967277LL;
  }
  return result;
}
