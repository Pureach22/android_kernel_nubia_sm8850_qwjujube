__int64 __fastcall sme_set_wisa_params(__int64 a1, _WORD *a2)
{
  unsigned int v4; // w21
  _WORD *v5; // x0
  __int64 v6; // x20
  __int64 v8; // [xsp+8h] [xbp-38h] BYREF
  __int64 v9; // [xsp+10h] [xbp-30h]
  __int64 v10; // [xsp+18h] [xbp-28h]
  __int64 v11; // [xsp+20h] [xbp-20h]
  __int64 v12; // [xsp+28h] [xbp-18h]
  __int64 v13; // [xsp+30h] [xbp-10h]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v4 = 2;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  v5 = (_WORD *)_qdf_mem_malloc(2u, "sme_set_wisa_params", 10209);
  if ( v5 )
  {
    v6 = (__int64)v5;
    *v5 = *a2;
    if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
    {
      _qdf_mem_free(v6);
      v4 = 16;
    }
    else
    {
      v9 = v6;
      LOWORD(v8) = 4471;
      v4 = scheduler_post_message_debug(
             0x34u,
             0x36u,
             54,
             (unsigned __int16 *)&v8,
             0x27F0u,
             (__int64)"sme_set_wisa_params");
      if ( v4 )
        _qdf_mem_free(v6);
      qdf_mutex_release(a1 + 12776);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
