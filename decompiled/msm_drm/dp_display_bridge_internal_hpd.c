__int64 __fastcall dp_display_bridge_internal_hpd(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x20
  void (*v10)(void); // x8

  v3 = *(_QWORD *)(a1 + 1168);
  if ( !v3 )
    return 4294967280LL;
  if ( *(_BYTE *)(v3 + 936) != 1 )
    return 4294967280LL;
  if ( (a3 & 1) != 0 )
  {
    v4 = a1;
    if ( *(_BYTE *)(a1 + 1832) == 1 )
    {
      v5 = *(void (__fastcall **)(_QWORD))(a1 + 1848);
      if ( v5 )
      {
        v6 = a1 + 1168;
        if ( *((_DWORD *)v5 - 1) != 251140989 )
          __break(0x8228u);
        v5(v6);
        a1 = v4;
      }
    }
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v7,
      "[d][%-4d]mst_attention_work. mst_active:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(a1 + 1832));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]mst_attention_work. mst_active:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(unsigned __int8 *)(v4 + 1832));
  }
  else
  {
    v10 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 48LL);
    if ( *((_DWORD *)v10 - 1) != -517830654 )
      __break(0x8228u);
    v10();
  }
  return 0;
}
