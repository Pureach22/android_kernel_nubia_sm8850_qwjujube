__int64 __fastcall cam_ife_mgr_csid_stop_hw(__int64 result, _QWORD *a2, int a3, int a4, char a5, char a6)
{
  _QWORD *v6; // x23
  unsigned int v7; // w22
  char v8; // w25
  char v9; // w24
  __int64 v10; // x21
  __int64 v11; // x21
  __int64 v12; // x8
  __int64 (__fastcall *v13)(__int64, __int64 *, __int64); // x9
  __int64 v14; // x0
  int v15; // [xsp+24h] [xbp-9Ch]
  int v16; // [xsp+24h] [xbp-9Ch]
  __int64 v17; // [xsp+28h] [xbp-98h]
  __int64 v18; // [xsp+28h] [xbp-98h]
  _QWORD *v19; // [xsp+30h] [xbp-90h]
  _QWORD *v20; // [xsp+30h] [xbp-90h]
  int v21; // [xsp+3Ch] [xbp-84h]
  int v22; // [xsp+3Ch] [xbp-84h]
  __int64 v23; // [xsp+40h] [xbp-80h] BYREF
  __int64 *v24; // [xsp+48h] [xbp-78h]
  __int64 v25; // [xsp+50h] [xbp-70h]
  __int64 v26; // [xsp+58h] [xbp-68h] BYREF
  __int64 v27; // [xsp+60h] [xbp-60h]
  __int64 v28; // [xsp+68h] [xbp-58h]
  __int64 v29; // [xsp+70h] [xbp-50h]
  __int64 v30; // [xsp+78h] [xbp-48h]
  __int64 v31; // [xsp+80h] [xbp-40h]
  __int64 v32; // [xsp+88h] [xbp-38h]
  __int64 v33; // [xsp+90h] [xbp-30h]
  __int64 v34; // [xsp+98h] [xbp-28h]
  __int64 v35; // [xsp+A0h] [xbp-20h]
  __int64 v36; // [xsp+A8h] [xbp-18h]
  __int64 v37; // [xsp+B0h] [xbp-10h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (_QWORD *)*a2;
  if ( (_QWORD *)*a2 != a2 )
  {
    v7 = 0;
    v8 = a5 & 1;
    v9 = a6 & 1;
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
    v24 = nullptr;
    do
    {
      v10 = v6[4];
      if ( v10 && *(_DWORD *)(v10 + 8) == 4 && *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL) == a3 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v21 = a3;
          v17 = result;
          v19 = a2;
          v15 = a4;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_csid_stop_hw",
            2491,
            "base_idx %d ctx_idx: %u res:%s res_id %d cnt %u",
            a3,
            *(_DWORD *)(result + 56),
            (const char *)(v10 + 128),
            *(_DWORD *)(v10 + 4),
            v7);
          result = v17;
          a2 = v19;
          a3 = v21;
          a4 = v15;
          if ( v7 > 0xA )
            goto LABEL_21;
        }
        else if ( v7 > 0xA )
        {
          goto LABEL_21;
        }
        *(&v26 + v7++) = v10;
      }
      v11 = v6[5];
      if ( v11 && *(_DWORD *)(v11 + 8) == 4 && *(_DWORD *)(*(_QWORD *)(v11 + 16) + 4LL) == a3 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v22 = a3;
          v18 = result;
          v20 = a2;
          v16 = a4;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_csid_stop_hw",
            2491,
            "base_idx %d ctx_idx: %u res:%s res_id %d cnt %u",
            a3,
            *(_DWORD *)(result + 56),
            (const char *)(v11 + 128),
            *(_DWORD *)(v11 + 4),
            v7);
          result = v18;
          a2 = v20;
          a3 = v22;
          a4 = v16;
          if ( v7 > 0xA )
            goto LABEL_21;
        }
        else if ( v7 > 0xA )
        {
          goto LABEL_21;
        }
        *(&v26 + v7++) = v11;
      }
      v6 = (_QWORD *)*v6;
    }
    while ( v6 != a2 );
    while ( v7 )
    {
      v24 = &v26;
      v12 = *(_QWORD *)(v26 + 16);
      LODWORD(v25) = v7;
      LODWORD(v23) = a4;
      v13 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v12 + 64);
      v14 = *(_QWORD *)(v12 + 112);
      BYTE4(v25) = v8;
      BYTE5(v25) = v9;
      if ( *((_DWORD *)v13 - 1) != 1989616049 )
        __break(0x8229u);
      result = v13(v14, &v23, 24);
      *(_BYTE *)(v26 + 144) = 0;
      if ( v7 == 1 )
        break;
      *(_BYTE *)(v27 + 144) = 0;
      if ( v7 == 2 )
        break;
      *(_BYTE *)(v28 + 144) = 0;
      if ( v7 == 3 )
        break;
      *(_BYTE *)(v29 + 144) = 0;
      if ( v7 == 4 )
        break;
      *(_BYTE *)(v30 + 144) = 0;
      if ( v7 == 5 )
        break;
      *(_BYTE *)(v31 + 144) = 0;
      if ( v7 == 6 )
        break;
      *(_BYTE *)(v32 + 144) = 0;
      if ( v7 == 7 )
        break;
      *(_BYTE *)(v33 + 144) = 0;
      if ( v7 == 8 )
        break;
      *(_BYTE *)(v34 + 144) = 0;
      if ( v7 == 9 )
        break;
      *(_BYTE *)(v35 + 144) = 0;
      if ( v7 == 10 )
        break;
      *(_BYTE *)(v36 + 144) = 0;
      if ( v7 == 11 )
        break;
LABEL_21:
      __break(0x5512u);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
