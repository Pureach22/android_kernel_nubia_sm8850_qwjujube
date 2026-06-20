__int64 __fastcall dwc3_msm_host_ss_powerdown(__int64 result)
{
  __int64 v1; // x8
  _DWORD *v2; // x8
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x20
  int v6; // w0
  int v7; // w0
  __int64 v8; // x20
  int v9; // w0
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x0
  void (__fastcall *v13)(__int64, __int64); // x9
  void (__fastcall *v14)(__int64, __int64); // x9
  __int64 v15; // x19

  if ( (*(_BYTE *)(result + 759) & 1) == 0 && (*(_BYTE *)(result + 758) & 1) == 0 && *(_DWORD *)(result + 2572) == 1 )
  {
    v1 = *(_QWORD *)(result + 40);
    v2 = (_DWORD *)(v1 ? *(_QWORD *)(v1 + 168) + 1232LL : result + 1128);
    if ( *v2 >= 5u )
    {
      v3 = result;
      v4 = readl((unsigned int *)(*(_QWORD *)(result + 8) + 1018340LL));
      writel(v4 | 0x20, (unsigned int *)(*(_QWORD *)(v3 + 8) + 1018340LL));
      v5 = *(_QWORD *)(v3 + 8);
      v6 = readl((unsigned int *)(v5 + 1017864));
      writel(v6 | 0x100, (unsigned int *)(v5 + 1017864));
      _const_udelay(21475);
      v7 = readl((unsigned int *)(*(_QWORD *)(v3 + 8) + 1017864LL));
      writel(v7 | 9, (unsigned int *)(*(_QWORD *)(v3 + 8) + 1017864LL));
      _const_udelay(21475);
      v8 = *(_QWORD *)(v3 + 8);
      v9 = readl((unsigned int *)(v8 + 1017864));
      writel(v9 & 0xFFFFFEFF, (unsigned int *)(v8 + 1017864));
      v10 = *(_QWORD *)(v3 + 456);
      v11 = v3;
      if ( v10 )
      {
        *(_DWORD *)(v10 + 16) |= 0x800u;
        v12 = *(_QWORD *)(v3 + 456);
        if ( v12 )
        {
          v13 = *(void (__fastcall **)(__int64, __int64))(v12 + 320);
          if ( !v13 )
            goto LABEL_14;
          if ( *((_DWORD *)v13 - 1) != -1429527844 )
            __break(0x8229u);
          v13(v12, 5);
          v12 = *(_QWORD *)(v3 + 456);
          v11 = v3;
          if ( v12 )
          {
LABEL_14:
            v14 = *(void (__fastcall **)(__int64, __int64))(v12 + 296);
            if ( !v14 )
              goto LABEL_18;
            if ( *((_DWORD *)v14 - 1) != 711694717 )
              __break(0x8229u);
            v14(v12, 1);
            v12 = *(_QWORD *)(v3 + 456);
            v11 = v3;
            if ( v12 )
LABEL_18:
              *(_DWORD *)(v12 + 16) &= ~0x800u;
          }
        }
      }
      v15 = v11;
      phy_power_off(*(_QWORD *)(v11 + 480));
      result = phy_exit(*(_QWORD *)(v15 + 480));
      *(_BYTE *)(v15 + 759) = 1;
    }
  }
  return result;
}
