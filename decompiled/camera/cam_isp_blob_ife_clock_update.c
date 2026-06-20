__int64 __fastcall cam_isp_blob_ife_clock_update(__int64 a1, __int64 a2)
{
  __int64 *v4; // x28
  char v5; // w26
  char v6; // w27
  unsigned int v7; // w24
  __int64 v8; // x8
  unsigned int v9; // w6
  __int64 v10; // x9
  __int64 v11; // x10
  unsigned __int64 v12; // x25
  unsigned __int64 *v13; // x14
  unsigned __int64 v14; // x11
  unsigned __int64 v15; // x12
  __int64 v16; // x13
  unsigned __int64 v17; // x15
  unsigned __int64 v18; // x16
  __int64 v19; // x9
  unsigned __int64 *v20; // x11
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // t1
  __int64 v23; // x21
  __int64 (__fastcall *v24)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x10
  unsigned __int64 *v29; // x14
  unsigned __int64 v30; // x11
  unsigned __int64 v31; // x12
  __int64 v32; // x13
  unsigned __int64 v33; // x15
  unsigned __int64 v34; // x16
  __int64 v35; // x9
  unsigned __int64 *v36; // x11
  unsigned __int64 v37; // x10
  unsigned __int64 v38; // t1
  __int64 (__fastcall *v39)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v40; // x0
  __int64 v42; // [xsp+18h] [xbp-28h]
  __int64 v43; // [xsp+20h] [xbp-20h] BYREF
  unsigned __int64 v44; // [xsp+28h] [xbp-18h]
  __int64 v45; // [xsp+30h] [xbp-10h]
  __int64 v46; // [xsp+38h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = 0;
  v43 = 0;
  if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000008,
      4,
      "cam_isp_blob_ife_clock_update",
      11201,
      "IFE clk update usage=%u left_clk= %lu right_clk=%lu ctx_idx: %u",
      *(_DWORD *)a1,
      *(_QWORD *)(a1 + 8),
      *(_QWORD *)(a1 + 16),
      *(_DWORD *)(a2 + 56));
  v4 = *(__int64 **)(a2 + 224);
  if ( v4 != (__int64 *)(a2 + 224) )
  {
    v5 = 0;
    v6 = 0;
    v7 = -22;
    v42 = a1 + 24;
    while ( 1 )
    {
      v8 = v4[4];
      if ( !v8 )
        goto LABEL_45;
      v9 = *((_DWORD *)v4 + 5);
      if ( !v9 || v9 == 8 )
      {
        if ( (v6 & 1) != 0 )
        {
          v6 = 1;
          goto LABEL_45;
        }
        v12 = *(_QWORD *)(a1 + 8);
        v6 = 1;
      }
      else
      {
        if ( v9 == 1 )
          goto LABEL_81;
        if ( v9 > 7 )
        {
          if ( v9 != 9 )
            goto LABEL_81;
LABEL_20:
          v12 = 0;
          goto LABEL_35;
        }
        v10 = *(unsigned int *)(a1 + 4);
        if ( !(_DWORD)v10 )
          goto LABEL_20;
        if ( (_DWORD)v10 == 1 )
        {
          v11 = 0;
          v12 = 0;
LABEL_31:
          v19 = v10 - v11;
          v20 = (unsigned __int64 *)(v42 + 8 * v11);
          do
          {
            v22 = *v20++;
            v21 = v22;
            if ( v22 > v12 )
              v12 = v21;
            --v19;
          }
          while ( v19 );
          goto LABEL_35;
        }
        v11 = (unsigned int)v10 & 0xFFFFFFFE;
        v13 = (unsigned __int64 *)(a1 + 32);
        v14 = 0;
        v15 = 0;
        v16 = v11;
        do
        {
          v17 = *(v13 - 1);
          v18 = *v13;
          v13 += 2;
          if ( v17 > v14 )
            v14 = v17;
          if ( v18 > v15 )
            v15 = v18;
          v16 -= 2;
        }
        while ( v16 );
        if ( v14 <= v15 )
          v12 = v15;
        else
          v12 = v14;
        if ( v11 != v10 )
          goto LABEL_31;
      }
LABEL_35:
      v23 = *(_QWORD *)(v8 + 16);
      if ( v23 && (v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v23 + 88)) != nullptr )
      {
        v43 = v4[4];
        if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x2000008,
            4,
            "cam_isp_blob_ife_clock_update",
            11248,
            "Update Clock value res_id=%u i= %d clk=%llu ctx_idx: %u",
            v9,
            0,
            v12,
            *(_DWORD *)(a2 + 56));
          v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v23 + 88);
        }
        v25 = *(_QWORD *)(v23 + 112);
        v44 = v12;
        if ( *((_DWORD *)v24 - 1) != -1055839300 )
          __break(0x8229u);
        v7 = v24(v25, 9, &v43, 24);
        if ( v7 )
        {
LABEL_84:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            1,
            "cam_isp_blob_ife_clock_update",
            11265,
            "IFE:%d Clock Update failed clk_rate:%llu rc:%d ctx_idx: %u",
            *(_DWORD *)(v23 + 4),
            v12,
            v7,
            *(_DWORD *)(a2 + 56));
          goto LABEL_83;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_isp_blob_ife_clock_update",
          11269,
          "NULL hw_intf! ctx_idx: %u",
          *(_DWORD *)(a2 + 56));
      }
