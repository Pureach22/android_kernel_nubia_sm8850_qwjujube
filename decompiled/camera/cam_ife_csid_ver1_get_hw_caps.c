__int64 __fastcall cam_ife_csid_ver1_get_hw_caps(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x13
  __int64 v6; // x14
  int v7; // w7
  int v8; // w8
  int v9; // w10
  int v10; // w11
  int v11; // w12
  char v12; // w13

  if ( a1 && a2 )
  {
    result = 0;
    v4 = *(_QWORD *)(a1 + 3680);
    v5 = **(_QWORD **)(v4 + 16);
    v6 = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 3392LL);
    v7 = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 152LL);
    *(_DWORD *)a2 = v7;
    v8 = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 156LL);
    *(_DWORD *)(a2 + 4) = v8;
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 160LL);
    v9 = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 136LL);
    *(_DWORD *)(a2 + 12) = v9;
    v10 = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 140LL);
    *(_DWORD *)(a2 + 16) = v10;
    v11 = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 144LL);
    *(_DWORD *)(a2 + 20) = v11;
    *(_BYTE *)(a2 + 29) = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 196LL) != 0;
    *(_BYTE *)(a2 + 30) = *(_DWORD *)(*(_QWORD *)(v5 + 96) + 200LL) != 0;
    v12 = debug_mdl;
    *(_BYTE *)(a2 + 28) = *(_BYTE *)(v6 + 12);
    if ( (v12 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v12 & 8,
        4,
        "cam_ife_csid_ver1_get_hw_caps",
        309,
        "CSID:%d No rdis:%d, no pix:%d, major:%d minor:%d ver :%d",
        *(_DWORD *)(*(_QWORD *)v4 + 4LL),
        v7,
        v8,
        v9,
        v10,
        v11);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_get_hw_caps",
      282,
      "CSID: Invalid args");
    return 4294967274LL;
  }
  return result;
}
