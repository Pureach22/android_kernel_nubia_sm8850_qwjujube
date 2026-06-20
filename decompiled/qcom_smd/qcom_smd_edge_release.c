__int64 __fastcall qcom_smd_edge_release(__int64 a1)
{
  _QWORD *v1; // x9
  _QWORD *v2; // x21
  _QWORD *v4; // x8
  _QWORD *v5; // x23
  __int64 v6; // x0
  _QWORD *v7; // x20

  v1 = *(_QWORD **)(a1 + 1024);
  v2 = (_QWORD *)(a1 + 1024);
  if ( v1 != (_QWORD *)(a1 + 1024) )
  {
    do
    {
      v5 = (_QWORD *)*v1;
      v4 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v4 == v1 && (_QWORD *)v5[1] == v1 )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      v6 = *(v1 - 17);
      v7 = v1 - 20;
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      kfree(v6);
      kfree(v7);
      v1 = v5;
    }
    while ( v5 != v2 );
  }
  return kfree(a1);
}
