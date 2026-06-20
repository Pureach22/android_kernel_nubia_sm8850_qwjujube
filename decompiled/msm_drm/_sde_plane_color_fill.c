__int64 __fastcall sde_plane_color_fill(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x8
  __int64 v4; // x9
  unsigned int v5; // w23
  __int64 result; // x0
  __int64 v7; // x1
  __int64 v8; // x22
  void (*v9)(void); // x8
  int v10; // w8
  void (*v11)(void); // x8
  void (*v12)(void); // x8
  void (*v13)(void); // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  void (*v17)(void); // x8
  void (*v18)(void); // x8
  int v19; // w9
  __int64 (*v20)(void); // x8

  v1 = *(_QWORD *)(a1 + 1768);
  if ( !v1 )
    return printk(&unk_226FC0, "_sde_plane_color_fill");
  v2 = *(_QWORD *)(a1 + 2208);
  if ( !v2 )
    return printk(&unk_27A67D, "_sde_plane_color_fill");
  if ( a1 && *(_QWORD *)a1 && (v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
    v5 = *(_DWORD *)(v4 + 5912);
  else
    v5 = 0;
  *(_DWORD *)(v2 + 28) = v5;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(a1 + 104));
  result = sde_get_sde_format_ext(875708993, 0);
  if ( result )
  {
    if ( v5 > 2 )
    {
      __break(0x5512u);
      return sde_plane_set_error(result, v7);
    }
    v8 = result;
    result = *(_QWORD *)(a1 + 2208);
    v9 = *(void (**)(void))(result + 8LL * v5 + 256);
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != 74160127 )
        __break(0x8228u);
      v9();
      v10 = *(_DWORD *)(a1 + 2300);
      *(_DWORD *)(a1 + 2288) = 0;
      *(_DWORD *)(a1 + 2292) = v10;
      sde_plane_setup_scaler(a1, v1, v8, 1);
      result = *(_QWORD *)(a1 + 2208);
      v11 = *(void (**)(void))(result + 8LL * v5 + 64);
      if ( v11 )
      {
        if ( *((_DWORD *)v11 - 1) != 563136525 )
          __break(0x8228u);
        v11();
        result = *(_QWORD *)(a1 + 2208);
      }
      v12 = *(void (**)(void))(result + 8LL * v5 + 88);
      if ( v12 )
      {
        if ( *((_DWORD *)v12 - 1) != -1599035892 )
          __break(0x8228u);
        v12();
        result = *(_QWORD *)(a1 + 2208);
      }
      v13 = *(void (**)(void))(result + 8LL * v5 + 136);
      if ( v13 )
      {
        if ( *((_DWORD *)v13 - 1) != -839651807 )
          __break(0x8228u);
        v13();
        result = *(_QWORD *)(a1 + 2208);
      }
      if ( !*(_QWORD *)(result + 8LL * v5 + 616) || *(_DWORD *)(v1 + 1776) == 2 )
        goto LABEL_40;
      v14 = *(_QWORD *)(a1 + 1768);
      if ( v14 )
      {
        v15 = *(_QWORD *)(v14 + 8);
        if ( v15 )
        {
          v16 = *(_QWORD *)(v15 + 2208);
LABEL_37:
          *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 1384LL) = v16;
          v17 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8LL * v5 + 616);
          if ( *((_DWORD *)v17 - 1) != -1904157959 )
            __break(0x8228u);
          v17();
          result = *(_QWORD *)(a1 + 2208);
LABEL_40:
          v18 = *(void (**)(void))(result + 8LL * v5 + 1336);
          if ( v18 )
          {
            if ( (*(_BYTE *)(a1 + 2388) & 1) == 0 )
            {
              v19 = *(_DWORD *)(v1 + 1648);
              if ( v19 == 2 || v19 == 8 || *(_DWORD *)(a1 + 2736) )
              {
                if ( *((_DWORD *)v18 - 1) != -2004904540 )
                  __break(0x8228u);
                v18();
                result = *(_QWORD *)(a1 + 2208);
              }
            }
          }
          v20 = *(__int64 (**)(void))(result + 8LL * v5 + 1312);
          if ( v20 )
          {
            if ( *((_DWORD *)v20 - 1) != 1253086170 )
              __break(0x8228u);
            return v20();
          }
          return result;
        }
        _drm_err("Invalid drm_crtc %pK\n", 0);
      }
      else
      {
        _drm_err("Invalid plane state %pK\n", 0);
      }
      v16 = 0;
      goto LABEL_37;
    }
  }
  return result;
}
