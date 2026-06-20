__int64 __fastcall sde_plane_get_scanout_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v8; // w8
  unsigned int v9; // w0
  __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w3
  __int64 v13; // x0
  __int64 v14; // x23
  unsigned int v15; // w0
  __int64 result; // x0
  int v17; // w8
  void *v18; // x0
  unsigned int v19; // w19
  unsigned int v20; // w19
  unsigned int v21; // w20
  char v22; // [xsp+0h] [xbp+0h]

  if ( a3 && a1 && a2 && a4 )
  {
    v8 = *(_DWORD *)(a2 + 1648);
    if ( (v8 == 8 || v8 == 2) && (v9 = sde_format_populate_layout(0, a3, a4)) != 0 )
    {
      v20 = v9;
      printk(&unk_27052F, "sde_plane_get_scanout_info");
      return v20;
    }
    else
    {
      if ( !*(_QWORD *)a1 || (v10 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 || (v11 = *(_QWORD *)(v10 + 8)) == 0 )
      {
        printk(&unk_234896, "_sde_plane_get_aspace");
        goto LABEL_27;
      }
      v12 = *(_DWORD *)(a2 + 1520);
      if ( (unsigned int)(v12 - 2) < 2 )
      {
        v13 = 0;
      }
      else
      {
        if ( v12 == 1 )
        {
          v13 = *(_QWORD *)(v11 + 1720);
          if ( !v13 )
            goto LABEL_27;
        }
        else
        {
          if ( v12 )
          {
            printk(&unk_25044B, "_sde_plane_get_aspace");
            v17 = -14;
            goto LABEL_28;
          }
          v13 = *(_QWORD *)(v11 + 1704);
          if ( !v13 )
          {
LABEL_27:
            v17 = -22;
LABEL_28:
            v18 = &unk_212956;
            v19 = v17;
LABEL_29:
            printk(v18, "sde_plane_get_scanout_info");
            return v19;
          }
        }
        if ( *(_BYTE *)(a2 + 1786) == 1 )
        {
          v14 = v13;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_plane_get_scanout_info",
            884,
            -1,
            *(_DWORD *)(a1 + 104),
            *(_DWORD *)(a1 + 1928),
            *(unsigned __int8 *)(v13 + 268),
            -1059143953,
            v22);
          v15 = msm_framebuffer_prepare(a3, *(_QWORD *)(a2 + 1744));
          if ( v15 )
          {
            v19 = v15;
            v18 = &unk_25B286;
            goto LABEL_29;
          }
          v13 = v14;
          *(_BYTE *)(a2 + 1786) = 0;
        }
      }
      result = sde_format_populate_layout(v13, a3, a4);
      if ( (_DWORD)result )
      {
        if ( (_DWORD)result == -11 )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "plane%d not updating same src addrs\n", *(_DWORD *)(a1 + 104));
          return 4294967285LL;
        }
        else
        {
          v21 = result;
          printk(&unk_2503F1, "sde_plane_get_scanout_info");
          result = v21;
          *(_BYTE *)(a1 + 2380) = 1;
        }
      }
    }
  }
  else
  {
    printk(&unk_2465A6, "sde_plane_get_scanout_info");
    return 4294967274LL;
  }
  return result;
}
