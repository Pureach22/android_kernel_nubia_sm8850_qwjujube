__int64 __fastcall sps_phy2h(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x21
  _QWORD *v5; // x22
  _QWORD *v6; // x9
  _QWORD *v7; // x8
  __int64 result; // x0
  __int64 v9; // x19
  _QWORD *v10; // x21
  __int64 v11; // x19
  _QWORD *v12; // x21
  int v13; // w0
  int v14; // w8
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = a1;
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
  {
    if ( !print_limit_option
      || (v11 = a1, v12 = a2, v13 = __ratelimit(&sps_phy2h__rs, "sps_phy2h"), a2 = v12, v14 = v13, a1 = v11, v14) )
    {
      v9 = a1;
      v10 = a2;
      printk(&unk_26A3F, "sps_phy2h", a3);
      a1 = v9;
      a2 = v10;
    }
  }
  v3 = sps;
  if ( sps
    && (*(_DWORD *)(sps + 288) > 2u
     || (v4 = a1,
         v5 = a2,
         ipc_log_string(*(_QWORD *)(sps + 264), "%s: Enter\n", "sps_phy2h"),
         v3 = sps,
         a1 = v4,
         a2 = v5,
         sps))
    && *(_DWORD *)(v3 + 48) )
  {
    if ( a2 )
    {
      v6 = (_QWORD *)(v3 + 160);
      v7 = (_QWORD *)(v3 + 160);
      while ( 1 )
      {
        v7 = (_QWORD *)*v7;
        if ( v7 == v6 )
          break;
        if ( v7[3] == a1 )
        {
          result = 0;
          *a2 = v7;
          goto LABEL_16;
        }
      }
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_phy2h__rs_17, "sps_phy2h")) )
      {
        printk(&unk_2A5B5, "sps_phy2h", v15);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM device %pa is not registered yet\n", "sps_phy2h", v15);
      result = 4294967277LL;
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_phy2h__rs_14, "sps_phy2h")) )
      {
        printk(&unk_2373E, "sps_phy2h", a3);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: handle is NULL\n", "sps_phy2h");
      result = 0xFFFFFFFFLL;
    }
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && debug_level_option
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_phy2h__rs_13, "sps_phy2h")) )
    {
      printk(&unk_24F08, "sps_phy2h", a3);
    }
    if ( sps && *(_DWORD *)(sps + 288) <= 3u )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver is not ready\n", "sps_phy2h");
    result = 4294966779LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
