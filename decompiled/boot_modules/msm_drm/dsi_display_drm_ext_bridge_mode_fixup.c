__int64 __fastcall dsi_display_drm_ext_bridge_mode_fixup(__int64 a1, __int64 *a2)
{
  __int64 bridge; // x0
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 (__fastcall *v14)(__int64, __int64 *, __int64 *); // x9
  __int64 v16; // [xsp+0h] [xbp-80h] BYREF
  __int64 v17; // [xsp+8h] [xbp-78h]
  __int64 v18; // [xsp+10h] [xbp-70h]
  __int64 v19; // [xsp+18h] [xbp-68h]
  __int64 v20; // [xsp+20h] [xbp-60h]
  __int64 v21; // [xsp+28h] [xbp-58h]
  __int64 v22; // [xsp+30h] [xbp-50h]
  __int64 v23; // [xsp+38h] [xbp-48h]
  __int64 v24; // [xsp+40h] [xbp-40h]
  __int64 v25; // [xsp+48h] [xbp-38h]
  __int64 v26; // [xsp+50h] [xbp-30h]
  __int64 v27; // [xsp+58h] [xbp-28h]
  __int64 v28; // [xsp+60h] [xbp-20h]
  __int64 v29; // [xsp+68h] [xbp-18h]
  __int64 v30; // [xsp+70h] [xbp-10h]
  __int64 v31; // [xsp+78h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  bridge = dsi_display_ext_get_bridge();
  if ( bridge )
  {
    v5 = a2[5];
    v20 = a2[4];
    v21 = v5;
    v6 = a2[9];
    v24 = a2[8];
    v25 = v6;
    v7 = a2[7];
    v22 = a2[6];
    v23 = v7;
    v8 = a2[14];
    v29 = a2[13];
    v30 = v8;
    v9 = a2[12];
    v10 = a2[10];
    v27 = a2[11];
    v28 = v9;
    v12 = *a2;
    v11 = a2[1];
    v26 = v10;
    v16 = v12;
    v17 = v11;
    v13 = a2[3];
    v18 = a2[2];
    v19 = v13;
    LODWORD(v11) = *(_DWORD *)(*(_QWORD *)bridge + 160LL);
    WORD2(v16) = WORD2(v12) / (unsigned int)v11;
    v14 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64 *))(*(_QWORD *)(bridge + 24) + 24LL);
    HIWORD(v16) = HIWORD(v16) / (unsigned int)v11;
    LOWORD(v17) = (unsigned __int16)v17 / (unsigned int)v11;
    WORD1(v17) = WORD1(v17) / (unsigned int)v11;
    WORD2(v17) = WORD2(v17) / (unsigned int)v11;
    LODWORD(v16) = (unsigned int)v16 / (unsigned int)v11;
    if ( *((_DWORD *)v14 - 1) != -875014461 )
      __break(0x8229u);
    LOBYTE(bridge) = v14(a1, &v16, &v16);
  }
  _ReadStatusReg(SP_EL0);
  return bridge & 1;
}
