__int64 __fastcall btfmcodec_frame_prepare_bearer_rsp_pkt(__int64 a1, char a2, char a3)
{
  __int64 result; // x0
  __int64 v4; // [xsp+Ch] [xbp-14h] BYREF
  char v5; // [xsp+14h] [xbp-Ch]
  char v6; // [xsp+15h] [xbp-Bh]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2;
  v6 = a3;
  v4 = 0x250000001LL;
  result = btfmcodec_dev_enqueue_pkt(a1, &v4, 0xAu);
  _ReadStatusReg(SP_EL0);
  return result;
}
