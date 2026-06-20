unsigned __int64 __fastcall funnel_platform_remove(unsigned __int64 result)
{
  __int64 v1; // x20
  unsigned __int64 v2; // x19
  _QWORD *v3; // x8
  __int64 *v4; // x0
  __int64 v5; // x9

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    raw_spin_lock(&delay_lock);
    if ( *(_BYTE *)(v1 + 89) == 1 )
    {
      v3 = *(_QWORD **)(v1 + 104);
      v4 = (__int64 *)(v1 + 96);
      if ( *v3 == v1 + 96 && (v5 = *v4, *(__int64 **)(*v4 + 8) == v4) )
      {
        *(_QWORD *)(v5 + 8) = v3;
        *v3 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report();
      }
      *(_QWORD *)(v1 + 96) = 0xDEAD000000000100LL;
      *(_QWORD *)(v1 + 104) = 0xDEAD000000000122LL;
    }
    raw_spin_unlock(&delay_lock);
    coresight_unregister(*(_QWORD *)(v1 + 24));
    _pm_runtime_disable(v2 + 16, 1);
    result = *(_QWORD *)(v1 + 16);
    if ( result )
    {
      if ( result <= 0xFFFFFFFFFFFFF000LL )
        return clk_put();
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
