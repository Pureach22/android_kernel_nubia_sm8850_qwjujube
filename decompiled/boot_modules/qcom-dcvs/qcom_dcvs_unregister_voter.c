__int64 __fastcall qcom_dcvs_unregister_voter(const char *a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x21
  _QWORD *v7; // x19
  _QWORD *v8; // x0
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  unsigned int v11; // w19
  _QWORD *v12; // x9

  result = 4294967274LL;
  if ( a1 && a2 <= 4 && a3 <= 2 )
  {
    if ( dcvs_data && (v5 = *(_QWORD *)(dcvs_data + 8LL * a2 + 96)) != 0 && (v6 = *(_QWORD *)(v5 + 8LL * a3 + 144)) != 0 )
    {
      mutex_lock(v6 + 72);
      v7 = (_QWORD *)(v6 + 48);
      do
      {
        v7 = (_QWORD *)*v7;
        if ( v7 == (_QWORD *)(v6 + 48) )
        {
          v11 = -22;
          goto LABEL_16;
        }
      }
      while ( strcmp((const char *)*(v7 - 3), a1) );
      v8 = v7 - 3;
      --*(_DWORD *)(v6 + 64);
      v9 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v9 == v7 && (v10 = (_QWORD *)*v7, *(_QWORD **)(*v7 + 8LL) == v7) )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
        v8 = v12;
      }
      *v7 = 0xDEAD000000000100LL;
      v7[1] = 0xDEAD000000000122LL;
      kfree(v8);
      v11 = 0;
LABEL_16:
      mutex_unlock(v6 + 72);
      return v11;
    }
    else
    {
      return 4294967277LL;
    }
  }
  return result;
}
