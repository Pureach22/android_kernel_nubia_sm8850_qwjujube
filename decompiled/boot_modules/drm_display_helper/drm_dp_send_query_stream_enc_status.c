__int64 __fastcall drm_dp_send_query_stream_enc_status(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x20
  __int64 v7; // x0
  unsigned int *port_validated_locked; // x0
  unsigned int v9; // w8
  unsigned int v11; // w23
  unsigned int v17; // w9
  __int64 v18; // x8
  __int64 v19; // x1
  _QWORD *v20; // x9
  _QWORD *v21; // x8
  char v22; // w8
  unsigned int v23; // w0
  __int64 v24; // x8
  __int64 v25; // x1
  unsigned int v26; // w23
  int v27; // w8
  _DWORD v29[2]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v30; // [xsp+10h] [xbp-80h] BYREF
  char v31; // [xsp+18h] [xbp-78h]
  _BYTE v32[7]; // [xsp+19h] [xbp-77h]
  __int64 v33; // [xsp+20h] [xbp-70h]
  __int64 v34; // [xsp+28h] [xbp-68h]
  __int64 v35; // [xsp+30h] [xbp-60h]
  __int64 v36; // [xsp+38h] [xbp-58h]
  __int64 v37; // [xsp+40h] [xbp-50h]
  __int64 v38; // [xsp+48h] [xbp-48h]
  __int64 v39; // [xsp+50h] [xbp-40h]
  __int64 v40; // [xsp+58h] [xbp-38h]
  __int64 v41; // [xsp+60h] [xbp-30h]
  __int64 v42; // [xsp+68h] [xbp-28h]
  __int64 v43; // [xsp+70h] [xbp-20h]
  __int64 v44; // [xsp+78h] [xbp-18h]
  __int64 v45; // [xsp+80h] [xbp-10h]
  __int64 v46; // [xsp+88h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)((char *)v29 + 3) = 0;
  v29[0] = 0;
  v6 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  if ( !v6 )
  {
    v26 = -12;
    goto LABEL_36;
  }
  mutex_lock(a1 + 100);
  v7 = a1[113];
  if ( v7 )
  {
    port_validated_locked = (unsigned int *)drm_dp_mst_topology_get_port_validated_locked(v7, a2);
    if ( port_validated_locked )
    {
      v9 = *port_validated_locked;
      _X22 = port_validated_locked;
      if ( *port_validated_locked )
      {
        do
        {
          __asm { PRFM            #0x11, [X22] }
          do
            v17 = __ldxr(port_validated_locked);
          while ( v17 == v9 && __stxr(v9 + 1, port_validated_locked) );
          v11 = v9;
          if ( v17 == v9 )
            break;
          v11 = 0;
          v9 = v17;
        }
        while ( v17 );
      }
      else
      {
        v11 = 0;
      }
      if ( (((v11 + 1) | v11) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(port_validated_locked, 0);
        if ( v11 )
        {
LABEL_15:
          v18 = *(_QWORD *)(*((_QWORD *)_X22 + 204) + 104LL);
          if ( v18 )
            v19 = *(_QWORD *)(v18 + 8);
          else
            v19 = 0;
          _drm_dev_dbg(0, v19, 1, "port %p (%d)\n", _X22, *_X22);
          mutex_unlock(a1 + 100);
          get_random_bytes(v29, 7);
          drm_modeset_lock(a1 + 2, 0);
          v20 = (_QWORD *)(a1[11] + 56LL);
          while ( 1 )
          {
            v20 = (_QWORD *)*v20;
            if ( v20 == (_QWORD *)(a1[11] + 56LL) )
              break;
            if ( (unsigned int *)*(v20 - 4) == _X22 )
            {
              v21 = v20 - 4;
              goto LABEL_23;
            }
          }
          v21 = nullptr;
LABEL_23:
          *(_QWORD *)(v6 + 312) = a1[113];
          v22 = *((_BYTE *)v21 + 9);
          v30 = 56;
          v31 = v22;
          v44 = 0;
          v45 = 0;
          v42 = 0;
          v43 = 0;
          v40 = 0;
          v41 = 0;
          v38 = 0;
          v39 = 0;
          v36 = 0;
          v37 = 0;
          v34 = 0;
          v35 = 0;
          v33 = 0;
          *(_DWORD *)&v32[3] = *(_DWORD *)((char *)v29 + 3);
          *(_DWORD *)v32 = v29[0];
          ((void (__fastcall *)(__int64 *, __int64))drm_dp_encode_sideband_req)(&v30, v6);
          drm_dp_queue_down_tx(a1, v6);
          v23 = drm_dp_mst_wait_tx_reply(a1[113], v6);
          if ( (v23 & 0x80000000) != 0 )
          {
            v26 = v23;
          }
          else if ( *(_BYTE *)(v6 + 346) == 1 )
          {
            v24 = a1[13];
            if ( v24 )
              v25 = *(_QWORD *)(v24 + 8);
            else
              v25 = 0;
            _drm_dev_dbg(0, v25, 2, "query encryption status nak received\n");
            v26 = -6;
          }
          else
          {
            v26 = 0;
            v27 = *(_DWORD *)(v6 + 355);
            *(_QWORD *)a3 = *(_QWORD *)(v6 + 348);
            *(_DWORD *)(a3 + 7) = v27;
          }
          drm_modeset_unlock(a1 + 2);
          drm_dp_mst_topology_put_port(_X22);
          goto LABEL_34;
        }
      }
      else if ( v11 )
      {
        goto LABEL_15;
      }
    }
  }
  mutex_unlock(a1 + 100);
  v26 = -22;
LABEL_34:
  kfree(v6);
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v26;
}
