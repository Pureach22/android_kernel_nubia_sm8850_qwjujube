__int64 __fastcall setup_gx_arc_votes_0(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x4
  __int64 v10; // x19
  int v11; // w8
  int v12; // w8
  unsigned int v13; // w25
  __int64 v14; // x27
  __int64 v15; // x26
  _WORD *v16; // x28
  unsigned int v17; // w24
  unsigned int v18; // kr00_4
  unsigned int v19; // w0
  __int64 result; // x0
  __int64 v21; // x9
  __int64 v22; // x9
  __int64 v23; // x8
  _DWORD *v24; // x10
  int v25; // w12
  unsigned int v26; // w19
  _QWORD v27[16]; // [xsp+10h] [xbp-D0h] BYREF
  _QWORD v28[10]; // [xsp+90h] [xbp-50h] BYREF

  v28[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = to_gen7_gmu((__int64)a1);
  v9 = (unsigned int)(*((_DWORD *)a1 + 2517) + 1);
  memset(v27, 0, sizeof(v27));
  if ( (unsigned int)v9 >= 0x21 )
  {
    dev_err(*a1, "Defined more GPU DCVS levels than RPMh can support\n");
    result = 4294967262LL;
  }
  else
  {
    *(_DWORD *)(v8 + 1352) = v9;
    v10 = v8;
    *(_QWORD *)(v8 + 1364) = 0;
    v11 = *((_DWORD *)a1 + 2291);
    memset(v28, 0, 48);
    if ( v11 == -1 )
      v12 = -1;
    else
      v12 = 0;
    v28[6] = 0;
    v28[7] = 0;
    *(_DWORD *)(v8 + 1364) = v12;
    v13 = *((_DWORD *)a1 + 2517) - 1;
    if ( (v13 & 0x80000000) != 0 )
    {
LABEL_12:
      result = adreno_rpmh_setup_volt_dependency_tbl(v27, a2, a3, v28, v9);
      if ( !(_DWORD)result )
      {
        v21 = *(unsigned int *)(v10 + 1352);
        if ( (_DWORD)v21 )
        {
          v22 = 4 * v21;
          v23 = 0;
          v24 = (_DWORD *)(v10 + 1360);
          while ( v23 != 128 )
          {
            v25 = *(_DWORD *)((char *)v27 + v23);
            v23 += 4;
            *v24 = v25;
            v24 += 3;
            if ( v22 == v23 )
              goto LABEL_17;
          }
LABEL_21:
          __break(0x5512u);
          __break(1u);
        }
LABEL_17:
        result = 0;
      }
    }
    else
    {
      v14 = 28LL * v13 + 9144;
      v15 = 0;
      v16 = (_WORD *)v28 + 1;
      while ( 1 )
      {
        if ( v13 > 0x1F || v15 == 372 )
          goto LABEL_21;
        v17 = *(_DWORD *)((char *)a1 + v14 + 20);
        v18 = *(_DWORD *)((char *)a1 + v14);
        *v16 = *(_DWORD *)((char *)a1 + v14 + 24);
        *(_DWORD *)(v10 + v15 + 1380) = v18 / 0x3E8;
        v19 = adreno_rpmh_to_cx_hlvl(a4, v17, v10 + v15 + 1376);
        if ( v19 )
          break;
        v15 += 12;
        ++v16;
        v14 -= 28;
        if ( 12LL * v13 + 12 == v15 )
        {
          v9 = *(unsigned int *)(v10 + 1352);
          goto LABEL_12;
        }
      }
      v26 = v19;
      dev_err(*a1, "Unsupported cx corner: %u\n", v17);
      result = v26;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
