__int64 __fastcall cam_cpas_print_smart_qos_priority(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x22
  unsigned __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x8
  unsigned __int64 v7; // x24
  __int64 v8; // x28
  unsigned int v9; // w25
  __int64 v10; // x26
  __int64 v11; // x21
  int v12; // w20
  int v13; // w0
  int v14; // w0
  unsigned __int64 v15; // x10
  __int64 result; // x0
  __int64 v17; // [xsp+8h] [xbp-218h]
  char s[512]; // [xsp+10h] [xbp-210h] BYREF
  __int64 v19; // [xsp+210h] [xbp-10h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3680);
  v3 = *(_QWORD *)(a1 + 3392);
  memset(s, 0, sizeof(s));
  v17 = v2;
  v4 = *(unsigned __int8 *)(v2 + 159424);
  if ( v4 >= 4 || (v5 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)v2 + 8 * v4 + 8) + 4LL), (unsigned int)v5 > 9) )
LABEL_11:
    __break(0x5512u);
  v6 = *(_QWORD *)(v3 + 1616);
  if ( *(_BYTE *)(v6 + 9) )
  {
    v7 = 0;
    v8 = 2;
    v9 = *(_DWORD *)(v2 + 4 * v5 + 2812);
    v10 = a1 + 24LL * v9;
    do
    {
      if ( v8 == 12 )
        goto LABEL_11;
      if ( v9 > 7 )
        goto LABEL_11;
      v11 = *(_QWORD *)(v6 + 8 * v8);
      v12 = cam_io_r_mb(*(_QWORD *)(v10 + 384) + *(unsigned int *)(v11 + 124));
      v13 = cam_io_r_mb(*(_QWORD *)(v10 + 384) + *(unsigned int *)(v11 + 120));
      if ( v7 > 0x200 )
        goto LABEL_11;
      v14 = scnprintf(&s[v7], 512 - v7, " [%s:high 0x%x low 0x%x]", *(const char **)(v11 + 24), v12, v13);
      v6 = *(_QWORD *)(v3 + 1616);
      v15 = v8 - 1;
      v7 += v14;
      ++v8;
    }
    while ( v15 < *(unsigned __int8 *)(v6 + 9) );
    LOBYTE(v4) = *(_BYTE *)(v17 + 159424);
  }
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             4,
             3,
             "cam_cpas_print_smart_qos_priority",
             892,
             "%s SmartQoS [Node Pri_lut] %s",
             g_camnoc_names[(char)v4],
             s);
  _ReadStatusReg(SP_EL0);
  return result;
}
