__int64 __fastcall msm_ext_disp_deregister_intf(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  _QWORD *v4; // x9
  _QWORD *v5; // x8
  _QWORD *v6; // x0
  _QWORD *v7; // x10
  void *v9; // x0
  _QWORD *v10; // x10

  if ( !a1 || !a2 )
  {
    v9 = &unk_7309;
LABEL_15:
    printk(v9, "msm_ext_disp_deregister_intf");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 168);
  if ( !v3 )
  {
    v9 = &unk_705D;
    goto LABEL_15;
  }
  mutex_lock(v3 + 88);
  v4 = (_QWORD *)(v3 + 72);
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(v3 + 72) )
      break;
    if ( *(v4 - 1) == a2 )
    {
      v5 = (_QWORD *)v4[1];
      v6 = v4 - 1;
      if ( (_QWORD *)*v5 == v4 && (v7 = (_QWORD *)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        v7[1] = v5;
        *v5 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
        v6 = v10;
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      kfree(v6);
      break;
    }
  }
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  mutex_unlock(v3 + 88);
  return 0;
}
