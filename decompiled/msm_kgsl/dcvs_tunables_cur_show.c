__int64 __fastcall dcvs_tunables_cur_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x24
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x25
  int v9; // w4
  const char *v10; // x5
  const char *v11; // x3
  _QWORD v13[8]; // [xsp+0h] [xbp-50h] BYREF
  int v14; // [xsp+40h] [xbp-10h]
  __int64 v15; // [xsp+48h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 - 12544) == 2 )
  {
    memset(v13, 255, sizeof(v13));
    v14 = -1;
    gen8_hwsched_hfi_get_dcvs_tuning_attrs(a1 - 23664, 1);
    v4 = 0;
    v5 = 0;
    do
    {
      if ( (unsigned __int64)(v4 - 15) >= 3 )
        v5 += (int)scnprintf(
                     a3 + v5,
                     4096 - v5,
                     "%30s: %10d          Status: %s\n",
                     dcvs_tunables_strings[v4],
                     *((_DWORD *)v13 + v4),
                     "Active");
      ++v4;
    }
    while ( v4 != 17 );
  }
  else
  {
    v6 = 0;
    v5 = 0;
    v7 = a1 + 232;
    v8 = -136;
    do
    {
      if ( (unsigned __int64)(v6 - 15) >= 3 )
      {
        v9 = *(_DWORD *)(v7 + v8);
        if ( v9 == -1 )
        {
          v9 = *(_DWORD *)(v7 + 4 * v6);
          v10 = "Active";
        }
        else if ( *(_BYTE *)(v7 + v8 + 4) )
        {
          v10 = "Pending";
        }
        else
        {
          v10 = "Active";
        }
        v11 = dcvs_tunables_strings[v6];
        *((_DWORD *)v13 + v6) = v9;
        v5 += (int)scnprintf(a3 + v5, 4096 - v5, "%30s: %10d          Status: %s\n", v11, v9, v10);
      }
      ++v6;
      v8 += 8;
    }
    while ( v6 != 17 );
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
