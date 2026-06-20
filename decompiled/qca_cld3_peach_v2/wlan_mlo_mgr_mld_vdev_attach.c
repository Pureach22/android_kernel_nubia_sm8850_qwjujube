__int64 __fastcall wlan_mlo_mgr_mld_vdev_attach(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 (__fastcall *v27)(__int64, __int64, unsigned __int8 *); // x9
  __int64 v28; // x1
  unsigned int v29; // w21
  int v30; // w8
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  unsigned int v35; // w20
  int v36; // w8
  int v37; // w9
  int v38; // w10
  int v39; // w11

  v10 = *(_QWORD *)(a1 + 216);
  if ( v10 && (v11 = *(_QWORD *)(v10 + 80)) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1344);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1344);
      *(_QWORD *)(a1 + 1352) |= 1uLL;
    }
    qdf_mem_copy((void *)(a1 + 80), a2, 6u);
    v15 = *(_QWORD *)(a1 + 1352);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    LODWORD(result) = mlo_dev_ctx_init(a1);
    v25 = *(_QWORD *)(v11 + 2808);
    if ( !v25 )
      goto LABEL_16;
    if ( !*(_QWORD *)v25 )
      goto LABEL_16;
    v26 = *(_QWORD *)(*(_QWORD *)v25 + 176LL);
    if ( !v26 )
      goto LABEL_16;
    v27 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int8 *))(v26 + 8);
    if ( !v27 )
      goto LABEL_16;
    v28 = *(unsigned __int8 *)(a1 + 168);
    v29 = result;
    if ( *((_DWORD *)v27 - 1) != -612755781 )
      __break(0x8229u);
    v30 = v27(v25, v28, a2);
    result = v29;
    if ( v30 )
    {
LABEL_16:
      v31 = *(unsigned __int8 *)(a1 + 74);
      v32 = *(unsigned __int8 *)(a1 + 75);
      v33 = *(unsigned __int8 *)(a1 + 76);
      v34 = *(unsigned __int8 *)(a1 + 79);
      v35 = result;
      if ( a2 )
      {
        v36 = *a2;
        v37 = a2[1];
        v38 = a2[2];
        v39 = a2[5];
      }
      else
      {
        v38 = 0;
        v36 = 0;
        v37 = 0;
        v39 = 0;
      }
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Failed to attach DP vdev  (%02x:%02x:%02x:**:**:%02x) to MLO Dev ctxt (%02x:%02x:%02x:**:**:%02x)",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_mlo_mgr_mld_vdev_attach",
        v31,
        v32,
        v33,
        v34,
        v36,
        v37,
        v38,
        v39);
      return v35;
    }
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Failed to get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_mlo_mgr_mld_vdev_attach");
    return 16;
  }
  return result;
}
