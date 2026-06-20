__int64 __fastcall ml_nlink_all_links_ready_for_state_change(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v14; // w8
  __int64 result; // x0
  bool is_link_switch_in_progress; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  const char *v26; // x2
  bool v27; // w0
  unsigned int v28; // [xsp+10h] [xbp-60h] BYREF
  _BYTE v29[4]; // [xsp+14h] [xbp-5Ch] BYREF
  int v30; // [xsp+18h] [xbp-58h] BYREF
  char v31; // [xsp+1Ch] [xbp-54h]
  int v32; // [xsp+20h] [xbp-50h] BYREF
  char v33; // [xsp+24h] [xbp-4Ch]
  _QWORD v34[5]; // [xsp+28h] [xbp-48h] BYREF
  _QWORD v35[2]; // [xsp+50h] [xbp-20h] BYREF
  int v36; // [xsp+60h] [xbp-10h]
  __int64 v37; // [xsp+68h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v33 = 0;
  v32 = 0;
  v36 = 0;
  v35[0] = 0;
  v35[1] = 0;
  v31 = 0;
  v30 = 0;
  memset(v34, 0, sizeof(v34));
  v14 = mlo_check_if_all_links_up(a2, a4, a5, a6, a7, a8, a9, a10, a11);
  result = 0;
  if ( (v14 & 1) != 0 )
  {
    is_link_switch_in_progress = mlo_mgr_is_link_switch_in_progress(a2);
    if ( a3 == 6 || !is_link_switch_in_progress )
    {
      if ( (mlo_is_link_recfg_in_progress(a2) & 1) != 0 )
      {
        v25 = *(unsigned __int8 *)(a2 + 168);
        v26 = "%s: mlo vdev %d link recfg in progress!";
      }
      else
      {
        if ( (policy_mgr_is_set_link_in_progress(a1) & 1) == 0 )
        {
          v27 = mlo_mgr_is_link_switch_in_progress(a2);
          if ( a3 != 6
            || v27
            || (ml_nlink_get_link_info(
                  a1,
                  a2,
                  8u,
                  5u,
                  v34,
                  (unsigned int *)v35,
                  (unsigned __int8 *)&v32,
                  &v30,
                  v29,
                  &v28),
                v29[0] >= 2u) )
          {
            result = 1;
            goto LABEL_11;
          }
          goto LABEL_10;
        }
        v25 = *(unsigned __int8 *)(a2 + 168);
        v26 = "%s: mlo vdev %d not ready due to set link in progress";
      }
    }
    else
    {
      v25 = *(unsigned __int8 *)(a2 + 168);
      v26 = "%s: mlo vdev %d link switch in progress!";
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      v26,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ml_nlink_all_links_ready_for_state_change",
      v25);
LABEL_10:
    result = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
