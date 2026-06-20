_QWORD *__fastcall msm_vidc_pools_deinit(__int64 a1)
{
  __int64 v2; // x27
  __int64 v3; // x20
  _QWORD *v4; // x22
  _QWORD **v5; // x24
  _QWORD *v6; // x0
  int v7; // w25
  _QWORD *v8; // x8
  _QWORD *v9; // x21
  _QWORD *v10; // x9
  _QWORD *result; // x0
  int v12; // w26
  _QWORD *v13; // x8
  _QWORD *v14; // x21
  _QWORD *v15; // x9

  v2 = 0;
  v3 = a1 + 2168;
  do
  {
    v4 = (_QWORD *)(v3 + 48 * v2);
    v5 = (_QWORD **)(v4 + 4);
    if ( a1 && (_QWORD **)v4[4] != v5 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_806A7, "err ", a1 + 340, "msm_vidc_destroy_pool_buffers", v4[1]);
    v6 = (_QWORD *)v4[2];
    if ( v6 != v4 + 2 )
    {
      v7 = 0;
      do
      {
        v9 = (_QWORD *)*v6;
        v8 = (_QWORD *)v6[1];
        if ( (_QWORD *)*v8 == v6 && (_QWORD *)v9[1] == v6 )
        {
          v9[1] = v8;
          *v8 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
          v6 = v10;
        }
        *v6 = 0xDEAD000000000100LL;
        v6[1] = 0xDEAD000000000122LL;
        vfree(v6);
        ++v7;
        v6 = v9;
      }
      while ( v9 != v4 + 2 );
    }
    result = *v5;
    if ( *v5 != v5 )
    {
      v12 = 0;
      do
      {
        v14 = (_QWORD *)*result;
        v13 = (_QWORD *)result[1];
        if ( (_QWORD *)*v13 == result && (_QWORD *)v14[1] == result )
        {
          v14[1] = v13;
          *v13 = v14;
        }
        else
        {
          _list_del_entry_valid_or_report(result);
          result = v15;
        }
        *result = 0xDEAD000000000100LL;
        result[1] = 0xDEAD000000000122LL;
        vfree(result);
        ++v12;
        result = v14;
      }
      while ( v14 != v5 );
    }
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        result = (_QWORD *)printk(&unk_8AA09, "high", a1 + 340, "msm_vidc_destroy_pool_buffers", v4[1]);
    }
    ++v2;
  }
  while ( v2 != 7 );
  return result;
}
