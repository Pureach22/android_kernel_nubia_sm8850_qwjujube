unsigned int *__fastcall cluster_gov_reflect(unsigned int *result)
{
  _BYTE *v1; // x20
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x22
  __int64 v4; // x23

  v1 = cluster_dev_list;
  if ( cluster_dev_list != (_UNKNOWN *)&cluster_dev_list )
  {
    v2 = *result;
    v3 = v2 >> 6;
    v4 = 1LL << v2;
    do
    {
      if ( v1[21] == 1 && (*(_QWORD *)(*((_QWORD *)v1 - 28) + 8 * v3 + 1328) & v4) != 0 )
      {
        raw_spin_lock(v1 + 16);
        if ( v1[23] == 1 )
          v1[24] = 1;
        result = (unsigned int *)raw_spin_unlock(v1 + 16);
      }
      v1 = *(_BYTE **)v1;
    }
    while ( v1 != (_BYTE *)&cluster_dev_list );
  }
  return result;
}
