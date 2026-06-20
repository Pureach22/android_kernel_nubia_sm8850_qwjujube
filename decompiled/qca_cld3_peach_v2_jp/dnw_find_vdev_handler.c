void __fastcall dnw_find_vdev_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 priv_fl; // x0
  void (__fastcall *v14)(__int64, __int64, __int64, _BOOL8); // x9
  __int64 v15; // x8
  __int64 v16; // x21
  __int64 v17; // x1
  __int64 v18; // x2
  _BOOL8 v19; // x3
  __int64 v20; // x0
  unsigned __int8 v21; // w9
  const char *v22; // x2

  if ( !a10 )
  {
    v22 = "%s: invalid vdev";
LABEL_17:
    qdf_trace_msg(0x98u, 2u, v22, a1, a2, a3, a4, a5, a6, a7, a8, "dnw_find_vdev_handler");
    return;
  }
  if ( (*(_DWORD *)(a10 + 16) | 2) != 3 )
    return;
  priv_fl = pre_cac_vdev_get_priv_fl(a10, (__int64)"wlan_get_dnw_vdev_info", 0x24u);
  if ( !priv_fl )
  {
    qdf_trace_msg(0x98u, 2u, "%s: NULL pre cac vdev priv", a1, a2, a3, a4, a5, a6, a7, a8, "wlan_get_dnw_vdev_info");
    goto LABEL_16;
  }
  if ( !a11 )
  {
LABEL_16:
    v22 = "%s: NULL dnw vdev or pdev info";
    goto LABEL_17;
  }
  if ( *(_BYTE *)(priv_fl + 32) == 1 )
  {
    v14 = *(void (__fastcall **)(__int64, __int64, __int64, _BOOL8))(a11 + 224);
    v15 = a10;
    if ( v14 )
    {
      v16 = priv_fl;
      v17 = *(unsigned int *)(a11 + 16);
      v18 = *(unsigned int *)(a11 + 20);
      v19 = *(_DWORD *)(a11 + 28) == 2;
      v20 = *(_QWORD *)(priv_fl + 24);
      if ( *((_DWORD *)v14 - 1) != 729299638 )
        __break(0x8229u);
      v14(v20, v17, v18, v19);
      priv_fl = v16;
      v15 = a10;
    }
    *(_BYTE *)(priv_fl + 32) = 0;
    *(_QWORD *)(priv_fl + 24) = 0;
    v21 = *(_BYTE *)(a11 + 11);
    if ( v21 )
    {
      *(_BYTE *)(a11 + 11) = --v21;
      if ( !v21 )
      {
        *(_BYTE *)(a11 + 9) = 0;
        stop_dnw_timer(a11, a1, a2, a3, a4, a5, a6, a7, a8);
        v21 = *(_BYTE *)(a11 + 11);
        v15 = a10;
      }
    }
    qdf_trace_msg(
      0x98u,
      8u,
      "%s: dnw count %d, vdev %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlan_dnw_reset",
      v21,
      *(unsigned __int8 *)(v15 + 104));
  }
}
