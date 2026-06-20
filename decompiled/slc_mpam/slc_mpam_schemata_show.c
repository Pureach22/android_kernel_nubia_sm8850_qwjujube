__int64 __fastcall slc_mpam_schemata_show(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  int v5; // w9
  int v6; // w10
  unsigned int partition; // w0
  __int64 result; // x0
  unsigned int v9; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v9 = 0;
  v4 = qcom_msc_lookup(2);
  if ( v4 )
  {
    v6 = *(_DWORD *)(a1 + 136);
    v5 = *(_DWORD *)(a1 + 140);
    LODWORD(v10[0]) = *(_DWORD *)(v4 + 12);
    HIWORD(v10[0]) = v5;
    WORD2(v10[0]) = v6;
  }
  partition = msc_system_get_partition(2, v10, &v9);
  if ( partition )
    LODWORD(result) = scnprintf(a2, 4096, "failed to get schemata %d\n", partition);
  else
    LODWORD(result) = scnprintf(a2, 4096, "gear=%d\n", v9);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
