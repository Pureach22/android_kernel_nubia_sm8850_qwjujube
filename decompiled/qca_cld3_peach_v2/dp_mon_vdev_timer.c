__int64 __fastcall dp_mon_vdev_timer(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x9
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w23
  __int64 v22; // x25
  int v23; // w27
  int should_timer_irq_yield; // w0
  __int64 v25; // x22
  unsigned __int64 v26; // x28
  const char *v27; // x2
  const char *v28; // x3
  __int64 v29; // x8
  __int64 v30; // x8
  _DWORD *v31; // x8
  int v32; // w0
  __int64 v33; // x8
  __int64 v34; // x8
  _DWORD *v35; // x8
  __int64 v36; // x19
  __int64 v37; // x1
  __int64 v38; // x19
  __int64 v39; // [xsp+0h] [xbp-20h]
  __int64 StatusReg; // [xsp+8h] [xbp-18h]
  unsigned int v41; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 72);
  result = wlan_cfg_get_num_mac_rings(v2[36]);
  v41 = result;
  v12 = *(_QWORD *)(a1 + 20112);
  if ( !*(_DWORD *)(a1 + 56) )
    goto LABEL_36;
  __isb(0xFu);
  v39 = v12;
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  dp_update_num_mac_rings_for_dbs(a1, (int *)&v41, v4, v5, v6, v7, v8, v9, v10, v11);
  v21 = 0xFFFF;
  v22 = 0xFFFFFFFFLL;
  do
  {
    if ( v41 )
    {
      v25 = 0;
      v26 = 0;
      v23 = 0;
      while ( 1 )
      {
        if ( v26 == 3 )
          __break(0x5512u);
        v29 = v2[12057] + v25;
        if ( *(_DWORD *)(v29 + 32) != 3 )
          v22 = *(unsigned __int8 *)(v29 + 8);
        if ( v26 == v22 )
        {
          v30 = *(_QWORD *)(a1 + 20112);
          if ( !v30 )
          {
            v27 = "%s: monitor soc is NULL";
LABEL_32:
            v28 = "dp_monitor_process";
            goto LABEL_9;
          }
          v31 = *(_DWORD **)(v30 + 432);
          if ( !v31 )
          {
            v27 = "%s: callback not registered";
            goto LABEL_32;
          }
          if ( *(v31 - 1) != 208847759 )
            __break(0x8228u);
          v32 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v31)(
                  a1,
                  0,
                  (unsigned int)v26,
                  (unsigned int)v21);
          if ( !v32 )
            goto LABEL_10;
        }
        else
        {
          v33 = *(_QWORD *)(v2[1] + 20112LL);
          if ( !v33 )
          {
            v27 = "%s: monitor soc is NULL";
LABEL_8:
            v28 = "dp_monitor_drop_packets_for_mac";
LABEL_9:
            qdf_trace_msg(0x92u, 8u, v27, v13, v14, v15, v16, v17, v18, v19, v20, v28, v39);
            goto LABEL_10;
          }
          v34 = *(_QWORD *)(v33 + 416);
          if ( !v34 || (v35 = *(_DWORD **)(v34 + 232)) == nullptr )
          {
            v27 = "%s: callback not registered";
            goto LABEL_8;
          }
          if ( *(v35 - 1) != 1758040130 )
            __break(0x8228u);
          v32 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD))v35)(
                  v2,
                  (unsigned int)v26,
                  (unsigned int)v21,
                  0);
          if ( !v32 )
            goto LABEL_10;
        }
        v21 -= v32;
        if ( v21 < 1 )
          goto LABEL_34;
        v23 += v32;
LABEL_10:
        ++v26;
        v25 += 18528;
        if ( v26 >= v41 )
          goto LABEL_4;
      }
    }
    v23 = 0;
LABEL_4:
    should_timer_irq_yield = dp_should_timer_irq_yield(a1, v23, StatusReg);
  }
  while ( !should_timer_irq_yield );
  if ( (should_timer_irq_yield & 0xFFFFFFFE) == 2 )
  {
LABEL_34:
    v36 = jiffies;
    v37 = v36 + (unsigned int)qdf_timer_get_multiplier();
  }
  else
  {
    v38 = jiffies;
    v37 = v38 + 2LL * (unsigned int)qdf_timer_get_multiplier();
  }
  result = mod_timer(v39 + 352, v37);
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
