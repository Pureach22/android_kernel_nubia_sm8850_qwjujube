__int64 __fastcall rpmh_rsc_is_tcs_completed(_QWORD *a1, int a2)
{
  int v4; // w21
  int v5; // w3

  if ( a2 )
    v4 = 4;
  else
    v4 = 1;
  if ( ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0 )
    goto LABEL_13;
  _const_udelay(42950);
  if ( ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0
    || (_const_udelay(42950),
        ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0)
    || (_const_udelay(42950),
        ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0)
    || (_const_udelay(42950),
        ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0)
    || (_const_udelay(42950),
        ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0)
    || (_const_udelay(42950),
        ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0)
    || (_const_udelay(42950),
        ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0)
    || (_const_udelay(42950),
        ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) != 0) )
  {
LABEL_13:
    writel_relaxed(0x80000000, (unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL)));
    v5 = 0;
  }
  else
  {
    _const_udelay(42950);
    if ( ((unsigned int)readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(a1[208] + 68LL))) & v4) == 0 )
      _const_udelay(42950);
    v5 = -16;
  }
  ipc_log_string(a1[209], "channel switched to: %d ret: %d", a2, v5);
  return 0;
}
