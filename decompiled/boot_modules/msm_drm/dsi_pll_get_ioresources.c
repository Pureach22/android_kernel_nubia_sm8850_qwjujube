__int64 __fastcall dsi_pll_get_ioresources(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v5; // x0

  if ( !platform_get_resource_byname(a1, 512, a3) )
    return 0;
  if ( a2 && (v5 = devm_ioremap(a1 + 16), (*a2 = v5) != 0) )
    return 0;
  else
    return 4294967284LL;
}
