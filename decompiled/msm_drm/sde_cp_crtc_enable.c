__int64 __fastcall sde_cp_crtc_enable(__int64 result)
{
  __int64 v1; // x21
  int v2; // w9
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x20
  void (__fastcall *v6)(__int64, __int64); // x8
  void (__fastcall *v7)(__int64, __int64); // x8
  void (__fastcall *v8)(__int64, __int64); // x8
  void (__fastcall *v9)(__int64, __int64); // x8
  void (__fastcall *v10)(__int64, __int64); // x8
  void (__fastcall *v11)(__int64, __int64); // x8
  unsigned __int64 StatusReg; // x22
  __int64 v13; // x23

  if ( !result )
    return _drm_err("invalid crtc handle");
  v2 = *(_DWORD *)(result + 2192);
  v3 = result;
  if ( v2 )
  {
    if ( (unsigned int)(v2 - 9) < 0xFFFFFFF8 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v13 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sde_cp_crtc_enable__alloc_tag;
      v5 = vzalloc_noprof(16396);
      *(_QWORD *)(StatusReg + 80) = v13;
      if ( v5 )
        goto LABEL_27;
      goto LABEL_40;
    }
    v4 = *(_QWORD *)(result + 2216) != 0;
    if ( v2 != 1 )
    {
      if ( *(_QWORD *)(result + 2264) )
        ++v4;
      if ( v2 != 2 )
      {
        if ( *(_QWORD *)(result + 2312) )
          ++v4;
        if ( v2 != 3 )
        {
          if ( *(_QWORD *)(result + 2360) )
            ++v4;
          if ( v2 != 4 )
          {
            if ( *(_QWORD *)(result + 2408) )
              ++v4;
            if ( v2 != 5 )
            {
              if ( *(_QWORD *)(result + 2456) )
                ++v4;
              if ( v2 != 6 )
              {
                if ( *(_QWORD *)(result + 2504) )
                  ++v4;
                if ( v2 != 7 && *(_QWORD *)(result + 2552) )
                  ++v4;
              }
            }
          }
        }
      }
    }
    if ( v4 )
    {
      v1 = 4664;
      mutex_lock(result + 4664);
      v5 = vzalloc_noprof(16396);
      if ( v5 )
      {
LABEL_27:
        v6 = (void (__fastcall *)(__int64, __int64))dspp_cap_update_func_0;
        if ( *((_DWORD *)dspp_cap_update_func_0 - 1) != 38859469 )
          __break(0x8228u);
        v6(v3, v5);
        v7 = (void (__fastcall *)(__int64, __int64))dspp_cap_update_func_1;
        if ( *((_DWORD *)dspp_cap_update_func_1 - 1) != 38859469 )
          __break(0x8228u);
        v7(v3, v5);
        v8 = (void (__fastcall *)(__int64, __int64))dspp_cap_update_func_2;
        if ( *((_DWORD *)dspp_cap_update_func_2 - 1) != 38859469 )
          __break(0x8228u);
        v8(v3, v5);
        v9 = (void (__fastcall *)(__int64, __int64))dspp_cap_update_func_3;
        if ( *((_DWORD *)dspp_cap_update_func_3 - 1) != 38859469 )
          __break(0x8228u);
        v9(v3, v5);
        v10 = (void (__fastcall *)(__int64, __int64))dspp_cap_update_func_4;
        if ( *((_DWORD *)dspp_cap_update_func_4 - 1) != 38859469 )
          __break(0x8228u);
        v10(v3, v5);
        v11 = (void (__fastcall *)(__int64, __int64))dspp_cap_update_func_5;
        if ( *((_DWORD *)dspp_cap_update_func_5 - 1) != 38859469 )
          __break(0x8228u);
        v11(v3, v5);
        msm_property_set_blob(v3 + 2600, v3 + 7864, v5, (unsigned int)(*(_DWORD *)(v5 + 0x4000) + 1), 4);
      }
LABEL_40:
      vfree(v5);
      return mutex_unlock(v3 + v1);
    }
  }
  return result;
}
