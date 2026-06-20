__int64 __fastcall wcd_mbhc_initialise(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x9
  void (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x9
  void (__fastcall *v10)(_QWORD); // x10
  _DWORD *v11; // x8
  __int64 v12; // x9
  void (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x8
  __int64 v19; // x1
  __int64 v20; // x1
  __int64 v21; // x1
  void (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v25; // x8
  __int64 v26; // x1
  __int64 v27; // x0
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x8
  __int64 v31; // x1
  int v32; // w9
  void (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x8
  __int64 v35; // x1
  __int64 v36; // x8
  __int64 v37; // x1
  void (__fastcall *v38)(__int64, __int64); // x8
  void (__fastcall *v39)(__int64, _BOOL8); // x8
  _BOOL8 v40; // x1
  __int64 v41; // x8
  __int64 v42; // x1
  __int64 v43; // x9
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x3
  __int64 v47; // x1
  __int64 v48; // x2
  _DWORD *v49; // x8

  v2 = *(_QWORD *)(a1 + 216);
  mutex_lock(a1 + 744);
  v3 = *(_QWORD *)(a1 + 120);
  v4 = *(void (__fastcall **)(__int64, __int64))(v3 + 296);
  if ( v4 )
  {
    v5 = v2;
    if ( *((_DWORD *)v4 - 1) != 1767426196 )
      __break(0x8228u);
LABEL_4:
    v4(v5, 0xFFFFFFFFLL);
    goto LABEL_11;
  }
  v4 = *(void (__fastcall **)(__int64, __int64))(v3 + 200);
  if ( v4 )
  {
    v5 = v2;
    if ( *((_DWORD *)v4 - 1) != 804672892 )
      __break(0x8228u);
    goto LABEL_4;
  }
  v6 = *(_QWORD *)(a1 + 856);
  v7 = *(unsigned int *)(v6 + 88);
  if ( (_DWORD)v7 )
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v7,
      *(unsigned __int8 *)(v6 + 92),
      (unsigned int)(3 << *(_BYTE *)(v6 + 93)));
LABEL_11:
  v9 = *(_QWORD *)(a1 + 112);
  v8 = *(_QWORD *)(a1 + 120);
  if ( *(_BYTE *)(v9 + 72) == 1
    && (v10 = *(void (__fastcall **)(_QWORD))(v8 + 264)) != nullptr
    && (*(_BYTE *)(v9 + 92) & 1) == 0 )
  {
    if ( *((_DWORD *)v10 - 1) != -144065355 )
      __break(0x822Au);
    v10(a1);
  }
  else
  {
    v11 = *(_DWORD **)(v8 + 320);
    if ( v11 )
    {
      if ( *(v11 - 1) != 496203713 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v11)(a1, 0);
    }
  }
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 112) + 88LL) )
  {
    v12 = *(_QWORD *)(a1 + 120);
    v13 = *(void (__fastcall **)(__int64, __int64))(v12 + 296);
    if ( v13 )
    {
      v14 = v2;
      v15 = 24;
      if ( *((_DWORD *)v13 - 1) != 1767426196 )
        __break(0x8228u);
LABEL_25:
      v13(v14, v15);
      goto LABEL_32;
    }
    v13 = *(void (__fastcall **)(__int64, __int64))(v12 + 200);
    if ( v13 )
    {
      v14 = v2;
      v15 = 0;
      if ( *((_DWORD *)v13 - 1) != 804672892 )
        __break(0x8228u);
      goto LABEL_25;
    }
    v16 = *(_QWORD *)(a1 + 856);
    v17 = *(unsigned int *)(v16 + 88);
    if ( (_DWORD)v17 )
      snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v17, *(unsigned __int8 *)(v16 + 92), 0);
  }
