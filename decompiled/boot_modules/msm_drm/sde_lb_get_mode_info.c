__int64 __fastcall sde_lb_get_mode_info(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x21
  int v14; // w8
  _QWORD v15[2]; // [xsp+0h] [xbp-3A0h] BYREF
  _DWORD s[226]; // [xsp+10h] [xbp-390h] BYREF
  __int64 v17; // [xsp+398h] [xbp-8h]

  result = 4294967274LL;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && a4 && a6 )
  {
    memset(s, 0, sizeof(s));
    v11 = *a1;
    v15[0] = 0;
    v15[1] = 0;
    if ( v11 )
    {
      drm_connector_list_iter_begin(v11, v15);
      do
      {
        v12 = drm_connector_list_iter_next(v15);
        if ( !v12 )
        {
          drm_connector_list_iter_end(v15);
          goto LABEL_11;
        }
      }
      while ( *(_DWORD *)(v12 + 156) != 16 );
      v13 = v12;
      drm_connector_list_iter_end(v15);
      memset((void *)a4, 0, 0x388u);
      result = sde_connector_get_mode_info(v13, a2, 0, (__int64)s);
      if ( (_DWORD)result )
        goto LABEL_13;
      v14 = s[9];
      *(_BYTE *)(a4 + 776) = 0;
      *(_QWORD *)(a4 + 60) = 0x6400000000LL;
      *(_DWORD *)(a4 + 36) = v14;
    }
    else
    {
      printk(&unk_21E943, v10);
LABEL_11:
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "primary connector is not created yet\n");
LABEL_13:
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
