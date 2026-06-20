__int64 __fastcall last_cmd_sb_v2(__int64 a1, unsigned int a2)
{
  int v4; // w3
  __int64 v5; // x1
  __int64 v6; // x8
  unsigned int v7; // w20
  __int64 result; // x0
  __int64 v9; // [xsp+18h] [xbp-58h] BYREF
  int v10[2]; // [xsp+20h] [xbp-50h]
  __int64 v11; // [xsp+28h] [xbp-48h]
  __int64 v12; // [xsp+30h] [xbp-40h]
  __int128 v13; // [xsp+38h] [xbp-38h]
  __int64 v14; // [xsp+48h] [xbp-28h]
  __int64 v15; // [xsp+50h] [xbp-20h]
  __int64 v16; // [xsp+58h] [xbp-18h]
  __int64 v17; // [xsp+60h] [xbp-10h]
  __int64 v18; // [xsp+68h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v13 = 0u;
  v11 = 0;
  v12 = 0;
  *(_QWORD *)v10 = 0;
  if ( !a1 )
  {
    v4 = -1;
LABEL_7:
    _drm_err("ctl %pK q %d index %d\n", (const void *)a1, a2, v4);
    goto LABEL_14;
  }
  v4 = *(_DWORD *)(a1 + 64);
  if ( a2 > 1 || v4 >= 7 )
    goto LABEL_7;
  v5 = *(unsigned int *)(a1 + 1784);
  if ( (unsigned int)v5 >= 2 )
  {
    _drm_err("invalid dpu idx %d\n");
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v6 = last_cmd_buf[v5];
  if ( !v6 || !*(_QWORD *)(v6 + 24) )
  {
    _drm_err("invalid last cmd buf for dpu idx %d\n");
    goto LABEL_14;
  }
  v9 = a1;
  HIDWORD(v13) = 1;
  v10[0] = 1;
  LODWORD(v13) = a2;
  *(_QWORD *)((char *)&v13 + 4) = 0x1900000001LL;
  v11 = v6;
  v7 = kick_off_v1((__int64)&v9, v5);
  if ( v7 )
    _drm_err("kick off last cmd failed\n");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "last_cmd_sb_v2",
    1849,
    -1,
    *(_DWORD *)(a1 + 64),
    v13,
    SDWORD1(v13),
    v10[0],
    *(_DWORD *)(a1 + 1784));
  result = v7;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