LABEL_32:
  v18 = *(_QWORD *)(a1 + 856);
  v19 = *(unsigned int *)(v18 + 120);
  if ( (_DWORD)v19 )
  {
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v19,
      *(unsigned __int8 *)(v18 + 124),
      *(unsigned __int8 *)(a1 + 163) << *(_BYTE *)(v18 + 125));
    v18 = *(_QWORD *)(a1 + 856);
  }
  v20 = *(unsigned int *)(v18 + 136);
  if ( (_DWORD)v20 )
  {
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v20,
      *(unsigned __int8 *)(v18 + 140),
      *(unsigned __int8 *)(a1 + 164) << *(_BYTE *)(v18 + 141));
    v18 = *(_QWORD *)(a1 + 856);
  }
  v21 = *(unsigned int *)(v18 + 152);
  if ( (_DWORD)v21 )
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v21,
      *(unsigned __int8 *)(v18 + 156),
      (unsigned int)(1 << *(_BYTE *)(v18 + 157)));
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 112) + 33LL) == 1 )
  {
    v22 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 120) + 248LL);
    if ( v22 )
    {
      if ( *((_DWORD *)v22 - 1) != -1918869124 )
        __break(0x8228u);
      v22(v2, 1);
    }
  }
  v23 = *(_QWORD *)(a1 + 856);
  v24 = *(unsigned int *)(v23 + 104);
  if ( (_DWORD)v24 )
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v24,
      *(unsigned __int8 *)(v23 + 108),
      (unsigned int)(1 << *(_BYTE *)(v23 + 109)));
  v25 = *(_QWORD *)(a1 + 856);
  v26 = *(unsigned int *)(v25 + 8);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 112) + 88LL) )
  {
    if ( !(_DWORD)v26 )
      goto LABEL_51;
    v27 = *(_QWORD *)(a1 + 216);
    v28 = *(unsigned __int8 *)(v25 + 12);
    v29 = 0;
  }
  else
  {
    if ( !(_DWORD)v26 )
      goto LABEL_51;
    v27 = *(_QWORD *)(a1 + 216);
    v28 = *(unsigned __int8 *)(v25 + 12);
    v29 = (unsigned int)(1 << *(_BYTE *)(v25 + 13));
  }
  snd_soc_component_update_bits(v27, v26, v28, v29);
LABEL_51:
  v30 = *(_QWORD *)(a1 + 856);
  v31 = *(unsigned int *)(v30 + 200);
  if ( (_DWORD)v31 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 112) + 88LL) )
      v32 = 4;
    else
      v32 = 6;
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v31,
      *(unsigned __int8 *)(v30 + 204),
      (unsigned int)(v32 << *(_BYTE *)(v30 + 205)));
  }
  v33 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 120) + 344LL);
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != 933030000 )
      __break(0x8228u);
    v33(v2);
  }
  else
  {
    v34 = *(_QWORD *)(a1 + 856);
    v35 = *(unsigned int *)(v34 + 216);
    if ( (_DWORD)v35 )
      snd_soc_component_update_bits(
        *(_QWORD *)(a1 + 216),
        v35,
        *(unsigned __int8 *)(v34 + 220),
        (unsigned int)(2 << *(_BYTE *)(v34 + 221)));
  }
  v36 = *(_QWORD *)(a1 + 856);
  v37 = *(unsigned int *)(v36 + 216);
  if ( (_DWORD)v37 )
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v37,
      *(unsigned __int8 *)(v36 + 220),
      (unsigned int)(2 << *(_BYTE *)(v36 + 221)));
  v38 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 120) + 160LL);
  if ( *((_DWORD *)v38 - 1) != -1918869124 )
    __break(0x8228u);
  v38(v2, 1);
  v39 = *(void (__fastcall **)(__int64, _BOOL8))(*(_QWORD *)(a1 + 120) + 128LL);
  if ( v39 )
  {
    v40 = *(_DWORD *)(*(_QWORD *)(a1 + 112) + 88LL) == 0;
    if ( *((_DWORD *)v39 - 1) != -1918869124 )
      __break(0x8228u);
    v39(v2, v40);
  }
  v41 = *(_QWORD *)(a1 + 856);
  v42 = *(unsigned int *)(v41 + 232);
  if ( (_DWORD)v42 )
  {
    v43 = 1374389535LL * (*(__int16 *)(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 8LL) + 48LL) - 1400);
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v42,
      *(unsigned __int8 *)(v41 + 236),
      ((unsigned int)(v43 >> 37) + ((unsigned __int64)v43 >> 63)) << *(_BYTE *)(v41 + 237));
  }
  v44 = *(_QWORD *)(a1 + 216);
  v45 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 8LL);
  if ( v45 )
  {
    v46 = *(unsigned __int8 *)(v45 + 65);
    v47 = v45 + 80;
    v48 = v45 + 80 + 2 * v46;
    v49 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 192LL);
    if ( *(v49 - 1) != -226424819 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))v49)(v44, v47, v48, v46, 0);
  }
  else
  {
    dev_err(*(_QWORD *)(*(_QWORD *)(v44 + 32) + 72LL), "%s: calibration data is NULL\n", "wcd_program_btn_threshold");
  }
  *(_DWORD *)(a1 + 864) = 0;
  return mutex_unlock(a1 + 744);
}
