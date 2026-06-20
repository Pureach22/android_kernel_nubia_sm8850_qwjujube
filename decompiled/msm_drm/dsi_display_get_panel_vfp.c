__int64 __fastcall dsi_display_get_panel_vfp(__int64 a1, int a2, int a3)
{
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w23
  __int64 result; // x0
  unsigned int v10; // w20
  int v11; // w8
  __int64 v12; // x9
  int v13; // w10
  _DWORD *v14; // x9
  _DWORD *v15; // x10
  int v16; // w9
  int v17; // w10
  _DWORD *v18; // x13
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  __int64 v20; // [xsp+10h] [xbp-20h]
  __int64 v21; // [xsp+18h] [xbp-18h]
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && *(_QWORD *)(a1 + 264) )
  {
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    mutex_lock(a1 + 72);
    v6 = *(_QWORD *)(a1 + 264);
    v7 = *(_QWORD *)(v6 + 1424);
    if ( v7 )
      v8 = *(_DWORD *)(v7 + 44);
    else
      v8 = 0;
    v10 = *(_DWORD *)(v6 + 1436);
    dsi_panel_get_dfps_caps(v6, &v19);
    if ( BYTE4(v22) )
      v11 = v20;
    else
      v11 = v8;
    if ( v11 )
    {
      v12 = *(_QWORD *)(a1 + 264);
      v13 = *(unsigned __int8 *)(v12 + 1280);
      v14 = (_DWORD *)(v12 + 1284);
      if ( v13 )
        v15 = v14;
      else
        v15 = (_DWORD *)(a1 + 160);
      if ( v10 )
      {
        v16 = 0;
        v17 = *v15 * a2;
        do
        {
          v18 = (_DWORD *)(*(_QWORD *)(a1 + 824) + 192LL * v16);
          if ( v18 && v18[6] == a3 && v17 == *v18 && v11 == v18[11] )
          {
            v10 = v18[9];
            goto LABEL_24;
          }
          ++v16;
        }
        while ( v10 != v16 );
        v10 = 0;
      }
LABEL_24:
      mutex_unlock(a1 + 72);
      result = v10;
    }
    else
    {
      mutex_unlock(a1 + 72);
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Null Refresh Rate\n");
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
