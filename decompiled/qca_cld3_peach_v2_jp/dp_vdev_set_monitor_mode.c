__int64 __fastcall dp_vdev_set_monitor_mode(__int64 a1, __int64 a2, char a3)
{
  __int64 ref_by_id_4; // x0
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int8 *v15; // x21
  __int64 v16; // x20
  __int64 v17; // x23
  __int64 v18; // x24
  __int64 v19; // x0
  unsigned int v20; // w22
  __int64 (__fastcall *v22)(_QWORD); // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 (__fastcall *v33)(_QWORD); // x8
  const char *v34; // x2
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 (__fastcall *v37)(_QWORD); // x8
  __int64 v38; // x0
  const char *v39; // x2
  __int64 v40; // x8
  __int64 (__fastcall *v41)(unsigned __int8 *, __int64); // x8
  unsigned int (__fastcall *v42)(_QWORD); // x8

  ref_by_id_4 = dp_vdev_get_ref_by_id_4();
  if ( !ref_by_id_4 )
    return 16;
  v15 = *(unsigned __int8 **)(ref_by_id_4 + 24);
  v16 = ref_by_id_4;
  if ( !v15 || (v6 = 95560, (v17 = *((_QWORD *)v15 + 11945)) == 0) )
  {
    v20 = 16;
    goto LABEL_7;
  }
  *(_DWORD *)(v17 + 18552) = 0xFFFF;
  v18 = *((_QWORD *)v15 + 11945);
  *(_DWORD *)(v18 + 24) = 0xFFFF;
  *(_QWORD *)(v18 + 16) = ref_by_id_4;
  *(_BYTE *)(v18 + 9) = *(_BYTE *)(ref_by_id_4 + 59);
  v19 = qdf_trace_msg(
          0x3Fu,
          3u,
          "pdev=%pK, pdev_id=%d, soc=%pK vdev=%pK\n",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          *v15,
          *((_QWORD *)v15 + 1),
          ref_by_id_4);
  if ( !a3 )
  {
    if ( *(_BYTE *)v17 == 1 )
    {
      qdf_trace_msg(0x3Fu, 8u, "monitor vap already created vdev=%pK\n", v7, v8, v9, v10, v11, v12, v13, v14, v16);
      v20 = 1;
      goto LABEL_7;
    }
    *(_BYTE *)v17 = 1;
    v22 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1624LL);
    if ( *((_DWORD *)v22 - 1) != 799902358 )
      __break(0x8228u);
    *(_BYTE *)(v17 + 39316) = v22(v19);
    v31 = *(_QWORD *)(*((_QWORD *)v15 + 1) + 20056LL);
    if ( v31 )
    {
      v32 = *(_QWORD *)(v31 + 416);
      if ( v32 && *(_QWORD *)(v32 + 984) )
      {
        v33 = *(__int64 (__fastcall **)(_QWORD))(v32 + 992);
        if ( *((_DWORD *)v33 - 1) != 337690155 )
          __break(0x8228u);
        if ( (v33(v15) & 1) != 0 )
          goto LABEL_5;
LABEL_24:
        v35 = *(_QWORD *)(*((_QWORD *)v15 + 1) + 20056LL);
        if ( v35 )
        {
          v36 = *(_QWORD *)(v35 + 416);
          if ( v36 )
          {
            v37 = *(__int64 (__fastcall **)(_QWORD))(v36 + 984);
            if ( v37 )
            {
              if ( *((_DWORD *)v37 - 1) != -1557217772 )
                __break(0x8228u);
              v38 = v37(v15);
LABEL_33:
              v40 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
              if ( v40 )
              {
                v41 = *(__int64 (__fastcall **)(unsigned __int8 *, __int64))(v40 + 32);
                if ( v41 )
                {
                  if ( *((_DWORD *)v41 - 1) != 381362779 )
                    __break(0x8228u);
                  v38 = v41(v15, 1);
                }
              }
              if ( *(_BYTE *)(*(_QWORD *)(a1 + 40) + 817LL) != 1 )
                goto LABEL_44;
              v42 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 200LL);
              if ( !v42 )
                goto LABEL_44;
              if ( *((_DWORD *)v42 - 1) != 1696218653 )
                __break(0x8228u);
              if ( v42(v38) || (v6 = *(unsigned __int8 *)(a1 + 20216), (v6 & 0x10) != 0) )
              {
LABEL_44:
                dp_mon_filter_setup_mon_mode(v15);
                v20 = dp_mon_filter_update(v15);
                if ( v20 )
                {
                  qdf_trace_msg(
                    0x89u,
                    2u,
                    "%s: %pK: Failed to reset monitor filters",
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    v13,
                    v14,
                    "dp_vdev_set_monitor_mode",
                    a1);
                  dp_mon_filter_reset_mon_mode(v15);
                  v6 = 255;
                  *(_BYTE *)v17 = 0;
                  *(_QWORD *)(v18 + 16) = 0;
                  *(_BYTE *)(v18 + 9) = -1;
                }
                goto LABEL_7;
              }
              goto LABEL_5;
            }
          }
          v39 = "%s: callback not registered";
        }
        else
        {
          v39 = "%s: monitor soc is NULL";
        }
        v38 = qdf_trace_msg(0x92u, 8u, v39, v7, v8, v9, v10, v11, v12, v13, v14, "dp_monitor_lite_mon_disable_rx");
        goto LABEL_33;
      }
      v34 = "%s: callback not registered";
    }
    else
    {
      v34 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(0x92u, 8u, v34, v23, v24, v25, v26, v27, v28, v29, v30, "dp_monitor_lite_mon_is_rx_adv_filter_enable");
    goto LABEL_24;
  }
LABEL_5:
  v20 = 0;
LABEL_7:
  dp_vdev_unref_delete(a1, v16, 7u, (unsigned int *)v6, v7, v8, v9, v10, v11, v12, v13, v14);
  return v20;
}
