__int64 __fastcall slc_mpam_monitors_data_show(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  int v5; // w9
  int v6; // w10
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v4 = qcom_msc_lookup(2);
  if ( v4 )
  {
    v6 = *(_DWORD *)(a1 + 136);
    v5 = *(_DWORD *)(a1 + 140);
    LODWORD(v8[0]) = *(_DWORD *)(v4 + 12);
    HIWORD(v8[0]) = v5;
    WORD2(v8[0]) = v6;
  }
  LODWORD(result) = msc_system_mon_read_all(2, v8, a2);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
