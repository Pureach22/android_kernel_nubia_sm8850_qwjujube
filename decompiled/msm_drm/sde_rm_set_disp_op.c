__int64 __fastcall sde_rm_set_disp_op(__int64 a1, int a2)
{
  __int64 i; // x21
  _QWORD *v5; // x26
  _QWORD *j; // x27
  __int64 v7; // x8

  if ( !a1 )
    return printk(&unk_26246B, "sde_rm_set_disp_op");
  mutex_lock(a1 + 280);
  for ( i = 0; i != 15; ++i )
  {
    v5 = (_QWORD *)(a1 + 24 + 16 * i);
    if ( v5 )
    {
      for ( j = (_QWORD *)*v5; j != v5; j = (_QWORD *)*j )
      {
        while ( 1 )
        {
          if ( j )
          {
            v7 = j[5];
            if ( v7 )
              break;
          }
          printk(&unk_25AF12, "sde_rm_set_disp_op");
          j = (_QWORD *)*j;
          if ( j == v5 )
            goto LABEL_4;
        }
        *(_DWORD *)(v7 + 28) = a2;
      }
    }
    else
    {
      printk(&unk_23527E, "sde_rm_set_disp_op");
    }
LABEL_4:
    ;
  }
  return mutex_unlock(a1 + 280);
}
