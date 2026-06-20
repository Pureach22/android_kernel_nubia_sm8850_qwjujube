__int64 __fastcall uetm_enable(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 result; // x0
  unsigned __int64 v7; // x8
  int v8; // w9
  _QWORD *v9; // x10
  _QWORD *v10; // x8
  _QWORD *v11; // x11
  char v12; // w9
  _QWORD *v13; // x11
  _QWORD *v14; // x10
  _QWORD *v15; // x11
  _QWORD *v16; // x10
  _QWORD *v17; // x11
  _QWORD *v18; // x10
  _QWORD *v19; // x11
  _QWORD *v20; // x10
  _QWORD *v21; // x11
  _QWORD *v22; // x10
  _QWORD *v23; // x11
  _QWORD *v24; // x10
  _QWORD *v25; // x11
  _QWORD *v26; // x12
  _QWORD *v27; // x10
  _QWORD *v28; // x11
  _QWORD *v29; // x13
  _QWORD *v30; // x11
  _QWORD *v31; // x10
  _QWORD *v32; // x11
  _QWORD *v33; // x10
  _QWORD *v34; // x13
  _QWORD *v35; // x11
  _QWORD *v36; // x12
  __int64 v37; // x0
  __int64 (__fastcall *v38)(__int64, int *, __int64, __int64, __int64); // x8
  __int64 v39; // x0
  __int64 (__fastcall *v40)(__int64, int *, __int64, __int64, __int64); // x8
  unsigned int v41; // w21
  unsigned __int64 v48; // x9
  int v49; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  v5 = *(_QWORD *)(v4 + 64);
  _X11 = (unsigned __int64 *)(a1 + 968);
  __asm { PRFM            #0x11, [X11] }
  while ( 1 )
  {
    v48 = __ldxr(_X11);
    if ( v48 )
      break;
    if ( !__stlxr(a3, _X11) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v48 )
  {
    dev_err(a1 + 56, "uetm %d already enabled,Skipping enable\n", *(_DWORD *)(v4 + 40));
    result = 4294967280LL;
    goto LABEL_62;
  }
  result = coresight_trace_id_get_system_id();
  if ( (result & 0x80000000) != 0 )
    goto LABEL_61;
  *(_BYTE *)(v4 + 44) = result;
  v7 = *(_QWORD *)(v5 + 8) & 0xFFFFFFFFFFFFFF80LL;
  *(_QWORD *)(v5 + 8) = v7;
  *(_QWORD *)(v5 + 8) = v7 | *(unsigned __int8 *)(v4 + 44);
  raw_spin_lock(v4 + 16);
  v8 = *(_DWORD *)(v4 + 20);
  v9 = *(_QWORD **)v4;
  v10 = *(_QWORD **)(v4 + 64);
  if ( v8 == 4 )
  {
    v12 = 0;
    v11 = *(_QWORD **)(v4 + 64);
  }
  else if ( v8 == 2 )
  {
    v11 = v10 + 48;
    v12 = 1;
  }
  else
  {
    v12 = 0;
    v11 = v10 + 48;
  }
  *v9 = *v11;
  v9[1] = v10[1];
  v9[2] = v10[2];
  v9[3] = v10[3];
  if ( (v12 & 1) != 0 )
  {
    v13 = v9 + 4;
  }
  else
  {
    v13 = v9 + 5;
    v9[4] = v10[4];
  }
  *v13 = v10[5];
  v14 = v13 + 1;
  if ( (v12 & 1) == 0 )
  {
    v14 = v13 + 2;
    v13[1] = v10[6];
  }
  *v14 = v10[7];
  v15 = v14 + 1;
  if ( (v12 & 1) == 0 )
  {
    v15 = v14 + 2;
    v14[1] = v10[8];
  }
  *v15 = v10[9];
  v16 = v15 + 1;
  if ( (v12 & 1) == 0 )
  {
    v16 = v15 + 2;
    v15[1] = v10[10];
  }
  *v16 = v10[11];
  v17 = v16 + 1;
  if ( (v12 & 1) == 0 )
  {
    v17 = v16 + 2;
    v16[1] = v10[12];
  }
  *v17 = v10[13];
  v18 = v17 + 1;
  if ( (v12 & 1) == 0 )
  {
    v18 = v17 + 2;
    v17[1] = v10[14];
  }
  *v18 = v10[15];
  v19 = v18 + 1;
  if ( (v12 & 1) == 0 )
  {
    v19 = v18 + 2;
    v18[1] = v10[16];
  }
  *v19 = v10[17];
  v20 = v19 + 1;
  if ( (v12 & 1) == 0 )
  {
    v20 = v19 + 2;
    v19[1] = v10[18];
  }
  *v20 = v10[19];
  v21 = v20 + 1;
  if ( (v12 & 1) == 0 )
  {
    v21 = v20 + 2;
    v20[1] = v10[20];
  }
  *v21 = v10[21];
  v22 = v21 + 1;
  if ( (v12 & 1) == 0 )
  {
    v22 = v21 + 2;
    v21[1] = v10[22];
  }
  *v22 = v10[23];
  v23 = v22 + 1;
  if ( (v12 & 1) == 0 )
  {
    v23 = v22 + 2;
    v22[1] = v10[24];
  }
  *v23 = v10[25];
  v24 = v23 + 1;
  if ( (v12 & 1) == 0 )
  {
    v24 = v23 + 2;
    v23[1] = v10[26];
  }
  *v24 = v10[27];
  v25 = v24 + 1;
  if ( (v12 & 1) == 0 )
  {
    v25 = v24 + 2;
    v24[1] = v10[28];
  }
  *v25 = v10[29];
  v26 = v25 + 1;
  if ( (v12 & 1) == 0 )
  {
    v26 = v25 + 2;
    v25[1] = v10[30];
  }
  *v26 = v10[31];
  v27 = v26 + 1;
  if ( (v12 & 1) == 0 )
  {
    v27 = v26 + 2;
    v26[1] = v10[32];
  }
  *v27 = v10[33];
  v28 = v27 + 1;
  if ( (v12 & 1) == 0 )
  {
    v29 = v27 + 2;
    v27[1] = v10[34];
    ++v27;
    v28 = v29;
  }
  *v28 = v10[35];
  v27[2] = v10[36];
  v27[3] = v10[37];
  v27[4] = v10[38];
  v27[5] = v10[39];
  if ( (v12 & 1) != 0 )
  {
    v30 = v27 + 6;
  }
  else
  {
    v30 = v27 + 7;
    v27[6] = v10[40];
  }
  *v30 = v10[41];
  v31 = v30 + 1;
  if ( (v12 & 1) == 0 )
  {
    v31 = v30 + 2;
    v30[1] = v10[42];
  }
  *v31 = v10[43];
  v32 = v31 + 1;
  if ( (v12 & 1) == 0 )
  {
    v32 = v31 + 2;
    v31[1] = v10[44];
  }
  *v32 = v10[45];
  v33 = v32 + 1;
  if ( (v12 & 1) == 0 )
  {
    v34 = v32 + 2;
    v32[1] = v10[46];
    ++v32;
    v33 = v34;
  }
  if ( *(_DWORD *)(v4 + 20) == 4 )
  {
    *v33 = v10[47];
    v33 = v32 + 3;
    v32[2] = v10[48];
  }
  *v33 = v10[49];
  v35 = v33 + 1;
  if ( (v12 & 1) == 0 )
  {
    v36 = v33 + 2;
    v33[1] = v10[50];
    ++v33;
    v35 = v36;
  }
  *v35 = v10[51];
  v33[2] = v10[52];
  v33[3] = v10[53];
  __dsb(0xFu);
  raw_spin_unlock(v4 + 16);
  coresight_csr_set_etr_atid(a1, *(unsigned __int8 *)(v4 + 44), 1, 0);
  v37 = ph;
  v38 = *(__int64 (__fastcall **)(__int64, int *, __int64, __int64, __int64))ops;
  v49 = *(_DWORD *)(v4 + 40);
  if ( *((_DWORD *)v38 - 1) != 1737159351 )
    __break(0x8228u);
  LODWORD(result) = v38(v37, &v49, 1430606925, 1, 4);
  if ( (_DWORD)result )
    goto LABEL_60;
  v39 = ph;
  v40 = *(__int64 (__fastcall **)(__int64, int *, __int64, __int64, __int64))(ops + 16);
  v49 = *(_DWORD *)(v4 + 40);
  if ( *((_DWORD *)v40 - 1) != 1737159351 )
    __break(0x8228u);
  result = v40(v39, &v49, 1430606925, 1, 4);
  if ( (_DWORD)result )
  {
LABEL_60:
    v41 = result;
    coresight_trace_id_put_system_id(*(unsigned __int8 *)(v4 + 44));
    coresight_csr_set_etr_atid(a1, *(unsigned __int8 *)(v4 + 44), 0, 0);
    result = v41;
LABEL_61:
    *(_QWORD *)(a1 + 968) = 0;
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
