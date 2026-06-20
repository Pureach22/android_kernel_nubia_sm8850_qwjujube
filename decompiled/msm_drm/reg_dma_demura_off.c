size_t __fastcall reg_dma_demura_off(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  int v7; // w23
  size_t result; // x0
  size_t v9; // x21
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned __int64 *v12; // x8
  void (__fastcall *v13)(_QWORD); // x9
  unsigned __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w0
  int v19; // w8
  __int64 (__fastcall *v20)(_QWORD); // x9
  unsigned int v21; // w0
  int v22; // w6
  int v23; // w7
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x1
  __int64 v27; // x10
  int v28; // w9
  __int64 v29; // x10
  unsigned __int64 v30; // x8
  int v31; // w9
  __int64 v32; // x8
  __int64 (__fastcall *v33)(_QWORD); // x8
  char v34; // [xsp+0h] [xbp-A0h]
  int v35; // [xsp+4h] [xbp-9Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-98h] BYREF
  __int64 v37; // [xsp+10h] [xbp-90h]
  unsigned __int64 v38; // [xsp+18h] [xbp-88h]
  __int64 v39; // [xsp+20h] [xbp-80h]
  __int64 v40; // [xsp+28h] [xbp-78h]
  __int64 v41; // [xsp+30h] [xbp-70h]
  __int64 v42; // [xsp+38h] [xbp-68h]
  int v43; // [xsp+40h] [xbp-60h]
  __int64 v44; // [xsp+44h] [xbp-5Ch]
  int v45; // [xsp+4Ch] [xbp-54h]
  int v46; // [xsp+50h] [xbp-50h]
  int v47; // [xsp+54h] [xbp-4Ch]
  unsigned __int64 v48; // [xsp+58h] [xbp-48h] BYREF
  __int128 v49; // [xsp+60h] [xbp-40h]
  unsigned __int64 v50; // [xsp+70h] [xbp-30h]
  int *v51; // [xsp+78h] [xbp-28h]
  __int64 v52; // [xsp+80h] [xbp-20h]
  __int64 v53; // [xsp+88h] [xbp-18h]
  __int64 v54; // [xsp+90h] [xbp-10h]
  __int64 v55; // [xsp+98h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  v53 = 0;
  v54 = 0;
  v5 = *(unsigned int *)(a1 + 1496);
  v51 = nullptr;
  v52 = 0;
  v6 = *(_QWORD *)(v4 + 48);
  v50 = 0;
  v48 = 0;
  v49 = 0u;
  v7 = *(_DWORD *)(v6 + 568);
  v35 = 0;
  result = sde_reg_dma_get_ops(v5);
  if ( !result )
    goto LABEL_19;
  v9 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_19;
  v10 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v10 >= 5 )
    goto LABEL_29;
  v11 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v11 > 1 )
    goto LABEL_29;
  if ( (unsigned __int64)(16 * v10 + 8 * v11 + 1600) > 0x7D0 )
    goto LABEL_30;
  v12 = &dspp_buf[2 * v10 + v11];
  v13 = *(void (__fastcall **)(_QWORD))(result + 64);
  v14 = v12[200];
  if ( *((_DWORD *)v13 - 1) != -870478129 )
    __break(0x8229u);
  v13(v14);
  v15 = *(unsigned int *)(a1 + 64);
  v48 = 0x8000000000000000LL;
  v49 = 0x14u;
  v50 = 0;
  v51 = nullptr;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  if ( (unsigned int)v15 > 4 )
    goto LABEL_29;
  v16 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v16 > 1 )
    goto LABEL_29;
  if ( (unsigned __int64)(16 * v15 + 8 * v16 + 1600) > 0x7D0 )
    goto LABEL_30;
  HIDWORD(v49) = 0;
  DWORD1(v49) = 0;
  v52 = 0;
  v50 = dspp_buf[2 * v15 + 200 + v16];
  v51 = nullptr;
  v17 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8);
  if ( *((_DWORD *)v17 - 1) != -1839634494 )
    __break(0x8228u);
  v18 = v17(&v48);
  if ( v18 )
  {
    result = _drm_err("write decode select failed ret %d\n", v18);
    goto LABEL_19;
  }
  v19 = *(_DWORD *)(a1 + 8);
  *(_QWORD *)((char *)&v49 + 4) = 0;
  HIDWORD(v49) = v7 + v19 + 4;
  v51 = &v35;
  v52 = 0x400000000LL;
  v20 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8);
  LODWORD(v48) = 1;
  if ( *((_DWORD *)v20 - 1) != -1839634494 )
    __break(0x8229u);
  v21 = v20(&v48);
  if ( v21 )
  {
    result = _drm_err("off(0x4): REG_SINGLE_WRITE failed ret %d\n", v21);
    goto LABEL_19;
  }
  result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dma_demura_off", 7455, -1, 4369, -1059143953, v22, v23, v34);
  v24 = *(unsigned int *)(a1 + 64);
  v25 = *(_QWORD *)(a2 + 16);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = v25;
  v37 = 0;
  if ( (unsigned int)v24 > 4 )
    goto LABEL_29;
  v26 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v26 > 1 )
    goto LABEL_29;
  if ( (unsigned __int64)(16 * v24 + 8 * v26 + 1600) > 0x7D0 )
    goto LABEL_30;
  v27 = *(_QWORD *)(a2 + 152);
  LODWORD(v37) = 1;
  LODWORD(v41) = 20;
  v28 = *(_DWORD *)(a2 + 160);
  v42 = v27;
  v29 = *(_QWORD *)(a2 + 164);
  v43 = v28;
  v30 = dspp_buf[2 * v24 + 200 + v26];
  v44 = v29;
  LODWORD(v29) = *(_DWORD *)(a2 + 172);
  v31 = *(_DWORD *)(a2 + 176);
  v38 = v30;
  v32 = *(unsigned int *)(a1 + 28);
  LODWORD(v40) = 0;
  v46 = v29;
  v47 = v31;
  v45 = *(_DWORD *)(a2 + 28);
  if ( (unsigned int)v32 > 2 )
  {
LABEL_29:
    __break(0x5512u);
LABEL_30:
    __break(1u);
  }
  v33 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8 * v32 + 16);
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != 1772228465 )
      __break(0x8228u);
    result = v33(&v36);
    if ( (_DWORD)result )
      result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
