__int64 __fastcall dp_htt_hif_t2h_hp_callback(__int64 a1, __int64 a2, char a3)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v14; // x0
  _QWORD v15[2]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v16; // [xsp+18h] [xbp-68h]
  __int64 v17; // [xsp+20h] [xbp-60h]
  __int64 v18; // [xsp+28h] [xbp-58h]
  __int64 v19; // [xsp+30h] [xbp-50h]
  __int64 v20; // [xsp+38h] [xbp-48h]
  __int64 v21; // [xsp+40h] [xbp-40h]
  __int64 v22; // [xsp+48h] [xbp-38h]
  __int64 v23; // [xsp+50h] [xbp-30h]
  __int64 v24; // [xsp+58h] [xbp-28h]
  __int64 v25; // [xsp+60h] [xbp-20h]
  __int64 v26; // [xsp+68h] [xbp-18h]
  __int64 v27; // [xsp+70h] [xbp-10h]
  __int64 v28; // [xsp+78h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v15[0] = 0;
  v15[1] = 0;
  if ( a3 != 5 )
  {
    v14 = printk(
            &unk_AAA255,
            "pipe_id == 5",
            "dp_htt_hif_t2h_hp_callback",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c");
    dump_stack(v14);
  }
  qdf_mem_set(v15, 0x70u, 0);
  HIDWORD(v20) = 0;
  v16 = a2;
  dp_htt_t2h_msg_handler(a1, (__int64)v15, v5, v6, v7, v8, v9, v10, v11, v12);
  _ReadStatusReg(SP_EL0);
  return 0;
}
