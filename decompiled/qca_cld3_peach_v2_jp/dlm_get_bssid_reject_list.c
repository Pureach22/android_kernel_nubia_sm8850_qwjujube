__int64 __fastcall dlm_get_bssid_reject_list(__int64 a1, __int64 a2, unsigned __int8 a3, int a4)
{
  __int64 pdev_obj; // x0
  __int64 v9; // x8
  __int64 v10; // x22
  __int64 psoc_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x23
  const char *v21; // x2
  __int64 result; // x0
  unsigned __int8 v23[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  pdev_obj = dlm_get_pdev_obj(a1);
  v9 = *(_QWORD *)(a1 + 80);
  v10 = pdev_obj;
  psoc_obj = dlm_get_psoc_obj(v9);
  if ( v10 && psoc_obj )
  {
    v20 = psoc_obj;
    if ( !(unsigned int)qdf_mutex_acquire(v10) )
    {
      dlm_fill_reject_list((_QWORD *)(v10 + 64), a2, v23, a4, a3, (__int64 *)(v20 + 8));
      qdf_mutex_release(v10);
      result = v23[0];
      goto LABEL_7;
    }
    v21 = "%s: failed to acquire reject_ap_list_lock";
  }
  else
  {
    v21 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
  }
  qdf_trace_msg(0x6Du, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "dlm_get_bssid_reject_list");
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
