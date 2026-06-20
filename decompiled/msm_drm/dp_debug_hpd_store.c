__int64 __fastcall dp_debug_hpd_store(int a1, int a2, char *s, __int64 a4)
{
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v8; // x9
  int v9; // w12
  bool v10; // zf
  char v11; // w11
  void (*v12)(void); // x9
  __int64 v13; // x0
  const char *v14; // x3
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  if ( dp_debug_p )
  {
    sscanf(s, "%d", &v15);
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]: hpd = %d\n", *(_DWORD *)(StatusReg + 1800), v15);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]: hpd = %d\n", *(_DWORD *)(StatusReg + 1800), v15);
    v8 = dp_debug_p;
    v9 = (v15 >> 1) & 1;
    v10 = (v15 & 7) == 0;
    v11 = v15 & 1;
    v15 &= 7u;
    *(_BYTE *)(dp_debug_p + 24) = v11;
    *(_BYTE *)(v8 + 161) = v9;
    if ( v10 )
      *(_BYTE *)(edid_ctl + 41) = 1;
    v12 = *(void (**)(void))(*(_QWORD *)(v8 + 104) + 48LL);
    if ( *((_DWORD *)v12 - 1) != -517830654 )
      __break(0x8229u);
    v12();
    v13 = get_ipc_log_context();
    if ( *(_BYTE *)(dp_debug_p + 24) )
      v14 = "dp debug hpd connect";
    else
      v14 = "dp debug hpd disconnect";
    ipc_log_string(v13, "[i][%-4d]: %s\n", *(unsigned int *)(StatusReg + 1800), v14);
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_2424A2, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_237BA8, "dp_debug_hpd_store");
    result = a4;
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
