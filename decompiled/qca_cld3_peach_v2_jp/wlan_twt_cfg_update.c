__int64 __fastcall wlan_twt_cfg_update(
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
  unsigned __int8 *comp_private_obj; // x0
  int v11; // w8
  unsigned __int8 *v12; // x19
  __int64 v13; // x4
  const char *v14; // x2
  __int64 v16; // x5
  unsigned __int8 v17; // w9
  unsigned int v18; // w10
  __int64 v19; // x6
  unsigned int v20; // w11
  unsigned __int8 v21; // w9
  unsigned int v22; // w10
  char is_flexible_twt_enabled; // w0
  char v24; // w8
  __int64 v25; // x7

  if ( !a1 )
  {
    v14 = "%s: null psoc";
LABEL_7:
    qdf_trace_msg(0x96u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_twt_cfg_update");
    return 16;
  }
  comp_private_obj = (unsigned __int8 *)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( !comp_private_obj )
  {
    v14 = "%s: null twt psoc priv obj";
    goto LABEL_7;
  }
  v11 = *comp_private_obj;
  v12 = comp_private_obj;
  v13 = v11 == 1 && comp_private_obj[20] > (unsigned int)(unsigned __int8)(comp_private_obj[3] - 1);
  v16 = comp_private_obj[1];
  v17 = comp_private_obj[21];
  comp_private_obj[3] = v13;
  comp_private_obj[2] = (_DWORD)v16 != 0;
  if ( (v17 & (unsigned __int8)v11 & 1) == 0 )
  {
    v16 = 0;
    comp_private_obj[1] = 0;
  }
  if ( (comp_private_obj[23] & 1) != 0 )
  {
    v18 = 1;
    if ( !v11 )
    {
LABEL_13:
      v19 = 0;
      goto LABEL_21;
    }
  }
  else
  {
    v18 = comp_private_obj[22];
    if ( !v11 )
      goto LABEL_13;
  }
  v20 = comp_private_obj[8];
  if ( v18 < v20 )
    v19 = 1;
  else
    v19 = comp_private_obj[8];
  if ( v18 < v20 && (comp_private_obj[23] & 1) == 0 )
    v19 = comp_private_obj[22];
LABEL_21:
  v21 = comp_private_obj[24];
  comp_private_obj[8] = v19;
  if ( (v21 & 1) == 0 )
  {
    v22 = comp_private_obj[22];
    if ( !v11 )
      goto LABEL_23;
LABEL_25:
    if ( v22 < comp_private_obj[9] )
    {
      if ( (v21 & 1) != 0 )
        v24 = 1;
      else
        v24 = comp_private_obj[22];
      comp_private_obj[9] = v24;
    }
    is_flexible_twt_enabled = mlme_is_flexible_twt_enabled(a1);
    v13 = v12[3];
    v16 = v12[1];
    v19 = v12[8];
    goto LABEL_31;
  }
  v22 = 1;
  if ( v11 )
    goto LABEL_25;
LABEL_23:
  is_flexible_twt_enabled = 0;
  v12[9] = 0;
LABEL_31:
  v25 = v12[9];
  v12[12] = is_flexible_twt_enabled & 1;
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: req: %d resp: %d bcast_req: %d bcast_resp: %d flex_twt %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_twt_cfg_update",
    v13,
    v16,
    v19,
    v25,
    is_flexible_twt_enabled & 1);
  return 0;
}
