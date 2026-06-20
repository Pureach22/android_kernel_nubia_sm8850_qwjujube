__int64 __fastcall drm_dp_mst_topology_mgr_set_mst(__int64 a1, char a2)
{
  int v4; // w20
  char v5; // w8
  unsigned int dpcd_caps; // w0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x1
  unsigned int v11; // w21
  _QWORD *v12; // x0
  unsigned int v13; // w22
  __int64 v14; // x8
  __int64 v15; // x1
  _QWORD *v16; // x0
  __int64 v18; // x1
  unsigned int v24; // w8
  char v25[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v4 = a2 & 1;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 800);
  v5 = *(_BYTE *)(a1 + 896);
  if ( (v5 & 1) == v4 )
  {
    v11 = 0;
  }
  else
  {
    _X20 = *(_QWORD **)(a1 + 904);
    *(_BYTE *)(a1 + 896) = v5 & 0xFE | a2 & 1;
    if ( (a2 & 1) == 0 )
    {
      v12 = *(_QWORD **)(a1 + 128);
      *(_QWORD *)(a1 + 904) = 0;
      v26[0] = 0;
      drm_dp_dpcd_write(v12, 0x111u, (__int64)v26, 1);
      *(_BYTE *)(a1 + 896) &= ~2u;
      memset((void *)(a1 + 470), 0, 0x146u);
      memset((void *)(a1 + 144), 0, 0x146u);
      mutex_unlock(a1 + 800);
      v13 = 0;
      v11 = 0;
      if ( !_X20 )
        goto LABEL_24;
      goto LABEL_23;
    }
    if ( _X20 )
      __break(0x800u);
    dpcd_caps = drm_dp_read_dpcd_caps(*(const char ***)(a1 + 128), (_BYTE *)(a1 + 912));
    if ( (dpcd_caps & 0x80000000) != 0 )
    {
      v14 = *(_QWORD *)(a1 + 104);
      v11 = dpcd_caps;
      if ( v14 )
        v15 = *(_QWORD *)(v14 + 8);
      else
        v15 = 0;
      _drm_dev_dbg(0, v15, 2, "%s: failed to read DPCD, ret %d\n", **(const char ***)(a1 + 128), dpcd_caps);
    }
    else
    {
      v8 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
      _X20 = (_QWORD *)v8;
      if ( v8 )
      {
        *(_BYTE *)(v8 + 32) = 1;
        *(_QWORD *)(v8 + 40) = v8 + 40;
        *(_QWORD *)(v8 + 48) = v8 + 40;
        *(_DWORD *)v8 = 1;
        *(_DWORD *)(v8 + 4) = 1;
        *(_QWORD *)(v8 + 64) = a1;
        *(_QWORD *)(a1 + 904) = v8;
        if ( !*(_DWORD *)v8 )
          __break(0x800u);
        __asm { PRFM            #0x11, [X20] }
        do
          v24 = __ldxr((unsigned int *)v8);
        while ( __stxr(v24 + 1, (unsigned int *)v8) );
        if ( v24 )
        {
          if ( (((v24 + 1) | v24) & 0x80000000) == 0 )
          {
LABEL_11:
            v9 = *(_QWORD *)(_X20[8] + 104LL);
            if ( v9 )
              v10 = *(_QWORD *)(v9 + 8);
            else
              v10 = 0;
            _drm_dev_dbg(0, v10, 1, "mstb %p (%d)\n", _X20, *(_DWORD *)_X20);
            v16 = *(_QWORD **)(a1 + 128);
            v25[0] = 7;
            v13 = drm_dp_dpcd_write(v16, 0x111u, (__int64)v25, 1);
            if ( (v13 & 0x80000000) == 0 )
            {
              drm_dp_dpcd_write_payload(a1, 0, 0, 63);
              queue_work_on(32, system_long_wq, a1 + 1024);
              v13 = 0;
            }
            mutex_unlock(a1 + 800);
LABEL_23:
            drm_dp_mst_topology_put_mstb(_X20);
            v11 = v13;
            goto LABEL_24;
          }
          v18 = 1;
        }
        else
        {
          v18 = 2;
        }
        refcount_warn_saturate(v8, v18);
        goto LABEL_11;
      }
      v11 = -12;
    }
  }
  mutex_unlock(a1 + 800);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v11;
}
