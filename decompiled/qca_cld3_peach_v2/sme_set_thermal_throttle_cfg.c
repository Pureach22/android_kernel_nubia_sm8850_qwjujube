__int64 __fastcall sme_set_thermal_throttle_cfg(__int64 a1, const void *a2)
{
  void *v4; // x0
  void *v5; // x20
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w20
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  void *v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = nullptr;
  v4 = (void *)_qdf_mem_malloc(0xA8u, "sme_set_thermal_throttle_cfg", 16821);
  if ( v4 )
  {
    v5 = v4;
    qdf_mem_set(v4, 0xA8u, 0);
    qdf_mem_copy(v5, a2, 0xA8u);
    qdf_mem_set(&v17, 0x30u, 0);
    v18 = v5;
    LODWORD(v17) = 4537;
    qdf_mutex_acquire(a1 + 12848);
    v6 = scheduler_post_message_debug(
           0x34u,
           0x36u,
           54,
           (unsigned __int16 *)&v17,
           0x41C4u,
           (__int64)"sme_set_thermal_throttle_cfg");
    if ( v6 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: failed to schedule throttle config req %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "sme_set_thermal_throttle_cfg",
        v6);
      _qdf_mem_free((__int64)v5);
      v15 = 16;
    }
    else
    {
      v15 = 0;
    }
    qdf_mutex_release(a1 + 12848);
  }
  else
  {
    v15 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v15;
}
