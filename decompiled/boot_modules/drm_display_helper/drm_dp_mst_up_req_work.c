__int64 __fastcall drm_dp_mst_up_req_work(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  _QWORD **v4; // x26
  _QWORD *v5; // x28
  unsigned __int8 *v6; // x23
  char v7; // w22
  __int64 v8; // x24
  __int64 v9; // x25
  _QWORD *v10; // x8
  __int64 v11; // x9
  int v12; // w8
  unsigned __int8 *v13; // x19
  unsigned int *mst_branch_device_by_guid_helper; // x0
  unsigned int v16; // w8
  unsigned int v17; // w19
  unsigned int v23; // w9
  __int64 v24; // x8
  __int64 v25; // x1
  __int64 v26; // x13
  __int64 v27; // x21
  unsigned int *v28; // x25
  unsigned int v29; // w8
  unsigned int v31; // w24
  unsigned int v33; // w9
  __int64 v34; // x1
  char v35; // w8
  __int64 v36; // x8
  __int64 v37; // x1
  __int64 v38; // x24
  __int64 v39; // x28
  unsigned int **v40; // x8
  unsigned int *v41; // x9
  int v42; // w8
  int v43; // w10
  int v44; // w9
  __int64 v45; // x1
  int v46; // w0
  int v47; // w28
  int v48; // w3
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 result; // x0
  __int64 v52; // [xsp+8h] [xbp-38h]
  __int64 v53; // [xsp+10h] [xbp-30h]
  __int64 v54; // [xsp+18h] [xbp-28h]
  __int64 v55; // [xsp+18h] [xbp-28h]
  int v56; // [xsp+24h] [xbp-1Ch]
  _QWORD *v57; // [xsp+28h] [xbp-18h]
  __int64 v58; // [xsp+30h] [xbp-10h]
  _QWORD *v59; // [xsp+38h] [xbp-8h]

  v1 = a1 - 424;
  mutex_lock(a1 - 424);
  v3 = a1 - 48;
  mutex_lock(a1 - 48);
  v4 = (_QWORD **)(a1 - 64);
  v5 = *(_QWORD **)(a1 - 64);
  if ( v5 == (_QWORD *)(a1 - 64) || (v6 = (unsigned __int8 *)(v5 - 17), v5 == &qword_88) )
  {
    mutex_unlock(a1 - 48);
    return mutex_unlock(v1);
  }
  v53 = v1;
  v57 = (_QWORD *)(a1 - 368);
  v7 = 0;
  v8 = a1 - 1272;
  v9 = a1 - 472;
  v52 = a1 - 248;
  v58 = a1 - 472;
  v59 = (_QWORD *)(a1 - 1168);
  do
  {
    v10 = (_QWORD *)v5[1];
    if ( (_QWORD *)*v10 == v5 && (v11 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
    {
      *(_QWORD *)(v11 + 8) = v10;
      *v10 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(v5);
    }
    *v5 = 0xDEAD000000000100LL;
    v5[1] = 0xDEAD000000000122LL;
    mutex_unlock(v3);
    if ( *((_BYTE *)v5 - 126) == 1 )
    {
      v12 = *((unsigned __int8 *)v5 - 120);
      if ( v12 != 2 )
      {
        if ( v12 != 19 )
          goto LABEL_47;
        v13 = v6 + 25;
        if ( v6 == (unsigned __int8 *)-25LL )
          goto LABEL_47;
LABEL_15:
        mutex_lock(v9);
        mst_branch_device_by_guid_helper = (unsigned int *)get_mst_branch_device_by_guid_helper(*v57, v13);
        _X27 = mst_branch_device_by_guid_helper;
        if ( !mst_branch_device_by_guid_helper )
        {
LABEL_34:
          mutex_unlock(v9);
          if ( !_X27 )
            goto LABEL_47;
LABEL_35:
          if ( *((_BYTE *)v5 - 120) != 2 )
          {
            drm_dp_mst_topology_put_mstb(_X27);
            v35 = 0;
            goto LABEL_99;
          }
          v26 = *((_QWORD *)_X27 + 8);
          v27 = v8;
          v28 = _X27 + 10;
          do
          {
            v28 = *(unsigned int **)v28;
            if ( v28 == _X27 + 10 )
              goto LABEL_98;
          }
          while ( *((unsigned __int8 *)v28 - 16) != *((unsigned __int8 *)v5 - 96) );
          _X19 = v28 - 6;
          v29 = *(v28 - 6);
          if ( v29 )
          {
            do
            {
              __asm { PRFM            #0x11, [X19] }
              do
                v33 = __ldxr(_X19);
              while ( v33 == v29 && __stxr(v29 + 1, _X19) );
              v31 = v29;
              if ( v33 == v29 )
                break;
              v31 = 0;
              v29 = v33;
            }
            while ( v33 );
          }
          else
          {
            v31 = 0;
          }
          if ( (((v31 + 1) | v31) & 0x80000000) != 0 )
          {
            v55 = v26;
            refcount_warn_saturate(v28 - 6, 0);
            v26 = v55;
            if ( v31 )
            {
LABEL_55:
              v36 = *(_QWORD *)(*((_QWORD *)v28 + 201) + 104LL);
              if ( v36 )
              {
                v37 = *(_QWORD *)(v36 + 8);
                v38 = v26;
              }
              else
              {
                v38 = v26;
                v37 = 0;
              }
              _drm_dev_dbg(0, v37, 1, "port %p (%d)\n", v28 - 6, *_X19);
              if ( v28 != (unsigned int *)&_ksymtab_drm_atomic_get_new_mst_topology_state )
              {
                if ( *((_QWORD *)v28 + 200) )
                {
                  if ( (*((_BYTE *)v28 - 15) & 1) == 0 && *((_BYTE *)v5 - 92) == 1 )
                  {
                    v39 = v38;
                    mutex_lock(v38 + 800);
                    --*(_DWORD *)(*((_QWORD *)v28 + 199) + 36LL);
                    v40 = *((unsigned int ***)v28 + 1);
                    if ( *v40 == v28 && (v41 = *(unsigned int **)v28, *(unsigned int **)(*(_QWORD *)v28 + 8LL) == v28) )
                    {
                      *((_QWORD *)v41 + 1) = v40;
                      *v40 = v41;
                    }
                    else
                    {
                      _list_del_entry_valid_or_report(v28);
                    }
                    v8 = v27;
                    *(_QWORD *)v28 = 0xDEAD000000000100LL;
                    *((_QWORD *)v28 + 1) = 0xDEAD000000000122LL;
                    mutex_unlock(v39 + 800);
                    drm_dp_mst_topology_put_port((_QWORD *)v28 - 3);
                    *((_BYTE *)_X27 + 72) = 0;
                    drm_dp_mst_topology_put_port((_QWORD *)v28 - 3);
                    drm_dp_mst_topology_put_mstb(_X27);
                    v9 = v58;
LABEL_89:
                    queue_work_on(32, system_long_wq, v52);
LABEL_90:
                    v35 = 1;
                    goto LABEL_99;
                  }
                  v54 = v38;
                  drm_modeset_lock(v38 + 16, 0);
                  v56 = 0;
                }
                else
                {
                  v54 = v38;
                  if ( *((_BYTE *)v28 - 15) && (*((_BYTE *)v5 - 92) & 1) == 0 )
                  {
                    *((_BYTE *)_X27 + 72) = 0;
                    v56 = 1;
                  }
                  else
                  {
                    v56 = 0;
                  }
                }
                v42 = *((unsigned __int8 *)v5 - 92);
                v43 = *((unsigned __int8 *)v28 - 13);
                v8 = v27;
                *((_BYTE *)v28 - 15) = v42;
                *((_BYTE *)v28 - 11) = *((_BYTE *)v5 - 95);
                v44 = *((unsigned __int8 *)v5 - 94);
                *((_BYTE *)v28 - 13) = v44;
                if ( v43 == v44 )
                {
                  if ( (v42 & 1) != 0 )
                    goto LABEL_73;
LABEL_80:
                  v45 = *((unsigned __int8 *)v5 - 91);
                }
                else if ( v44 )
                {
                  if ( v42 )
                  {
                    v45 = 0;
                    *((_WORD *)v28 - 3) = 0;
                  }
                  else
                  {
                    drm_dp_send_enum_path_resources(v54, _X27, v28 - 6);
                    if ( (*((_BYTE *)v28 - 15) & 1) == 0 )
                      goto LABEL_80;
LABEL_73:
                    v45 = 0;
                  }
                }
                else
                {
                  v45 = 0;
                  *((_WORD *)v28 - 3) = 0;
                  if ( (v42 & 1) == 0 )
                    goto LABEL_80;
                }
                v46 = drm_dp_port_set_pdt(v28 - 6, v45, *((unsigned __int8 *)v5 - 93));
                if ( v46 == 1 )
                {
                  v47 = 1;
                  if ( !*((_QWORD *)v28 + 200) )
                  {
LABEL_83:
                    v9 = v58;
                    if ( v56 )
                      drm_dp_mst_port_add_connector(_X27, _X19);
LABEL_88:
                    drm_dp_mst_topology_put_port(_X19);
                    drm_dp_mst_topology_put_mstb(_X27);
                    if ( v47 )
                      goto LABEL_89;
                    goto LABEL_90;
                  }
                }
                else
                {
                  v47 = v56;
                  v48 = v46;
                  if ( v46 < 0 )
                  {
                    v49 = *(_QWORD *)(v54 + 104);
                    if ( v49 )
                      v50 = *(_QWORD *)(v49 + 8);
                    else
                      v50 = 0;
                    dev_err(v50, "[drm] *ERROR* Failed to change PDT for port %p: %d\n", v28 - 6, v48);
                    v47 = 0;
                    if ( !*((_QWORD *)v28 + 200) )
                      goto LABEL_83;
                  }
                  else if ( !*((_QWORD *)v28 + 200) )
                  {
                    goto LABEL_83;
                  }
                }
                drm_modeset_unlock(v54 + 16);
                v9 = v58;
                goto LABEL_88;
              }
            }
          }
          else if ( v31 )
          {
            goto LABEL_55;
          }
LABEL_98:
          drm_dp_mst_topology_put_mstb(_X27);
          v8 = v27;
          v9 = v58;
          v35 = 1;
          goto LABEL_99;
        }
        v16 = *mst_branch_device_by_guid_helper;
        if ( *mst_branch_device_by_guid_helper )
        {
          do
          {
            __asm { PRFM            #0x11, [X27] }
            do
              v23 = __ldxr(mst_branch_device_by_guid_helper);
            while ( v23 == v16 && __stxr(v16 + 1, mst_branch_device_by_guid_helper) );
            v17 = v16;
            if ( v23 == v16 )
              break;
            v17 = 0;
            v16 = v23;
          }
          while ( v23 );
        }
        else
        {
          v17 = 0;
        }
        if ( (((v17 + 1) | v17) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(mst_branch_device_by_guid_helper, 0);
          if ( v17 )
            goto LABEL_28;
        }
        else if ( v17 )
        {
LABEL_28:
          v24 = *(_QWORD *)(*((_QWORD *)_X27 + 8) + 104LL);
          if ( v24 )
            v25 = *(_QWORD *)(v24 + 8);
          else
            v25 = 0;
          _drm_dev_dbg(0, v25, 1, "mstb %p (%d)\n", _X27, *_X27);
          goto LABEL_34;
        }
        _X27 = nullptr;
        goto LABEL_34;
      }
      v13 = v6 + 24;
      if ( v6 != (unsigned __int8 *)-24LL )
        goto LABEL_15;
    }
    else
    {
      _X27 = (unsigned int *)drm_dp_get_mst_branch_device(v8, *v6, (char *)v5 - 134);
      if ( _X27 )
        goto LABEL_35;
    }
LABEL_47:
    if ( *v59 )
      v34 = *(_QWORD *)(*v59 + 8LL);
    else
      v34 = 0;
    _drm_dev_dbg(0, v34, 2, "Got MST reply from unknown device %d\n", *v6);
    v35 = 0;
LABEL_99:
    v7 |= v35;
    kfree(v6);
    mutex_lock(v3);
    v5 = *v4;
    if ( *v4 == v4 )
      break;
    v6 = (unsigned __int8 *)(v5 - 17);
  }
  while ( v5 != &qword_88 );
  mutex_unlock(v3);
  result = mutex_unlock(v53);
  if ( (v7 & 1) != 0 )
    return drm_kms_helper_hotplug_event(*v59);
  return result;
}
