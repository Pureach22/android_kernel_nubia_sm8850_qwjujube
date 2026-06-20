__int64 __fastcall fpm_policy_update(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x0
  unsigned __int64 v14; // x21
  __int64 *v15; // x22
  __int64 v16; // x8
  const char *v17; // x2
  unsigned int v18; // w20
  int v19; // w9
  __int64 v20; // x8
  __int64 v21; // x24
  __int64 context; // x0
  __int64 v23; // x23
  __int64 v24; // x24
  __int64 v25; // x8
  __int64 v26; // x24
  __int64 v27; // x0
  __int64 v28; // x23
  __int64 v29; // x24
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v48; // x22
  __int64 v49; // x0
  __int64 v50; // x20
  __int64 v51; // x8
  __int64 v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    v17 = "%s: fpm_ctx is NULL";
LABEL_13:
    qdf_trace_msg(0x45u, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "fpm_policy_update");
    v18 = 4;
    goto LABEL_73;
  }
  if ( !a2 )
  {
    v17 = "%s: policy is NULL";
    goto LABEL_13;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v13 = raw_spin_lock(a1);
  }
  else
  {
    v13 = raw_spin_lock_bh(a1);
    a1[1] |= 1uLL;
  }
  v14 = _ReadStatusReg(SP_EL0);
  v15 = a1 + 2;
  *(_DWORD *)(v14 + 16) += 512;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
    {
LABEL_41:
      v19 = *((_DWORD *)v15 + 24);
      if ( (v19 & 1) != 0 )
        *((_BYTE *)v15 + 100) = *(_BYTE *)(a2 + 100);
      if ( (v19 & 2) == 0 )
      {
LABEL_44:
        *(_QWORD *)(a2 + 40) = v16;
        *(_BYTE *)(a2 + 32) = *((_BYTE *)v15 + 32);
        local_bh_enable_3(v13);
        qdf_atomic_notfier_call();
        v18 = 0;
        v20 = a1[1];
        if ( (v20 & 1) != 0 )
          goto LABEL_86;
LABEL_72:
        raw_spin_unlock(a1);
        goto LABEL_73;
      }
      v21 = *(unsigned __int8 *)(a2 + 101);
      context = dp_get_context();
      if ( context )
      {
        if ( (unsigned int)v21 <= 0x1F )
        {
          v23 = *(_QWORD *)(context + 1552);
          if ( v23 )
          {
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v14 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v23 + 264);
              v24 = *(_QWORD *)(v23 + 8 * v21);
              if ( v24 )
                goto LABEL_53;
            }
            else
            {
              raw_spin_lock_bh(v23 + 264);
              *(_QWORD *)(v23 + 272) |= 1uLL;
              v24 = *(_QWORD *)(v23 + 8 * v21);
              if ( v24 )
LABEL_53:
                ++*(_BYTE *)(v24 + 17);
            }
            v25 = *(_QWORD *)(v23 + 272);
            if ( (v25 & 1) != 0 )
            {
              *(_QWORD *)(v23 + 272) = v25 & 0xFFFFFFFFFFFFFFFELL;
              context = raw_spin_unlock_bh(v23 + 264);
              if ( v24 )
                goto LABEL_56;
            }
            else
            {
              context = raw_spin_unlock(v23 + 264);
              if ( v24 )
              {
LABEL_56:
                v26 = *((unsigned __int8 *)v15 + 101);
                v27 = dp_get_context();
                if ( v27 )
                {
                  if ( (unsigned int)v26 <= 0x1F )
                  {
                    v28 = *(_QWORD *)(v27 + 1552);
                    if ( v28 )
                    {
                      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                        || (*(_DWORD *)(v14 + 16) & 0xF0000) != 0
                        || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
                      {
                        raw_spin_lock(v28 + 264);
                        v29 = *(_QWORD *)(v28 + 8 * v26);
                        if ( v29 )
                          goto LABEL_63;
                      }
                      else
                      {
                        raw_spin_lock_bh(v28 + 264);
                        *(_QWORD *)(v28 + 272) |= 1uLL;
                        v29 = *(_QWORD *)(v28 + 8 * v26);
                        if ( v29 )
LABEL_63:
                          --*(_BYTE *)(v29 + 17);
                      }
                      v30 = *(_QWORD *)(v28 + 272);
                      if ( (v30 & 1) != 0 )
                      {
                        *(_QWORD *)(v28 + 272) = v30 & 0xFFFFFFFFFFFFFFFELL;
                        v13 = raw_spin_unlock_bh(v28 + 264);
                        if ( v29 )
                          goto LABEL_66;
                      }
                      else
                      {
                        v13 = raw_spin_unlock(v28 + 264);
                        if ( v29 )
                        {
LABEL_66:
                          v16 = v15[5];
                          *((_BYTE *)v15 + 101) = *(_BYTE *)(a2 + 101);
                          goto LABEL_44;
                        }
                      }
                    }
                  }
                }
                v48 = *(unsigned __int8 *)(a2 + 101);
                v49 = dp_get_context();
                if ( v49 )
                {
                  if ( (unsigned int)v48 <= 0x1F )
                  {
                    v50 = *(_QWORD *)(v49 + 1552);
                    if ( v50 )
                    {
                      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                        || (*(_DWORD *)(v14 + 16) & 0xF0000) != 0
                        || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
                      {
                        raw_spin_lock(v50 + 264);
                        v51 = *(_QWORD *)(v50 + 8 * v48);
                        if ( v51 )
                          goto LABEL_82;
                      }
                      else
                      {
                        raw_spin_lock_bh(v50 + 264);
                        *(_QWORD *)(v50 + 272) |= 1uLL;
                        v51 = *(_QWORD *)(v50 + 8 * v48);
                        if ( v51 )
LABEL_82:
                          --*(_BYTE *)(v51 + 17);
                      }
                      v52 = *(_QWORD *)(v50 + 272);
                      if ( (v52 & 1) != 0 )
                      {
                        *(_QWORD *)(v50 + 272) = v52 & 0xFFFFFFFFFFFFFFFELL;
                        v49 = raw_spin_unlock_bh(v50 + 264);
                      }
                      else
                      {
                        v49 = raw_spin_unlock(v50 + 264);
                      }
                    }
                  }
                }
                local_bh_enable_3(v49);
                qdf_trace_msg(
                  0x45u,
                  2u,
                  "%s: svc_id update failed",
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  "fpm_policy_update");
                v18 = 16;
                v20 = a1[1];
                if ( (v20 & 1) != 0 )
                  goto LABEL_86;
                goto LABEL_72;
              }
            }
          }
        }
      }
      local_bh_enable_3(context);
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: new svc_id:%u is not valid",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "fpm_policy_update",
        *(unsigned __int8 *)(a2 + 101));
      v18 = 4;
      v20 = a1[1];
      if ( (v20 & 1) != 0 )
        goto LABEL_86;
      goto LABEL_72;
    }
  }
  v15 = a1 + 3;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
      goto LABEL_41;
  }
  v15 = a1 + 4;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
      goto LABEL_41;
  }
  v15 = a1 + 5;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
      goto LABEL_41;
  }
  v15 = a1 + 6;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
      goto LABEL_41;
  }
  v15 = a1 + 7;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
      goto LABEL_41;
  }
  v15 = a1 + 8;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
      goto LABEL_41;
  }
  v15 = a1 + 9;
  while ( 1 )
  {
    v15 = (__int64 *)*v15;
    if ( !v15 )
      break;
    v16 = v15[5];
    if ( v16 == *(_QWORD *)(a2 + 40) )
      goto LABEL_41;
  }
  local_bh_enable_3(v13);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: no policy found with policy_id:%llx",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "fpm_policy_update",
    *(_QWORD *)(a2 + 40));
  v18 = 17;
  v20 = a1[1];
  if ( (v20 & 1) == 0 )
    goto LABEL_72;
LABEL_86:
  a1[1] = v20 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1);
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return v18;
}
