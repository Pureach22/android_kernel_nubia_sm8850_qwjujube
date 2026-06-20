__int64 __fastcall sde_hdcp_2x_send_message(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x9
  unsigned int v9; // w10
  __int64 v10; // x8
  __int64 result; // x0
  _QWORD v12[3]; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 144);
  v9 = *(_DWORD *)(a1 + 80);
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v12[0] = 0;
  v12[1] = v8;
  LODWORD(v8) = *(_DWORD *)(a1 + 112);
  LODWORD(v12[0]) = 1;
  v10 = *(_QWORD *)(a1 + 104);
  v13 = __PAIR64__(v9, v8);
  v12[2] = v10 + 1;
  result = sde_hdcp_2x_wakeup_client(a1, (unsigned int *)v12, a3, a4, a5, a6, a7, a8);
  _ReadStatusReg(SP_EL0);
  return result;
}
