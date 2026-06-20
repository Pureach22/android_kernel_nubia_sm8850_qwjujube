__int64 __fastcall ml_nlink_allow_conc(__int64 a1, __int64 a2, unsigned __int16 a3, unsigned __int16 a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  char v16; // w0
  unsigned int v18; // [xsp+10h] [xbp-60h] BYREF
  char v19; // [xsp+17h] [xbp-59h] BYREF
  int v20; // [xsp+18h] [xbp-58h] BYREF
  char v21; // [xsp+1Ch] [xbp-54h]
  int v22; // [xsp+20h] [xbp-50h] BYREF
  char v23; // [xsp+24h] [xbp-4Ch]
  _QWORD v24[5]; // [xsp+28h] [xbp-48h] BYREF
  _QWORD v25[2]; // [xsp+50h] [xbp-20h] BYREF
  int v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v23 = 0;
  v22 = 0;
  v26 = 0;
  v25[0] = 0;
  v25[1] = 0;
  v21 = 0;
  v20 = 0;
  memset(v24, 0, sizeof(v24));
  ml_nlink_get_link_info(a1, a2, 5u, 5u, v24, (unsigned int *)v25, (unsigned __int8 *)&v22, &v20, &v19, &v18);
  if ( (v18 & ~a4) != 0 )
  {
    v16 = policy_mgr_allow_non_force_link_bitmap(a1, a2, a3, a4);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: not allow - no active link after force inactive 0x%x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "ml_nlink_sta_inactivity_allowed_with_quiet");
    v16 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v16 & 1;
}
