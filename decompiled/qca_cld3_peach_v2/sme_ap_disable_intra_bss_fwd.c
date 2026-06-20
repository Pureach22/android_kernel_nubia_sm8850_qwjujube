__int64 __fastcall sme_ap_disable_intra_bss_fwd(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 v6; // x0
  __int64 v7; // x22
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-38h] BYREF
  __int64 v10; // [xsp+10h] [xbp-30h]
  __int64 v11; // [xsp+18h] [xbp-28h]
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h]
  __int64 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v6 = _qdf_mem_malloc(3u, "sme_ap_disable_intra_bss_fwd", 9290);
  if ( v6 )
  {
    v7 = v6;
    *(_WORD *)v6 = a2;
    *(_BYTE *)(v6 + 2) = a3 & 1;
    if ( (unsigned int)qdf_mutex_acquire(a1 + 12848) )
    {
      _qdf_mem_free(v7);
      result = 16;
    }
    else
    {
      v10 = v7;
      LOWORD(v9) = 4317;
      scheduler_post_message_debug(
        0x34u,
        0x36u,
        54,
        (unsigned __int16 *)&v9,
        0x245Du,
        (__int64)"sme_ap_disable_intra_bss_fwd");
      qdf_mutex_release(a1 + 12848);
      result = 0;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
