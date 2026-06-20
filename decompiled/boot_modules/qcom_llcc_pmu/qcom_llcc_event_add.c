__int64 __fastcall qcom_llcc_event_add(__int64 a1, char a2)
{
  int v4; // w8
  unsigned int v5; // w0
  int v6; // w23
  __int64 result; // x0
  int v8; // w8

  raw_spin_lock(&users_lock);
  if ( *(_DWORD *)(llccpmu + 1456) == 1 )
  {
    v4 = users;
    if ( !users )
    {
      mon_enable(*(unsigned int *)(a1 + 668));
      v4 = users;
    }
    users = v4 + 1;
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 668);
    if ( v5 >= 0x20
      || (v6 = *(_DWORD *)((char *)&users_alive + _per_cpu_offset[v5])) == 0
      && (((void (*)(void))mon_enable)(), v5 = *(_DWORD *)(a1 + 668), v5 > 0x1F) )
    {
      __break(0x5512u);
      return qcom_llcc_event_del();
    }
    *(_DWORD *)((char *)&users_alive + _per_cpu_offset[v5]) = v6 + 1;
  }
  raw_spin_unlock(&users_lock);
  result = 0;
  if ( (a2 & 1) != 0 )
    v8 = 0;
  else
    v8 = 3;
  *(_DWORD *)(a1 + 480) = v8;
  return result;
}
