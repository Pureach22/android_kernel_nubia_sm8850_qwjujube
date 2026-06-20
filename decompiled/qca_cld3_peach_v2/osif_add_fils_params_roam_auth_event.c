__int64 __fastcall osif_add_fils_params_roam_auth_event(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  __int64 result; // x0
  __int16 v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a2 + 112);
  if ( (_DWORD)v4 && (unsigned int)nla_put(a1, 11, v4, a2 + 116) )
  {
    qdf_trace_msg(72, 2, "%s: pmk send fail", "osif_add_fils_params_roam_auth_event");
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( (unsigned int)nla_put(a1, 12, 16, a2 + 180) )
  {
    qdf_trace_msg(72, 2, "%s: pmkid send fail", "osif_add_fils_params_roam_auth_event");
    goto LABEL_6;
  }
  qdf_trace_msg(
    72,
    8,
    "%s: Update ERP Seq Num %d, Next ERP Seq Num %d",
    "osif_add_fils_params_roam_auth_event",
    *(unsigned __int8 *)(a2 + 196),
    *(unsigned __int16 *)(a2 + 198));
  if ( *(_BYTE *)(a2 + 196) != 1 )
  {
    result = 0;
    goto LABEL_7;
  }
  v6 = *(_WORD *)(a2 + 198);
  result = nla_put(a1, 13, 2, &v6);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(72, 2, "%s: ERP seq num send fail", "osif_add_fils_params_roam_auth_event");
    goto LABEL_6;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
