__int64 __fastcall dp_bbm_apply_independent_policy(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v4; // x19
  __int64 v5; // x23
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w4
  int v15; // w4
  __int64 v16; // x20
  __int64 v17; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x8
  __int64 *v20; // x9
  unsigned int v21; // w25
  unsigned __int64 v22; // x26
  __int64 v23; // x10
  __int64 v24; // x27
  unsigned int v25; // w8
  __int64 v26; // x8
  int v27; // w11
  __int64 v28; // x0
  _DWORD *v29; // x8
  __int64 v30; // x1
  __int64 (__fastcall *v31)(__int64, __int64, unsigned int *); // x8
  __int64 v32; // x1
  char v33; // w0
  __int64 (__fastcall *v34)(__int64, __int64); // x8
  __int64 v35; // x1
  char v36; // w0
  unsigned int v37; // w4
  const char *v38; // x2
  const char *v39; // x3
  unsigned int v40; // w1
  int v41; // w4
  __int64 v42; // x0
  __int64 (__fastcall *v43)(_QWORD); // x8
  char v44; // w0
  __int64 v45; // x8
  __int64 v46; // x1
  int v47; // w8
  __int64 v48; // x0
  __int64 (__fastcall *v49)(_QWORD); // x8
  _DWORD *v50; // x22
  unsigned int v51; // w8
  unsigned int v52; // w20
  unsigned int v53; // w21
  __int64 v54; // [xsp+0h] [xbp-30h] BYREF
  __int64 *v55; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v56; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD v57[3]; // [xsp+18h] [xbp-18h] BYREF

  v57[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( a2 )
  {
    v4 = (_QWORD *)result;
    if ( result )
    {
      v5 = *(_QWORD *)(result + 1160);
      qdf_mutex_acquire(v5 + 32);
      v14 = *(_DWORD *)a2;
      if ( *(int *)a2 > 1 )
      {
        if ( v14 != 2 )
        {
          if ( v14 != 3 )
          {
            if ( v14 == 4 )
            {
              v15 = *(_DWORD *)(a2 + 4);
              if ( v15 == 1 )
              {
                *(_QWORD *)v5 = &bus_bw_table_low_latency;
                goto LABEL_125;
              }
              if ( !v15 )
              {
                *(_QWORD *)v5 = &bus_bw_table_default;
LABEL_125:
                result = qdf_mutex_release(v5 + 32);
                goto LABEL_126;
              }
              v38 = "%s: wlm level %d not handled in BBM WLM policy";
              v39 = "bbm_apply_wlm_policy";
              goto LABEL_105;
            }
            goto LABEL_93;
          }
          v41 = *(_DWORD *)(a2 + 4);
          if ( v41 == 1 )
          {
            v45 = v4[145];
          }
          else
          {
            if ( v41 )
            {
              v38 = "%s: flag %d not handled in res/sus BBM policy";
              v39 = "bbm_apply_non_persistent_policy";
              goto LABEL_105;
            }
            v42 = v4[47];
            v43 = (__int64 (__fastcall *)(_QWORD))v4[67];
            if ( *((_DWORD *)v43 - 1) != 859392181 )
              __break(0x8228u);
            v44 = v43(v42);
            v45 = v4[145];
            if ( (v44 & 1) != 0 )
            {
              v46 = 3;
              *(_DWORD *)(v45 + 8) = 3;
LABEL_124:
              pld_request_bus_bandwidth(*(_QWORD *)(v4[2] + 40LL), v46);
              goto LABEL_125;
            }
          }
          *(_DWORD *)(v45 + 8) = 0;
          v46 = 0;
          goto LABEL_124;
        }
        v37 = *(_DWORD *)(a2 + 4);
        if ( v37 > 9 )
        {
          v38 = "%s: Invalid user vote level %d";
          v39 = "bbm_apply_user_policy";
          v40 = 2;
LABEL_106:
          qdf_trace_msg(0x45u, v40, v38, v6, v7, v8, v9, v10, v11, v12, v13, v39);
          goto LABEL_125;
        }
        if ( *(_BYTE *)(a2 + 8) == 1 )
          *(_DWORD *)(v5 + 20) = v37;
        else
          *(_DWORD *)(v5 + 20) = 0;
LABEL_110:
        v50 = (_DWORD *)v4[145];
        v51 = v50[3];
        if ( v50[4] > v51 )
          v51 = v50[4];
        if ( v50[5] > v51 )
          v51 = v50[5];
        if ( v50[6] > v51 )
          v51 = v50[6];
        if ( v50[7] <= v51 )
          v52 = v51;
        else
          v52 = v50[7];
        if ( v52 == v50[2] )
          goto LABEL_125;
        if ( v52 - 1 > 8 )
          v53 = 0;
        else
          v53 = dword_AEF718[v52 - 1];
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Bus bandwidth vote level change from %d to %d pld_vote: %d",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "bbm_request_bus_bandwidth",
          v54);
        v50[2] = v52;
        v46 = v53;
        goto LABEL_124;
      }
      if ( !v14 )
      {
        if ( (*(_DWORD *)(a2 + 4) & 0xFFFFFFFE) == 4 )
          v47 = 7;
        else
          v47 = 0;
        *(_DWORD *)(v5 + 12) = v47;
        goto LABEL_110;
      }
      if ( v14 != 1 )
      {
LABEL_93:
        v38 = "%s: BBM policy %d not handled";
        v39 = "dp_bbm_apply_independent_policy";
LABEL_105:
        v40 = 5;
        goto LABEL_106;
      }
      v16 = *(unsigned int *)(a2 + 4);
      v17 = v4[145];
      v54 = 0;
      v55 = nullptr;
      if ( (_DWORD)v16 )
      {
        if ( !*v4 )
        {
          qdf_trace_msg(0x45u, 2u, "%s: psoc is NULL", v6, v7, v8, v9, v10, v11, v12, v13, "bbm_apply_tput_policy");
          goto LABEL_110;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v4 + 33);
        }
        else
        {
          raw_spin_lock_bh(v4 + 33);
          v4[34] |= 1uLL;
        }
        dp_get_front_intf_no_lock(v4, &v55);
        dp_get_next_intf_no_lock(v4, v55, &v54);
        v19 = v4[34];
        if ( (v19 & 1) != 0 )
        {
          v4[34] = v19 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v4 + 33);
          v20 = v55;
          if ( v55 )
            goto LABEL_20;
        }
        else
        {
          raw_spin_unlock(v4 + 33);
          v20 = v55;
          if ( v55 )
          {
LABEL_20:
            v21 = 0;
            v22 = _ReadStatusReg(SP_EL0);
            while ( !*((_BYTE *)v20 + 3661) )
            {
LABEL_27:
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v22 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v4 + 33);
              }
              else
              {
                raw_spin_lock_bh(v4 + 33);
                v4[34] |= 1uLL;
              }
              v55 = (__int64 *)v54;
              dp_get_next_intf_no_lock(v4, v54, &v54);
              v26 = v4[34];
              if ( (v26 & 1) != 0 )
              {
                v4[34] = v26 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v4 + 33);
                v20 = v55;
                if ( !v55 )
                {
LABEL_108:
                  *(_DWORD *)(v17 + 16) = v21;
                  goto LABEL_110;
                }
              }
              else
              {
                raw_spin_unlock(v4 + 33);
                v20 = v55;
                if ( !v55 )
                  goto LABEL_108;
              }
            }
            v23 = *v20;
            v56 = 0;
            v24 = **(_QWORD **)(v23 + 1160);
            *(_QWORD *)((char *)v57 + 6) = 0;
            v57[0] = 0;
            if ( (unsigned int)v16 >= 9 )
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: invalid tput level %d",
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                "bbm_get_bus_bw_level_vote",
                (unsigned int)v16);
