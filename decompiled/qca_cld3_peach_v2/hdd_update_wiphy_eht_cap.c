__int64 __fastcall hdd_update_wiphy_eht_cap(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 v13; // x21
  __int64 v14; // x23
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _WORD *v24; // x24
  __int64 v25; // x9
  bool v26; // w8
  __int64 v27; // x8
  int v28; // w8
  _WORD *v29; // x22
  __int64 v30; // x9
  bool v31; // w8
  __int64 v32; // x8
  int v33; // w8
  __int64 v34; // x21
  _WORD *v35; // x10
  _BYTE *v36; // x8
  int v37; // w12
  int v38; // w9
  __int64 v39; // x20
  __int64 v40; // x10
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  bool v49; // [xsp+4h] [xbp-6Ch] BYREF
  _QWORD v50[11]; // [xsp+8h] [xbp-68h] BYREF
  int v51; // [xsp+60h] [xbp-10h]
  __int64 v52; // [xsp+68h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 24);
  v51 = 0;
  v12 = *(_QWORD *)(a1 + 128);
  v11 = *(_QWORD *)(a1 + 136);
  memset(v50, 0, sizeof(v50));
  v14 = *(_QWORD *)(v10 + 328);
  v13 = *(_QWORD *)(v10 + 336);
  v49 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_update_wiphy_eht_cap");
  result = ucfg_psoc_mlme_get_11be_capab(*(_QWORD *)a1, &v49);
  if ( v49 )
  {
    result = mlme_cfg_get_eht_caps(*(_QWORD *)a1, (__int64)v50);
    if ( !(_DWORD)result )
    {
      if ( v14 )
      {
        v24 = *(_WORD **)(a1 + 128);
        *v24 = 12;
        *(_WORD *)(v14 + 92) = 2;
        v25 = *(_QWORD *)(a1 + 128);
        v26 = LOBYTE(v50[0]) != 0;
        *(_QWORD *)(v14 + 96) = v25;
        *(_BYTE *)(v25 + 59) = v26;
        v27 = *(_QWORD *)(a1 + 128);
        if ( *(_BYTE *)(v27 + 59) == 1 && (*(_BYTE *)(v27 + 2) & 1) == 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: 2.4 GHz HE caps not present",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "hdd_update_wiphy_eht_cap");
          *(_BYTE *)(*(_QWORD *)(a1 + 128) + 59LL) = 0;
          *(_WORD *)(v14 + 92) = 1;
          if ( !v13 )
            goto LABEL_22;
LABEL_12:
          v29 = *(_WORD **)(a1 + 136);
          *v29 = 12;
          *(_WORD *)(v13 + 92) = 2;
          v30 = *(_QWORD *)(a1 + 136);
          v31 = LOBYTE(v50[0]) != 0;
          *(_QWORD *)(v13 + 96) = v30;
          *(_BYTE *)(v30 + 59) = v31;
          v32 = *(_QWORD *)(a1 + 136);
          if ( *(_BYTE *)(v32 + 59) == 1 && (*(_BYTE *)(v32 + 2) & 1) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: 5 GHz HE caps not present",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "hdd_update_wiphy_eht_cap");
            *(_BYTE *)(*(_QWORD *)(a1 + 136) + 59LL) = 0;
            *(_WORD *)(v13 + 92) = 1;
          }
          else
          {
            v33 = *(_DWORD *)((char *)v50 + 1);
            if ( (*(_DWORD *)((_BYTE *)v50 + 1) & 0x200000) != 0 )
              *(_BYTE *)(v11 + 62) |= 0x20u;
            if ( (v33 & 0x400000) != 0 )
              *(_BYTE *)(v11 + 62) |= 0x40u;
            qdf_mem_copy(v29 + 64, *(const void **)(a1 + 136), 0x68u);
            *v29 = 4;
            v29[64] = 8;
          }
LABEL_22:
          v34 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 352LL);
          if ( !v34 || (v35 = *(_WORD **)(a1 + 144), v36 = v35 + 31, v35 == (_WORD *)-62LL) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: 6ghz not supported in wiphy",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "hdd_update_wiphy_eht_caps_6ghz");
            goto LABEL_32;
          }
          v37 = LOBYTE(v50[0]);
          v38 = *(_DWORD *)((char *)v50 + 1);
          *v35 = 12;
          *(_WORD *)(v34 + 92) = 2;
          v39 = *(_QWORD *)(a1 + 144);
          *(_QWORD *)(v34 + 96) = v39;
          *(_BYTE *)(v39 + 59) = v37 != 0;
          v40 = *(_QWORD *)(a1 + 144);
          if ( *(_BYTE *)(v40 + 59) == 1 && (*(_BYTE *)(v40 + 2) & 1) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: 6 GHz HE caps not present",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "hdd_update_wiphy_eht_caps_6ghz");
            *(_BYTE *)(*(_QWORD *)(a1 + 144) + 59LL) = 0;
            *(_WORD *)(v34 + 92) = 1;
            goto LABEL_32;
          }
          if ( (v38 & 0x20000) != 0 )
          {
            *v36 |= 2u;
            if ( (v38 & 0x200000) == 0 )
            {
LABEL_28:
              if ( (v38 & 0x400000) == 0 )
              {
LABEL_30:
                qdf_mem_copy((void *)(v39 + 128), *(const void **)(a1 + 144), 0x68u);
                *(_WORD *)v39 = 4;
                *(_WORD *)(v39 + 128) = 8;
LABEL_32:
                result = qdf_trace_msg(
                           0x33u,
                           8u,
                           "%s: exit",
                           v41,
                           v42,
                           v43,
                           v44,
                           v45,
                           v46,
                           v47,
                           v48,
                           "hdd_update_wiphy_eht_cap");
                goto LABEL_33;
              }
LABEL_29:
              *v36 |= 0x40u;
              goto LABEL_30;
            }
          }
          else if ( (v38 & 0x200000) == 0 )
          {
            goto LABEL_28;
          }
          *v36 |= 0x20u;
          if ( (v38 & 0x400000) == 0 )
            goto LABEL_30;
          goto LABEL_29;
        }
        v28 = *(_DWORD *)((char *)v50 + 1);
        if ( (*(_DWORD *)((_BYTE *)v50 + 1) & 0x200000) != 0 )
          *(_BYTE *)(v12 + 62) |= 0x20u;
        if ( (v28 & 0x400000) != 0 )
          *(_BYTE *)(v12 + 62) |= 0x40u;
        qdf_mem_copy(v24 + 64, *(const void **)(a1 + 128), 0x68u);
        *v24 = 4;
        v24[64] = 8;
      }
      if ( !v13 )
        goto LABEL_22;
      goto LABEL_12;
    }
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
