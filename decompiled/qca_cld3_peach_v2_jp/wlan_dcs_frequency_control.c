__int64 __fastcall wlan_dcs_frequency_control(
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
  int v11; // w8
  const char *v12; // x2
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x22
  __int64 v17; // x23
  bool is_vdev_ll_lt_sap; // w0
  int v19; // w20
  __int64 v20; // x21
  unsigned int multiplier; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  int v32; // w9
  char v33; // w4
  __int64 v34; // x21
  __int64 (__fastcall *v35)(__int64, __int64 *, __int64); // x8
  __int64 v36; // x2
  __int64 v37; // [xsp+0h] [xbp-10h] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a2 + 272);
  v37 = 0;
  if ( v11 == 1 )
  {
    v12 = "%s: In the process of dcs disable, shouldn't go to here";
LABEL_12:
    result = qdf_trace_msg(0x74u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_dcs_frequency_control", v37, v38);
    goto LABEL_13;
  }
  v15 = *(_QWORD *)(a2 + 264);
  v16 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
  if ( v15 < *(unsigned __int8 *)(a2 + 176)
    || (v17 = a2,
        is_vdev_ll_lt_sap = policy_mgr_is_vdev_ll_lt_sap(a1, *(unsigned __int8 *)(a3 + 76)),
        v15 = *(_QWORD *)(v17 + 264),
        a2 = v17,
        is_vdev_ll_lt_sap)
    || v16 - *(_QWORD *)(v17 + 8LL * ((unsigned __int8)(v15 - *(_BYTE *)(v17 + 176)) % 0xAu) + 184) > 0x493DF )
  {
    *(_QWORD *)(a2 + 264) = v15 + 1;
    *(_QWORD *)(a2 + 8 * (v15 % 0xA) + 184) = v16;
    wlan_dcs_set_algorithm_process(a1, *(_DWORD *)(a3 + 72), 0, a4, a5, a6, a7, a8, a9, a10, a11);
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
    if ( !comp_private_obj )
    {
      v12 = "%s: dcs private psoc object is null";
      goto LABEL_12;
    }
    v32 = *(_DWORD *)(a3 + 68);
    v33 = *(_BYTE *)(a3 + 76);
    v34 = comp_private_obj;
    LODWORD(v37) = *(_DWORD *)(a3 + 72);
    BYTE4(v37) = v33;
    BYTE5(v37) = v32;
    qdf_trace_msg(
      0x74u,
      4u,
      "%s: vdev %d: start dcs callback handler",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_dcs_frequency_control",
      v37,
      v38);
    v35 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v34 + 1152);
    v36 = *(_QWORD *)(v34 + 1160);
    if ( *((_DWORD *)v35 - 1) != 1380631204 )
      __break(0x8228u);
    result = v35(a1, &v37, v36);
  }
  else
  {
    wlan_dcs_set_algorithm_process(a1, *(_DWORD *)(a3 + 72), 0, a4, a5, a6, a7, a8, a9, a10, a11);
    *(_QWORD *)(v17 + 336) = a1;
    v19 = *(_DWORD *)(v17 + 180);
    *(_BYTE *)(v17 + 272) = 1;
    *(_DWORD *)(v17 + 344) = *(_DWORD *)(a3 + 72);
    v20 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    *(_QWORD *)(v17 + 296) = v20 + _msecs_to_jiffies((unsigned int)(60000 * v19)) * multiplier;
    add_timer(v17 + 280);
    result = qdf_trace_msg(
               0x74u,
               4u,
               "%s: vdev %d start dcs disable timer",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "wlan_dcs_frequency_control",
               *(unsigned __int8 *)(a3 + 76),
               v37,
               v38);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
