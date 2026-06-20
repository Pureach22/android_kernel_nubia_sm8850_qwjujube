__int64 __fastcall hdd_config_power(
        __int64 *a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 v13; // x25
  __int64 v14; // x23
  __int64 v15; // x24
  __int64 v16; // x8
  _QWORD *v17; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  __int64 v27; // x20
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  unsigned int v38; // w22
  __int64 v39; // x4
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w22
  __int64 vdev_by_user; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x19
  __int64 v67; // x20
  __int64 v68; // x20
  unsigned int v69; // w23
  unsigned int v70; // w24
  __int64 v71; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v72; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v73; // [xsp+18h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a1;
  v12 = a2[25];
  v13 = a2[71];
  v14 = a2[101];
  v15 = a2[102];
  v17 = *(_QWORD **)(*a1 + 24);
  v16 = *(_QWORD *)(*a1 + 32);
  v71 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_power", v16 + 296);
  if ( !(v12 | v13) )
  {
    v27 = jiffies;
    if ( hdd_config_power___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: power attr and opm attr is null",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "hdd_config_power");
      result = 0;
      hdd_config_power___last_ticks = v27;
      goto LABEL_35;
    }
    goto LABEL_7;
  }
  if ( v12 && v13 )
  {
    v26 = jiffies;
    if ( hdd_config_power___last_ticks_441 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid OPM set attribute",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "hdd_config_power");
      hdd_config_power___last_ticks_441 = v26;
    }
    goto LABEL_34;
  }
  if ( !(unsigned int)ucfg_pmo_get_default_power_save_mode(*v17) )
  {
    v67 = jiffies;
    if ( hdd_config_power___last_ticks_443 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: OPM power save is disabled in ini",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "hdd_config_power");
      hdd_config_power___last_ticks_443 = v67;
    }
    goto LABEL_34;
  }
  if ( v12 )
    v37 = v12;
  else
    v37 = v13;
  v38 = *(unsigned __int8 *)(v37 + 4);
  v39 = *(unsigned __int8 *)(v37 + 4);
  v72 = v38;
  qdf_trace_msg(0x33u, 8u, "%s: opm_mode %d", v29, v30, v31, v32, v33, v34, v35, v36, "hdd_config_power", v39);
  if ( v38 == 2 && (!v14 || !v15) )
  {
    v68 = jiffies;
    if ( hdd_config_power___last_ticks_446 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid User defined OPM attributes",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "hdd_config_power");
      hdd_config_power___last_ticks_446 = v68;
    }
    goto LABEL_34;
  }
  result = hdd_set_power_config(v17, v11, &v72);
  if ( !(_DWORD)result )
  {
    v56 = v72;
    if ( v72 < 2 )
    {
      LODWORD(v71) = v72;
      goto LABEL_18;
    }
    if ( v72 == 2 )
    {
      v56 = 2;
      LODWORD(v71) = 2;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Invalid opm_mode: %d",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "hdd_vendor_opm_to_pmo_opm",
        v72);
      v56 = 0;
      LODWORD(v71) = 0;
      if ( v72 != 2 )
      {
LABEL_18:
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 86, "hdd_config_power");
        if ( vdev_by_user )
        {
          v66 = vdev_by_user;
          if ( v72 == 2 )
            ucfg_pmo_set_ps_params(vdev_by_user, &v71);
          else
            ucfg_pmo_core_vdev_set_ps_opm_mode(vdev_by_user, v56);
          _hdd_objmgr_put_vdev_by_user(v66, 86, "hdd_config_power");
        }
        else
        {
          qdf_trace_msg(0x33u, 2u, "%s: vdev is null", v58, v59, v60, v61, v62, v63, v64, v65, "hdd_config_power");
        }
LABEL_7:
        result = 0;
        goto LABEL_35;
      }
    }
    v69 = *(unsigned __int16 *)(v14 + 4);
    WORD2(v71) = v69;
    v70 = *(unsigned __int16 *)(v15 + 4);
    HIWORD(v71) = v70;
    if ( !v69 )
    {
LABEL_34:
      result = 4294967274LL;
      goto LABEL_35;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: ps_ito %d spec_wake %d opm_mode %d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "hdd_config_power",
      v69,
      v70,
      v56);
    result = hdd_set_power_config_params(v17, v11, v69, v70);
    if ( !(_DWORD)result )
      goto LABEL_18;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
