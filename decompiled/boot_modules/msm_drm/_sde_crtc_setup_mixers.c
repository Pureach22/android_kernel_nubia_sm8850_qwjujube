__int64 __fastcall sde_crtc_setup_mixers(__int64 a1)
{
  __int64 *i; // x23
  __int64 v3; // x8
  __int64 v4; // x26
  __int64 v5; // x24
  __int64 v6; // x21
  __int64 v7; // x28
  __int64 v8; // x8
  __int64 primary_ctl_in_lb; // x0
  char v10; // w9
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 result; // x0
  __int64 v14; // [xsp+0h] [xbp-70h]
  _QWORD v15[3]; // [xsp+8h] [xbp-68h] BYREF
  _QWORD v16[3]; // [xsp+20h] [xbp-50h] BYREF
  _QWORD v17[3]; // [xsp+38h] [xbp-38h] BYREF
  _QWORD v18[4]; // [xsp+50h] [xbp-20h] BYREF

  v18[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 4616);
  *(_BYTE *)(a1 + 2196) = 0;
  *(_QWORD *)(a1 + 2188) = 0;
  v14 = a1 + 2200;
  memset((void *)(a1 + 2200), 0, 0x180u);
  for ( i = *(__int64 **)(*(_QWORD *)a1 + 816LL); i != (__int64 *)(*(_QWORD *)a1 + 816LL); i = (__int64 *)*i )
  {
    if ( i[9] == a1 && (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1) & 1) == 0 )
    {
      if ( a1 && *(_QWORD *)a1 && (v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
      {
        v4 = *(_QWORD *)(v3 + 8);
        if ( !v4 )
          printk(&unk_234896, "_sde_crtc_get_kms");
      }
      else
      {
        printk(&unk_25E167, "_sde_crtc_get_kms");
        v4 = 0;
      }
      memset(v18, 0, 24);
      memset(v17, 0, sizeof(v17));
      memset(v16, 0, sizeof(v16));
      memset(v15, 0, sizeof(v15));
      sde_rm_init_hw_iter(v18, *((unsigned int *)i + 4), 2);
      sde_rm_init_hw_iter(v17, *((unsigned int *)i + 4), 5);
      sde_rm_init_hw_iter(v16, *((unsigned int *)i + 4), 3);
      sde_rm_init_hw_iter(v15, *((unsigned int *)i + 4), 4);
      v5 = *(unsigned int *)(a1 + 2192);
      if ( (unsigned int)v5 <= 7 )
      {
        v6 = 0;
        v7 = v14 + 48LL * (unsigned int)v5;
        while ( (sde_rm_get_hw(v4 + 2144, v18) & 1) != 0 )
        {
          v8 = v18[0];
          *(_BYTE *)(v7 + 44) = 0;
          *(_QWORD *)v7 = v8;
          if ( i != (__int64 *)&unk_8 && (*((_BYTE *)i + 636) & 0x80) != 0 )
          {
            primary_ctl_in_lb = sde_get_primary_ctl_in_lb(*(__int64 ***)(a1 + 2008));
            *(_QWORD *)(v7 + 8) = primary_ctl_in_lb;
            v6 = primary_ctl_in_lb;
            ++*(_DWORD *)(a1 + 2188);
            *(_BYTE *)(v7 + 44) = 1;
            if ( !primary_ctl_in_lb )
              goto LABEL_3;
          }
          else if ( (sde_rm_get_hw(v4 + 2144, v17) & 1) != 0 )
          {
            v6 = v17[0];
            *(_QWORD *)(v7 + 8) = v17[0];
            ++*(_DWORD *)(a1 + 2188);
            if ( !v6 )
              goto LABEL_3;
          }
          else
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "no ctl assigned to lm %d, using previous\n", *(_DWORD *)(*(_QWORD *)v7 + 32LL) - 1);
            *(_QWORD *)(v7 + 8) = v6;
            if ( !v6 )
            {
LABEL_3:
              printk(&unk_24FD88, "_sde_crtc_setup_mixer_for_encoder");
              break;
            }
          }
          sde_rm_get_hw(v4 + 2144, v16);
          *(_QWORD *)(v7 + 16) = v16[0];
          sde_rm_get_hw(v4 + 2144, v15);
          *(_QWORD *)(v7 + 24) = v15[0];
          *(_QWORD *)(v7 + 32) = i - 1;
          v10 = _drm_debug;
          ++*(_DWORD *)(a1 + 2192);
          if ( (v10 & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "setup mixer %d: lm %d\n", v5, *(_DWORD *)(*(_QWORD *)v7 + 32LL) - 1);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "setup mixer %d: ctl %d\n", v5, *(_DWORD *)(*(_QWORD *)(v7 + 8) + 64LL) - 1);
          }
          v11 = *(_QWORD *)(v7 + 24);
          if ( v11 && (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "setup mixer %d: ds %d\n", v5, *(_DWORD *)(v11 + 32) - 1);
          ++v5;
          v7 += 48;
          if ( v5 == 8 )
            break;
        }
      }
    }
  }
  mutex_unlock(a1 + 4616);
  v12 = *(_QWORD *)(a1 + 2008);
  if ( *(_BYTE *)(v12 + 6921) == 1 )
  {
    sort(v14, *(unsigned int *)(a1 + 2192), 48, crtc_cmp, 0);
    v12 = *(_QWORD *)(a1 + 2008);
  }
  result = sde_crtc_check_dest_scaler_data(a1, v12);
  _ReadStatusReg(SP_EL0);
  return result;
}
