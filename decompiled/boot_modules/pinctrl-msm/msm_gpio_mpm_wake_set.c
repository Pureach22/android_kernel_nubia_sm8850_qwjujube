__int64 __fastcall msm_gpio_mpm_wake_set(unsigned int a1, char a2)
{
  __int64 v3; // x22
  __int64 v4; // x19
  unsigned int v5; // w0
  unsigned __int64 v6; // x8
  int v7; // w8
  unsigned int v8; // w10
  unsigned int v9; // w8
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x9
  unsigned int v13; // w10
  unsigned int v14; // w9
  __int64 v15; // x0

  v3 = *(_QWORD *)(*(_QWORD *)(msm_pinctrl_data + 968) + 32LL) + 112LL * a1;
  if ( *(_DWORD *)(v3 + 104) == -1 && (*(_WORD *)(v3 + 92) & 0x7C0) == 0 )
    return 4294967294LL;
  v4 = raw_spin_lock_irqsave(msm_pinctrl_data + 764);
  v5 = readl(*(_QWORD *)(msm_pinctrl_data + 8 * ((*(_QWORD *)(v3 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v3 + 68));
  v6 = *(_QWORD *)(v3 + 92);
  if ( ((v5 >> ((v6 >> 6) & 0x1F)) & 1) != 0 )
  {
    v7 = 1 << (v6 >> 11);
    v8 = v5 | v7;
    v9 = v5 & ~v7;
    if ( (a2 & 1) != 0 )
      v10 = v8;
    else
      v10 = v9;
    writel(
      v10,
      *(_QWORD *)(msm_pinctrl_data + 8 * ((*(_QWORD *)(v3 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v3 + 68));
  }
  else
  {
    v11 = readl_relaxed(*(_QWORD *)(msm_pinctrl_data + 8 * ((*(_QWORD *)(v3 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v3 + 100));
    v12 = 1LL << *(_DWORD *)(v3 + 104);
    v13 = v11 | v12;
    v14 = v11 & ~(_DWORD)v12;
    if ( (a2 & 1) != 0 )
      v15 = v13;
    else
      v15 = v14;
    writel_relaxed(
      v15,
      *(_QWORD *)(msm_pinctrl_data + 8 * ((*(_QWORD *)(v3 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v3 + 100));
  }
  raw_spin_unlock_irqrestore(msm_pinctrl_data + 764, v4);
  return 0;
}
