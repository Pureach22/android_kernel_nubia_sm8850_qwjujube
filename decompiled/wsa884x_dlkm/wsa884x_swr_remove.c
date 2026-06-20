__int64 __fastcall wsa884x_swr_remove(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x8
  __int64 v4; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x8
  __int64 result; // x0

  if ( a1 && (v2 = *(_QWORD *)(a1 + 224)) != 0 )
  {
    if ( *(_QWORD *)(v2 + 720) )
      proc_remove();
    v3 = *(_DWORD **)(v2 + 648);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v2 + 640);
      if ( *(v3 - 1) != -875060373 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v3)(v4, v2 + 616, 0);
    }
    debugfs_remove(*(_QWORD *)(v2 + 544));
    *(_QWORD *)(v2 + 544) = 0;
    snd_soc_unregister_component(a1 + 72);
    v5 = *(_QWORD **)(v2 + 696);
    if ( v5 )
    {
      kfree(*v5);
      kfree(*(_QWORD *)(*(_QWORD *)(v2 + 696) + 152LL));
      kfree(*(_QWORD *)(v2 + 696));
    }
    v6 = *(_QWORD **)(v2 + 704);
    if ( v6 )
    {
      kfree(*v6);
      kfree(*(_QWORD *)(v2 + 704));
    }
    msm_cdc_release_supplies(a1 + 72, *(_QWORD *)(v2 + 672), *(_QWORD *)(v2 + 656), *(unsigned int *)(v2 + 664));
    result = 0;
    *(_QWORD *)(a1 + 224) = 0;
  }
  else
  {
    dev_err(a1 + 72, "%s: wsa884x is NULL\n", "wsa884x_swr_remove");
    return 4294967274LL;
  }
  return result;
}
