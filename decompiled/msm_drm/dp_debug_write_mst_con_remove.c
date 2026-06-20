__int64 __fastcall dp_debug_write_mst_con_remove(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  __int64 v8; // x0
  int v9; // w9
  __int64 v10; // x0
  void (*v11)(void); // x8
  int v12; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v13[2]; // [xsp+8h] [xbp-38h] BYREF
  char s[8]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v12 = 0;
  if ( !v4 )
  {
    result = -19;
    goto LABEL_10;
  }
  if ( !*a4 )
  {
    if ( a3 >= 0x1F )
      v6 = 31;
    else
      v6 = a3;
    v13[0] = 0;
    v13[1] = 0;
    *(_QWORD *)s = 0;
    v15 = 0;
    v16 = 0;
    v17 = 0;
    _check_object_size(s, v6, 0);
    if ( !inline_copy_from_user((__int64)s, a2, v6) )
    {
      s[v6] = 0;
      if ( sscanf(s, "%d", &v12) != 1 )
        goto LABEL_3;
      if ( v12 )
      {
        drm_connector_list_iter_begin(***(_QWORD ***)(v4 + 144), v13);
        do
        {
          v8 = drm_connector_list_iter_next(v13);
          if ( !v8 )
          {
            drm_connector_list_iter_end(v13);
            _drm_err("invalid connector id %u\n", v12);
            goto LABEL_9;
          }
        }
        while ( *(_DWORD *)(v8 + 64) != v12 );
        drm_connector_list_iter_end(v13);
        v9 = v12;
        v10 = *(_QWORD *)(v4 + 104);
        *(_BYTE *)(v4 + 303) = 1;
        *(_DWORD *)(v4 + 304) = v9;
        v11 = *(void (**)(void))(v10 + 56);
        if ( *((_DWORD *)v11 - 1) != -143022559 )
          __break(0x8228u);
        v11();
      }
    }
LABEL_9:
    result = v6;
    goto LABEL_10;
  }
LABEL_3:
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
