__int64 __fastcall msm_vidc_ts_reorder_flush(__int64 a1)
{
  _QWORD *v1; // x1
  _QWORD *v2; // x23
  _QWORD *v4; // x26
  _QWORD *v5; // x8
  __int64 v6; // x9
  _QWORD *v7; // x9
  _QWORD *v8; // x27

  v1 = *(_QWORD **)(a1 + 3240);
  v2 = (_QWORD *)(a1 + 3240);
  if ( v1 != (_QWORD *)(a1 + 3240) )
  {
    do
    {
      v4 = (_QWORD *)*v1;
      if ( a1 && (msm_vidc_debug & 4) != 0 )
      {
        v8 = v1;
        printk(&unk_8598D, "low ", a1 + 340, "msm_vidc_ts_reorder_flush", v1[2]);
        v1 = v8;
      }
      v5 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v5 == v1 && (v6 = *v1, *(_QWORD **)(*v1 + 8LL) == v1) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
        v1 = v7;
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      msm_vidc_pool_free(a1);
      v1 = v4;
    }
    while ( v4 != v2 );
  }
  *(_DWORD *)(a1 + 3256) = 0;
  return 0;
}
