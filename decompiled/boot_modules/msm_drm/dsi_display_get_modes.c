__int64 __fastcall dsi_display_get_modes(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  unsigned int modes_helper; // w21
  unsigned int dfps_caps; // w0
  __int64 v7; // x8
  unsigned int v8; // w9
  unsigned int v9; // w2
  _QWORD v11[4]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v12; // [xsp+28h] [xbp-28h] BYREF
  __int64 v13; // [xsp+30h] [xbp-20h]
  __int64 v14; // [xsp+38h] [xbp-18h]
  __int64 v15; // [xsp+40h] [xbp-10h]
  __int64 v16; // [xsp+48h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  if ( a1 && a2 )
  {
    *a2 = 0;
    mutex_lock(a1 + 72);
    v4 = *(_QWORD *)(a1 + 824);
    if ( v4 )
    {
LABEL_4:
      modes_helper = 0;
      *a2 = v4;
LABEL_16:
      mutex_unlock(a1 + 72);
      goto LABEL_17;
    }
    v4 = _kmalloc_noprof(192LL * *(unsigned int *)(*(_QWORD *)(a1 + 264) + 1436LL), 3520);
    *(_QWORD *)(a1 + 824) = v4;
    if ( v4 )
    {
      dfps_caps = dsi_panel_get_dfps_caps(*(_QWORD *)(a1 + 264), &v12);
      if ( dfps_caps )
      {
        modes_helper = dfps_caps;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to get dfps caps from panel\n",
          *(const char **)(a1 + 32));
        v4 = *(_QWORD *)(a1 + 824);
      }
      else
      {
        v7 = *(_QWORD *)(a1 + 264);
        v8 = *(_DWORD *)(a1 + 1212);
        v9 = *(_DWORD *)(v7 + 1432);
        if ( v8 != -1 && v8 >= v9 )
          *(_DWORD *)(a1 + 1212) = -1;
        v11[0] = v12;
        v11[1] = v13;
        v11[2] = v14;
        v11[3] = v15;
        modes_helper = dsi_display_get_modes_helper(
                         a1,
                         (__int64 *)(a1 + 168),
                         v9,
                         (__int64)v11,
                         v7 + 1976,
                         (_BYTE *)(v7 + 1392),
                         v7 + 2000);
        v4 = *(_QWORD *)(a1 + 824);
        if ( !modes_helper )
          goto LABEL_4;
      }
    }
    else
    {
      modes_helper = -12;
    }
    kfree(v4);
    goto LABEL_16;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  modes_helper = -22;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return modes_helper;
}
