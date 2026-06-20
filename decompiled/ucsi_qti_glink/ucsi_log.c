__int64 __fastcall ucsi_log(__int64 a1, const char *a2, int a3, __int64 a4, unsigned __int64 a5)
{
  __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w28
  unsigned int v13; // w25
  int v14; // w0
  int v15; // w9
  __int64 (*v16)(void); // x8
  __int64 v17; // x0
  unsigned __int64 v18; // x9
  int v19; // w8
  unsigned __int64 v20; // x5
  int v21; // w6
  int v22; // w11
  unsigned int v23; // w9
  unsigned __int64 v24; // t2
  const char *v25; // x3
  unsigned int v26; // w8
  unsigned __int64 v27; // t2
  const char *v28; // x3
  __int64 result; // x0
  _QWORD v30[34]; // [xsp+10h] [xbp-110h] BYREF

  v30[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v30, 0, 256);
  if ( a5 )
  {
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = 1;
    do
    {
      v14 = scnprintf((char *)v30 + v10, 256 - v10, "%02x ", *(unsigned __int8 *)(a4 + v11));
      v11 = v13;
      v10 = (unsigned int)(v14 + v12);
      if ( v13 >= a5 )
        break;
      ++v13;
      v12 += v14;
    }
    while ( (unsigned int)v10 < 0xFF );
    if ( (unsigned int)v10 > 0xFF )
    {
      __break(0x5512u);
      return ucsi_qti_read_version();
    }
  }
  else
  {
    v10 = 0;
  }
  v15 = *(unsigned __int8 *)(a1 + 1452);
  *((_BYTE *)v30 + v10) = 0;
  if ( v15 == 1 )
  {
    v16 = (__int64 (*)(void))arch_timer_read_counter;
    if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
      __break(0x8228u);
    v17 = v16();
    v18 = 1000 * v17 / 0x47868C000uLL;
    v19 = 1000 * v17 / 0x4B00uLL - 1000000 * v18;
    v20 = (1221679587 * (unsigned __int64)(unsigned int)v18) >> 42;
    v21 = ((unsigned int)((1145324613 * (unsigned __int64)(unsigned int)v18) >> 32) >> 4) - 60 * v20;
    v22 = v18 - 3600 * v20;
    HIDWORD(v24) = a3;
    LODWORD(v24) = a3;
    v23 = v24 >> 2;
    if ( v23 > 8 )
      v25 = "UNKNOWN:";
    else
      v25 = (&off_77E8)[v23];
    result = ipc_log_string(
               ucsi_ipc_log,
               "%s %s %s (%02u:%02u:%02u.%06u)\n",
               a2,
               v25,
               (const char *)v30,
               v20,
               v21,
               v22 - 60 * v21,
               v19);
  }
  else
  {
    HIDWORD(v27) = a3;
    LODWORD(v27) = a3;
    v26 = v27 >> 2;
    if ( v26 > 8 )
      v28 = "UNKNOWN:";
    else
      v28 = (&off_77E8)[v26];
    result = ipc_log_string(ucsi_ipc_log, "%s %s %s\n", a2, v28, (const char *)v30);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
