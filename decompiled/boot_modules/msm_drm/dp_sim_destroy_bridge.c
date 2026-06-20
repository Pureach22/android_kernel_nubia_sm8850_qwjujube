__int64 __fastcall dp_sim_destroy_bridge(__int64 a1)
{
  _QWORD *v3; // x19
  _QWORD *v4; // x1
  _QWORD *v5; // x8
  _QWORD *v6; // x23
  _QWORD *v7; // x9

  if ( !a1 )
    return 4294967274LL;
  if ( (*(_DWORD *)(a1 + 16) & 0x80000000) == 0 )
    return 4294967274LL;
  v3 = (_QWORD *)(a1 - 8);
  dp_mst_sim_destroy(*(_QWORD *)(a1 + 24));
  v4 = *(_QWORD **)(a1 + 2200);
  if ( v4 != (_QWORD *)(a1 + 2200) )
  {
    do
    {
      v6 = (_QWORD *)*v4;
      v5 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v5 == v4 && (_QWORD *)v6[1] == v4 )
      {
        v6[1] = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
        v4 = v7;
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      devm_kfree(*v3);
      v4 = v6;
    }
    while ( v6 != (_QWORD *)(a1 + 2200) );
  }
  if ( *(_QWORD *)(a1 + 2240) )
    devm_kfree(*v3);
  devm_kfree(*v3);
  return 0;
}
