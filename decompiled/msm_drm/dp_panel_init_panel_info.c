__int64 __fastcall dp_panel_init_panel_info(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  char v6[4]; // [xsp+0h] [xbp-10h] BYREF
  char v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)(a1 + 1192) + 24LL);
    v6[0] = 2;
    drm_dp_dpcd_write(v2, 1536, v6, 1);
    usleep_range_state(200, 205, 2);
    v3 = *(_QWORD *)(a1 + 1192);
    v7[0] = 1;
    drm_dp_dpcd_write(*(_QWORD *)(v3 + 24), 1536, v7, 1);
    usleep_range_state(1000, 2000, 2);
    result = 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_init_panel_info");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
