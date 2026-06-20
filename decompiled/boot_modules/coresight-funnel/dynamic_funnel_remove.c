__int64 __fastcall dynamic_funnel_remove(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v2; // x8
  __int64 *v3; // x0
  __int64 v4; // x9

  v1 = *(_QWORD *)(a1 + 152);
  raw_spin_lock(&delay_lock);
  if ( *(_BYTE *)(v1 + 89) == 1 )
  {
    v2 = *(_QWORD **)(v1 + 104);
    v3 = (__int64 *)(v1 + 96);
    if ( *v2 == v1 + 96 && (v4 = *v3, *(__int64 **)(*v3 + 8) == v3) )
    {
      *(_QWORD *)(v4 + 8) = v2;
      *v2 = v4;
    }
    else
    {
      _list_del_entry_valid_or_report();
    }
    *(_QWORD *)(v1 + 96) = 0xDEAD000000000100LL;
    *(_QWORD *)(v1 + 104) = 0xDEAD000000000122LL;
  }
  raw_spin_unlock(&delay_lock);
  return coresight_unregister(*(_QWORD *)(v1 + 24));
}
