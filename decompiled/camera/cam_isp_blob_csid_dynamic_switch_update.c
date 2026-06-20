__int64 __fastcall cam_isp_blob_csid_dynamic_switch_update(_DWORD *a1, _QWORD *a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  int v4; // w8
  int v5; // w7
  __int64 v7; // x23
  int v8; // w9
  int v9; // w10
  int v10; // w9
  unsigned __int64 v11; // x22
  _DWORD *v12; // x23
  __int64 v13; // x24
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 (__fastcall *v17)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v18; // x0
  unsigned int v19; // w25
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF
  __int64 v21; // [xsp+10h] [xbp-30h]
  __int64 v22; // [xsp+18h] [xbp-28h]
  __int64 v23; // [xsp+20h] [xbp-20h]
  __int64 v24; // [xsp+28h] [xbp-18h]
  __int64 v25; // [xsp+30h] [xbp-10h]
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[40];
  v3 = a2[2];
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v4 = *(unsigned __int8 *)(v2 + 4288);
  v5 = *(_DWORD *)(v3 + 56);
  v20 = 0;
  v21 = 0;
  if ( v4 == 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_csid_dynamic_switch_update",
      10811,
      "MUP is already updated for Req: %lld on ctx: %u",
      *(_QWORD *)(*a2 + 8LL),
      v5);
  }
  else
  {
    v7 = *(_QWORD *)(v3 + 72);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_isp_blob_csid_dynamic_switch_update",
      10817,
      "csid mup value=%u, ctx_idx: %u req id %lld",
      *a1,
      v5,
      *(_QWORD *)(*a2 + 8LL));
    *(_BYTE *)(v2 + 4288) = 1;
    v8 = *a1;
    BYTE4(v25) = 1;
    *(_DWORD *)(v2 + 4280) = v8;
    if ( *(_DWORD *)(v7 + 80972) >= 2u )
      *(_DWORD *)(v2 + 4280) = (*a1 & 1) == 0;
    if ( *(_DWORD *)(v2 + 8) == 1 )
    {
      v9 = *(unsigned __int8 *)(v3 + 9387);
      LODWORD(v20) = *a1;
      BYTE4(v20) = 1;
      if ( v9 == 1 )
      {
        v10 = a1[1];
        BYTE4(v21) = 1;
        LODWORD(v21) = v10;
      }
    }
    if ( *(_DWORD *)(v3 + 8716) )
    {
      v11 = 0;
      v12 = (_DWORD *)(v3 + 8592);
      v13 = *(_QWORD *)(v3 + 72) + 96LL;
      result = 4294967274LL;
      while ( v11 != 11 )
      {
        if ( !*v12 && !*(v12 - 1) )
        {
          v15 = (unsigned int)*(v12 - 2);
          if ( (unsigned int)v15 > 7 )
            break;
          v16 = *(_QWORD *)(v13 + 8 * v15);
          if ( v16 )
          {
            v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v16 + 88);
            if ( v17 )
            {
              v18 = *(_QWORD *)(v16 + 112);
              if ( *((_DWORD *)v17 - 1) != -1055839300 )
                __break(0x8228u);
              result = v17(v18, 54, &v20, 48);
              if ( (_DWORD)result )
              {
                v19 = result;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_isp_update_csid_mode_update_util",
                  10786,
                  "Dynamic switch update failed, ctx_idx: %u",
                  *(_DWORD *)(v3 + 56));
                result = v19;
              }
            }
          }
        }
        ++v11;
        v12 += 3;
        if ( v11 >= *(unsigned int *)(v3 + 8716) )
          goto LABEL_22;
      }
      __break(0x5512u);
    }
  }
  result = 4294967274LL;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
