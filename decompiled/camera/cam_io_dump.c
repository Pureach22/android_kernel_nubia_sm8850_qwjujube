__int64 __fastcall cam_io_dump(__int64 a1, unsigned int a2, int a3, __int64 a4, char a5)
{
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 result; // x0
  __int64 v12; // x25
  int v13; // w19
  char *v14; // x28
  unsigned int v15; // w20
  unsigned int v16; // w21
  int v17; // w0
  int v18; // w0
  int v19; // w0
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // [xsp+8h] [xbp-98h]
  char v26; // [xsp+18h] [xbp-88h] BYREF
  __int64 v27; // [xsp+19h] [xbp-87h]
  __int64 v28; // [xsp+21h] [xbp-7Fh]
  __int64 v29; // [xsp+29h] [xbp-77h]
  __int64 v30; // [xsp+31h] [xbp-6Fh]
  __int64 v31; // [xsp+39h] [xbp-67h]
  __int64 v32; // [xsp+41h] [xbp-5Fh]
  __int64 v33; // [xsp+49h] [xbp-57h]
  __int64 v34; // [xsp+51h] [xbp-4Fh]
  __int64 v35; // [xsp+59h] [xbp-47h]
  __int64 v36; // [xsp+61h] [xbp-3Fh]
  __int64 v37; // [xsp+69h] [xbp-37h]
  __int64 v38; // [xsp+71h] [xbp-2Fh]
  __int64 v39; // [xsp+79h] [xbp-27h]
  __int64 v40; // [xsp+81h] [xbp-1Fh]
  _BYTE v41[15]; // [xsp+89h] [xbp-17h] BYREF
  __int64 v42; // [xsp+98h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v41, 0, sizeof(v41));
  v40 = 0;
  v39 = 0;
  v38 = 0;
  v37 = 0;
  v36 = 0;
  v35 = 0;
  v34 = 0;
  v33 = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  if ( (a5 & 1) != 0 )
  {
    v9 = a4;
    v10 = 3;
  }
  else
  {
    v9 = debug_mdl & a4;
    if ( (debug_mdl & a4) == 0 || debug_priority )
      goto LABEL_6;
    v10 = 4;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
    3,
    v9,
    v10,
    "cam_io_dump",
    252,
    "addr=%pK offset=0x%x size=%d",
    a1,
    a2,
    a3);
LABEL_6:
  result = 4294967274LL;
  if ( !a1 || a3 < 1 )
    goto LABEL_27;
  v24 = a4;
  v12 = 0;
  v13 = 0;
  v14 = &v26;
  v15 = a2;
  v26 = 0;
  do
  {
    if ( (v12 & 3) != 0 )
    {
      v16 = a2;
    }
    else
    {
      v16 = v15 + 4 * v12;
      v17 = scnprintf(v14, 128LL - v13, "0x%08x: ", a2);
      v14 += v17;
      v13 += v17;
    }
    v18 = readl_relaxed((unsigned int *)(a1 + v16));
    v19 = scnprintf(v14, 128LL - v13, "%08x  ", v18);
    if ( (++v12 & 3) != 0 )
    {
      v14 += v19;
      v13 += v19;
      goto LABEL_10;
    }
    if ( (a5 & 1) != 0 )
    {
      v20 = v24;
      v21 = 3;
    }
    else
    {
      v20 = debug_mdl & v24;
      if ( (debug_mdl & v24) == 0 || debug_priority )
        goto LABEL_20;
      v21 = 4;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v20,
      v21,
      "cam_io_dump",
      274,
      "%s",
      &v26);
LABEL_20:
    v13 = 0;
    v14 = &v26;
    v26 = 0;
LABEL_10:
    a2 += 4;
  }
  while ( a3 != v12 );
  if ( !v26 )
    goto LABEL_26;
  if ( (a5 & 1) != 0 )
  {
    v22 = v24;
    v23 = 3;
    goto LABEL_25;
  }
  result = 0;
  v22 = debug_mdl & v24;
  if ( (debug_mdl & v24) != 0 && !debug_priority )
  {
    v23 = 4;
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
      3,
      v22,
      v23,
      "cam_io_dump",
      281,
      "%s",
      &v26);
LABEL_26:
    result = 0;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
