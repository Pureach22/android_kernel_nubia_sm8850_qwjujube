__int64 __fastcall sde_cp_ad_set_prop(__int64 a1, int a2)
{
  unsigned __int64 v3; // x21
  __int64 result; // x0
  unsigned int v5; // w19
  unsigned __int64 v6; // x22
  __int64 *v7; // x23
  __int64 v8; // x8
  __int64 v9; // x20
  int v10; // w10
  int v11; // w8
  __int64 (__fastcall *v12)(__int64, int *); // x8
  __int64 (__fastcall *v13)(__int64, __int64 *); // x8
  __int64 v14; // [xsp+0h] [xbp-F0h] BYREF
  _QWORD *v15; // [xsp+8h] [xbp-E8h]
  int v16; // [xsp+14h] [xbp-DCh] BYREF
  _QWORD v17[3]; // [xsp+18h] [xbp-D8h] BYREF
  __int64 v18; // [xsp+30h] [xbp-C0h]
  __int64 v19; // [xsp+38h] [xbp-B8h]
  __int64 v20; // [xsp+40h] [xbp-B0h]
  __int64 v21; // [xsp+48h] [xbp-A8h]
  __int64 v22; // [xsp+50h] [xbp-A0h]
  __int64 v23; // [xsp+58h] [xbp-98h]
  __int64 v24; // [xsp+60h] [xbp-90h]
  __int64 v25; // [xsp+68h] [xbp-88h]
  __int64 v26; // [xsp+70h] [xbp-80h]
  __int64 v27; // [xsp+78h] [xbp-78h]
  __int64 v28; // [xsp+80h] [xbp-70h]
  __int64 v29; // [xsp+88h] [xbp-68h]
  __int64 v30; // [xsp+90h] [xbp-60h]
  __int64 v31; // [xsp+98h] [xbp-58h]
  __int64 v32; // [xsp+A0h] [xbp-50h]
  __int64 v33; // [xsp+A8h] [xbp-48h]
  __int64 v34; // [xsp+B0h] [xbp-40h]
  __int64 v35; // [xsp+B8h] [xbp-38h]
  __int64 v36; // [xsp+C0h] [xbp-30h]
  __int64 v37; // [xsp+C8h] [xbp-28h]
  __int64 v38; // [xsp+D0h] [xbp-20h]
  __int64 v39; // [xsp+D8h] [xbp-18h]
  __int64 v40; // [xsp+E0h] [xbp-10h]
  __int64 v41; // [xsp+E8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(a1 + 2192);
  v16 = a2;
  v14 = 0;
  v15 = nullptr;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  result = sde_crtc_get_disp_op(a1);
  HIDWORD(v18) = *(_DWORD *)(a1 + 2192);
  if ( (_DWORD)v3 )
  {
    v5 = result;
    v6 = 0;
    v7 = (__int64 *)(a1 + 2216);
    do
    {
      if ( v6 == 8 )
LABEL_16:
        __break(0x5512u);
      v8 = *(v7 - 2);
      if ( !v8 )
        break;
      v9 = *v7;
      if ( !*v7 )
        break;
      if ( v5 > 2 )
        goto LABEL_16;
      if ( !*(_QWORD *)(v9 + 496 + 8LL * v5) || !*(_QWORD *)(v9 + 520 + 8LL * v5) )
        break;
      v10 = *(_DWORD *)(v8 + 376);
      v19 = *(v7 - 2);
      v11 = *(_DWORD *)(v8 + 380);
      LODWORD(v14) = v16;
      v15 = v17;
      LODWORD(v20) = v11;
      HIDWORD(v20) = v10 * v3;
      v12 = *(__int64 (__fastcall **)(__int64, int *))(v9 + 496 + 8LL * v5);
      if ( *((_DWORD *)v12 - 1) != -1077458825 )
        __break(0x8228u);
      result = v12(v9, &v16);
      if ( (_DWORD)result )
        break;
      v13 = *(__int64 (__fastcall **)(__int64, __int64 *))(v9 + 520 + 8LL * v5);
      if ( *((_DWORD *)v13 - 1) != 1841204718 )
        __break(0x8228u);
      result = v13(v9, &v14);
      ++v6;
      v7 += 6;
    }
    while ( v6 < v3 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
