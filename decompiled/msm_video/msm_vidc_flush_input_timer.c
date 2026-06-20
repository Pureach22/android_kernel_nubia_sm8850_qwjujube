__int64 __fastcall msm_vidc_flush_input_timer(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v6; // x1
  _QWORD *v7; // x8
  _QWORD *v8; // x21
  _QWORD *v9; // x9

  if ( a1 && (msm_vidc_debug & 4) != 0 )
    printk(&unk_821B8, "low ", a1 + 340, "msm_vidc_flush_input_timer", a5);
  v6 = *(_QWORD **)(a1 + 4008);
  if ( v6 != (_QWORD *)(a1 + 4008) )
  {
    do
    {
      v8 = (_QWORD *)*v6;
      v7 = (_QWORD *)v6[1];
      if ( (_QWORD *)*v7 == v6 && (_QWORD *)v8[1] == v6 )
      {
        v8[1] = v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
        v6 = v9;
      }
      *v6 = v6;
      v6[1] = v6;
      msm_vidc_pool_free(a1);
      v6 = v8;
    }
    while ( v8 != (_QWORD *)(a1 + 4008) );
  }
  return 0;
}
