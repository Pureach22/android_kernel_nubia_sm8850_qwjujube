__int64 __fastcall dp_sim_debug_write_skip_link_training(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  __int64 v8; // x0
  bool v9; // zf
  char v10; // w9
  __int64 ipc_log_context; // x0
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  char s[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
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
      v12 = 0;
      *(_QWORD *)s = 0;
      _check_object_size(s, v6, 0);
      if ( !inline_copy_from_user_0((__int64)s, a2, v6) )
      {
        s[v6] = 0;
        v8 = sscanf(s, "%d %u", (char *)&v12 + 4, &v12);
        if ( (_DWORD)v8 != 2 )
        {
          ipc_log_context = get_ipc_log_context(v8);
          ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          printk(&unk_275B6D, "dp_sim_debug_write_skip_link_training");
          result = -22;
          goto LABEL_15;
        }
        mutex_lock(v4 + 88);
        v9 = HIDWORD(v12) == 0;
        *(_DWORD *)(v4 + 2232) = v12;
        v10 = !v9;
        *(_BYTE *)(v4 + 2282) = v10;
        mutex_unlock(v4 + 88);
      }
      result = v6;
    }
  }
  else
  {
    result = -19;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
