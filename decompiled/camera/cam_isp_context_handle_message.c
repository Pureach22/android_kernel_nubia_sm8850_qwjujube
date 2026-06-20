__int64 __fastcall cam_isp_context_handle_message(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 *v4; // x9
  __int64 (__fastcall *v5)(__int64, __int64 *); // x8
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v9; // [xsp+0h] [xbp-80h] BYREF
  __int64 v10; // [xsp+8h] [xbp-78h]
  __int64 v11; // [xsp+10h] [xbp-70h]
  __int64 v12; // [xsp+18h] [xbp-68h]
  __int64 v13; // [xsp+20h] [xbp-60h]
  __int64 v14; // [xsp+28h] [xbp-58h]
  __int64 v15; // [xsp+30h] [xbp-50h]
  __int64 v16; // [xsp+38h] [xbp-48h]
  __int64 v17; // [xsp+40h] [xbp-40h]
  __int64 v18; // [xsp+48h] [xbp-38h]
  __int64 v19; // [xsp+50h] [xbp-30h]
  __int64 v20; // [xsp+58h] [xbp-28h]
  __int64 v21; // [xsp+60h] [xbp-20h] BYREF
  __int64 v22; // [xsp+68h] [xbp-18h]
  __int64 *v23; // [xsp+70h] [xbp-10h]
  __int64 v24; // [xsp+78h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 264);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v21 = v3;
  v22 = 0;
  if ( a2 == 7 )
  {
    v4 = *(__int64 **)(a1 + 208);
    LODWORD(v22) = 0;
    LODWORD(v9) = 11;
    v10 = a3;
    v23 = &v9;
    v5 = (__int64 (__fastcall *)(__int64, __int64 *))v4[12];
    v6 = *v4;
    if ( *((_DWORD *)v5 - 1) != 1863972096 )
      __break(0x8228u);
    v7 = v5(v6, &v21);
    if ( v7 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_context_handle_message",
        10758,
        "Update clock rate failed rc: %d",
        v7);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_handle_message",
      10761,
      "Invalid message type %d",
      a2);
    v7 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
