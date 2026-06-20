__int64 __fastcall hw_fence_dbg_reset_client_wr(__int64 a1, int a2, size_t a3)
{
  __int64 v3; // x30
  __int64 v4; // x21
  __int64 v5; // x19
  unsigned int debugfs_input_client_with_min; // w0
  __int64 v7; // x23
  unsigned int v8; // w20
  _QWORD *v9; // x22
  __int64 v10; // x4
  unsigned __int64 v11; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = v3;
  v5 = a3;
  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  debugfs_input_client_with_min = get_debugfs_input_client_with_min(a1, a2, a3, v13, 1);
  if ( (debugfs_input_client_with_min & 0x80000000) != 0 )
  {
LABEL_14:
    v5 = -22;
    goto LABEL_15;
  }
  v7 = v13[0];
  v8 = debugfs_input_client_with_min;
  mutex_lock(v13[0] + 544LL);
  v9 = (_QWORD *)(v7 + 528);
  do
  {
    v9 = (_QWORD *)*v9;
    if ( v9 == (_QWORD *)(v7 + 528) )
    {
      mutex_unlock(v7 + 544);
LABEL_13:
      printk(&unk_27072, "hw_fence_dbg_reset_client_wr", 266, v4, v8);
      goto LABEL_14;
    }
  }
  while ( *((_DWORD *)v9 - 16) != v8 );
  mutex_unlock(v7 + 544);
  if ( v9 == &qword_40 )
    goto LABEL_13;
  v11 = *(v9 - 5);
  if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_13;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    printk(&unk_2481F, "hw_fence_dbg_reset_client_wr", 270, v8, v10);
  if ( (unsigned int)msm_hw_fence_reset_client() )
    printk(&unk_29688, "hw_fence_dbg_reset_client_wr", 273, v4, v8);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v5;
}
