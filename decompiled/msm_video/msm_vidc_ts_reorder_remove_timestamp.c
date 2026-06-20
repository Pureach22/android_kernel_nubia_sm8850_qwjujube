__int64 __fastcall msm_vidc_ts_reorder_remove_timestamp(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x9
  __int64 v4; // x11
  _QWORD *v5; // x1
  _QWORD *v6; // x8
  _QWORD *v8; // x10
  __int64 v9; // x9

  v2 = *(_QWORD **)(a1 + 3240);
  while ( v2 != (_QWORD *)(a1 + 3240) )
  {
    v4 = v2[2];
    v5 = v2;
    v2 = (_QWORD *)*v2;
    if ( v4 == a2 )
    {
      v6 = (_QWORD *)v5[1];
      if ( (_QWORD *)*v6 == v5 && (_QWORD *)v2[1] == v5 )
      {
        v2[1] = v6;
        *v6 = v2;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
        v5 = v8;
        a1 = v9;
      }
      *v5 = v5;
      v5[1] = v5;
      --*(_DWORD *)(a1 + 3256);
      msm_vidc_pool_free(a1);
      return 0;
    }
  }
  return 0;
}
