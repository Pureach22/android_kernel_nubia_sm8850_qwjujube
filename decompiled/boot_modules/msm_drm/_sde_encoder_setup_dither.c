__int64 __fastcall sde_encoder_setup_dither(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x21
  __int64 *v8; // x22
  __int64 v9; // x8
  __int64 v10; // x23
  __int64 v11; // x1
  __int64 v12; // x20
  int v13; // w20
  __int64 v14; // x0
  _DWORD *v15; // x8
  __int64 v16; // x0
  _DWORD *v17; // x8
  __int64 v18; // x0
  _DWORD *v19; // x8
  __int64 v20; // x8
  __int64 v21; // x0
  _DWORD *v22; // x8
  void *v23; // x0
  void *v24; // x0
  __int64 v25; // x0
  _DWORD *v26; // x8
  __int64 v27; // x0
  _DWORD *v28; // x8
  __int64 v29; // x0
  _DWORD *v30; // x8

  _ReadStatusReg(SP_EL0);
  v2 = *(__int64 **)a1;
  if ( *(_QWORD *)a1 )
  {
    v3 = *v2;
    if ( !v3 )
    {
      v23 = &unk_26FCAB;
      goto LABEL_39;
    }
    v4 = *(_QWORD *)(v3 + 56);
    if ( !v4 || !*(_QWORD *)(v4 + 8) )
      goto LABEL_37;
    LODWORD(v2) = sde_kms_get_disp_op();
  }
  for ( result = *(_QWORD *)(a1 + 8); result; result = *(_QWORD *)(a1 + 8) )
  {
    v6 = *(_QWORD *)(a1 + 496);
    if ( !v6 )
      break;
    if ( (unsigned int)v2 < 3 )
    {
      v7 = (unsigned int)v2;
      if ( !*(_QWORD *)(v6 + 8LL * (unsigned int)v2 + 328) )
        break;
      v8 = *(__int64 **)a1;
      if ( !*(_QWORD *)a1 )
        break;
      if ( !*v8 )
      {
        v24 = &unk_26FCAB;
        goto LABEL_55;
      }
      v9 = *(_QWORD *)(*v8 + 56);
      if ( !v9 || (v10 = *(_QWORD *)(v9 + 8)) == 0 )
      {
        v24 = &unk_234896;
LABEL_55:
        result = printk(v24, "sde_encoder_get_kms");
        break;
      }
      v11 = *(_QWORD *)(result + 2512);
      if ( !v11 )
        break;
      v12 = *(_QWORD *)(v11 + 1376);
      if ( !(_DWORD)v12 || (_DWORD)v12 == 10 && *(_DWORD *)(a1 + 664) == 3 )
        break;
      if ( *((_WORD *)v8 + 2020) == 10 || *((_BYTE *)v8 + 4025) == 10 || *((_DWORD *)v8 + 1184) == 30 )
      {
        if ( (unsigned int)v12 >= 0x11 )
        {
          result = printk(&unk_22E16F, "sde_rm_topology_get_num_lm");
          break;
        }
        v13 = *(_DWORD *)(*(_QWORD *)(v10 + 2472) + 28 * (*(_QWORD *)(v11 + 1376) & 0x1FLL) + 4);
        if ( v13 < 1 )
          break;
        v14 = v8[42];
        v15 = *(_DWORD **)(*(_QWORD *)(a1 + 496) + 8 * v7 + 328);
        if ( *(v15 - 1) != 779437806 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v15)(v14, 0, 0);
        if ( v13 == 1 )
          break;
        v16 = v8[43];
        v17 = *(_DWORD **)(*(_QWORD *)(a1 + 496) + 8 * v7 + 328);
        if ( *(v17 - 1) != 779437806 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v17)(v16, 0, 0);
        if ( v13 == 2 )
          break;
        v18 = v8[44];
        v19 = *(_DWORD **)(*(_QWORD *)(a1 + 496) + 8 * v7 + 328);
        if ( *(v19 - 1) != 779437806 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v19)(v18, 0, 0);
        if ( v13 == 3 )
          break;
        v20 = *(_QWORD *)(a1 + 496);
        v21 = v8[45];
      }
      else
      {
        result = sde_connector_get_dither_cfg();
        if ( (_DWORD)result == -61 )
          break;
        result = sde_rm_topology_get_num_lm(v10 + 2144, (unsigned int)v12);
        if ( (int)result < 1 )
          break;
        v13 = result;
        v25 = v8[42];
        v26 = *(_DWORD **)(*(_QWORD *)(a1 + 496) + 8 * v7 + 328);
        if ( *(v26 - 1) != 779437806 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v26)(v25, 0, 0);
        if ( v13 == 1 )
          break;
        v27 = v8[43];
        v28 = *(_DWORD **)(*(_QWORD *)(a1 + 496) + 8 * v7 + 328);
        if ( *(v28 - 1) != 779437806 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v28)(v27, 0, 0);
        if ( v13 == 2 )
          break;
        v29 = v8[44];
        v30 = *(_DWORD **)(*(_QWORD *)(a1 + 496) + 8 * v7 + 328);
        if ( *(v30 - 1) != 779437806 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v30)(v29, 0, 0);
        if ( v13 == 3 )
          break;
        v20 = *(_QWORD *)(a1 + 496);
        v21 = v8[45];
      }
      v22 = *(_DWORD **)(v20 + 8 * v7 + 328);
      if ( *(v22 - 1) != 779437806 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v22)(v21, 0, 0);
      if ( v13 == 4 )
        break;
    }
    __break(0x5512u);
LABEL_37:
    v23 = &unk_234896;
LABEL_39:
    printk(v23, "sde_encoder_get_kms");
    LODWORD(v2) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
