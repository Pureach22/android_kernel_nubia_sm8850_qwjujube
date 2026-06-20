__int64 __fastcall slc_mpam_monitor_data_show(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  int v5; // w9
  int v6; // w10
  int v7; // w0
  __int64 v8; // x21
  __int64 result; // x0
  __int128 v10; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+18h] [xbp-28h]
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h]
  _QWORD v14[2]; // [xsp+30h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  v10 = 0u;
  v4 = qcom_msc_lookup(2);
  if ( v4 )
  {
    v6 = *(_DWORD *)(a1 + 136);
    v5 = *(_DWORD *)(a1 + 140);
    LODWORD(v14[0]) = *(_DWORD *)(v4 + 12);
    HIWORD(v14[0]) = v5;
    WORD2(v14[0]) = v6;
  }
  if ( (*(_BYTE *)(a1 + 145) & 1) != 0
    || (*(_BYTE *)(a1 + 147) & 1) != 0
    || (*(_BYTE *)(a1 + 149) & 1) != 0
    || *(_BYTE *)(a1 + 151) == 1 )
  {
    msc_system_mon_stats_read(2, v14, &v10);
    v7 = scnprintf(a2, 4096, "timestamp=%llu,", *(_QWORD *)((char *)&v10 + 4));
    v8 = v7;
    if ( *(_BYTE *)(a1 + 145) == 1 )
      v8 = v7 + (__int64)(int)scnprintf(a2 + v7, 4096LL - v7, "cap_cnt=%u,", HIDWORD(v10));
    if ( *(_BYTE *)(a1 + 147) == 1 )
      v8 += (int)scnprintf(a2 + v8, 4096 - v8, "miss_cnt=%llu,", v11);
    if ( *(_BYTE *)(a1 + 149) == 1 )
      v8 += (int)scnprintf(a2 + v8, 4096 - v8, "fe_bytes=%llu,", v12);
    if ( *(_BYTE *)(a1 + 151) == 1 )
      v8 += (int)scnprintf(a2 + v8, 4096 - v8, "be_bytes=%llu,", v13);
    result = v8 - 1 + (int)scnprintf(a2 + v8 - 1, 4097 - v8, "\n");
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
