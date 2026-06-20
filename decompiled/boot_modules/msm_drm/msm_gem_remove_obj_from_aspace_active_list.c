__int64 __fastcall msm_gem_remove_obj_from_aspace_active_list(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 272);
    if ( v1 )
    {
      v2 = *(__int64 (**)(void))(v1 + 32);
      if ( v2 )
      {
        if ( *((_DWORD *)v2 - 1) != -604584043 )
          __break(0x8228u);
        return v2();
      }
    }
  }
  return result;
}
