__int64 __fastcall cam_cpas_dump_state_monitor_array_info(__int64 a1, __int64 *a2)
{
  __int64 v2; // x22
  __int64 v3; // x21
  __int64 v4; // x23
  unsigned int v6; // w20
  __int64 result; // x0
  unsigned __int64 v8; // x8
  int cpu_buf; // w0
  int v10; // w6
  unsigned int v11; // w19
  unsigned __int64 v12; // x7
  unsigned int v13; // w9
  int v14; // w10
  int v15; // w1
  unsigned int v16; // w2
  _DWORD *v17; // x3
  unsigned int v18; // w9
  int v19; // w4
  int v20; // w4
  int v21; // w4
  int v22; // w4
  int v23; // w4
  int v24; // w4
  _QWORD *v25; // x4
  int v26; // w5
  int v27; // w5
  int v28; // w5
  int v29; // w3
  __int64 v30; // x8
  int v31; // w0
  int v32; // w0
  unsigned int v33; // w20
  char v34; // [xsp+0h] [xbp-50h]
  __int64 v35; // [xsp+8h] [xbp-48h] BYREF
  size_t v36; // [xsp+10h] [xbp-40h] BYREF
  __int64 v37; // [xsp+18h] [xbp-38h] BYREF
  __int64 v38; // [xsp+20h] [xbp-30h]
  size_t v39; // [xsp+28h] [xbp-28h]
  unsigned __int64 v40; // [xsp+30h] [xbp-20h]
  __int64 v41; // [xsp+38h] [xbp-18h]
  __int64 v42; // [xsp+40h] [xbp-10h]
  __int64 v43; // [xsp+48h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3680);
  v41 = 0;
  v42 = 0;
  v3 = *(_QWORD *)(a1 + 3392);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v4 = *(_QWORD *)(v2 + 8216);
  if ( v4 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      2,
      "cam_cpas_dump_state_monitor_array_info",
      4021,
      "No valid entries in cpas monitor array");
LABEL_5:
    result = 0;
    goto LABEL_55;
  }
  if ( v4 > 99 )
  {
    v8 = v4 + 1;
    LODWORD(v4) = 100;
    v6 = v8 % 0x64;
  }
  else
  {
    v6 = 0;
  }
  cpu_buf = cam_mem_get_cpu_buf(*((_DWORD *)a2 + 5), &v35, &v36);
  if ( cpu_buf )
  {
    v10 = *((_DWORD *)a2 + 5);
    v11 = cpu_buf;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dump_state_monitor_array_info",
      4037,
      "Invalid handle %u rc %d",
      v10,
      cpu_buf);
    result = v11;
    goto LABEL_55;
  }
  v12 = a2[1];
  if ( v36 <= v12 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      2,
      "cam_cpas_dump_state_monitor_array_info",
      4043,
      "Dump buffer overshoot len %zu offset %zu",
      v36,
      v12);
LABEL_54:
    cam_mem_put_cpu_buf(*((_DWORD *)a2 + 5));
    result = 4294967268LL;
    goto LABEL_55;
  }
  v13 = 0;
  if ( (_DWORD)v4 )
  {
    v14 = *(_DWORD *)(v2 + 2780);
    v15 = v4;
    v16 = v6;
    do
    {
      v17 = (_DWORD *)(v2 + 8224 + 1512LL * v16);
      v18 = v13 + 304;
      if ( v14 )
      {
        if ( (unsigned int)(v14 - 7) < 0xFFFFFFFA )
LABEL_66:
          __break(0x5512u);
        if ( v17[56] == 1 )
          v19 = 176;
        else
          v19 = 160;
        v18 += v19;
        if ( v14 != 1 )
        {
          v20 = v17[90] == 1 ? 176 : 160;
          v18 += v20;
          if ( v14 != 2 )
          {
            v21 = v17[124] == 1 ? 176 : 160;
            v18 += v21;
            if ( v14 != 3 )
            {
              v22 = v17[158] == 1 ? 176 : 160;
              v18 += v22;
              if ( v14 != 4 )
              {
                v23 = v17[192] == 1 ? 176 : 160;
                v18 += v23;
                if ( v14 != 5 )
                {
                  if ( v17[226] == 1 )
                    v24 = 176;
                  else
                    v24 = 160;
                  v18 += v24;
                }
              }
            }
          }
        }
      }
      v25 = *(_QWORD **)v2;
      if ( *(_QWORD *)(*(_QWORD *)v2 + 8LL) )
      {
        v26 = v17[262];
        v18 += 8;
        if ( v26 )
          v18 += 144 * v26;
      }
      if ( v25[2] )
      {
        v27 = v17[263];
        v18 += 8;
        if ( v27 )
          v18 += 144 * v27;
      }
      if ( v25[3] )
      {
        v28 = v17[264];
        v18 += 8;
        if ( v28 )
          v18 += 144 * v28;
      }
      if ( v25[4] )
      {
        v29 = v17[265];
        v18 += 8;
        if ( v29 )
          v18 += 144 * v29;
      }
      --v15;
      v16 = (v16 + 1) % 0x64;
      v13 = v18 + 160 * *(unsigned __int8 *)(*(_QWORD *)(v3 + 1616) + 9LL) + 144;
    }
    while ( v15 );
  }
  if ( v36 - v12 < v13 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      2,
      "cam_cpas_dump_state_monitor_array_info",
      4084,
      "Dump buffer exhaust remain %zu min %u",
      v36 - v12,
      v13);
    goto LABEL_54;
  }
  v30 = *a2;
  v39 = v36;
  v40 = v12;
  v41 = 0;
  v37 = v30;
  v38 = v35;
  if ( !(_DWORD)v4 )
  {
LABEL_64:
    v32 = *((_DWORD *)a2 + 5);
    a2[1] = v12;
    cam_mem_put_cpu_buf(v32);
    goto LABEL_5;
  }
  while ( 1 )
  {
    if ( v6 > 0x63 )
      goto LABEL_66;
    v31 = cam_common_user_dump_helper(
            &v37,
            (__int64 (__fastcall *)(__int64, __int64))&cam_cpas_user_dump_state_monitor_array_info,
            v2 + 8224 + 1512LL * v6,
            8,
            "CPAS_MONITOR.%d.%s:",
            v6,
            v2 + 8224 + 1512LL * v6 + 16,
            v12,
            v34);
    if ( v31 )
      break;
    if ( v6 == 99 )
      v6 = 0;
    else
      ++v6;
    LODWORD(v4) = v4 - 1;
    if ( !(_DWORD)v4 )
    {
      v12 = v40;
      goto LABEL_64;
    }
  }
  v33 = v31;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_dump_state_monitor_array_info",
    4101,
    "Dump state info failed, rc: %d",
    v31);
  cam_mem_put_cpu_buf(*((_DWORD *)a2 + 5));
  result = v33;
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
