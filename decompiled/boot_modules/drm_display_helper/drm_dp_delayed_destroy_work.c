__int64 __fastcall drm_dp_delayed_destroy_work(__int64 a1)
{
  __int64 v1; // x20
  _QWORD **v2; // x26
  __int64 result; // x0
  _QWORD *v4; // x27
  _QWORD *v5; // x22
  char v7; // w8
  char v8; // w19
  _QWORD *v9; // x8
  __int64 v10; // x9
  __int64 v11; // x24
  _QWORD *v12; // x9
  _QWORD *v13; // x8
  _QWORD *v14; // x28
  __int64 *v15; // x11
  __int64 *v16; // x10
  char v17; // w23
  __int64 *v18; // x9
  __int64 **v19; // x8
  __int64 v20; // x8
  __int64 v21; // x1
  __int64 v23; // x0
  int v28; // w8
  bool v29; // zf
  _QWORD *v30; // x22
  __int64 v31; // x23
  _QWORD *v32; // x8
  __int64 v33; // x9
  char v34; // w19
  __int64 v35; // x24
  __int64 v36; // x0
  char v38; // [xsp+Ch] [xbp-14h]
  _QWORD *v39; // [xsp+10h] [xbp-10h]
  char v40; // [xsp+1Ch] [xbp-4h]

  v1 = a1 - 56;
  v2 = (_QWORD **)(a1 - 72);
  v38 = 0;
  v39 = (_QWORD *)(a1 - 88);
  do
  {
    while ( 2 )
    {
      mutex_lock(v1);
      v4 = *v2;
      v5 = *v2 - 1;
      _ZF = *v2 == v2 || *v2 == (_QWORD *)&unk_8;
      v7 = !_ZF;
      v40 = v7;
      if ( _ZF )
      {
LABEL_60:
        mutex_unlock(v1);
        goto LABEL_61;
      }
      v8 = v7;
      while ( 1 )
      {
        v9 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v9 == v4 && (v10 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
        {
          *(_QWORD *)(v10 + 8) = v9;
          *v9 = v10;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        mutex_unlock(v1);
        v11 = v4[7];
        mutex_lock(v11 + 800);
        v12 = (_QWORD *)v4[4];
        if ( v12 != v4 + 4 )
        {
          do
          {
            v14 = (_QWORD *)*v12;
            v13 = (_QWORD *)v12[1];
            if ( (_QWORD *)*v13 == v12 && (_QWORD *)v14[1] == v12 )
            {
              v14[1] = v13;
              *v13 = v14;
            }
            else
            {
              _list_del_entry_valid_or_report(v12);
            }
            *v12 = 0xDEAD000000000100LL;
            v12[1] = 0xDEAD000000000122LL;
            drm_dp_mst_topology_put_port(v12 - 3);
            v12 = v14;
          }
          while ( v14 != v4 + 4 );
        }
        mutex_unlock(v11 + 800);
        mutex_lock(v4[7] + 936LL);
        v15 = *(__int64 **)(v11 + 984);
        v16 = (__int64 *)(v11 + 984);
        if ( v15 == (__int64 *)(v11 + 984) )
        {
          mutex_unlock(v4[7] + 936LL);
        }
        else
        {
          v17 = 0;
LABEL_23:
          v18 = v15;
          do
          {
            v15 = (__int64 *)*v18;
            if ( (_QWORD *)*(v18 - 1) == v5 )
            {
              v19 = (__int64 **)v18[1];
              *((_DWORD *)v18 + 5) = 4;
              if ( *v19 == v18 && (__int64 *)v15[1] == v18 )
              {
                v15[1] = (__int64)v19;
                *v19 = v15;
              }
              else
              {
                _list_del_entry_valid_or_report(v18);
              }
              v17 = 1;
              *v18 = 0xDEAD000000000100LL;
              v18[1] = 0xDEAD000000000122LL;
              if ( v15 == v16 )
              {
                mutex_unlock(v4[7] + 936LL);
LABEL_34:
                _wake_up(v4[7] + 1000LL, 3, 0, 0);
                goto LABEL_36;
              }
              goto LABEL_23;
            }
            v18 = (__int64 *)*v18;
          }
          while ( v15 != v16 );
          mutex_unlock(v4[7] + 936LL);
          if ( (v17 & 1) != 0 )
            goto LABEL_34;
        }
LABEL_36:
        v20 = *(_QWORD *)(v4[7] + 104LL);
        v21 = v20 ? *(_QWORD *)(v20 + 8) : 0LL;
        _X24 = (unsigned int *)v4 - 1;
        _drm_dev_dbg(0, v21, 1, "mstb %p (%d)\n", v5, *((_DWORD *)v4 - 1) - 1);
        __asm { PRFM            #0x11, [X24] }
        do
          v28 = __ldxr(_X24);
        while ( __stlxr(v28 - 1, _X24) );
        if ( v28 == 1 )
          break;
        if ( v28 <= 0 )
        {
          refcount_warn_saturate((char *)v4 - 4, 3);
          if ( (v8 & 1) == 0 )
            goto LABEL_59;
        }
        else if ( (v8 & 1) == 0 )
        {
          goto LABEL_59;
        }
LABEL_49:
        mutex_lock(v1);
        v4 = *v2;
        v5 = *v2 - 1;
        v29 = *v2 == v2 || *v2 == (_QWORD *)&unk_8;
        v8 = !v29;
        if ( v29 )
          goto LABEL_60;
      }
      __dmb(9u);
      v23 = v4[6];
      if ( v23 )
        drm_dp_mst_put_port_malloc(v23);
      kfree(v5);
      if ( (v8 & 1) != 0 )
        goto LABEL_49;
LABEL_59:
      v40 = 1;
LABEL_61:
      mutex_lock(v1);
      v30 = (_QWORD *)*v39;
      if ( (_QWORD *)*v39 != v39 )
      {
        v31 = (__int64)(v30 - 3);
        if ( v30 != &_ksymtab_drm_atomic_get_new_mst_topology_state )
        {
          do
          {
            v32 = (_QWORD *)v30[1];
            if ( (_QWORD *)*v32 == v30 && (v33 = *v30, *(_QWORD **)(*v30 + 8LL) == v30) )
            {
              *(_QWORD *)(v33 + 8) = v32;
              *v32 = v33;
            }
            else
            {
              _list_del_entry_valid_or_report(v30);
            }
            *v30 = 0xDEAD000000000100LL;
            v30[1] = 0xDEAD000000000122LL;
            mutex_unlock(v1);
            if ( *((_BYTE *)v30 - 12) )
            {
              v34 = *((_BYTE *)v30 - 14);
              if ( *((_BYTE *)v30 - 12) == 2 && (*((_BYTE *)v30 - 14) & 1) != 0 )
              {
                v35 = v30[201];
                mutex_lock(v35 + 800);
                drm_dp_mst_topology_put_mstb((_QWORD *)v30[2]);
                v30[2] = 0;
                mutex_unlock(v35 + 800);
              }
              else
              {
                i2c_del_adapter(v30 + 4);
              }
              *((_BYTE *)v30 - 12) = 0;
              *((_BYTE *)v30 - 14) = v34;
            }
            v36 = v30[200];
            if ( v36 )
            {
              drm_connector_unregister(v36);
              drm_mode_object_put(v30[200] + 64LL);
            }
            drm_dp_mst_put_port_malloc(v31);
            mutex_lock(v1);
            v30 = (_QWORD *)*v39;
            if ( (_QWORD *)*v39 == v39 )
              break;
            v31 = (__int64)(v30 - 3);
          }
          while ( v30 != &_ksymtab_drm_atomic_get_new_mst_topology_state );
          mutex_unlock(v1);
          v38 = 1;
          continue;
        }
      }
      break;
    }
    result = mutex_unlock(v1);
  }
  while ( (v40 & 1) != 0 );
  if ( (v38 & 1) != 0 )
    return drm_kms_helper_hotplug_event(*(_QWORD *)(a1 - 1072));
  return result;
}
