__int64 __fastcall lim_switch_channel_cback(
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
  __int64 result; // x0
  __int64 cmpt_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int16 *v24; // x21
  int v25; // w8
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
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD))lim_tear_down_link_with_ap)(
               a1,
               *(unsigned __int8 *)(a12 + 8),
               65532,
               0);
    goto LABEL_14;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a12 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
  {
    v38 = "%s: vdev component object is NULL";
LABEL_13:
    result = qdf_trace_msg(0x35u, 2u, v38, v16, v17, v18, v19, v20, v21, v22, v23, "lim_switch_channel_cback");
    goto LABEL_14;
  }
  v24 = *(unsigned __int16 **)(*(_QWORD *)(cmpt_obj + 520) + 40LL);
  if ( !v24 )
  {
    v38 = "%s: des_chan is NULL";
    goto LABEL_13;
  }
  v25 = *(_DWORD *)(a12 + 88);
  *(_DWORD *)(a12 + 284) = *(_DWORD *)(a12 + 288);
  if ( v25 == 2 )
    *(_DWORD *)(a12 + 7196) = 0;
  LOWORD(v39) = 5143;
  result = _qdf_mem_malloc(0x34u, "lim_switch_channel_cback", 2113);
  if ( result )
  {
    *(_DWORD *)result = 3413015;
    *(_DWORD *)(result + 8) = *v24;
    *(_BYTE *)(result + 4) = *(_BYTE *)(a12 + 10);
    v26 = *((_DWORD *)v24 + 6);
    *(_DWORD *)(result + 12) = v26;
    if ( v26 )
    {
      *(_BYTE *)(result + 16) = *(_BYTE *)(a12 + 7211);
      *(_BYTE *)(result + 17) = *((_BYTE *)v24 + 3);
      *(_DWORD *)(result + 20) = *((_DWORD *)v24 + 4);
      *(_BYTE *)(result + 18) = *((_BYTE *)v24 + 4);
      *(_DWORD *)(result + 24) = *((_DWORD *)v24 + 5);
    }
    v27 = *((_DWORD *)v24 + 7);
    v28 = result;
    *(_DWORD *)(result + 44) = 0;
    *(_DWORD *)(result + 48) = v27;
    qdf_mem_copy((void *)(result + 36), (const void *)(a12 + 24), 6u);
    v29 = *(_WORD *)(a12 + 8);
    v40 = v28;
    HIDWORD(v39) = 0;
    qdf_trace(53, 6u, v29, 5143);
    sys_process_mmh_msg(a1, &v39);
    result = wlan_vdev_mlme_sm_deliver_evt(
               *(_QWORD *)(a12 + 16),
               7u,
               0x36B0u,
               a12,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
