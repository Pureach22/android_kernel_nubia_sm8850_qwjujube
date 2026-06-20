__int64 __fastcall cam_ife_csid_ver2_irq_comp_cfg(__int64 a1, __int64 a2, int a3)
{
  _DWORD *v3; // x21
  int *v4; // x9
  int v6; // w26
  int v7; // w27
  __int64 v8; // x23
  int v10; // w24
  int v11; // w25
  unsigned int (__fastcall *v12)(_QWORD); // x8
  unsigned __int64 v13; // x20
  __int64 result; // x0
  __int64 v16; // x0
  _DWORD *v17; // x9
  _DWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 == 56 )
  {
    v3 = *(_DWORD **)(**(_QWORD **)(a1 + 31136) + 240LL);
    if ( v3 )
    {
      v4 = *(int **)(a2 + 40);
      v6 = v3[1];
      v7 = v3[2];
      v8 = *(_QWORD *)(*(_QWORD *)a2 + 48LL);
      v10 = *v4;
      v11 = v4[1];
      v12 = *(unsigned int (__fastcall **)(_QWORD))(v8 + 24);
      if ( *((_DWORD *)v12 - 1) != 2010610996 )
        __break(0x8228u);
      v13 = 4LL * v12(1);
      if ( v13 <= *(unsigned int *)(a2 + 24) )
      {
        v16 = *(_QWORD *)(a2 + 16);
        v17 = *(_DWORD **)(v8 + 120);
        v18[0] = *v3;
        v18[1] = (v11 << v7) | (v10 << v6);
        if ( *(v17 - 1) != -1401492769 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, _DWORD *))v17)(v16, 1, v18);
        result = 0;
        *(_DWORD *)(a2 + 28) = v13;
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_irq_comp_cfg",
          9032,
          "CSID:%u buf size:%d is not sufficient, expected: %d",
          *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
        result = 4294967274LL;
      }
    }
    else
    {
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver2_irq_comp_cfg",
          9020,
          "No multi-context support in CSID[%u]",
          *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
        result = 0;
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_irq_comp_cfg",
      9005,
      "CSID %u Invalid args size expected: %zu actual: %zu",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      0x38u,
      a3);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
