__int64 __fastcall policy_mgr_check_sap_restart(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 context; // x0
  __int64 (*v13)(void); // x8
  __int64 v14; // x19
  const char *v15; // x2
  const char *v16; // x2
  __int64 (*v17)(void); // x8
  __int64 result; // x0
  _DWORD *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  if ( !a1 )
  {
    v16 = "%s: Invalid psoc";
LABEL_16:
    result = qdf_trace_msg(0x4Fu, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "policy_mgr_check_sap_restart");
    goto LABEL_24;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v16 = "%s: Invalid context";
    goto LABEL_16;
  }
  v13 = *(__int64 (**)(void))(context + 320);
  v14 = context;
  if ( v13 )
  {
    if ( *((_DWORD *)v13 - 1) != 799902358 )
      __break(0x8228u);
    if ( (v13() & 1) != 0 )
    {
      v15 = "%s: channel switch is already in progress";
LABEL_14:
      result = qdf_trace_msg(0x4Fu, 8u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "policy_mgr_check_sap_restart");
      goto LABEL_24;
    }
  }
  v17 = *(__int64 (**)(void))(v14 + 328);
  if ( v17 )
  {
    if ( *((_DWORD *)v17 - 1) != 799902358 )
      __break(0x8228u);
    if ( (v17() & 1) != 0 )
    {
      v15 = "%s: DFS CAC in progress, do not restart SAP";
      goto LABEL_14;
    }
  }
  v19 = *(_DWORD **)(v14 + 296);
  if ( v19 )
  {
    if ( *(v19 - 1) != 801623019 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned int *))v19)(a1, a2, &v28);
    if ( !(_DWORD)result )
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: SAP vdev id %d switch to new ch freq: %d",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "policy_mgr_check_sap_restart",
                 (unsigned __int8)a2,
                 v28);
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: SAP restart get channel callback in NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "policy_mgr_check_sap_restart");
  }
  *(_DWORD *)(v14 + 964) = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
