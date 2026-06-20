__int64 __fastcall sde_crtc_mode_fixup(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 *v6; // x23
  __int64 v7; // x9
  __int64 v8; // x8
  _QWORD *v9; // x9
  __int64 v10; // x10
  void *v12; // x0

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  v5 = **(_QWORD **)(a3 - 24);
  v6 = *(__int64 **)(v5 + 816);
  while ( 1 )
  {
    if ( v6 == (__int64 *)(v5 + 816) )
    {
      v12 = &unk_22095A;
      goto LABEL_22;
    }
    if ( ((*(_DWORD *)(a3 - 4) >> *((_DWORD *)v6 + 15)) & 1) != 0
      && (a3 == 24
       || v6 == (__int64 *)&unk_8
       || (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v6 - 1) & 1) == 0
       && ((*(_DWORD *)(a3 + 1788) >> *((_DWORD *)v6 + 15)) & 1) == 0) )
    {
      break;
    }
    v6 = (__int64 *)*v6;
    v5 = **(_QWORD **)(a3 - 24);
  }
  v7 = *(_QWORD *)(a3 + 304);
  v8 = *(unsigned int *)(v7 + 40);
  if ( (int)v8 < 1 )
    goto LABEL_20;
  v9 = *(_QWORD **)(v7 + 48);
  while ( 1 )
  {
    if ( *v9 )
    {
      v10 = v9[3];
      if ( *(__int64 **)(v10 + 16) == v6 - 1 )
        break;
    }
    --v8;
    v9 += 5;
    if ( !v8 )
      goto LABEL_20;
  }
  if ( !v10 )
  {
LABEL_20:
    v12 = &unk_21221C;
LABEL_22:
    printk(v12, "sde_crtc_mode_fixup");
    return 1;
  }
  if ( (*(_BYTE *)(v10 + 3240) & 0x38) != 0 && (*(_BYTE *)(a1 + 172) & 1) == 0 )
  {
    printk(&unk_22706B, "sde_crtc_mode_fixup");
    return 0;
  }
  return 1;
}
