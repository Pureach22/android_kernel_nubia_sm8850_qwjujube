__int64 __fastcall wlan_mlo_vdev_aid_mgr_deinit(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x8
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  unsigned int v30; // w9
  unsigned int v31; // w9
  unsigned int v33; // w9
  unsigned int v34; // w9

  v9 = *(_QWORD *)(*(_QWORD *)(result + 2232) + 8LL);
  if ( v9 )
  {
    v10 = *(_QWORD *)(v9 + 264);
    v11 = result;
    if ( v10 )
    {
      qdf_trace_msg(
        0x8Fu,
        4u,
        "%s: AID mgr ref cnt %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_mlo_vdev_aid_mgr_deinit",
        *(unsigned int *)(v10 + 260));
      v20 = *(_QWORD *)(v9 + 264);
      if ( v20 )
      {
        _X8 = (unsigned int *)(v20 + 260);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v30 = __ldxr(_X8);
          v31 = v30 - 1;
        }
        while ( __stlxr(v31, _X8) );
        __dmb(0xBu);
        if ( !v31 )
        {
          *(_WORD *)(v20 + 258) = 0;
          _qdf_mem_free(v20);
        }
      }
      *(_QWORD *)(v9 + 264) = 0;
      v22 = *(_QWORD *)(v9 + 272);
      if ( v22 )
        goto LABEL_6;
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ID %d, doesn't have associated AID mgr",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_mlo_vdev_aid_mgr_deinit",
        0);
      v22 = *(_QWORD *)(v9 + 272);
      if ( v22 )
      {
LABEL_6:
        qdf_trace_msg(
          0x8Fu,
          4u,
          "%s: AID mgr ref cnt %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_mlo_vdev_aid_mgr_deinit",
          *(unsigned int *)(v22 + 260));
        v23 = *(_QWORD *)(v9 + 272);
        if ( v23 )
        {
          _X8 = (unsigned int *)(v23 + 260);
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v33 = __ldxr(_X8);
            v34 = v33 - 1;
          }
          while ( __stlxr(v34, _X8) );
          __dmb(0xBu);
          if ( !v34 )
          {
            *(_WORD *)(v23 + 258) = 0;
            _qdf_mem_free(v23);
          }
        }
        *(_QWORD *)(v9 + 272) = 0;
        goto LABEL_11;
      }
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: ID %d, doesn't have associated AID mgr",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_mlo_vdev_aid_mgr_deinit",
      1);
LABEL_11:
    result = _qdf_mem_free(v9);
    *(_QWORD *)(*(_QWORD *)(v11 + 2232) + 8LL) = 0;
  }
  return result;
}
