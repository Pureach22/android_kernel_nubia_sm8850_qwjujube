__int64 __fastcall policy_mgr_get_nondfs_preferred_channel(__int64 a1, unsigned int a2, char a3, unsigned int a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  char is_mlo_ap; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x21
  __int64 v37; // [xsp+0h] [xbp-210h] BYREF
  _QWORD v38[13]; // [xsp+8h] [xbp-208h] BYREF
  _DWORD s[102]; // [xsp+70h] [xbp-1A0h] BYREF
  __int64 v40; // [xsp+208h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  memset(v38, 0, 102);
  v37 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_get_nondfs_preferred_channel");
    goto LABEL_16;
  }
  v17 = context;
  if ( (a3 & 1) == 0 )
  {
    if ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _DWORD *, char *, _QWORD *, __int64, _QWORD))policy_mgr_get_pcl)(
                          a1,
                          a2,
                          s,
                          (char *)&v37 + 4,
                          v38,
                          102,
                          a4) )
      goto LABEL_9;
LABEL_16:
    result = 2437;
    goto LABEL_17;
  }
  is_mlo_ap = policy_mgr_is_mlo_ap(a1, a4);
  if ( (policy_mgr_is_any_nondfs_chnl_present(a1, &v37, is_mlo_ap & 1, a4) & 1) != 0 )
  {
    result = (unsigned int)v37;
    goto LABEL_17;
  }
  if ( (unsigned int)policy_mgr_get_pcl_for_existing_conn(
                       a1,
                       a2,
                       (__int64)s,
                       (_DWORD *)&v37 + 1,
                       (__int64)v38,
                       0x66u,
                       0,
                       a4,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26) )
    goto LABEL_16;
LABEL_9:
  if ( !HIDWORD(v37) )
    goto LABEL_16;
  v36 = 0;
  while ( 1 )
  {
    if ( v36 == 102 )
      __break(0x5512u);
    if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v17 + 8), s[v36], v28, v29, v30, v31, v32, v33, v34, v35) & 1) == 0
      && (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, (unsigned int)s[v36]) & 1) != 0 )
    {
      break;
    }
    if ( ++v36 >= (unsigned __int64)HIDWORD(v37) )
      goto LABEL_16;
  }
  result = (unsigned int)s[v36];
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