LABEL_45:
      v26 = v4[5];
      if ( !v26 )
        goto LABEL_7;
      v9 = *((_DWORD *)v4 + 5);
      if ( !v9 || v9 == 8 )
      {
        if ( (v5 & 1) != 0 )
        {
          v5 = 1;
          goto LABEL_7;
        }
        v12 = *(_QWORD *)(a1 + 16);
        v5 = 1;
        goto LABEL_72;
      }
      if ( v9 == 1 )
        goto LABEL_81;
      if ( v9 >= 8 )
      {
        if ( v9 != 9 )
        {
LABEL_81:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_ife_clock_update",
            11237,
            "Invalid res_id %u, ctx_idx: %u",
            v9,
            *(_DWORD *)(a2 + 56));
          break;
        }
LABEL_57:
        v12 = 0;
        goto LABEL_72;
      }
      v27 = *(unsigned int *)(a1 + 4);
      if ( !(_DWORD)v27 )
        goto LABEL_57;
      if ( (_DWORD)v27 == 1 )
      {
        v28 = 0;
        v12 = 0;
LABEL_68:
        v35 = v27 - v28;
        v36 = (unsigned __int64 *)(v42 + 8 * v28);
        do
        {
          v38 = *v36++;
          v37 = v38;
          if ( v38 > v12 )
            v12 = v37;
          --v35;
        }
        while ( v35 );
        goto LABEL_72;
      }
      v28 = (unsigned int)v27 & 0xFFFFFFFE;
      v29 = (unsigned __int64 *)(a1 + 32);
      v30 = 0;
      v31 = 0;
      v32 = v28;
      do
      {
        v33 = *(v29 - 1);
        v34 = *v29;
        v29 += 2;
        if ( v33 > v30 )
          v30 = v33;
        if ( v34 > v31 )
          v31 = v34;
        v32 -= 2;
      }
      while ( v32 );
      if ( v30 <= v31 )
        v12 = v31;
      else
        v12 = v30;
      if ( v28 != v27 )
        goto LABEL_68;
LABEL_72:
      v23 = *(_QWORD *)(v26 + 16);
      if ( v23 && (v39 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v23 + 88)) != nullptr )
      {
        v43 = v4[5];
        if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x2000008,
            4,
            "cam_isp_blob_ife_clock_update",
            11248,
            "Update Clock value res_id=%u i= %d clk=%llu ctx_idx: %u",
            v9,
            1,
            v12,
            *(_DWORD *)(a2 + 56));
          v39 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v23 + 88);
        }
        v40 = *(_QWORD *)(v23 + 112);
        v44 = v12;
        if ( *((_DWORD *)v39 - 1) != -1055839300 )
          __break(0x8229u);
        v7 = v39(v40, 9, &v43, 24);
        if ( v7 )
          goto LABEL_84;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_isp_blob_ife_clock_update",
          11269,
          "NULL hw_intf! ctx_idx: %u",
          *(_DWORD *)(a2 + 56));
      }
LABEL_7:
      v4 = (__int64 *)*v4;
      if ( v4 == (__int64 *)(a2 + 224) )
        goto LABEL_83;
    }
  }
  v7 = -22;
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return v7;
}
