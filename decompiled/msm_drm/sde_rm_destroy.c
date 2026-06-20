__int64 __fastcall sde_rm_destroy(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x9
  _QWORD *v4; // x8
  _QWORD *v5; // x22
  __int64 i; // x22
  _QWORD *v7; // x24
  _QWORD *v8; // x20
  _QWORD *v9; // x8
  _QWORD *v10; // x25
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 result; // x0
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h]
  int v16; // [xsp+10h] [xbp-10h]
  int v17; // [xsp+14h] [xbp-Ch]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v15 = 0;
    v16 = 0;
    v14 = 0;
    v17 = 5;
    while ( (sde_rm_get_hw_locked(a1, (__int64)&v14, 1) & 1) != 0 )
      sde_hw_fence_deinit(*(_QWORD *)(v15 + 40));
    v2 = *(_QWORD **)(a1 + 8);
    if ( v2 != (_QWORD *)(a1 + 8) )
    {
      do
      {
        v5 = (_QWORD *)*v2;
        v4 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v4 == v2 && (_QWORD *)v5[1] == v2 )
        {
          v5[1] = v4;
          *v4 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
          v2 = v3;
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree(v2);
        v2 = v5;
      }
      while ( v5 != (_QWORD *)(a1 + 8) );
    }
    for ( i = 0; i != 15; ++i )
    {
      v7 = (_QWORD *)(a1 + 24 + 16 * i);
      v8 = (_QWORD *)*v7;
      if ( (_QWORD *)*v7 != v7 )
      {
        do
        {
          v10 = (_QWORD *)*v8;
          v9 = (_QWORD *)v8[1];
          if ( (_QWORD *)*v9 == v8 && (_QWORD *)v10[1] == v8 )
          {
            v10[1] = v9;
            *v9 = v10;
          }
          else
          {
            _list_del_entry_valid_or_report(v8);
          }
          v11 = *((unsigned int *)v8 + 8);
          v12 = v8[5];
          *v8 = 0xDEAD000000000100LL;
          v8[1] = 0xDEAD000000000122LL;
          sde_rm_hw_destroy(v11, v12);
          kfree(v8);
          v8 = v10;
        }
        while ( v10 != v7 );
      }
    }
    sde_hw_mdp_destroy(*(_QWORD *)(a1 + 264));
    result = 0;
    *(_QWORD *)(a1 + 264) = 0;
  }
  else
  {
    printk(&unk_26246B, "sde_rm_destroy");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
