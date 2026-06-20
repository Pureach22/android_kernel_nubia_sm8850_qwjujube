__int64 __fastcall hdd_fix_features(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 **context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  unsigned int (*v22)(void); // x8
  __int64 **v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  unsigned int (__fastcall *v33)(__int64 **, __int64); // x8
  __int64 v34; // x22
  const char *v35; // x2
  const char *v36; // x3
  unsigned int v37; // w0
  unsigned int v38; // w1
  char is_legacy_connection; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x4
  __int64 v49; // x5
  _QWORD v51[2]; // [xsp+0h] [xbp-10h] BYREF

  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 0;
  if ( !(unsigned int)_osif_vdev_sync_op_start(a1, v51, "hdd_fix_features") )
  {
    if ( (*(_BYTE *)(a1 + 55153) & 1) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Not triggered by hdd_netdev_update_features",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "__hdd_fix_features");
LABEL_26:
      _osif_vdev_sync_op_stop(v51[0], "hdd_fix_features");
      a2 = (int)a2;
      goto LABEL_27;
    }
    context = (__int64 **)_cds_get_context(
                            71,
                            (__int64)"hdd_get_tso_csum_feature_flags",
                            v4,
                            v5,
                            v6,
                            v7,
                            v8,
                            v9,
                            v10,
                            v11);
    if ( context )
    {
      if ( *context )
      {
        v21 = **context;
        if ( v21 )
        {
          v22 = *(unsigned int (**)(void))(v21 + 264);
          if ( v22 )
          {
            v23 = context;
            if ( *((_DWORD *)v22 - 1) != -1095293032 )
              __break(0x8228u);
            if ( v22() )
            {
              if ( *v23 )
              {
                v32 = **v23;
                if ( v32 )
                {
                  v33 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v32 + 264);
                  if ( v33 )
                  {
                    if ( *((_DWORD *)v33 - 1) != -1095293032 )
                      __break(0x8228u);
                    if ( v33(v23, 5) )
                    {
                      v34 = 1114131;
LABEL_22:
                      is_legacy_connection = hdd_is_legacy_connection(*(_QWORD *)(a1 + 55520));
                      v48 = *(unsigned int *)(a1 + 2728);
                      v49 = *(_QWORD *)(a1 + 184);
                      if ( (is_legacy_connection & 1) != 0 )
                        a2 &= ~v34;
                      else
                        a2 |= v34;
                      *(_BYTE *)(a1 + 55154) = (is_legacy_connection & 1) == 0;
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: vdev mode %d current features 0x%llx, requesting feature change 0x%llx",
                        v40,
                        v41,
                        v42,
                        v43,
                        v44,
                        v45,
                        v46,
                        v47,
                        "__hdd_fix_features",
                        v48,
                        v49,
                        a2);
                      goto LABEL_26;
                    }
                  }
                }
              }
              else
              {
                qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v24, v25, v26, v27, v28, v29, v30, v31, "cdp_cfg_get");
              }
              v34 = 18;
              goto LABEL_22;
            }
          }
        }
LABEL_21:
        v34 = 0;
        goto LABEL_22;
      }
      v35 = "%s: Invalid Instance";
      v36 = "cdp_cfg_get";
      v37 = 137;
      v38 = 8;
    }
    else
    {
      v35 = "%s: soc handle is NULL";
      v36 = "hdd_get_tso_csum_feature_flags";
      v37 = 51;
      v38 = 2;
    }
    qdf_trace_msg(v37, v38, v35, v13, v14, v15, v16, v17, v18, v19, v20, v36);
    goto LABEL_21;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return a2;
}
