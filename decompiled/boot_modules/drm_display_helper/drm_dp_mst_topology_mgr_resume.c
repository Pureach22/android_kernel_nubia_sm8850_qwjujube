__int64 __fastcall drm_dp_mst_topology_mgr_resume(__int64 a1, char a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x1
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x8
  __int64 v13; // x1
  __int64 result; // x0
  char v15[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-28h] BYREF
  __int64 v17; // [xsp+10h] [xbp-20h]
  __int64 v18; // [xsp+18h] [xbp-18h] BYREF
  __int64 v19; // [xsp+20h] [xbp-10h]
  __int64 v20; // [xsp+28h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  mutex_lock(a1 + 800);
  if ( !*(_QWORD *)(a1 + 904) )
  {
LABEL_21:
    mutex_unlock(a1 + 800);
    result = 0xFFFFFFFFLL;
    goto LABEL_22;
  }
  if ( (drm_dp_read_dpcd_caps(*(const char ***)(a1 + 128), (_BYTE *)(a1 + 912)) & 0x80000000) != 0 )
    goto LABEL_8;
  v4 = *(_QWORD **)(a1 + 128);
  v15[0] = 7;
  if ( (drm_dp_dpcd_write(v4, 0x111u, (__int64)v15, 1) & 0x80000000) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 104);
    if ( v10 )
      v11 = *(_QWORD *)(v10 + 8);
    else
      v11 = 0;
    _drm_dev_dbg(0, v11, 2, "mst write failed - undocked during suspend?\n");
    goto LABEL_21;
  }
  if ( (unsigned int)drm_dp_dpcd_read(*(_QWORD **)(a1 + 128), 0x30u, (__int64)&v18, 16) != 16 )
  {
LABEL_8:
    v8 = *(_QWORD *)(a1 + 104);
    if ( v8 )
      v9 = *(_QWORD *)(v8 + 8);
    else
      v9 = 0;
    _drm_dev_dbg(0, v9, 2, "dpcd read failed - undocked during suspend?\n");
    goto LABEL_21;
  }
  v5 = *(_QWORD *)(a1 + 904);
  v16 = v18;
  v17 = v19;
  if ( (unsigned int)drm_dp_check_mstb_guid(v5, &v16) )
  {
    v6 = *(_QWORD *)(a1 + 104);
    if ( v6 )
      v7 = *(_QWORD *)(v6 + 8);
    else
      v7 = 0;
    _drm_dev_dbg(0, v7, 2, "check mstb failed - undocked during suspend?\n");
    goto LABEL_21;
  }
  queue_work_on(32, system_long_wq, a1 + 1024);
  mutex_unlock(a1 + 800);
  if ( (a2 & 1) != 0 )
  {
    v12 = *(_QWORD *)(a1 + 104);
    if ( v12 )
      v13 = *(_QWORD *)(v12 + 8);
    else
      v13 = 0;
    _drm_dev_dbg(0, v13, 2, "Waiting for link probe work to finish re-syncing topology...\n");
    flush_work(a1 + 1024);
  }
  result = 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
