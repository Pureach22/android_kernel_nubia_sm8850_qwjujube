_QWORD *__fastcall stp_policy_node_lookup(__int64 a1, char *a2)
{
  __int64 v4; // x23
  _QWORD *v5; // x23
  _QWORD *v6; // t1
  _QWORD *v7; // x20
  char *v8; // x0
  const char *v9; // x22
  _QWORD *v10; // x24
  char *v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&unk_440);
  mutex_lock(a1 + 928);
  v4 = *(_QWORD *)(a1 + 920);
  if ( !v4 || (v6 = *(_QWORD **)(v4 + 80), v5 = (_QWORD *)(v4 + 80), v12[0] = a2, v6 == v5) )
  {
    mutex_unlock(a1 + 928);
LABEL_13:
    mutex_unlock(&unk_440);
    v7 = nullptr;
    goto LABEL_14;
  }
  v7 = nullptr;
LABEL_4:
  while ( 1 )
  {
    v8 = strsep(v12, "/");
    if ( !v8 )
      break;
    v9 = v8;
    if ( *v8 )
    {
      v10 = v5;
      while ( 1 )
      {
        v10 = (_QWORD *)*v10;
        if ( v10 == v5 )
          goto LABEL_10;
        if ( !strcmp(v9, (const char *)*(v10 - 4)) )
        {
          v7 = v10 - 4;
          v5 = v10 + 6;
          if ( v12[0] )
            goto LABEL_4;
          goto LABEL_10;
        }
      }
    }
  }
LABEL_10:
  mutex_unlock(a1 + 928);
  if ( !v7 )
    goto LABEL_13;
  config_item_get(v7);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v7;
}
