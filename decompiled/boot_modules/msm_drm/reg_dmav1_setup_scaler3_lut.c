unsigned __int64 __fastcall reg_dmav1_setup_scaler3_lut(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  unsigned __int64 result; // x0
  unsigned __int64 v8; // x21
  int v9; // w8
  unsigned int v10; // w9
  unsigned int v11; // w9
  unsigned int v12; // w9
  unsigned int v13; // w9
  unsigned __int64 v14; // x22
  int *v15; // x23
  int v16; // w24
  bool v17; // cf
  __int64 v18; // x20
  int v19; // w8
  int v20; // w28
  __int64 (__fastcall *v21)(_QWORD); // x8
  int v22; // w9
  int v23; // w27
  __int64 (__fastcall *v24)(_QWORD); // x8
  int v25; // w28
  int v26; // w9
  int v27; // w27
  __int64 (__fastcall *v28)(_QWORD); // x8
  int v29; // w9
  int v30; // w10
  __int64 (__fastcall *v31)(_QWORD); // x8
  __int64 (__fastcall *v32)(_QWORD); // x9
  int v33; // w1
  int v34; // [xsp+Ch] [xbp-44h]
  int v35; // [xsp+10h] [xbp-40h]
  int v36; // [xsp+1Ch] [xbp-34h] BYREF
  __int64 v37; // [xsp+20h] [xbp-30h]
  __int64 v38; // [xsp+28h] [xbp-28h]
  __int64 v39; // [xsp+30h] [xbp-20h]
  __int64 v40; // [xsp+38h] [xbp-18h]
  __int64 v41; // [xsp+40h] [xbp-10h]
  __int64 v42; // [xsp+48h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v37 = 0;
  result = sde_reg_dma_get_ops(a4);
  if ( !result )
    goto LABEL_47;
  v8 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_47;
  v35 = *(_DWORD *)(a2 + 168);
  if ( (v35 & 2) == 0 || *(_QWORD *)(a2 + 200) != 800 )
  {
    v9 = 0;
    if ( (v35 & 4) == 0 )
      goto LABEL_11;
LABEL_8:
    v10 = *(_DWORD *)(a2 + 176);
    if ( v10 <= 8 && *(_QWORD *)(a2 + 216) == 2160 )
    {
      v38 = *(_QWORD *)(a2 + 208) + 240LL * v10;
      v9 = 1;
    }
    goto LABEL_11;
  }
  v37 = *(_QWORD *)(a2 + 192);
  v9 = 1;
  if ( (v35 & 4) != 0 )
    goto LABEL_8;
LABEL_11:
  if ( (v35 & 8) != 0 )
  {
    v11 = *(_DWORD *)(a2 + 180);
    if ( v11 <= 8 && *(_QWORD *)(a2 + 216) == 2160 )
    {
      v39 = *(_QWORD *)(a2 + 208) + 240LL * v11;
      v9 = 1;
    }
  }
  v34 = a3;
  if ( (v35 & 0x10) != 0 )
  {
    v12 = *(_DWORD *)(a2 + 184);
    if ( v12 <= 9 && *(_QWORD *)(a2 + 232) == 2400 )
    {
      v40 = *(_QWORD *)(a2 + 224) + 240LL * v12;
      v9 = 1;
    }
  }
  if ( (v35 & 0x20) != 0 )
  {
    v13 = *(_DWORD *)(a2 + 188);
    if ( v13 <= 9 && *(_QWORD *)(a2 + 232) == 2400 )
    {
      v41 = *(_QWORD *)(a2 + 224) + 240LL * v13;
LABEL_24:
      v14 = 0;
      v15 = (int *)&unk_28A334;
      v16 = a3 + 256;
      while ( 1 )
      {
        v18 = *(&v37 + v14);
        if ( v18 )
        {
          v20 = *(v15 - 4);
          v19 = *(v15 - 3);
          *(_DWORD *)a1 = 2;
          *(_QWORD *)(a1 + 32) = v18;
          *(_QWORD *)(a1 + 12) = 0;
          *(_DWORD *)(a1 + 20) = v16 + v19;
          *(_DWORD *)(a1 + 40) = 0;
          *(_DWORD *)(a1 + 44) = 16 * v20;
          v21 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
          if ( *((_DWORD *)v21 - 1) != -1839634494 )
            __break(0x8228u);
          LODWORD(result) = v21(a1);
          if ( (_DWORD)result )
            goto LABEL_45;
          v23 = *(v15 - 2);
          v22 = *(v15 - 1);
          *(_DWORD *)a1 = 2;
          *(_QWORD *)(a1 + 12) = 0;
          *(_DWORD *)(a1 + 20) = v16 + v22;
          *(_QWORD *)(a1 + 32) = v18 + 4LL * (unsigned int)(4 * v20);
          *(_DWORD *)(a1 + 40) = 0;
          *(_DWORD *)(a1 + 44) = 16 * v23;
          v24 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
          v36 = 1;
          if ( *((_DWORD *)v24 - 1) != -1839634494 )
            __break(0x8228u);
          LODWORD(result) = v24(a1);
          if ( (_DWORD)result )
            goto LABEL_45;
          v25 = v23 + v20;
          v36 = 2;
          v27 = *v15;
          v26 = v15[1];
          *(_DWORD *)a1 = 2;
          *(_QWORD *)(a1 + 12) = 0;
          *(_DWORD *)(a1 + 20) = v16 + v26;
          *(_QWORD *)(a1 + 32) = v18 + 4LL * (unsigned int)(4 * v25);
          *(_DWORD *)(a1 + 40) = 0;
          *(_DWORD *)(a1 + 44) = 16 * v27;
          v28 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
          if ( *((_DWORD *)v28 - 1) != -1839634494 )
            __break(0x8228u);
          LODWORD(result) = v28(a1);
          if ( (_DWORD)result )
            goto LABEL_45;
          v30 = v15[2];
          v29 = v15[3];
          *(_DWORD *)a1 = 2;
          *(_QWORD *)(a1 + 12) = 0;
          *(_DWORD *)(a1 + 20) = v16 + v29;
          *(_QWORD *)(a1 + 32) = v18 + 4LL * (unsigned int)(4 * (v27 + v25));
          *(_DWORD *)(a1 + 40) = 0;
          *(_DWORD *)(a1 + 44) = 16 * v30;
          v31 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
          v36 = 3;
          if ( *((_DWORD *)v31 - 1) != -1839634494 )
            __break(0x8228u);
          result = v31(a1);
          if ( (_DWORD)result )
          {
LABEL_45:
            v33 = result;
            goto LABEL_46;
          }
          v36 = 4;
        }
        v17 = v14++ >= 4;
        v15 += 8;
        if ( v17 )
          goto LABEL_40;
      }
    }
  }
  if ( v9 )
    goto LABEL_24;
LABEL_40:
  if ( (v35 & 1) != 0 )
  {
    *(_DWORD *)(a1 + 20) = v34 + 76;
    *(_DWORD *)a1 = 1;
    *(_QWORD *)(a1 + 12) = 0;
    *(_QWORD *)(a1 + 32) = &v36;
    *(_QWORD *)(a1 + 40) = 0x400000000LL;
    v32 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
    v36 = 1;
    if ( *((_DWORD *)v32 - 1) != -1839634494 )
      __break(0x8229u);
    result = v32(a1);
    v33 = result;
    if ( (_DWORD)result )
LABEL_46:
      result = _drm_err("lut write failed ret %d\n", v33);
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
