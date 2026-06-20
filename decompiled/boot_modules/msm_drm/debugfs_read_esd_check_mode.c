__int64 __fastcall debugfs_read_esd_check_mode(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  char *v9; // x0
  __int64 v10; // x19
  __int64 v11; // x8
  size_t v12; // x21
  __int64 v13; // x8
  int v14; // w0

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  if ( *(_QWORD *)(v4 + 264) )
  {
    v9 = (char *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 256);
    v10 = (__int64)v9;
    if ( (unsigned __int64)v9 >= 0x11 )
    {
      v11 = *(_QWORD *)(v4 + 264);
      if ( v11 == -1720 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid panel esd config\n");
        v12 = 0;
      }
      else
      {
        if ( a3 >= 0xFF )
          v12 = 255;
        else
          v12 = a3;
        if ( *(_BYTE *)(v11 + 1720) == 1 )
        {
          v13 = *(unsigned int *)(v11 + 1724);
          if ( (unsigned int)v13 > 5 )
            v14 = snprintf(v9, v12, "invalid");
          else
            v14 = snprintf(v9, v12, off_2915C8[v13]);
        }
        else
        {
          v14 = snprintf(v9, v12, "ESD feature not enabled");
        }
        if ( v14 )
        {
          _check_object_size(v10, v12, 1);
          if ( !inline_copy_to_user_5(a2, v10, v12) )
            *a4 += v12;
        }
      }
      kfree(v10);
      return v12;
    }
    else
    {
      return -12;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid panel data\n");
    return -22;
  }
}
