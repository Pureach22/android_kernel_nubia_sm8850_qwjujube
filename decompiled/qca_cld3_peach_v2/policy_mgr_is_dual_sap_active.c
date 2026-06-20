bool __fastcall policy_mgr_is_dual_sap_active(__int64 a1)
{
  int v1; // w8
  int v2; // w9
  unsigned int v4; // [xsp+8h] [xbp-38h] BYREF
  unsigned int v5; // [xsp+Ch] [xbp-34h] BYREF
  int v6; // [xsp+10h] [xbp-30h] BYREF
  char v7; // [xsp+14h] [xbp-2Ch]
  _BYTE v8[5]; // [xsp+16h] [xbp-2Ah] BYREF
  _BYTE v9[5]; // [xsp+1Bh] [xbp-25h] BYREF
  _QWORD v10[2]; // [xsp+20h] [xbp-20h] BYREF
  int v11; // [xsp+30h] [xbp-10h]
  __int64 v12; // [xsp+38h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v5) = 0;
  LOBYTE(v4) = 0;
  v11 = 0;
  v10[0] = 0;
  v10[1] = 0;
  v7 = 0;
  v6 = 0;
  policy_mgr_get_ml_and_non_ml_mode_count(
    a1,
    &v5,
    (__int64)v9,
    &v4,
    (__int64)v8,
    (unsigned __int64)v10,
    (unsigned __int64)&v6,
    1u);
  v1 = (unsigned __int8)v5;
  v2 = (unsigned __int8)v4;
  _ReadStatusReg(SP_EL0);
  return v2 + v1 == 2;
}
