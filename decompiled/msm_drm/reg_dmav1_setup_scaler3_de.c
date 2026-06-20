__int64 __fastcall reg_dmav1_setup_scaler3_de(__int64 a1, __int64 a2, int a3, char a4, unsigned int a5)
{
  unsigned __int64 ops; // x0
  unsigned int v10; // w23
  unsigned __int64 v11; // x24
  int v12; // w9
  int v13; // w11
  __int16 v14; // w13
  int v15; // w10
  __int16 v16; // w14
  int v17; // w12
  unsigned int v18; // w11
  int v19; // w13
  unsigned int v20; // w14
  __int16 v21; // w8
  unsigned int v22; // w12
  unsigned int v23; // w12
  __int64 (__fastcall *v24)(_QWORD); // x9
  unsigned int v25; // w0
  unsigned int v26; // w8
  __int64 (__fastcall *v27)(_QWORD); // x9
  unsigned int v29; // [xsp+8h] [xbp-28h] BYREF
  _DWORD v30[7]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ops = sde_reg_dma_get_ops(a5);
  v10 = -95;
  if ( ops && ops <= 0xFFFFFFFFFFFFF000LL )
  {
    v11 = ops;
    v12 = *(_WORD *)(a2 + 256) & 0x3FF | ((*(_WORD *)(a2 + 258) & 0x3FF) << 16);
    v13 = *(_WORD *)(a2 + 268) & 0x3FF;
    v14 = *(_WORD *)(a2 + 270);
    v15 = *(_WORD *)(a2 + 262) & 0x3FF | ((*(_WORD *)(a2 + 264) & 0x3FF) << 10);
    v16 = *(_WORD *)(a2 + 274);
    v17 = (*(_WORD *)(a2 + 260) & 7) << 13;
    v30[2] = *(unsigned __int8 *)(a2 + 252) | ((*(_WORD *)(a2 + 254) & 0x3FF) << 16);
    v30[3] = v12;
    v18 = v13 & 0xC00003FF | ((v14 & 0x3FF) << 10) & 0xC00FFFFF | ((*(_WORD *)(a2 + 272) & 0x3FF) << 20);
    LOBYTE(v12) = *(_WORD *)(a2 + 250);
    v19 = *(_DWORD *)(a2 + 280);
    v20 = v16 & 0x3FF | ((*(_WORD *)(a2 + 276) & 0x3FF) << 10) & 0xC00FFFFF | ((*(_WORD *)(a2 + 278) & 0x3FF) << 20);
    v21 = *(_WORD *)(a2 + 244);
    v30[4] = v15 & 0xC00FFFFF | ((*(_WORD *)(a2 + 266) & 0x3FF) << 20);
    v30[5] = v18;
    LOWORD(v15) = *(_WORD *)(a2 + 246);
    v22 = v17 & 0xFFFFE1FF | ((v12 & 0xF) << 9);
    LOBYTE(v12) = *(_WORD *)(a2 + 248);
    *(_DWORD *)a1 = 2;
    v23 = v22 & 0xFFF8FFFF | ((v12 & 7) << 16);
    v30[6] = v20;
    *(_DWORD *)(a1 + 20) = a3 + 36;
    *(_QWORD *)(a1 + 12) = 0;
    *(_QWORD *)(a1 + 32) = v30;
    *(_QWORD *)(a1 + 40) = 0x1C00000000LL;
    v24 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
    v30[0] = v21 & 0x1FF | ((v15 & 0x1FF) << 16);
    v30[1] = v23 & 0xFF0FFFFF | ((v19 & 0xF) << 20);
    if ( *((_DWORD *)v24 - 1) != -1839634494 )
      __break(0x8229u);
    v25 = v24(a1);
    if ( v25 )
    {
      v10 = v25;
      _drm_err("de write failed ret %d\n", v25);
    }
    else if ( (a4 & 1) != 0 )
    {
      if ( (*(_BYTE *)(a2 + 292) & 1) != 0 )
        v26 = *(_DWORD *)(a2 + 300) & 0x3FF
            | ((*(_DWORD *)(a2 + 304) & 0x3FF) << 10) & 0xC00FFFFF
            | ((*(_DWORD *)(a2 + 296) & 0x3FF) << 20);
      else
        v26 = 1072693248;
      *(_QWORD *)(a1 + 12) = 0;
      *(_DWORD *)a1 = 1;
      *(_DWORD *)(a1 + 20) = a3 + 100;
      *(_QWORD *)(a1 + 32) = &v29;
      *(_QWORD *)(a1 + 40) = 0x400000000LL;
      v27 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      v29 = v26;
      if ( *((_DWORD *)v27 - 1) != -1839634494 )
        __break(0x8229u);
      v10 = v27(a1);
      if ( v10 )
        _drm_err("de lpf write failed ret %d\n", v10);
    }
    else
    {
      v10 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v10;
}
