__int64 init_module()
{
  __int64 v0; // x0
  unsigned int v1; // w0
  unsigned int v2; // w19
  unsigned __int64 v3; // x8
  unsigned __int64 StatusReg; // x8
  _DWORD v6[2]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v7; // [xsp+10h] [xbp-80h]
  __int64 v8; // [xsp+18h] [xbp-78h]
  __int64 v9; // [xsp+20h] [xbp-70h]
  _DWORD v10[2]; // [xsp+28h] [xbp-68h] BYREF
  __int64 v11; // [xsp+30h] [xbp-60h]
  __int64 v12; // [xsp+38h] [xbp-58h]
  __int64 v13; // [xsp+40h] [xbp-50h]
  _DWORD v14[2]; // [xsp+48h] [xbp-48h] BYREF
  __int64 v15; // [xsp+50h] [xbp-40h]
  __int64 v16; // [xsp+58h] [xbp-38h]
  __int64 v17; // [xsp+60h] [xbp-30h]
  _QWORD v18[5]; // [xsp+68h] [xbp-28h] BYREF

  v18[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = _kmalloc_cache_noprof(platform_driver_unregister, 3520, 264);
  cvp_driver = v0;
  if ( v0 )
  {
    _mutex_init(v0, "&cvp_driver->lock", &msm_cvp_init___key);
    v1 = _platform_driver_register(msm_cvp_driver, &_this_module);
    if ( v1 )
    {
      v2 = v1;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_91176, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      kfree(cvp_driver);
      cvp_driver = 0;
    }
    else
    {
      v18[0] = 8;
      memset(&v18[1], 0, 24);
      v14[1] = 0;
      v15 = 0;
      *(_QWORD *)(cvp_driver + 72) = _kmem_cache_create_args("cvp_session_msg", 336, v18, 0);
      v16 = 0;
      v17 = 0;
      v14[0] = 8;
      v10[1] = 0;
      v11 = 0;
      *(_QWORD *)(cvp_driver + 88) = _kmem_cache_create_args("msm_cvp_frame", 2600, v14, 0);
      v12 = 0;
      v13 = 0;
      v10[0] = 8;
      v6[1] = 0;
      v7 = 0;
      *(_QWORD *)(cvp_driver + 104) = _kmem_cache_create_args("cvp_internal_buf", 64, v10, 0);
      v8 = 0;
      v9 = 0;
      v6[0] = 8;
      *(_QWORD *)(cvp_driver + 120) = _kmem_cache_create_args("msm_cvp_smem", 152, v6, 0);
      _mutex_init(&wncc_buf_pool, "&wncc_buf_pool.lock", &msm_cvp_init___key_10);
      v2 = 0;
    }
  }
  else
  {
    v2 = -12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v3 = _ReadStatusReg(SP_EL0);
      printk(&unk_8D90A, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
