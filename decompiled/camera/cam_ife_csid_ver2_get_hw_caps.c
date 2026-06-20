__int64 __fastcall cam_ife_csid_ver2_get_hw_caps(__int64 a1, __int64 a2)
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
  char v12; // w15
  char v13; // w13

  if ( a1 && a2 )
  {
    result = 0;
    v4 = *(_QWORD *)(a1 + 3680);
    v5 = **(_QWORD **)(v4 + 31136);
    v6 = *(_QWORD *)(*(_QWORD *)(v4 + 31128) + 3392LL);
    v7 = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 500LL);
    *(_DWORD *)a2 = v7;
    v8 = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 504LL);
    *(_DWORD *)(a2 + 4) = v8;
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 508LL);
    v9 = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 484LL);
    *(_DWORD *)(a2 + 12) = v9;
    v10 = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 488LL);
    *(_DWORD *)(a2 + 16) = v10;
    v11 = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 492LL);
    *(_DWORD *)(a2 + 20) = v11;
    *(_BYTE *)(a2 + 29) = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 572LL) != 0;
    *(_BYTE *)(a2 + 30) = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 576LL) != 0;
    *(_BYTE *)(a2 + 31) = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 580LL) != 0;
    *(_BYTE *)(a2 + 28) = *(_BYTE *)(v6 + 12);
    *(_DWORD *)(a2 + 24) = *(_DWORD *)(*(_QWORD *)(v5 + 120) + 584LL);
    *(_BYTE *)(a2 + 32) = *(_BYTE *)(*(_QWORD *)(v5 + 120) + 597LL);
    v12 = *(_BYTE *)(v5 + 664);
    v13 = debug_mdl;
    *(_BYTE *)(a2 + 33) = v12;
    if ( (v13 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v13 & 8,
        4,
        "cam_ife_csid_ver2_get_hw_caps",
        3811,
        "CSID:%u num-rdis:%d, num-pix:%d, major:%d minor:%d ver:%d",
        *(_DWORD *)(*(_QWORD *)(v4 + 31120) + 4LL),
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
      "cam_ife_csid_ver2_get_hw_caps",
      3780,
      "CSID: Invalid args");
    return 4294967274LL;
  }
  return result;
}
