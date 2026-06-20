bool __fastcall policy_mgr_is_2x2_2G_1x1_5G_dbs_capable(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  _BOOL8 result; // x0
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  int v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v11 = 0;
  result = (unsigned int)policy_mgr_get_hw_dbs_nss(a1, (int *)&v11) >= 2
        && (unsigned int)v11 > HIDWORD(v11)
        && (policy_mgr_get_hw_mode_idx_from_dbs_hw_list(
              a1,
              2u,
              4u,
              1u,
              4u,
              1u,
              1u,
              0,
              v2,
              v3,
              v4,
              v5,
              v6,
              v7,
              v8,
              v9,
              0)
          & 0x80u) == 0LL;
  _ReadStatusReg(SP_EL0);
  return result;
}
