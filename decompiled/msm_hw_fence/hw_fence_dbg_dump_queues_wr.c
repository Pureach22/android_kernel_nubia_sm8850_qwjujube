__int64 __fastcall hw_fence_dbg_dump_queues_wr(__int64 a1, int a2, size_t a3)
{
  __int64 v3; // x19
  int debugfs_input_client_with_min; // w0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a3;
  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  debugfs_input_client_with_min = get_debugfs_input_client_with_min(a1, a2, a3, v6, 0);
  if ( debugfs_input_client_with_min < 0 )
    v3 = -22;
  else
    *(int *)((char *)&dword_200 + v6[0]) = debugfs_input_client_with_min;
  _ReadStatusReg(SP_EL0);
  return v3;
}
