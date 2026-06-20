__int64 __fastcall aw22xxx_rgb_show(__int64 a1, int a2, char *s)
{
  _DWORD *v3; // x21
  __int64 v5; // x23
  __int64 v6; // x23
  __int64 v7; // x23
  __int64 v8; // x23
  __int64 v9; // x23
  __int64 v10; // x23
  __int64 v11; // x23
  __int64 v12; // x23

  v3 = *(_DWORD **)(a1 + 152);
  v5 = snprintf(s, 0x1000u, "rgb[%d] = 0x%06x\n", 0, v3[191]);
  v6 = v5 + snprintf(&s[v5], 4096 - v5, "rgb[%d] = 0x%06x\n", 1, v3[192]);
  v7 = v6 + snprintf(&s[v6], 4096 - v6, "rgb[%d] = 0x%06x\n", 2, v3[193]);
  v8 = v7 + snprintf(&s[v7], 4096 - v7, "rgb[%d] = 0x%06x\n", 3, v3[194]);
  v9 = v8 + snprintf(&s[v8], 4096 - v8, "rgb[%d] = 0x%06x\n", 4, v3[195]);
  v10 = v9 + snprintf(&s[v9], 4096 - v9, "rgb[%d] = 0x%06x\n", 5, v3[196]);
  v11 = v10 + snprintf(&s[v10], 4096 - v10, "rgb[%d] = 0x%06x\n", 6, v3[197]);
  v12 = v11 + snprintf(&s[v11], 4096 - v11, "rgb[%d] = 0x%06x\n", 7, v3[198]);
  return v12 + snprintf(&s[v12], 4096 - v12, "rgb[%d] = 0x%06x\n", 8, v3[199]);
}
