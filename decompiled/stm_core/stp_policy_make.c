__int64 __fastcall stp_policy_make(__int64 a1, const char *a2)
{
  const char *v3; // x0
  const char *v4; // x21
  char *v5; // x0
  char *v6; // x0
  const char *v7; // x22
  __int64 device; // x0
  _QWORD *v9; // x20
  int v10; // w22
  __int64 result; // x0
  __int64 v12; // x19
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x9
  __int64 v16; // x10
  unsigned __int64 v17; // x19
  _QWORD *v18; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = nullptr;
  v19[0] = 0;
  v3 = (const char *)kasprintf(3264, "%s", a2);
  if ( !v3 )
  {
    result = -12;
    goto LABEL_15;
  }
  v4 = v3;
  v5 = strrchr(v3, 46);
  if ( !v5 )
  {
    kfree(v4);
    result = -22;
    goto LABEL_15;
  }
  *v5 = 0;
  v6 = strrchr(v4, 58);
  v7 = v6;
  if ( v6 )
  {
    *v6 = 0;
    v7 = v6 + 1;
  }
  device = stm_find_device((__int64)v4);
  if ( !device )
  {
    kfree(v4);
    result = -19;
    goto LABEL_15;
  }
  v9 = (_QWORD *)device;
  v10 = stm_lookup_protocol(v7, &v18, v19);
  kfree(v4);
  if ( !v10 )
  {
    mutex_lock(v9 + 116);
    if ( v9[115] )
    {
      v12 = -16;
    }
    else
    {
      v14 = _kmalloc_cache_noprof(mutex_unlock, 3520, 144);
      v9[115] = v14;
      if ( v14 )
      {
        config_group_init_type_name(v14, a2, &stp_policy_type);
        v15 = v19[0];
        v16 = v9[115];
        v9[133] = v18;
        v9[134] = v15;
        *(_QWORD *)(v16 + 136) = v9;
        v17 = v9[115];
        mutex_unlock(v9 + 116);
        result = v17;
        if ( v17 < 0xFFFFFFFFFFFFF001LL )
          goto LABEL_15;
        goto LABEL_14;
      }
      v12 = -12;
    }
    mutex_unlock(v9 + 116);
    result = v12;
LABEL_14:
    v13 = result;
    stm_put_protocol(v18);
    stm_put_device((__int64)v9);
    result = v13;
    goto LABEL_15;
  }
  stm_put_device((__int64)v9);
  result = -19;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
