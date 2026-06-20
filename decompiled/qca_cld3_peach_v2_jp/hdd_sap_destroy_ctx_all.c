__int64 __fastcall hdd_sap_destroy_ctx_all(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x1
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v22; // x27
  __int64 v23; // x28
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x23
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  if ( (a2 & 1) == 0 )
  {
    v10 = result;
    v28[0] = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: destroying all the sap context",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_sap_destroy_ctx_all");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v10 + 32);
    }
    else
    {
      raw_spin_lock_bh(v10 + 32);
      *(_QWORD *)(v10 + 40) |= 1uLL;
    }
    hdd_get_front_adapter_no_lock(v10, v28);
    if ( v28[0] )
    {
      hdd_adapter_dev_hold_debug(v28[0], 6);
      v12 = v28[0];
    }
    else
    {
      v12 = 0;
    }
    hdd_get_next_adapter_no_lock(v10, v12, &v27);
    if ( v27 )
      hdd_adapter_dev_hold_debug(v27, 6);
    v13 = *(_QWORD *)(v10 + 40);
    if ( (v13 & 1) != 0 )
    {
      *(_QWORD *)(v10 + 40) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 32);
      result = v28[0];
      if ( !v28[0] )
        goto LABEL_41;
    }
    else
    {
      raw_spin_unlock(v10 + 32);
      result = v28[0];
      if ( !v28[0] )
        goto LABEL_41;
    }
    v22 = _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
        if ( *(_DWORD *)(result + 40) == 1 && (*(_QWORD *)(result + 1640) & 1) != 0 )
        {
          v23 = result + 52832;
          if ( result != -52832 )
          {
            do
            {
              v25 = *(_QWORD *)(v23 + 2160);
              v26 = *(_QWORD *)(v23 + 272);
              if ( v25 )
              {
                _qdf_mem_free(v25);
                *(_QWORD *)(v23 + 2160) = 0;
              }
              if ( v26 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: destroying sap context",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hdd_sap_destroy_ctx");
                if ( !(unsigned int)sap_destroy_ctx(v26) )
                  *(_QWORD *)(v23 + 272) = 0;
              }
              else
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: sap context is NULL",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hdd_sap_destroy_ctx");
              }
              result = v28[0];
              if ( v28[0] )
              {
                if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v23 - *(_DWORD *)v23 - 52832) >> 4))
                  || (*(_QWORD *)(v28[0] + 1640LL) & 1) == 0 )
                {
                  break;
                }
                v23 = v28[0] + 52832LL;
              }
            }
            while ( v23 );
          }
        }
        hdd_adapter_dev_put_debug(result, 6);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v22 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v10 + 32);
        }
        else
        {
          raw_spin_lock_bh(v10 + 32);
          *(_QWORD *)(v10 + 40) |= 1uLL;
        }
        v28[0] = v27;
        hdd_get_next_adapter_no_lock(v10, v27, &v27);
        hdd_validate_next_adapter(v28, &v27, 6);
        if ( v27 )
          hdd_adapter_dev_hold_debug(v27, 6);
        v24 = *(_QWORD *)(v10 + 40);
        if ( (v24 & 1) != 0 )
          break;
        raw_spin_unlock(v10 + 32);
        result = v28[0];
        if ( !v28[0] )
          goto LABEL_41;
      }
      *(_QWORD *)(v10 + 40) = v24 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 32);
      result = v28[0];
    }
    while ( v28[0] );
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
