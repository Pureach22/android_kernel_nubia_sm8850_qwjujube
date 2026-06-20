__int64 __fastcall dp_panel_set_colorspace(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  int v4; // w20
  __int64 (*v5)(void); // x8
  __int64 v6; // x0
  unsigned int v7; // w9
  unsigned int v8; // w8
  __int64 (*v9)(void); // x8
  int v10; // w8
  char v11; // w8
  int v12; // w9
  char v13; // w9
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 (*v16)(void); // x8

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 1216);
    v4 = a2;
    if ( *(_BYTE *)(a1 + 1233) == 1 )
    {
      *(_DWORD *)(v2 + 32) = 319096576;
      v5 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 1200) + 160LL);
      if ( *((_DWORD *)v5 - 1) != -1720141962 )
        __break(0x8228u);
      v6 = v5();
      if ( (_DWORD)v6 )
      {
        LOBYTE(v7) = 0;
        LOBYTE(v8) = 0x80;
      }
      else if ( (unsigned int)(v4 - 9) > 3 )
      {
        LOBYTE(v7) = 0;
        LOBYTE(v8) = 0;
      }
      else
      {
        v11 = 8 * (v4 - 9);
        v7 = 0x4040006u >> v11;
        v8 = 0x80u >> v11;
      }
      *(_BYTE *)(v2 + 52) = v7;
      *(_BYTE *)(v2 + 53) = v8;
      v12 = (unsigned __int8)(*(_DWORD *)(a1 + 156) / 3u);
      if ( v12 != 6 )
      {
        if ( v12 == 8 )
          v13 = 1;
        else
          v13 = 2;
        *(_BYTE *)(v2 + 53) = v13 | v8;
      }
      *(_BYTE *)(v2 + 54) = 1;
    }
    else
    {
      *(_DWORD *)(v2 + 200) &= 0xFFFFFFE1;
      v9 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 1200) + 160LL);
      if ( *((_DWORD *)v9 - 1) != -1720141962 )
        __break(0x8228u);
      v6 = v9();
      if ( (_DWORD)v6 )
      {
        v10 = 2 * (unsigned __int8)v6;
      }
      else if ( (unsigned int)(v4 - 7) > 7 )
      {
        v10 = 0;
      }
      else
      {
        v10 = dword_29D3A0[v4 - 7];
      }
      *(_DWORD *)(v2 + 200) |= v10;
    }
    if ( *(_BYTE *)(a1 + 1232) == 1 )
    {
      ipc_log_context = get_ipc_log_context(v6);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(ipc_log_context, "[d][%-4d]panel is ON programming colorspace\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]panel is ON programming colorspace\n", *(_DWORD *)(StatusReg + 1800));
      v16 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 1216) + 616LL);
      if ( *((_DWORD *)v16 - 1) != -488369993 )
        __break(0x8228u);
      return v16();
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_275CE5, a2);
    return 4294967274LL;
  }
}
