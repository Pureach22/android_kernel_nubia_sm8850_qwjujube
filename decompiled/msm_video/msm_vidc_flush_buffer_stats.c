__int64 __fastcall msm_vidc_flush_buffer_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  _QWORD *v6; // x1
  _QWORD *v7; // x8
  _QWORD *v8; // x22
  _QWORD *v9; // x9

  v5 = a1;
  if ( a1 && (msm_vidc_debug & 4) != 0 )
    a1 = printk(&unk_977DB, "low ", a1 + 340, "msm_vidc_flush_buffer_stats", a5);
  v6 = *(_QWORD **)(v5 + 4088);
  if ( v6 != (_QWORD *)(v5 + 4088) )
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
      a1 = msm_vidc_pool_free(v5);
      v6 = v8;
    }
    while ( v8 != (_QWORD *)(v5 + 4088) );
  }
  *(_QWORD *)(v5 + 38424) = ktime_get(a1) / 0x3E8uLL;
  return 0;
}
