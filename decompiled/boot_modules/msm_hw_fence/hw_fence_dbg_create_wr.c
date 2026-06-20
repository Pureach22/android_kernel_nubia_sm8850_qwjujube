__int64 __fastcall hw_fence_dbg_create_wr(__int64 a1, int a2, size_t a3)
{
  __int64 v3; // x30
  __int64 v4; // x19
  unsigned int debugfs_input_client_with_min; // w0
  __int64 v7; // x22
  unsigned int v8; // w20
  _QWORD *v9; // x23
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x22
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-38h] BYREF
  __int64 v14; // [xsp+10h] [xbp-30h] BYREF
  __int64 v15; // [xsp+18h] [xbp-28h] BYREF
  __int64 *v16; // [xsp+20h] [xbp-20h]
  unsigned __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v4 = v3;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = nullptr;
  v13 = 0;
  v14 = 0;
  debugfs_input_client_with_min = get_debugfs_input_client_with_min(a1, a2, a3, &v14, 1);
  if ( (debugfs_input_client_with_min & 0x80000000) != 0 )
    goto LABEL_14;
  v7 = v14;
  v8 = debugfs_input_client_with_min;
  mutex_lock(v14 + 544);
  v9 = (_QWORD *)(v7 + 528);
  do
  {
    v9 = (_QWORD *)*v9;
    if ( v9 == (_QWORD *)(v7 + 528) )
    {
      mutex_unlock(v7 + 544);
LABEL_13:
      printk(&unk_27072, "hw_fence_dbg_create_wr", 511, v4, v8);
      goto LABEL_14;
    }
  }
  while ( *((_DWORD *)v9 - 16) != v8 );
  mutex_unlock(v7 + 544);
  if ( v9 == &qword_40 )
    goto LABEL_13;
  v10 = *(v9 - 5);
  if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_13;
  v11 = hw_dma_fence_init();
  result = -22;
  if ( v11 && v11 <= 0xFFFFFFFFFFFFF000LL )
  {
    v16 = &v13;
    v17 = v11;
    if ( !(unsigned int)msm_hw_fence_create(*(v9 - 5), &v15) )
    {
      result = a3;
      ++hw_fence_dbg_create_wr_hw_fence_dbg_seqno;
      *(_QWORD *)(v11 + 128) = *(v9 - 5);
      goto LABEL_15;
    }
    printk(&unk_28479, "hw_fence_dbg_create_wr", 526, v4, v8);
    dma_fence_put((unsigned int *)v11);
LABEL_14:
    result = -22;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
