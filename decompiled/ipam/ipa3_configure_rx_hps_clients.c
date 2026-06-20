__int64 __fastcall ipa3_configure_rx_hps_clients(int a1, int a2, signed int a3, char a4)
{
  unsigned __int64 v4; // x8
  bool v5; // cf
  unsigned __int64 v6; // x9
  int v7; // w11
  _DWORD *v8; // x8
  __int64 v9; // x11
  __int64 v10; // x11
  __int64 v11; // x11
  __int64 v12; // x10
  int v13; // w8
  __int64 v14; // x11
  __int64 v15; // x11
  __int64 v16; // x11
  __int64 v17; // x10
  unsigned int v18; // w8
  unsigned int v19; // w9
  __int64 v20; // x0
  __int64 result; // x0
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+8h] [xbp-18h]
  int v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v22 = 0;
  v23 = 0;
  if ( a2 < 1 )
    goto LABEL_44;
  v4 = *(unsigned __int8 *)(ipa3_ctx + 32244);
  v5 = v4 >= 0x18 || (unsigned int)a3 >= 7;
  v6 = 56 * v4;
  v7 = !v5;
  v8 = &ipa3_rsrc_rx_grp_config[v6 / 4];
  if ( (a4 & 1) == 0 )
  {
    if ( (v7 & 1) == 0 )
      goto LABEL_54;
    if ( v6 + 8LL * a3 + 4 > 0x540 )
      goto LABEL_55;
    LODWORD(v22) = v8[2 * a3 + 1];
    if ( a2 == 1 )
      goto LABEL_44;
LABEL_31:
    v14 = a3 + 1LL;
    if ( (unsigned int)(a3 + 1) >= 7 )
      goto LABEL_54;
    if ( v6 + 8 * v14 + 4 > 0x540 )
      goto LABEL_55;
    HIDWORD(v22) = v8[2 * v14 + 1];
    if ( a2 == 2 )
      goto LABEL_44;
LABEL_34:
    v15 = a3 + 2LL;
    if ( (unsigned int)(a3 + 2) >= 7 )
      goto LABEL_54;
    if ( v6 + 8 * v15 + 4 > 0x540 )
      goto LABEL_55;
    LODWORD(v23) = v8[2 * v15 + 1];
    if ( a2 == 3 )
      goto LABEL_44;
LABEL_37:
    v16 = a3 + 3LL;
    if ( (unsigned int)(a3 + 3) >= 7 )
      goto LABEL_54;
    if ( v6 + 8 * v16 + 4 > 0x540 )
      goto LABEL_55;
    HIDWORD(v23) = v8[2 * v16 + 1];
    if ( a2 == 4 )
      goto LABEL_44;
    goto LABEL_40;
  }
  if ( !v7 )
    goto LABEL_54;
  if ( v6 + 8LL * a3 > 0x53F )
    goto LABEL_55;
  LODWORD(v22) = v8[2 * a3];
  if ( a2 == 1 )
    goto LABEL_44;
  if ( (a4 & 1) == 0 )
    goto LABEL_31;
  v9 = a3 + 1LL;
  if ( (unsigned int)(a3 + 1) > 6 )
    goto LABEL_54;
  if ( v6 + 8 * v9 > 0x53F )
    goto LABEL_55;
  HIDWORD(v22) = v8[2 * v9];
  if ( a2 == 2 )
    goto LABEL_44;
  if ( (a4 & 1) == 0 )
    goto LABEL_34;
  v10 = a3 + 2LL;
  if ( (unsigned int)(a3 + 2) > 6 )
    goto LABEL_54;
  if ( v6 + 8 * v10 > 0x53F )
    goto LABEL_55;
  LODWORD(v23) = v8[2 * v10];
  if ( a2 == 3 )
    goto LABEL_44;
  if ( (a4 & 1) == 0 )
    goto LABEL_37;
  v11 = a3 + 3LL;
  if ( (unsigned int)(a3 + 3) > 6 )
    goto LABEL_54;
  if ( v6 + 8 * v11 > 0x53F )
    goto LABEL_55;
  HIDWORD(v23) = v8[2 * v11];
  if ( a2 == 4 )
    goto LABEL_44;
  if ( (a4 & 1) != 0 )
  {
    v12 = a3 + 4LL;
    if ( (unsigned int)v12 <= 6 )
    {
      if ( v6 + 8 * v12 > 0x53F )
        goto LABEL_55;
      v13 = v8[2 * v12];
      goto LABEL_43;
    }
LABEL_54:
    __break(0x5512u);
LABEL_55:
    __break(1u);
  }
LABEL_40:
  v17 = a3 + 4LL;
  if ( (unsigned int)v17 >= 7 )
    goto LABEL_54;
  if ( v6 + 8 * v17 + 4 > 0x540 )
    goto LABEL_55;
  v13 = v8[2 * v17 + 1];
LABEL_43:
  v24 = v13;
  if ( a2 != 5 )
    goto LABEL_54;
LABEL_44:
  if ( (a4 & 1) != 0 )
    v18 = 86;
  else
    v18 = 88;
  if ( (a4 & 1) != 0 )
    v19 = 87;
  else
    v19 = 89;
  if ( a1 )
    v20 = v19;
  else
    v20 = v18;
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(v20, 0, &v22);
  _ReadStatusReg(SP_EL0);
  return result;
}
