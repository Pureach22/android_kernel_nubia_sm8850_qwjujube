__int64 __fastcall wmi_print_cmd_log_buffer(
        __int64 a1,
        unsigned int a2,
        __int64 (__fastcall *a3)(__int64, const char *),
        __int64 a4)
{
  unsigned int v5; // w19
  unsigned int v6; // w8
  int *v7; // x9
  unsigned int v8; // w10
  unsigned int v9; // w27
  int v10; // w20
  __int64 result; // x0
  unsigned int v12; // w28
  unsigned int *v13; // x22
  unsigned __int64 v14; // x8
  int v15; // w26
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x24
  unsigned __int64 v18; // x25
  const char *v19; // x0
  unsigned int v20; // w0
  unsigned int v21; // w24
  int v22; // w0
  __int64 v23; // x24
  int v24; // w0
  __int64 v25; // x24
  int v26; // w0
  __int64 v27; // x8
  long double v28; // q0
  _QWORD v31[17]; // [xsp+18h] [xbp-88h] BYREF

  v31[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 24);
  v6 = *(_DWORD *)(a1 + 8);
  v7 = *(int **)(a1 + 16);
  memset(&v31[10], 0, 48);
  if ( v5 >= a2 )
    v8 = a2;
  else
    v8 = v5;
  memset(&v31[6], 0, 32);
  if ( v8 >= v6 )
    v9 = v6;
  else
    v9 = v8;
  memset(v31, 0, 48);
  v10 = *v7;
  if ( *((_DWORD *)a3 - 1) != 1872960511 )
    __break(0x8222u);
  result = a3(a4, "Time (seconds)      Cmd Id              Payload");
  if ( v9 )
  {
    v12 = (v5 - v9 + v10) % v5;
    do
    {
      v13 = (unsigned int *)(*(_QWORD *)a1 + 32LL * v12);
      v14 = *((_QWORD *)v13 + 3);
      v15 = *v13;
      if ( 10 * v14 < v14 )
        v16 = 10 * (v14 / 0xC0);
      else
        v16 = 10 * v14 / 0xC0;
      v17 = v16 / 0xF4240;
      v18 = v16 % 0xF4240;
      v19 = (const char *)wmi_id_to_name(*v13);
      scnprintf(v31, 128, "% 8lld.%06lld    %6u (%s)    ", v17, v18, v15, v19);
      if ( v20 >= 0x81
        || (v21 = v20,
            scnprintf((char *)v31 + v20, 128LL - v20, "0x%08x ", v13[1]),
            v23 = v22 + v21,
            (unsigned int)v23 > 0x80)
        || (scnprintf((char *)v31 + v23, 128 - v23, "0x%08x ", v13[2]),
            v25 = (unsigned int)(v24 + v23),
            (unsigned int)v25 > 0x80)
        || (scnprintf((char *)v31 + v25, 128 - v25, "0x%08x ", v13[3]),
            v27 = (unsigned int)(v26 + v25),
            (unsigned int)v27 > 0x80) )
      {
        __break(0x5512u);
      }
      *(double *)&v28 = scnprintf((char *)v31 + v27, 128 - v27, "0x%08x ", v13[4]);
      if ( *((_DWORD *)a3 - 1) != 1872960511 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD *, long double))a3)(a4, v31, v28);
      --v9;
      if ( v12 + 1 < *(_DWORD *)(a1 + 24) )
        ++v12;
      else
        v12 = 0;
    }
    while ( v9 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
