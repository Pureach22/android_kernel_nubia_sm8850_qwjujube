__int64 __fastcall sme_send_vdev_pause_for_bcn_period(__int64 a1, char a2, char a3)
{
  _BYTE *v5; // x0
  __int64 v6; // x19
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v5 = (_BYTE *)_qdf_mem_malloc(2u, "sme_send_vdev_pause_for_bcn_period", 16310);
  if ( !v5 )
    goto LABEL_4;
  v6 = (__int64)v5;
  *v5 = a2;
  v5[1] = a3;
  qdf_mem_set(&v16, 0x30u, 0);
  LODWORD(v16) = 5300;
  v17 = v6;
  result = scheduler_post_message_debug(
             0x34u,
             0x35u,
             53,
             (unsigned __int16 *)&v16,
             0x3FC2u,
             (__int64)"sme_send_vdev_pause_for_bcn_period");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Not able to post vdev pause indication",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "sme_send_vdev_pause_for_bcn_period");
    _qdf_mem_free(v6);
LABEL_4:
    result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
