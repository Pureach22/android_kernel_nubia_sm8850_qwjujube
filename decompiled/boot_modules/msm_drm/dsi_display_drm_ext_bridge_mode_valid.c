__int64 __fastcall dsi_display_drm_ext_bridge_mode_valid(__int64 a1, __int64 a2, __int64 *a3)
{
  _QWORD *bridge; // x0
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 (__fastcall *v16)(__int64, __int64, __int64 *); // x9
  __int64 result; // x0
  __int64 v18; // [xsp+0h] [xbp-80h] BYREF
  __int64 v19; // [xsp+8h] [xbp-78h]
  __int64 v20; // [xsp+10h] [xbp-70h]
  __int64 v21; // [xsp+18h] [xbp-68h]
  __int64 v22; // [xsp+20h] [xbp-60h]
  __int64 v23; // [xsp+28h] [xbp-58h]
  __int64 v24; // [xsp+30h] [xbp-50h]
  __int64 v25; // [xsp+38h] [xbp-48h]
  __int64 v26; // [xsp+40h] [xbp-40h]
  __int64 v27; // [xsp+48h] [xbp-38h]
  __int64 v28; // [xsp+50h] [xbp-30h]
  __int64 v29; // [xsp+58h] [xbp-28h]
  __int64 v30; // [xsp+60h] [xbp-20h]
  __int64 v31; // [xsp+68h] [xbp-18h]
  __int64 v32; // [xsp+70h] [xbp-10h]
  __int64 v33; // [xsp+78h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  bridge = (_QWORD *)dsi_display_ext_get_bridge();
  if ( bridge )
  {
    v7 = a3[5];
    v22 = a3[4];
    v23 = v7;
    v8 = a3[9];
    v26 = a3[8];
    v27 = v8;
    v9 = a3[7];
    v24 = a3[6];
    v25 = v9;
    v10 = a3[14];
    v31 = a3[13];
    v32 = v10;
    v11 = a3[12];
    v12 = a3[10];
    v29 = a3[11];
    v30 = v11;
    v14 = *a3;
    v13 = a3[1];
    v28 = v12;
    v18 = v14;
    v19 = v13;
    v15 = a3[3];
    v20 = a3[2];
    v21 = v15;
    LODWORD(v13) = *(_DWORD *)(*bridge + 160LL);
    WORD2(v18) = WORD2(v14) / (unsigned int)v13;
    v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(bridge[3] + 16LL);
    HIWORD(v18) = HIWORD(v18) / (unsigned int)v13;
    LOWORD(v19) = (unsigned __int16)v19 / (unsigned int)v13;
    WORD1(v19) = WORD1(v19) / (unsigned int)v13;
    WORD2(v19) = WORD2(v19) / (unsigned int)v13;
    LODWORD(v18) = (unsigned int)v18 / (unsigned int)v13;
    if ( *((_DWORD *)v16 - 1) != 618918276 )
      __break(0x8229u);
    result = v16(a1, a2, &v18);
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
