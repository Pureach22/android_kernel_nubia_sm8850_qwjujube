__int64 __fastcall dwc3_core_send_gadget_ep_cmd(__int64 a1, int a2, unsigned int *a3)
{
  __int64 v3; // x24
  __int64 v4; // x25
  __int64 v8; // x22
  int v9; // w0
  int v10; // w8
  int v11; // w23
  unsigned int v12; // w20
  int v13; // w25
  __int64 v14; // x0
  __int64 v15; // x1
  unsigned int v17; // w21
  const char *v18; // x0
  const char **v19; // x8
  const char *v20; // x2
  const char *v21; // x0
  const char **v22; // x8
  const char *v23; // x2
  __int64 v24; // x8
  int v25; // w0

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_QWORD *)(a1 + 24);
  v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 368) + 96LL) + 152LL);
  if ( *(_DWORD *)(*(_QWORD *)(v3 + 848) + 72LL) > 3u )
  {
    v11 = 0;
  }
  else
  {
    v9 = readl(*(_QWORD *)(v8 + 8) + 49664LL);
    if ( (v9 & 0x40) != 0 )
    {
      v9 &= ~0x40u;
      v10 = 64;
    }
    else
    {
      v10 = 0;
    }
    v11 = v9 & 0x100 | v10;
    if ( v11 )
      writel(v9 & 0xFFFFFEFF, *(_QWORD *)(v8 + 8) + 49664LL);
  }
  writel_relaxed(a3[2], *(_QWORD *)(a1 + 128) - 49400LL);
  __dsb(0xFu);
  writel_relaxed(a3[1], *(_QWORD *)(a1 + 128) - 49404LL);
  __dsb(0xFu);
  writel_relaxed(*a3, *(_QWORD *)(a1 + 128) - 49408LL);
  __dsb(0xFu);
  if ( (a2 & 0xF) == 7 && (*(_BYTE *)(v4 + 3) & 3) != 1 )
    v12 = a2 & 0x7FFFFAF7;
  else
    v12 = a2 | 0x400;
  writel_relaxed(v12, *(_QWORD *)(a1 + 128) - 49396LL);
  __dsb(0xFu);
  v13 = -5000;
  while ( 1 )
  {
    v14 = readl_relaxed(*(_QWORD *)(a1 + 128) - 49396LL);
    if ( (v14 & 0x400) == 0 )
      break;
    if ( __CFADD__(v13++, 1) )
    {
      v17 = -110;
      goto LABEL_27;
    }
  }
  v17 = (unsigned __int16)v14 >> 12;
  if ( (unsigned __int16)v14 >> 12 )
  {
    if ( v17 == 2 )
    {
      v17 = -11;
    }
    else
    {
      if ( v17 == 1 )
      {
        v18 = (const char *)dev_driver_string(*(_QWORD *)(v3 + 368));
        v19 = *(const char ***)(v3 + 368);
        v20 = v19[14];
        if ( !v20 )
          v20 = *v19;
        v14 = _warn_printk("%s %s: No resource for %s\n", v18, v20, (const char *)(a1 + 184));
        __break(0x800u);
      }
      else
      {
        v21 = (const char *)dev_driver_string(*(_QWORD *)(v3 + 368));
        v22 = *(const char ***)(v3 + 368);
        v23 = v22[14];
        if ( !v23 )
          v23 = *v22;
        v14 = _warn_printk("%s %s: UNKNOWN cmd status\n", v21, v23);
        __break(0x800u);
      }
      v17 = -22;
    }
  }
LABEL_27:
  if ( (v12 & 0xF) == 6 && v17 != -110 )
  {
    if ( !v17 )
    {
      if ( *(unsigned __int8 *)(a1 + 170) >= 0x20uLL )
      {
        __break(0x5512u);
        return writel_relaxed(v14, v15);
      }
      v24 = v8 + 40LL * *(unsigned __int8 *)(a1 + 170);
      if ( *(_DWORD *)(v24 + 1280) == 2 )
        *(_QWORD *)(v24 + 1304) |= 1uLL;
      else
        *(_DWORD *)(a1 + 164) |= 8u;
    }
    *(_BYTE *)(a1 + 172) = ((unsigned int)readl_relaxed(*(_QWORD *)(a1 + 128) - 49396LL) >> 16) & 0x7F;
  }
  if ( v11 )
  {
    v25 = readl(*(_QWORD *)(v8 + 8) + 49664LL);
    writel(v25 | (unsigned int)v11, *(_QWORD *)(v8 + 8) + 49664LL);
  }
  return v17;
}
