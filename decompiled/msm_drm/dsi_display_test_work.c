__int64 __fastcall dsi_display_test_work(__int64 a1)
{
  __int64 v1; // x19
  int mode_count; // w0
  __int64 result; // x0
  unsigned int modes; // w0
  unsigned int v5; // w0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v11; // x6
  int v12; // w7
  unsigned int v13; // w0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  int v20; // w7
  unsigned int v21; // w19
  int v22; // [xsp+Ch] [xbp-14h] BYREF
  const void *v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(const void **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 - 8);
  v23[0] = nullptr;
  v22 = 0;
  mode_count = dsi_display_get_mode_count(v1, &v22);
  if ( !mode_count )
  {
    modes = dsi_display_get_modes(v1, (__int64 *)v23);
    if ( modes )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get modes, rc=%d\n", modes);
    }
    else
    {
      v5 = dsi_display_set_mode(v1, v23[0]);
      if ( v5 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set mode, rc=%d\n", v5);
      }
      else
      {
        v13 = dsi_display_prepare(v1, v6, v7, v8, v9, v10, v11, v12);
        if ( v13 )
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to prepare display, rc=%d\n", v13);
        }
        else
        {
          result = dsi_display_enable(v1, v14, v15, v16, v17, v18, v19, v20);
          if ( !(_DWORD)result )
            goto LABEL_12;
          v21 = result;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable display, rc=%d\n", result);
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to unprep display, rc=%d\n", v21);
        }
      }
    }
    result = kfree(v23[0]);
    goto LABEL_12;
  }
  result = drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get modes count, rc=%d\n", mode_count);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
