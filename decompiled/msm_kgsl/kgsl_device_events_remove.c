__int64 __fastcall kgsl_device_events_remove(__int64 a1)
{
  unsigned __int64 *v2; // x9
  unsigned __int64 *v3; // x10
  unsigned __int64 v4; // x11
  unsigned __int64 *v5; // x12
  unsigned __int64 **v6; // x8
  unsigned __int64 v7; // x13

  raw_write_lock(a1 + 13168);
  v2 = *(unsigned __int64 **)(a1 + 13152);
  v3 = (unsigned __int64 *)(a1 + 13152);
  if ( v2 != (unsigned __int64 *)(a1 + 13152) )
  {
    v4 = 0xDEAD000000000100LL;
    do
    {
      v5 = (unsigned __int64 *)*v2;
      if ( (unsigned __int64 *)*(v2 - 2) != v2 - 2 )
        __break(0x800u);
      v6 = (unsigned __int64 **)v2[1];
      if ( *v6 == v2 && (v7 = *v2, *(unsigned __int64 **)(*v2 + 8) == v2) )
      {
        *(_QWORD *)(v7 + 8) = v6;
        *v6 = (unsigned __int64 *)v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = v4;
      v2[1] = v4 + 34;
      v2 = v5;
    }
    while ( v5 != v3 );
  }
  return raw_write_unlock(a1 + 13168);
}