LABEL_24:
              v25 = 0;
              goto LABEL_25;
            }
            v27 = *((_DWORD *)v20 + 7);
            v28 = *(_QWORD *)(v23 + 376);
            v25 = 0;
            if ( v27 <= 1 )
            {
              if ( !v27 )
                goto LABEL_65;
              if ( v27 != 1 )
                goto LABEL_25;
            }
            else
            {
              if ( v27 == 11 )
              {
                v34 = *(__int64 (__fastcall **)(__int64, __int64))(v23 + 528);
                v35 = v20[7];
                if ( *((_DWORD *)v34 - 1) != 412937074 )
                  __break(0x8228u);
                v36 = v34(v28, v35);
                if ( (v36 & 1) != 0 )
                  v25 = 5;
                else
                  v25 = 0;
                if ( (unsigned int)v16 >= 5 && (v36 & 1) != 0 )
                  v25 = *(_DWORD *)(v24 + 4 * v16 + 180);
                goto LABEL_25;
              }
              if ( v27 != 3 )
              {
                if ( v27 != 2 )
                {
LABEL_25:
                  if ( v25 > v21 )
                    v21 = v25;
                  goto LABEL_27;
                }
LABEL_65:
                v31 = *(__int64 (__fastcall **)(__int64, __int64, unsigned int *))(v23 + 512);
                v32 = v20[7];
                if ( *((_DWORD *)v31 - 1) != -1777952391 )
                  __break(0x8228u);
                v33 = v31(v28, v32, &v56);
                v25 = 0;
                if ( (v33 & 1) != 0 && v56 <= 6 )
                  v25 = *(_DWORD *)(v24 + 36LL * v56 + 4 * v16);
                goto LABEL_25;
              }
            }
            v29 = *(_DWORD **)(v23 + 520);
            v30 = v20[7];
            if ( *(v29 - 1) != 74975039 )
              __break(0x8228u);
            if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v29)(v28, v30, v57) & 1) != 0 )
            {
              v25 = LOWORD(v57[0]);
              if ( LOWORD(v57[0]) )
                v25 = *(_DWORD *)(v24 + 4 * v16);
              if ( WORD1(v57[0]) && *(_DWORD *)(v24 + 4 * v16 + 36) > v25 )
                v25 = *(_DWORD *)(v24 + 4 * v16 + 36);
              if ( WORD2(v57[0]) && *(_DWORD *)(v24 + 4 * v16 + 72) > v25 )
                v25 = *(_DWORD *)(v24 + 4 * v16 + 72);
              if ( HIWORD(v57[0]) && *(_DWORD *)(v24 + 4 * v16 + 108) > v25 )
                v25 = *(_DWORD *)(v24 + 4 * v16 + 108);
              if ( LOWORD(v57[1]) && *(_DWORD *)(v24 + 4 * v16 + 144) > v25 )
                v25 = *(_DWORD *)(v24 + 4 * v16 + 144);
              if ( WORD1(v57[1]) && *(_DWORD *)(v24 + 4 * v16 + 180) > v25 )
                v25 = *(_DWORD *)(v24 + 4 * v16 + 180);
              if ( WORD2(v57[1]) && *(_DWORD *)(v24 + 4 * v16 + 216) > v25 )
                v25 = *(_DWORD *)(v24 + 4 * v16 + 216);
              goto LABEL_25;
            }
            goto LABEL_24;
          }
        }
      }
      else
      {
        v48 = v4[47];
        v49 = (__int64 (__fastcall *)(_QWORD))v4[67];
        if ( *((_DWORD *)v49 - 1) != 859392181 )
          __break(0x8228u);
        if ( (v49(v48) & 1) == 0 )
          goto LABEL_110;
      }
      *(_DWORD *)(v17 + 16) = 0;
      goto LABEL_110;
    }
  }
LABEL_126:
  _ReadStatusReg(SP_EL0);
  return result;
}
