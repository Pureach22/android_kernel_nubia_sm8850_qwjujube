__int64 __fastcall gen7_gmu_parse_fw(__int64 a1)
{
  unsigned __int64 **v1; // x20
  __int64 v2; // x23
  unsigned __int64 *v4; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x10
  int v7; // w21
  __int64 v8; // x1
  int v9; // w10
  __int64 result; // x0
  __int64 v11; // x22
  const char *v12; // x21
  unsigned int v13; // w0
  const char *v14; // x22
  unsigned int v15; // w0
  unsigned int v16; // w19

  v1 = (unsigned __int64 **)(a1 - 1768);
  v2 = *(_QWORD *)(a1 + 1544);
  if ( !*(_QWORD *)(a1 - 1768) )
  {
    v11 = *(_QWORD *)(a1 + 14264);
    v12 = *(const char **)(v11 + 112);
    if ( !v12 )
      return 4294967274LL;
    v13 = request_firmware(a1 - 1768, *(_QWORD *)(v11 + 112), v2 + 16);
    if ( v13 )
    {
      v14 = *(const char **)(v11 + 120);
      if ( !v14 )
      {
        v16 = v13;
        goto LABEL_21;
      }
      v15 = request_firmware(v1, v14, v2 + 16);
      if ( v15 )
      {
        v16 = v15;
        v12 = v14;
LABEL_21:
        dev_err(v2 + 16, "request_firmware (%s) failed: %d\n", v12, v16);
        return v16;
      }
    }
  }
  v4 = *v1;
  v5 = **v1;
  if ( !v5 )
    return 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = v6 + 16;
    if ( v6 + 16 > v5 )
      break;
    v8 = v4[1] + v6;
    if ( *(_DWORD *)(v8 + 4) )
      return 0;
    v9 = *(_DWORD *)(v8 + 8);
    if ( v9 == 7 || v9 == 1 )
    {
      result = ((__int64 (__fastcall *)(__int64))gmu_core_process_prealloc)(a1);
      if ( (_DWORD)result )
        return result;
      v4 = *v1;
      v5 = **v1;
    }
    v6 = v7;
    if ( v7 >= v5 )
      return 0;
  }
  dev_err(v2 + 16, "Invalid FW Block\n");
  return 4294967274LL;
}
