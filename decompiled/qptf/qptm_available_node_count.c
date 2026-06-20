__int64 qptm_available_node_count()
{
  _UNKNOWN **v0; // x8
  unsigned int v1; // w19
  int v2; // w9

  if ( qptm_list == (_UNKNOWN *)&qptm_list )
  {
    return (unsigned int)-19;
  }
  else
  {
    mutex_lock(&qptm_list_lock);
    v0 = (_UNKNOWN **)qptm_list;
    if ( qptm_list == (_UNKNOWN *)&qptm_list )
    {
      v1 = 0;
    }
    else
    {
      v1 = 0;
      do
      {
        v2 = *((unsigned __int8 *)v0 - 20);
        v0 = (_UNKNOWN **)*v0;
        v1 += v2;
      }
      while ( v0 != &qptm_list );
    }
    mutex_unlock(&qptm_list_lock);
  }
  return v1;
}
