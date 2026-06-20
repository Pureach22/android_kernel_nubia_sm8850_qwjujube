__int64 __fastcall cam_ife_hw_mgr_attach_sfe_sys_cache_id(
        __int64 result,
        unsigned int a2,
        unsigned int *a3,
        unsigned int a4)
{
  char *v5; // x20
  __int64 v6; // x22
  char v7; // w10
  unsigned int *v8; // x20
  unsigned int v9; // w21
  int v10; // w7
  unsigned int v11; // w20
  unsigned int v12; // [xsp+Ch] [xbp-4h]
  unsigned int v13; // [xsp+Ch] [xbp-4h]

  if ( (result & 1) == 0 )
  {
    if ( *a3 <= 2 )
    {
      v7 = debug_mdl;
      *((_DWORD *)&g_ife_hw_mgr[10156] + 5 * *a3) |= 1LL << a2;
      if ( (v7 & 8) != 0 && !debug_priority )
      {
        if ( a2 > 5 )
          goto LABEL_28;
        v8 = a3;
        v9 = a4;
        result = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   v7 & 8,
                   4,
                   "cam_ife_hw_mgr_attach_sfe_sys_cache_id",
                   19934,
                   "SFE[%u] non-shared cache_type %d, type %u",
                   *a3,
                   *((_DWORD *)&g_ife_hw_mgr[10147] + 3 * a2 + 1),
                   a2);
        a3 = v8;
        a4 = v9;
      }
      *a3 = (*a3 + 1) % a4;
      return result;
    }
LABEL_28:
    __break(0x5512u);
    return inline_copy_from_user_4((unsigned __int8)result, a2, (size_t)a3);
  }
  if ( !a4 )
    return result;
  v5 = (char *)g_ife_hw_mgr + 12 * a2;
  v6 = 1LL << a2;
  LODWORD(qword_3A8658) = qword_3A8658 | (1LL << a2);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    if ( a2 > 5 )
      goto LABEL_28;
    v12 = a4;
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_ife_hw_mgr_attach_sfe_sys_cache_id",
               19929,
               "SFE[%u] shared scid %d type %u",
               0,
               *((_DWORD *)v5 + 20295),
               a2);
    a4 = v12;
    if ( v12 == 1 )
      return result;
  }
  else if ( a4 == 1 )
  {
    return result;
  }
  LODWORD(qword_3A866C) = qword_3A866C | v6;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    if ( a2 <= 5 )
    {
      v13 = a4;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_hw_mgr_attach_sfe_sys_cache_id",
                 19929,
                 "SFE[%u] shared scid %d type %u",
                 1,
                 *((_DWORD *)v5 + 20295),
                 a2);
      a4 = v13;
      if ( v13 == 2 )
        return result;
      goto LABEL_9;
    }
    goto LABEL_28;
  }
  if ( a4 == 2 )
    return result;
LABEL_9:
  LODWORD(qword_3A8680) = qword_3A8680 | v6;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    if ( a2 > 5 )
      goto LABEL_28;
    v10 = *((_DWORD *)v5 + 20295);
    v11 = a4;
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_ife_hw_mgr_attach_sfe_sys_cache_id",
               19929,
               "SFE[%u] shared scid %d type %u",
               2,
               v10,
               a2);
    if ( v11 != 3 )
      goto LABEL_28;
  }
  else if ( a4 != 3 )
  {
    goto LABEL_28;
  }
  return result;
}
