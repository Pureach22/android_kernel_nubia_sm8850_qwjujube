__int64 __fastcall extract_reg_fcc_rules_tlv(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  __int64 v14; // x8
  __int64 v15; // x21
  __int64 v16; // x22
  __int64 v17; // x8
  unsigned int v18; // w20
  unsigned __int16 *v19; // x8

  *(_DWORD *)(a3 + 352) = 0;
  if ( *(_QWORD *)(a1 + 48) )
  {
    v12 = *(unsigned int *)(a1 + 56);
    if ( (unsigned int)v12 >= 3 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Number of fcc rules is greater than MAX_NUM_FCC_RULES",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "extract_reg_fcc_rules_tlv");
      return 4;
    }
    v14 = a2 + 20LL * *(unsigned int *)(a1 + 24) + 8LL * *(unsigned int *)(a1 + 40);
    v15 = v14 + 324;
    if ( v14 == -328 )
    {
      v17 = 0;
    }
    else
    {
      v16 = a1;
      v17 = _qdf_mem_malloc(4 * v12, "extract_ext_fcc_rules_from_wmi", 17471);
      if ( v17 && (_DWORD)v12 )
      {
        a1 = v16;
        *(_WORD *)v17 = *(_DWORD *)(v15 + 8);
        *(_BYTE *)(v17 + 2) = *(_WORD *)(v15 + 10);
        if ( (_DWORD)v12 != 1 )
        {
          *(_WORD *)(v17 + 4) = *(_DWORD *)(v15 + 16);
          *(_BYTE *)(v17 + 6) = *(_WORD *)(v15 + 18);
        }
      }
      else
      {
        a1 = v16;
      }
    }
    *(_QWORD *)(a3 + 344) = v17;
    *(_DWORD *)(a3 + 352) = *(_DWORD *)(a1 + 56);
    if ( v17 )
      goto LABEL_14;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Fcc rules not sent by fw",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_reg_fcc_rules_tlv");
    if ( *(_QWORD *)(a3 + 344) )
    {
LABEL_14:
      if ( *(_DWORD *)(a3 + 352) )
      {
        v18 = 0;
        do
        {
          v19 = (unsigned __int16 *)(*(_QWORD *)(a3 + 344) + 4LL * (int)v18);
          qdf_trace_msg(
            0x31u,
            8u,
            "FCC rule %d center_freq %d tx_power %d",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            v18++,
            *v19,
            *((unsigned __int8 *)v19 + 2));
        }
        while ( v18 < *(_DWORD *)(a3 + 352) );
      }
    }
  }
  return 0;
}
