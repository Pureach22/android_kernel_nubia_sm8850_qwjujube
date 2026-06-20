__int64 __fastcall check_gdsc_status(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w21
  __int64 v9; // x1
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x20
  const char *v13; // x19
  __int64 v14; // x22
  const char *v15; // x21
  __int64 v16; // x8
  __int64 v17; // x22
  unsigned int v18; // w20
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967274LL;
    goto LABEL_9;
  }
  result = 4294967274LL;
  if ( !a2 )
    goto LABEL_9;
  if ( !*(_QWORD *)(a1 + 336) )
    goto LABEL_9;
  v19[0] = 0;
  v7 = poll_gdsc_status(a1, a3);
  result = 0;
  if ( !v7 )
    goto LABEL_9;
  v8 = v7;
  regmap_read(*(_QWORD *)(a1 + 336), 0, (char *)v19 + 4);
  v10 = *(_QWORD *)(a1 + 352);
  if ( v10 )
  {
    v10 = regmap_read(v10, 0, v19);
    if ( a3 <= 1 )
    {
      v15 = check_gdsc_status_gdsc_states[a3];
      dev_warn(
        a2,
        "%s %s state (after %d us timeout): 0x%x, GDS_HW_CTRL: 0x%x. Re-polling.\n",
        *(const char **)(a1 + 8),
        v15,
        *(_DWORD *)(a1 + 508),
        HIDWORD(v19[0]),
        LODWORD(v19[0]));
      result = poll_gdsc_status(a1, a3);
      if ( (_DWORD)result )
      {
        v16 = *(_QWORD *)(a1 + 336);
        v17 = a1;
        v18 = result;
        regmap_read(v16, 0, (char *)v19 + 4);
        regmap_read(*(_QWORD *)(v17 + 352), 0, v19);
        dev_err(
          a2,
          "%s %s final state (after additional %d us timeout): 0x%x, GDS_HW_CTRL: 0x%x\n",
          *(const char **)(v17 + 8),
          v15,
          *(_DWORD *)(v17 + 508),
          HIDWORD(v19[0]),
          LODWORD(v19[0]));
        result = v18;
      }
      goto LABEL_9;
    }
  }
  else if ( a3 <= 1 )
  {
    v11 = a1;
    v12 = a2;
    v13 = check_gdsc_status_gdsc_states[a3];
    v14 = v11;
    dev_err(v12, "%s %s timed out: 0x%x\n", *(const char **)(v11 + 8), v13, HIDWORD(v19[0]));
    _udelay(*(unsigned int *)(v14 + 508));
    regmap_read(*(_QWORD *)(v14 + 336), 0, (char *)v19 + 4);
    dev_err(
      v12,
      "%s %s final state: 0x%x (%d us timeout)\n",
      *(const char **)(v14 + 8),
      v13,
      HIDWORD(v19[0]),
      *(_DWORD *)(v14 + 508));
    result = v8;
LABEL_9:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(1u);
  return poll_gdsc_status(v10, v9);
}
