__int64 __fastcall wlan_mgmt_txrx_vdev_drain(
        __int64 a1,
        void (*a2)(void),
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  __int64 comp_private_obj; // x0
  int v16; // w27
  __int64 v17; // x23
  int i; // w28
  __int64 v19; // x24
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x1
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned int v27; // w24
  _DWORD *v28; // x9
  __int64 v29; // x8
  _DWORD *v30; // x8
  __int64 v31; // x0
  unsigned int v32; // w19
  const char *v33; // x2

  if ( !a1 )
  {
    v32 = 4;
    v33 = "%s: vdev context is NULL";
LABEL_38:
    qdf_trace_msg(0x4Bu, 2u, v33, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mgmt_txrx_vdev_drain");
    return v32;
  }
  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 )
  {
    v32 = 4;
    v33 = "%s: pdev context is NULL";
    goto LABEL_38;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(*(_QWORD *)(a1 + 216), 1);
  if ( !comp_private_obj )
  {
    v32 = 16;
    v33 = "%s: mgmt txrx context is NULL";
    goto LABEL_38;
  }
  v16 = *(_DWORD *)(comp_private_obj + 28);
  v17 = comp_private_obj;
  if ( !v16 )
  {
    v32 = 16;
    v33 = "%s: pool size is 0";
    goto LABEL_38;
  }
  for ( i = 0; i != v16; ++i )
  {
    v19 = *(_QWORD *)(v17 + 32) + 72LL * i;
    if ( *(_BYTE *)(v19 + 65) == 1 )
    {
      v20 = *(_QWORD *)(v11 + 80);
      if ( v20 )
      {
        v21 = *(_QWORD *)(v20 + 2136);
        if ( !v21 )
          goto LABEL_6;
        v22 = *(__int64 (__fastcall **)(__int64, __int64))(v21 + 24);
        if ( v22 )
        {
          v23 = *(unsigned int *)(v19 + 40);
          if ( *((_DWORD *)v22 - 1) != 1891869479 )
            __break(0x8228u);
          v24 = v22(v11, v23);
          if ( v24 && *(_QWORD *)(v24 + 96) == a1 )
          {
            if ( a2 )
            {
              if ( *((_DWORD *)a2 - 1) != 1726064455 )
                __break(0x8234u);
              a2();
            }
            v25 = *(_QWORD *)(v11 + 80);
            if ( v25 )
            {
              v26 = *(_QWORD *)(v25 + 2136);
              v27 = *(_DWORD *)(v19 + 40);
              if ( v26 )
              {
                v28 = *(_DWORD **)v26;
                if ( *(_QWORD *)v26 )
                {
                  if ( *(v28 - 1) != 20594172 )
                    __break(0x8229u);
                  ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v28)(v11, v27, 0, a3);
                  continue;
                }
              }
              else
              {
                qdf_trace_msg(
                  0x38u,
                  2u,
                  "%s: rx_ops is NULL",
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  a11,
                  "wlan_lmac_if_get_mgmt_txrx_rx_ops");
                v29 = *(_QWORD *)(v11 + 80);
                if ( !v29 )
                  continue;
                v26 = *(_QWORD *)(v29 + 2136);
                if ( !v26 )
                {
LABEL_6:
                  qdf_trace_msg(
                    0x38u,
                    2u,
                    "%s: rx_ops is NULL",
                    a4,
                    a5,
                    a6,
                    a7,
                    a8,
                    a9,
                    a10,
                    a11,
                    "wlan_lmac_if_get_mgmt_txrx_rx_ops");
                  continue;
                }
              }
              v30 = *(_DWORD **)(v26 + 16);
              if ( v30 )
              {
                if ( *(v30 - 1) != 1475484239 )
                  __break(0x8228u);
                v31 = ((__int64 (__fastcall *)(__int64, _QWORD))v30)(v11, v27);
                if ( v31 )
                  _qdf_nbuf_free(v31);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
