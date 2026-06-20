__int64 __fastcall a6xx_reset(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 resource_byname; // x0
  int v7; // w0
  int v8; // w20
  unsigned __int64 v15; // x10

  v1 = *(_QWORD *)(a1 + 9136);
  result = a6xx_clear_pending_transactions();
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 9136) = 0;
    kgsl_pwrctrl_change_state(a1, 1);
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
    a6xx_reset_preempt_records(a1);
    result = adreno_start(a1, 0);
    if ( !(_DWORD)result )
    {
      kgsl_pwrctrl_change_state(a1, 2);
      v4 = *(_QWORD *)(a1 + 14264);
      *(_QWORD *)(a1 + 9136) = v1;
      if ( *(_BYTE *)(v4 + 177) != 1 )
        goto LABEL_9;
      v5 = a6xx_gx_cpr_toggle_gx_cpr_virt;
      if ( !a6xx_gx_cpr_toggle_gx_cpr_virt )
      {
        resource_byname = platform_get_resource_byname(*(_QWORD *)(a1 + 11168), 512, "gx_cpr");
        if ( !resource_byname )
          goto LABEL_9;
        v5 = devm_ioremap_resource(*(_QWORD *)(a1 + 11168) + 16LL, resource_byname);
        a6xx_gx_cpr_toggle_gx_cpr_virt = v5;
        if ( !v5 )
        {
          dev_err(*(_QWORD *)a1, "Failed to map GX CPR\n");
          if ( *(_DWORD *)(a1 + 11128) )
            return 0;
          goto LABEL_10;
        }
      }
      v7 = readl_relaxed(v5 + 4);
      __dsb(0xDu);
      v8 = v7;
      writel_relaxed(v7 & 0xFFFFFFF0, a6xx_gx_cpr_toggle_gx_cpr_virt + 4);
      __dsb(0xEu);
      _const_udelay(21475);
      writel_relaxed(v8 | 1u, a6xx_gx_cpr_toggle_gx_cpr_virt + 4);
      __dsb(0xEu);
LABEL_9:
      if ( *(_DWORD *)(a1 + 11128) )
        return 0;
LABEL_10:
      kgsl_pwrctrl_change_state(a1, 128);
      return 0;
    }
  }
  return result;
}
