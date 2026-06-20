__int64 __fastcall dp_display_get_available_dp_resources(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x11
  char v6; // w10
  int v7; // w7
  unsigned int v8; // w8
  __int64 result; // x0
  __int64 v13; // x0

  if ( a1 && a2 && a3 )
  {
    *(_QWORD *)a3 = *(_QWORD *)a2;
    v3 = *(_QWORD *)(a2 + 32);
    v4 = *(_QWORD *)(a2 + 8);
    v5 = *(_QWORD *)(a2 + 16);
    *(_QWORD *)(a3 + 24) = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(a3 + 32) = v3;
    *(_QWORD *)(a3 + 8) = v4;
    *(_QWORD *)(a3 + 16) = v5;
    v6 = _drm_debug;
    if ( *(_DWORD *)(a2 + 4) >= *(_DWORD *)(a1 + 48) )
      v7 = *(_DWORD *)(a1 + 48);
    else
      v7 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a3 + 4) = v7;
    v8 = *(_DWORD *)(a2 + 8);
    if ( v8 >= *(_DWORD *)(a1 + 52) )
      v8 = *(_DWORD *)(a1 + 52);
    *(_DWORD *)(a3 + 8) = v8;
    if ( (v6 & 4) != 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]max_lm:%d, avail_lm:%d, dp_avail_lm:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 48),
        *(_DWORD *)(a2 + 4),
        v7);
      result = 0;
      if ( (_drm_debug & 4) == 0 )
        return result;
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]max_dsc:%d, avail_dsc:%d, dp_avail_dsc:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 52),
        *(_DWORD *)(a2 + 8),
        *(_DWORD *)(a3 + 8));
    }
    return 0;
  }
  else
  {
    if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v13 = 0;
    ipc_log_string(v13, "[e][%-4d]invalid arguments\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_259FDE, "dp_display_get_available_dp_resources");
    return 4294967274LL;
  }
}
