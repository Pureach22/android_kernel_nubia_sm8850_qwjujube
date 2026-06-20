__int64 __fastcall lim_send_beacon_ind(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  void *v14; // x0
  const void *v15; // x1
  void *v16; // x19
  __int64 result; // x0
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  void *v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = nullptr;
  if ( a2 )
  {
    v14 = (void *)_qdf_mem_malloc(6u, "lim_send_beacon_ind", 3782);
    if ( v14 )
    {
      v15 = (const void *)(a2 + 24);
      v16 = v14;
      qdf_mem_copy(v14, v15, 6u);
      v19 = v16;
      result = sch_process_pre_beacon_ind(a1, &v18, a3);
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Error:Unable to get the PESessionEntry",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_send_beacon_ind");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
