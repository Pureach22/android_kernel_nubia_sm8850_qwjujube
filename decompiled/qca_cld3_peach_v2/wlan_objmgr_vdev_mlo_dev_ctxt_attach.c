__int64 __fastcall wlan_objmgr_vdev_mlo_dev_ctxt_attach(
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
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  unsigned int v15; // w20
  const char *v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v15 = 16;
    v16 = "%s: Failed to get psoc";
LABEL_15:
    qdf_trace_msg(0x57u, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_objmgr_vdev_mlo_dev_ctxt_attach");
    wlan_objmgr_vdev_obj_delete(a1, v17, v18, v19, v20, v21, v22, v23, v24);
    goto LABEL_16;
  }
  if ( !(*(_DWORD *)(a1 + 80) | *(unsigned __int16 *)(a1 + 84)) )
  {
    v15 = 0;
    goto LABEL_16;
  }
  v12 = *(_QWORD *)(v11 + 2808);
  if ( !v12
    || !*(_QWORD *)v12
    || (v13 = *(_QWORD *)(*(_QWORD *)v12 + 176LL)) == 0
    || (v14 = *(__int64 (**)(void))(v13 + 8)) == nullptr )
  {
    v15 = 16;
LABEL_14:
    v16 = "%s: Fail to attach vdev to DP MLO Dev ctxt";
    goto LABEL_15;
  }
  if ( *((_DWORD *)v14 - 1) != -612755781 )
    __break(0x8228u);
  v15 = v14();
  if ( v15 )
    goto LABEL_14;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v15;
}
