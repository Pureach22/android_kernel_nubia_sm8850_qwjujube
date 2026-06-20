unsigned __int64 __fastcall qmi_rmnet_change_link(__int64 a1, __int64 a2, unsigned __int8 *a3, unsigned int a4)
{
  __int64 qmi_pt; // x0
  unsigned int v9; // w9
  __int64 v10; // x8
  unsigned __int64 result; // x0
  int v12; // w9
  __int64 v13; // x22
  int v14; // w23
  _BOOL8 v15; // x19
  __int64 v16; // x0
  int v17; // w8
  int v18; // w11
  int v19; // w10
  __int64 v20; // x0
  __int64 qos_pt; // x0
  __int64 v22; // x20
  int v23; // w22
  int v24; // w24
  int v25; // w21
  unsigned int v26; // w23
  unsigned __int8 *v27; // t2
  __int64 v28; // x25
  __int64 v29; // x26
  __int64 v30; // x19
  _BOOL4 v31; // w22
  unsigned int v32; // w8
  __int64 v33; // x0
  __int64 v34; // x2
  __int64 v35; // x0
  __int64 v36; // x2
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  unsigned int v40; // w21
  __int64 v41; // x0
  char v42; // w9
  __int64 v43; // x0
  __int64 *v44; // x11
  int v45; // w8
  __int64 v46; // x27
  __int64 v47; // x26
  __int64 *v48; // x21
  __int64 **v49; // x8
  __int64 *v50; // x9
  __int64 v51; // x0
  unsigned __int64 v52; // x19
  int v53; // [xsp+Ch] [xbp-24h]
  __int64 v54; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int64 v55; // [xsp+18h] [xbp-18h]
  int v56; // [xsp+20h] [xbp-10h]
  __int64 v57; // [xsp+28h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qmi_pt = rmnet_get_qmi_pt(a2);
  v9 = *a3;
  v10 = qmi_pt;
  result = 0;
  if ( v9 <= 4 )
  {
    if ( v9 == 1 )
    {
      result = 0;
      if ( v10 && dfc_mode == 4 )
      {
        if ( *(_QWORD *)(v10 + 24) || *(_QWORD *)(v10 + 32) )
        {
          qos_pt = rmnet_get_qos_pt(a1);
          if ( a3 )
          {
            v22 = qos_pt;
            if ( qos_pt )
            {
              if ( *((_DWORD *)a3 + 2) <= 0xFu )
              {
                if ( !(unsigned int)((__int64 (*)(void))rtnl_is_locked)()
                  && (qmi_rmnet_add_flow___already_done & 1) == 0 )
                {
                  qmi_rmnet_add_flow___already_done = 1;
                  _warn_printk(
                    "RTNL: assertion failed at %s (%d)\n",
                    "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",
                    474);
                  __break(0x800u);
                }
                v23 = a3[1];
                v24 = *((_DWORD *)a3 + 1);
                v56 = 0;
                v27 = a3 + 8;
                v25 = *((_DWORD *)a3 + 2);
                v26 = *((_DWORD *)v27 + 1);
                v54 = 0;
                v55 = 0;
                raw_spin_lock_bh(v22 + 332);
                v29 = v22 + 40;
                v28 = *(_QWORD *)(v22 + 40);
                if ( v28 != v22 + 40 )
                {
                  do
                  {
                    while ( *(_DWORD *)(v28 + 20) != v26 || *(_DWORD *)(v28 + 24) != v24 )
                    {
                      v28 = *(_QWORD *)v28;
                      if ( v28 == v29 )
                        goto LABEL_66;
                    }
                    if ( !v28 )
                      break;
                    if ( *(unsigned __int8 *)(v28 + 16) != v23 )
                    {
                      v44 = *(__int64 **)(v28 + 32);
                      if ( v44 )
                      {
                        v45 = *((_DWORD *)v44 + 5) - 1;
                        *((_DWORD *)v44 + 5) = v45;
                        if ( !v45 )
                        {
                          v46 = 0;
                          v47 = v22 + 72;
                          v53 = v25;
                          do
                          {
                            if ( *(__int64 **)v47 == v44 )
                            {
                              *(_QWORD *)v47 = 0;
                              *(_WORD *)(v47 + 8) = 0;
                              v48 = v44;
                              __dmb(0xBu);
                              qmi_rmnet_flow_control(a1, v46, 1);
                              v44 = v48;
                              if ( dfc_mode == 4 )
                              {
                                qmi_rmnet_flow_control(a1, v46 + 15, 1);
                                v44 = v48;
                              }
                            }
                            ++v46;
                            v47 += 16;
                          }
                          while ( v46 != 16 );
                          v49 = (__int64 **)v44[1];
                          if ( *v49 == v44 && (v50 = (__int64 *)*v44, *(__int64 **)(*v44 + 8) == v44) )
                          {
                            v50[1] = (__int64)v49;
                            *v49 = v50;
                          }
                          else
                          {
                            _list_del_entry_valid_or_report(v44);
                          }
                          v25 = v53;
                          *v44 = 0xDEAD000000000100LL;
                          v44[1] = 0xDEAD000000000122LL;
                          *(_QWORD *)(v22 + 336) = v44;
                        }
                      }
                      v51 = _qmi_rmnet_bearer_get(v22, v23);
                      if ( v51 )
                      {
                        v36 = v51;
                        *(_BYTE *)(v28 + 16) = v23;
                        *(_DWORD *)(v28 + 20) = v26;
                        *(_DWORD *)(v28 + 24) = v24;
                        *(_DWORD *)(v28 + 28) = v25;
                        goto LABEL_73;
                      }
                      goto LABEL_74;
                    }
                    v32 = *(_DWORD *)(v28 + 28);
                    if ( v32 == v25 )
                      goto LABEL_74;
                    BYTE1(v54) = v23;
                    v55 = __PAIR64__(v26, v32);
                    HIDWORD(v54) = v24;
                    raw_spin_unlock_bh(v22 + 332);
                    qmi_rmnet_del_flow(a1, &v54);
                    raw_spin_lock_bh(v22 + 332);
                    v28 = *(_QWORD *)v29;
                  }
                  while ( *(_QWORD *)v29 != v29 );
                }
LABEL_66:
                v33 = _kmalloc_cache_noprof(_stack_chk_fail, 2336, 40);
                v28 = v33;
                if ( v33 )
                {
                  *(_BYTE *)(v33 + 16) = v23;
                  *(_DWORD *)(v33 + 20) = v26;
                  *(_DWORD *)(v33 + 24) = v24;
                  *(_DWORD *)(v33 + 28) = v25;
                  v34 = *(_QWORD *)v29;
                  if ( *(_QWORD *)(*(_QWORD *)v29 + 8LL) != v29 || v33 == v29 || v34 == v33 )
                  {
                    _list_add_valid_or_report(v33, v22 + 40, v34);
                  }
                  else
                  {
                    *(_QWORD *)(v34 + 8) = v33;
                    *(_QWORD *)v33 = v34;
                    *(_QWORD *)(v33 + 8) = v29;
                    *(_QWORD *)v29 = v33;
                  }
                  v35 = _qmi_rmnet_bearer_get(v22, v23);
                  if ( v35 )
                  {
                    v36 = v35;
LABEL_73:
                    *(_QWORD *)(v28 + 32) = v36;
                    ((void (__fastcall *)(__int64, __int64))_qmi_rmnet_update_mq)(a1, v22);
                  }
LABEL_74:
                  raw_spin_unlock_bh(v22 + 332);
                  v37 = *(_QWORD *)(v22 + 336);
                  if ( v37 )
                  {
                    *(_BYTE *)(v37 + 121) = 1;
                    timer_delete_sync(*(_QWORD *)(v22 + 336) + 80LL);
                    *(_BYTE *)(*(_QWORD *)(v22 + 336) + 148LL) = 1;
                    timer_delete_sync(*(_QWORD *)(v22 + 336) + 152LL);
                    kfree(*(_QWORD *)(v22 + 336));
                    *(_QWORD *)(v22 + 336) = 0;
                  }
                }
                else
                {
                  raw_spin_unlock_bh(v22 + 332);
                }
              }
            }
          }
        }
        goto LABEL_91;
      }
      goto LABEL_92;
    }
    if ( v9 == 2 )
    {
      result = 0;
      if ( v10 && dfc_mode == 4 )
      {
        qmi_rmnet_del_flow(a1, a3);
        goto LABEL_91;
      }
      goto LABEL_92;
    }
    if ( v9 != 4 )
      goto LABEL_92;
    v12 = *((_DWORD *)a3 + 1);
    dfc_qmap = v12 & 0x20;
    dfc_mode = v12 & 0xF;
    dfc_ps_ext = v12 & 0x40;
    if ( (v12 & 0xF) != 4 && (v12 & 0x10) == 0 )
      goto LABEL_91;
    v13 = v10;
    if ( !(unsigned int)rtnl_is_locked(0) && (qmi_rmnet_setup_client___already_done & 1) == 0 )
    {
      qmi_rmnet_setup_client___already_done = 1;
      _warn_printk("RTNL: assertion failed at %s (%d)\n", "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c", 643);
      __break(0x800u);
    }
    v14 = *((_DWORD *)a3 + 2);
    v15 = v14 != 0;
    if ( !v13 )
    {
      v16 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
      if ( !v16 )
        goto LABEL_113;
      v13 = v16;
      rmnet_init_qmi_pt(a2, v16);
    }
    v17 = *((_DWORD *)a3 + 1);
    *(_BYTE *)(v13 + 72) = 1;
    *(_DWORD *)v13 = v17;
    *(_DWORD *)(v13 + 76) = v17 & 0x40;
    v18 = *((_DWORD *)a3 + 3);
    v19 = *((_DWORD *)a3 + 4);
    LODWORD(v54) = *((_DWORD *)a3 + 2);
    HIDWORD(v54) = v19;
    LODWORD(v55) = v18;
    if ( dfc_mode != 4 || *(_QWORD *)(v13 + 8LL * (v14 != 0) + 24) || *(_QWORD *)(v13 + 8 * v15 + 40) )
    {
      v20 = 0;
      if ( (a3[4] & 0x10) == 0 )
        goto LABEL_26;
    }
    else
    {
      if ( dfc_qmap )
        v20 = dfc_qmap_client_init(a2, v15, &v54, v13);
      else
        v20 = dfc_qmi_client_init(a2, v15, (unsigned int *)&v54, v13);
      *(_BYTE *)(v13 + v15 + 56) = 0;
      if ( (a3[4] & 0x10) == 0 )
        goto LABEL_26;
    }
    if ( !v14 && !*(_QWORD *)(v13 + 8) && !*(_QWORD *)(v13 + 16) )
      v20 = wda_qmi_client_init(a2, &v54, v13);
LABEL_26:
    if ( (v20 & 0x80000000) == 0 )
    {
      if ( (a3[4] & 0x10) != 0 )
      {
        qmi_rmnet_work_init(a2);
        v20 = rmnet_set_powersave_format(a2);
      }
      rmnet_ll_wq_init(v20);
      result = rmnet_get_qmi_pt(a2);
      if ( result )
      {
        *(_QWORD *)(result + 80) = a2;
        atomic_store(result, (unsigned __int64 *)&qmi_info_ptr);
        goto LABEL_91;
      }
      goto LABEL_92;
    }
LABEL_113:
    result = rmnet_get_qmi_pt(a2);
    if ( !result )
      goto LABEL_92;
    if ( !*(_QWORD *)(result + 8)
      && !*(_QWORD *)(result + 24)
      && !*(_QWORD *)(result + 32)
      && !*(_QWORD *)(result + 16)
      && !*(_QWORD *)(result + 40)
      && !*(_QWORD *)(result + 48) )
    {
      v52 = result;
      rmnet_reset_qmi_pt(a2);
      kfree(v52);
    }
    goto LABEL_91;
  }
  if ( *a3 > 6u )
  {
    if ( v9 == 7 )
    {
      if ( *((int *)a3 + 1) < 100 )
      {
        result = 4294967274LL;
      }
      else
      {
        result = 0;
        rmnet_wq_frequency = *((_DWORD *)a3 + 1);
      }
    }
    else if ( v9 == 8 )
    {
      result = 0;
      if ( v10 )
      {
        if ( dfc_mode == 4 )
        {
          if ( *(_QWORD *)(v10 + 24) || *(_QWORD *)(v10 + 32) )
          {
            result = rmnet_ll_switch(a1, a3, a4);
            goto LABEL_92;
          }
          goto LABEL_91;
        }
      }
    }
    goto LABEL_92;
  }
  if ( v9 == 5 )
  {
    if ( !v10 )
      goto LABEL_91;
    v30 = v10;
    if ( *((_DWORD *)a3 + 2) )
    {
      v31 = 0;
      if ( (unsigned int)rtnl_is_locked(0) )
      {
LABEL_82:
        v40 = !v31;
        v41 = *(_QWORD *)(v30 + 8);
        if ( !v41 )
          v41 = *(_QWORD *)(v30 + 16);
        v42 = !v31;
        if ( !v41 )
          v42 = 1;
        if ( (v42 & 1) != 0 )
        {
          *(_BYTE *)(v30 + v40 + 56) = 1;
          if ( rmnet_ps_wq )
            _flush_workqueue();
        }
        else
        {
          wda_qmi_client_exit();
          *(_QWORD *)(v30 + 8) = 0;
          *(_QWORD *)(v30 + 16) = 0;
        }
        v43 = _qmi_rmnet_delete_client(a2, v30, v40);
        rmnet_ll_wq_exit(v43);
        goto LABEL_91;
      }
    }
    else
    {
      rmnet_clear_powersave_format(a2);
      v38 = *(_QWORD *)(v30 + 8);
      if ( !v38 )
        v38 = *(_QWORD *)(v30 + 16);
      wda_qmi_client_release(v38);
      v39 = qmi_rmnet_work_exit(a2);
      v31 = *((_DWORD *)a3 + 2) == 0;
      if ( (unsigned int)rtnl_is_locked(v39) )
        goto LABEL_82;
    }
    if ( (qmi_rmnet_delete_client___already_done & 1) == 0 )
    {
      qmi_rmnet_delete_client___already_done = 1;
      _warn_printk("RTNL: assertion failed at %s (%d)\n", "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c", 722);
      __break(0x800u);
    }
    goto LABEL_82;
  }
  if ( v9 == 6 )
  {
    if ( *((_DWORD *)a3 + 1) )
    {
      result = 0;
      qmi_rmnet_scale_factor = *((_DWORD *)a3 + 1);
      goto LABEL_92;
    }
LABEL_91:
    result = 0;
  }
LABEL_92:
  _ReadStatusReg(SP_EL0);
  return result;
}
