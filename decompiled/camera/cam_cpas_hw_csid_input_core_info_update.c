__int64 __fastcall cam_cpas_hw_csid_input_core_info_update(__int64 a1, int a2, int a3, char a4)
{
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 result; // x0
  __int64 string_index; // x0
  __int64 v10; // x1
  __int64 v11; // x8
  __int64 v12; // x9
  int v13; // w12
  __int64 v14; // x13
  int v15; // w15
  __int64 v16; // x14
  __int64 v17; // x14
  unsigned int v18; // [xsp+Ch] [xbp-94h] BYREF
  char s[8]; // [xsp+10h] [xbp-90h] BYREF
  __int64 v20; // [xsp+18h] [xbp-88h]
  __int64 v21; // [xsp+20h] [xbp-80h]
  __int64 v22; // [xsp+28h] [xbp-78h]
  __int64 v23; // [xsp+30h] [xbp-70h]
  __int64 v24; // [xsp+38h] [xbp-68h]
  __int64 v25; // [xsp+40h] [xbp-60h]
  __int64 v26; // [xsp+48h] [xbp-58h]
  __int64 v27; // [xsp+50h] [xbp-50h]
  __int64 v28; // [xsp+58h] [xbp-48h]
  __int64 v29; // [xsp+60h] [xbp-40h]
  __int64 v30; // [xsp+68h] [xbp-38h]
  __int64 v31; // [xsp+70h] [xbp-30h]
  __int64 v32; // [xsp+78h] [xbp-28h]
  __int64 v33; // [xsp+80h] [xbp-20h]
  _QWORD v34[3]; // [xsp+88h] [xbp-18h]

  v34[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 3392);
  v18 = -1;
  if ( *(_BYTE *)(v4 + 1609) != 1 )
    goto LABEL_3;
  v5 = *(_QWORD *)(a1 + 3680);
  if ( (*(_BYTE *)(v5 + 159432) & 1) != 0 )
    goto LABEL_3;
  *(_DWORD *)((char *)v34 + 7) = 0;
  v33 = 0;
  v34[0] = 0;
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
  *(_QWORD *)s = 0;
  v20 = 0;
  if ( (a3 | a2) < 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_csid_input_core_info_update",
      4576,
      "Invalid core info csid:%d sfe:%d",
      a2,
      a3);
    result = 4294967274LL;
    goto LABEL_4;
  }
  snprintf(s, 0x83u, "%s%d", "sfe", a3);
  string_index = cam_common_util_get_string_index(v4 + 16, *(_DWORD *)(v4 + 12), s, (int *)&v18);
  if ( (_DWORD)string_index )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_csid_input_core_info_update",
      4585,
      "Failed in getting correct client index");
    result = 4294967274LL;
    goto LABEL_4;
  }
  v11 = v18;
  if ( v18 < 0x2B )
  {
    v12 = v5 + 320;
    if ( *(_BYTE *)(*(_QWORD *)(v5 + 320 + 8LL * v18) + 171LL) != 1 )
    {
LABEL_3:
      result = 0;
LABEL_4:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( (a4 & 1) != 0 )
      v13 = a2 + 1;
    else
      v13 = 32;
    v14 = 1048;
    while ( 1 )
    {
      v17 = *(_QWORD *)(*(_QWORD *)(v12 + 8 * v11) + v14 - 8);
      if ( v17 )
        break;
      v15 = v13;
      v16 = *(_QWORD *)(*(_QWORD *)(v12 + 8 * v11) + v14);
      if ( v16 )
        goto LABEL_16;
LABEL_17:
      v14 += 16;
      result = 0;
      if ( v14 == 1720 )
        goto LABEL_4;
    }
    if ( (a4 & 1) != 0 )
    {
      *(_DWORD *)(v17 + 16) = a2 + 1;
      v15 = a2 + 1;
    }
    else
    {
      v15 = 32;
      *(_DWORD *)(v17 + 16) = 32;
    }
    v16 = *(_QWORD *)(*(_QWORD *)(v12 + 8 * v11) + v14);
    if ( !v16 )
      goto LABEL_17;
LABEL_16:
    *(_DWORD *)(v16 + 16) = v15;
    goto LABEL_17;
  }
  __break(0x5512u);
  return cam_cpas_hw_csid_process_resume(string_index, v10);
}
