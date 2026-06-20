__int64 __fastcall cam_isp_add_csid_offline_cmd(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  int v4; // w6
  unsigned int v5; // w7
  unsigned int v6; // w6
  unsigned int v7; // w7
  __int64 v8; // x11
  __int64 v9; // x8
  __int64 (__fastcall *v11)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v12; // x0
  __int64 result; // x0
  int v17; // w3
  const char *v18; // x5
  __int64 v19; // x4
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  __int64 v21; // [xsp+8h] [xbp-18h]
  __int64 v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 40);
  v5 = *(_DWORD *)(a1 + 24);
  v21 = 0;
  if ( v4 + 1 >= v5 )
  {
    v18 = "Insufficient  HW entries :%d %d";
    v19 = 1978;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_csid_offline_cmd",
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
    v19 = 1992;
    goto LABEL_13;
  }
  v8 = *(_QWORD *)(a2 + 16);
  v9 = *(_QWORD *)(a3 + 8);
  LODWORD(v21) = v6 - v7;
  v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v8 + 88);
  v12 = *(_QWORD *)(v8 + 112);
  v22 = a2;
  v20 = v9 + (v7 & 0xFFFFFFFC);
  if ( *((_DWORD *)v11 - 1) != -1055839300 )
    __break(0x8229u);
  result = v11(v12, 51, &v20, 24);
  if ( !(_DWORD)result )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_add_csid_offline_cmd",
        2011,
        "offline cmd update added for CSID: %u res: %d",
        *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL),
        *(_DWORD *)(a2 + 4));
      v17 = HIDWORD(v21);
      if ( !HIDWORD(v21) )
        goto LABEL_10;
    }
    else
    {
      v17 = HIDWORD(v21);
      if ( !HIDWORD(v21) )
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
