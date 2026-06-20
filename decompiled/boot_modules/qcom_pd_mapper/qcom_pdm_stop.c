__int64 __fastcall qcom_pdm_stop(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x21
  _QWORD *v4; // x23
  _QWORD *v5; // x0
  _QWORD *v6; // x9
  _QWORD *v7; // x8
  _QWORD *v8; // x25
  _QWORD *v9; // x8
  _QWORD *v10; // x9

  v1 = *(_QWORD **)(a1 + 312);
  v2 = (_QWORD *)(a1 + 312);
  if ( v1 != (_QWORD *)(a1 + 312) )
  {
    do
    {
      v4 = (_QWORD *)*v1;
      v5 = (_QWORD *)v1[2];
      if ( v5 != v1 + 2 )
      {
        do
        {
          v8 = (_QWORD *)*v5;
          v7 = (_QWORD *)v5[1];
          if ( (_QWORD *)*v7 == v5 && (_QWORD *)v8[1] == v5 )
          {
            v8[1] = v7;
            *v7 = v8;
          }
          else
          {
            ((void (*)(void))_list_del_entry_valid_or_report)();
            v5 = v6;
          }
          *v5 = 0xDEAD000000000100LL;
          v5[1] = 0xDEAD000000000122LL;
          kfree(v5);
          v5 = v8;
        }
        while ( v8 != v1 + 2 );
      }
      v9 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v9 == v1 && (v10 = (_QWORD *)*v1, *(_QWORD **)(*v1 + 8LL) == v1) )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      kfree(v1);
      v1 = v4;
    }
    while ( v4 != v2 );
  }
  qmi_handle_release(a1 + 8);
  return kfree(a1);
}
