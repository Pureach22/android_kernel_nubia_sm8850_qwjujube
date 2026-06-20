__int64 __fastcall sme_qos_is_acm(
        __int64 a1,
        unsigned __int16 *a2,
        int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v14; // x8
  __int64 result; // x0
  unsigned int v16; // w19
  __int64 v17; // [xsp+0h] [xbp-10h] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  if ( a4 )
  {
    v17 = a4;
    v14 = a4;
    if ( *(_BYTE *)(a4 + 3426) )
      goto LABEL_8;
  }
  else
  {
    if ( (unsigned int)csr_get_parsed_bss_description_ies(a1, a2, &v17) )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: csr_get_parsed_bss_description_ies() failed",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "sme_qos_is_acm");
      result = 0;
      goto LABEL_24;
    }
    v14 = v17;
    if ( *(_BYTE *)(v17 + 3426) )
    {
LABEL_8:
      if ( a3 > 1 )
      {
        if ( a3 == 2 )
        {
          result = (*(unsigned __int16 *)(v14 + 3438) >> 4) & 1;
          if ( a4 )
            goto LABEL_24;
          goto LABEL_23;
        }
        if ( a3 == 3 )
        {
          result = (*(unsigned __int16 *)(v14 + 3442) >> 4) & 1;
          if ( a4 )
            goto LABEL_24;
          goto LABEL_23;
        }
      }
      else
      {
        if ( !a3 )
        {
          result = (*(unsigned __int16 *)(v14 + 3430) >> 4) & 1;
          if ( !a4 )
            goto LABEL_23;
          goto LABEL_24;
        }
        if ( a3 == 1 )
        {
          result = (*(unsigned __int16 *)(v14 + 3434) >> 4) & 1;
          if ( a4 )
            goto LABEL_24;
LABEL_23:
          v16 = result;
          _qdf_mem_free(v17);
          result = v16;
          goto LABEL_24;
        }
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: unknown AC = %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "sme_qos_is_acm",
        (unsigned int)a3,
        v17,
        v18);
      goto LABEL_18;
    }
  }
  if ( *(_BYTE *)(v14 + 3422) )
    goto LABEL_8;
LABEL_18:
  result = 0;
  if ( !a4 )
    goto LABEL_23;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
