__int64 __fastcall nl80211_parse_mesh_config(__int64 a1, __int64 a2, int *a3)
{
  __int64 v4; // x8
  _WORD *v5; // x2
  __int64 result; // x0
  int v8; // w8
  __int16 v9; // w9
  __int64 v10; // [xsp+8h] [xbp-108h] BYREF
  __int64 v11; // [xsp+10h] [xbp-100h]
  __int64 v12; // [xsp+18h] [xbp-F8h]
  __int64 v13; // [xsp+20h] [xbp-F0h]
  __int64 v14; // [xsp+28h] [xbp-E8h]
  __int64 v15; // [xsp+30h] [xbp-E0h]
  __int64 v16; // [xsp+38h] [xbp-D8h]
  __int64 v17; // [xsp+40h] [xbp-D0h]
  __int64 v18; // [xsp+48h] [xbp-C8h]
  __int64 v19; // [xsp+50h] [xbp-C0h]
  __int64 v20; // [xsp+58h] [xbp-B8h]
  __int64 v21; // [xsp+60h] [xbp-B0h]
  __int64 v22; // [xsp+68h] [xbp-A8h]
  __int64 v23; // [xsp+70h] [xbp-A0h]
  __int64 v24; // [xsp+78h] [xbp-98h]
  __int64 v25; // [xsp+80h] [xbp-90h]
  __int64 v26; // [xsp+88h] [xbp-88h]
  __int64 v27; // [xsp+90h] [xbp-80h]
  __int64 v28; // [xsp+98h] [xbp-78h]
  __int64 v29; // [xsp+A0h] [xbp-70h]
  __int64 v30; // [xsp+A8h] [xbp-68h]
  __int64 v31; // [xsp+B0h] [xbp-60h]
  __int64 v32; // [xsp+B8h] [xbp-58h]
  __int64 v33; // [xsp+C0h] [xbp-50h]
  __int64 v34; // [xsp+C8h] [xbp-48h]
  __int64 v35; // [xsp+D0h] [xbp-40h]
  __int64 v36; // [xsp+D8h] [xbp-38h]
  __int64 v37; // [xsp+E0h] [xbp-30h]
  __int64 v38; // [xsp+E8h] [xbp-28h]
  __int64 v39; // [xsp+F0h] [xbp-20h]
  __int64 v40; // [xsp+F8h] [xbp-18h]
  __int64 v41; // [xsp+100h] [xbp-10h]
  __int64 v42; // [xsp+108h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v5 = *(_WORD **)(v4 + 280);
  if ( !v5
    || (unsigned int)_nla_parse(
                       &v10,
                       31,
                       v5 + 2,
                       (unsigned __int16)(*v5 - 4),
                       &nl80211_meshconf_params_policy,
                       0,
                       *(_QWORD *)(a1 + 64)) )
  {
    goto LABEL_3;
  }
  v8 = v11;
  if ( v11 )
  {
    *(_WORD *)a2 = *(_WORD *)(v11 + 4);
    v8 = 1;
  }
  if ( v12 )
  {
    v8 |= 2u;
    *(_WORD *)(a2 + 2) = *(_WORD *)(v12 + 4);
  }
  if ( v13 )
  {
    v8 |= 4u;
    *(_WORD *)(a2 + 4) = *(_WORD *)(v13 + 4);
  }
  if ( v14 )
  {
    v8 |= 8u;
    *(_WORD *)(a2 + 6) = *(_WORD *)(v14 + 4);
  }
  if ( v15 )
  {
    v8 |= 0x10u;
    *(_BYTE *)(a2 + 8) = *(_BYTE *)(v15 + 4);
  }
  if ( v16 )
  {
    v8 |= 0x20u;
    *(_BYTE *)(a2 + 9) = *(_BYTE *)(v16 + 4);
  }
  if ( v25 )
  {
    v8 |= 0x4000u;
    *(_BYTE *)(a2 + 10) = *(_BYTE *)(v25 + 4);
  }
  if ( v17 )
  {
    v8 |= 0x40u;
    *(_BYTE *)(a2 + 11) = *(_BYTE *)(v17 + 4) != 0;
  }
  if ( v31 )
  {
    v8 |= 0x100000u;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(v31 + 4);
  }
  if ( v18 )
  {
    v8 |= 0x80u;
    *(_BYTE *)(a2 + 16) = *(_BYTE *)(v18 + 4);
  }
  if ( v19 )
  {
    v8 |= 0x100u;
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(v19 + 4);
  }
  if ( (v8 & 0x200) != 0 && (unsigned int)(*(_DWORD *)(a2 + 20) - 0x10000) < 0xFFFF0001 )
    goto LABEL_3;
  if ( v20 )
  {
    v8 |= 0x200u;
    *(_WORD *)(a2 + 24) = *(_WORD *)(v20 + 4);
  }
  if ( v21 )
  {
    v8 |= 0x400u;
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(v21 + 4);
  }
  if ( (v8 & 0x800) != 0 && (unsigned int)(*(_DWORD *)(a2 + 28) - 0x10000) < 0xFFFF0001 )
    goto LABEL_3;
  if ( v22 )
  {
    v8 |= 0x800u;
    *(_WORD *)(a2 + 32) = *(_WORD *)(v22 + 4);
  }
  if ( v28 )
  {
    v8 |= 0x20000u;
    *(_WORD *)(a2 + 34) = *(_WORD *)(v28 + 4);
  }
  if ( v23 )
  {
    v8 |= 0x1000u;
    *(_WORD *)(a2 + 36) = *(_WORD *)(v23 + 4);
  }
  if ( v24 )
  {
    v8 |= 0x2000u;
    *(_BYTE *)(a2 + 38) = *(_BYTE *)(v24 + 4);
  }
  if ( v26 )
  {
    v8 |= 0x8000u;
    *(_WORD *)(a2 + 42) = *(_WORD *)(v26 + 4);
  }
  if ( v27 )
  {
    v8 |= 0x10000u;
    *(_BYTE *)(a2 + 44) = *(_BYTE *)(v27 + 4) != 0;
  }
  if ( v29 )
  {
    v8 |= 0x40000u;
    *(_BYTE *)(a2 + 45) = *(_BYTE *)(v29 + 4) != 0;
  }
  if ( v30 )
  {
    v8 |= 0x80000u;
    *(_DWORD *)(a2 + 48) = *(_DWORD *)(v30 + 4);
  }
  if ( v39 )
  {
    v8 |= 0x10000000u;
    *(_BYTE *)(a2 + 39) = *(_BYTE *)(v39 + 4) != 0;
  }
  if ( v41 )
  {
    v8 |= 0x40000000u;
    *(_BYTE *)(a2 + 40) = *(_BYTE *)(v41 + 4) != 0;
  }
  if ( v32 )
  {
    v9 = *(_WORD *)(v32 + 4);
    if ( (v9 & 0xFFE8) != 0 )
    {
LABEL_3:
      result = 4294967274LL;
      goto LABEL_4;
    }
    v8 |= 0x200000u;
    *(_WORD *)(a2 + 52) = v9 & 7;
  }
  if ( v33 )
  {
    v8 |= 0x400000u;
    *(_DWORD *)(a2 + 56) = *(_DWORD *)(v33 + 4);
  }
  if ( (v8 & 0x800000) != 0 && (unsigned int)(*(_DWORD *)(a2 + 56) - 0x10000) < 0xFFFF0001 )
    goto LABEL_3;
  if ( v34 )
  {
    v8 |= 0x800000u;
    *(_WORD *)(a2 + 60) = *(_WORD *)(v34 + 4);
  }
  if ( v35 )
  {
    v8 |= 0x1000000u;
    *(_WORD *)(a2 + 62) = *(_WORD *)(v35 + 4);
  }
  if ( v36 )
  {
    v8 |= 0x2000000u;
    *(_DWORD *)(a2 + 64) = *(_DWORD *)(v36 + 4);
  }
  if ( v37 )
  {
    v8 |= 0x4000000u;
    *(_WORD *)(a2 + 68) = *(_WORD *)(v37 + 4);
  }
  if ( v38 )
  {
    v8 |= 0x8000000u;
    *(_DWORD *)(a2 + 72) = *(_DWORD *)(v38 + 4);
  }
  if ( v40 )
  {
    v8 |= 0x20000000u;
    *(_BYTE *)(a2 + 76) = *(_BYTE *)(v40 + 4) != 0;
  }
  result = 0;
  if ( a3 )
    *a3 = v8;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
