__int64 __fastcall dwc3_msm_host_ss_powerup(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 result; // x0
  __int64 v6; // x8
  _DWORD *v7; // x8
  __int64 v8; // x0
  void (*v9)(void); // x8
  void (*v10)(void); // x8
  __int64 v11; // x20
  int v12; // w0
  int v13; // w0
  __int64 v14; // x20
  int v15; // w0
  int v16; // w0

  v2 = *(_QWORD *)(a1 + 40);
  v3 = *(_QWORD *)(a1 + 1256);
  if ( v2 )
    v4 = (_DWORD *)(*(_QWORD *)(v2 + 168) + 1232LL);
  else
    v4 = (_DWORD *)(a1 + 1128);
  result = ipc_log_string(v3, "%s: start: speed:%d\n", "dwc3_msm_host_ss_powerup", *v4);
  if ( *(_BYTE *)(a1 + 759) == 1 && *(_BYTE *)(a1 + 736) == 1 && (*(_BYTE *)(a1 + 758) & 1) == 0 )
  {
    v6 = *(_QWORD *)(a1 + 40);
    v7 = (_DWORD *)(v6 ? *(_QWORD *)(v6 + 168) + 1232LL : a1 + 1128);
    if ( *v7 >= 5u )
    {
      v8 = *(_QWORD *)(a1 + 456);
      if ( v8 )
      {
        v9 = *(void (**)(void))(v8 + 296);
        if ( !v9 )
          goto LABEL_16;
        if ( *((_DWORD *)v9 - 1) != 711694717 )
          __break(0x8228u);
        v9();
        v8 = *(_QWORD *)(a1 + 456);
        if ( v8 )
        {
LABEL_16:
          v10 = *(void (**)(void))(v8 + 312);
          if ( v10 )
          {
            if ( *((_DWORD *)v10 - 1) != -1429527844 )
              __break(0x8228u);
            v10();
          }
        }
      }
      phy_init(*(_QWORD *)(a1 + 480));
      phy_power_on(*(_QWORD *)(a1 + 480));
      v11 = *(_QWORD *)(a1 + 8);
      v12 = readl((unsigned int *)(v11 + 1017864));
      writel(v12 | 0x100, (unsigned int *)(v11 + 1017864));
      _const_udelay(21475);
      v13 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 1017864LL));
      writel(v13 & 0xFFFFFFF6, (unsigned int *)(*(_QWORD *)(a1 + 8) + 1017864LL));
      _const_udelay(21475);
      v14 = *(_QWORD *)(a1 + 8);
      v15 = readl((unsigned int *)(v14 + 1017864));
      writel(v15 & 0xFFFFFEFF, (unsigned int *)(v14 + 1017864));
      v16 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 1018340LL));
      result = writel(v16 & 0xFFFFFFDF, (unsigned int *)(*(_QWORD *)(a1 + 8) + 1018340LL));
      *(_BYTE *)(a1 + 759) = 0;
    }
  }
  return result;
}
