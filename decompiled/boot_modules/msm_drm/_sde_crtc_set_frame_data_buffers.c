__int64 __fastcall sde_crtc_set_frame_data_buffers(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned __int64 v3; // x22
  unsigned int v4; // w20
  __int64 v5; // x28
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  bool v10; // cf
  void *v11; // x0
  unsigned int v12; // w9
  unsigned int v13; // w8
  __int64 v14; // x20
  _QWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = result;
    v15[0] = 0;
    v15[1] = 0;
    result = inline_copy_from_user_2((int)v15, a2, 0x10u);
    if ( (_DWORD)result )
    {
      result = printk(&unk_2534B8, "_sde_crtc_set_frame_data_buffers");
    }
    else
    {
      if ( LODWORD(v15[0]) )
      {
        if ( LODWORD(v15[0]) > 3 )
        {
          result = printk(&unk_261F45, "_sde_crtc_set_frame_data_buffers");
          goto LABEL_30;
        }
        v3 = 1;
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          if ( v3 == 4 )
            goto LABEL_31;
          v4 = *((_DWORD *)v15 + v3);
          v5 = *(unsigned int *)(v2 + 7884);
          v6 = _kmalloc_cache_noprof(wake_up_process, 3520, 24);
          if ( !v6 )
            goto LABEL_22;
          if ( (unsigned int)v5 >= 3 )
            goto LABEL_31;
          v7 = *(_QWORD *)v2;
          *(_QWORD *)(v2 + 7888 + 8 * v5) = v6;
          *(_DWORD *)v6 = v4;
          v8 = drm_framebuffer_lookup(v7, 0, v4);
          *(_QWORD *)(v6 + 8) = v8;
          if ( !v8 )
          {
            v11 = &unk_22AA8A;
            goto LABEL_21;
          }
          v9 = msm_framebuffer_bo(v8, 0);
          *(_QWORD *)(v6 + 16) = v9;
          if ( !v9 )
            break;
          result = msm_gem_get_buffer(v9, *(_QWORD *)v2, *(_QWORD *)(v6 + 8), 816);
          if ( (_DWORD)result )
            goto LABEL_22;
          v10 = v3++ >= LODWORD(v15[0]);
          ++*(_DWORD *)(v2 + 7884);
          if ( v10 )
            goto LABEL_30;
        }
        v11 = &unk_27D393;
LABEL_21:
        printk(v11, "_sde_crtc_get_frame_data_buffer");
LABEL_22:
        result = printk(&unk_23B781, "_sde_crtc_set_frame_data_buffers");
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        result = _drm_dev_dbg(0, 0, 0, "clearing frame data buffers");
      }
      v12 = *(_DWORD *)(v2 + 7884);
      v13 = v12 - 1;
      *(_DWORD *)(v2 + 7884) = v12 - 1;
      if ( v12 )
      {
        while ( v12 <= 3 )
        {
          v14 = *(_QWORD *)(v2 + 7888 + 8LL * v13);
          if ( v14 )
          {
            msm_gem_put_buffer(*(_QWORD *)(v14 + 16));
            result = kfree(v14);
            v13 = *(_DWORD *)(v2 + 7884);
          }
          v12 = v13--;
          *(_DWORD *)(v2 + 7884) = v13;
          if ( !v12 )
            goto LABEL_29;
        }
LABEL_31:
        __break(0x5512u);
        __break(1u);
      }
LABEL_29:
      *(_DWORD *)(v2 + 7884) = 0;
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
