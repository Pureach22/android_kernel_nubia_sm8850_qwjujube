__int64 __fastcall coresight_orphan_match(__int64 a1, __int64 a2)
{
  __int64 *v2; // x21
  __int64 v4; // x8
  __int64 v6; // x24
  char v7; // w25
  __int64 csdev_by_fwnode; // x22
  _QWORD *v9; // x23
  __int64 v10; // x8
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 924) != 1 )
    return 0;
  v2 = (__int64 *)(a1 - 56);
  v4 = *(_QWORD *)(a1 - 56);
  if ( *(int *)(v4 + 4) >= 1 )
  {
    v6 = 0;
    v7 = 0;
    csdev_by_fwnode = a2;
    while ( 1 )
    {
      v9 = *(_QWORD **)(*(_QWORD *)(v4 + 8) + 8 * v6);
      v10 = v9[5];
      if ( !v10 || v9[6] )
        goto LABEL_14;
      if ( csdev_by_fwnode && v10 == *(_QWORD *)(csdev_by_fwnode + 808) )
        break;
      v7 = 1;
      if ( v9[2] )
        goto LABEL_5;
LABEL_15:
      if ( v2 == (__int64 *)a2 )
      {
        csdev_by_fwnode = coresight_find_csdev_by_fwnode(v9[1]);
        if ( !csdev_by_fwnode )
          goto LABEL_4;
      }
      else if ( !csdev_by_fwnode )
      {
        goto LABEL_4;
      }
      if ( v9[1] != *(_QWORD *)(csdev_by_fwnode + 808) )
      {
LABEL_4:
        v7 = 1;
        goto LABEL_5;
      }
      result = coresight_make_links(v2, v9, csdev_by_fwnode);
      if ( (_DWORD)result )
        return result;
      v9[2] = csdev_by_fwnode;
      v9[4] = v2;
      result = ((__int64 (__fastcall *)(_QWORD *))coresight_add_in_conn)(v9);
      if ( (_DWORD)result )
        return result;
LABEL_5:
      v4 = *v2;
      if ( ++v6 >= *(int *)(*v2 + 4) )
        goto LABEL_27;
    }
    if ( *(_DWORD *)(csdev_by_fwnode + 8) != 3 )
    {
      __break(0x800u);
      v7 = 1;
      if ( v9[2] )
        goto LABEL_5;
      goto LABEL_15;
    }
    v9[6] = csdev_by_fwnode;
LABEL_14:
    if ( v9[2] )
      goto LABEL_5;
    goto LABEL_15;
  }
  v7 = 0;
LABEL_27:
  *(_BYTE *)(a1 + 924) = v7 & 1;
  return 0;
}
