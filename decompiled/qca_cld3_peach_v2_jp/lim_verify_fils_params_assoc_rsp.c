__int64 __fastcall lim_verify_fils_params_assoc_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
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
  char v12; // w10
  _BYTE *v13; // x20
  const char *v18; // x2
  __int64 result; // x0
  void *v20; // x0
  __int64 v21; // x23
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  char v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_BYTE *)(a3 + 2756);
  v13 = *(_BYTE **)(a2 + 9976);
  v22 = *(_QWORD *)(a3 + 2748);
  v23 = v12;
  if ( *v13 != 1 )
    goto LABEL_20;
  if ( !v13 )
  {
    v18 = "%s: FILS Info not present";
    goto LABEL_8;
  }
  if ( !*(_BYTE *)(a3 + 2748) )
  {
    v18 = "%s: FILS IE not present";
    goto LABEL_8;
  }
  if ( !(unsigned int)qdf_mem_cmp(v13 + 70, (char *)&v22 + 1, 8u) )
  {
    v20 = (void *)_qdf_mem_malloc(0x101u, "lim_verify_fils_params_assoc_rsp", 2350);
    if ( !v20 )
    {
      v18 = "%s: malloc failed for fils_key_auth";
      goto LABEL_8;
    }
    v21 = (__int64)v20;
    memcpy(v20, (const void *)(a3 + 2757), 0x101u);
    if ( *(unsigned __int8 *)(v21 + 1) != (unsigned __int8)v13[1020]
      || (unsigned int)qdf_mem_cmp(v13 + 1021, (const void *)(v21 + 2), (unsigned __int8)v13[1069]) )
    {
      _qdf_mem_free(v21);
      goto LABEL_9;
    }
    _qdf_mem_free(v21);
    if ( !*(_BYTE *)(a3 + 3023) )
    {
      v18 = "%s: FILS KDE list absent";
      goto LABEL_8;
    }
    if ( (unsigned int)lim_parse_kde_elements(a1, v13, a3 + 3024) )
    {
      v18 = "%s: KDE parsing fails";
      goto LABEL_8;
    }
    lim_update_fils_hlp_data(
      (int *)(a3 + 3279),
      (int *)(a3 + 3285),
      *(_WORD *)(a3 + 3292),
      (const void *)(a3 + 3294),
      a2,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12);
LABEL_20:
    result = 1;
    goto LABEL_21;
  }
  v18 = "%s: FILS session mismatch";
LABEL_8:
  qdf_trace_msg(0x35u, 2u, v18, a5, a6, a7, a8, a9, a10, a11, a12, "lim_verify_fils_params_assoc_rsp");
LABEL_9:
  result = 0;
  *(_DWORD *)a4 = 516;
  *(_WORD *)(a4 + 4) = 1;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
