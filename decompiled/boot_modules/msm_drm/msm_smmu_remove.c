__int64 __fastcall msm_smmu_remove(__int64 a1)
{
  __int64 v1; // x19
  _UNKNOWN **v2; // x9
  _QWORD *v3; // x8
  __int64 *v4; // x0
  __int64 v5; // x9

  v1 = *(_QWORD *)(a1 + 168);
  *(_BYTE *)(v1 + 40) = 0;
  mutex_lock(&smmu_list_lock);
  v2 = &sde_smmu_list;
  while ( 1 )
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &sde_smmu_list )
      break;
    if ( v2 - 6 == (_UNKNOWN **)v1 )
    {
      v3 = *(_QWORD **)(v1 + 56);
      v4 = (__int64 *)(v1 + 48);
      if ( *v3 == v1 + 48 && (v5 = *v4, *(__int64 **)(*v4 + 8) == v4) )
      {
        *(_QWORD *)(v5 + 8) = v3;
        *v3 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      *(_QWORD *)(v1 + 48) = 0xDEAD000000000100LL;
      *(_QWORD *)(v1 + 56) = 0xDEAD000000000122LL;
      return mutex_unlock(&smmu_list_lock);
    }
  }
  return mutex_unlock(&smmu_list_lock);
}
