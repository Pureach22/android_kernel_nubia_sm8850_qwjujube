__int64 __fastcall arm_smmu_device_shutdown(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x20
  __int64 v6; // x8
  _DWORD *v7; // x8
  __int64 v8; // x0
  __int64 v9; // x20
  unsigned int v11; // w8
  unsigned int v18; // w10

  v1 = *(_QWORD **)(a1 + 168);
  if ( find_first_bit(v1 + 8, 128) == 128 )
  {
    v3 = v1[6];
    if ( !v3 )
      goto LABEL_7;
  }
  else
  {
    dev_notice(a1 + 16, "disabling translation\n");
    v3 = v1[6];
    if ( !v3 )
      goto LABEL_7;
  }
  v4 = *(void (__fastcall **)(_QWORD))(v3 + 80);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != -874862150 )
      __break(0x8228u);
    v4(v1);
  }
LABEL_7:
  v5 = *v1;
  if ( (*(_WORD *)(*v1 + 488LL) & 7) == 0 && (_pm_runtime_resume(*v1, 4) & 0x80000000) != 0 )
  {
    v11 = *(_DWORD *)(v5 + 480);
    do
    {
      if ( !v11 )
        break;
      _X12 = (unsigned int *)(v5 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v18 = __ldxr(_X12);
        if ( v18 != v11 )
          break;
        if ( !__stlxr(v11 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v18 == v11;
      v11 = v18;
    }
    while ( !_ZF );
  }
  v6 = v1[6];
  if ( v6 && (v7 = *(_DWORD **)(v6 + 8)) != nullptr )
  {
    if ( *(v7 - 1) != -1008624849 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, __int64))v7)(v1, 0, 0, 1);
  }
  else
  {
    v8 = writel_relaxed_0(1u, (unsigned int *)v1[1]);
  }
  if ( (*(_WORD *)(*v1 + 488LL) & 7) != 0
    || (v9 = *v1,
        *(_QWORD *)(v9 + 520) = ktime_get_mono_fast_ns(v8),
        _pm_runtime_suspend(*v1, 13),
        (*(_WORD *)(*v1 + 488LL) & 7) != 0) )
  {
    clk_bulk_disable(*((unsigned int *)v1 + 51), v1[27]);
    arm_smmu_power_off(v1, v1[38]);
  }
  else
  {
    pm_runtime_force_suspend(*v1);
  }
  return clk_bulk_unprepare(*((unsigned int *)v1 + 51), v1[27]);
}
