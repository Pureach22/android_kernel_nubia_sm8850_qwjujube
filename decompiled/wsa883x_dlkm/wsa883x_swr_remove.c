__int64 __fastcall wsa883x_swr_remove(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x8
  __int64 v4; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x8
  __int64 result; // x0

  if ( a1 && (v2 = *(_QWORD *)(a1 + 224)) != 0 )
  {
    if ( *(_QWORD *)(v2 + 408) )
      proc_remove();
    wcd_free_irq(v2 + 216, 0, 0);
    wcd_free_irq(v2 + 216, 1, 0);
    wcd_free_irq(v2 + 216, 2, 0);
    wcd_free_irq(v2 + 216, 3, 0);
    wcd_free_irq(v2 + 216, 4, 0);
    wcd_free_irq(v2 + 216, 5, 0);
    wcd_free_irq(v2 + 216, 6, 0);
    wcd_free_irq(v2 + 216, 7, 0);
    wcd_free_irq(v2 + 216, 8, 0);
    wcd_free_irq(v2 + 216, 9, 0);
    v3 = *(_DWORD **)(v2 + 344);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v2 + 336);
      if ( *(v3 - 1) != -875060373 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v3)(v4, v2 + 312, 0);
    }
    debugfs_remove(*(_QWORD *)(v2 + 256));
    *(_QWORD *)(v2 + 256) = 0;
    snd_soc_unregister_component(a1 + 72);
    v5 = *(_QWORD **)(v2 + 384);
    if ( v5 )
    {
      kfree(*v5);
      kfree(*(_QWORD *)(*(_QWORD *)(v2 + 384) + 152LL));
      kfree(*(_QWORD *)(v2 + 384));
    }
    v6 = *(_QWORD **)(v2 + 392);
    if ( v6 )
    {
      kfree(*v6);
      kfree(*(_QWORD *)(v2 + 392));
    }
    msm_cdc_release_supplies(a1 + 72, *(_QWORD *)(v2 + 368), *(_QWORD *)(v2 + 352), *(unsigned int *)(v2 + 360));
    result = 0;
    *(_QWORD *)(a1 + 224) = 0;
  }
  else
  {
    dev_err(a1 + 72, "%s: wsa883x is NULL\n", "wsa883x_swr_remove");
    return 4294967274LL;
  }
  return result;
}
