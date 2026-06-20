__int64 __fastcall dp_debug_tpg_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  unsigned __int64 v8; // x1
  size_t v9; // x20
  __int64 v10; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  int v13; // w1
  __int64 v14; // x0
  void (*v15)(void); // x8
  int v16; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v16 = 0;
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      if ( a3 >= 7 )
        v6 = 7;
      else
        v6 = a3;
      v17[0] = 0;
      _check_object_size(v17, v6, 0);
      v8 = a2;
      v9 = v6;
      if ( !inline_copy_from_user((__int64)v17, v8, v6) )
      {
        *((_BYTE *)v17 + v6) = 0;
        v10 = kstrtoint(v17, 10, &v16);
        if ( !(_DWORD)v10 )
        {
          ipc_log_context = get_ipc_log_context(v10);
          StatusReg = _ReadStatusReg(SP_EL0);
          ipc_log_string(ipc_log_context, "[d][%-4d]tpg_pattern: %d\n", *(_DWORD *)(StatusReg + 1800), v16);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]tpg_pattern: %d\n", *(_DWORD *)(StatusReg + 1800), v16);
          v13 = v16;
          if ( v16 != *(_DWORD *)(v4 + 164) )
          {
            v14 = *(_QWORD *)(v4 + 120);
            if ( v14 )
            {
              v15 = *(void (**)(void))(v14 + 1080);
              if ( *((_DWORD *)v15 - 1) != 1927397843 )
                __break(0x8228u);
              v15();
              v13 = v16;
            }
            *(_DWORD *)(v4 + 164) = v13;
          }
        }
      }
      result = v9;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
