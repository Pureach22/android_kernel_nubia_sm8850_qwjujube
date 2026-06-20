__int64 __fastcall dp_debug_write_hpd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  unsigned __int64 v8; // x1
  size_t v9; // x20
  __int64 v10; // x0
  char v11; // w10
  int v12; // w8
  __int64 ipc_log_context; // x0
  int v14; // w8
  unsigned __int64 StatusReg; // x19
  const char *v16; // x3
  void (*v17)(void); // x8
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v18 = 0;
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
      v19[0] = 0;
      _check_object_size(v19, v6, 0);
      v8 = a2;
      v9 = v6;
      if ( !inline_copy_from_user((__int64)v19, v8, v6) )
      {
        *((_BYTE *)v19 + v6) = 0;
        v10 = kstrtoint(v19, 10, &v18);
        if ( !(_DWORD)v10 )
        {
          v11 = v18 & 1;
          v12 = (v18 >> 1) & 1;
          v18 &= 7u;
          *(_BYTE *)(v4 + 24) = v11;
          *(_BYTE *)(v4 + 161) = v12;
          ipc_log_context = get_ipc_log_context(v10);
          v14 = *(unsigned __int8 *)(v4 + 24);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( v14 )
            v16 = "[CONNECT]";
          else
            v16 = "[DISCONNECT]";
          ipc_log_string(ipc_log_context, "[i][%-4d]%s\n", *(unsigned int *)(StatusReg + 1800), v16);
          if ( (_drm_debug & 4) != 0 )
            printk(&unk_241D69, *(unsigned int *)(StatusReg + 1800));
          else
            printk(&unk_279553, "dp_debug_write_hpd");
          v17 = *(void (**)(void))(*(_QWORD *)(v4 + 104) + 48LL);
          if ( *((_DWORD *)v17 - 1) != -517830654 )
            __break(0x8228u);
          v17();
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
