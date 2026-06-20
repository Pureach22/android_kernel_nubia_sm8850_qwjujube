__int64 __fastcall wlan_ipa_pm_flush(__int64 a1)
{
  unsigned __int64 v2; // x8
  __int64 *v3; // x22
  unsigned __int64 v4; // x25
  unsigned __int64 StatusReg; // x27
  __int64 *v6; // x9
  __int64 v7; // x8
  __int64 v8; // x8
  void (__fastcall *v9)(_QWORD); // x8
  __int64 *v10; // x20
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x21
  __int64 *v13; // x22
  __int64 v14; // x23
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x24
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 *v21; // x8
  __int64 v22; // x8
  __int64 v23; // x26
  __int64 v24; // x8
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  __int64 v35; // x22
  __int64 v36; // x8
  __int64 (*v37)(void); // x8
  unsigned int v43; // w8
  __int64 v44; // x8
  __int64 result; // x0
  unsigned __int64 v46; // x9
  __int64 v47; // [xsp+0h] [xbp-10h] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v2 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v2 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v2 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 3360);
    v3 = *(__int64 **)(a1 + 3288);
    if ( v3 )
    {
LABEL_5:
      LODWORD(v4) = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v6 = *(__int64 **)(a1 + 3296);
        --*(_DWORD *)(a1 + 3304);
        if ( v3 == v6 )
        {
          v7 = 0;
          *(_QWORD *)(a1 + 3296) = 0;
        }
        else
        {
          v7 = *v3;
        }
        *(_QWORD *)(a1 + 3288) = v7;
        *v3 = 0;
        v8 = *(_QWORD *)(a1 + 3368);
        if ( (v8 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 3368) = v8 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 3360);
        }
        else
        {
          raw_spin_unlock(a1 + 3360);
        }
        if ( *((_BYTE *)v3 + 40) == 1 )
        {
          v9 = *(void (__fastcall **)(_QWORD))(a1 + 7360);
          if ( v9 && *(_QWORD *)(v3[6] + 24) )
          {
            if ( *((_DWORD *)v9 - 1) != 1976926460 )
              __break(0x8228u);
            v9(v3);
            ++*(_QWORD *)(a1 + 3680);
            goto LABEL_24;
          }
          goto LABEL_23;
        }
        v10 = (__int64 *)v3[6];
        if ( *((_BYTE *)v3 + 64) == 1 )
        {
          v11 = *(void (__fastcall **)(_QWORD))(a1 + 7368);
          if ( v11 && v10[3] )
          {
            if ( *((_DWORD *)v11 - 1) != -1095694526 )
              __break(0x8228u);
            v11(v3);
            ++*(_QWORD *)(a1 + 4144);
            goto LABEL_24;
          }
LABEL_23:
          dev_kfree_skb_any_reason(v3, 1);
          goto LABEL_24;
        }
        v12 = *v10;
        if ( *v10 )
          break;
LABEL_24:
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 3360);
        }
        else
        {
          raw_spin_lock_bh(a1 + 3360);
          *(_QWORD *)(a1 + 3368) |= 1uLL;
        }
        v3 = *(__int64 **)(a1 + 3288);
        v4 = (unsigned int)(v4 + 1);
        if ( !v3 )
          goto LABEL_99;
      }
      v47 = 0;
      v13 = (__int64 *)v3[7];
      if ( *(_QWORD *)v12 )
      {
        v14 = *(_QWORD *)(*(_QWORD *)v12 + 2120LL);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
          goto LABEL_37;
      }
      else
      {
        v14 = 0;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
          goto LABEL_37;
      }
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
      {
        raw_spin_lock_bh(v10 + 7);
        v10[8] |= 1uLL;
        goto LABEL_38;
      }
LABEL_37:
      raw_spin_lock(v10 + 7);
