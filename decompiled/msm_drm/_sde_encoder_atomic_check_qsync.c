__int64 __fastcall sde_encoder_atomic_check_qsync(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x22
  bool v5; // w20
  __int64 v6; // x9
  __int64 v7; // x8
  int is_dirty; // w19
  int v9; // w8
  int v10; // w9
  char v11; // w8
  unsigned int v12; // w20
  int v13; // w19
  __int64 (__fastcall *v14)(_QWORD); // x8
  unsigned int v15; // w0
  __int64 v16; // x8
  unsigned int v17; // w23
  __int64 v18; // x8
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w4

  v2 = *(_QWORD *)(a2 + 32);
  v4 = a1;
  v5 = 1;
  if ( v2 )
  {
    v6 = *(_QWORD *)(a2 + 8);
    if ( v6 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)(v2 + 32) + 56LL * *(unsigned int *)(v6 + 160) + 24);
      if ( v7 )
        v5 = (*(_BYTE *)(v7 + 10) & 0xE) == 0;
    }
  }
  is_dirty = msm_property_is_dirty(a1 + 3312, a2 + 448, 33);
  msm_property_is_dirty(v4 + 3312, a2 + 448, 37);
  if ( !v5 && (is_dirty & 1) != 0 && (*(_DWORD *)(a2 + 3240) & 0xD0) != 0 )
  {
    printk(&unk_224241, "_sde_encoder_atomic_check_qsync");
    return 4294967274LL;
  }
  v9 = *(_DWORD *)(a2 + 1536);
  if ( (*(_BYTE *)(v4 + 4715) & 1) != 0 )
  {
    if ( (v9 != 1) | is_dirty & 1 )
      goto LABEL_18;
  }
  else
  {
    v10 = *(unsigned __int8 *)(v4 + 4713);
    if ( v9 == 1 )
      v10 = 0;
    if ( ((v10 | is_dirty) & 1) != 0 )
      goto LABEL_18;
  }
  if ( v9 )
    v11 = v5;
  else
    v11 = 1;
  if ( (v11 & 1) != 0 )
    return 0;
LABEL_18:
  v12 = drm_mode_vrefresh(*(_QWORD *)(a2 + 3232));
  v13 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 3232) + 20LL);
  if ( (*(_BYTE *)(v4 + 4715) & 1) != 0 || (*(_BYTE *)(v4 + 4713) & 1) != 0 )
  {
    v14 = *(__int64 (__fastcall **)(_QWORD))(v4 + 3192);
    if ( !v14 )
      return 0;
  }
  else
  {
    if ( *(_DWORD *)(a2 + 1632) != 1 )
      return 0;
    v14 = *(__int64 (__fastcall **)(_QWORD))(v4 + 3192);
    if ( !v14 )
      return 0;
    if ( !*(_DWORD *)(a2 + 1536) )
    {
      printk(&unk_23F468, "_sde_encoder_avr_step_check");
      return 4294967274LL;
    }
  }
  if ( *((_DWORD *)v14 - 1) != 1917458973 )
    __break(0x8228u);
  v15 = v14(a2);
  v16 = *(_QWORD *)(a2 + 16);
  v17 = v15;
  if ( !v16 )
  {
    printk(&unk_246014, "_sde_encoder_get_qsync_fps_callback");
LABEL_48:
    printk(&unk_2538FD, "_sde_encoder_avr_step_check");
    return 4294967274LL;
  }
  v18 = *(_QWORD *)(v16 + 328);
  if ( !(v4 | v18) )
  {
    printk(&unk_273944, "_sde_encoder_get_qsync_fps_callback");
    goto LABEL_48;
  }
  if ( !v4 )
  {
    v4 = *(_QWORD *)(v18 + 8);
    if ( !v4 )
      goto LABEL_48;
  }
  v19 = *(__int64 (__fastcall **)(_QWORD))(v4 + 3184);
  if ( !v19 )
    goto LABEL_48;
  if ( *((_DWORD *)v19 - 1) != 1917458973 )
    __break(0x8228u);
  v20 = v19(a2);
  if ( (v20 & 0x80000000) != 0 )
  {
    printk(&unk_26211F, "_sde_encoder_get_qsync_fps_callback");
    goto LABEL_48;
  }
  if ( !v20 || !v12 || v17 % v12 || v17 % v20 || v17 < v12 || v12 * v13 % v17 )
    goto LABEL_48;
  return 0;
}
