__int64 __fastcall ipa3_tasklet_find_freepage(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD **v2; // x8
  _QWORD *v3; // x10
  int v4; // w9
  _QWORD *v5; // x11
  _QWORD *v6; // x8
  _QWORD *v7; // x2
  _QWORD *v8; // x10
  _QWORD *v9; // x11
  _QWORD *v10; // x12
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x0
  _QWORD *v18; // [xsp+8h] [xbp-18h] BYREF
  _QWORD **v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(result + 1784) )
  {
    v1 = (_QWORD *)result;
    v18 = &v18;
    v19 = &v18;
    raw_spin_lock_bh(*(_QWORD *)(result + 1944) + 1684LL);
    v2 = (_QWORD **)v1[223];
    v3 = *v2;
    if ( *v2 == v2 )
      goto LABEL_23;
    v4 = 0;
    do
    {
      v5 = (_QWORD *)*v3;
      if ( *(_DWORD *)(v3[2] + 52LL) == 1 )
      {
        v6 = (_QWORD *)v3[1];
        if ( (_QWORD *)*v6 == v3 && (_QWORD *)v5[1] == v3 )
        {
          v5[1] = v6;
          *v6 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
        }
        *v3 = v3;
        v3[1] = v3;
        v7 = v18;
        if ( (_QWORD **)v18[1] != &v18 || v3 == &v18 || v3 == v18 )
        {
          _list_add_valid_or_report(v3, &v18);
        }
        else
        {
          v18[1] = v3;
          *v3 = v7;
          v3[1] = &v18;
          v18 = v3;
        }
        v2 = (_QWORD **)v1[223];
        ++v4;
      }
      v3 = v5;
    }
    while ( v5 != v2 );
    if ( !v4 )
    {
LABEL_23:
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d Scheduling WQ not found free pages\n", "ipa3_tasklet_find_freepage", 1428);
          v14 = ipa3_ctx;
        }
      }
      ++*(_QWORD *)(v14 + 34120);
      v16 = v1[224];
      v17 = _msecs_to_jiffies(*(unsigned int *)(v14 + 51400));
      queue_delayed_work_on(32, v16, v1 + 225, v17);
    }
    else
    {
      v8 = v18;
      if ( v18 != &v18 )
      {
        v9 = *v2;
        v10 = v19;
        v18[1] = v2;
        *v2 = v8;
        *v10 = v9;
        v9[1] = v10;
      }
      v11 = ipa3_ctx;
      v12 = ipa3_ctx + 0x8000;
      *(_QWORD *)(ipa3_ctx + 34128) += v4;
      if ( v11 )
      {
        v13 = *(_QWORD *)(v12 + 1392);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d found free pages count = %d\n", "ipa3_tasklet_find_freepage", 1437, v4);
          v11 = ipa3_ctx;
        }
      }
      *(_BYTE *)(v11 + 51295) = 0;
      *(_DWORD *)(v1[243] + 1612LL) = 1;
    }
    result = raw_spin_unlock_bh(v1[243] + 1684LL);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
