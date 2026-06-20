__int64 __fastcall msm_vidc_ts_reorder_get_first_timestamp(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  __int64 v4; // x10
  _QWORD *v6; // x11
  __int64 v7; // x10

  v2 = *(_QWORD **)(a1 + 3240);
  if ( v2 == (_QWORD *)(a1 + 3240) )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_835CA, "err ", a1 + 340, "msm_vidc_ts_reorder_get_first_timestamp", *a2);
    return 4294967274LL;
  }
  else
  {
    v3 = (_QWORD *)v2[1];
    if ( (_QWORD *)*v3 == v2 && (v4 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
    {
      *(_QWORD *)(v4 + 8) = v3;
      *v3 = v4;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 3240));
      a2 = v6;
      a1 = v7;
    }
    *v2 = v2;
    v2[1] = v2;
    *a2 = v2[2];
    --*(_DWORD *)(a1 + 3256);
    msm_vidc_pool_free(a1);
    return 0;
  }
}
