__int64 __fastcall _arm_tbu_micro_idle_cfg(const char ***a1, unsigned int a2, int a3)
{
  __int64 v6; // x0
  const char **v7; // x8
  __int64 v8; // x20
  const char *v9; // x8
  int v10; // w0
  const char **v11; // x8
  int v12; // w23
  const char *v13; // x8
  char *v14; // x24
  int v15; // w0
  int v16; // w8
  __int64 v17; // x25
  unsigned int v18; // w21
  int v19; // w22
  const char *v20; // x0
  const char *v21; // x2

  v6 = raw_spin_lock_irqsave(a1 + 28);
  v7 = a1[6];
  v8 = v6;
  if ( v7 && (v9 = *v7) != nullptr )
  {
    if ( *((_DWORD *)v9 - 1) != 616069899 )
      __break(0x8228u);
    v10 = ((__int64 (__fastcall *)(const char ***, __int64, __int64))v9)(a1, 7, 1528);
  }
  else
  {
    v10 = readl_relaxed_1((char *)a1[1] + (7 << *((_DWORD *)a1 + 7)) + 1528);
  }
  v11 = a1[6];
  v12 = v10 & ~a3;
  if ( v11 && (v13 = v11[1]) != nullptr )
  {
    if ( *((_DWORD *)v13 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(const char ***, __int64, __int64, _QWORD))v13)(a1, 7, 1528, v12 | a2);
  }
  else
  {
    writel_relaxed_1(v12 | a2, (char *)a1[1] + (7 << *((_DWORD *)a1 + 7)) + 1528);
  }
  v14 = (char *)a1[1] + (7 << *((_DWORD *)a1 + 7));
  v15 = readl_0(v14 + 1532);
  v16 = v15 & a3;
  if ( (v15 & a3) != a2 )
  {
    v17 = 200001;
    while ( --v17 >= 0 )
    {
      __yield();
      if ( ((unsigned int)readl_0(v14 + 1532) & a3) == a2 )
        goto LABEL_14;
    }
    v15 = readl_0(v14 + 1532);
    v16 = v15 & a3;
  }
  if ( v16 == a2 )
  {
LABEL_14:
    v18 = 0;
  }
  else
  {
    v19 = v15;
    v20 = (const char *)dev_driver_string(*a1);
    v21 = (*a1)[14];
    if ( !v21 )
      v21 = **a1;
    _warn_printk("%s %s: Timed out configuring micro idle! %x instead of %x\n", v20, v21, v19, v12 | a2);
    v18 = -110;
    __break(0x800u);
  }
  _const_udelay(21475);
  raw_spin_unlock_irqrestore(a1 + 28, v8);
  return v18;
}
