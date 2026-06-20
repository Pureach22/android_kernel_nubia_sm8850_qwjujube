// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_106578(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  __int64 *v4; // x19
  __int64 result; // x0
  int v6; // w4
  __int64 v7; // x8
  int v8; // w5
  __int64 v9; // x20
  __int64 v10; // x8
  char v11; // [xsp-60h] [xbp-60h]

  if ( a3 )
    return sde_rm_debugfs_init();
  if ( *v4 )
  {
    v6 = *(_DWORD *)(*v4 + 24);
    if ( !v4 )
      goto LABEL_9;
  }
  else
  {
    v6 = -1;
    if ( !v4 )
      goto LABEL_9;
  }
  v7 = v4[358];
  if ( v7 )
  {
    v8 = *(_DWORD *)(v7 + 12) - 1;
    goto LABEL_10;
  }
LABEL_9:
  v8 = -1;
LABEL_10:
  sde_evtlog_log(
    *(_QWORD *)(v3 + 1528),
    "sde_encoder_phys_wb_disable",
    2818,
    -1,
    v6,
    v8,
    *((unsigned __int8 *)v4 + 2290),
    -1059143953,
    v11);
  result = v4[352];
  v9 = *v4;
  *((_DWORD *)v4 + 208) = 1;
  if ( result && v4[353] )
  {
    msm_framebuffer_cleanup();
    result = drm_mode_object_put(v4[352] + 24);
    v4[352] = 0;
    v4[353] = 0;
  }
  v10 = *(_QWORD *)(v9 + 1360);
  if ( v10 )
    *(_DWORD *)(v10 + 7872) &= ~(1 << *(_DWORD *)(*v4 + 68));
  v4[367] = 0;
  v4[54] = 0;
  v4[52] = 0;
  *((_BYTE *)v4 + 2290) = 0;
  *((_DWORD *)v4 + 219) = 0;
  *((_DWORD *)v4 + 220) = 0;
  *((_DWORD *)v4 + 221) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
