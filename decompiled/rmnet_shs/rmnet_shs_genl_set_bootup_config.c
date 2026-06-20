__int64 __fastcall rmnet_shs_genl_set_bootup_config(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x1
  int v5; // w1
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-58h] BYREF
  __int64 v8; // [xsp+10h] [xbp-50h]
  __int64 v9; // [xsp+18h] [xbp-48h]
  __int64 v10; // [xsp+20h] [xbp-40h]
  __int64 v11; // [xsp+28h] [xbp-38h]
  __int64 v12; // [xsp+30h] [xbp-30h]
  __int64 v13; // [xsp+38h] [xbp-28h]
  __int64 v14; // [xsp+40h] [xbp-20h]
  __int64 v15; // [xsp+48h] [xbp-18h]
  __int64 v16; // [xsp+50h] [xbp-10h]
  __int64 v17; // [xsp+58h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 32);
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v11 = 0;
    v12 = 0;
    v9 = 0;
    v10 = 0;
    v7 = 0;
    v8 = 0;
    v4 = *(_QWORD *)(v2 + 56);
    if ( v4 && (int)nla_memcpy(&v7, v4, 80) >= 1 )
    {
      HIBYTE(word_1949D) = BYTE4(v7);
      HIBYTE(dword_19499) = _sw_hweight64(BYTE4(v7));
      word_1948E = v7;
      LOBYTE(word_1949D) = ~HIBYTE(word_1949D);
      dword_19488 = HIDWORD(v16);
      dword_194A0 = v16;
      if ( (v7 & 2) != 0 )
        rmnet_shs_inst_rate_switch = 1;
      v5 = 539;
      rmnet_shs_cpu_rx_min_pps_thresh = (unsigned int)v8;
      qword_15CD8 = HIDWORD(v8);
      rmnet_shs_cpu_rx_max_pps_thresh = (_UNKNOWN *)(unsigned int)v12;
      off_15C98 = (_UNKNOWN *)HIDWORD(v12);
      qword_15CE0 = (unsigned int)v9;
      qword_15CE8 = HIDWORD(v9);
      qword_15CA0 = (unsigned int)v13;
      qword_15CA8 = HIDWORD(v13);
      qword_15CF0 = (unsigned int)v10;
      qword_15CF8 = HIDWORD(v10);
      qword_15D00 = (unsigned int)v11;
      qword_15D08 = HIDWORD(v11);
      qword_15CB0 = (unsigned int)v14;
      off_15CB8 = (_UNKNOWN *)HIDWORD(v14);
      off_15CC0 = (_UNKNOWN *)(unsigned int)v15;
      qword_15CC8 = HIDWORD(v15);
    }
    else
    {
      v5 = 530;
    }
    rmnet_shs_genl_send_int_to_userspace(a2, v5);
    result = 0;
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
