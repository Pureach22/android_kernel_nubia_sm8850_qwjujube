__int64 __fastcall cam_io_print_info(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x9
  __int64 v4; // x20
  unsigned int v5; // w25
  int *v6; // x8
  unsigned __int64 v7; // x22
  int v8; // w26
  unsigned __int64 v9; // x23
  const char *v10; // x9
  char *v11; // x27
  int v12; // w0
  int v13; // w0
  int v14; // w0
  __int64 result; // x0
  int v16; // [xsp+10h] [xbp-A0h]
  int v17; // [xsp+14h] [xbp-9Ch]
  const char *v18; // [xsp+18h] [xbp-98h]
  char v19; // [xsp+20h] [xbp-90h] BYREF
  __int64 v20; // [xsp+21h] [xbp-8Fh]
  __int64 v21; // [xsp+29h] [xbp-87h]
  __int64 v22; // [xsp+31h] [xbp-7Fh]
  __int64 v23; // [xsp+39h] [xbp-77h]
  __int64 v24; // [xsp+41h] [xbp-6Fh]
  __int64 v25; // [xsp+49h] [xbp-67h]
  __int64 v26; // [xsp+51h] [xbp-5Fh]
  __int64 v27; // [xsp+59h] [xbp-57h]
  __int64 v28; // [xsp+61h] [xbp-4Fh]
  __int64 v29; // [xsp+69h] [xbp-47h]
  __int64 v30; // [xsp+71h] [xbp-3Fh]
  __int64 v31; // [xsp+79h] [xbp-37h]
  __int64 v32; // [xsp+81h] [xbp-2Fh]
  __int64 v33; // [xsp+89h] [xbp-27h]
  _BYTE v34[15]; // [xsp+91h] [xbp-1Fh] BYREF
  __int64 v35; // [xsp+A0h] [xbp-10h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned int *)(a1 + 28);
  memset(v34, 0, sizeof(v34));
  v33 = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  v26 = 0;
  v25 = 0;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  if ( (unsigned int)v1 >= 8 )
    __break(0x5512u);
  v3 = *(_QWORD *)a1 + 24LL * (unsigned int)v1;
  v4 = *(_QWORD *)(v3 + 288);
  if ( v4 && *(_DWORD *)(a1 + 20) )
  {
    v5 = *(_DWORD *)(a1 + 16);
    v6 = *(int **)(*(_QWORD *)a1 + 8 * v1 + 224);
    v7 = 0;
    v8 = 0;
    v9 = v4 + *(_QWORD *)(v3 + 304);
    if ( *(_QWORD *)(a1 + 8) )
      v10 = *(const char **)(a1 + 8);
    else
      v10 = (const char *)&unk_3E455A;
    v11 = &v19;
    v18 = v10;
    v16 = *(_DWORD *)(a1 + 16);
    v17 = *v6;
    v19 = 0;
    do
    {
      if ( v4 + (unsigned __int64)v5 >= v9 )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          *(unsigned int *)(a1 + 24),
          3,
          "cam_io_print_info",
          320,
          "Invalid size start:0x%x base: 0x%X end: 0x%x i:%d",
          v16,
          v4,
          v9,
          v7);
        result = 4294967274LL;
        goto LABEL_20;
      }
      if ( (v7 & 3) == 0 )
      {
        v12 = scnprintf(v11, 128LL - v8, "0x%x: ", v17 + v5);
        v11 += v12;
        v8 += v12;
      }
      v13 = readl_relaxed((unsigned int *)(v4 + v5));
      v14 = scnprintf(v11, 128LL - v8, "0x%08x  ", v13);
      if ( (++v7 & 3) != 0 )
      {
        v11 += v14;
        v8 += v14;
      }
      else
      {
        v11 = &v19;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          *(unsigned int *)(a1 + 24),
          3,
          "cam_io_print_info",
          336,
          "%s %s",
          v18,
          &v19);
        v8 = 0;
        v19 = 0;
      }
      v5 += 4;
    }
    while ( v7 < *(unsigned int *)(a1 + 20) );
    if ( v19 )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(unsigned int *)(a1 + 24),
        3,
        "cam_io_print_info",
        343,
        "%s %s",
        v18,
        &v19);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
