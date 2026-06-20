__int64 __fastcall debugfs_update_cmd_scheduling_params(__int64 a1, unsigned __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 v4; // x22
  __int64 result; // x0
  unsigned __int64 v8; // x0
  const char *v9; // x19
  unsigned __int64 v10; // x1
  __int64 v11; // x20
  unsigned int v12; // w10
  int v13; // w8
  int v14; // w9
  __int64 v15; // x11
  __int64 v16; // x10
  __int64 v17; // [xsp+0h] [xbp-10h] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v17 = 0;
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      v8 = _kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 256);
      v9 = (const char *)v8;
      if ( v8 >= 0x11 )
      {
        if ( a3 >= 0xFF )
          a3 = 255;
        _check_object_size(v8, a3, 0);
        v10 = a2;
        v11 = a3;
        if ( inline_copy_from_user_7((__int64)v9, v10, a3) )
        {
          v11 = -22;
        }
        else
        {
          v9[a3] = 0;
          if ( sscanf(v9, "%d %d", (char *)&v17 + 4, &v17) != 2 )
          {
            result = -14;
            goto LABEL_12;
          }
          v12 = *(_DWORD *)(v4 + 160);
          if ( v12 )
          {
            v14 = v17;
            v13 = HIDWORD(v17);
            v15 = *(_QWORD *)(v4 + 168);
            if ( v15 )
            {
              *(_DWORD *)(v15 + 2524) = HIDWORD(v17);
              *(_DWORD *)(v15 + 2528) = v14;
              v12 = *(_DWORD *)(v4 + 160);
            }
            if ( v12 >= 2 )
            {
              v16 = *(_QWORD *)(v4 + 216);
              if ( v16 )
              {
                *(_DWORD *)(v16 + 2524) = v13;
                *(_DWORD *)(v16 + 2528) = v14;
              }
            }
          }
        }
        kfree(v9);
        result = v11;
      }
      else
      {
        result = -12;
      }
    }
  }
  else
  {
    result = -19;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
