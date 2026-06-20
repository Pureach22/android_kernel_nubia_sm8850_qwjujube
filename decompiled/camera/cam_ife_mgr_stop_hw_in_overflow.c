__int64 __fastcall cam_ife_mgr_stop_hw_in_overflow(__int64 *a1)
{
  __int64 v1; // x19
  int v2; // w9
  unsigned int *v3; // x8
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  int v7; // w0
  int v8; // w2
  int v9; // w0
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x23
  __int64 v12; // x24
  _QWORD *i; // x20
  _QWORD *j; // x20
  __int64 v15; // x20
  unsigned __int64 v16; // x23

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_stop_hw_in_overflow",
      8319,
      "Invalid arguments");
    return 4294967274LL;
  }
  v1 = *a1;
  if ( !*a1 || (*(_BYTE *)(v1 + 9376) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_stop_hw_in_overflow",
      8324,
      "Invalid context is used");
    return 0xFFFFFFFFLL;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_stop_hw_in_overflow",
      8328,
      "Enter...ctx id:%u",
      *(_DWORD *)(v1 + 56));
    v2 = *(_DWORD *)(v1 + 8716);
    if ( v2 )
      goto LABEL_7;
    goto LABEL_40;
  }
  v2 = *(_DWORD *)(v1 + 8716);
  if ( !v2 )
  {
LABEL_40:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_stop_hw_in_overflow",
      8331,
      "Number of bases are zero, ctx_index %u",
      *(_DWORD *)(v1 + 56));
    return 4294967274LL;
  }
LABEL_7:
  v3 = (unsigned int *)(v1 + 8584);
  if ( !*(_DWORD *)(v1 + 8588) || v2 == 1 )
  {
LABEL_47:
    v6 = *v3;
    v7 = cam_cdm_reset_hw(*(_DWORD *)(v1 + 8720));
    if ( v7 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_ife_mgr_stop_hw_in_overflow",
        8349,
        "CDM: %u reset failed rc: %d in ctx: %u",
        *(_DWORD *)(v1 + 8744),
        v7,
        *(_DWORD *)(v1 + 56));
    if ( *(_DWORD *)(v1 + 8844) )
    {
      if ( (*(_BYTE *)(v1 + 9390) & 1) == 0 )
      {
        v8 = *(_DWORD *)(v1 + 9140);
        *(_BYTE *)(v1 + 9390) = 1;
        v9 = cam_ife_mgr_handle_reg_dump(v1, (unsigned int *)(v1 + 8900), v8, 15);
        if ( v9 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_stop_hw_in_overflow",
            8361,
            "Reg dump on error failed rc: %d in ctx: %u",
            v9,
            *(_DWORD *)(v1 + 56));
      }
    }
    cam_ife_mgr_csid_stop_hw(v1, (_QWORD *)(v1 + 208), v6, 2, 0, 0);
    v10 = *(unsigned int *)(v1 + 8716);
    if ( (_DWORD)v10 )
    {
      v11 = 0;
      v12 = 8584;
      while ( 1 )
      {
        if ( v6 != v11 )
        {
          if ( v11 > 0xA )
            goto LABEL_59;
          cam_ife_mgr_csid_stop_hw(v1, (_QWORD *)(v1 + 208), *(_DWORD *)(v1 + v12), 2, 0, 0);
          v10 = *(unsigned int *)(v1 + 8716);
        }
        ++v11;
        v12 += 12;
        if ( v11 >= v10 )
          goto LABEL_60;
      }
    }
    goto LABEL_60;
  }
  if ( !*(_DWORD *)(v1 + 8600) )
  {
    v5 = 8596;
LABEL_46:
    v3 = (unsigned int *)(v1 + v5);
    goto LABEL_47;
  }
  if ( v2 == 2 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8612) )
  {
    v5 = 8608;
    goto LABEL_46;
  }
  if ( v2 == 3 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8624) )
  {
    v5 = 8620;
    goto LABEL_46;
  }
  if ( v2 == 4 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8636) )
  {
    v5 = 8632;
    goto LABEL_46;
  }
  if ( v2 == 5 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8648) )
  {
    v5 = 8644;
    goto LABEL_46;
  }
  if ( v2 == 6 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8660) )
  {
    v5 = 8656;
    goto LABEL_46;
  }
  if ( v2 == 7 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8672) )
  {
    v5 = 8668;
    goto LABEL_46;
  }
  if ( v2 == 8 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8684) )
  {
    v5 = 8680;
    goto LABEL_46;
  }
  if ( v2 == 9 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8696) )
  {
    v5 = 8692;
    goto LABEL_46;
  }
  if ( v2 == 10 )
    goto LABEL_47;
  if ( !*(_DWORD *)(v1 + 8708) )
  {
    v5 = 8704;
    goto LABEL_46;
  }
  if ( v2 == 11 )
    goto LABEL_47;
LABEL_59:
  __break(0x5512u);
LABEL_60:
  for ( i = *(_QWORD **)(v1 + 224); i != (_QWORD *)(v1 + 224); i = (_QWORD *)*i )
    cam_ife_hw_mgr_stop_hw_res((__int64)i);
  for ( j = *(_QWORD **)(v1 + 256); j != (_QWORD *)(v1 + 256); j = (_QWORD *)*j )
    cam_ife_hw_mgr_stop_hw_res((__int64)j);
  if ( *(_DWORD *)(v1 + 8512) )
  {
    v15 = 0;
    v16 = 0;
    do
    {
      cam_ife_hw_mgr_stop_hw_res(*(_QWORD *)(v1 + 272) + v15);
      ++v16;
      v15 += 128;
    }
    while ( v16 < *(unsigned int *)(v1 + 8512) );
  }
  cam_tasklet_stop(*(_QWORD *)(v1 + 16));
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_stop_hw_in_overflow",
      8396,
      "Exit...ctx id:%u rc :%d",
      *(_DWORD *)(v1 + 56),
      0);
    return 0;
  }
  return result;
}
