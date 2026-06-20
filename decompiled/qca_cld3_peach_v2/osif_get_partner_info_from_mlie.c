__int64 __fastcall osif_get_partner_info_from_mlie(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  int mlie; // w0
  __int64 result; // x0
  unsigned int v7; // w19
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 120);
  v8 = 0;
  v9[0] = 0;
  if ( v2 > 6 && (v3 = *(_QWORD *)(a1 + 128)) != 0 )
  {
    mlie = util_find_mlie(v3 + 6, v2 - 6, &v8, v9);
    if ( mlie || !v8 )
    {
      v7 = mlie;
      qdf_trace_msg(72, 8, "%s: ML IE not found %d", "osif_get_partner_info_from_mlie", mlie);
      goto LABEL_9;
    }
    qdf_trace_msg(72, 8, "%s: ML IE found length %d", "osif_get_partner_info_from_mlie", LODWORD(v9[0]));
    result = util_get_bvmlie_persta_partner_info(v8, v9[0], a2, 255);
    if ( (_DWORD)result )
    {
      v7 = result;
      qdf_trace_msg(72, 2, "%s: Unable to find per-sta profile in ML IE", "osif_get_partner_info_from_mlie");
LABEL_9:
      result = v7;
    }
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: Connect response is null return error", "osif_get_partner_info_from_mlie");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