LABEL_38:
      _X28 = (unsigned int *)(v12 + 3284);
      if ( (*((_DWORD *)v10 + 8) | 2) == 3 && *(_BYTE *)(v12 + 7357) == 1 )
      {
        ipa_free_skb(v13);
        v16 = v10[8];
        if ( (v16 & 1) != 0 )
        {
          v10[8] = v16 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v10 + 7);
        }
        else
        {
          raw_spin_unlock(v10 + 7);
        }
        ++v10[13];
      }
      else
      {
        if ( v14 )
        {
          v17 = v10[8];
          if ( (v17 & 1) != 0 )
          {
            v10[8] = v17 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v10 + 7);
          }
          else
          {
            raw_spin_unlock(v10 + 7);
          }
          v18 = *v13;
          qdf_mem_set((void *)(*v13 + 40), 0x30u, 0);
          *(_DWORD *)(v18 + 48) |= 1u;
          if ( *(_BYTE *)(v14 + 608) != 1 )
          {
            v21 = v13 + 1;
            goto LABEL_59;
          }
          if ( !(unsigned int)_qdf_nbuf_map(v14, v18, 1) )
          {
            v22 = 80;
            if ( (*(_BYTE *)(v18 + 68) & 4) == 0 )
              v22 = 40;
            v21 = (__int64 *)(v18 + v22);
LABEL_59:
            v23 = *v21;
            *(_QWORD *)(v18 + 40) = *v21;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v12 + 3384);
              if ( *(_DWORD *)(v12 + 3488) )
              {
LABEL_63:
                if ( !(unsigned int)qdf_list_remove_front((_DWORD *)(v12 + 3472), &v47) )
                {
                  *(_QWORD *)(v47 + 32) = v13;
                  v25 = *(_QWORD *)(v12 + 3392);
                  ++*(_QWORD *)(v12 + 3616);
                  if ( (v25 & 1) != 0 )
                  {
                    *(_QWORD *)(v12 + 3392) = v25 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(v12 + 3384);
                  }
                  else
                  {
                    raw_spin_unlock(v12 + 3384);
                  }
                  *(_DWORD *)(v18 + 48) = *(_DWORD *)(v18 + 48) & 1 | (2 * *(_DWORD *)(v47 + 24));
                  v34 = *(_QWORD *)(v12 + 1456);
                  v35 = *v13;
                  if ( v34 && *(_QWORD *)v34 && (v36 = *(_QWORD *)(*(_QWORD *)v34 + 152LL)) != 0 )
                  {
                    v37 = *(__int64 (**)(void))(v36 + 64);
                    if ( v37 )
                    {
                      if ( *((_DWORD *)v37 - 1) != -1980056647 )
                        __break(0x8228u);
                      v35 = v37();
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x45u,
                      1u,
                      "%s invalid instance",
                      v26,
                      v27,
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v33,
                      "cdp_ipa_tx_send_data_frame",
                      v47,
                      v48);
                  }
                  if ( v35 )
                  {
                    _qdf_nbuf_free(v35);
                    ++v10[12];
                  }
                  else
                  {
                    __asm { PRFM            #0x11, [X28] }
                    do
                      v43 = __ldxr(_X28);
                    while ( __stxr(v43 + 1, _X28) );
                    ++v10[10];
                  }
                  goto LABEL_24;
                }
              }
            }
            else
            {
              raw_spin_lock_bh(v12 + 3384);
              *(_QWORD *)(v12 + 3392) |= 1uLL;
              if ( *(_DWORD *)(v12 + 3488) )
                goto LABEL_63;
            }
            v24 = *(_QWORD *)(v12 + 3392);
            ++*(_QWORD *)(v12 + 3624);
            if ( (v24 & 1) != 0 )
            {
              *(_QWORD *)(v12 + 3392) = v24 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v12 + 3384);
            }
            else
            {
              raw_spin_unlock(v12 + 3384);
            }
            if ( *(_BYTE *)(v14 + 608) == 1 )
            {
              if ( (**(_BYTE **)(v12 + 1464) & 0x40) != 0 )
                *(_QWORD *)(v18 + 40) = v23;
              _qdf_nbuf_unmap(v14, v18, 1);
            }
            ipa_free_skb(v13);
            goto LABEL_24;
          }
          ipa_free_skb(v13);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v10 + 7);
            v19 = v10[8];
            v20 = v10[11];
          }
          else
          {
            raw_spin_lock_bh(v10 + 7);
            v20 = v10[11];
            v19 = v10[8] | 1;
            v10[8] = v19;
          }
        }
        else
        {
          ipa_free_skb(v13);
          v20 = v10[11];
          v19 = v10[8];
        }
        v10[11] = v20 + 1;
        if ( (v19 & 1) != 0 )
        {
          v10[8] = v19 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v10 + 7);
        }
        else
        {
          raw_spin_unlock(v10 + 7);
        }
      }
      goto LABEL_24;
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 3360);
    *(_QWORD *)(a1 + 3368) |= 1uLL;
    v3 = *(__int64 **)(a1 + 3288);
    if ( v3 )
      goto LABEL_5;
  }
  v4 = 0;
LABEL_99:
  v44 = *(_QWORD *)(a1 + 3368);
  if ( (v44 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3368) = v44 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 3360);
  }
  else
  {
    result = raw_spin_unlock(a1 + 3360);
  }
  v46 = *(_QWORD *)(a1 + 3656);
  *(_QWORD *)(a1 + 3648) += v4;
  if ( v46 < v4 )
    *(_QWORD *)(a1 + 3656) = v4;
  _ReadStatusReg(SP_EL0);
  return result;
}
