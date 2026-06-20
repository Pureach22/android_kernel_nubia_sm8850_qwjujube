__int64 __fastcall wlan_dp_lb_set_default_affinity(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  __int64 **v15; // x0
  __int64 v16; // x8
  __int64 (*v17)(void); // x8
  unsigned __int8 v18; // w25
  unsigned int v19; // w26
  __int64 v20; // [xsp+0h] [xbp-10h] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  result = qdf_cpumask_empty((_DWORD *)(a1 + 2856));
  if ( (result & 1) == 0 )
  {
    qdf_cpumask_copy(&v20, (_QWORD *)(a1 + 2856));
    v11 = 0;
    while ( 1 )
    {
      v12 = *(_QWORD *)(a1 + 240);
      if ( v12 && *(_QWORD *)v12 && (v13 = *(_QWORD *)(*(_QWORD *)v12 + 152LL)) != 0 )
      {
        v14 = *(__int64 (**)(void))(v13 + 264);
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != -1653155309 )
            __break(0x8228u);
          result = v14();
          if ( (result & 1) != 0 )
            goto LABEL_3;
        }
        v15 = *(__int64 ***)(a1 + 240);
        if ( !v15 )
        {
LABEL_18:
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance",
            v3,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            "cdp_get_ext_grp_id_from_reo_num",
            v20,
            v21);
          goto LABEL_19;
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          1u,
          "%s invalid instance",
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          "cdp_ipa_check_is_ring_ipa_rx",
          v20,
          v21);
        v15 = *(__int64 ***)(a1 + 240);
        if ( !v15 )
          goto LABEL_18;
      }
      v16 = **v15;
      if ( v16 )
      {
        v17 = *(__int64 (**)(void))(v16 + 968);
        if ( v17 )
        {
          if ( *((_DWORD *)v17 - 1) != 2077786039 )
            __break(0x8228u);
          v18 = v17();
          goto LABEL_20;
        }
      }
LABEL_19:
      v18 = -22;
LABEL_20:
      v19 = qdf_cpumask_first(&v20);
      hif_check_and_apply_irq_affinity(*(_QWORD *)(a1 + 248), v18, v19);
      *(_BYTE *)(a1 + 2915 + v11) = v19;
      qdf_cpumask_clear_cpu(v19, (__int64)&v20);
      result = qdf_cpumask_empty(&v20);
      if ( (result & 1) != 0 )
        result = (__int64)qdf_cpumask_copy(&v20, (_QWORD *)(a1 + 2856));
LABEL_3:
      if ( ++v11 == 8 )
      {
        *(_BYTE *)(a1 + 2913) = 1;
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
