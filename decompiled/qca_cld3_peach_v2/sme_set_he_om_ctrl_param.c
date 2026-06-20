__int64 __fastcall sme_set_he_om_ctrl_param(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x23
  __int64 v17; // x0
  _BYTE *v18; // x21
  __int64 result; // x0
  const char *v20; // x2
  const char *v21; // x3
  __int64 v22; // x4
  unsigned int v23; // w1
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  int v25; // [xsp+10h] [xbp-10h] BYREF
  int v26; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 6u || (v13 = *(_QWORD *)(a1 + 17296) + 96LL * a2, v26 = 0, v24 = 0, v25 = 0, !v13) )
  {
    v20 = "%s: Session does not exist, Session_id: %d";
    v21 = "sme_validate_session_for_cap_update";
    v22 = a2;
    v23 = 2;
LABEL_10:
    qdf_trace_msg(0x34u, v23, v20, a5, a6, a7, a8, a9, a10, a11, a12, v21, v22);
    result = 4294967274LL;
    goto LABEL_11;
  }
  if ( !cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), a2) )
  {
    v20 = "%s: STA is not connected, Session_id: %d";
    v21 = "sme_validate_session_for_cap_update";
    v22 = a2;
    v23 = 8;
    goto LABEL_10;
  }
  v17 = *(_QWORD *)(a1 + 21632);
  v18 = (_BYTE *)(a1 + 20480);
  wlan_get_op_chan_freq_info_vdev_id(v17, a2, &v26, &v25, &v24);
  if ( a3 <= 2 )
  {
    if ( a3 == 1 )
    {
      if ( *(unsigned __int8 *)(v13 + 61) <= (unsigned int)a4 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: OMI Nss %d is > connected Nss %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "sme_set_he_om_ctrl_param",
          a4);
        result = 0;
        v18[1296] = 0;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Set OM ctrl Rx Nss cfg to %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "sme_set_he_om_ctrl_param",
          a4);
        result = 0;
        v18[1297] = a4;
        v18[1296] = 1;
      }
    }
    else
    {
      if ( a3 != 2 )
      {
LABEL_22:
        v20 = "%s: Invalid OMI param %d";
        v21 = "sme_set_he_om_ctrl_param";
        v23 = 8;
        v22 = (unsigned int)a3;
        goto LABEL_10;
      }
      if ( v24 >= a4 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Set OM ctrl BW cfg to %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "sme_set_he_om_ctrl_param");
        result = 0;
        v18[1295] = a4;
        v18[1294] = 1;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: OMI BW %d is > connected BW %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "sme_set_he_om_ctrl_param");
        result = 0;
        v18[1294] = 0;
      }
    }
  }
  else
  {
    if ( a3 == 5 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Set OM ctrl UL MU data dis to %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "sme_set_he_om_ctrl_param",
        a4);
      result = 0;
      v18[1301] = a4 != 0;
      goto LABEL_11;
    }
    if ( a3 != 4 )
    {
      if ( a3 == 3 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Set OM ctrl UL MU dis to %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "sme_set_he_om_ctrl_param",
          a4);
        result = 0;
        v18[1298] = a4 != 0;
        goto LABEL_11;
      }
      goto LABEL_22;
    }
    if ( *(unsigned __int8 *)(v13 + 61) <= (unsigned int)a4 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: OMI NSTS %d is > connected Nss %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "sme_set_he_om_ctrl_param",
        a4);
      result = 0;
      v18[1299] = 0;
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Set OM ctrl tx nsts cfg to %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "sme_set_he_om_ctrl_param",
        a4);
      result = 0;
      v18[1300] = a4;
      v18[1299] = 1;
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
