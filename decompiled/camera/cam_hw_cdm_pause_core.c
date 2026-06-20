__int64 __fastcall cam_hw_cdm_pause_core(__int64 a1, unsigned __int8 a2)
{
  unsigned int *v4; // x22
  unsigned int **v5; // x8
  unsigned int *v6; // x9
  unsigned int *v7; // x8
  unsigned int v8; // w9
  char v9; // w23
  unsigned int v10; // w21
  unsigned int v11; // w20
  __int64 v12; // x6
  const char *v13; // x5
  __int64 v14; // x2
  __int64 v15; // x4
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int **)(a1 + 3680);
  v17[0] = 0;
  v5 = *((unsigned int ***)v4 + 29);
  v6 = v5[9];
  v7 = *v5;
  v8 = v6[4];
  v9 = v8 & a2;
  if ( ((unsigned __int8)v8 & a2 & 1) != 0 )
  {
    v10 = v7[71] | 1;
  }
  else
  {
    v10 = 1;
    if ( (v8 & 1) == 0 )
      goto LABEL_8;
  }
  cam_cdm_read_hw_reg(a1, v7[7], (int *)v17 + 1);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**((_QWORD **)v4 + 29) + 36LL), (int *)v17);
  v7 = **((unsigned int ***)v4 + 29);
  if ( (v7[71] & HIDWORD(v17[0])) != 0 && (v7[70] & v17[0]) == 0 && (a2 & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_pause_core",
      195,
      "Pause core not done yet, can't resume core");
    v11 = -11;
    goto LABEL_17;
  }
LABEL_8:
  if ( cam_cdm_write_hw_reg(a1, v7[7], v10) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_pause_core",
      205,
      "Failed to Write core_en for %s%u",
      *(const char **)(a1 + 152),
      *(_DWORD *)(a1 + 116));
    v11 = -5;
    if ( (v9 & 1) == 0 )
      goto LABEL_17;
  }
  else
  {
    v11 = 0;
    if ( (v9 & 1) == 0 )
      goto LABEL_17;
  }
  if ( (unsigned int)cam_common_read_poll_timeout(
                       (const void *)(*(_QWORD *)(a1 + 384) + *(unsigned int *)(**((_QWORD **)v4 + 29) + 36LL)),
                       0,
                       10000,
                       *(_DWORD *)(**((_QWORD **)v4 + 29) + 280LL),
                       *(_DWORD *)(**((_QWORD **)v4 + 29) + 280LL),
                       v17) )
  {
    v12 = LODWORD(v17[0]);
    v13 = "Pause core operation not successful: status=0x%08x";
    v14 = 2;
    v15 = 219;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      1,
      v14,
      "cam_hw_cdm_pause_core",
      v15,
      v13,
      v12);
    goto LABEL_17;
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v12 = *v4;
    v13 = "Pause core CDM[%u] successful";
    v14 = 4;
    v15 = 221;
    goto LABEL_14;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v11;
}
