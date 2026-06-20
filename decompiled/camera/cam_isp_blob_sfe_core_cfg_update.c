__int64 __fastcall cam_isp_blob_sfe_core_cfg_update(__int64 *a1, __int64 a2)
{
  __int64 v2; // x24
  unsigned __int64 v4; // x25
  _DWORD *v5; // x27
  __int64 v6; // x28
  unsigned int v7; // w23
  __int64 v8; // x6
  __int64 v9; // x2
  __int64 v10; // x4
  const char *v11; // x5
  __int64 v12; // x8
  __int64 *v13; // x8
  __int64 v14; // x9
  __int64 (__fastcall *v15)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x0
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v22; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 16);
  if ( *(_DWORD *)(v2 + 8716) )
  {
    v4 = 0;
    v5 = (_DWORD *)(v2 + 8592);
    v6 = *(_QWORD *)(v2 + 72) + 224LL;
    v7 = -22;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    while ( 1 )
    {
      if ( v4 == 11 )
LABEL_19:
        __break(0x5512u);
      if ( *v5 == 7 )
      {
        v12 = (unsigned int)*(v5 - 2);
        if ( (int)v12 <= 2 )
        {
          if ( (unsigned int)v12 > 2 )
            goto LABEL_19;
          v13 = *(__int64 **)(v6 + 8 * v12);
          if ( v13 )
          {
            v14 = *v13;
            if ( *v13 && (v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v14 + 88)) != nullptr )
            {
              v16 = a1[3];
              v17 = a1[4];
              v18 = *(_QWORD *)(v14 + 112);
              v25 = a1[2];
              v26 = v16;
              v20 = *a1;
              v19 = a1[1];
              v27 = v17;
              v23 = v20;
              v24 = v19;
              if ( *((_DWORD *)v15 - 1) != -1055839300 )
                __break(0x8228u);
              v7 = v15(v18, 25, &v22, 48);
              if ( !v7 )
                goto LABEL_5;
              v8 = *(unsigned int *)(v2 + 56);
              v9 = 1;
              v10 = 11176;
              v11 = "SFE core cfg parse fail, ctx_idx: %u";
            }
            else
            {
              v8 = *(unsigned int *)(v2 + 56);
              v9 = 2;
              v10 = 11178;
              v11 = "NULL hw_intf! ctx_idx: %u";
            }
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              v9,
              "cam_isp_blob_sfe_core_cfg_update",
              v10,
              v11,
              v8);
          }
        }
      }
LABEL_5:
      ++v4;
      v5 += 3;
      if ( v4 >= *(unsigned int *)(v2 + 8716) )
        goto LABEL_18;
    }
  }
  v7 = -22;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v7;
}
