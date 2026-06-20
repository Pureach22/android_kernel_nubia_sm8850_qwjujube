__int64 __fastcall cam_isp_blob_sfe_clock_update(__int64 a1, __int64 a2)
{
  __int64 *v4; // x23
  int v5; // w27
  unsigned int v6; // w25
  __int64 v7; // x7
  char v8; // w9
  __int64 v9; // x6
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x4
  const char *v13; // x5
  __int64 v14; // x8
  char v15; // w22
  int v16; // w6
  __int64 v17; // x9
  __int64 v18; // x10
  unsigned __int64 v19; // x24
  unsigned __int64 *v20; // x10
  int v21; // w9
  __int64 v22; // x26
  unsigned __int64 *v23; // x14
  unsigned __int64 v24; // x11
  unsigned __int64 v25; // x12
  __int64 v26; // x13
  unsigned __int64 v27; // x15
  unsigned __int64 v28; // x16
  __int64 v29; // x9
  unsigned __int64 *v30; // x11
  unsigned __int64 v31; // x10
  unsigned __int64 v32; // t1
  __int64 (__fastcall *v33)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v34; // x0
  char v36; // [xsp+3Ch] [xbp-24h]
  __int64 v37; // [xsp+40h] [xbp-20h] BYREF
  unsigned __int64 v38; // [xsp+48h] [xbp-18h]
  __int64 v39; // [xsp+50h] [xbp-10h]
  __int64 v40; // [xsp+58h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v37 = 0;
  if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000008,
      4,
      "cam_isp_blob_sfe_clock_update",
      11295,
      "SFE clk update usage: %u left_clk: %lu right_clk: %lu ctx_idx: %u",
      *(_DWORD *)a1,
      *(_QWORD *)(a1 + 8),
      *(_QWORD *)(a1 + 16),
      *(_DWORD *)(a2 + 56));
  v4 = *(__int64 **)(a2 + 240);
  if ( v4 != (__int64 *)(a2 + 240) )
  {
    v5 = 0;
    v36 = 0;
    v6 = -22;
    while ( 1 )
    {
      v7 = 0;
      v8 = 1;
      while ( 1 )
      {
        v14 = v4[v7 + 4];
        v15 = v8;
        if ( !v14 )
          goto LABEL_11;
        v16 = *((_DWORD *)v4 + 5);
        if ( !v16 )
          break;
        v17 = *(unsigned int *)(a1 + 4);
        if ( !(_DWORD)v17 )
        {
          v19 = 0;
          v22 = *(_QWORD *)(v14 + 16);
          if ( !v22 )
            goto LABEL_9;
          goto LABEL_41;
        }
        if ( (_DWORD)v17 == 1 )
        {
          v18 = 0;
          v19 = 0;
LABEL_32:
          v29 = v17 - v18;
          v30 = (unsigned __int64 *)(a1 + 24 + 8 * v18);
          do
          {
            v32 = *v30++;
            v31 = v32;
            if ( v32 > v19 )
              v19 = v31;
            --v29;
          }
          while ( v29 );
          goto LABEL_36;
        }
        v18 = (unsigned int)v17 & 0xFFFFFFFE;
        v23 = (unsigned __int64 *)(a1 + 32);
        v24 = 0;
        v25 = 0;
        v26 = v18;
        do
        {
          v27 = *(v23 - 1);
          v28 = *v23;
          v23 += 2;
          if ( v27 > v24 )
            v24 = v27;
          if ( v28 > v25 )
            v25 = v28;
          v26 -= 2;
        }
        while ( v26 );
        if ( v24 <= v25 )
          v19 = v25;
        else
          v19 = v24;
        if ( v18 != v17 )
          goto LABEL_32;
LABEL_36:
        v22 = *(_QWORD *)(v14 + 16);
        if ( !v22 )
          goto LABEL_9;
LABEL_41:
        v33 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v22 + 88);
        if ( v33 )
        {
          v37 = v4[v7 + 4];
          if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x2000008,
              4,
              "cam_isp_blob_sfe_clock_update",
              11331,
              "SFE res_id: %u i: %d clk: %llu ctx_idx: %u",
              v16,
              v7,
              v19,
              *(_DWORD *)(a2 + 56));
            v33 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v22 + 88);
          }
          v34 = *(_QWORD *)(v22 + 112);
          v38 = v19;
          if ( *((_DWORD *)v33 - 1) != -1055839300 )
            __break(0x8229u);
          v6 = v33(v34, 9, &v37, 24);
          if ( !v6 )
            goto LABEL_11;
          v9 = *(unsigned int *)(a2 + 56);
          v10 = 0x2000000;
          v11 = 1;
          v12 = 11347;
          v13 = "SFE clock update failed, ctx_idx: %u";
          goto LABEL_10;
        }
LABEL_9:
        v9 = *(unsigned int *)(a2 + 56);
        v10 = 8;
        v11 = 2;
        v12 = 11349;
        v13 = "NULL hw_intf! ctx_idx: %u";
LABEL_10:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          v10,
          v11,
          "cam_isp_blob_sfe_clock_update",
          v12,
          v13,
          v9);
LABEL_11:
        v8 = 0;
        v7 = 1;
        if ( (v15 & 1) == 0 )
          goto LABEL_7;
      }
      if ( (v8 & 1) != 0 )
      {
        v20 = (unsigned __int64 *)(a1 + 8);
        v21 = 1;
        if ( (v5 & 1) != 0 )
        {
          v5 = 1;
          goto LABEL_11;
        }
LABEL_40:
        v19 = *v20;
        v5 = v21;
        v22 = *(_QWORD *)(v14 + 16);
        if ( !v22 )
          goto LABEL_9;
        goto LABEL_41;
      }
      if ( (v36 & 1) == 0 )
      {
        v20 = (unsigned __int64 *)(a1 + 16);
        v36 = 1;
        v21 = v5;
        goto LABEL_40;
      }
      v36 = 1;
LABEL_7:
      v4 = (__int64 *)*v4;
      if ( v4 == (__int64 *)(a2 + 240) )
        goto LABEL_50;
    }
  }
  v6 = -22;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return v6;
}
