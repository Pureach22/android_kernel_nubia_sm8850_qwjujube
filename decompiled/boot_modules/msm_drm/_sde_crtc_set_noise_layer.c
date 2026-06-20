__int64 __fastcall sde_crtc_set_noise_layer(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  unsigned int v9; // w4
  unsigned int v10; // w8
  void *v11; // x0
  unsigned __int64 v14; // x9
  unsigned __int64 v21; // x9

  v5 = result;
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "crtc %s\n", (const char *)(result + 2176));
  if ( a3 )
  {
    result = inline_copy_from_user_2((int)a2 + 4576, a3, 0x20u);
    if ( (_DWORD)result )
      return printk(&unk_24C4A0, "_sde_crtc_set_noise_layer");
    if ( v5 && *(_QWORD *)v5 && (v6 = *(_QWORD *)(*(_QWORD *)v5 + 56LL)) != 0 )
    {
      v7 = *(_QWORD *)(v6 + 8);
      if ( v7 )
      {
        v8 = *(_QWORD *)(v7 + 152);
        if ( v8 )
        {
          v9 = *(_DWORD *)(a2 + 4588);
          if ( (*(_QWORD *)(v8 + 22008) & 0x400000000000LL) != 0 )
            v10 = 0xFFFF;
          else
            v10 = 255;
          if ( v9 > 0xB
            || *(_DWORD *)(a2 + 4584) != v9 - 1
            || *(_DWORD *)(a2 + 4592) - 1 >= v10
            || *(_DWORD *)(a2 + 4596) > 6u
            || *(_DWORD *)(a2 + 4600) - 1 >= v10 )
          {
            return printk(&unk_24C4D8, "_sde_crtc_set_noise_layer");
          }
          *(_BYTE *)(a2 + 4568) = 1;
          _X8 = (unsigned __int64 *)(a2 + 1792);
          __asm { PRFM            #0x11, [X8] }
          do
            v21 = __ldxr(_X8);
          while ( __stxr(v21 | 4, _X8) );
          return result;
        }
        return printk(&unk_27D36D, "_sde_crtc_set_noise_layer");
      }
      v11 = &unk_234896;
    }
    else
    {
      v11 = &unk_25E167;
    }
    printk(v11, "_sde_crtc_get_kms");
    return printk(&unk_27D36D, "_sde_crtc_set_noise_layer");
  }
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "noise layer removed\n");
  *(_BYTE *)(a2 + 4568) = 0;
  _X8 = (unsigned __int64 *)(a2 + 1792);
  __asm { PRFM            #0x11, [X8] }
  do
    v14 = __ldxr(_X8);
  while ( __stxr(v14 | 4, _X8) );
  return result;
}
