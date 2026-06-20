__int64 __fastcall cscfg_unload_owned_cfgs_feats(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  _QWORD *i; // x10
  _QWORD *v4; // x20
  _QWORD *v5; // x9
  __int64 v6; // x8
  _QWORD *v7; // x9
  _QWORD *v8; // x11
  _QWORD *v9; // x12
  _QWORD *v10; // x8
  _QWORD *v11; // x9
  _QWORD *v12; // x11
  _QWORD *v13; // x12
  _QWORD *v14; // x8
  _QWORD *v15; // x23
  _QWORD *v16; // x8
  _QWORD *v17; // x9
  _QWORD *v18; // x10
  _QWORD *v19; // x8

  v1 = result;
  v2 = cscfg_mgr;
  for ( i = *(_QWORD **)(cscfg_mgr + 912); i != (_QWORD *)(cscfg_mgr + 912); i = (_QWORD *)*i )
  {
    v6 = *(i - 3);
    v7 = *(_QWORD **)(v6 + 1024);
    v8 = (_QWORD *)(v6 + 1024);
    if ( v7 != (_QWORD *)(v6 + 1024) )
    {
      do
      {
        v9 = (_QWORD *)*v7;
        if ( *(_QWORD *)(*(v7 - 3) + 80LL) == v1 )
        {
          v10 = (_QWORD *)v7[1];
          if ( (_QWORD *)*v10 == v7 && (_QWORD *)v9[1] == v7 )
          {
            v9[1] = v10;
            *v10 = v9;
          }
          else
          {
            result = _list_del_entry_valid_or_report(v7);
          }
          *v7 = 0xDEAD000000000100LL;
          v7[1] = 0xDEAD000000000122LL;
        }
        v7 = v9;
      }
      while ( v9 != v8 );
      v6 = *(i - 3);
    }
    v11 = *(_QWORD **)(v6 + 1008);
    v12 = (_QWORD *)(v6 + 1008);
    if ( v11 != (_QWORD *)(v6 + 1008) )
    {
      do
      {
        v13 = (_QWORD *)*v11;
        if ( *(_QWORD *)(*(v11 - 2) + 64LL) == v1 )
        {
          v14 = (_QWORD *)v11[1];
          if ( (_QWORD *)*v14 == v11 && (_QWORD *)v13[1] == v11 )
          {
            v13[1] = v14;
            *v14 = v13;
          }
          else
          {
            result = _list_del_entry_valid_or_report(v11);
          }
          *v11 = 0xDEAD000000000100LL;
          v11[1] = 0xDEAD000000000122LL;
        }
        v11 = v13;
      }
      while ( v13 != v12 );
    }
    v2 = cscfg_mgr;
  }
  v4 = *(_QWORD **)(v2 + 944);
  if ( v4 != (_QWORD *)(v2 + 944) )
  {
    do
    {
      v15 = (_QWORD *)*v4;
      if ( v4[8] == v1 )
      {
        result = etm_perf_del_symlink_cscfg((__int64)(v4 - 2));
        v16 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v16 == v4 && (v17 = (_QWORD *)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
        {
          v17[1] = v16;
          *v16 = v17;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v4);
        }
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        v2 = cscfg_mgr;
      }
      v4 = v15;
    }
    while ( v15 != (_QWORD *)(v2 + 944) );
  }
  v5 = *(_QWORD **)(v2 + 928);
  if ( v5 != (_QWORD *)(v2 + 928) )
  {
    do
    {
      v18 = (_QWORD *)*v5;
      if ( v5[6] == v1 )
      {
        v19 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v19 == v5 && (_QWORD *)v18[1] == v5 )
        {
          v18[1] = v19;
          *v19 = v18;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v5);
        }
        *v5 = 0xDEAD000000000100LL;
        v5[1] = 0xDEAD000000000122LL;
        v2 = cscfg_mgr;
      }
      v5 = v18;
    }
    while ( v18 != (_QWORD *)(v2 + 928) );
  }
  return result;
}
