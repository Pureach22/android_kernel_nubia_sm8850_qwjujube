__int64 __fastcall ucfg_nan_disable_ind_to_userspace(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x21
  __int64 result; // x0
  void (__fastcall *v22)(_QWORD); // x8
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  int v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v23 = 416;
  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_8:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc_nan_obj is null",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ucfg_nan_disable_ind_to_userspace");
    result = 4;
    goto LABEL_9;
  }
  v19 = comp_private_obj;
  v20 = _qdf_mem_malloc(0x2Cu, "ucfg_nan_disable_ind_to_userspace", 1534);
  result = 2;
  if ( v20 )
  {
    *(_DWORD *)(v20 + 8) = 2;
    *(_QWORD *)v20 = a1;
    *(_DWORD *)(v20 + 16) = 12;
    qdf_mem_copy((void *)(v20 + 26), &v23, 0xCu);
    v22 = *(void (__fastcall **)(_QWORD))(v19 + 16);
    if ( *((_DWORD *)v22 - 1) != -1334644194 )
      __break(0x8228u);
    v22(v20);
    _qdf_mem_free(v20);
    result = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
