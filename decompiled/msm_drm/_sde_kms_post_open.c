__int64 __fastcall sde_kms_post_open(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  void (__fastcall *v3)(__int64, __int64); // x8
  __int64 v4; // x1
  _QWORD v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v5[1] = 0;
  if ( result )
  {
    v1 = *(_QWORD *)(result + 136);
    if ( v1 )
    {
      if ( *(_BYTE *)(v1 + 936) == 1 )
      {
        mutex_lock(v1 + 432);
        drm_connector_list_iter_begin(v1, v5);
        while ( 1 )
        {
          v2 = drm_connector_list_iter_next(v5);
          if ( !v2 )
            break;
          if ( (*(_BYTE *)(v2 + 2080) & 1) != 0 )
          {
            v3 = *(void (__fastcall **)(__int64, __int64))(v2 + 3056);
            if ( v3 )
            {
              v4 = *(_QWORD *)(v2 + 2760);
              if ( *((_DWORD *)v3 - 1) != 1212788166 )
                __break(0x8228u);
              v3(v2, v4);
            }
          }
        }
        drm_connector_list_iter_end(v5);
        result = mutex_unlock(v1 + 432);
      }
    }
    else
    {
      result = printk(&unk_231B33, "_sde_kms_post_open");
    }
  }
  else
  {
    result = printk(&unk_234896, "_sde_kms_post_open");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
