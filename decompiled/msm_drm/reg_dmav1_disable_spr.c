unsigned __int64 __fastcall reg_dmav1_disable_spr(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  int v5; // w23
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w24
  unsigned __int64 result; // x0
  unsigned __int64 v10; // x21
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 *v13; // x8
  void (__fastcall *v14)(_QWORD); // x9
  unsigned __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 (__fastcall *v18)(_QWORD); // x8
  int v19; // w0
  __int64 (__fastcall *v20)(_QWORD); // x9
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x1
  __int64 v24; // x10
  int v25; // w9
  __int64 v26; // x10
  unsigned __int64 v27; // x8
  int v28; // w9
  __int64 v29; // x8
  __int64 (__fastcall *v30)(_QWORD); // x8
  int v31; // [xsp+4h] [xbp-9Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-98h] BYREF
  __int64 v33; // [xsp+10h] [xbp-90h]
  unsigned __int64 v34; // [xsp+18h] [xbp-88h]
  __int64 v35; // [xsp+20h] [xbp-80h]
  __int64 v36; // [xsp+28h] [xbp-78h]
  __int64 v37; // [xsp+30h] [xbp-70h]
  __int64 v38; // [xsp+38h] [xbp-68h]
  int v39; // [xsp+40h] [xbp-60h]
  __int64 v40; // [xsp+44h] [xbp-5Ch]
  int v41; // [xsp+4Ch] [xbp-54h]
  int v42; // [xsp+50h] [xbp-50h]
  int v43; // [xsp+54h] [xbp-4Ch]
  unsigned __int64 v44; // [xsp+58h] [xbp-48h] BYREF
  __int128 v45; // [xsp+60h] [xbp-40h]
  unsigned __int64 v46; // [xsp+70h] [xbp-30h]
  int *v47; // [xsp+78h] [xbp-28h]
  __int64 v48; // [xsp+80h] [xbp-20h]
  __int64 v49; // [xsp+88h] [xbp-18h]
  __int64 v50; // [xsp+90h] [xbp-10h]
  __int64 v51; // [xsp+98h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  v49 = 0;
  v50 = 0;
  v5 = *(_DWORD *)(a1 + 8);
  v6 = *(unsigned int *)(a1 + 1496);
  v47 = nullptr;
  v48 = 0;
  v7 = *(_QWORD *)(v4 + 48);
  v46 = 0;
  v44 = 0;
  v45 = 0u;
  v8 = *(_DWORD *)(v7 + 416);
  v31 = 0;
  result = sde_reg_dma_get_ops(v6);
  if ( !result )
    goto LABEL_29;
  v10 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_29;
  v11 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v11 >= 5 )
    goto LABEL_30;
  v12 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v12 > 1 )
    goto LABEL_30;
  if ( (unsigned __int64)(16 * v11 + 8 * v12 + 960) > 0x7CF )
    goto LABEL_31;
  v13 = &dspp_buf[2 * v11 + v12];
  v14 = *(void (__fastcall **)(_QWORD))(result + 64);
  v15 = v13[120];
  if ( *((_DWORD *)v14 - 1) != -870478129 )
    __break(0x8229u);
  v14(v15);
  v16 = *(unsigned int *)(a1 + 64);
  v44 = 0x8000000000000000LL;
  v45 = 0xCu;
  v46 = 0;
  v47 = nullptr;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  if ( (unsigned int)v16 > 4 )
    goto LABEL_30;
  v17 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v17 > 1 )
    goto LABEL_30;
  if ( (unsigned __int64)(16 * v16 + 8 * v17 + 960) > 0x7CF )
    goto LABEL_31;
  HIDWORD(v45) = 0;
  DWORD1(v45) = 0;
  v48 = 0;
  v46 = dspp_buf[2 * v16 + 120 + v17];
  v47 = nullptr;
  v18 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
  if ( *((_DWORD *)v18 - 1) != -1839634494 )
    __break(0x8228u);
  v19 = v18(&v44);
  if ( v19 )
  {
    result = _drm_err("spr write decode select failed ret %d\n", v19);
    goto LABEL_29;
  }
  *(_QWORD *)((char *)&v45 + 4) = 0;
  HIDWORD(v45) = v5 + v8 + 4;
  v47 = &v31;
  v48 = 0x402000000LL;
  v20 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
  LODWORD(v44) = 5;
  if ( *((_DWORD *)v20 - 1) != -1839634494 )
    __break(0x8229u);
  result = v20(&v44);
  if ( (_DWORD)result )
  {
    result = _drm_err("write spr disable failed ret %d\n", result);
    goto LABEL_29;
  }
  v21 = *(unsigned int *)(a1 + 64);
  v22 = *(_QWORD *)(a2 + 16);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = v22;
  v33 = 0;
  if ( (unsigned int)v21 > 4 )
    goto LABEL_30;
  v23 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v23 > 1 )
    goto LABEL_30;
  if ( (unsigned __int64)(16 * v21 + 8 * v23 + 960) > 0x7CF )
    goto LABEL_31;
  v24 = *(_QWORD *)(a2 + 152);
  LODWORD(v33) = 1;
  LODWORD(v37) = 12;
  v25 = *(_DWORD *)(a2 + 160);
  v38 = v24;
  v26 = *(_QWORD *)(a2 + 164);
  v39 = v25;
  v27 = dspp_buf[2 * v21 + 120 + v23];
  v40 = v26;
  LODWORD(v26) = *(_DWORD *)(a2 + 172);
  v28 = *(_DWORD *)(a2 + 176);
  v34 = v27;
  v29 = *(unsigned int *)(a1 + 28);
  LODWORD(v36) = 0;
  v42 = v26;
  v43 = v28;
  v41 = *(_DWORD *)(a2 + 28);
  if ( (unsigned int)v29 > 2 )
  {
LABEL_30:
    __break(0x5512u);
LABEL_31:
    __break(1u);
  }
  v30 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8 * v29 + 16);
  if ( !v30 )
    goto LABEL_28;
  if ( *((_DWORD *)v30 - 1) != 1772228465 )
    __break(0x8228u);
  result = v30(&v32);
  if ( (_DWORD)result )
    result = _drm_err("failed to kick off ret %d\n", result);
  else
LABEL_28:
    *(_DWORD *)(a1 + 84) = 0;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
