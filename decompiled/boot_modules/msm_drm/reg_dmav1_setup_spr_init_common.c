__int64 __fastcall reg_dmav1_setup_spr_init_common(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v8; // w9
  int v9; // w13
  int v10; // w14
  int v11; // w10
  int v12; // w11
  int v13; // w8
  unsigned int v14; // w13
  int v15; // w12
  unsigned int v16; // w10
  __int64 v17; // x11
  int v18; // w14
  int v19; // w8
  int v20; // w9
  int v21; // w25
  __int64 (__fastcall *v22)(_QWORD); // x8
  unsigned int v23; // w0
  unsigned int v24; // w23
  int v25; // w10
  int v26; // w8
  int v27; // w12
  int v28; // w10
  int v29; // w11
  int v30; // w8
  int v31; // w8
  int v32; // w9
  int v33; // w10
  int v34; // w11
  int v35; // w8
  int v36; // w9
  __int64 (__fastcall *v37)(_QWORD); // x10
  unsigned int v38; // w0
  __int64 v40; // x8
  int v41; // w9
  __int16 v42; // w11
  __int16 v43; // w12
  __int64 v44; // x8
  char v45; // w10
  __int16 v46; // w14
  __int16 v47; // w15
  __int64 (__fastcall *v48)(_QWORD); // x8
  unsigned int v49; // [xsp+8h] [xbp-88h] BYREF
  unsigned int v50; // [xsp+Ch] [xbp-84h]
  unsigned int v51; // [xsp+10h] [xbp-80h]
  unsigned int v52; // [xsp+14h] [xbp-7Ch]
  unsigned __int64 v53; // [xsp+18h] [xbp-78h]
  unsigned __int64 v54; // [xsp+20h] [xbp-70h]
  __int64 v55; // [xsp+28h] [xbp-68h]
  __int64 v56; // [xsp+30h] [xbp-60h]
  __int64 v57; // [xsp+38h] [xbp-58h]
  __int64 v58; // [xsp+40h] [xbp-50h]
  _DWORD v59[2]; // [xsp+48h] [xbp-48h] BYREF
  _BYTE v60[12]; // [xsp+50h] [xbp-40h]
  __int64 v61; // [xsp+5Ch] [xbp-34h]
  __int64 v62; // [xsp+64h] [xbp-2Ch]
  __int64 v63; // [xsp+6Ch] [xbp-24h]
  __int64 v64; // [xsp+74h] [xbp-1Ch]
  __int64 v65; // [xsp+7Ch] [xbp-14h]
  int v66; // [xsp+84h] [xbp-Ch]
  __int64 v67; // [xsp+88h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)(a2 + 200);
  v9 = *(_DWORD *)(a2 + 244);
  v10 = *(_DWORD *)(a2 + 248);
  v11 = *(_DWORD *)(a2 + 220);
  v12 = *(_DWORD *)(a2 + 224);
  v13 = *(_DWORD *)(a2 + 196) & 0x1F;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v14 = v9 & 0x1F
      | (32 * (v10 & 0x1F)) & 0x3FF
      | ((*(_WORD *)(a2 + 252) & 0x1F) << 10) & 0x7FFF
      | ((*(_DWORD *)(a2 + 256) & 0x1F) << 15) & 0xC00FFFFF
      | ((*(_DWORD *)(a2 + 260) & 0x1F) << 20) & 0xC1FFFFFF
      | ((*(_DWORD *)(a2 + 264) & 0x1F) << 25);
  v15 = *(_DWORD *)(a2 + 268) & 0x1F;
  v16 = v11 & 0x1F
      | (32 * (v12 & 0x1F)) & 0x3FF
      | ((*(_WORD *)(a2 + 228) & 0x1F) << 10) & 0x7FFF
      | ((*(_DWORD *)(a2 + 232) & 0x1F) << 15) & 0xC00FFFFF
      | ((*(_DWORD *)(a2 + 236) & 0x1F) << 20) & 0xC1FFFFFF
      | ((*(_DWORD *)(a2 + 240) & 0x1F) << 25);
  v17 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
  v18 = *(_DWORD *)(a2 + 272);
  v49 = v13 & 0xC000001F
      | (32 * (v8 & 0x1F)) & 0x3FF
      | ((*(_WORD *)(a2 + 204) & 0x1F) << 10) & 0x7FFF
      | ((*(_DWORD *)(a2 + 208) & 0x1F) << 15) & 0xC00FFFFF
      | ((*(_DWORD *)(a2 + 212) & 0x1F) << 20) & 0xC1FFFFFF
      | ((*(_DWORD *)(a2 + 216) & 0x1F) << 25);
  v50 = v16;
  v19 = *(_DWORD *)(a1 + 8);
  v20 = *(_DWORD *)(v17 + 416);
  *(_DWORD *)a3 = 2;
  v21 = v20 + v19;
  *(_QWORD *)(a3 + 12) = 0;
  v51 = v14;
  v52 = v15 & 0xFFFFFC1F | (32 * (v18 & 0x1F));
  *(_DWORD *)(a3 + 20) = v20 + v19 + 36;
  *(_QWORD *)(a3 + 32) = &v49;
  *(_QWORD *)(a3 + 40) = 0x1000000000LL;
  v22 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  if ( *((_DWORD *)v22 - 1) != -1839634494 )
    __break(0x8228u);
  v23 = v22(a3);
  if ( v23 )
  {
    v24 = v23;
    _drm_err("write spr cfg17 failed ret %d\n", v23);
  }
  else
  {
    v25 = *(_DWORD *)(a2 + 156);
    v26 = *(_DWORD *)(a2 + 140) & 0x7FF | ((*(_DWORD *)(a2 + 144) & 0x7FF) << 16);
    v27 = *(_DWORD *)(a2 + 148) & 0x7FF | ((*(_DWORD *)(a2 + 152) & 0x7FF) << 16);
    v49 = *(_DWORD *)(a2 + 132) & 0x7FF | ((*(_DWORD *)(a2 + 136) & 0x7FF) << 16);
    v50 = v26;
    v28 = v25 & 0x7FF | ((*(_DWORD *)(a2 + 160) & 0x7FF) << 16);
    v29 = *(_DWORD *)(a2 + 164) & 0x7FF | ((*(_DWORD *)(a2 + 168) & 0x7FF) << 16);
    v30 = *(_DWORD *)(a2 + 172) & 0x7FF | ((*(_DWORD *)(a2 + 176) & 0x7FF) << 16);
    v51 = v27;
    v52 = v28;
    v53 = __PAIR64__(v30, v29);
    v31 = *(_DWORD *)(a2 + 180);
    v32 = *(_DWORD *)(a2 + 184);
    v33 = *(_DWORD *)(a2 + 188);
    v34 = *(_DWORD *)(a2 + 192);
    *(_DWORD *)a3 = 2;
    *(_DWORD *)(a3 + 20) = v21 + 52;
    v35 = v31 & 0x7FF | ((v32 & 0x7FF) << 16);
    *(_QWORD *)(a3 + 12) = 0;
    v36 = v33 & 0x7FF | ((v34 & 0x7FF) << 16);
    *(_QWORD *)(a3 + 32) = &v49;
    *(_QWORD *)(a3 + 40) = 0x2000000000LL;
    v37 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
    v54 = __PAIR64__(v36, v35);
    if ( *((_DWORD *)v37 - 1) != -1839634494 )
      __break(0x822Au);
    v38 = v37(a3);
    if ( v38 )
    {
      v24 = v38;
      _drm_err("write spr cfg16 failed ret %d\n", v38);
    }
    else
    {
      v24 = reg_dmav1_setup_spr_cfg3_params(a1, a2, a3, a4);
      if ( !v24 )
      {
        if ( *(_WORD *)(a2 + 16) )
        {
          v40 = *(_QWORD *)(a1 + 72);
          v66 = 0;
          v65 = 0;
          v41 = *(_DWORD *)(a1 + 8);
          v42 = *(_WORD *)(a2 + 46);
          v64 = 0;
          v43 = *(_WORD *)(a2 + 40);
          v44 = *(_QWORD *)(v40 + 48);
          v45 = *(_WORD *)(a2 + 26);
          v46 = *(_WORD *)(a2 + 42);
          v47 = *(_WORD *)(a2 + 44);
          v63 = 0;
          LODWORD(v44) = *(_DWORD *)(v44 + 416);
          *(_DWORD *)a3 = 2;
          *(_QWORD *)(a3 + 12) = 0;
          v62 = 0;
          *(_QWORD *)(a3 + 32) = v59;
          *(_QWORD *)(a3 + 40) = 0xC00000000LL;
          *(_DWORD *)(a3 + 20) = v41 + v44 + 96;
          v61 = 0;
          *(_QWORD *)&v60[4] = 0;
          v59[0] = v45 & 0xF;
          v59[1] = v42 & 0x3FF | ((v43 & 0x7FF) << 16);
          v48 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
          *(_QWORD *)v60 = v46 & 0x7FF | ((unsigned __int16)(v47 & 0x7FF) << 16);
          if ( *((_DWORD *)v48 - 1) != -1839634494 )
            __break(0x8228u);
          v24 = v48(a3);
          if ( v24 )
            _drm_err("write spr cfg12 failed ret %d\n", v24);
        }
        else
        {
          v24 = 0;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v24;
}
