__int64 __fastcall ucfg_nan_update_mc_list(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  const char *v12; // x2
  __int64 result; // x0
  __int64 (__fastcall *v14)(__int64); // x8
  _QWORD v15[17]; // [xsp+8h] [xbp-C8h] BYREF
  __int64 (__fastcall *v16)(__int64); // [xsp+90h] [xbp-40h]
  __int64 v17; // [xsp+98h] [xbp-38h]
  __int64 v18; // [xsp+A0h] [xbp-30h]
  __int64 v19; // [xsp+A8h] [xbp-28h]
  __int64 v20; // [xsp+B0h] [xbp-20h]
  __int64 v21; // [xsp+B8h] [xbp-18h]
  __int64 v22; // [xsp+C0h] [xbp-10h]
  __int64 v23; // [xsp+C8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 216);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v16 = nullptr;
  memset(v15, 0, sizeof(v15));
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v12 = "%s: psoc is null";
    goto LABEL_6;
  }
  if ( (unsigned int)ucfg_nan_get_callbacks(v10, v15) )
  {
    v12 = "%s: Couldn't get callback object";
LABEL_6:
    result = qdf_trace_msg(0x53u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_nan_update_mc_list");
    goto LABEL_7;
  }
  v14 = v16;
  if ( !v16 )
  {
    v12 = "%s: set_mc_list callback not registered";
    goto LABEL_6;
  }
  if ( *((_DWORD *)v16 - 1) != 1458356883 )
    __break(0x8228u);
  result = v14(a1);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
