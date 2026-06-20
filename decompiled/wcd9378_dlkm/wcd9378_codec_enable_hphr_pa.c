__int64 __fastcall wcd9378_codec_enable_hphr_pa(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x19
  void (__fastcall *v4)(__int64, __int64, __int64); // x8
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 v7; // x0
  __int64 virq; // x0
  __int64 v9; // x0
  void (__fastcall *v10)(__int64, __int64, __int64); // x8
  __int64 v11; // x0
  void (__fastcall *v12)(__int64, __int64, __int64); // x8
  __int64 v13; // x0
  unsigned __int64 v21; // x10

  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) - 184LL) + 152LL);
  if ( a3 == 8 )
  {
    mutex_lock(v3 + 232);
    _X8 = (unsigned __int64 *)(v3 + 16);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
    mutex_unlock(v3 + 232);
    if ( (*(_QWORD *)(v3 + 16) & 0x400) == 0 )
    {
      v10 = *(void (__fastcall **)(__int64, __int64, __int64))(v3 + 3232);
      if ( v10 )
      {
        v11 = *(_QWORD *)(v3 + 3224);
        if ( *((_DWORD *)v10 - 1) != -17866579 )
          __break(0x8228u);
        v10(v11, 1, 65537);
      }
      wcd_disable_irq(v3 + 408, 14);
    }
    v12 = *(void (__fastcall **)(__int64, __int64, __int64))(v3 + 3232);
    if ( v12 && *(_BYTE *)(v3 + 393) == 1 )
    {
      v13 = *(_QWORD *)(v3 + 3224);
      if ( *((_DWORD *)v12 - 1) != -17866579 )
        __break(0x8228u);
      v12(v13, 4, 0x10000);
    }
    blocking_notifier_call_chain(*(_QWORD *)(v3 + 336) + 976LL, 12);
  }
  else if ( a3 == 1 )
  {
    v4 = *(void (__fastcall **)(__int64, __int64, __int64))(v3 + 3232);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v3 + 3224);
      if ( *((_DWORD *)v4 - 1) != -17866579 )
        __break(0x8228u);
      v4(v5, 1, 65537);
      v6 = *(void (__fastcall **)(__int64, __int64, __int64))(v3 + 3232);
      if ( v6 )
      {
        v7 = *(_QWORD *)(v3 + 3224);
        if ( *((_DWORD *)v6 - 1) != -17866579 )
          __break(0x8228u);
        v6(v7, 1, 0x10000);
      }
    }
    virq = regmap_irq_get_virq(*(_QWORD *)(v3 + 432), 14);
    v9 = irq_to_desc(virq);
    if ( !v9 || *(_DWORD *)(v9 + 136) )
      wcd_enable_irq(v3 + 408, 14);
  }
  return 0;
}
