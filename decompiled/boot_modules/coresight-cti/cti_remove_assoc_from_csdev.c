__int64 __fastcall cti_remove_assoc_from_csdev(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x8
  _QWORD *v5; // x20
  _QWORD *v6; // x10
  __int64 v7; // x8
  __int64 v8; // x9
  _QWORD v9[5]; // [xsp+8h] [xbp-28h] BYREF

  v9[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = coresight_find_output_type(*a1, 4, 1);
  if ( result )
  {
    v3 = result;
    mutex_lock(&ect_mutex);
    v4 = *(_QWORD *)(*(_QWORD *)(v3 + 152) + 152LL);
    v5 = (_QWORD *)(v4 + 24);
    while ( 1 )
    {
      v5 = (_QWORD *)*v5;
      if ( v5 == (_QWORD *)(v4 + 24) )
        break;
      v6 = (_QWORD *)*(v5 - 2);
      if ( v6 == a1 )
      {
        v7 = *(_QWORD *)(v4 + 8);
        v9[0] = v7;
        v8 = *(_QWORD *)(v7 + 168);
        v9[1] = *(v5 - 1);
        v9[2] = v6;
        if ( !v8 )
          v8 = *(_QWORD *)(v7 + 56);
        v9[3] = v8;
        coresight_remove_sysfs_link(v9);
        *(v5 - 2) = 0;
        break;
      }
    }
    result = mutex_unlock(&ect_mutex);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
