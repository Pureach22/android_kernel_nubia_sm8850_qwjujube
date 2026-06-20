__int64 __fastcall cam_soc_util_set_sw_client_rate_through_mmrm(
        const void *a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  unsigned int v8; // w20
  const void *v10; // x20
  __int64 v11; // x22
  __int64 v13; // [xsp+18h] [xbp-38h] BYREF
  __int64 v14; // [xsp+20h] [xbp-30h]
  __int64 v15; // [xsp+28h] [xbp-28h]
  int v16; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v17; // [xsp+38h] [xbp-18h]
  __int64 v18; // [xsp+40h] [xbp-10h]
  __int64 v19; // [xsp+48h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v14 = 0;
  v15 = 0;
  v13 = 0;
  v16 = a5;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    v10 = a1;
    v11 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_set_sw_client_rate_through_mmrm",
      995,
      "sw client mmrm=%pK, nrt=%d, min_rate=%ld req_rate %ld, num_blocks=%d",
      a1,
      a2 & 1,
      a3,
      a4,
      a5);
    a3 = v11;
    a1 = v10;
    if ( (a2 & 1) != 0 )
    {
LABEL_4:
      v13 = a3;
      v14 = a4;
      v8 = mmrm_client_set_value_in_range(a1, &v16, &v13);
      if ( !v8 )
        goto LABEL_9;
      goto LABEL_8;
    }
  }
  else if ( (a2 & 1) != 0 )
  {
    goto LABEL_4;
  }
  v8 = mmrm_client_set_value(a1, &v16, a4, a4, a5, a6, a7);
  if ( v8 )
LABEL_8:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_sw_client_rate_through_mmrm",
      1011,
      "Set rate failed rate %ld rc %d",
      a4,
      v8);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v8;
}
