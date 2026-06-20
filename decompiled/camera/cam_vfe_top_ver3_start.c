__int64 __fastcall cam_vfe_top_ver3_start(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x19
  unsigned int started; // w0
  __int64 v10; // x6
  const char *v11; // x5
  unsigned int v12; // w19
  __int64 v13; // x4
  const char *v14; // x5
  __int64 v15; // x4
  unsigned int v17; // w0
  __int64 (__fastcall *v18)(_QWORD); // x8

  if ( !a1 || !a2 )
  {
    v14 = "Error, Invalid input arguments";
    v15 = 537;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_start",
      v15,
      v14);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 10432) + 3296LL) )
  {
    v14 = "Error soc_private NULL";
    v15 = 545;
    goto LABEL_9;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 112LL);
  if ( *(_DWORD *)(v6 + 92) != 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_start",
      577,
      "VFE HW not powered up");
    return 0xFFFFFFFFLL;
  }
  started = cam_vfe_top_apply_clock_start_stop(a1 + 24, a2, a3, a4, a5, a6);
  if ( started )
  {
    v10 = *(unsigned int *)(v6 + 116);
    v11 = "VFE:%d Failed in applying start clock rc:%d";
    v12 = started;
    v13 = 557;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_start",
      v13,
      v11,
      v10,
      v12);
    return v12;
  }
  v17 = cam_vfe_top_apply_bw_start_stop(a1 + 24);
  if ( v17 )
  {
    v10 = *(unsigned int *)(v6 + 116);
    v11 = "VFE:%d Failed in applying start bw rc:%d";
    v12 = v17;
    v13 = 565;
    goto LABEL_15;
  }
  v18 = *(__int64 (__fastcall **)(_QWORD))(a2 + 88);
  if ( !v18 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_start",
      573,
      "Invalid res id:%d",
      *(_DWORD *)(a2 + 4));
    return 4294967274LL;
  }
  if ( *((_DWORD *)v18 - 1) != -260532613 )
    __break(0x8228u);
  return v18(a2);
}
