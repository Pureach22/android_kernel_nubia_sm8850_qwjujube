__int64 __fastcall gx_clkctl_canoe_probe(__int64 a1)
{
  int v2; // w0
  unsigned __int64 v3; // x20
  unsigned int v5; // w8
  unsigned int v12; // w10

  pm_runtime_enable(a1 + 16);
  v2 = _pm_runtime_resume(a1 + 16, 4);
  if ( v2 < 0 )
  {
    v5 = *(_DWORD *)(a1 + 496);
    LODWORD(v3) = v2;
    do
    {
      if ( !v5 )
        break;
      _X12 = (unsigned int *)(a1 + 496);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v12 = __ldxr(_X12);
        if ( v12 != v5 )
          break;
        if ( !__stlxr(v5 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v12 == v5;
      v5 = v12;
    }
    while ( !_ZF );
  }
  else
  {
    v3 = qcom_cc_map(a1, &gx_clkctl_canoe_desc);
    if ( v3 < 0xFFFFFFFFFFFFF001LL )
    {
      LODWORD(v3) = qcom_cc_really_probe(a1 + 16, &gx_clkctl_canoe_desc, v3);
      if ( (_DWORD)v3 )
        dev_err_probe(a1 + 16, (unsigned int)v3, "Failed to register GX CLKCTL\n");
      else
        dev_info(a1 + 16, "Registered GX CLKCTL clocks\n");
    }
    _pm_runtime_idle(a1 + 16, 5);
  }
  return (unsigned int)v3;
}
