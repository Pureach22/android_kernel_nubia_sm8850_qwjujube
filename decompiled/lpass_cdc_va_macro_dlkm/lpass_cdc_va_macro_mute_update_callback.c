__int64 __fastcall lpass_cdc_va_macro_mute_update_callback(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8

  v1 = *(_QWORD *)(a1 - 16);
  snd_soc_component_update_bits(*(_QWORD *)(v1 + 168), ((*(_DWORD *)(a1 - 8) << 7) + 13312) & 0xFF80, 16, 0);
  mutex_lock(v1 + 120);
  v2 = *(_DWORD *)(v1 + 1584) - 1;
  *(_DWORD *)(v1 + 1584) = v2;
  if ( !v2 )
  {
    pm_relax(*(_QWORD *)v1);
    if ( (*(_DWORD *)(v1 + 1584) & 0x80000000) == 0 )
      return mutex_unlock(v1 + 120);
LABEL_5:
    *(_DWORD *)(v1 + 1584) = 0;
    return mutex_unlock(v1 + 120);
  }
  if ( v2 < 0 )
    goto LABEL_5;
  return mutex_unlock(v1 + 120);
}
