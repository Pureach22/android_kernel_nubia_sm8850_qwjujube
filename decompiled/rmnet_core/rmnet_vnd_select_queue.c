__int64 __fastcall rmnet_vnd_select_queue(__int64 a1, __int64 a2)
{
  unsigned int queue; // w21
  unsigned int v5; // w8
  int v7; // [xsp+Ch] [xbp-74h] BYREF
  unsigned __int64 v8[14]; // [xsp+10h] [xbp-70h] BYREF

  v8[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v7 = 0;
  rmnet_module_hook_perf_egress(a2);
  if ( *(_QWORD *)(a1 + 2696) )
    queue = qmi_rmnet_get_queue(a1, a2);
  else
    queue = 0;
  if ( rmnet_core_userspace_connected )
    rmnet_update_pid_and_check_boost(*(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), *(_DWORD *)(a2 + 112), &v7, v8);
  rmnet_module_hook_aps_pre_queue(a1, a2);
  v5 = *(_DWORD *)(a1 + 40);
  _ReadStatusReg(SP_EL0);
  if ( queue >= v5 )
    return 0;
  else
    return queue;
}
