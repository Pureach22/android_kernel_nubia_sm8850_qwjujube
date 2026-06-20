__int64 __fastcall cam_cpas_hw_register_client(__int64 a1, char *string)
{
  __int64 v4; // x22
  __int64 v5; // x21
  size_t v6; // x0
  __int64 result; // x0
  int string_index; // w0
  __int64 v9; // x25
  unsigned int v10; // w21
  __int64 v11; // x26
  char v12; // w8
  __int64 v13; // x0
  __int64 v14; // x1
  unsigned int v15; // [xsp+2Ch] [xbp-94h] BYREF
  char s[8]; // [xsp+30h] [xbp-90h] BYREF
  __int64 v17; // [xsp+38h] [xbp-88h]
  __int64 v18; // [xsp+40h] [xbp-80h]
  __int64 v19; // [xsp+48h] [xbp-78h]
  __int64 v20; // [xsp+50h] [xbp-70h]
  __int64 v21; // [xsp+58h] [xbp-68h]
  __int64 v22; // [xsp+60h] [xbp-60h]
  __int64 v23; // [xsp+68h] [xbp-58h]
  __int64 v24; // [xsp+70h] [xbp-50h]
  __int64 v25; // [xsp+78h] [xbp-48h]
  __int64 v26; // [xsp+80h] [xbp-40h]
  __int64 v27; // [xsp+88h] [xbp-38h]
  __int64 v28; // [xsp+90h] [xbp-30h]
  __int64 v29; // [xsp+98h] [xbp-28h]
  __int64 v30; // [xsp+A0h] [xbp-20h]
  _QWORD v31[3]; // [xsp+A8h] [xbp-18h]

  v31[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)((char *)v31 + 7) = 0;
  v30 = 0;
  v31[0] = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  *(_QWORD *)s = 0;
  v17 = 0;
  v15 = -1;
  if ( !string )
    goto LABEL_10;
  v4 = *(_QWORD *)(a1 + 3680);
  v5 = *(_QWORD *)(a1 + 3392);
  v6 = strnlen(string, 0x80u);
  if ( v6 >= 0x81 )
  {
    _fortify_panic(2, 128, v6 + 1);
    goto LABEL_26;
  }
  if ( !(_BYTE)v6 )
  {
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_register_client",
      3290,
      "Invalid cpas client identifier");
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( (unsigned __int8)v6 != 128 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_hw_register_client",
        3295,
        "Register params : identifier=%s, cell_index=%d",
        string,
        *((_DWORD *)string + 32));
    if ( *(_BYTE *)(v5 + 8) == 1 )
      snprintf(s, 0x83u, "%s%d", string, *((_DWORD *)string + 32));
    else
      snprintf(s, 0x83u, "%s", string);
    mutex_lock(a1);
    string_index = cam_common_util_get_string_index(v5 + 16, *(_DWORD *)(v5 + 12), s, (int *)&v15);
    if ( !string_index )
    {
      if ( v15 < 0x2C )
      {
        v9 = v4 + 664;
        mutex_lock(v4 + 664 + 48LL * v15);
        v10 = v15;
        if ( v15 <= 0x2A )
        {
          v11 = v4 + 320;
          if ( *(_BYTE *)(*(_QWORD *)(v4 + 320 + 8LL * v15) + 168LL) == 1 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_hw_register_client",
              3326,
              "Inval client %s %d : %d %d %pK %d",
              string,
              *((_DWORD *)string + 32),
              1,
              1,
              *(const void **)(v4 + 320 + 8LL * v15),
              0);
            if ( v15 <= 0x2B )
            {
              mutex_unlock(v9 + 48LL * v15);
              mutex_unlock(a1);
              result = 0xFFFFFFFFLL;
              goto LABEL_22;
            }
          }
          else
          {
            *((_DWORD *)string + 40) = v15;
            memcpy(*(void **)(v11 + 8LL * v10), string, 0xA8u);
            ++*(_DWORD *)(v4 + 2788);
            v12 = debug_mdl;
            *(_BYTE *)(*(_QWORD *)(v11 + 8LL * v10) + 168LL) = 1;
            if ( (v12 & 4) == 0
              || debug_priority
              || (((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v12 & 4,
                    4,
                    "cam_cpas_hw_register_client",
                    3343,
                    "client=[%d][%s][%d], registered_clients=%d",
                    v10,
                    *(const char **)(v11 + 8LL * v10),
                    *(_DWORD *)(*(_QWORD *)(v11 + 8LL * v10) + 128LL),
                    *(_DWORD *)(v4 + 2788)),
                  v10 = v15,
                  v15 <= 0x2B) )
            {
              mutex_unlock(v9 + 48LL * v10);
              mutex_unlock(a1);
              result = 0;
              goto LABEL_22;
            }
          }
        }
      }
      __break(0x5512u);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_register_client",
      3311,
      "Client %s is not found in CPAS client list rc=%d",
      s,
      string_index);
    mutex_unlock(a1);
    result = 4294967277LL;
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_26:
  v13 = _fortify_panic(4, 128, 129);
  return cam_cpas_hw_set_addr_trans(v13, v14);
}
