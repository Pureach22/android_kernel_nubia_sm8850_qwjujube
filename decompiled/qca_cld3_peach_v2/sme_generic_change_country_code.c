__int64 __fastcall sme_generic_change_country_code(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  _DWORD *v13; // x0
  __int64 v14; // x20
  unsigned int v15; // w20
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
  if ( a1 )
  {
    result = qdf_mutex_acquire(a1 + 12848);
    if ( !(_DWORD)result )
    {
      v13 = (_DWORD *)_qdf_mem_malloc(8u, "sme_generic_change_country_code", 3997);
      if ( v13 )
      {
        v14 = (__int64)v13;
        *v13 = 529464;
        qdf_mem_copy(v13 + 1, a2, 2u);
        *(_BYTE *)(v14 + 6) = 32;
        LODWORD(v16) = 5176;
        v17 = v14;
        if ( (unsigned int)scheduler_post_message_debug(
                             0x34u,
                             0x34u,
                             52,
                             (unsigned __int16 *)&v16,
                             0xFB0u,
                             (__int64)"sme_generic_change_country_code") )
        {
          _qdf_mem_free(v14);
          v15 = 16;
        }
        else
        {
          v15 = 0;
        }
        qdf_mutex_release(a1 + 12848);
        result = v15;
      }
      else
      {
        qdf_mutex_release(a1 + 12848);
        result = 2;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: mac is null", a3, a4, a5, a6, a7, a8, a9, a10, "sme_generic_change_country_code");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
