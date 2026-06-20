__int64 __fastcall ml_nlink_is_support_emlsr_with_freq(__int64 a1, unsigned int *a2, unsigned int a3)
{
  unsigned int hc_id; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 v14; // x4
  __int64 result; // x0
  unsigned int v16; // w21
  int rd_type; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _BOOL8 is_disc_active; // x0
  __int64 v27; // x1
  __int64 v28; // x2
  unsigned int v29; // w8
  char *v30; // x8
  char *v31; // x9
  unsigned int v32; // w8
  unsigned int v33; // w20
  const char *v34; // x22
  char *v35; // x21
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = a3;
  hc_id = get_hc_id(a1, 2u, a2);
  if ( hc_id >= 0x11 )
  {
    v13 = "%s: invalid ml_hc_id, %d";
    v14 = hc_id;
LABEL_3:
    qdf_trace_msg(0x8Fu, 8u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "ml_nlink_is_support_emlsr_with_freq", v14);
    result = 0;
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( hc_id - 7 <= 0xFFFFFFFC )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: ml %s no emlsr support",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "ml_nlink_is_support_emlsr_with_freq",
      off_B32E90[hc_id]);
    result = 0;
    goto LABEL_18;
  }
  v16 = get_hc_id(a1, 1u, &v45);
  if ( v16 >= 0xA )
  {
    v13 = "%s: invalid legacy_hc_id %d";
    v14 = v16;
    goto LABEL_3;
  }
  rd_type = policy_mgr_get_rd_type(a1);
  is_disc_active = wlan_nan_is_disc_active(a1, v18, v19, v20, v21, v22, v23, v24, v25);
  v29 = rd_type - 1;
  if ( is_disc_active )
    v29 = 0;
  if ( v29 > 3 )
    v30 = (char *)&disallow_mlo_mode_table_sbs_low_share;
  else
    v30 = (char *)*(&off_B32F18 + v29);
  if ( 8LL * v16 + 80 * (unsigned __int64)hc_id <= 0x54F )
  {
    v31 = &v30[80 * hc_id];
    v32 = hc_id - 4;
    v33 = *(_DWORD *)&v31[8 * v16];
    if ( v32 > 2 )
      v34 = "Unknown";
    else
      v34 = off_B32F38[v32];
    v35 = off_B32F50[v16];
    v36 = policy_mgr_get_rd_type(a1);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: ml %s legacy %s rd %d disallow_mode_bitmap 0x%x",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "ml_nlink_is_support_emlsr_with_freq",
      v34,
      v35,
      v36,
      v33);
    result = (v33 & 7) == 0;
    goto LABEL_18;
  }
  __break(1u);
  return ml_nlink_handle_mcc_links(is_disc_active, v27, v28);
}
