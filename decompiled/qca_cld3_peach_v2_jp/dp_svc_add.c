__int64 __fastcall dp_svc_add(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  __int64 context; // x0
  __int64 v20; // x21
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v22; // x8
  bool v23; // w20
  bool v24; // cf
  __int64 v25; // x9
  int v26; // w10
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  __int64 v37; // x0
  unsigned __int64 v38; // x20
  int v39; // w8
  __int64 v40; // x0
  __int64 v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2
  __int64 v51; // x4
  unsigned __int64 v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7

  if ( !a1 )
    return 4;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: service class add: svc_id:%u buffer_latency_tolerance:%u app_ind_default_dscp:%u app_ind_special_dscp:%u",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_svc_add",
    *(unsigned __int8 *)(a1 + 16),
    *(unsigned int *)(a1 + 20),
    *(unsigned __int8 *)(a1 + 24),
    *(unsigned __int8 *)(a1 + 25));
  if ( *(unsigned __int8 *)(a1 + 16) < 0x20u )
  {
    context = dp_get_context();
    if ( !context || (v20 = *(_QWORD *)(context + 1552)) == 0 )
    {
      v18 = "%s: svc_ctx is not initialised";
      goto LABEL_23;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = 0;
    v23 = 1;
    *(_DWORD *)(StatusReg + 16) += 512;
    do
    {
      v25 = *(_QWORD *)(v20 + 8 * v22);
      if ( v25 )
      {
        if ( v22 == *(unsigned __int8 *)(a1 + 16) )
          break;
        v26 = *(_DWORD *)(v25 + 28);
        if ( v26 == *(_DWORD *)(a1 + 28)
          && ((v26 & 1) == 0 || *(_DWORD *)(v25 + 20) == *(_DWORD *)(a1 + 20))
          && ((v26 & 2) == 0 || *(unsigned __int8 *)(v25 + 24) == *(unsigned __int8 *)(a1 + 24))
          && ((v26 & 4) == 0 || *(unsigned __int8 *)(v25 + 25) == *(unsigned __int8 *)(a1 + 25)) )
        {
          break;
        }
      }
      v24 = v22++ >= 0x1F;
      v23 = !v24;
    }
    while ( v22 != 32 );
    local_bh_enable_5();
    if ( v23 )
    {
      v35 = "%s: duplicate svc_id/entry is not allowed";
    }
    else
    {
      v37 = _qdf_mem_malloc(0x20u, "dp_svc_add", 97);
      if ( v37 )
      {
        v38 = v37;
        *(_DWORD *)(v37 + 20) = *(_DWORD *)(a1 + 20);
        *(_BYTE *)(v37 + 24) = *(_BYTE *)(a1 + 24);
        *(_BYTE *)(v37 + 25) = *(_BYTE *)(a1 + 25);
        v39 = *(_DWORD *)(a1 + 28);
        *(_BYTE *)(v37 + 17) = 0;
        *(_DWORD *)(v37 + 28) = v39;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v40 = raw_spin_lock(v20 + 264);
        }
        else
        {
          v40 = raw_spin_lock_bh(v20 + 264);
          *(_QWORD *)(v20 + 272) |= 1uLL;
        }
        if ( *(_DWORD *)(v20 + 256) == 32 )
        {
          v41 = *(_QWORD *)(v20 + 272);
          if ( (v41 & 1) != 0 )
          {
            *(_QWORD *)(v20 + 272) = v41 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v20 + 264);
          }
          else
          {
            raw_spin_unlock(v20 + 264);
          }
          _qdf_mem_free(v38);
          v50 = "%s: maximum service_class limit:%u reached";
          v51 = 32;
        }
        else
        {
          v52 = *(unsigned __int8 *)(a1 + 16);
          if ( v52 >= 0x20 )
          {
            __break(0x5512u);
            return qdf_spin_unlock_bh_26(v40);
          }
          if ( !*(_QWORD *)(v20 + 8 * v52) )
          {
            *(_BYTE *)(v38 + 16) = v52;
            atomic_store(v38, (unsigned __int64 *)(v20 + 8 * v52));
            ++*(_DWORD *)(v20 + 256);
            qdf_spin_unlock_bh_26(v20 + 264);
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: new svc added: svc_id:%u",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "dp_svc_add",
              *(unsigned __int8 *)(v38 + 16));
            return 0;
          }
          qdf_spin_unlock_bh_26(v20 + 264);
          _qdf_mem_free(v38);
          v51 = *(unsigned __int8 *)(a1 + 16);
          v50 = "%s: svc_id:%u is already in use";
        }
        qdf_trace_msg(0x45u, 2u, v50, v42, v43, v44, v45, v46, v47, v48, v49, "dp_svc_add", v51);
        return 16;
      }
      v35 = "%s: memory allocation failure";
    }
    qdf_trace_msg(0x45u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "dp_svc_add");
    return 16;
  }
  v18 = "%s: invalid svc_id";
LABEL_23:
  qdf_trace_msg(0x45u, 2u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "dp_svc_add");
  return 4;
}
