__int64 __fastcall kgsl_set_thermal_constraint(__int64 a1)
{
  _DWORD *v2; // x8
  void (__fastcall *v3)(_QWORD); // x8

  rt_mutex_lock(a1 + 120);
  v2 = *(_DWORD **)(*(_QWORD *)(a1 - 2216) + 304LL);
  if ( *(v2 - 1) != -227291694 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v2)(a1 - 10968, 0, 0) )
  {
    if ( *(_DWORD *)(a1 - 20) != 255 )
    {
      v3 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 2216) + 312LL);
      if ( *((_DWORD *)v3 - 1) != 1058568764 )
        __break(0x8228u);
      v3(a1 - 10968);
    }
    if ( *(_DWORD *)(a1 + 152) == 2 )
      kgsl_pwrctrl_pwrlevel_change(a1 - 10968);
  }
  return rt_mutex_unlock(a1 + 120);
}
