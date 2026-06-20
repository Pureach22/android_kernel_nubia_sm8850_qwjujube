__int64 __fastcall qcom_llcc_event_del(__int64 a1)
{
  unsigned int v2; // w0
  int v3; // w8
  int v4; // w22

  raw_spin_lock(&users_lock);
  if ( *(_DWORD *)(llccpmu + 1456) == 1 )
  {
    if ( !--users )
      mon_disable(*(unsigned int *)(a1 + 668));
    return raw_spin_unlock(&users_lock);
  }
  v2 = *(_DWORD *)(a1 + 668);
  if ( v2 < 0x20 )
  {
    v3 = *(_DWORD *)((char *)&users_alive + _per_cpu_offset[v2]);
    v4 = v3 - 1;
    if ( v3 != 1 || (((void (*)(void))mon_disable)(), v2 = *(_DWORD *)(a1 + 668), v2 <= 0x1F) )
    {
      *(_DWORD *)((char *)&users_alive + _per_cpu_offset[v2]) = v4;
      return raw_spin_unlock(&users_lock);
    }
  }
  __break(0x5512u);
  return qcom_llcc_event_start();
}
