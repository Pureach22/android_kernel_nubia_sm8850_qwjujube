__int64 __fastcall cam_isp_add_go_cmd(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  int v4; // w6
  unsigned int v5; // w7
  unsigned int v6; // w6
  unsigned int v7; // w7
  __int64 v8; // x9
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 (__fastcall *v12)(__int64, __int64, __int64 *, __int64); // x9
  __int64 result; // x0
  int v17; // w3
  const char *v18; // x5
  __int64 v19; // x4
  __int64 v20; // [xsp+0h] [xbp-40h] BYREF
  __int64 v21; // [xsp+8h] [xbp-38h]
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 v23; // [xsp+18h] [xbp-28h]
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  __int64 v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 40);
  v5 = *(_DWORD *)(a1 + 24);
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  if ( v4 + 1 >= v5 )
  {
    v18 = "Insufficient  HW entries :%d %d";
    v19 = 1433;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_go_cmd",
      v19,
      v18);
    result = 4294967274LL;
    goto LABEL_14;
  }
  v6 = *(_DWORD *)(a3 + 20);
  v7 = *(_DWORD *)(a3 + 24);
  if ( v6 <= v7 )
  {
    v18 = "no free mem %d %d";
    v19 = 1447;
    goto LABEL_13;
  }
  v8 = *(_QWORD *)(a3 + 8);
  LODWORD(v23) = v6 - v7;
  v10 = *(_QWORD *)(a2 + 24);
  v11 = v8 + (v7 & 0xFFFFFFFC);
  v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(a2 + 104);
  v20 = a2;
  LODWORD(v21) = 34;
  v22 = v11;
  if ( *((_DWORD *)v12 - 1) != -1380041226 )
    __break(0x8229u);
  result = v12(v10, 34, &v20, 56);
  if ( !(_DWORD)result )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_add_go_cmd",
        1465,
        "GO_CMD added for RD res %d hw_id %d",
        *(_DWORD *)a2,
        *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL));
      v17 = HIDWORD(v23);
      if ( !HIDWORD(v23) )
        goto LABEL_10;
    }
    else
    {
      v17 = HIDWORD(v23);
      if ( !HIDWORD(v23) )
      {
LABEL_10:
        result = 0;
        goto LABEL_14;
      }
    }
    cam_isp_update_hw_entry(1, a1, a3, v17, a4 & 1);
    goto LABEL_10;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
