__int64 __fastcall adreno_parse_ib_lpac(_QWORD *a1, __int64 a2, __int64 a3, unsigned __int64 a4, unsigned __int64 a5)
{
  __int64 result; // x0
  unsigned __int64 v11; // x8
  __int64 v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  if ( __CFADD__(a4, 4 * a5) || (v11 = *(_QWORD *)(a2 + 40), v11 < a4) || 4 * a5 + a4 <= v11 )
  {
    result = kgsl_snapshot_have_object(a2, a3, a4);
    if ( !(_DWORD)result )
    {
      result = adreno_ib_create_object_list((__int64)a1, a3, a4, a5, *(_QWORD *)(a2 + 48), v12);
      if ( (_DWORD)result == -7 )
        ib_max_objs = 1;
      if ( v12[0] )
        result = kgsl_snapshot_add_ib_obj_list(a2);
    }
  }
  else
  {
    *(_QWORD *)(a2 + 40) = a4;
    *(_DWORD *)(a2 + 56) = a5;
    result = (__int64)kgsl_snapshot_push_object(a1, a3, a4, a5);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
