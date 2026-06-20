__int64 __fastcall sde_crtc_atomic_set_property(__int64 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v8; // w0
  __int64 result; // x0
  int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  int v14; // w24
  const void *blob; // x0
  size_t v16; // x7
  const void *v17; // x6
  __int64 v18; // x9
  int output_fence; // w0
  void *v20; // x0
  unsigned int v21; // w20
  int v22; // w23
  __int64 v23; // [xsp+10h] [xbp-20h] BYREF
  __int64 v24; // [xsp+18h] [xbp-18h] BYREF
  size_t v25[2]; // [xsp+20h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  if ( !a1 || !a2 || !a3 )
  {
    printk(&unk_253460, "sde_crtc_atomic_set_property");
    result = 4294967274LL;
    goto LABEL_14;
  }
  _ReadStatusReg(SP_EL0);
  v8 = sde_cp_crtc_set_property(a1, a2, a3, a4);
  if ( v8 != -2 )
    goto LABEL_6;
  v8 = msm_property_atomic_set(a1 + 325, a2 + 768, a3, a4);
  if ( v8 )
    goto LABEL_6;
  v10 = msm_property_index(a1 + 325, a3);
  if ( v10 <= 11 )
  {
    if ( v10 > 5 )
    {
      if ( (unsigned int)(v10 - 9) < 3 )
      {
        *(_BYTE *)(a2 + 481) = 1;
        goto LABEL_8;
      }
      if ( v10 != 6 )
      {
        if ( v10 == 8 )
          sde_crtc_set_dim_layer_v1((int)a1, a2, a4);
        goto LABEL_8;
      }
      if ( !a4 )
      {
LABEL_8:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "%s: %s[%d] <= 0x%llx\n",
            (const char *)a1[4],
            (const char *)(a3 + 52),
            *(_DWORD *)(a3 + 16),
            a4);
        result = 0;
        goto LABEL_14;
      }
      if ( (unsigned int)inline_copy_from_user_2((int)&v23, a4, 8u) )
      {
        printk(&unk_276C1D, "sde_crtc_atomic_set_property");
      }
      else
      {
        if ( v23 != -1 )
          goto LABEL_8;
        output_fence = sde_crtc_get_output_fence(a1, a2, &v24);
        if ( output_fence )
        {
          v22 = output_fence;
          printk(&unk_21219E, "sde_crtc_atomic_set_property");
          v8 = v22;
          goto LABEL_6;
        }
        if ( !(unsigned int)inline_copy_to_user_1(a4, &v24, 8) )
          goto LABEL_8;
        printk(&unk_2121D2, "sde_crtc_atomic_set_property");
        put_unused_fd((unsigned int)v24);
      }
      v8 = -14;
      goto LABEL_69;
    }
    if ( (unsigned int)(v10 - 1) >= 3 )
    {
      if ( v10 == 5 )
        *(_QWORD *)(a2 + 1800) = 1000000LL * *(_QWORD *)(a2 + 960);
      goto LABEL_8;
    }
    v11 = *a1;
    v25[0] = 0;
    if ( v11 && (v12 = *(_QWORD *)(v11 + 56)) != 0 )
    {
      v13 = *(_QWORD *)(v12 + 8);
      if ( v13 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(v13 + 152) + 16LL) == 22 )
        {
          v8 = 0;
          goto LABEL_6;
        }
        v14 = v10;
        blob = (const void *)msm_property_get_blob(a1 + 325, a2 + 768, v25);
        v16 = v25[0];
        v17 = blob;
        if ( !blob || !v25[0] )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "%s: lut(%d): cleared: %pK, %zu\n", (const char *)a1 + 2176, v14, blob, v25[0]);
          v16 = 0;
          v17 = nullptr;
          v25[0] = 0;
        }
        if ( v14 == 3 )
        {
          *(_QWORD *)(a2 + 4464) = v17;
          *(_QWORD *)(a2 + 4472) = v16;
          v18 = *(_QWORD *)(a2 + 4432);
          if ( !v18 )
            goto LABEL_63;
        }
        else if ( v14 == 2 )
        {
          *(_QWORD *)(a2 + 4448) = v17;
          *(_QWORD *)(a2 + 4456) = v16;
          v18 = *(_QWORD *)(a2 + 4432);
          if ( !v18 )
          {
LABEL_63:
            *(_BYTE *)(a2 + 4424) = v18;
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_crtc_set_dest_scaler_lut",
              3009,
              4,
              *((_DWORD *)a1 + 28),
              0,
              v14,
              v25[0],
              v18);
            v8 = 0;
            goto LABEL_6;
          }
        }
        else
        {
          *(_QWORD *)(a2 + 4432) = v17;
          *(_QWORD *)(a2 + 4440) = v16;
          v18 = *(_QWORD *)(a2 + 4432);
          if ( !v18 )
            goto LABEL_63;
        }
        v18 = *(_QWORD *)(a2 + 4448);
        if ( v18 )
          LOBYTE(v18) = *(_QWORD *)(a2 + 4464) != 0;
        goto LABEL_63;
      }
      v20 = &unk_234896;
    }
    else
    {
      v20 = &unk_25E167;
    }
    printk(v20, "_sde_crtc_get_kms");
    v8 = -22;
    goto LABEL_6;
  }
  if ( v10 <= 17 )
  {
    if ( (unsigned int)(v10 - 12) < 4 )
      *(_WORD *)(a2 + 481) = 257;
    goto LABEL_8;
  }
  if ( v10 > 24 )
  {
    if ( v10 == 25 )
    {
      sde_crtc_set_noise_layer((int)a1, a2, a4);
    }
    else if ( v10 == 26 )
    {
      sde_crtc_set_frame_data_buffers(a1, a4);
    }
    goto LABEL_8;
  }
  if ( v10 == 18 )
  {
    v8 = sde_crtc_set_roi_v1(a2, a4);
  }
  else
  {
    if ( v10 != 20 )
      goto LABEL_8;
    v8 = sde_crtc_set_dest_scaler(a1, a2, a4);
  }
LABEL_6:
  if ( v8 != -1 )
  {
    if ( !v8 )
      goto LABEL_8;
LABEL_69:
    v21 = v8;
    printk(&unk_268AE2, "sde_crtc_atomic_set_property");
    result = v21;
    goto LABEL_14;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "%s: failed to set property%d %s: %d\n",
      (const char *)a1[4],
      *(_DWORD *)(a3 + 16),
      (const char *)(a3 + 52),
      -1);
  result = 0xFFFFFFFFLL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
