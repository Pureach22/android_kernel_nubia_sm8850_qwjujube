__int64 __fastcall coresight_add_helper(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  mutex_lock(&coresight_mutex);
  v4 = _dev_fwnode(a2 + 56);
  v5 = fwnode_handle_get(v4);
  v6 = *(unsigned int *)(*a1 + 4LL);
  if ( (int)v6 < 1 )
  {
LABEL_5:
    if ( (unsigned __int64)coresight_add_out_conn(a1[19]) <= 0xFFFFFFFFFFFFF000LL )
      ((void (*)(void))coresight_add_in_conn)();
  }
  else
  {
    v7 = *(_QWORD *)(*a1 + 8LL);
    while ( *(_QWORD *)(*(_QWORD *)v7 + 8LL) != v5 )
    {
      --v6;
      v7 += 8;
      if ( !v6 )
        goto LABEL_5;
    }
  }
  result = mutex_unlock(&coresight_mutex);
  _ReadStatusReg(SP_EL0);
  return result;
}
