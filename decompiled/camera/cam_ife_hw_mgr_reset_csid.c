__int64 __fastcall cam_ife_hw_mgr_reset_csid(__int64 a1, int a2)
{
  __int64 *v2; // x21
  __int64 *v3; // x22
  __int64 v4; // x23
  __int64 v7; // x8
  __int64 v8; // x27
  __int64 v9; // x9
  __int64 (__fastcall *v10)(__int64, __int64 *, __int64); // x9
  __int64 v11; // x0
  unsigned int v12; // w0
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x27
  __int64 v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64 *, __int64); // x9
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 result; // x0
  unsigned int v21; // w20
  __int64 v22; // [xsp+10h] [xbp-20h] BYREF
  __int64 v23; // [xsp+18h] [xbp-18h]
  _QWORD v24[2]; // [xsp+20h] [xbp-10h]

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (__int64 *)(a1 + 208);
  v2 = *(__int64 **)(a1 + 208);
  v24[0] = 0;
  if ( v2 != (__int64 *)(a1 + 208) )
  {
    v4 = *(_QWORD *)(a1 + 72);
    v22 = 0;
    v23 = 0;
    do
    {
      v7 = v2[4];
      if ( v7 )
      {
        v8 = *(_QWORD *)(v7 + 16);
        if ( *(_BYTE *)(v4 + 81882) != 1 )
          goto LABEL_9;
        v9 = *(unsigned int *)(v8 + 4);
        if ( (unsigned int)v9 > 7 )
          goto LABEL_22;
        if ( (*((_BYTE *)v24 + v9) & 1) == 0 )
        {
LABEL_9:
          v10 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v8 + 32);
          v11 = *(_QWORD *)(v8 + 112);
          LODWORD(v22) = a2;
          v23 = v7;
          if ( *((_DWORD *)v10 - 1) != 1989616049 )
            __break(0x8229u);
          v12 = v10(v11, &v22, 16);
          if ( v12 )
          {
LABEL_24:
            v21 = v12;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_reset_csid",
              1661,
              "RESET HW res failed: (ctx_idx: %u type:%d, id:%d)",
              *(_DWORD *)(a1 + 56),
              *((_DWORD *)v2 + 4),
              *((_DWORD *)v2 + 5));
            result = v21;
            goto LABEL_25;
          }
          v13 = *(unsigned int *)(v8 + 4);
          if ( (unsigned int)v13 > 7 )
            goto LABEL_22;
          *((_BYTE *)v24 + v13) = 1;
        }
      }
      v14 = v2[5];
      if ( v14 )
      {
        v15 = *(_QWORD *)(v14 + 16);
        if ( *(_BYTE *)(v4 + 81882) != 1 )
          goto LABEL_18;
        v16 = *(unsigned int *)(v15 + 4);
        if ( (unsigned int)v16 > 7 )
          goto LABEL_22;
        if ( (*((_BYTE *)v24 + v16) & 1) == 0 )
        {
LABEL_18:
          LODWORD(v22) = a2;
          v17 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v15 + 32);
          v18 = *(_QWORD *)(v15 + 112);
          v23 = v2[5];
          if ( *((_DWORD *)v17 - 1) != 1989616049 )
            __break(0x8229u);
          v12 = v17(v18, &v22, 16);
          if ( v12 )
            goto LABEL_24;
          v19 = *(unsigned int *)(v15 + 4);
          if ( (unsigned int)v19 > 7 )
          {
LABEL_22:
            __break(0x5512u);
            break;
          }
          *((_BYTE *)v24 + v19) = 1;
        }
      }
      v2 = (__int64 *)*v2;
    }
    while ( v2 != v3 );
  }
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
