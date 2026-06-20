__int64 __fastcall wma_mon_mlme_vdev_stop_resp(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _DWORD v11[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+10h] [xbp-30h]
  __int64 v13; // [xsp+18h] [xbp-28h]
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 520);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  LODWORD(v1) = *(unsigned __int8 *)(v1 + 168);
  v12 = 0;
  v11[0] = 5303;
  v11[1] = v1;
  result = scheduler_post_message_debug(
             0x36u,
             0x34u,
             52,
             (unsigned __int16 *)v11,
             0x13B3u,
             (__int64)"wma_mon_mlme_vdev_stop_resp");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Fail to post set vdev stop response",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wma_mon_mlme_vdev_stop_resp");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
