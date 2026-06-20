__int64 __fastcall cam_ife_csid_halt(_QWORD *a1, __int64 a2)
{
  _DWORD *v2; // x19
  __int64 v3; // x7
  __int64 v4; // x8
  __int64 *v5; // x8
  __int64 v6; // x24
  _QWORD *v7; // x22
  _DWORD *v8; // x25
  __int64 v9; // x19
  int v10; // w0
  __int64 v11; // x9
  unsigned int v12; // w19
  unsigned int v13; // w8
  const char *v14; // x3
  const char *v15; // x5
  __int64 v16; // x6
  __int64 v17; // x4
  __int64 v19; // x22
  _QWORD *v20; // x23
  int v21; // [xsp+0h] [xbp-10h]

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_halt",
      3187,
      "CSID: Invalid args");
    return (unsigned int)-22;
  }
  v2 = *(_DWORD **)(a2 + 8);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v19 = a2;
    v20 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_halt",
      3197,
      "CSID:%d res_type %d res_id %d",
      *(_DWORD *)(*a1 + 4LL),
      *v2,
      v2[1]);
    a2 = v19;
    a1 = v20;
  }
  if ( *v2 != 3 )
  {
    v14 = "cam_ife_csid_halt";
    v15 = "CSID:%d Invalid res type %d";
    v16 = *(unsigned int *)(*a1 + 4LL);
    v17 = 3202;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      v14,
      v17,
      v15,
      v16);
    return (unsigned int)-22;
  }
  v3 = (unsigned int)v2[1];
  if ( (_DWORD)v3 == 5 )
  {
    v4 = *(_QWORD *)(a2 + 8);
    if ( *(_DWORD *)(v4 + 4) == 5 )
    {
      if ( *(_DWORD *)(v4 + 8) == 4 )
      {
        v6 = a1[1];
        v5 = (__int64 *)a1[2];
        v7 = a1;
        v8 = (_DWORD *)a2;
        v9 = *v5;
        cam_io_w_mb(0, *(_QWORD *)(v6 + 384) + *(unsigned int *)(*(_QWORD *)(*v5 + 8) + 4LL));
        v10 = cam_io_r_mb(*(_QWORD *)(v6 + 384) + *(unsigned int *)(*(_QWORD *)(v9 + 8) + 24LL));
        v11 = *(_QWORD *)(v9 + 8);
        v12 = v10 & 0xFFFFFFF3 | (4 * *v8);
        cam_io_w_mb(v12, *(_QWORD *)(v6 + 384) + *(unsigned int *)(v11 + 24));
        v13 = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_change_pxl_halt_mode",
            3174,
            "CSID:%d IPP path Res halt mode:%d configured:%x",
            *(unsigned int *)(*v7 + 4LL),
            (unsigned int)*v8,
            v12);
          return 0;
        }
        return v13;
      }
      v14 = "cam_ife_csid_change_pxl_halt_mode";
      v15 = "CSID:%d Res:%d in invalid state:%d";
      v16 = *(unsigned int *)(*a1 + 4LL);
      v17 = 3158;
    }
    else
    {
      v14 = "cam_ife_csid_change_pxl_halt_mode";
      v15 = "CSID:%d Invalid res id %d";
      v16 = *(unsigned int *)(*a1 + 4LL);
      v17 = 3152;
    }
    goto LABEL_15;
  }
  v13 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_halt",
      3213,
      "CSID:%d res_id %d",
      *(unsigned int *)(*a1 + 4LL),
      v3,
      v21);
    return 0;
  }
  return v13;
}
