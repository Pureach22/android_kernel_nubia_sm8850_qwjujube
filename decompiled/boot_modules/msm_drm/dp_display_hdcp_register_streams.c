__int64 __fastcall dp_display_hdcp_register_streams(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x23
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v7; // x8
  char v8; // w9
  unsigned int v9; // w9
  __int64 v10; // x10
  __int64 v11; // x1
  _BYTE *v12; // x8
  __int64 (__fastcall *v13)(__int64, __int64, int *); // x8
  int v14; // w19
  __int64 v15; // x0
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 128);
  if ( *(_BYTE *)(v1 + 8) == 1 && (*(_BYTE *)(result + 12) & 8) != 0 )
  {
    v2 = *(_QWORD *)(result + 224);
    v3 = *(_QWORD *)(result + 232);
    if ( ((*(_BYTE *)(*(_QWORD *)(result + 176) + 5LL) & 1) == 0 || *(_DWORD *)(*(_QWORD *)(result + 168) + 8LL))
      && *(_BYTE *)(v1 + 10) == 1
      && *(_BYTE *)(result + 1832) == 1
      && v3
      && *(_QWORD *)(v3 + 88) )
    {
      v4 = result;
      v16 = 0;
      if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v5 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      result = ipc_log_string(
                 v5,
                 "[d][%-4d]Registering all active panel streams with HDCP\n",
                 *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]Registering all active panel streams with HDCP\n",
                   *(_DWORD *)(StatusReg + 1800));
      v7 = *(_QWORD *)(v4 + 208);
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 916);
        LOBYTE(v16) = 0;
        BYTE1(v16) = v8;
        v9 = 1;
      }
      else
      {
        v9 = 0;
      }
      v10 = *(_QWORD *)(v4 + 216);
      if ( v10 )
      {
        v11 = v9 + 1;
        v12 = (_BYTE *)((unsigned __int64)&v16 | (2LL * v9));
        *v12 = 1;
        v12[1] = *(_DWORD *)(v10 + 916);
      }
      else
      {
        if ( !v7 )
          goto LABEL_24;
        v11 = 1;
      }
      v13 = *(__int64 (__fastcall **)(__int64, __int64, int *))(v3 + 88);
      if ( *((_DWORD *)v13 - 1) != 1655197450 )
        __break(0x8228u);
      result = v13(v2, v11, &v16);
      if ( (_DWORD)result )
      {
        v14 = result;
        if ( !g_dp_display || (v15 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v15 = 0;
        ipc_log_string(v15, "[e][%-4d]failed to register streams. rc = %d\n", *(_DWORD *)(StatusReg + 1800), v14);
        result = printk(&unk_230E53, "dp_display_hdcp_register_streams");
      }
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
