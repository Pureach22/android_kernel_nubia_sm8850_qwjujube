__int64 __usercall dp_vdev_unref_delete@<X0>(
        __int64 result@<X0>,
        __int64 a2@<X1>,
        unsigned int a3@<W2>,
        unsigned int *_X8@<X8>,
        double a5@<D0>,
        double a6@<D1>,
        double a7@<D2>,
        double a8@<D3>,
        double a9@<D4>,
        double a10@<D5>,
        double a11@<D6>,
        double a12@<D7>)
{
  __int64 v12; // x19
  __int64 v13; // x20
  unsigned int v14; // w23
  __int64 v15; // x24
  void (__fastcall *v16)(__int64, __int64); // x26
  __int64 v17; // x21
  __int64 (__fastcall *v18)(_QWORD); // x25
  const char *v19; // x8
  __int64 v20; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  __int64 v39; // x8
  void (__fastcall *v40)(_QWORD); // x8
  const char *v41; // x2
  __int64 v42; // x8
  __int64 v43; // x8
  void (__fastcall *v44)(__int64, __int64); // x8
  const char *v45; // x2
  __int64 v46; // x8
  __int64 v47; // x8
  void (__fastcall *v48)(_QWORD); // x8
  __int64 v49; // x23
  __int64 v50; // x24
  __int64 *v51; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v53; // x8
  __int64 v54; // x8
  _QWORD *v55; // x9
  _QWORD *v56; // x8
  __int64 v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v71; // w10
  unsigned int v74; // w8
  unsigned int v75; // w8

  if ( a3 >= 0x20 )
  {
    __break(0x5512u);
  }
  else
  {
    v14 = *(unsigned __int8 *)(a2 + 59);
    v15 = *(_QWORD *)(a2 + 24);
    v12 = a2;
    v13 = result;
    _X8 = (unsigned int *)(a2 + 4LL * a3 + 43388);
  }
  __asm { PRFM            #0x11, [X8] }
  do
    v71 = __ldxr(_X8);
  while ( __stlxr(v71 - 1, _X8) );
  __dmb(0xBu);
  _X9 = (unsigned int *)(v12 + 43384);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v74 = __ldxr(_X9);
    v75 = v74 - 1;
  }
  while ( __stlxr(v75, _X9) );
  __dmb(0xBu);
  if ( v75 )
    return result;
  v16 = *(void (__fastcall **)(__int64, __int64))(v12 + 272);
  v18 = *(__int64 (__fastcall **)(_QWORD))(v12 + 288);
  v17 = *(_QWORD *)(v12 + 296);
  v19 = " with del_notify";
  v20 = *(_QWORD *)(v12 + 88);
  if ( !v16 )
    v19 = (const char *)&unk_98C763;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: deleting vdev object %pK (%02x:%02x:%02x:**:**:%02x)%s",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "dp_vdev_unref_delete",
    v12,
    *(unsigned __int8 *)(v12 + 96),
    *(unsigned __int8 *)(v12 + 97),
    *(unsigned __int8 *)(v12 + 98),
    *(unsigned __int8 *)(v12 + 101),
    v19);
  if ( *(_DWORD *)(v12 + 32) != 4 )
  {
    dp_tx_flow_pool_unmap_handler(v15, v14, 0, v14);
    dp_tx_vdev_detach(v12);
    goto LABEL_28;
  }
  v29 = *(unsigned __int8 *)(v13 + 17840);
  if ( v29 == 1 )
  {
    v38 = *(_QWORD *)(v13 + 20112);
    if ( v38 )
    {
      v39 = *(_QWORD *)(v38 + 416);
      if ( v39 )
      {
        v40 = *(void (__fastcall **)(_QWORD))(v39 + 504);
        if ( v40 )
        {
          if ( *((_DWORD *)v40 - 1) != -82823681 )
            __break(0x8228u);
          v40(v13);
          goto LABEL_19;
        }
      }
      v41 = "%s: callback not registered";
    }
    else
    {
      v41 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(0x92u, 8u, v41, v21, v22, v23, v24, v25, v26, v27, v28, "dp_monitor_vdev_timer_stop");
  }
  else
  {
    if ( v29 != 2 )
      goto LABEL_28;
    timer_delete_sync(v13 + 17784);
  }
LABEL_19:
  v42 = *(_QWORD *)(v13 + 20112);
  if ( v42 )
  {
    v43 = *(_QWORD *)(v42 + 416);
    if ( v43 )
    {
      v44 = *(void (__fastcall **)(__int64, __int64))(v43 + 200);
      if ( v44 )
      {
        if ( *((_DWORD *)v44 - 1) != 502678718 )
          __break(0x8228u);
        v44(v13, v12);
        goto LABEL_28;
      }
    }
    v45 = "%s: callback not registered";
  }
  else
  {
    v45 = "%s: monitor soc is NULL";
  }
  qdf_trace_msg(0x92u, 8u, v45, v30, v31, v32, v33, v34, v35, v36, v37, "dp_monitor_flush_rings");
LABEL_28:
  v46 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 24) + 8LL) + 20112LL);
  if ( v46 )
  {
    v47 = *(_QWORD *)(v46 + 416);
    if ( v47 && (v48 = *(void (__fastcall **)(_QWORD))(v47 + 128)) != nullptr )
    {
      if ( *((_DWORD *)v48 - 1) != 341701128 )
        __break(0x8228u);
      v48(v12);
    }
    else
    {
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: callback not registered",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "dp_monitor_vdev_detach");
    }
  }
  v49 = 0;
  v50 = v12 + 46072;
  do
  {
    v51 = *(__int64 **)(v50 + v49);
    if ( v51 )
    {
      if ( *v51 )
      {
        _qdf_mem_free(*v51);
        v51 = *(__int64 **)(v50 + v49);
        if ( v51[1] )
        {
          _qdf_mem_free(v51[1]);
          v51 = *(__int64 **)(v50 + v49);
          if ( v51[2] )
          {
            _qdf_mem_free(v51[2]);
            v51 = *(__int64 **)(v50 + v49);
            if ( v51[3] )
            {
              _qdf_mem_free(v51[3]);
              v51 = *(__int64 **)(v50 + v49);
              if ( v51[4] )
              {
                _qdf_mem_free(v51[4]);
                v51 = *(__int64 **)(v50 + v49);
                if ( v51[5] )
                {
                  _qdf_mem_free(v51[5]);
                  v51 = *(__int64 **)(v50 + v49);
                  if ( v51[6] )
                  {
                    _qdf_mem_free(v51[6]);
                    v51 = *(__int64 **)(v50 + v49);
                    if ( v51[7] )
                    {
                      _qdf_mem_free(v51[7]);
                      v51 = *(__int64 **)(v50 + v49);
                      if ( v51[8] )
                      {
                        _qdf_mem_free(v51[8]);
                        v51 = *(__int64 **)(v50 + v49);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      _qdf_mem_free((__int64)v51);
    }
    v49 += 24;
  }
  while ( v49 != 72 );
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v13 + 18968);
    v53 = *(_QWORD *)(v13 + 18952);
    if ( v53 )
      goto LABEL_53;
  }
  else
  {
    raw_spin_lock_bh(v13 + 18968);
    *(_QWORD *)(v13 + 18976) |= 1uLL;
    v53 = *(_QWORD *)(v13 + 18952);
    if ( v53 )
    {
LABEL_53:
      while ( v53 != v12 )
      {
        v53 = *(_QWORD *)(v53 + 43352);
        if ( !v53 )
          goto LABEL_60;
      }
      v54 = *(_QWORD *)(v12 + 43352);
      v55 = *(_QWORD **)(v12 + 43360);
      if ( v54 )
        v56 = (_QWORD *)(v54 + 43360);
      else
        v56 = (_QWORD *)(v13 + 18960);
      *v56 = v55;
      *v55 = *(_QWORD *)(v12 + 43352);
      *(_QWORD *)(v12 + 43360) = 0;
      *(_QWORD *)(v12 + 43352) = 0;
    }
  }
LABEL_60:
  v57 = *(_QWORD *)(v13 + 18976);
  if ( (v57 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 18976) = v57 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 18968);
  }
  else
  {
    raw_spin_unlock(v13 + 18968);
  }
  wlan_minidump_remove(v58, v59, v60, v61, v62, v63, v64, v65, v12, 46248, *(_QWORD *)(v13 + 16));
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != 2138108659 )
      __break(0x823Au);
    v16(v20, v12);
  }
  result = _qdf_mem_free(v12);
  if ( v18 )
  {
    if ( *((_DWORD *)v18 - 1) != 251140989 )
      __break(0x8239u);
    return v18(v17);
  }
  return result;
}
