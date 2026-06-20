__int64 __fastcall cam_ife_mgr_csid_start_hw(_DWORD *a1, __int64 a2, int a3, char a4, char a5, char a6, char a7)
{
  int v7; // w8
  unsigned int v8; // w10
  __int64 v10; // x11
  char v11; // w25
  _DWORD *v12; // x12
  _QWORD *v13; // x28
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x0
  __int64 v17; // x19
  _DWORD *v18; // x9
  _DWORD *v19; // x21
  __int64 v20; // x22
  _QWORD *v21; // x23
  char v22; // w24
  unsigned int v23; // w27
  __int64 v24; // x8
  __int64 v25; // x26
  int v26; // w8
  bool v27; // w19
  const char *v28; // x11
  int v29; // w7
  __int64 v30; // x8
  __int64 v31; // x21
  int v32; // w9
  __int64 result; // x0
  __int64 v34; // [xsp+20h] [xbp-C0h]
  __int64 v35; // [xsp+28h] [xbp-B8h]
  char v36; // [xsp+30h] [xbp-B0h]
  char v37; // [xsp+34h] [xbp-ACh]
  char v38; // [xsp+38h] [xbp-A8h]
  char v39; // [xsp+3Ch] [xbp-A4h]
  _DWORD *v40; // [xsp+40h] [xbp-A0h]
  unsigned int v41; // [xsp+48h] [xbp-98h]
  _DWORD *v42; // [xsp+50h] [xbp-90h]
  _QWORD *v43; // [xsp+58h] [xbp-88h] BYREF
  __int64 v44; // [xsp+60h] [xbp-80h]
  __int64 v45; // [xsp+68h] [xbp-78h]
  __int64 v46; // [xsp+70h] [xbp-70h]
  _QWORD v47[13]; // [xsp+78h] [xbp-68h] BYREF

  v47[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a1[2179];
  v8 = v7 - 1;
  if ( v7 - 1 >= 0 )
  {
    v38 = a5 & 1;
    v39 = a4 & 1;
    v36 = a7 & 1;
    v37 = a6 & 1;
    v10 = 0;
    v11 = 0;
    v12 = a1 + 2146;
    v13 = a1 + 52;
    v14 = (unsigned int)(v7 - 1);
    memset(v47, 0, 88);
    v43 = nullptr;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v41 = v8;
    v42 = a1;
    v40 = a1 + 2146;
    do
    {
      if ( v8 >= 0xB )
        goto LABEL_38;
      v19 = &v12[3 * v14];
      v20 = v14;
      if ( !v19[2] )
      {
        v21 = (_QWORD *)*v13;
        if ( (_QWORD *)*v13 != v13 )
        {
          v22 = 0;
          v23 = 0;
          while ( 1 )
          {
            v24 = (unsigned int)v19[1];
            if ( (unsigned int)v24 > 1 )
              break;
            v25 = v21[v24 + 4];
            if ( v25 && *v19 == *(_DWORD *)(*(_QWORD *)(v25 + 16) + 4LL) )
            {
              v26 = *((_DWORD *)v21 + 5);
              if ( v26 == a3 || a1[2328] == 2 && !*(_DWORD *)(v25 + 4) )
                v10 = v25;
              v27 = v26 == 5;
              v22 |= *((_DWORD *)v21 + 26) != 0;
              if ( (debug_mdl & 8) != 0 && !debug_priority )
              {
                v34 = v10;
                v35 = a2;
                v28 = "N";
                if ( (v22 & 1) != 0 )
                  v28 = "Y";
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_ife_mgr_csid_start_hw",
                  1741,
                  "csid[%u] ctx_idx: %u res:%s res_id %d cnt %u, is_secure: %s",
                  *v19,
                  a1[14],
                  (const char *)(v25 + 128),
                  *(_DWORD *)(v25 + 4),
                  v23,
                  v28);
                v12 = v40;
                v8 = v41;
                v10 = v34;
                a2 = v35;
                a1 = v42;
              }
              if ( v23 > 0xA )
                break;
              v11 |= v27;
              v47[v23++] = v25;
            }
            v21 = (_QWORD *)*v21;
            if ( v21 == v13 )
              goto LABEL_27;
          }
LABEL_38:
          __break(0x5512u);
        }
        v23 = 0;
        v22 = 0;
LABEL_27:
        if ( (v11 & 1) == 0 && v10 )
          *(_BYTE *)(v10 + 144) = 1;
        if ( v23 )
        {
          v29 = a1[2181];
          LODWORD(v44) = v23;
          v43 = v47;
          v30 = *(__int64 *)((char *)&qword_10 + v47[0]);
          if ( v29 < 0 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_mgr_csid_start_hw",
              1757,
              "CSID[%u], physical CDM hw_idx is invalid: %d on ctx: %u",
              *(unsigned int *)(v30 + 4));
            result = 4294967274LL;
            goto LABEL_36;
          }
          v31 = v10;
          if ( a2 && *(_BYTE *)(a2 + 4289) == 1 )
          {
            v32 = *(_DWORD *)(a2 + 4292);
            BYTE2(v46) = 1;
            LODWORD(v45) = v32;
          }
          v15 = a1[2366];
          v16 = *(_QWORD *)(v30 + 112);
          v17 = a2;
          HIDWORD(v44) = v29;
          HIBYTE(v45) = v15 != 0;
          BYTE5(v45) = v39;
          LOBYTE(v46) = v37;
          v18 = *(_DWORD **)(v30 + 56);
          BYTE6(v45) = v38;
          BYTE4(v45) = v22 & 1;
          BYTE1(v46) = v36;
          if ( *(v18 - 1) != 1989616049 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD **, __int64))v18)(v16, &v43, 32);
          v8 = v41;
          a1 = v42;
          a2 = v17;
          v12 = v40;
          v10 = v31;
        }
      }
      v14 = v20 - 1;
    }
    while ( v20 );
  }
  result = 0;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
