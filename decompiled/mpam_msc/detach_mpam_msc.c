void __fastcall detach_mpam_msc(__int64 a1, __int64 a2, int a3)
{
  _QWORD *v3; // x8
  __int64 *v4; // x0
  __int64 v5; // x9
  __int64 v6; // x9

  if ( a2 && a3 == 2 )
  {
    v3 = *(_QWORD **)(a2 + 80);
    v4 = (__int64 *)(a2 + 72);
    if ( *v3 == a2 + 72 && (v5 = *v4, *(__int64 **)(*v4 + 8) == v4) )
    {
      *(_QWORD *)(v5 + 8) = v3;
      *v3 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v4, a2);
      a2 = v6;
    }
    *(_QWORD *)(a2 + 72) = 0xDEAD000000000100LL;
    *(_QWORD *)(a2 + 80) = 0xDEAD000000000122LL;
  }
}
