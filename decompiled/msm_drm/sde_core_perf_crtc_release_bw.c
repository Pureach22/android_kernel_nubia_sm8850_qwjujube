__int64 __fastcall sde_core_perf_crtc_release_bw(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 *i; // x21
  void *v8; // x0
  void *v9; // x0

  if ( !result )
  {
    v9 = &unk_25E167;
    return printk(v9, "sde_core_perf_crtc_release_bw");
  }
  v1 = result;
  if ( !*(_QWORD *)result || (v2 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v8 = &unk_231B33;
LABEL_27:
    printk(v8, "_sde_crtc_get_kms");
    goto LABEL_28;
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    v8 = &unk_234896;
    goto LABEL_27;
  }
  if ( !*(_QWORD *)(v3 + 152) )
  {
LABEL_28:
    v9 = &unk_234896;
    return printk(v9, "sde_core_perf_crtc_release_bw");
  }
  v4 = *(_QWORD *)(v3 + 136);
  if ( *(_DWORD *)(*(_QWORD *)(v4 + 56) + 5912LL) != 1 )
  {
    result = sde_cesta_is_enabled(**(unsigned int **)(v4 + 64));
    if ( (result & 1) == 0 )
    {
      result = sde_crtc_get_intf_mode((__int64 *)v1, *(_QWORD *)(v1 + 2008));
      v5 = *(_QWORD *)(v1 + 2008);
      if ( (_DWORD)result == 1 || v5 && *(_QWORD *)(v5 + 472) )
      {
        result = sde_crtc_get_intf_mode((__int64 *)v1, v5);
        if ( (_DWORD)result == 1 )
        {
          v6 = *(_QWORD *)v1;
          for ( i = *(__int64 **)(*(_QWORD *)v1 + 864LL); i != (__int64 *)(v6 + 864); i = (__int64 *)*i )
          {
            result = (__int64)(i - 2);
            if ( i != &qword_10 && *((_BYTE *)i + 156) )
            {
              result = sde_crtc_get_intf_mode((__int64 *)result, i[249]);
              if ( (_DWORD)result == 2 )
                return result;
              v6 = *(_QWORD *)v1;
            }
          }
        }
        if ( *(_DWORD *)(v3 + 2056) )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "Release BW crtc=%d\n", *(_DWORD *)(v1 + 112));
          *(_QWORD *)(v1 + 7424) = 0;
          sde_core_perf_crtc_update_bus(v3, v1, 0);
          *(_QWORD *)(v1 + 7432) = 0;
          sde_core_perf_crtc_update_bus(v3, v1, 1);
          *(_QWORD *)(v1 + 7440) = 0;
          sde_core_perf_crtc_update_bus(v3, v1, 2);
          *(_QWORD *)(v1 + 7448) = 0;
          return sde_core_perf_crtc_update_bus(v3, v1, 3);
        }
      }
    }
  }
  return result;
}
