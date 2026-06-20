__int64 __fastcall policy_mgr_ap_csa_end(__int64 a1, unsigned int a2, char a3, char a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x24
  __int64 v18; // x22
  __int64 result; // x0
  const char *v20; // x2
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  __int64 v22; // [xsp+8h] [xbp-18h]
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v21 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v20 = "%s: Invalid context";
LABEL_7:
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               v20,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "policy_mgr_ap_csa_end",
               v21,
               v22,
               v23,
               v24);
    goto LABEL_8;
  }
  v17 = *(_QWORD *)(context + 2096);
  v18 = context;
  if ( !v17 )
  {
    v20 = "%s: Invalid work_info context";
    goto LABEL_7;
  }
  result = wlan_mlme_is_aux_emlsr_support(a1);
  if ( (result & 1) != 0 )
  {
    qdf_mutex_acquire(v18 + 56);
    qdf_mem_set((void *)(v17 + 8), 0x18u, 0);
    qdf_mutex_release(v18 + 56);
    qdf_mem_set(&v21, 0x18u, 0);
    LOBYTE(v21) = a3 & 1;
    BYTE1(v21) = a4 & 1;
    result = ml_nlink_conn_change_notify(a1, a2, 15, &v21);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
