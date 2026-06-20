void __fastcall lim_switch_channel_cback(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12)
{
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int16 *v23; // x21
  int v24; // w8
  __int64 v25; // x0
  int v26; // w8
  int v27; // w8
  __int64 v28; // x21
  __int16 v29; // w2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  __int64 v39; // [xsp+8h] [xbp-38h] BYREF
  __int64 v40; // [xsp+10h] [xbp-30h]
  __int64 v41; // [xsp+18h] [xbp-28h]
  __int64 v42; // [xsp+20h] [xbp-20h]
  __int64 v43; // [xsp+28h] [xbp-18h]
  __int64 v44; // [xsp+30h] [xbp-10h]
  __int64 v45; // [xsp+38h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  if ( a2 )
  {
    lim_tear_down_link_with_ap(a1, *(unsigned __int8 *)(a12 + 8), 0xFFFCu, 0);
    goto LABEL_14;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a12 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
  {
    v38 = "%s: vdev component object is NULL";
LABEL_13:
    qdf_trace_msg(0x35u, 2u, v38, v15, v16, v17, v18, v19, v20, v21, v22, "lim_switch_channel_cback");
    goto LABEL_14;
  }
  v23 = *(unsigned __int16 **)(*(_QWORD *)(cmpt_obj + 504) + 40LL);
  if ( !v23 )
  {
    v38 = "%s: des_chan is NULL";
    goto LABEL_13;
  }
  v24 = *(_DWORD *)(a12 + 88);
  *(_DWORD *)(a12 + 284) = *(_DWORD *)(a12 + 288);
  if ( v24 == 2 )
    *(_DWORD *)(a12 + 7196) = 0;
  LOWORD(v39) = 5143;
  v25 = _qdf_mem_malloc(0x2Cu, "lim_switch_channel_cback", 2113);
  if ( v25 )
  {
    *(_DWORD *)v25 = 2888727;
    *(_DWORD *)(v25 + 8) = *v23;
    *(_BYTE *)(v25 + 4) = *(_BYTE *)(a12 + 10);
    v26 = *((_DWORD *)v23 + 6);
    *(_DWORD *)(v25 + 12) = v26;
    if ( v26 )
    {
      *(_BYTE *)(v25 + 16) = *(_BYTE *)(a12 + 7211);
      *(_BYTE *)(v25 + 17) = *((_BYTE *)v23 + 3);
      *(_DWORD *)(v25 + 20) = *((_DWORD *)v23 + 4);
      *(_BYTE *)(v25 + 18) = *((_BYTE *)v23 + 4);
      *(_DWORD *)(v25 + 24) = *((_DWORD *)v23 + 5);
    }
    v27 = *((_DWORD *)v23 + 7);
    v28 = v25;
    *(_DWORD *)(v25 + 36) = 0;
    *(_DWORD *)(v25 + 40) = v27;
    qdf_mem_copy((void *)(v25 + 28), (const void *)(a12 + 24), 6u);
    v29 = *(_WORD *)(a12 + 8);
    v40 = v28;
    HIDWORD(v39) = 0;
    qdf_trace(53, 6u, v29, 5143);
    sys_process_mmh_msg(a1, &v39);
    wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(a12 + 16), 7u, 0x2A28u, a12, v30, v31, v32, v33, v34, v35, v36, v37);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
}
