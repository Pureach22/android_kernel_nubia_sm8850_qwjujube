__int64 __fastcall cvp_msg_pending(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  _QWORD *v7; // x24
  __int64 v8; // x10
  _QWORD *v9; // x23
  _QWORD *v10; // x8
  unsigned int v11; // w22

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
    return 0;
  raw_spin_lock(a1);
  if ( (*(_DWORD *)(a1 + 4) | 4) == 4 )
  {
    raw_spin_unlock(a1);
    *a2 = 0;
    return 1;
  }
  v7 = *(_QWORD **)(a1 + 16);
  if ( v7 != (_QWORD *)(a1 + 16) )
  {
    if ( !a3 )
    {
      if ( v7 )
      {
        list_del_init(*(_QWORD **)(a1 + 16));
        v9 = v7;
LABEL_16:
        --*(_DWORD *)(a1 + 8);
      }
      else
      {
        v9 = nullptr;
      }
      v11 = 1;
      goto LABEL_19;
    }
    while ( v7 != (_QWORD *)(a1 + 16) )
    {
      v8 = v7[6];
      v9 = v7;
      v7 = (_QWORD *)*v7;
      if ( *a3 == v8 )
      {
        v10 = (_QWORD *)v9[1];
        if ( (_QWORD *)*v10 == v9 && (_QWORD *)v7[1] == v9 )
        {
          v7[1] = v10;
          *v10 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v9);
        }
        *v9 = v9;
        v9[1] = v9;
        goto LABEL_16;
      }
    }
  }
  v11 = 0;
  v9 = nullptr;
LABEL_19:
  raw_spin_unlock(a1);
  *a2 = v9;
  return v11;
}
