__int64 __fastcall target_if_encrypt_decrypt_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x20
  const char *v14; // x2
  __int64 result; // x0
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  __int64 v17; // [xsp+8h] [xbp-18h]
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v16 = 0;
  if ( a2 )
  {
    psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
    if ( psoc_from_scn_hdl )
    {
      v11 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
      if ( v11 && (v12 = *(_QWORD *)(v11 + 16)) != 0 )
      {
        v13 = psoc_from_scn_hdl;
        if ( !(unsigned int)wmi_extract_encrypt_decrypt_resp_params(v12) )
        {
          tgt_disa_encrypt_decrypt_resp(a3, a4, a5, a6, a7, a8, a9, a10, v13, (__int64)&v16);
          result = 0;
          goto LABEL_11;
        }
        v14 = "%s: Extraction of encrypt decrypt resp params failed";
      }
      else
      {
        v14 = "%s: Invalid wmi handle";
      }
    }
    else
    {
      v14 = "%s: psoc ptr is NULL";
    }
  }
  else
  {
    v14 = "%s: Invalid pointer";
  }
  qdf_trace_msg(
    0x49u,
    2u,
    v14,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_encrypt_decrypt_event_handler",
    v16,
    v17,
    v18,
    v19);
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
