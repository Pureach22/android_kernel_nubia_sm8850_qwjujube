__int64 __fastcall dsi_conn_set_allowed_mode_switch(__int64 result, __int64 a2)
{
  _QWORD **v3; // x21
  __int64 v4; // x22
  _QWORD *v5; // x8
  _QWORD *v6; // x23
  __int64 v7; // x24
  _QWORD *v8; // x26
  __int64 v9; // x27
  _QWORD *v10; // x25
  int v11; // w20
  __int64 v12; // x8
  int v13; // w11
  __int64 v14; // [xsp+8h] [xbp-E8h]
  __int64 v15; // [xsp+10h] [xbp-E0h] BYREF
  __int64 v16; // [xsp+18h] [xbp-D8h] BYREF
  __int64 v17; // [xsp+20h] [xbp-D0h] BYREF
  __int64 v18; // [xsp+28h] [xbp-C8h]
  __int64 v19; // [xsp+30h] [xbp-C0h]
  __int64 v20; // [xsp+38h] [xbp-B8h]
  __int64 v21; // [xsp+40h] [xbp-B0h]
  __int64 v22; // [xsp+48h] [xbp-A8h]
  __int64 v23; // [xsp+50h] [xbp-A0h]
  __int64 v24; // [xsp+58h] [xbp-98h]
  __int64 v25; // [xsp+60h] [xbp-90h]
  __int64 v26; // [xsp+68h] [xbp-88h]
  __int64 v27; // [xsp+70h] [xbp-80h]
  __int64 v28; // [xsp+78h] [xbp-78h]
  __int64 v29; // [xsp+80h] [xbp-70h]
  __int64 v30; // [xsp+88h] [xbp-68h]
  __int64 v31; // [xsp+90h] [xbp-60h]
  __int64 v32; // [xsp+98h] [xbp-58h]
  __int64 v33; // [xsp+A0h] [xbp-50h]
  __int64 v34; // [xsp+A8h] [xbp-48h]
  __int64 v35; // [xsp+B0h] [xbp-40h]
  __int64 v36; // [xsp+B8h] [xbp-38h]
  __int64 v37; // [xsp+C0h] [xbp-30h]
  __int64 v38; // [xsp+C8h] [xbp-28h]
  __int64 v39; // [xsp+D0h] [xbp-20h]
  __int64 v40; // [xsp+D8h] [xbp-18h]
  __int64 v41; // [xsp+E0h] [xbp-10h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  if ( a2 && (v14 = *(_QWORD *)(a2 + 264)) != 0 )
  {
    v3 = (_QWORD **)(result + 176);
    LODWORD(v4) = -2;
    v5 = (_QWORD *)(result + 176);
    do
    {
      v5 = (_QWORD *)*v5;
      v4 = (unsigned int)(v4 + 1);
    }
    while ( v5 != v3 );
    v6 = *v3;
    if ( *v3 != v3 )
    {
      v7 = 0;
      v8 = (_QWORD *)(result + 176);
      do
      {
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
        v17 = 0;
        v18 = 0;
        LODWORD(v17) = *((unsigned __int16 *)v6 - 30);
        HIDWORD(v17) = *((unsigned __int16 *)v6 - 27) - *((unsigned __int16 *)v6 - 28);
        LODWORD(v18) = *((unsigned __int16 *)v6 - 27) - *((unsigned __int16 *)v6 - 29) - HIDWORD(v17);
        HIDWORD(v18) = *((unsigned __int16 *)v6 - 29) - *((unsigned __int16 *)v6 - 30);
        LODWORD(v19) = *((unsigned __int16 *)v6 - 26);
        LODWORD(v20) = *((unsigned __int16 *)v6 - 25);
        HIDWORD(v20) = *((unsigned __int16 *)v6 - 22) - *((unsigned __int16 *)v6 - 23);
        LODWORD(v21) = *((unsigned __int16 *)v6 - 22) - *((unsigned __int16 *)v6 - 24) - HIDWORD(v20);
        HIDWORD(v21) = *((unsigned __int16 *)v6 - 24) - *((unsigned __int16 *)v6 - 25);
        HIDWORD(v22) = drm_mode_vrefresh(v6 - 8);
        BYTE4(v19) = *(_BYTE *)(v6 - 5) & 1;
        LOBYTE(v22) = (*(_BYTE *)(v6 - 5) & 4) != 0;
        result = dsi_display_find_mode(a2, &v17, 0, &v16);
        if ( (_DWORD)result )
          break;
        v9 = *(_QWORD *)(v16 + 184);
        *(_DWORD *)(v9 + 3448) |= 1LL << v7;
        if ( v7 == v4 )
          break;
        v8 = (_QWORD *)*v8;
        v10 = (_QWORD *)*v8;
        if ( (_QWORD *)*v8 != v8 )
        {
          v11 = 1;
          do
          {
            if ( v10 != v3 )
            {
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
              v17 = 0;
              v18 = 0;
              LODWORD(v17) = *((unsigned __int16 *)v10 - 30);
              HIDWORD(v17) = *((unsigned __int16 *)v10 - 27) - *((unsigned __int16 *)v10 - 28);
              LODWORD(v18) = *((unsigned __int16 *)v10 - 27) - *((unsigned __int16 *)v10 - 29) - HIDWORD(v17);
              HIDWORD(v18) = *((unsigned __int16 *)v10 - 29) - *((unsigned __int16 *)v10 - 30);
              LODWORD(v19) = *((unsigned __int16 *)v10 - 26);
              LODWORD(v20) = *((unsigned __int16 *)v10 - 25);
              HIDWORD(v20) = *((unsigned __int16 *)v10 - 22) - *((unsigned __int16 *)v10 - 23);
              LODWORD(v21) = *((unsigned __int16 *)v10 - 22) - *((unsigned __int16 *)v10 - 24) - HIDWORD(v20);
              HIDWORD(v21) = *((unsigned __int16 *)v10 - 24) - *((unsigned __int16 *)v10 - 25);
              HIDWORD(v22) = drm_mode_vrefresh(v10 - 8);
              BYTE4(v19) = *(_BYTE *)(v10 - 5) & 1;
              LOBYTE(v22) = (*(_BYTE *)(v10 - 5) & 4) != 0;
              result = dsi_display_find_mode(a2, &v17, 0, &v15);
              if ( (_DWORD)result )
                goto LABEL_28;
              v12 = *(_QWORD *)(v15 + 184);
              v13 = *(_DWORD *)(v15 + 160) & *(_DWORD *)(v16 + 160);
              if ( (v13 & 2) != 0
                || (v13 & 1) != 0 && ((*(_BYTE *)(v14 + 1388) & 1) != 0 || (*(_BYTE *)(v14 + 1392) & 1) != 0)
                || *(_DWORD *)(v16 + 44) == *(_DWORD *)(v15 + 44)
                && *(_DWORD *)(v16 + 24) == *(_DWORD *)(v15 + 24)
                && *(_DWORD *)v16 == *(_DWORD *)v15 )
              {
                *(_DWORD *)(v9 + 3448) |= 1LL << ((unsigned __int8)v11 + (unsigned __int8)v7);
                *(_DWORD *)(v12 + 3448) |= 1LL << v7;
              }
              if ( v11 + (int)v7 >= (unsigned int)v4 )
                break;
              ++v11;
            }
            v10 = (_QWORD *)*v10;
          }
          while ( v10 != v8 );
        }
        v6 = (_QWORD *)*v6;
        ++v7;
      }
      while ( v6 != v3 );
    }
  }
  else
  {
    result = drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid parameters");
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
