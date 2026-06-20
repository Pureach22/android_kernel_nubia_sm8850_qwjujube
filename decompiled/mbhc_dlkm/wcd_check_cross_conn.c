__int64 __fastcall wcd_check_cross_conn(__int64 a1)
{
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0
  char v5; // w0
  __int64 v6; // x8
  __int64 v7; // x1
  int v8; // w22
  _DWORD *v9; // x8
  __int64 v10; // x8
  char v11; // w0
  int v12; // w23
  char v13; // w0
  __int64 v14; // x8
  int v15; // w25
  int v16; // w24
  unsigned int v17; // w0
  unsigned int v18; // w20
  unsigned int v19; // w0
  unsigned int v20; // w21
  void (__fastcall *v21)(_QWORD); // x8
  unsigned int v22; // w20
  void *v23; // x0
  __int64 v24; // x8
  __int64 v25; // x1
  __int64 v26; // x1
  __int64 v27; // x1
  __int64 v28; // x1
  __int64 v29; // x1
  __int64 v30; // x1
  void (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x8
  __int64 v33; // x1

  if ( wcd_swch_level_remove(a1) )
    return 4294967274LL;
  v2 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 120) + 184LL);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a1 + 216);
    if ( *((_DWORD *)v2 - 1) != -67188162 )
      __break(0x8228u);
    if ( (v2(v3) & 1) != 0 )
      return 4294967274LL;
  }
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 856) + 168LL) )
  {
    v5 = snd_soc_component_read(*(_QWORD *)(a1 + 216));
    v6 = *(_QWORD *)(a1 + 856);
    v7 = *(unsigned int *)(v6 + 168);
    v8 = (unsigned __int8)(v5 & *(_BYTE *)(v6 + 172)) >> *(_BYTE *)(v6 + 173);
    if ( (_DWORD)v7 )
      snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v7, *(unsigned __int8 *)(v6 + 172), 0);
  }
  else
  {
    v8 = 234;
  }
  v9 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 8LL);
  if ( v9 )
  {
    if ( *(v9 - 1) != 496203713 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v9)(a1, 0);
  }
  v10 = *(_QWORD *)(a1 + 856);
  if ( *(_DWORD *)(v10 + 744) )
  {
    v11 = snd_soc_component_read(*(_QWORD *)(a1 + 216));
    v10 = *(_QWORD *)(a1 + 856);
    v12 = (unsigned __int8)(v11 & *(_BYTE *)(v10 + 748)) >> *(_BYTE *)(v10 + 749);
    if ( *(_DWORD *)(v10 + 664) )
      goto LABEL_17;
LABEL_20:
    v15 = 234;
    if ( *(_DWORD *)(v10 + 184) )
      goto LABEL_18;
    goto LABEL_21;
  }
  v12 = 234;
  if ( !*(_DWORD *)(v10 + 664) )
    goto LABEL_20;
LABEL_17:
  v13 = snd_soc_component_read(*(_QWORD *)(a1 + 216));
  v14 = *(_QWORD *)(a1 + 856);
  v15 = (unsigned __int8)(v13 & *(_BYTE *)(v14 + 668)) >> *(_BYTE *)(v14 + 669);
  if ( *(_DWORD *)(v14 + 184) )
  {
LABEL_18:
    v16 = (unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a1 + 216)) & *(_BYTE *)(*(_QWORD *)(a1 + 856) + 188LL)) >> *(_BYTE *)(*(_QWORD *)(a1 + 856) + 189LL);
    goto LABEL_22;
  }
LABEL_21:
  v16 = 234;
LABEL_22:
  v17 = wcd_measure_adc_once((_QWORD *)a1, 4);
  if ( (v17 & 0x80000000) != 0 )
  {
    v23 = &unk_E4B4;
LABEL_33:
    printk(v23, "wcd_check_cross_conn");
LABEL_34:
    v22 = 0;
    goto LABEL_35;
  }
  v18 = v17;
  v19 = wcd_measure_adc_once((_QWORD *)a1, 5);
  if ( (v19 & 0x80000000) != 0 )
  {
    v23 = &unk_E13D;
    goto LABEL_33;
  }
  v20 = v19;
  v21 = **(void (__fastcall ***)(_QWORD))(a1 + 120);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != -144065355 )
      __break(0x8228u);
    v21(a1);
  }
  if ( v18 <= *(_DWORD *)(a1 + 196) || v20 <= *(_DWORD *)(a1 + 200) )
    goto LABEL_34;
  v22 = 1;
LABEL_35:
  v24 = *(_QWORD *)(a1 + 856);
  v25 = *(unsigned int *)(v24 + 184);
  if ( (_DWORD)v25 )
  {
    snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v25, *(unsigned __int8 *)(v24 + 188), 0);
    v24 = *(_QWORD *)(a1 + 856);
  }
  v26 = *(unsigned int *)(v24 + 536);
  if ( (_DWORD)v26 )
  {
    snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v26, *(unsigned __int8 *)(v24 + 540), 0);
    v24 = *(_QWORD *)(a1 + 856);
  }
  v27 = *(unsigned int *)(v24 + 184);
  if ( (_DWORD)v27 )
  {
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v27,
      *(unsigned __int8 *)(v24 + 188),
      (unsigned int)(1 << *(_BYTE *)(v24 + 189)));
    v24 = *(_QWORD *)(a1 + 856);
  }
  v28 = *(unsigned int *)(v24 + 664);
  if ( (_DWORD)v28 )
  {
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v28,
      *(unsigned __int8 *)(v24 + 668),
      (unsigned int)(v15 << *(_BYTE *)(v24 + 669)));
    v24 = *(_QWORD *)(a1 + 856);
  }
  v29 = *(unsigned int *)(v24 + 744);
  if ( (_DWORD)v29 )
  {
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v29,
      *(unsigned __int8 *)(v24 + 748),
      (unsigned int)(v12 << *(_BYTE *)(v24 + 749)));
    v24 = *(_QWORD *)(a1 + 856);
  }
  v30 = *(unsigned int *)(v24 + 184);
  if ( (_DWORD)v30 )
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v30,
      *(unsigned __int8 *)(v24 + 188),
      (unsigned int)(v16 << *(_BYTE *)(v24 + 189)));
  v31 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 120) + 8LL);
  if ( v31 )
  {
    if ( *((_DWORD *)v31 - 1) != 496203713 )
      __break(0x8228u);
    v31(a1, 1);
  }
  v32 = *(_QWORD *)(a1 + 856);
  v33 = *(unsigned int *)(v32 + 168);
  if ( (_DWORD)v33 )
    snd_soc_component_update_bits(
      *(_QWORD *)(a1 + 216),
      v33,
      *(unsigned __int8 *)(v32 + 172),
      (unsigned int)(v8 << *(_BYTE *)(v32 + 173)));
  return v22;
}
