__int64 __fastcall dp_debug_write_edid_modes(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x21
  size_t v7; // x19
  unsigned __int64 v9; // x1
  size_t v10; // x20
  size_t v11; // x0
  int v12; // w9
  int v13; // w10
  int v14; // w8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  int v17; // [xsp+8h] [xbp-38h] BYREF
  int v18; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v19; // [xsp+10h] [xbp-30h] BYREF
  char s[8]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v19 = 0;
  v18 = 0;
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      v6 = *(_QWORD *)(v4 + 120);
      if ( a3 >= 0x1F )
        v7 = 31;
      else
        v7 = a3;
      v22 = 0;
      v23 = 0;
      *(_QWORD *)s = 0;
      v21 = 0;
      v17 = 0;
      _check_object_size(s, v7, 0);
      v9 = a2;
      v10 = v7;
      v11 = inline_copy_from_user((__int64)s, v9, v7);
      if ( !v11
        && (s[v7] = 0, v11 = sscanf(s, "%d %d %d %d", (char *)&v19 + 4, &v19, &v18, &v17), (_DWORD)v11 == 4)
        && HIDWORD(v19)
        && (v12 = v19) != 0
        && (v13 = v18) != 0 )
      {
        *(_DWORD *)(v6 + 984) = HIDWORD(v19);
        v14 = v17;
        *(_BYTE *)(v6 + 981) = 1;
        *(_DWORD *)(v6 + 988) = v12;
        *(_DWORD *)(v6 + 992) = v13;
        *(_DWORD *)(v6 + 996) = v14;
      }
      else
      {
        ipc_log_context = get_ipc_log_context(v11);
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(ipc_log_context, "[d][%-4d]clearing debug modes\n", *(_DWORD *)(StatusReg + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]clearing debug modes\n", *(_DWORD *)(StatusReg + 1800));
        *(_BYTE *)(v6 + 981) = 0;
      }
      result = v10;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
