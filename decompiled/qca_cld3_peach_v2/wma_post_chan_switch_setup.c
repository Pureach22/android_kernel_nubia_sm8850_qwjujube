__int64 __fastcall wma_post_chan_switch_setup(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _DWORD *v28; // x8
  unsigned __int16 *v29; // x20
  __int64 v30; // x8
  void (*v31)(void); // x8
  int v32; // w9
  _QWORD *v33; // x21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  __int64 result; // x0
  int v44; // w8
  __int64 v45; // x9
  _DWORD *v46; // x9
  int v47; // [xsp+8h] [xbp-38h] BYREF
  __int64 v48; // [xsp+Ch] [xbp-34h]
  __int64 v49; // [xsp+14h] [xbp-2Ch]
  int v50; // [xsp+1Ch] [xbp-24h]
  __int64 v51; // [xsp+20h] [xbp-20h]
  __int64 v52; // [xsp+28h] [xbp-18h]
  int v53; // [xsp+30h] [xbp-10h]
  __int64 v54; // [xsp+38h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_post_chan_switch_setup", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = _cds_get_context(71, (__int64)"wma_post_chan_switch_setup", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( context )
  {
    v28 = (_DWORD *)(context[65] + 488LL * (unsigned __int8)a1);
    if ( v28 )
    {
      if ( v28[41] != 4 )
      {
LABEL_26:
        result = 0;
        goto LABEL_27;
      }
      v29 = *(unsigned __int16 **)(*(_QWORD *)v28 + 40LL);
      if ( v19 && *v19 )
      {
        v30 = *(_QWORD *)(*v19 + 8LL);
        if ( v30 && (v31 = *(void (**)(void))(v30 + 40)) != nullptr )
        {
          v32 = *((unsigned __int8 *)v29 + 2);
          v48 = 0;
          v33 = v19;
          v49 = 0;
          v47 = v32;
          v50 = 0;
          if ( *((_DWORD *)v31 - 1) != -96731432 )
            __break(0x8228u);
          v31();
        }
        else
        {
          v33 = v19;
          qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", v20, v21, v22, v23, v24, v25, v26, v27);
        }
        v44 = *v29;
        v53 = 0;
        v51 = 0;
        v52 = 0;
      }
      else
      {
        v33 = v19;
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "cdp_txrx_set_vdev_param");
        v44 = *v29;
        v53 = 0;
        v51 = 0;
        v52 = 0;
        if ( !v33 )
        {
LABEL_24:
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "cdp_txrx_set_vdev_param");
          goto LABEL_26;
        }
      }
      if ( *v33 )
      {
        v45 = *(_QWORD *)(*v33 + 8LL);
        if ( v45 && (v46 = *(_DWORD **)(v45 + 40)) != nullptr )
        {
          v47 = v44;
          v48 = v51;
          v49 = v52;
          v50 = v53;
          if ( *(v46 - 1) != -96731432 )
            __break(0x8229u);
          ((void (__fastcall *)(_QWORD *, _QWORD, __int64, int *))v46)(v33, a1, 32, &v47);
        }
        else
        {
          qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", v34, v35, v36, v37, v38, v39, v40, v41);
        }
        goto LABEL_26;
      }
      goto LABEL_24;
    }
    v42 = "%s: wma txrx node is NULL";
  }
  else
  {
    v42 = "%s: wma is NULL";
  }
  qdf_trace_msg(0x35u, 2u, v42, v20, v21, v22, v23, v24, v25, v26, v27, "wma_post_chan_switch_setup");
  result = 16;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
