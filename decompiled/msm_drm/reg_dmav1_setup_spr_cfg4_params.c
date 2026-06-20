__int64 __fastcall reg_dmav1_setup_spr_cfg4_params(__int64 a1, _WORD *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  int v5; // w9
  __int16 v6; // w11
  __int16 v7; // w12
  __int64 v8; // x8
  char v9; // w10
  __int16 v10; // w14
  __int16 v11; // w15
  __int64 (__fastcall *v12)(_QWORD); // x8
  unsigned int v13; // w19
  _DWORD v15[2]; // [xsp+8h] [xbp-48h] BYREF
  _BYTE v16[12]; // [xsp+10h] [xbp-40h]
  __int64 v17; // [xsp+1Ch] [xbp-34h]
  __int64 v18; // [xsp+24h] [xbp-2Ch]
  __int64 v19; // [xsp+2Ch] [xbp-24h]
  __int64 v20; // [xsp+34h] [xbp-1Ch]
  __int64 v21; // [xsp+3Ch] [xbp-14h]
  int v22; // [xsp+44h] [xbp-Ch]
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2[8] )
  {
    v4 = *(_QWORD *)(a1 + 72);
    v22 = 0;
    v21 = 0;
    v5 = *(_DWORD *)(a1 + 8);
    v6 = a2[23];
    v20 = 0;
    v7 = a2[20];
    v8 = *(_QWORD *)(v4 + 48);
    v9 = a2[13];
    v10 = a2[21];
    v11 = a2[22];
    v19 = 0;
    LODWORD(v8) = *(_DWORD *)(v8 + 416);
    *(_DWORD *)a3 = 2;
    *(_QWORD *)(a3 + 12) = 0;
    v18 = 0;
    *(_QWORD *)(a3 + 32) = v15;
    *(_QWORD *)(a3 + 40) = 0xC00000000LL;
    *(_DWORD *)(a3 + 20) = v5 + v8 + 96;
    v17 = 0;
    *(_QWORD *)&v16[4] = 0;
    v15[0] = v9 & 0xF;
    v15[1] = v6 & 0x3FF | ((v7 & 0x7FF) << 16);
    v12 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
    *(_QWORD *)v16 = v10 & 0x7FF | ((unsigned __int16)(v11 & 0x7FF) << 16);
    if ( *((_DWORD *)v12 - 1) != -1839634494 )
      __break(0x8228u);
    v13 = v12(a3);
    if ( v13 )
      _drm_err("write spr cfg12 failed ret %d\n", v13);
  }
  else
  {
    v13 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}
